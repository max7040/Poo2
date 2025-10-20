#include <iostream>
#include <stdio.h> // Para gets()

using namespace std;

// Prototipe de la función
int contarPalabras(const char cadena[]);

int main()
{
    char cadena[256];
    int numPalabras;

    cout << "Ingrese una cadena de caracteres: ";
    gets(cadena); 

    numPalabras = contarPalabras(cadena);

    cout << "\nLa cadena ingresada tiene " << numPalabras << " palabras." << endl;

    return 0;
}

// Función que cuenta el número de palabras
int contarPalabras(const char cadena[])
{
    int i = 0;
    int contador = 0;
    bool enPalabra = false;

    while (cadena[i] != '\0')
    {
        // Si el caracter actual NO es un espacio
        if (cadena[i] != ' ')
        {
            // Si estábamos fuera de una palabra, significa que encontramos el inicio de una nueva
            if (enPalabra == false)
            {
                contador++;    // Incrementar el contador de palabras
                enPalabra = true; // Estamos ahora dentro de una palabra
            }
        }
        else
        {
            // Si es un espacio, estamos fuera de la palabra
            enPalabra = false;
        }
        i++;
    }

    return contador;
}