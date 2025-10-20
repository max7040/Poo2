#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int contarConsonantesJuntas(char cadena[]);

int main()
{
    // Ejemplo proporcionado
    char cadena1[] = "El curso de algoritmos es interesante";
    int consonantes;

    consonantes = contarConsonantesJuntas(cadena1);

    cout << "Cadena: " << cadena1 << endl;
    cout << "Numero de pares de consonantes juntas: " << consonantes << endl; // Debería dar 5 (l-c, r-s, r-t, n-t, r-s)

    return 0;
}

// Verifica si un carácter es una consonante (asumiendo que letras son a-z/A-Z)
bool esConsonante(char c)
{
    c = tolower(c);
    if (c >= 'a' && c <= 'z')
    {
        // Si es una letra y no es vocal, es consonante
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
        {
            return true;
        }
    }
    return false;
}

// Función que cuenta el número de veces que dos consonantes están juntas
int contarConsonantesJuntas(char cadena[])
{
    int contador = 0;
    
    // Recorrer hasta el penúltimo carácter
    for (int i = 0; cadena[i+1] != '\0'; i++)
    {
        if (esConsonante(cadena[i]) && esConsonante(cadena[i+1]))
        {
            contador++;
        }
    }
    
    return contador;
}