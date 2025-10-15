#include <iostream>
#include "Racional.h" // Incluye la definicion de la clase Racional

using namespace std;

int main()
{
    Racional r1(2, 3), r2(1, 2), r3(2, 3), r4;

    cout << "\nNumeros racionales" << endl;
    cout << "r1 = " << r1 << endl; // r1 = 2/3
    cout << "r2 = " << r2 << endl; // r2 = 1/2
    cout << "r3 = " << r3 << endl; // r3 = 2/3
    cout << "r4 = " << r4 << endl; // r4 = 0/1 (Constructor por defecto)

    // Suma: r4 = r1 + r2
    // r1 + r2 = 2/3 + 1/2 = 4/6 + 3/6 = 7/6
    r4 = r1 + r2;
    cout << "\nSuma de r1 y r2 = r4 -> " << r4 << endl; // r4 = 7/6

    // Comparacion: r1 == r3
    if (r1 == r3)
        cout << "\nr1 es igual a r3" << endl;
    else
        cout << "\nr1 no es igual a r3" << endl;

    // Asignacion con suma compuesta: r4 = r4 + r1
    // r4 += r1 = 7/6 + 2/3 = 7/6 + 4/6 = 11/6
    r4 += r1;
    cout << "\nr4 = r4 + r1 -> " << r4 << endl; // r4 = 11/6

    // Asignacion con producto compuesto: r4 = r4 * r2
    // r4 *= r2 = 11/6 * 1/2 = 11/12
    r4 *= r2;
    cout << "\nr4 = r4 * r2 -> " << r4 << endl; // r4 = 11/12

    // Pre-incremento: ++r3
    // ++r3 = 2/3 + 1 = 2/3 + 3/3 = 5/3
    ++r3;
    cout << "\n++r3 = " << r3 << endl; // r3 = 5/3

    // Asignacion simple: r1 = r4
    r1 = r4;
    cout << "\nAsignando r4 a r1 -> " << r1 << endl; // r1 = 11/12

    cout << "\nPresione una tecla para finalizar...!";

    return 0;
}