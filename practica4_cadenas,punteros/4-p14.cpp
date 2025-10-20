#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int contarPalabrasLongitudN(char cadena[], int n);

int main()
{
    char cadena[256];
    int longitud;
    int cantidad;

    cout << "Ingrese una cadena de caracteres: ";
    gets(cadena); 

    cout << "Ingrese la longitud N de las palabras a contar: ";
    cin >> longitud;

    cantidad = contarPalabrasLongitudN(cadena, longitud);

    cout << "\nSe encontraron " << cantidad << " palabras con longitud " << longitud << " en la cadena." << endl;

    return 0;
}

// Función que cuenta palabras de longitud N
int contarPalabrasLongitudN(char cadena[], int n)
{
    int i = 0;
    int contador = 0;
    
    while (cadena[i] != '\0')
    {
        // 1. Saltar espacios
        while (cadena[i] == ' ')
        {
            i++;
        }
        
        // Marcar el inicio de la palabra
        int inicio_palabra = i;
        
        // 2. Avanzar al final de la palabra
        while (cadena[i] != ' ' && cadena[i] != '\0')
        {
            i++;
        }
        
        // Marcar el final de la palabra (o el espacio/fin de cadena)
        int fin_palabra = i;
        
        // 3. Calcular longitud de la palabra
        int longitud_actual = fin_palabra - inicio_palabra;
        
        // 4. Comprobar si la longitud coincide
        if (longitud_actual == n)
        {
            contador++;
        }
        
        // Si llegamos al final de la cadena, terminamos
        if (cadena[i] == '\0')
        {
            break;
        }
    }

    return contador;
}