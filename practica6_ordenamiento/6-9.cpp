#include <iostream>
using namespace std;

// Prototipo de función
int search_bin(int a[], int n, int key);

int main() {
    // El arreglo DEBE estar ordenado para Búsqueda Binaria
    int a[] = {10, 20, 30, 40, 50, 60}; 
    int key = 50;
    // Cálculo del tamaño del arreglo
    int n = sizeof(a) / sizeof(a[0]); 
    
    cout << "Busqueda Binaria Iterativa" << endl;
    cout << "\nClave a buscar = " << key << endl;

    int k = search_bin(a, n, key);
    
    if (k == -1) {
        cout << "\nNo existe el elemento" << endl;
    } else {
        cout << "\nEl elemento tiene el índice: " << k << endl;
    }
    return 0;
}

// Implementación de search_bin (Versión Iterativa)
int search_bin(int a[], int n, int key) {
    int izq = 0;
    int der = n - 1;
    int mitad;

    // Repetir mientras el límite izquierdo no exceda al derecho
    while (izq <= der) { 
        mitad = (izq + der) / 2; // División entera

        if (a[mitad] == key) {
            return mitad; // Encontrado
        } else if (a[mitad] < key) {
            izq = mitad + 1; // La clave está en la mitad derecha
        } else { // a[mitad] > key
            der = mitad - 1; // La clave está en la mitad izquierda
        }
    }
    
    return -1; // No encontrado
}