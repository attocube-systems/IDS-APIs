Python streaming - using the SEN.Stream.dll and python api wrapper


The SEN.Stream.dll provides functionality to read and decode streams of positional data from attocube interferometer devices. 
The dll contains functions that take input buffers, establish the initial http connection to the attocube interferometer device for streaming,  process streams, and write decoded data.

The Python wrapper contains modules to call and use functions from the SEN.Stream.dll. This is typically done using Python’s built-in ctypes libraries, which enable Python to load the DLL, define the C function signatures, and pass data between Python and C correctly.


Here's what to know when using SEN.Stream.dll through the python api wrapper

Main modules:
SEN.stream - the SEN.stream python module provides the interface to the core streaming functions of the SEN.Streaming.dll. It loads the DLL, sets up correct function signatures, wraps and exposes the C functions as simpler Python-callable methods.

	available methods in the SEN.stream module: 

		open:  Open Stream connection to device
		close: Close stream and stop recording if necessary
		read:  Read and decode position data in buffer, uses the methods readRaw and decodeBuffer; requires 1 param - bufferSize(int) to hold each sample 		data of axes, returns the decoded buffer.
		readRaw: Read raw position data in buffer(Undecoded data); requires 1 param - bufferSize(int), returns 	buffer of raw data
		decodeBuffer: Decode the raw position data buffer to positions in pm; requires 1 param(buffer containing the raw read data), returns 6 values - 	decodedBytes(int), 3 buffers holdong positional data and 3 buffers holding error flags   
		startRecording: Starts stream recording to file(aws file)
		stopRecording: Stop stream recording to file

	These methods can be called on an instance of the Stream object. The Stream is instantiated with device
	parameters as shown below:
		e.g: Stream(deviceIp, isMaster, intervalInMicroseconds, axis0=ax0, axis1=ax1, axis2=ax2) 
		>> Stream("192.168.1.1", true, 10, axis0=true, axis1=true, axis2=true) 


SEN.streaming - using python's multiprocessiong module, the SEN.streaming module contains functions that allows you to stream and record stream in the background generating the binary .aws stream file that can be exported to csv using the 
WaveExport or decoded & loaded into the code for further use through the streaming.loadFile() function.

	available methods in the SEN.streaming module:
		open: Open Stream connection to device
		loadFile: Load decoded content of recorded stream file
		startBackgroundStreaming: Starts position streaming to file in background
		stopBackgroundStreaming: Stops the position streaming
		isRunningBackgroundStreaming: Get state of background position reading


Running the background streaming example - Attempting to run Examples/streaming_example_backgroundStreaming.py as a file will throw an error (ImportError: attempted relative import with no known parent package). This is due to the use of relative imports primarily in SEN.py. In order to execute the backgroundStreaming example, the file needs to be called in the terminal as a python module.
	To do that(Taken that the api is located in the folder '08_Python_Library'): 
		- run the command "python -m 08_Python_Library.streaming.Examples.streaming_example_backgroundStreaming" instead of "python '08_Python_Library\streaming\Examples\streaming_example_backgroundStreaming.py'" 
		- In the terminal make sure the command is not run in the api folder itself but one level higher. for example: sif the api folder '08_Python_Library' is located on "C:\Users\user\Desktop\08_Python_Library>", go one level higher like "C:\Users\user\Desktop>"

finally execute the example like this - C:\Users\user\Desktop> python -m 08_Python_Library.streaming.Examples.streaming_example_backgroundStreaming


If you by any means want to execute the example as a file instead of python module, then you must change the relative imports in the SEN.py and Examples\streaming_example_backgroundStreaming.py to absolute imports.
e.g changing relative to absolute:
	'from . import ACS' -> 'import ACS'
	'from .network import Network' -> 'from network import Network'
	'from ... import SEN' -> 'import SEN' (in the example file)

Note: Pay attention to the respective paths of the modules being imported. In the example file you may need to append the parent folder path to system path.
	api_folder_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../..'))
	sys.path.append(api_folder_path)