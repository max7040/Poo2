#include <iostream>
using namespace std;

// Prototipo de la función recursiva
bool iguales(int x, int y);

int main() {
    // Ejemplos con la misma cantidad de dígitos
    cout << "345 y 345 son iguales? " << (iguales(345, 345) ? "TRUE" : "FALSE") << endl; // TRUE
    cout << "123 y 129 son iguales? " << (iguales(123, 129) ? "TRUE" : "FALSE") << endl; // FALSE
    cout << "0 y 0 son iguales? " << (iguales(0, 0) ? "TRUE" : "FALSE") << endl;         // TRUE

    return 0;
}

// Escribir el código de la función recursiva cuyo prototipo es: bool iguales(int x, int y);
// Asume que x e y tienen la misma cantidad de dígitos.
bool iguales(int x, int y) {
    // Caso base: Ambos números llegan a 0. Si llegaron aquí, todos los dígitos anteriores eran iguales.
    if (x == 0 && y == 0) {
        return true;
    }
    
    // Caso de fallo: Si los últimos dígitos son diferentes
    if (x % 10 != y % 10) {
        return false;
    }
    
    // Caso general: Llamada recursiva con los números sin el último dígito
    return iguales(x / 10, y / 10);
}