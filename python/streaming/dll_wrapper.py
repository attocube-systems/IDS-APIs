import ctypes

import os
import os.path
import platform

CURRENT_PATH = os.path.dirname(__file__)

if platform.architecture()[0] == '64bit':
    CURRENT_PATH = os.path.join(CURRENT_PATH, "x64")
else:
    CURRENT_PATH = os.path.join(CURRENT_PATH, "x86")

if os.name == "nt":
    DLL_PATH = os.path.join(CURRENT_PATH, "Attocube.Common.NativeC.dll")
else:
    raise Exception("Streaming not supported on this platform")

API = ctypes.cdll.LoadLibrary(DLL_PATH)

_GetLastStreamError = API.GetLastStreamError
_GetLastStreamError.restype = ctypes.c_int

_OpenStream = API.OpenStream
_OpenStream.restype = ctypes.c_void_p

_CloseStream = API.CloseStream

_GetPacketSize = API.GetPacketSize
_GetPacketSize.restype = ctypes.c_int

_ReadStream = API.ReadStream
_ReadStream.restype = ctypes.c_int

_DecodeStreamSingle = API.DecodeStreamSingle
_DecodeStreamSingle.restype = ctypes.c_int

_StartStreamRecording = API.StartStreamRecording
_StartStreamRecording.restype = ctypes.c_bool

_StopStreamRecording = API.StopStreamRecording
_StopStreamRecording.restype = ctypes.c_bool

_DecodePackets = API.DecodePackets
