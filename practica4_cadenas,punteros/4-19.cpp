#include <iostream>
#include <conio.h> // para getche()
// punteros y sentencias de asignacion
using namespace std;

int main() // Puntero_3.cpp
{
    int i, j; // variables enteras
    int *pi, *pj; // variables puntero a entero

    // parte 1
    i = 220;
    j = 41;
    pi = &i; // asignar la direccion de i a pi
    pj = &j; // asignas pi a j
    
    cout << "\nParte 1" << endl;
    cout << "Valor en i: " << i << "\tDireccion de i: " << pi << endl;
    cout << "Valor apuntado por pi: " << *pi << "\tDireccion en pj: " << pj << endl;
    cout << "Valor apuntado por pj: " << *pj << "\tDireccion en pj: " << pj << endl;

    // parte 2
    j = 500;
    pj = &i;

    cout << "\nParte 2" << endl;
    cout << "Valor en j: " << j << "\tDireccion de j: " << &j << endl;
    cout << "Valor apuntado por pj: " << *pj << "\tDireccion en pj: " << pj << endl;
    pi = pj;
    cout << "Valor apuntado por pi: " << *pi << "\tValor apuntado por pj: " << *pj << endl;
    cout << endl;

    // parte 3
    *pj = *pi;
    cout << "\nParte 3" << endl;
    cout << "Direccion almacenada en pi: " << pi << "\tDireccion almacenada en pj: " << pj << endl;
    cout << "Valor apuntado por pi: " << *pi << "\tValor apuntado por pj: " << *pj << endl;
    cout << endl;

    cout << "Valor en i: " << i << "\tValor en j: " << j << endl;
    cout << "Direccion de pi: " << &pi << "\tDireccion de pj: " << &pj << endl;

    getche();
    return 0;
}