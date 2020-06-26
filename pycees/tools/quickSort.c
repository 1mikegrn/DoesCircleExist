#include <Python.h>
#include <stdio.h>

void swap(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array on the basis of pivot element
int partition(double* array, int low, int high) {
    
        // Select the pivot element
        double pivot = array[high];
        int i = (low - 1);

        // Put the elements smaller than pivot on the left 
        // and greater than pivot on the right of pivot
        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;
                swap(&array[i], &array[j]);
            }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void qSort(double* array, int low, int high) {
    if (low < high) {
        
        // Select pivot position and put all the elements smaller 
        // than pivot on left and greater than pivot on right
        int pi = partition(array, low, high);
        
        // Sort the elements on the left of pivot
        qSort(array, low, pi - 1);
        
        // Sort the elements on the right of pivot
        qSort(array, pi + 1, high);
    }
}

// convert PyObject list into C list, sort, and build resultant PyObject list
static PyObject* convertList(PyObject* inputList, int inputListLength) {

    // generate a heap list where the c objects can be dynamically placed
    double* list_in_c = (double*) malloc(inputListLength*sizeof(double*));

    // extract python objects and place in C list
    for (int index = 0; index < inputListLength; index++) {
        PyObject *item;
        item = PyList_GetItem(inputList, index);
        list_in_c[index] = PyFloat_AsDouble(item);
    }

    // sort C list using quickSort
    qSort(list_in_c, 0, inputListLength - 1);

    // iterate through C list generating PyObjects, place objects in python list
    PyObject* sorted = PyList_New(inputListLength);
    for (int index = 0; index < inputListLength; index++) {
        PyObject* val = Py_BuildValue("d", list_in_c[index]);
        PyList_SetItem(sorted, index, val);
    }

    // free C list and return generated python list object
    free(list_in_c);
    return sorted;
}

// parse input arguments, build resulting list to return to Python
static PyObject* parseList(PyObject *self, PyObject *args) {

    PyObject *inputList;
    int inputListLength;

    // parse input into C-level PyObject
    if (!PyArg_ParseTuple(args, "O", &inputList)){
        return NULL;
    }

    // get length of object (length of the input list)
    inputListLength = PyObject_Length(inputList);

    return Py_BuildValue("O", convertList(inputList, inputListLength));
}

static char qSortDocs[] = 
    "Sorts floating point numbers in a list using quickSort\n";

static PyMethodDef quickSortMethod[] = {
 {"quickSort", (PyCFunction) parseList, METH_VARARGS, qSortDocs},
 {NULL,NULL,0,NULL}
};

static struct PyModuleDef quickSortModule = {
    PyModuleDef_HEAD_INIT,
    "quickSort",
    NULL,
    -1,
    quickSortMethod
};

PyMODINIT_FUNC PyInit_quickSort(void){
    return PyModule_Create(&quickSortModule);
}

// int main(){
//     double x[] = {0.962990, 0.520871, 0.489694, 0.346397, 0.233498, 0.096399, 0.170206, 0.090712, 0.663923, 0.432472};
//     int n = sizeof(x)/sizeof(*x);
//     qSort(x, 0, n-1);
//     for (int i=0; i<n; i++) {
//         printf("%f, ", x[i]);
//     }
// }