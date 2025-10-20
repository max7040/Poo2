#include <iostream>
#include <string.h> // para comparar dos cadenas, la función devuelve un valor
using namespace std;
/* negativo si la primera cadena es menor que la segunda, positivo si es mayor y
cero en caso que sean iguales. */
int main() // Cadena_8.cpp
{
    char cad1[] = "LENGUAJE C++";
    char cad2[] = "LENGUAJE C++";
    char cad3[] = "Lenguaje C++";
    char cad4[] = "lenguaje c++";
    cout << "\nFuncion strcmp():" << endl << endl;
    cout << "Cadena 1 : " << cad1 << endl;
    cout << "Cadena 2 : " << cad2 << endl;
    cout << "Cadena 3 : " << cad3 << endl;
    cout << "Cadena 4 : " << cad4 << endl;

    // comparar cadena 1 con cadena 2
    int result = strcmp(cad1, cad2);
    if (result < 0)
        cout << "\n" << cad1 << " es menor que: " << cad2 << " -> resultado = " << result << endl;
    if (result == 0)
        cout << "\n" << cad1 << " es igual que: " << cad2 << " -> resultado = " << result << endl;
    if (result > 0)
        cout << "\n" << cad1 << " es mayor que: " << cad2 << " -> resultado = " << result << endl;
    
    // comparar cadena 1 con cadena 3
    result = strcmp(cad1, cad3);
    if (result < 0)
        cout << "\n" << cad1 << " es menor que: " << cad3 << " -> resultado = " << result << endl;
    if (result == 0)
        cout << "\n" << cad1 << " es igual que: " << cad3 << " -> resultado = " << result << endl;
    if (result > 0)
        cout << "\n" << cad1 << " es mayor que: " << cad3 << " -> resultado = " << result << endl;
    
    // comparar cadena 1 con cadena 4
    result = strcmp(cad1, cad4);
    if (result < 0)
        cout << "\n" << cad1 << " es menor que: " << cad4 << " -> resultado = " << result << endl;
    if (result == 0)
        cout << "\n" << cad1 << " es igual que: " << cad4 << " -> resultado = " << result << endl;
    if (result > 0)
        cout << "\n" << cad1 << " es mayor que: " << cad4 << " -> resultado = " << result << endl;
    
    return 0;
}