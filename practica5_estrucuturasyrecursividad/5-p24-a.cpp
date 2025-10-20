#include <iostream>
using namespace std;

void imprimirEnBaseB(int n, int b);

int main() {
    cout << "25 en base 8: "; 
    imprimirEnBaseB(25, 8); 
    cout << endl; // Salida: 31

    cout << "42 en base 2: "; 
    imprimirEnBaseB(42, 2); 
    cout << endl; // Salida: 101010
    
    return 0;
}

// Función que imprima recursivamente el número entero en la base b.
void imprimirEnBaseB(int n, int b) {
    // Caso base 1: Base invalida
    if (b < 2 || b > 10) {
        cout << "[Base invalida]";
        return;
    }
    
    // Caso base 2: Fin de la recursión (el cociente es 0)
    if (n == 0) {
        return;
    }

    // Llamada recursiva con el cociente (se llama antes de imprimir para obtener el orden correcto)
    imprimirEnBaseB(n / b, b);
    
    // Imprime el residuo (el dígito en la base b)
    cout << n % b;
}