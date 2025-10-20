#include <iostream>
using namespace std;

const int MAX = 50;

// Prototipos de funciones
void burbuja1(int x[MAX], int n);
void leerArray(int x[MAX], int n);
void escribeArray(int x[MAX], int n);

int main() {
    int n, a[MAX];
    cout << "Cuantos enteros a ordenar en el array? ";
    cin >> n;

    leerArray(a, n);
    burbuja1(a, n); // Llamada a la funcion que ordena
    cout << "\nEl array ordenado es: " << endl;
    escribeArray(a, n);
    return 0;
}

// Implementación de burbuja1
void burbuja1(int x[MAX], int n) {
    int aux;
    for (int i = n - 1; i > 0; i--) { // Bucle exterior
        for (int j = 0; j < i; j++) { // Bucle interior
            if (x[j] > x[j + 1]) {
                // Intercambio
                aux = x[j];
                x[j] = x[j + 1];
                x[j + 1] = aux;
            }
        }
    }
}

// Implementación de leerArray
void leerArray(int x[MAX], int n) {
    cout << "Ingrese " << n << " datos en el Array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }
}

// Implementación de escribeArray
void escribeArray(int x[MAX], int n) {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}