project(sbp)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Debug)
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
set(PYTHON_BINDINGS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/python)

set(HEADERS
    ${PROJECT_INCLUDE_DIR}/SBPNetwork.h
    ${PROJECT_INCLUDE_DIR}/SBPLayer.h
    ${PROJECT_INCLUDE_DIR}/SBPNeuron.h
)

set(PYTHON_BINDINGS
    ${PYTHON_BINDINGS_DIR}/pysbp.cpp
)

set(SOURCES
    ${HEADERS}
    #${PYTHON_BINDINGS}
    ${PROJECT_SOURCE_DIR}/SBPNetwork.cpp
    ${PROJECT_SOURCE_DIR}/SBPLayer.cpp
    ${PROJECT_SOURCE_DIR}/SBPNeuron.cpp
)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_executable(xor ${SOURCES} ${PROJECT_TESTS_DIR}/xor.cpp)
