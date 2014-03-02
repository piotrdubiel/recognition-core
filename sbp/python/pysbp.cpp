#include <Python/Python.h>

static PyObject* classify(PyObject* self, PyObject* args)
{
    return Py_BuildValue("s", "Hello, Python extensions!!");
}

static char helloworld_docs[] =
    "helloworld( ): Any message you want to put here!!\n";

static PyMethodDef classify_funcs[] = {
    {"classify", (PyCFunction)classify,
     METH_NOARGS, helloworld_docs},
    {NULL}
};

DL_EXPORT(void) initpysbp(void)
{
    Py_InitModule3("pysbp", classify_funcs, "Extension module example!");
}
