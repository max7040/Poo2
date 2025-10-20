#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAX_LONG_CADENA = 512;

// Prototipe de la función solicitada
void reemplazar(char principal[], char a_reemplazar[], char reemplazo[]);

int main()
{
    char principal[MAX_LONG_CADENA];
    char a_reemplazar[100];
    char reemplazo[100];
    
    cout << "Ingrese la cadena principal: ";
    gets(principal);

    cout << "Ingrese la subcadena a reemplazar: ";
    gets(a_reemplazar);

    cout << "Ingrese la subcadena de reemplazo: ";
    gets(reemplazo);

    reemplazar(principal, a_reemplazar, reemplazo);

    cout << "\nCadena final: " << principal << endl;

    return 0;
}

// Función que reemplaza todas las ocurrencias de una subcadena por otra
void reemplazar(char principal[], char a_reemplazar[], char reemplazo[])
{
    char buffer[MAX_LONG_CADENA]; // Buffer temporal para reconstruir la cadena
    char *ptr = principal;
    char *sub_ptr;

    buffer[0] = '\0'; // Inicializar el buffer

    // Mientras se encuentre la subcadena
    while ((sub_ptr = strstr(ptr, a_reemplazar)) != NULL)
    {
        // 1. Copiar la parte antes de la ocurrencia al buffer
        int longitud_antes = sub_ptr - ptr;
        strncat(buffer, ptr, longitud_antes); 
        
        // 2. Concatenar la cadena de reemplazo
        strcat(buffer, reemplazo);
        
        // 3. Mover el puntero 'ptr' para que apunte al inicio de la siguiente búsqueda
        ptr = sub_ptr + strlen(a_reemplazar);
    }

    // 4. Concatenar el resto de la cadena (lo que queda después de la última ocurrencia)
    strcat(buffer, ptr);

    // 5. Copiar el resultado final de vuelta a la cadena principal
    strcpy(principal, buffer);
}