#include <iostream>
#include <cmath>
using namespace std;

int contarDigitos(int n);

int main() {
    cout << "Digitos de 4567: " << contarDigitos(4567) << endl;  // Salida: 4
    cout << "Digitos de -123: " << contarDigitos(-123) << endl;  // Salida: 3
    cout << "Digitos de 0: " << contarDigitos(0) << endl;        // Salida: 1
    
    return 0;
}

// Escribe una función recursiva que devuelva la cantidad de dígitos que tiene un 
// número entero (positivo o negativo) el cual es recibido como argumento.
int contarDigitos(int n) {
    // Si el numero es negativo, lo convertimos a positivo para el conteo
    if (n < 0) {
        n = -n;
    }
    
    // Caso base: Si el numero es un solo digito (0 a 9)
    if (n < 10) {
        return 1;
    }

    // Caso general: Devuelve 1 (el digito actual) + la llamada recursiva con n/10
    return 1 + contarDigitos(n / 10);
}