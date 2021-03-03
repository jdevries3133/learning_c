#include <stdio.h>
#include <wchar.h>
#define PY_SSIZE_T_CLEAN
#include <Python.h>


static long long c_factorial(int num)
{
    long long result = 1;
    for (int i = 1; i < num; i++) {
        result *= i;
    }
    return result;
}

static PyObject *FactoError;

static PyObject * factorial(PyObject *self, PyObject *args)
{
    const int input;

    if (!PyArg_ParseTuple(args, "i", &input)) {
        return NULL;
    }

    if (input > 21) {  // NOLINT
        PyErr_SetString(FactoError, "Input is too large. (1 < input < 21)");
        return NULL;
    }

    long long result = c_factorial(input);  // NOLINT
    return PyLong_FromLongLong(result);
}

static PyMethodDef FactoMethods[] = {
    {
        "factorial",  // name of method
        factorial,  // function
        METH_VARARGS,  // size of per-interpreter state of the module
        "Get the factorial quickly"  // function __doc__
    },
};

static struct PyModuleDef factomodule = {
    PyModuleDef_HEAD_INIT,
    "facto",
    "Fast factorializer.",
    -1,
    FactoMethods,
};


PyMODINIT_FUNC PyInit_facto(void)
{
    PyObject *m;

    m = PyModule_Create(&factomodule);
    if (m == NULL) {
        return NULL;
    }

    FactoError = PyErr_NewException("facto.error", NULL, NULL);
    Py_XINCREF(FactoError);
    if (PyModule_AddObject(m, "error", FactoError) < 0) {
        Py_XDECREF(FactoError);
        Py_CLEAR(FactoError);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
