C# API WRAPPER - SEN.StreamDLLWrapper.dll
 
The C# API wrapper provides a managed interface to access and invoke the functions exposed by the SEN streaming C DLL(SEN.Stream.dll) in a C# application. 
It uses P/Invoke (Platform Invocation Services) to call the unmanaged C functions, enabling seamless integration between C and C# code, while handling data type conversions and memory management. This wrapper simplifies calling C library methods from C# and ensures compatibility with .NET applications.


When using the SEN.StreamDLLWrapper.dll in your project, here’s what you need to know about where to place it and how to reference it in your .NET application:

Required dlls:
	- SEN.StreamDLLWrapper.dll: the C# wrapper
 	- SEN.Stream.dll: the actual C_dll


1. Placing the two DLLs:
	- The C# API Wrapper DLL (SEN.StreamDLLWrapper.dll): The C# API wrapper DLL is a managed assembly, which means it is part of your .NET project. You need to reference it in your project so that you can use its functionality to interact with the C DLL.
You don't need to place the C# wrapper DLL directly in the executable folder at build time. Instead, you should ensure that it's referenced by your .NET project. When you build the project, Visual Studio (or the .NET CLI) will output this DLL to your project’s output directory, typically either bin\Debug or bin\Release.

	- The C_DLL (SEN.Stream.dll) is the original Streaming library that the C# API wrapper(SEN.StreamDLLWrapper.dll) interacts with using P/Invoke. This DLL needs to be located in the platform-specific directory where the application can find and load it during runtime. 
The C DLL should be placed in the same directory as the application’s executable. This ensures that the application can find the unmanaged library without issues. Missing or incorrectly placing the SEN.Stream.dll can result in runtime errors.
	example target location: YourProject\bin\Debug\SEN.Stream.dll


2. Referencing the C# API Wrapper DLL(SEN.StreamDLLWrapper):
When developing in Visual Studio (or using the .NET CLI), you need to reference the C# API wrapper DLL in your project. You’ll need to manually add a reference.

	> Right-click on your project in Solution Explorer > Add > Reference > Browse and select the C# API wrapper(SEN.StreamDLLWrapper.dll) file.


3. Usage: Once the DLL is referenced, you can use its methods just like any other .NET class. You’ll call the methods exposed in your wrapper, which in turn will call the unmanaged C functions from the C DLL.
	Example of calling a method from the C# API wrapper:
		using SEN.StreamDLLWrapper;
		class Program
		{
    			static void Main()
    			{
        		 	var wrapper = new StreamDLLWrapper();
       			 	wrapper.Open_Stream("192.168.1.1", true, 10, channelMask); // Calling a function that interacts with the C DLL
    			}
		}
