#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void encriptar(char cadena[]);

int main()
{
    char cadena[256];

    cout << "Ingrese la cadena de caracteres a encriptar: ";
    gets(cadena); 

    encriptar(cadena);

    cout << "\nCadena encriptada: " << cadena << endl;

    return 0;
}

void encriptar(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        char c = cadena[i];
        
        switch (c)
        {
            // Vocales minúsculas
            case 'a':
                cadena[i] = '0';
                break;
            case 'e':
                cadena[i] = '1';
                break;
            case 'i':
                cadena[i] = '2';
                break;
            case 'o':
                cadena[i] = '3';
                break;
            case 'u':
                cadena[i] = '4';
                break;
            
            // Vocales mayúsculas
            case 'A':
                cadena[i] = '0';
                break;
            case 'E':
                cadena[i] = '1';
                break;
            case 'I':
                cadena[i] = '2';
                break;
            case 'O':
                cadena[i] = '3';
                break;
            case 'U':
                cadena[i] = '4';
                break;

            // El dígito '6' se reemplaza por '5'
            case '6':
                cadena[i] = '5';
                break;
            
            // Los demás caracteres quedan igual
        }
    }
}