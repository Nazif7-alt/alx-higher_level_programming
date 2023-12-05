#include <stdlib.h>
#include <stdio.h>

/**
 * print_python_list_info - function that prints some basic
 * info about Python lists
 * @p: python list
 */

void print_python_list_info(PyObject *p)
{
    int elem;

    printf("[*] Size of the Python List = %lu\n", Py_SIZE(p));
    printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
    for (elem = 0; elem < Py_SIZE(p); elem++)
        printf("Element %d: %s\n", elem, Py_TYPE(PyList_GetItem(p, elem))->tp_name);
}

int main(void)
{
    Py_Initialize();

    // Create a Python list
    PyObject *pyList = PyList_New(4);
    PyList_SetItem(pyList, 0, PyLong_FromLong(1));
    PyList_SetItem(pyList, 1, PyFloat_FromDouble(3.14));
    PyList_SetItem(pyList, 2, PyUnicode_DecodeUTF8("Hello", 5, NULL));
    PyList_SetItem(pyList, 3, PyBool_FromLong(1));

    // Print information about the Python list
    print_python_list_info(pyList);

    // Cleanup
    Py_XDECREF(pyList);
    Py_Finalize();

    return 0;
}
