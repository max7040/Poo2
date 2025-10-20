#include <iostream>
#include <stdio.h>
#include <ctype.h> // Para tolower()

using namespace std;

int main()
{
    char cadena[256];
    char caracter;
    int contador = 0;
    int i = 0;
    
    cout << "Ingrese una cadena de caracteres: ";
    gets(cadena); 

    cout << "Ingrese el caracter con el que deben empezar las palabras: ";
    cin >> caracter;

    // Convertir el caracter de busqueda a minúscula
    char car_lower = tolower(caracter);

    while (cadena[i] != '\0')
    {
        // 1. Saltar todos los espacios iniciales
        while (cadena[i] == ' ')
        {
            i++;
        }
        
        // 2. Comprobar si la palabra comienza con el caracter buscado
        if (cadena[i] != '\0') // Asegura que no es el final de la cadena
        {
            if (tolower(cadena[i]) == car_lower)
            {
                contador++;
            }
        }

        // 3. Avanzar al final de la palabra
        while (cadena[i] != ' ' && cadena[i] != '\0')
        {
            i++;
        }
    }

    cout << "\nHay " << contador << " palabras que empiezan con el caracter '" << caracter << "'." << endl;

    return 0;
}