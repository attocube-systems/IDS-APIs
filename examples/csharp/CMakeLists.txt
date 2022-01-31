cmake_minimum_required(VERSION 3.14)
project(API_EXAMPLE VERSION 1.0 LANGUAGES CSharp)

include(CSharpUtilities)


set(SOURCE_FILES csharp.example.cs)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_REFERENCES
	"../../c#/CSharpAPIDLL.dll"
	"../../c#/Newtonsoft.Json.dll"
)