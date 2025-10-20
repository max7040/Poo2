#include <iostream>
#include <cmath>
using namespace std;

// Prototipo de la función recursiva
// n_base_b: El número en base b (ej. 328, tratado como entero decimal)
// b: La base (ej. 9)
// pos: La posición del dígito actual, comenzando en 0 (unidades)
long long calcularEquivalenteBaseBDiez(int n_base_b, int b, int pos);

int main() {
    int numero = 328; // El número en base 9
    int base = 9;
    
    // Ejemplo: (328) base 9 = 3*9^2 + 2*9^1 + 8*9^0 = 243 + 18 + 8 = (269) base 10
    // La imagen del ejercicio tiene un error en el ejemplo: (328) base 9 es (269) base 10, no (93) base 10.
    
    cout << "Calculando el equivalente de (" << numero << ") en base " << base << " a base 10." << endl;
    long long resultado = calcularEquivalenteBaseBDiez(numero, base, 0);
    
    cout << "El equivalente es: " << resultado << " en base 10." << endl;
    
    return 0;
}

// Implementación de la función recursiva
long long calcularEquivalenteBaseBDiez(int n_base_b, int b, int pos) {
    // Caso base: Cuando el número en la base b es 0, la conversión termina.
    if (n_base_b == 0) {
        return 0;
    }

    // 1. Obtener el último dígito (el dígito actual)
    int digito = n_base_b % 10;
    
    // 2. Calcular la contribución del dígito actual: digito * (b ^ pos)
    long long valorActual = digito * (long long)pow(b, pos);
    
    // 3. Llamada recursiva con el número sin el último dígito (n/10) y la siguiente posición (pos + 1)
    return valorActual + calcularEquivalenteBaseBDiez(n_base_b / 10, b, pos + 1);
}