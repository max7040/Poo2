#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int contarDiptongos(char cadena[]);

int main()
{
    // Ejemplo proporcionado
    char cadena1[] = "En el puerto de Huanchaco, Guayo miro al cielo y cogio la guanabana con el gigante";
    int diptongos;

    diptongos = contarDiptongos(cadena1);

    cout << "Cadena: " << cadena1 << endl;
    cout << "Numero de diptongos encontrados: " << diptongos << endl;

    // Otros ejemplos:
    char cadena2[] = "prohibido, desahucio, Piura";
    cout << "\nCadena: " << cadena2 << endl;
    cout << "Numero de diptongos (prohibido, desahucio, Piura): " << contarDiptongos(cadena2) << endl; 

    return 0;
}

// Determina el tipo de vocal
char tipoVocal(char c)
{
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'o')
    {
        return 'A'; // Abierta
    }
    else if (c == 'i' || c == 'u')
    {
        return 'C'; // Cerrada
    }
    return 'N'; // No vocal
}

// Función que cuenta el número de diptongos
int contarDiptongos(char cadena[])
{
    int contador = 0;
    
    // Recorrer hasta el penúltimo carácter
    for (int i = 0; cadena[i+1] != '\0'; i++)
    {
        char tipo1 = tipoVocal(cadena[i]);
        char tipo2 = tipoVocal(cadena[i+1]);
        
        // Regla 1: Dos vocales cerradas (C-C)
        if (tipo1 == 'C' && tipo2 == 'C')
        {
            contador++;
        }
        // Regla 2: Cerrada y Abierta (C-A)
        else if (tipo1 == 'C' && tipo2 == 'A')
        {
            contador++;
        }
        // Regla 3: Abierta y Cerrada (A-C)
        else if (tipo1 == 'A' && tipo2 == 'C')
        {
            contador++;
        }
    }
    
    return contador;
}