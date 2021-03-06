#include <stdio.h>
#include <wchar.h>
#define PY_SSIZE_T_CLEAN
#include <Python.h>

/**
 * spammodule.c follows the tutorial from the Offical CPython API
 * Documentation:
 *
 *      https://docs.python.org/3/extending/extending.html
 *
 * This module simply exposes the C system() API directly to python. After
 * installation, it can be imported and used within python as follows:
 *
 * >>> import spam
 * >>> spam.system('ls')
 */

static PyObject *SpamError;

static PyObject * spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command)) {
        return NULL;
    }
    sts = system(command);
    if (sts < 0) {
        PyErr_SetString(SpamError, "System command failed");
        return NULL;
    }
    return PyLong_FromLong(sts);
}

static PyMethodDef SpamMethods[] = {
    {
        "system",  // name of module
        spam_system,  // module documentation
        METH_VARARGS,  // size of per-interpreter state of the module
        "Execute a shell command."  //
    },
    {NULL}
};

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",
    "docstring for my c module",
    -1,
    SpamMethods,
};


PyMODINIT_FUNC PyInit_spam(void)
{
    PyObject *m;

    m = PyModule_Create(&spammodule);
    if (m == NULL) {
        return NULL;
    }

    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_XINCREF(SpamError);
    if (PyModule_AddObject(m, "error", SpamError) < 0) {
        Py_XDECREF(SpamError);
        Py_CLEAR(SpamError);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
