C Streaming API examples - using the SEN.Stream.dll for C applications

The SEN.Stream.dll provides functionality to read and decode streams of positional data from attocube interferometer devices.  
The dll contains functions that take input buffers, establish the initial http connection to the attocube interferometer device for streaming, process streams, and write decoded data.

Here's what to know when using SEN.Stream.dll in C applications
The DLL provides the following core functions:
	OpenStream
	CloseStream
	ReadStream
	DecodeStream
	DecodePackets
	StartStreamRecording
	StopStreamRecording

The basic steps required to get the dll running with your C application
Step 1: Include the DLL's Header
	In your C/C++ project, you need to include the header for the DLL. Ensure the header file can be found in the project file path.
	e.g. include "SEN.Stream.h"


Step 2: Link the DLL: You need to link your C++ project with the SEN.Stream.dll. If you are using an import library (like SEN.Stream.lib), ensure it is linked correctly in your project settings.
 - In Visual Studio:
	Open the Project Properties.
	Go to Configuration Properties > Linker > Input.
	Add SEN.Stream.lib to Additional Dependencies.

 - In GCC/MinGW:
	g++ -o MyApp MyApp.cpp -L. -lSEN.Stream


Step 3: Ensure DLL Availability
	Make sure that SEN.Stream.dll is accessible when running your application:
	Place SEN.Stream.dll in the same directory as the executable.
	Or add the directory containing  SEN.Stream.dll to the system’s PATH environment variable.
