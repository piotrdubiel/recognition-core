#include "utils.h"

PyObject* buildListFromFloatVector(std::vector<float> v) {
    int i;
    PyObject *lst = PyList_New(v.size());
    if (!lst) {
        return NULL;
    }
    for (i = 0; i < v.size(); i++) {
        PyObject* val = PyFloat_FromDouble(v[i]);
        if (!val) {
            Py_DECREF(lst);
            return NULL;
        }
        PyList_SET_ITEM(lst, i, val);   // reference to num stolen
    }
    return lst;
}

std::vector<float> buildFloatVectorFromList(PyObject* list) {
    Py_ssize_t size = PyList_Size(list);
    if (size < 0) {
        throw std::exception();
    }
    int i;
    std::vector<float> result;
    result.reserve(size);

    for (i = 0; i < size; i++) {
        result.push_back(PyFloat_AsDouble(PyList_GetItem(list, i)));   
    }
    return result;
}
