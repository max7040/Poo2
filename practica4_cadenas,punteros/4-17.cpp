#include <iostream>
// mostrar el uso de punteros
using namespace std;

int main() // Puntero_1.cpp
{
    int x; // variable entera
    int *ptrX; // puntero a entero
    x = 150; // asignacion
    ptrX = &x; // asignacion
    cout << "\nVariables y punteros" << endl;
    cout << "\nValor en x = \t" << x << endl;
    cout << "Valor apuntado por ptrX = " << *ptrX << endl;
    cout << "Direccion de x = \t" << &x << endl;
    cout << "Contenido de ptrX = \t" << ptrX << endl;
    cout << "Direccion de ptrX = \t" << &ptrX << endl << endl;
    return 0;
}