#include <iostream>
#include <cstdlib>
using namespace std;

void imprimirBinario(int n);

int main() {
    int numero = 25;
    cout << "Binario de " << numero << ": ";
    imprimirBinario(numero);
    cout << endl; // Salida: 11001

    numero = 10;
    cout << "Binario de " << numero << ": ";
    imprimirBinario(numero);
    cout << endl; // Salida: 1010
    
    return 0;
}

// Implementa una función recursiva que imprima la representación binaria de un número.
void imprimirBinario(int n) {
    if (n == 0) {
        return; // Caso base: Si es 0, termina
    } else {
        // Llamada recursiva con n/2
        imprimirBinario(n / 2);
        
        // Imprime el residuo (0 o 1) después de que todas las llamadas recursivas hayan terminado
        cout << n % 2;
    }
}