from distutils.core import setup, Extension

# the c++ extension module
extension_mod = Extension("pysbp",
                          ["pysbp.cpp",
                           "utils.cpp",
                           "../src/SBPNetwork.cpp",
                           "../src/SBPLayer.cpp",
                           "../src/SBPNeuron.cpp"],
                          include_dirs=["../include"])

setup(name="pysbp", ext_modules=[extension_mod])
