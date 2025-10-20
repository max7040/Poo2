#include <iostream>

using namespace std;

// Prototipe de la función
char *palabraMasLarga(char *oracion);

int main()
{
    char oracion[] = "La programacion con punteros a veces resulta confusa";
    char *palabra_larga;

    cout << "Oracion: " << oracion << endl;

    palabra_larga = palabraMasLarga(oracion);

    cout << "Palabra mas larga: " << palabra_larga << endl; 

    return 0;
}

/*
 * Función que recibe un puntero a la oración y devuelve un puntero a la palabra
 * de mayor longitud, sin usar funciones de <string.h>.
 * La función modifica la oración original (sustituye espacios por '\0').
 */
char *palabraMasLarga(char *oracion)
{
    char *ptr_actual = oracion;
    char *ptr_larga = oracion;
    int max_longitud = 0;
    int longitud_actual = 0;

    // Recorrer la cadena
    while (*ptr_actual != '\0')
    {
        // 1. Saltar espacios (si los hay)
        while (*ptr_actual == ' ')
        {
            *ptr_actual = '\0'; // Terminamos la palabra anterior (si la había)
            ptr_actual++;
        }

        char *inicio_palabra = ptr_actual; // Puntero al inicio de la palabra actual
        longitud_actual = 0;

        // 2. Calcular la longitud de la palabra
        while (*ptr_actual != ' ' && *ptr_actual != '\0')
        {
            longitud_actual++;
            ptr_actual++;
        }

        // 3. Comparar longitud
        if (longitud_actual > max_longitud)
        {
            max_longitud = longitud_actual;
            ptr_larga = inicio_palabra; // Guardar el puntero a la palabra más larga
        }
        
        // Si llegamos a '\0', salimos del bucle principal en la siguiente iteración
        // Si llegamos a ' ', el bucle continuará y saltará el espacio.
    }

    return ptr_larga;
}