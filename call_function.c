#include <python2.7/Python.h>
#include <stdlib.h>
int main(void)
{
   // Set PYTHONPATH TO working directory
   setenv("PYTHONPATH",".",1);

   // creating py objecs
   PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *presult;


   // Initialize the Python Interpreter
   Py_Initialize();


   // Build the name object
   pName = PyString_FromString((char*)"arbName"); //name of py file

   // Load the module object
   pModule = PyImport_Import(pName);


   // pDict is a borrowed reference 
   pDict = PyModule_GetDict(pModule);


   // pFunc is also a borrowed reference 
   pFunc = PyDict_GetItemString(pDict, (char*)"someFunction"); //function name

   if (PyCallable_Check(pFunc))
   {
       pValue=Py_BuildValue("(z)",(char*)"something");
       PyErr_Print();
       printf("Let's give this a shot!\n");
       presult=PyObject_CallObject(pFunc,pValue);
       PyErr_Print();
   } else 
   {
       PyErr_Print();
   }
   printf("Result is %ld\n",PyInt_AsLong(presult));
   Py_DECREF(pValue);

   // Clean up
   Py_DECREF(pModule);
   Py_DECREF(pName);

   // Finish the Python Interpreter
   Py_Finalize();


    return 0;
}
