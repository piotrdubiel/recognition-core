#include <stdlib.h>
#include <Python/Python.h>
#include <iostream>
#include "SBPNetwork.h"
#include "utils.h"

SBPNetwork* network = NULL;

static PyObject* init(PyObject* self) {
    if (network != NULL) {
        delete network;
    }
    network = new SBPNetwork();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject* load(PyObject* self) {
    if (network != NULL) {
        std::cerr << "Deleting old network" << std::endl;
        delete network;
    }
    network = new SBPNetwork();
    network->add_layer(2, 2);
    network->add_layer(2, 1);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject* add_layer(PyObject* self, PyObject* args) {
    if (network == NULL) {
        return NULL;
    }
    
    Py_ssize_t neuron_size = PyTuple_Size(args);

    if (!neuron_size) {
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_TypeError, "At least one argument should be provided");
        }
        return NULL;
    }

    int i;
    std::vector<vector<float> > weights;
    weights.reserve(neuron_size);
    for (i = 0; i < neuron_size; i++) {
        vector<float> w = buildFloatVectorFromList(PyTuple_GetItem(args, i));
        weights.push_back(w);
        vector<float>::iterator it;
    }
    network->add_layer(weights);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject* classify(PyObject* self, PyObject* args)
{
    PyObject* argObjects;
    if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &argObjects)) {
        return NULL;
    }

    std::vector<float> x = buildFloatVectorFromList(argObjects);
    return buildListFromFloatVector(network->classify(x));
}

static PyObject* train(PyObject* self, PyObject* args)
{
    PyObject* inputObject;
    PyObject* outputObject;
    if (!PyArg_ParseTuple(args, "OO", &inputObject, &outputObject)) {
        return NULL;
    }

    std::vector<float> input = buildFloatVectorFromList(inputObject);
    std::vector<float> output = buildFloatVectorFromList(outputObject);

    network->train(input, output, 0.1);
    Py_INCREF(Py_None);
    return Py_None;
}


static char helloworld_docs[] =
    "helloworld( ): Any message you want to put here!!\n";

static PyMethodDef sbp_functions[] = {
    {"classify", (PyCFunction)classify, METH_VARARGS, helloworld_docs},
    {"load", (PyCFunction)load, METH_NOARGS, helloworld_docs},
    {"init", (PyCFunction)init, METH_NOARGS, helloworld_docs},
    {"add_layer", (PyCFunction)add_layer, METH_VARARGS, helloworld_docs},
    {"train", (PyCFunction)train, METH_VARARGS, helloworld_docs},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initpysbp(void)
{
    Py_InitModule3("pysbp", sbp_functions, "Extension module example!");
}
