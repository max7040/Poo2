#include <iostream>
using namespace std;

const int MAX = 20;

// Prototipos de funciones
void insercionDirecta(int a[], int n);
void leerArray(int a[], int n);
void escribeArray(int a[], int n);

int main() {
    // Ordena_Incorcion_Directa.cpp
    int n, x[MAX];
    cout << "Cuantos enteros a ordenar en el array? ";
    cin >> n;

    leerArray(x, n);
    insercionDirecta(x, n); // Llamada a la funcion ordenar
    cout << "\nEl array ordenado es: " << endl;
    escribeArray(x, n);
    return 0;
}

// Implementación de insercionDirecta
void insercionDirecta(int a[], int n) {
    int i, j;
    int temp;

    // Recorre el array desde el segundo elemento (índice 1)
    for (i = 1; i < n; i++) {
        temp = a[i]; // Valor a insertar en la parte ordenada
        j = i - 1;   // Última posición de la parte ya ordenada

        // Desplaza los elementos de la parte ordenada (j) que sean mayores que temp
        while (j >= 0 && temp < a[j]) {
            a[j + 1] = a[j]; // Desplaza el elemento a la derecha
            j--;
        }
        
        // Inserta temp en su posición correcta
        a[j + 1] = temp; 
    }
}

// Implementación de leerArray
void leerArray(int a[], int n) {
    cout << "\nIngrese " << n << " datos en el Array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

// Implementación de escribeArray
void escribeArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}