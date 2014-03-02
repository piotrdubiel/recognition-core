project(pysbp)

FIND_PACKAGE(PythonLibs)

INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})

target_link_libraries(sbp)
