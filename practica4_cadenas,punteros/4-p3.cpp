#include <iostream>
#include <stdio.h> // Para gets() o puts()

using namespace std;

int main()
{
    char cadena[256];

    cout << "Ingrese una cadena de caracteres: ";
    // Usamos gets() para leer la cadena completa, ya que es la forma usada en los ejemplos.
    gets(cadena); 
    
    cout << "\nCadena ingresada: ";
    puts(cadena); // Imprime la cadena original

    // Recorrer la cadena y reemplazar
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == ' ')
        {
            cadena[i] = '*';
        }
    }

    cout << "Cadena transformada: ";
    puts(cadena); // Imprime la cadena modificada

    return 0;
}