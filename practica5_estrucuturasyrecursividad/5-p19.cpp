#include <iostream>
#include <cmath>
using namespace std;

// Prototipo de la función recursiva
long long convertirBaseB(int n, int b, int potencia);

int main() {
    int numero_baseB = 421; // Ejemplo: 421 en base 5
    int base = 5;
    
    // Ejemplo: (421) base 5 = 4*5^2 + 2*5^1 + 1*5^0 = 100 + 10 + 1 = (111) base 10
    
    cout << "Convirtiendo (" << numero_baseB << ") en base " << base << " a base 10." << endl;
    long long resultado = convertirBaseB(numero_baseB, base, 0);
    
    cout << "El equivalente es: " << resultado << " en base 10." << endl;
    
    return 0;
}

// Escribir una función recursiva que convierta un entero n escrito en una base b, 
// con b < 10, a su equivalente en base 10.
long long convertirBaseB(int n, int b, int potencia) {
    // Caso base: Si el número es 0, la conversión terminó.
    if (n == 0) {
        return 0;
    }

    // 1. Obtener el último dígito
    int digito = n % 10;
    
    // 2. Sumar la contribución actual y realizar la llamada recursiva
    // La recursión avanza al siguiente dígito y aumenta la potencia de la base.
    return (long long)(digito * pow(b, potencia)) + 
           convertirBaseB(n / 10, b, potencia + 1);
}