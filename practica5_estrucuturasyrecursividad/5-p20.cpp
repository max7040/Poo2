#include <iostream>
#include <cmath>
using namespace std;

// Prototipo de la función que devuelve el número invertido.
int invertirNumero(int n);

// Variable global (o auxiliar) para construir el número invertido.
// La recursividad pura requiere pasar este valor, pero una variable global 
// simplifica la implementación como se hace a menudo en ejemplos recursivos.
int numeroInverso = 0;

int main() {
    int numero = 12345;
    cout << "El inverso de " << numero << " es: " << invertirNumero(numero) << endl; // Salida: 54321
    
    numeroInverso = 0; // Resetear la variable para una nueva llamada
    int otroNumero = 901;
    cout << "El inverso de " << otroNumero << " es: " << invertirNumero(otroNumero) << endl; // Salida: 109

    return 0;
}

// Escribe una función recursiva que reciba un entero n y lo devuelva en sentido inverso.
int invertirNumero(int n) {
    // Caso base: Si el numero es 0, la recursión termina
    if (n == 0) {
        return 0;
    }
    
    // 1. Obtener el último dígito
    int digito = n % 10;
    
    // 2. Agregar el dígito al número invertido (se multiplica por 10 y se suma)
    numeroInverso = numeroInverso * 10 + digito;
    
    // 3. Llamada recursiva con el resto del número (n/10)
    invertirNumero(n / 10);

    return numeroInverso;
}