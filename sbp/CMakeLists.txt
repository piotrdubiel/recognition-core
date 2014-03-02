project(sbp)
cmake_minimum_required(VERSION 2.8)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (PYTHON_BINDINGS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/python)

if(BUILD_PYTHON_BINDINGS)
    find_package(PythonInterp REQUIRED)
    find_package(PythonLibs REQUIRED)
    execute_process(
        COMMAND ${PYTHON_EXECUTABLE} -c "from distutils import sysconfig; print(sysconfig.get_python_lib(1,0,prefix=''))"
        OUTPUT_VARIABLE PYTHON_INSTDIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if(PYTHONLIBS_FOUND)
        include_directories(${PYTHON_INCLUDE_DIR})
    endif()
endif()

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
    ${PROJECT_SOURCE_DIR}/SBPNetwork.cpp
    ${PROJECT_SOURCE_DIR}/SBPLayer.cpp
    ${PROJECT_SOURCE_DIR}/SBPNeuron.cpp
)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

if(BUILD_PYTHON_BINDINGS)
    add_library(pysbp ${PYTHON_BINDINGS})
    set_target_properties(sbp PROPERTIES PREFIX "")

    target_link_libraries(sbp pysbp)
endif()
