#include <iostream>
using namespace std;

// Prototipo de función recursiva
int search_bin_recursiva(int a[], int key, int izq, int der);

int main() {
    // El arreglo DEBE estar ordenado para Búsqueda Binaria
    int a[] = {10, 20, 30, 40, 50, 60}; 
    int key = 40;
    int izq = 0;
    int n = sizeof(a) / sizeof(a[0]); // Tamaño del arreglo
    int der = n - 1;
    
    cout << "Busqueda Binaria Recursiva" << endl;
    cout << "\nClave a buscar = " << key << endl;

    int k = search_bin_recursiva(a, key, izq, der);
    
    if (k == -1) {
        cout << "\nNo existe el elemento" << endl;
    } else {
        cout << "\nEl elemento " << key << " tiene el indice: " << k << endl;
    }
    return 0;
}

// Implementación de search_bin_recursiva (Versión Recursiva)
int search_bin_recursiva(int a[], int key, int izq, int der) {
    // Caso base: si los límites se cruzan, no se encontró
    if (izq > der) { 
        return (-1);
    }
    
    int mitad = (izq + der) / 2; // División entera
    
    // Operador condicional ternario para manejar los tres casos
    return (key == a[mitad]) ? 
            mitad : // Caso 1: Encontrado. Retorna la posición.
           (key < a[mitad]) ? 
            search_bin_recursiva(a, key, izq, mitad - 1) : // Caso 2: Buscar en mitad izquierda
            search_bin_recursiva(a, key, mitad + 1, der); // Caso 3: Buscar en mitad derecha
}