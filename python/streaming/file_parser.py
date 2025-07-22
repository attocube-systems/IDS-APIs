import ctypes

from dateutil import parser

from .dll_wrapper import _DecodePackets
from .stream import Stream

############
### BETA ###
############

def parse(file):
    headerSize, headerParams = parseHeader(file)
    # reset to start of data buffer:
    file.seek(headerSize)
    return decodeFile(file, headerParams)

def parseHeader(file):
    headerSize = 0
    headerParams = {}
    for line in file.readlines():
        try:
            params = line.decode("utf8").replace("\n", "").replace("\r", "").split(": ")
            headerSize += len(line)
            if params[0] == "Date":
                headerParams["recorded"] = parser.parse(params[1])
            elif params[0] == "Channels":
                headerParams["channels"] = [{_k.split("=")[0]: _k.split("=")[1] for _k in param.split(",")} for param in params[1].split(";")]
            elif params[0] == "SampleInterval":
                headerParams["frequency"] = 1000000 / int(params[1])
            elif params[0] == "SampleCount":
                headerParams["perPacketSampleCount"] = int(params[1])
        except UnicodeDecodeError:
            break

    headerParams["channelIds"] = [int(x["id"][3]) for x in headerParams["channels"] if x["id"].startswith("Pos")]
    return headerSize, headerParams

def decodeFile(file, headerParams):
    PACKET_BUFFER_LEN = 1024

    result = []

    packetSize = ctypes.sizeof(ctypes.c_int64) \
                    + ((ctypes.sizeof(ctypes.c_int64) \
                        + (ctypes.sizeof(ctypes.c_int32) * (headerParams["perPacketSampleCount"] - 1))
                    ) * len(headerParams["channelIds"]))
    bufferSize = packetSize * PACKET_BUFFER_LEN

    buffer_c = bytearray()
    sourceSamplePos = 0
    while True:
        buffer_c += file.read(bufferSize)
        packetCount = len(buffer_c) // packetSize
        buffer = buffer_c[:packetCount*packetSize]
        buffer_c = buffer_c[packetCount*packetSize:]

        if packetCount == 0:
            break

        # StreamDecoder.Decode(src, 0, packetCount, _perPacketSampleCount, dst);
        _buffer = (ctypes.c_uint8 * len(buffer))(*buffer)
        _offsets = (ctypes.c_int64 * 3)()
        _axis = [
            (ctypes.c_int64 * (headerParams["perPacketSampleCount"] * PACKET_BUFFER_LEN))(),
            (ctypes.c_int64 * (headerParams["perPacketSampleCount"] * PACKET_BUFFER_LEN))(),
            (ctypes.c_int64 * (headerParams["perPacketSampleCount"] * PACKET_BUFFER_LEN))()
        ]
        #error flags are decoded into these buffers
        _axisErr = [
            (ctypes.c_uint8 * (headerParams["perPacketSampleCount"] * PACKET_BUFFER_LEN))(),
            (ctypes.c_uint8 * (headerParams["perPacketSampleCount"] * PACKET_BUFFER_LEN))(),
            (ctypes.c_uint8 * (headerParams["perPacketSampleCount"] * PACKET_BUFFER_LEN))()
        ]
        _dest = (ctypes.POINTER(ctypes.c_int64)*3)(*[ctypes.cast(ax, ctypes.POINTER(ctypes.c_int64)) for ax in _axis])
        _dstErr = (ctypes.POINTER(ctypes.c_uint8)*3)(*[ctypes.cast(ex, ctypes.POINTER(ctypes.c_uint8)) for ex in _axisErr])  

        _DecodePackets(_buffer,
                       ctypes.c_int(packetCount),
                       ctypes.c_int(headerParams["perPacketSampleCount"]),
                       ctypes.c_int(len(headerParams["channelIds"])),
                       _offsets,
                       *_dest,
                       *_dstErr
                       )

        sampleCountInBuffer = packetCount * headerParams["perPacketSampleCount"]
        srcFreq = headerParams["frequency"]
        for j in range(sampleCountInBuffer):
            time = sourceSamplePos / srcFreq
            elem = [time, None, None, None]
            err = [None, None, None]
            for i_src, i_dst in enumerate(headerParams["channelIds"]):
                elem[i_dst+1] = _axis[i_src][j] - int(headerParams["channels"][i_src+1]["offs"])
                err[i_dst] = _axisErr[i_src][j] - int(headerParams["channels"][i_src+1]["offs"])
            elem.extend(err)
            result.append(tuple(elem))
            sourceSamplePos += 1

    return result

def fileWriter(deviceAddress,
               isMaster,
               intervalInMicroseconds,
               filePath,
               bufferSize,
               axis0,
               axis1,
               axis2,
               barrier=None,
               stopped=None,
               barrier_timeout = 10):
    try:
        with Stream(deviceAddress,
                    isMaster,
                    intervalInMicroseconds,
                    filePath,
                    axis0,
                    axis1,
                    axis2) as stream:
            
            if barrier is not None:
                barrier.wait(timeout = barrier_timeout)
            while (not stopped.value if stopped is not None else True):
                _ = stream.readRaw(bufferSize)
    except Exception as e: 
        print(e)
