#include <iostream>
using namespace std;

// Prototipo de función
int search_lin(int a[], int n, int key);

int main() {
    int a[] = {10, 40, 50, 30, 70, 60};
    int key = 50;
    // Cálculo del tamaño del arreglo
    int n = sizeof(a) / sizeof(a[0]); 
    
    cout << "Busqueda Secuencial" << endl;
    cout << "\nClave a buscar = " << key << endl;

    int k = search_lin(a, n, key);
    
    if (k == -1) {
        cout << "\nNo existe el elemento " << key << endl;
    } else {
        cout << "\nEl elemento " << key << " tiene el índice: " << k << endl;
    }
    return 0;
}

// Implementación de search_lin
int search_lin(int a[], int n, int key) {
    int i = 0;
    // Bucle para recorrer el arreglo hasta encontrar la clave o llegar al final
    while (i < n && a[i] != key) {
        i++;
    }
    // Si i == n, la clave no fue encontrada. Si no, retorna el índice i.
    return (i == n) ? (-1) : (i); 
}