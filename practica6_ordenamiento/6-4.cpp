#include <iostream>
using namespace std;

const int MAX = 20;

// Prototipos de funciones
void Seleccion_Directa(int a[], int n);
void leerArray(int a[], int n);
void escribeArray(int a[], int n);

int main() {
    // Ordena_Seleccion_Directa.cpp
    int n, x[MAX];
    cout << "Cuantos enteros a ordenar en el array? ";
    cin >> n;

    leerArray(x, n);
    Seleccion_Directa(x, n); // Llamada a la funcion ordenar
    cout << "\nEl array ordenado es: " << endl;
    escribeArray(x, n);
    return 0;
}

// Implementación de Seleccion_Directa
void Seleccion_Directa(int a[], int n) {
    int i, j, k; // i: posición actual, j: iterador de búsqueda, k: índice del menor
    int menor; // Almacena el valor del menor elemento encontrado

    for (i = 0; i < n; i++) {
        menor = a[i]; // Selección inicial del primer elemento del sub-array no ordenado
        k = i;        // Índice inicial
        
        // Búsqueda del menor elemento en el resto del array (de i+1 a n-1)
        for (j = i + 1; j < n; j++) { 
            if (a[j] < menor) {
                menor = a[j]; // Nuevo menor valor
                k = j;        // Nuevo índice del menor
            }
        }
        
        // Intercambio: mover el menor elemento encontrado (en k) a la posición actual (i)
        a[k] = a[i];  // El valor de la posición i se mueve a donde estaba el menor (k)
        a[i] = menor; // El menor valor se coloca en la posición i
    }
}

// Implementación de leerArray
void leerArray(int a[], int n) {
    cout << "Ingrese " << n << " datos en el Array:" << endl;
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