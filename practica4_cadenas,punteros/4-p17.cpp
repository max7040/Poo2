#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAX_LONG_CADENA = 256;

// Prototipe de la función principal
void suprimeImpares(char cad1[], char cad2[]);

int main()
{
    char cad1[MAX_LONG_CADENA] = "Un ejemplo de cadenas para prueba";
    char cad2[MAX_LONG_CADENA];
    
    cout << "cad1 = " << cad1 << endl;

    suprimeImpares(cad1, cad2);

    // Palabras con longitud impar: Un(2), ejemplo(7), de(2), cadenas(7), para(4), prueba(6)
    // Longitudes impares: ejemplo, cadenas
    cout << "cad2 = " << cad2 << endl; // Debería ser "ejemplo cadenas"

    return 0;
}

// Función que guarda en cad2 solo las palabras de cad1 con longitud impar
void suprimeImpares(char cad1[], char cad2[])
{
    int i = 0;
    
    // Inicializar cad2 vacía
    cad2[0] = '\0';
    
    // Recorrer cad1
    while (cad1[i] != '\0')
    {
        // 1. Saltar espacios
        while (cad1[i] == ' ')
        {
            i++;
        }
        
        // Marcar el inicio de la palabra
        int inicio_palabra = i;
        
        // 2. Avanzar al final de la palabra
        while (cad1[i] != ' ' && cad1[i] != '\0')
        {
            i++;
        }
        
        // Marcar el final de la palabra
        int fin_palabra = i;
        
        // 3. Calcular longitud
        int longitud_actual = fin_palabra - inicio_palabra;
        
        // 4. Comprobar si la longitud es impar
        if (longitud_actual > 0 && longitud_actual % 2 != 0)
        {
            char palabra_actual[MAX_LONG_CADENA];
            
            // Copiar la palabra actual a un buffer temporal
            strncpy(palabra_actual, &cad1[inicio_palabra], longitud_actual);
            palabra_actual[longitud_actual] = '\0'; // Asegurar el fin de cadena

            // Si cad2 no está vacía, añadir un espacio antes de concatenar
            if (cad2[0] != '\0')
            {
                strcat(cad2, " ");
            }
            // Concatenar la palabra a cad2
            strcat(cad2, palabra_actual);
        }
        
        // Si llegamos al final, terminamos
        if (cad1[i] == '\0')
        {
            break;
        }
    }
}