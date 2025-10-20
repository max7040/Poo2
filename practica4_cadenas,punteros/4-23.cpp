#include <iostream>
using namespace std;

// muestra el uso del operador new para asignar memoria dinamica
int main() // Asignacion_Dinamica_1.cpp
{
    int i, *pi;
    pi = new int; // pi es ahora variable dinamica
    cout << "\nIngrese un entero: ";
    cin >> *pi;
    cout << "\nValor ingresado: " << *pi << endl;
    i = *pi;
    cout << "Valor en i: " << i << endl;
    *pi = *pi + 10; // el valor entero ingresado es ahora aumentado en 10
    cout << "Valor incrementado en 10: " << *pi << endl;
    i = *pi;
    cout << "Valor actual en i: " << i << endl;
    cout << "Nuevo valor en i: " << i << endl;
    return 0;
}