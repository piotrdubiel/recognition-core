cmake_minimum_required (VERSION 2.8)
project(recognition-core)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
 
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
 
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

find_package(Valgrind)
if(VALGRIND_FOUND)
    execute_process(COMMAND valgrind bin/classifier)   
endif(VALGRIND_FOUND)

add_subdirectory(ann)
add_subdirectory(tests)
