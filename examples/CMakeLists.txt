cmake_minimum_required(VERSION 3.16)
project(example)

set(ATTOPATH ../c-dll/linux/64bit)

include_directories(${ATTOPATH})

add_executable(${PROJECT_NAME} c.example.c)
find_library(ATTOCUBE_LIB attocubeJSON ${ATTOPATH})

target_link_libraries(${PROJECT_NAME} "${ATTOCUBE_LIB}")
