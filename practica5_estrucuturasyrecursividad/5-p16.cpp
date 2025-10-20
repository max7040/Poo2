#include <iostream>
using namespace std;

void convertirBase(int n, int base);

int main() {
    int numero = 25;
    int base = 8;
    cout << "El numero " << numero << " en base " << base << " es: ";
    convertirBase(numero, base);
    cout << endl; // Salida: 31 (25 en base 8)

    numero = 42;
    base = 2;
    cout << "El numero " << numero << " en base " << base << " es: ";
    convertirBase(numero, base);
    cout << endl; // Salida: 101010 (42 en base 2)
    
    return 0;
}

// Escribir una función recursiva que convierta el número n a una base b menor que 10.
void convertirBase(int n, int base) {
    // Caso base: Cuando el cociente es menor que la base, el cociente es el último dígito
    if (n < base) {
        cout << n;
        return;
    }

    // Llamada recursiva con el cociente de la división
    convertirBase(n / base, base);
    
    // Imprime el residuo (el dígito actual en la base b)
    cout << n % base;
}