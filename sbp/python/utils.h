#ifndef SBP_UTILS_H
#define SBP_UTILS_H

#include <Python/Python.h>
#include <vector>

PyObject* buildListFromFloatVector(std::vector<float> v);
std::vector<float> buildFloatVectorFromList(PyObject* list);

#endif //SBP_UTILS_H
