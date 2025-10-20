#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAX_FORMULAS = 20; // N (Número máximo de fórmulas)
const int MAX_LONG_FORMULA = 10; // M (Longitud máxima de cada fórmula)

// Prototipe de la función solicitada (Asumimos N=MAX_FORMULAS y M=MAX_LONG_FORMULA)
int encuentraHidroxidos(char formu[], char hidrox[MAX_FORMULAS][MAX_LONG_FORMULA]);

int main()
{
    // Ejemplo de entrada
    char formu[] = "KOH H2O2 NaCl NaOH MgOH CO2 C9H8O4 CaOH";
    char hidrox[MAX_FORMULAS][MAX_LONG_FORMULA];
    int cantidad;
    
    cout << "Cadena de formulas: " << formu << endl;

    cantidad = encuentraHidroxidos(formu, hidrox);
    
    cout << "\nEl vector hidrox generado por la funcion sera:" << endl;
    for (int i = 0; i < cantidad; i++)
    {
        cout << hidrox[i] << " ";
    }
    cout << endl;

    cout << "La funcion devolvio el valor: " << cantidad << endl; // Devolverá 4
    
    return 0;
}

// Implementación de la función
int encuentraHidroxidos(char formu[], char hidrox[MAX_FORMULAS][MAX_LONG_FORMULA])
{
    char temp_formu[512]; // Copia temporal para tokenizar
    char *token;
    int contador_hidroxidos = 0;
    
    // 1. Copiar la cadena para no modificar la original
    strcpy(temp_formu, formu);
    
    // 2. Tokenizar la cadena (separar por espacios)
    // El primer token es la primera fórmula
    token = strtok(temp_formu, " "); 
    
    // 3. Recorrer todos los tokens (fórmulas)
    while (token != NULL)
    {
        int longitud = strlen(token);
        
        // 4. Verificar si termina en "OH"
        // La fórmula debe tener al menos 2 caracteres para terminar en OH
        if (longitud >= 2)
        {
            // Comprobar los dos últimos caracteres
            if (token[longitud - 2] == 'O' && token[longitud - 1] == 'H')
            {
                // Es un hidróxido: almacenar y contar
                if (contador_hidroxidos < MAX_FORMULAS)
                {
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