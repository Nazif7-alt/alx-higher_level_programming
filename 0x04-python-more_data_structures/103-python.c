#include <stdio.h>
#include <Python.h>

// Function to print information about a Python tuple
// Note: This code is inspired by Nazif's work

/**
 * print_python_tuple - Prints tuple information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_tuple(PyObject *p)
{
    long int size, i;
    PyTupleObject *tuple;
    PyObject *obj;

    // Get the size of the tuple
    size = ((PyVarObject *)(p))->ob_size;
    // Cast the Python object to a tuple
    tuple = (PyTupleObject *)p;

    printf("[*] Python tuple info\n");
    printf("[*] Size of the Python Tuple = %ld\n", size);

    // Loop through each element in the tuple
    for (i = 0; i < size; i++)
    {
        // Get the i-th element
        obj = tuple->ob_item[i];
        // Print information about the element's type
        printf("Element %ld: %s\n", i, ((obj)->ob_type)->tp_name);
    }
}

// Main function for testing the print_python_tuple function
int main(void)
{
    PyObject *my_tuple, *elem1, *elem2, *elem3;

    // Create different types of Python objects for tuple elements
    elem1 = PyLong_FromLong(10);
    elem2 = PyFloat_FromDouble(3.14);
    elem3 = PyUnicode_DecodeUTF8("Hello", 5, "strict");

    // Pack the elements into a tuple
    my_tuple = PyTuple_Pack(3, elem1, elem2, elem3);

    // Print information about the tuple
    print_python_tuple(my_tuple);

    // Don't forget to free the allocated objects
    Py_DECREF(elem1);
    Py_DECREF(elem2);
    Py_DECREF(elem3);
    Py_DECREF(my_tuple);

    return 0;
}
