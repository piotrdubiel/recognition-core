project(cnn)
cmake_minimum_required(VERSION 2.8)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(HEADERS
    ${PROJECT_INCLUDE_DIR}/CNNNetwork.h
    ${PROJECT_INCLUDE_DIR}/CNNLayer.h
    ${PROJECT_INCLUDE_DIR}/CNNWeight.h
    ${PROJECT_INCLUDE_DIR}/CNNLink.h
    ${PROJECT_INCLUDE_DIR}/CNNNeuron.h
)

set(SOURCES
    ${HEADERS}
    ${PROJECT_SOURCE_DIR}/CNNNetwork.cpp
    ${PROJECT_SOURCE_DIR}/CNNLayer.cpp
    ${PROJECT_SOURCE_DIR}/CNNWeight.cpp
    ${PROJECT_SOURCE_DIR}/CNNLink.cpp
    ${PROJECT_SOURCE_DIR}/CNNNeuron.cpp
)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

add_library(${PROJECT_NAME} SHARED ${SOURCES})
