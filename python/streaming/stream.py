import ctypes

from .dll_wrapper import _GetLastStreamError, \
                         _OpenStream, \
                         _CloseStream, \
                         _ReadStream, \
                         _DecodeStreamSingle, \
                         _StartStreamRecording, \
                         _StopStreamRecording
class Stream():
    def __init__(self, deviceAddress, isMaster, intervalInMicroseconds, filePath=None, axis0=False, axis1=False, axis2=False):
        """
        Stream class handling the connection between IDS and Python

        Parameters
        ----------
        deviceAddress : str
            IP address of IDS
        isMaster : bool
            Master
        intervalInMicroseconds : int
            Sample rate of the position samples
        filePath : str, optional
            If defined, stream recording is started automatically to the given file.
        axis0 : bool, default: False
            Should Axis 0 be recorded?
        axis1 : bool, default: False
            Should Axis 1 be recorded?
        axis2 : bool, default: False
            Should Axis 2 be recorded?
        """
        self.handle = 0
        self.connected = False

        self.deviceAddress = deviceAddress
        self.isMaster = isMaster
        self.intervalInMicroseconds = intervalInMicroseconds
        self.filePath = filePath

        self.recording = False

        self.channelMask = 0
        if axis0:
            self.channelMask |= 1
        if axis1:
            self.channelMask |= 2
        if axis2:
            self.channelMask |= 4

    def __del__(self):
        if self.connected and self.handle != 0:
            self.close()

    def __enter__(self):
        self.open()
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        if self.connected and self.handle != 0:
            self.close()

    @property
    def lastError(self):
        return _GetLastStreamError()

    def open(self):
        """
        Open Stream with parameters given in constructor
        """
        if self.connected or self.handle != 0:
            raise Exception("Stream already connected")

        handle = _OpenStream(ctypes.c_char_p(self.deviceAddress.encode("utf-8")),
                             ctypes.c_bool(self.isMaster),
                             ctypes.c_int(self.intervalInMicroseconds),
                             ctypes.c_uint8(self.channelMask))
        if handle != 0 and handle is not None:
            self.connected = True
            self.handle = handle

            if self.filePath is not None:
                self.startRecording(self.filePath)
            return
        raise Exception("Cannot connect to IDS streaming. Maybe, the measurement is not running on all requested axes or Streaming is not running on your IDS.")

    def close(self):
        """
        Close stream and stop recording if necessary
        """
        if not self.connected or self.handle == 0:
            raise Exception("Stream not connected")
        if self.recording:
            self.stopRecording()
        _CloseStream(ctypes.c_void_p(self.handle))
        self.connected = False

    def readRaw(self, bufferSize):
        """
        Read raw position data in buffer. Use decodeBuffer to get real positions

        Parameters
        ----------
        bufferSize : int
            Size of buffer (created by this method) in Bytes

        Returns
        -------
        buffer : bytearray
            Buffer of raw position data
        """
        if not self.connected or self.handle == 0:
            raise Exception("Stream not connected")

        buffer = (ctypes.c_uint8 * bufferSize)()
        _len = _ReadStream(ctypes.c_void_p(self.handle),
                           buffer,
                           ctypes.c_int(bufferSize))
        return buffer[:_len]

    def decodeBuffer(self, buffer):
        """
        Decode raw position data buffer to positions in pm.

        Parameters
        ----------
        buffer : bytearray
            Buffer of raw position data

        Returns
        -------
        decodedBytes : int
            Number of decoded Bytes
        axis0 : list
            List containing positions of axis 0 in pm
        axis1 : list
            List containing positions of axis 1 in pm
        axis2 : list
            List containing positions of axis 2 in pm
        """
        axis0 = (ctypes.c_int64 * len(buffer))()
        axis1 = (ctypes.c_int64 * len(buffer))()
        axis2 = (ctypes.c_int64 * len(buffer))()
        decodedSampleCount = (ctypes.c_int * 1)()

        decodedBytes = _DecodeStreamSingle(ctypes.c_void_p(self.handle),
                                          (ctypes.c_uint8 * len(buffer))(*buffer),
                                          ctypes.c_int(len(buffer)),
                                          axis0,
                                          axis1,
                                          axis2,
                                          ctypes.c_int(ctypes.sizeof(axis0)*3),
                                          decodedSampleCount)

        decodedSamples = decodedSampleCount[0]
        if decodedSamples == 0:
            print("No samples received.")
            print("Possible causes:")
            print("\t- Measurement is not running on all selected axes")
            print("\t- Error on at least one of your selected axes")
            print("\t- Buffer too small")

        axis0 = axis0[:decodedSamples]
        axis1 = axis1[:decodedSamples]
        axis2 = axis2[:decodedSamples]

        if self.channelMask & 1 == 0:
            axis2 = axis1
            axis1 = axis0
            axis0 = []
        if self.channelMask & 2 == 0:
            axis2 = axis1
            axis1 = []
        if self.channelMask & 4 == 0:
            axis2 = []

        return decodedBytes, axis0, axis1, axis2

    def read(self, bufferSize):
        """
        Read and decode position data in buffer.

        Parameters
        ----------
        bufferSize : int
            Size of buffer (created by this method) in Bytes

        Returns
        -------
        decodedBytes : int
            Number of decoded Bytes
        axis0 : list
            List containing positions of axis 0 in pm
        axis1 : list
            List containing positions of axis 1 in pm
        axis2 : list
            List containing positions of axis 2 in pm
        """
        buffer = self.readRaw(bufferSize)
        return self.decodeBuffer(buffer)

    def startRecording(self, filePath):
        """
        Starts stream recording to file

        Parameters
        ----------
        filePath : str
            File to record to
        """
        success = _StartStreamRecording(ctypes.c_void_p(self.handle),
                                        ctypes.c_char_p(filePath.encode("utf-8")))
        self.recording = True
        if not success:
            raise Exception("Cannot start recording")

    def stopRecording(self):
        """
        Stop stream recording to file
        """
        success = _StopStreamRecording(ctypes.c_void_p(self.handle))
        self.recording = False
        if not success:
            raise Exception("Cannot stop recording")
