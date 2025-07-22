#pragma once

#include <stdint.h>

#if __cplusplus
#define __extern_c__ extern "C"
#else
#define __extern_c__
#endif

#if ATTOCUBECOMMONNATIVE_EXPORTS && defined _MSC_VER
#define DLLEXPORT(rettype) __extern_c__ __declspec(dllexport) rettype __stdcall
#elif defined _MSC_VER
#define DLLEXPORT(rettype) __extern_c__ __declspec(dllimport) rettype __stdcall
#else
#define DLLEXPORT(rettype) __extern_c__ rettype
#endif

DLLEXPORT(void*) OpenStream(const char* host, const bool isMaster, const int intervalInMicroseconds, const uint8_t channelMask);
DLLEXPORT(void) CloseStream(void* stream);
DLLEXPORT(int) ReadStream(void* stream, uint8_t* buffer, int bufferSize);
DLLEXPORT(int) DecodeStream(void* stream, const uint8_t* buffer, int bufferSize, int64_t* sampleBuffer1, int64_t* sampleBuffer2, int64_t* sampleBuffer3, uint8_t* errorBuffer1, uint8_t* errorBuffer2, uint8_t* errorBuffer3, int destinationBuffersSize, int* decodedSamplesCount);
DLLEXPORT(bool) StartStreamRecording(void* stream, const char* path);
DLLEXPORT(bool) StopStreamRecording(void* stream);

DLLEXPORT(void) DecodePackets(const uint8_t* src, int packetCount, const int samplesPerPacket, const int channelCount, int64_t* __restrict offsets, int64_t* sampleBuffer1, int64_t* sampleBuffer2, int64_t* sampleBuffer3, uint8_t* errorBuffer1, uint8_t* errorBuffer2, uint8_t* errorBuffer3);