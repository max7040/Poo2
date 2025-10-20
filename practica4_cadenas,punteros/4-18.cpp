#include <iostream>
#include <conio.h> // para getche()
// muestra el uso de variables y punteros
using namespace std;

int main() // Puntero_2.cpp
{
    int i; // variable entera
    int *pi; // pi variable puntero a entero

    i = 505; // asignacion
    pi = &i;
    cout << "\nValor almacenado en i:\t" << i << endl; // valor almacenado en i
    cout << "Direccion de i:\t\t" << &i << endl; // direccion de i
    cout << "Direccion almacenada en pi:\t" << pi << endl; // pi guarda la direccion de i
    cout << "Valor al que apunta pi:\t" << *pi << endl; // valor al que apunta pi
    cout << "Direccion de pi:\t" << &pi << endl; // direccion de pi

    *pi = 2490; // cambiando el valor apuntado por pi
    cout << "\nNuevo valor apuntado por pi:\t" << *pi << endl; /* nuevo valor apuntado por pi */
    cout << "Nuevo valor en i:\t\t" << i << endl; // nuevo valor en i
    cout << "Direccion de i:\t\t" << &i << endl;
    getche();
    return 0;
}