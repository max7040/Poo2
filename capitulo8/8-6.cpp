// Archivo main.cpp
#include <iostream>
#include "entero.h"

using namespace std;

int main()
{
    cout << "\nClase entero:" << endl;

    entero a(7);
    cout << "a = ";
    a.imprimir();

    entero b(10);
    cout << "b = ";
    b.imprimir();

    entero c;
    c = a;
    cout << "c = ";
    c.imprimir();

    entero e(-20);
    cout << "e = ";
    e.imprimir();

    e | e; // valor absoluto (Esto parece una llamada a operador binario | en el .cpp, pero en el main.cpp se usa como unario: |e)
           // La declaracion en .h es binaria: entero operator|(entero y);
           // La implementacion en .cpp es binaria: entero entero::operator|(entero y), y parece calcular |num|
           // Al usar 'e | e;' se llama a 'e.operator|(e)' y el codigo del operador modifica 'e' a su valor absoluto.
    cout << "\nValor absoluto e: ";
    e.imprimir();

    a + b;
    cout << "a + b = ";
    a.imprimir(); // a = 7 + 10 = 17

    a - c;
    cout << "a - c = ";
    a.imprimir(); // a = 17 - 7 = 10 (c tenia el valor original de a, que es 7)

    a * b;
    cout << "a * b = ";
    a.imprimir(); // a = 10 * 10 = 100

    a / b;
    cout << "a / b = ";
    a.imprimir(); // a = 100 / 10 = 10

    a % c;
    cout << "a % c = ";
    a.imprimir(); // a = 10 % 7 = 3

    entero f(30);
    cout << "\nDivisores de ";
    f.imprimir();
    !f; // Llama a void entero::operator!()

    return 0;
}