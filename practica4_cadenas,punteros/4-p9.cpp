#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

// Función auxiliar para convertir toda la cadena a minúsculas
void toLowerCadena(char cad[])
{
    for (int i = 0; cad[i] != '\0'; i++)
    {
        cad[i] = tolower(cad[i]);
    }
}

int main()
{
    char oracion[256];
    char palabra[50];
    char temp_oracion[256]; // Copia de la oración para no modificar la original
    int contador = 0;

    cout << "Ingrese la oracion (cadena 1): ";
    gets(oracion);

    cout << "Ingrese la palabra a buscar (cadena 2): ";
    gets(palabra);
    
    // Copiar y convertir a minúsculas para búsqueda insensible
    strcpy(temp_oracion, oracion);
    toLowerCadena(temp_oracion);
    toLowerCadena(palabra);

    // Añadir espacios al inicio y fin para asegurar que se buscan palabras completas
    // (Ejemplo: buscar "la" en "tabla" no debe contar)
    char busqueda[256] = " ";
    strcat(busqueda, palabra);
    strcat(busqueda, " ");
    
    char temp_padded[258] = " ";
    strcat(temp_padded, temp_oracion);
    strcat(temp_padded, " ");


    // Usar la función strstr para buscar la subcadena
    char *ptr = temp_padded;
    
    while ((ptr = strstr(ptr, busqueda)) != NULL)
    {
        contador++;
        // Avanzar el puntero para continuar la búsqueda después de la ocurrencia
        ptr += strlen(busqueda) - 1; // Avanza hasta casi el final de la palabra encontrada
    }

    cout << "\nLa palabra '" << palabra << "' aparece " << contador << " veces en la oracion." << endl;

    return 0;
}