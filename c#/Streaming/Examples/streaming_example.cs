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
    int packetSize, samplesPerPacket, decodedSamplesCount;

    int durationInSeconds = 5;

    uint channelMask = 1 | 2 | 4; //adjust according to which axis needs to be streamed

    IntPtr stream = api.Open_Stream("192.168.1.1", true, 10, channelMask, 3);
    if (stream == IntPtr.Zero)
    {
        Console.WriteLine("/--Failed to open stream--/");
        return;
    }
    else
    {
        DateTime start = DateTime.Now;
        while ((DateTime.Now - start).TotalSeconds < durationInSeconds)
        {
            api.Get_StreamInfo(stream, out packetSize, out samplesPerPacket);
            byte[] buffer = new byte[packetSize]; //single packet buffer

            long[] axis1 = new long[samplesPerPacket];
            long[] axis2 = new long[samplesPerPacket];
            long[] axis3 = new long[samplesPerPacket];
            byte[] err1 = new byte[samplesPerPacket];
            byte[] err2 = new byte[samplesPerPacket];
            byte[] err3 = new byte[samplesPerPacket];

            float[] ecuData = new float[4];

            api.Start_StreamRecording(stream, "testRecording.aws"); //by default file will be saved in /bin folder unless absolute or relative path is provided
            var bytesRead = api.Read_Stream(stream, buffer, buffer.Length);
            api.Decode_Stream(stream, buffer, bytesRead, axis1, axis2, axis3, err1, err2, err3, ecuData, axis1.Length, &decodedSamplesCount);

            Console.WriteLine($"ecu: {ecuData[0]}°C; {ecuData[1]}%; {ecuData[2]}hPa, {ecuData[3]}");
            Console.WriteLine($"axis1: {axis1[0]} (error flag: {err1[0]})\t axis2: {axis2[0]} (error flag: {err2[0]})\t axis3: {axis3[0]} (error flag: {err3[0]})\n");
        }
        api.Stop_StreamRecording(stream);
        api.Close_Stream(stream);

    }

}

streamIds();