from multiprocessing import Process, \
                            Value, \
                            Barrier

from .file_parser import parse, \
                         fileWriter

from .stream import Stream

from time import sleep

class Streaming():
    def __init__(self, device):
        self.device = device
        self.background_process = None

    def open(self, isMaster, intervalInMicroseconds, filePath=None, axis0=False, axis1=False, axis2=False):
        """
        Open position stream

        Parameters
        ----------
        isMaster : bool
            Master
        intervalInMicroseconds : int
            Sample interval (in us) of the position samples
        filePath : str, optional
            If defined, stream recording is started automatically to the given file.
        axis0 : bool, default: False
            Should Axis 0 be recorded?
        axis1 : bool, default: False
            Should Axis 1 be recorded?
        axis2 : bool, default: False
            Should Axis 2 be recorded?

        Returns
        -------
        stream : Stream
            Stream object
        """
        return Stream(self.device.address,
                      isMaster,
                      intervalInMicroseconds,
                      filePath,
                      axis0,
                      axis1,
                      axis2)

    def loadFile(self, filePath):
        """
        Load content of recorded stream file

        Parameters
        ----------
        filePath : str
            Path to file


        Returns
        -------
        samples : list(tuple(float, float, float, float))
            A list containing all samples as tuples in the following format:
            (time, axis0, axis1, axis2)
        """
        with open(filePath, "rb") as file:
            return parse(file)

    def startBackgroundStreaming(self, isMaster, intervalInMicroseconds, filePath, bufferSize=2<<20, axis0=False, axis1=False, axis2=False, barrier_timeout = 10):
        """
        Starts concurrent and permanent position streaming to file in background.
        Programm must run in a main function:

        def main():
            do_everything()

        if __name__ == '__main__':
            main()

        Parameters
        ----------
        isMaster : bool
            Master
        intervalInMicroseconds : int
            Sample interval (in us) of the position samples
        filePath : str
            target file
        bufferSize : int
            Size of each buffer in bytes
        axis0 : bool, default: False
            Should Axis 0 be recorded?
        axis1 : bool, default: False
            Should Axis 1 be recorded?
        axis2 : bool, default: False
            Should Axis 2 be recorded?
        """

        if self.background_process is not None:
            raise Exception("Stream recording already started")

        barrier = Barrier(2)
        stopped = Value('b', False)

        self.background_process = Process(target=fileWriter, args=(self.device.address,
                                                                isMaster,
                                                                intervalInMicroseconds,
                                                                filePath,
                                                                bufferSize,
                                                                axis0,
                                                                axis1,
                                                                axis2,
                                                                barrier,
                                                                stopped,barrier_timeout))
        self.background_process.daemon = True
        self.background_process.stopped = stopped
        self.background_process.start()

        barrier.wait(timeout = barrier_timeout)
        sleep(0.1)
        return

    def stopBackgroundStreaming(self):
        """
        Stops the permanent position streaming
        """
        if self.background_process is None:
            raise Exception("Stream recording is not started")
        if not self.background_process.is_alive():
            raise Exception("Stream recording does not answer")

        self.background_process.stopped.value = True
        self.background_process.join()
        self.background_process = None

    def isRunningBackgroundStreaming(self):
        """
        Get state of background position reading

        Returns
        -------
        running : bool
            True, if background position reading is alive and running
        """
        return self.background_process is not None and self.background_process.is_alive()
