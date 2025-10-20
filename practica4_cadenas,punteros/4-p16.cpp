#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

// Prototipe de la función solicitada
void iniciales(char *p, char *q);

int main()
{
    char cadenaP[256] = "este examen esta muy facil";
    char cadenaQ[256]; // Debe ser lo suficientemente grande
    
    char *p = cadenaP; // p apunta a cadenaP
    char *q = cadenaQ; // q apunta a cadenaQ

    cout << "p apunta a la cadena: " << p << endl;
    
    iniciales(p, q);

    cout << "q apunta a la cadena: " << q << endl; // Debería ser "eeemf"

    return 0;
}

// Función que construye una cadena con las iniciales de las palabras
void iniciales(char *p, char *q)
{
    // El puntero q escribirá el resultado
    char *q_inicio = q; 
    
    // Mientras p no apunte al final de la cadena
    while (*p != '\0')
    {
        // 1. Guardar la inicial (el primer carácter de la palabra)
        *q = *p;
        q++; // Mover q al siguiente espacio de escritura

        // 2. Avanzar p hasta el espacio o fin de la cadena
        while (*p != ' ' && *p != '\0')
        {
            p++;
        }

        // 3. Saltar todos los espacios (para llegar al inicio de la siguiente palabra)
        while (*p == ' ')
        {
            p++;
        }
    }
    
    // Finalizar la cadena de destino con el carácter nulo
    *q = '\0';
    
    // No necesitamos reasignar q al inicio, ya que los punteros se pasan por valor.
    // Solo modificamos el contenido de la memoria a la que apuntan.
}