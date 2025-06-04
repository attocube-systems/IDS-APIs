/*H**********************************************************************
*
* DESCRIPTION :       
*       This is an exemplary implementation of the C# API Wrapper for the IDS streaming feature.
*       The program uses the SEN.StreamDLLWrapper which interact with the SEN.Stream native C library to       
*        stream and decode atleast 5000 position values with a streaming rate of 100 kHz from axis 1, 2 and 3.
*       Note that error buffers should contain values of 0s or 1s after successful decoding. Error flag 1 indicates that error detected on 
*       the corresponding position value whereas 0 indicates no error detected.
*
* CREATED : 17.03.2025
*           Copyright attocube systems GmbH, 2018.  All rights reserved.
*
*H*/

using SEN.StreamDLLWrapper;

//use unsafe to allow pointers and memory manipulation
static unsafe void streamIds()

{
    var api = new StreamDLLWrapper();

    int samplesToReceive = 5000;
    int sampleBufferSize = (samplesToReceive + 1024); //must be enough to hold atleast 1023 samples(minimum samples contained in a single IDS frame)

    byte[] buffer = new byte[60 * 1024];
    int bufferSize = buffer.Length;

    int decodedSamplesCount = 0;
    int* decodedSamplesCountPtr = &decodedSamplesCount;
    uint channelMask = 1 | 2 | 4; //adjust according to which axis needs to be streamed

    long[] axis1 = new long[sampleBufferSize];
    long[] axis2 = new long[sampleBufferSize];
    long[] axis3 = new long[sampleBufferSize];
    byte[] err1 = new byte[sampleBufferSize];
    byte[] err2 = new byte[sampleBufferSize];
    byte[] err3 = new byte[sampleBufferSize];


    IntPtr stream = api.Open_Stream("192.168.1.1", true, 10, channelMask);
    if (stream == IntPtr.Zero)
    {
        Console.WriteLine("/--Failed to open stream--/");
        return;
    }
    else
    {
        Console.WriteLine("/--Stream is open--/");
        api.Start_StreamRecording(stream, "testRecording.aws"); //by default file will be saved in /bin folder unless absolute or relative path is provided
        var bytesRead = api.Read_Stream(stream, buffer, buffer.Length);
        api.Decode_Stream(stream, buffer, bufferSize, axis1, axis2, axis3, err1, err2, err3, axis1.Length, decodedSamplesCountPtr);
        api.Stop_StreamRecording(stream);
        api.Close_Stream(stream);

        Console.WriteLine(decodedSamplesCount);
        for (int i = 0; i < decodedSamplesCount; i++)
        {
            Console.WriteLine($"axis1: {axis1[i]} (error flag: {err1[i]})\t axis2: {axis2[i]} (error flag: {err2[i]})\t axis3: {axis3[i]} (error flag: {err3[i]})\n");
        }
    }
    
}

streamIds();