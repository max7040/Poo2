#include <iostream>
#include <stdio.h> // Para gets() y puts()
#include <string.h> // Para strupr() y strlwr()
using namespace std;
/* La función strupr() convierte los caracteres de una cadena en mayúsculas.
La función strlwr() convierte los caracteres de una cadena en minúsculas */
int main() // Cadena_10.cpp
{
    char cadel[40], cadel2[40];
    cout << "\nIngrese Cadena en minusculas: ";
    gets(cadel);
    strupr(cadel);
    cout << "\nA mayusculas: ";
    puts(cadel);
    cout << endl;
    
    cout << "\nIngrese Cadena en Mayusculas: ";
    gets(cadel2);
    strlwr(cadel2);
    cout << "\nA minusculas: ";
    puts(cadel2);
    cout << endl;
    return 0;
}