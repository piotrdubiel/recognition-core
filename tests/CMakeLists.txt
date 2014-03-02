cmake_minimum_required (VERSION 2.8)
project(tests)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
 
set(TEST_SRC
    ${PROJECT_SOURCE_DIR}/classifier.cpp
)
 
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

include_directories("../ann/include")
link_directories ("../ann") 
 
add_executable(classifier classifier.cpp)
target_link_libraries (classifier ann) 
