#include <iostream>
#include <string.h>
#include <stdlib.h> // Para const int N = 255;
#include <ctype.h>  // Para tolower

using namespace std;

const int N = 255; // Longitud máxima para la cadena y las palabras
const int MAX_PALABRAS = 20; // Número máximo de palabras a pluralizar

// Prototipos de las funciones auxiliares
bool esVocal(char v);
bool esConstante(char c);
bool es_e_acentuada(char c);
bool es_i_u_acentuada(char c);

// Prototipo de la función principal
void FormaPlural(char sing[], char plu[MAX_PALABRAS][N]);

int main()
{
    // Cadena de palabras de ejemplo
    char singular[] = "gato cafe te colibri bambu virtud razon mama sofa";
    
    // Array bidimensional para guardar los plurales
    char plurales[MAX_PALABRAS][N];
    
    cout << "Palabras en singular: " << singular << endl << endl;
    
    FormaPlural(singular, plurales);
    
    return 0;
}

// --- Implementación de Funciones Auxiliares ---

bool esVocal(char v)
{
    char c = tolower(v);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool esConstante(char c)
{
    char lower_c = tolower(c);
    // Es una letra (no dígito, ni signo, etc.) y no es una vocal ni acentuada
    if (lower_c >= 'a' && lower_c <= 'z')
    {
        return !esVocal(c);
    }
    return false;
}

bool es_e_acentuada(char c)
{
    return (c == 'é' || c == 'É');
}

bool es_i_u_acentuada(char c)
{
    return (c == 'í' || c == 'Í' || c == 'ú' || c == 'Ú');
}

// --- Implementación de la Función Principal ---

void FormaPlural(char sing[], char plu[MAX_PALABRAS][N])
{
    char temp_sing[N];
    strcpy(temp_sing, sing); // Copia para tokenizar
    
    char *token;
    int num_palabras = 0;
    
    // Lista de excepciones a las que se les aplica R1 (Añadir 's') a pesar de las reglas
    const char *excepciones[] = {"papa", "mama", "sofa", "cafe", "te"};
    const int NUM_EXCEPCIONES = 5;

    // Obtener el primer token (palabra)
    token = strtok(temp_sing, " "); 
    
    while (token != NULL && num_palabras < MAX_PALABRAS)
    {
        int longitud = strlen(token);
        char ultima = token[longitud - 1]; // Último carácter
        bool es_excepcion = false;
        
        // 1. Comprobar si es una excepción
        for (int i = 0; i < NUM_EXCEPCIONES; i++)
        {
            if (strcmp(token, excepciones[i]) == 0)
            {
                es_excepcion = true;
                break;
            }
        }
        
        // 2. Aplicar la regla de pluralización
        
        // A. Regla R1: Añadir 's'
        if (es_excepcion || (esVocal(ultima) && !es_e_acentuada(ultima) && !es_i_u_acentuada(ultima)) || es_e_acentuada(ultima))
        {
            // Aplica R1: Añadir 's' (gato, mesa, café, té)
            strcpy(plu[num_palabras], token);
            strcat(plu[num_palabras], "s");
        }
        
        // B. Regla R2: Añadir 'es'
        else if (esConstante(ultima) || es_i_u_acentuada(ultima))
        {
            // Aplica R2: Añadir 'es' (virtud, razón, colibrí, bambú)
            strcpy(plu[num_palabras], token);
            strcat(plu[num_palabras], "es");
        }
        
        // C. Caso no contemplado o error (copiar palabra original)
        else
        {
            strcpy(plu[num_palabras], token);
        }

        // 3. Imprimir el resultado
        cout << token << " -> " << plu[num_palabras] << endl;
        
        num_palabras++;
        token = strtok(NULL, " ");
    }
}