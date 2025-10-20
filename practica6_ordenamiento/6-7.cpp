#include <iostream>
using namespace std;

const int MAX = 20;

// Prototipos de funciones
void ShellSort(int a[], int n);
void leerArray(int a[], int n);
void escribeArray(int a[], int n);

int main() {
    int n, x[MAX];
    cout << "Cuantos enteros a ordenar en el array? ";
    cin >> n;

    leerArray(x, n);
    ShellSort(x, n); // Llamada a la funcion ordenar
    cout << "\nEl array ordenado es: " << endl;
    escribeArray(x, n);
    return 0;
}

// Implementación de ShellSort
void ShellSort(int a[], int n) {
    int i, salto, aux;
    int j; // Se necesita 'j' para el bucle interior de tipo inserción
    bool Flag;

    salto = n + 1;
    while (salto > 0) {
        salto = salto / 2; // División entera. Generación del salto.
        
        // Si el salto es 0, salta el bucle for de ordenación para terminar
        if (salto == 0) break; 
        
        Flag = true;
        while (Flag == true) {
            Flag = false; // Se reinicia la bandera
            j = 0;
            
            // Recorrido de los elementos del arreglo con el salto actual
            while ((j + salto) < n) {
                // Compara a[j] y a[j + salto]
                if (a[j] > a[j + salto]) {
                    // Intercambiar
                    aux = a[j];
                    a[j] = a[j + salto];
                    a[j + salto] = aux;
                    Flag = true; // Hubo intercambio, debe seguir pasando
                }
                j = j + 1;
            }
        }
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