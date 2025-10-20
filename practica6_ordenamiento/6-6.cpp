#include <iostream>
using namespace std;

const int MAX = 20;

// Prototipos de funciones
void QuickSort(int left, int right, int a[]);
void leerArray(int a[], int n);
void escribeArray(int a[], int n);

int main() {
    int n, x[MAX];
    cout << "Cuantos enteros a ordenar en el array? ";
    cin >> n;

    leerArray(x, n);
    int left = 0;
    int right = n - 1;
    QuickSort(left, right, x); // Llamada a la funcion ordenar
    cout << "\nEl array ordenado es: " << endl;
    escribeArray(x, n);
    return 0;
}

// Implementación de QuickSort (Función recursiva)
void QuickSort(int left, int right, int a[]) {
    int aux;
    int i = left;  // extremo izquierdo
    int j = right; // extremo derecho
    // Cálculo del pivote como el elemento central
    int x = a[(left + right) / 2]; // pivote

    do {
        // Busca elemento mayor que el pivote
        while (a[i] < x) {
            i = i + 1;
        }

        // Busca elemento menor que el pivote
        while (x < a[j]) {
            j = j - 1;
        }

        // Si i <= j, intercambia y mueve los punteros
        if (i <= j) {
            // Intercambiar
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    // Llamadas recursivas para las sublistas
    if (left < j) {
        QuickSort(left, j, a);
    }
    if (i < right) {
        QuickSort(i, right, a);
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