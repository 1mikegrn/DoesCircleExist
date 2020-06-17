#include <Python.h>
#include <stdio.h>

static void changeDir(int* step, char d) {
    int wave[6][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,0},{0,1}};

    for (int j = 1; j < 5; j++) {
        if (wave[j][0] == step[0] && wave[j][1] == step[1]) {
            if (d == 'L') {
                step[0] = wave[j-1][0];
                step[1] = wave[j-1][1];
                return;
            } else {
                step[0] = wave[j+1][0];
                step[1] = wave[j+1][1];  
                return;              
            }
        }
    }
}

static char* CitemCheck(PyObject *commandString, int commandStringLength) {

    int pos[] = {0, 0};
    int step[] = {0, 1};

    PyObject *encodedString = PyUnicode_AsEncodedString(
        commandString, "UTF-8", "strict"
    );

    char *commandChars = PyBytes_AsString(encodedString);

    for (int n = 0; n < 4; n++){
        for (int i = 0; commandChars[i] != '\0'; i++) {
            if (commandChars[i] == 'G') {
                for (int j = 0; j<2; j++) {
                    pos[j] += step[j];
                }
            } else {
                changeDir(step, commandChars[i]);
            }   
        }
    }

    Py_DECREF(encodedString);

    if (pos[0] == 0 && pos[1] == 0){
        char string[] = "YES\0";
        return string;
    }
    else {
        char string[] = "NO\0";
        return string;
    }
}

static PyObject *ClistCheck(PyObject *commandList, int commandListLength) {

    PyObject *results = PyList_New(commandListLength);

    for (int index = 0; index < commandListLength; index++) {
        PyObject *commandString;
        commandString = PyList_GetItem(commandList, index);
        int commandStringLength = PyObject_Length(commandString);

        PyObject* pyItem = Py_BuildValue(
            "s", CitemCheck(commandString, commandStringLength)
        );
        PyList_SetItem(results, index, pyItem);
    }
    Py_DECREF(commandList);
    return results;
}

static PyObject *parseListCheck(PyObject *self, PyObject *args) {
    PyObject *commandList;
    int commandListLength;

    if (!PyArg_ParseTuple(args, "O", &commandList)){
        return NULL;
    }

    commandListLength = PyObject_Length(commandList);

    return Py_BuildValue("O", ClistCheck(commandList, commandListLength));
}

static char listCheckDocs[] = 
    "Checks the command string to see if circle exists\n";

static PyMethodDef listCheck[] = {
 {"listCheck", (PyCFunction) parseListCheck, METH_VARARGS, listCheckDocs},
 {NULL,NULL,0,NULL}
};

static struct PyModuleDef DCE = {
    PyModuleDef_HEAD_INIT,
    "listCheck",
    NULL,
    -1,
    listCheck
};

PyMODINIT_FUNC PyInit_cExt(void){
    return PyModule_Create(&DCE);
}