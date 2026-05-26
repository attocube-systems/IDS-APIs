#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "SEN.Stream.h"

/*H**********************************************************************
*
* DESCRIPTION :
*       This is an exemplary implementation of the C API for the SEN streaming feature.
*       The program streams and decodes 1023 position values with a streaming rate of 100 kHz from axis 1, 2 and 3.
*       Note that error buffers should contain values of 0s or 1s after successful decoding. Error flag 1 indicates that error detected on
*       the corresponding position value whereas 0 indicates no error detected.
*       The ecu buffer holds the 4 ecu data: temperature, humidity, pressure and RefractiveIndex respectively
*
* CREATED : 29.10.2018; UPDATED : 17.03.2025
*           Copyright attocube systems GmbH, 2018.  All rights reserved.
*
*H*/

typedef struct {
    int size;
    unsigned char* data;
}Buffer;

typedef struct {
    int packetSize;
    int samplesPerPacket;
}StreamInfo;

int main()
{
    char deviceIp[] = "192.168.1.1";
    int timeoutInSecs = 10;

    // stream data with 100 kHz from axis 1, 2 and 3; Adjust accordingly to preferred axis, e.g. channel mask 1 | 4 represents 1st and 3rd axis  
    void* stream = OpenStream(deviceIp, true, 10, 1 | 2 | 4, timeoutInSecs);
    StreamInfo streamInfo = { 0 };
    GetStreamInfo(stream, &streamInfo.packetSize, &streamInfo.samplesPerPacket);

    Buffer buffer = {
        .size = streamInfo.packetSize,
        .data = (unsigned char*)malloc(streamInfo.packetSize)
    };

    float durationInSecs = 5.0;
    clock_t start = clock();
    while (((double)(clock() - start)) / CLOCKS_PER_SEC < durationInSecs)
    {

        if (buffer.data == NULL) {
            printf("Buffer allocation failed!\n");
            return EXIT_FAILURE;
        }

        int count = ReadStream(stream, buffer.data, buffer.size);

        // declare position buffers for selected axis
        int64_t axis1[1024],
            axis2[1024],
            axis3[1024];

        //declare error buffers for selected axis
        uint8_t error1[1024],
            error2[1024],
            error3[1024];

        float ecuBuffer[4];

        int destBufferSize = sizeof(axis1) * 3;

        int decodedSamplesCount;

        // Number of axis passed into the OpenStream() should correspond to the number of valid buffers passed into the DecodeStream() function.

        //DecodeStream function requires 3buffers each for both position and error samples however, if less than 3 axis were passed into the OpenStream() function, 
        // pass nullptr repectively for the unwanted buffers. 
        int decodedBytes = DecodeStream(stream, buffer.data, count, axis1, axis2, axis3, error1, error2, error3, ecuBuffer, destBufferSize, &decodedSamplesCount);


        printf("Decoded samples count: %i\nDecoded bytes: %i\n", decodedSamplesCount, decodedBytes);
        printf("temp: %f; hum: %f; press: %f; rI: %f\n", ecuBuffer[0], ecuBuffer[1], ecuBuffer[2], ecuBuffer[3]);
        printf("axis1: %I64d (error flag: %u)\t axis2: %I64d (error flag: %u)\t axis3: %I64d (error flag: %u)\n\n", axis1[0], error1[0], axis2[0], error2[0], axis3[0], error3[0]); //print first samples each
    }
    CloseStream(stream);
    free(buffer.data);
    return EXIT_SUCCESS;
}

