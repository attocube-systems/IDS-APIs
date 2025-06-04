#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>
#include <inttypes.h>
//#include <unistd.h>
#include "IDS.NativeC.h"
#include <corecrt_memcpy_s.h>

/*H**********************************************************************
*
* DESCRIPTION :
*       This is an exemplary implementation of the C API for the IDS streaming feature.
*       The program loops the data recording until at least 5000 (note that only packages of max. 1023 values are received)samples were streamed and decoded.
*       The received data is written into a .txt file.
*       Furthermore the data gets recorded into a .aws file using the StartStreamRecording function.
*
* CREATED : 29.10.2018; UPDATED : 17.03.2025
*           Copyright attocube systems GmbH, 2018.  All rights reserved.
*
*H*/

int main()
{
    // the buffer for raw stream data
    unsigned char buffer[16 << 10]; // 16k byte
    int bytesInBuffer = 0;

    // the number of samples we want to receive
    const int samplesToReceive = 5000;

    // note: DecodeStream can only decode full IDS frames. therefore trying
    // to decode less samples than a full frame contains returns 0 samples. IDS frames
    // hold up to 1023 samples, depending on streaming rate and number of channels.
    // to allow decoding arbitrary "samplesToReceive" number of samples, we simply
    // overallocate the channel buffers by 1022 samples
    const int sampleBuffersSize = samplesToReceive + 1022;
    int64_t channelX[sampleBuffersSize];
    int64_t channelY[sampleBuffersSize];
    int64_t channelZ[sampleBuffersSize];   
    
    uint8_t errX[sampleBuffersSize];
    uint8_t errY[sampleBuffersSize];
    uint8_t errZ[sampleBuffersSize];

    void* stream = OpenStream("192.168.1.1", true, 10, 1); //samplerate 100kHz and axis 1

    // record the streaming into a .aws file that can be decoded with WAVEExport
    StartStreamRecording(stream, "test.aws");

    // retrieve values continously until more that 5000 samples were decoded (more samples were streamed)
    for (int samplesInBuffers = 0; samplesInBuffers < samplesToReceive;)
    {
        bytesInBuffer += ReadStream(stream, buffer + bytesInBuffer, sizeof(buffer) - bytesInBuffer);

        int64_t* axes[] =
        {
               channelX + samplesInBuffers,
               channelY + samplesInBuffers,
               channelZ + samplesInBuffers
        };
        uint8_t* errorFlags[] =
        {
               errX + samplesInBuffers,
               errY + samplesInBuffers,
               errZ + samplesInBuffers
        };

        int decodedSamplesCount;

		//passing nullptr for unwanted buffers, if more than 1 axis is streamed replace the respective nullptr with the necessary buffers  
        int decodedBytes = DecodeStream(stream, buffer, bytesInBuffer, axes[0], nullptr, nullptr,
            errorFlags[0], nullptr, nullptr, sampleBuffersSize - samplesInBuffers, &decodedSamplesCount);
         
        bytesInBuffer -= decodedBytes;
        samplesInBuffers += decodedSamplesCount;
        memmove_s(buffer, sizeof(buffer), buffer + decodedBytes, bytesInBuffer);
    }

    StopStreamRecording(stream);
    CloseStream(stream);

    // write the 5000 samples (although we received more) into a .txt file
    size_t n = sizeof(channelX) / sizeof(int64_t);
    FILE* pFile;
    errno_t err = fopen_s(&pFile, "test.txt", "w");
    fputs("x-values \t\t\t y-values \t\t\t z-Values\n", pFile);
    for (int i = 0; i < samplesToReceive; ++i)
    {
        fprintf(pFile, "%I64d (error flag: %u)\n", channelX[i], errX[i]);
    }
    fclose(pFile);


}

