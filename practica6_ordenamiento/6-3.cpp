#include <iostream>
using namespace std;

const int MAX = 20; // Usado en este ejemplo, aunque main no lo necesita explícitamente

// Prototipos de funciones
void burbuja3(int x[], int n);
void leerArray(int x[], int n);
void escribeArray(int x[], int n);

int main() {
    int n, a[MAX];
    cout << "Cuantos enteros a ordenar en el array? ";
    cin >> n;

    leerArray(a, n);
    burbuja3(a, n); // Llamada a la funcion ordenar
    cout << "\nEl array ordenado es: " << endl;
    escribeArray(a, n);
    return 0;
}

// Implementación de burbuja3
void burbuja3(int x[], int n) {
    int aux;
    bool Flag = false; // Bandera logica
    
    while (Flag == false) {
        Flag = true; // Se asume que está ordenado al inicio del ciclo
        for (int k = 0; k < n - 1; k++) {
            if (x[k] > x[k + 1]) {
                // Intercambio
                aux = x[k];
                x[k] = x[k + 1];
                x[k + 1] = aux;
                Flag = false; // Se realizó un intercambio, debe seguir iterando
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