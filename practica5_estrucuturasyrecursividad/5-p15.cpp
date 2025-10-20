#include <iostream>
using namespace std;

void imprimirImpares(int n);

int main() {
    int numero = 15;
    cout << "Impares hasta " << numero << ": ";
    imprimirImpares(numero);
    cout << endl; // Salida: 1 3 5 7 9 11 13 15
    
    return 0;
}

// Escribe una función recursiva que recibe un número entero positivo e imprime
// los números impares existentes hasta dicho número.
void imprimirImpares(int n) {
    // Caso base: Si n es menor que 1, termina
    if (n < 1) {
        return;
    }

    // Llamada recursiva para procesar los números anteriores
    // Esto asegura que la impresión se haga en orden ascendente
    if (n > 1) {
        imprimirImpares(n - 1);
    }
    
    // Procesa e imprime el número actual si es impar
    if (n % 2 != 0) {
        cout << n << " ";
    }
}