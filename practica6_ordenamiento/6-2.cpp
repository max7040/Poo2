#include <iostream>
using namespace std;

const int MAX = 20;

// Prototipos de funciones
void burbuja2(int x[], int n);
void leerArray(int x[], int n);
void escribeArray(int x[], int n);

int main() {
    int n, a[MAX];
    cout << "Cuantos enteros a ordenar en el array? ";
    cin >> n;

    leerArray(a, n);
    burbuja2(a, n); // Llamada a la funcion ordenar
    cout << "\nEl array ordenado es: " << endl;
    escribeArray(a, n);
    return 0;
}

// Implementación de burbuja2
void burbuja2(int x[], int n) {
    int aux;
    for (int i = 0; i < n; i++) {
        // La optimización es el límite: j < n - i - 1
        for (int j = 0; j < n - i - 1; j++) { 
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
void leerArray(int x[], int n) {
    cout << "\nIngrese " << n << " datos en el Array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }
}

// Implementación de escribeArray
void escribeArray(int x[], int n) {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}