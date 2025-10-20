#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// -----------------------------------------------------
// a) Búsqueda Secuencial (en array desordenado)
int search_secuencial(const vector<int>& a, int key) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == key) {
            return i; // Retorna el índice si lo encuentra
        }
    }
    return -1; // Retorna -1 si no lo encuentra
}

// -----------------------------------------------------
// b) Búsqueda Binaria (en array ordenado)
int search_binaria(const vector<int>& a, int key) {
    int izq = 0;
    int der = a.size() - 1;

    while (izq <= der) { 
        int mitad = izq + (der - izq) / 2; // Cálculo para evitar desbordamiento
        
        if (a[mitad] == key) {
            return mitad;
        } else if (a[mitad] < key) {
            izq = mitad + 1; // Busca en la mitad derecha
        } else {
            der = mitad - 1; // Busca en la mitad izquierda
        }
    }
    return -1; // No encontrado
}

// Función principal
int main() {
    // Array original del problema 1 (desordenado)
    vector<int> a_desordenado = {9, 7, 1, 3, 5, 4, 8, 2};
    // Array ordenado (necesario para la búsqueda binaria)
    vector<int> a_ordenado = {1, 2, 3, 4, 5, 7, 8, 9}; 
    int key = 5;

    cout << "\n--- 2. ALGORITMOS DE BUSQUEDA (Clave: " << key << ") ---" << endl;

    // 2a) Búsqueda Secuencial
    int k_sec = search_secuencial(a_desordenado, key);
    cout << "Array Secuencial: [9, 7, 1, 3, 5, 4, 8, 2]" << endl;
    if (k_sec != -1) {
        cout << "Busqueda Secuencial: Elemento " << key << " encontrado en el INDICE: " << k_sec << endl; // Output: 4
    } else {
        cout << "Busqueda Secuencial: Elemento no encontrado." << endl;
    }

    // 2b) Búsqueda Binaria
    int k_bin = search_binaria(a_ordenado, key);
    cout << "Array Binaria:   [1, 2, 3, 4, 5, 7, 8, 9] (Ordenado)" << endl;
    if (k_bin != -1) {
        cout << "Busqueda Binaria: Elemento " << key << " encontrado en el INDICE: " << k_bin << endl; // Output: 4
    } else {
        cout << "Busqueda Binaria: Elemento no encontrado." << endl;
    }

    return 0;
}