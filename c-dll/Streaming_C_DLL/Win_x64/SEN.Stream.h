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
#elif defined __GNUC__
#define DLLEXPORT(rettype) __extern_c__ __attribute__((visibility("default"))) rettype
#else
#define DLLEXPORT(rettype) __extern_c__ rettype
#endif

DLLEXPORT(void*) OpenStream(const char* host, const bool isMaster, const int intervalInMicroseconds, const uint8_t channelMask, int timeoutInSeconds);
DLLEXPORT(void) CloseStream(void* stream);

DLLEXPORT(void) GetStreamInfo(void* stream, int* packetSize, int* samplesPerPacket);

DLLEXPORT(int) ReadStream(void* stream, uint8_t* buffer, int bufferSize);
DLLEXPORT(int) DecodeStream(void* stream, const uint8_t* buffer, int bufferSize,
	int64_t* sampleBuffer0, int64_t* sampleBuffer1, int64_t* sampleBuffer2,
	uint8_t* errorBuffer0, uint8_t* errorBuffer1, uint8_t* errorBuffer2,
	float* ecuBuffer,
	int destinationBuffersSize, int* decodedSamplesCount);

DLLEXPORT(bool) StartStreamRecording(void* stream, const char* path);
DLLEXPORT(bool) StopStreamRecording(void* stream);

DLLEXPORT(void) DecodePackets(const uint8_t* src, int packetCount, const int samplesPerPacket, const int channelCount,
	int64_t* __restrict sampleOffsets,
	int64_t* sampleBuffer0, int64_t* sampleBuffer1, int64_t* sampleBuffer2,
	uint8_t* errorBuffer0, uint8_t* errorBuffer1, uint8_t* errorBuffer2,
	float* __restrict ecuBuffer);