#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>
#include "SEN.NativeC.h"

/*H**********************************************************************
*
* DESCRIPTION :
*       This is an exemplary implementation of the C API for the SEN streaming feature.
*       The program streams and decodes 1023 position values with a streaming rate of 100 kHz from axis 1, 2 and 3.
*       Note that error buffers should contain values of 0s or 1s after successful decoding. Error flag 1 indicates that error detected on 
*       the corresponding position value whereas 0 indicates no error detected.
*
* CREATED : 29.10.2018; UPDATED : 17.03.2025
*           Copyright attocube systems GmbH, 2018.  All rights reserved.
*
*H*/

int main()
{
    char deviceIp[] = "192.168.1.1";
    
    // stream data with 100 kHz from axis 1, 2 and 3; Adjust accordingly to preferred axis, e.g. channel mask 1 | 4 represents 1st and 3rd axis  
    void* stream = OpenStream(deviceIp, true, 10, 1 | 2 | 4); 
    
    unsigned char buffer[8192 << 1]; /* 8192 * 2 */
    int count = ReadStream(stream, buffer, sizeof(buffer));

    /** @todo Get rid of the typecast */
    printf("Size of buffer is: %lu\nCount is: %i\n", (long unsigned int)sizeof(buffer), count);
    
    printf("");

    // declare position buffers for selected axis
    int64_t axis1[1024],
        axis2[1024],
        axis3[1024];    
    
	//declare error buffers for selected axis
    uint8_t error1[1024],
        error2[1024],
        error3[1024];

    int destBufferSize = sizeof(axis1) * 3;

    int decodedSamplesCount;
    
    // Number of axis passed into the OpenStream() should correspond to the number of valid buffers passed into the DecodeStream() function.

    //DecodeStream function requires 3buffers each for both position and error samples however, if less than 3 axis were passed into the OpenStream() function, 
	// pass nullptr repectively for the unwanted buffers. 
    int decodedBytes = DecodeStream(stream, buffer, count, axis1, axis2, axis3, error1, error2, error3, destBufferSize, &decodedSamplesCount);

    CloseStream(stream);
   
    printf("Decoded samples count: %i\nDecoded bytes: %i\n", decodedSamplesCount, decodedBytes);
    for (int i = 0; i < decodedSamplesCount; ++i)
    {
		//print decoded position values and error flags. Remember to remove unwanted buffers from the print statement.
         printf("axis1: %I64d (error flag: %u)\t axis2: %I64d (error flag: %u)\t axis3: %I64d (error flag: %u)\n", axis1[i], error1[i], axis2[i], error2[i], axis3[i], error3[i]);

    }

    printf("Done!\n");
    return EXIT_SUCCESS;
}

