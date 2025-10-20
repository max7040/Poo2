#include <iostream>
#include <cmath>
using namespace std;

// Prototipo de la función principal
int contarParesEnPosicionImpar(int n);

// Función auxiliar recursiva
// n: el numero restante
// pos: la posicion actual, decreciendo desde la cantidad total de digitos
int contarPares(int n, int pos);

int main() {
    cout << "Resultado para 3231: " << contarParesEnPosicionImpar(3231) << endl;    // Esperado: 0
    cout << "Resultado para 2233: " << contarParesEnPosicionImpar(2233) << endl;    // Esperado: 1 (2 en pos 1)
    cout << "Resultado para 22768: " << contarParesEnPosicionImpar(22768) << endl;  // Esperado: 2 (2 en pos 1, 6 en pos 4)
    cout << "Resultado para 816352: " << contarParesEnPosicionImpar(816352) << endl; // Esperado: 3 (8 en pos 1, 6 en pos 3, 2 en pos 6)
    
    return 0;
}

// Función que determina la posición inicial y llama a la función recursiva.
int contarParesEnPosicionImpar(int n) {
    if (n < 0) n = -n;
    if (n == 0) return 0;
    
    // Calcula el número de dígitos para iniciar el conteo de posición.
    int numDigitos = floor(log10(n)) + 1;
    
    return contarPares(n, numDigitos);
}

// n: el número restante, pos: la posición del último dígito
int contarPares(int n, int pos) {
    // Caso base: Si no quedan dígitos
    if (n == 0) {
        return 0;
    }
    
    // 1. Llamada recursiva (procesa los dígitos restantes con la posición anterior)
    int cuentaRestante = contarPares(n / 10, pos - 1);
    
    // 2. Procesar el dígito actual (el dígito más a la izquierda de la LLAMADA ACTUAL,
    // que es el dígito de la posición 'pos' en el número original).
    
    int digitoActual = n % 10;
    int suma = 0;

    // Condición: Posición es impar Y Dígito es par
    // Posición es impar: pos % 2 != 0
    // Dígito es par: digitoActual % 2 == 0
    if ((pos % 2 != 0) && (digitoActual % 2 == 0)) {
        suma = 1;
    }

    return cuentaRestante + suma;
}