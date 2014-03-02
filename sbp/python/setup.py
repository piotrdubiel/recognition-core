from distutils.core import setup, Extension

# the c++ extension module
extension_mod = Extension("pysbp", ["pysbp.cpp"])

setup(name="pysbp", ext_modules=[extension_mod])
