#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAX_FORMULAS = 20;
const int MAX_LONG_FORMULA = 10;
// Array bidimensional para almacenar el contenido de las fórmulas
char buffer_hidrox[MAX_FORMULAS][MAX_LONG_FORMULA]; 

// Prototipe de la función solicitada con punteros
// char *formu: Puntero a la cadena de entrada
// char *hidrox[]: Array de punteros que apuntarán a las fórmulas válidas
int encuentraHidroxidosPunteros(char *formu, char *hidrox[]);

int main()
{
    char formu[] = "KOH H2O2 NaCl NaOH MgOH CO2 C9H8O4 CaOH";
    char *hidrox[MAX_FORMULAS]; // Array de punteros

    // Inicializar el array de punteros para que apunte a las filas del buffer estático
    for (int i = 0; i < MAX_FORMULAS; i++)
    {
        hidrox[i] = buffer_hidrox[i];
    }
    
    int cantidad = encuentraHidroxidosPunteros(formu, hidrox);
    
    cout << "Cadena de formulas: " << formu << endl;
    cout << "\nEl vector hidrox generado (usando punteros) sera:" << endl;
    for (int i = 0; i < cantidad; i++)
    {
        // Imprimir usando el puntero del array
        cout << hidrox[i] << " "; 
    }
    cout << endl;

    cout << "La funcion devolvio el valor: " << cantidad << endl; // Devolverá 4
    
    return 0;
}

// Implementación de la función con punteros
int encuentraHidroxidosPunteros(char *formu, char *hidrox[])
{
    char temp_formu[512]; // Copia temporal para tokenizar
    char *token;
    int contador_hidroxidos = 0;
    
    // 1. Copiar la cadena (apuntada por *formu) a un buffer temporal
    strcpy(temp_formu, formu);
    
    // 2. Tokenizar la cadena
    token = strtok(temp_formu, " "); 
    
    while (token != NULL)
    {
        int longitud = strlen(token);
        
        // 3. Verificar si termina en "OH"
        if (longitud >= 2)
        {
            if (token[longitud - 2] == 'O' && token[longitud - 1] == 'H')
            {
                // Es un hidróxido:
                if (contador_hidroxidos < MAX_FORMULAS)
                {
                    // Almacenar el hidróxido en el espacio apuntado por hidrox[contador_hidroxidos]
                    // (que ya fue configurado en main para apuntar a buffer_hidrox[i])
                    strcpy(hidrox[contador_hidroxidos], token);
                    contador_hidroxidos++;
                }
            }
        }
        
        // Obtener el siguiente token
        token = strtok(NULL, " ");
    }
    
    return contador_hidroxidos;
}