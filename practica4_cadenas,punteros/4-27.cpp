#include <iostream>
#include <cstdlib>
using namespace std;
// muestro el uso de un array dinamico
typedef int *pArrayEnt; // puntero a un array de enteros
void leerArray(int a[], int n);
void escribirArray(int a[], int n);
void ordenaArray(int a[], int n);

int main() // punter7.cpp
{
    pArrayEnt a;
    int n;

    cout << "Ingrese numero de elementos en el Array ";
    cin >> n;

    a = new int[n]; // array dinamico
    if (a == NULL)
    {
        cout << "Error: Memoria insuficiente!.\n" << endl;
        exit(1);
    }
    
    leerArray(a, n);
    ordenaArray(a, n);
    escribirArray(a, n);
    delete[](a); // liberar memoria dinamica
    return 0;
}

void leerArray(int a[], int n)
{
    cout << "Ingrese " << n << " enteros en el array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void escribirArray(int a[], int n)
{
    cout << "\nEL array ordenado de menor a mayor es: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Metodo de Seleccion Directa
void ordenaArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        int selec = a[i]; // seleccion inicial
        for (int j = i + 1; j < n; j++) // busqueda en secuencia
        {
            if (a[j] < selec)
            {
                k = j;
                selec = a[k]; // seleccion
            }
        }
        
        a[k] = a[i]; // intercambio
        a[i] = selec;
    }
}