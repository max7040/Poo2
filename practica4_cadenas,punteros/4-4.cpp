#include <iostream>
#include <stdio.h> // Para gets() y puts()

using namespace std;
/* Uso de las funciones gets() y puts(), observe que la función
gets() lee una cadena y no se trunca cuando lee un espacio en
blanco, a diferencia de cin */
int main() // Cadena_3.cpp
{
    char cad[40];
    cout << "\nIngrese sus nombres y apellidos: ";
    gets(cad); // Lee la cadena
    cout << "\nHola, ";
    puts(cad); // Imprime la cadena
    cout << endl;
    return 0;
}