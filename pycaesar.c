#include <Python.h>
#include <stdlib.h>
#include "caesar.h"

static PyObject* pycaesar_caesar(PyObject* self, PyObject* args) {
    char* input;
    int shift;

    if (!PyArg_ParseTuple(args, "si", &input, &shift))
        return NULL;

    char* output = malloc(strlen(input) * sizeof(char));
    caesar(output, input, shift);
    PyObject* output_obj = Py_BuildValue("s", output);
    free(output);
    return output_obj;
}

static PyMethodDef pycaesar_methods[] = {
    {"caesar", pycaesar_caesar, METH_VARARGS, "Execute Caesar cipher algorithm."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

PyMODINIT_FUNC initpycaesar() {
    Py_InitModule("pycaesar", pycaesar_methods);
}

int main(int argc, char** argv)
{
    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(argv[0]);

    /* Initialize the Python interpreter. Required. */
    Py_Initialize();

    /* Add a static module */
    initpycaesar();
}
