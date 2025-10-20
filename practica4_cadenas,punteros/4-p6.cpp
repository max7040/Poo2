#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAX_PALABRAS = 30; // Maximo número de palabras
const int MAX_LONG_CADENA = 256;

// Prototipe de la función de ayuda para tokenizar
int separarPalabras(char cadena[], char *vectorPalabras[]);

// Prototipe de la función principal solicitada
void intercambiarPalabras(char cadena[], int pos1, int pos2);

int main()
{
    char cadena[MAX_LONG_CADENA];
    int pos1, pos2;

    cout << "Ingrese la cadena de caracteres (con espacios): ";
    gets(cadena);

    cout << "Ingrese la posicion de la primera palabra a intercambiar (empezando en 0): ";
    cin >> pos1;

    cout << "Ingrese la posicion de la segunda palabra a intercambiar (empezando en 0): ";
    cin >> pos2;

    intercambiarPalabras(cadena, pos1, pos2);

    cout << "\nCadena con palabras intercambiadas: " << cadena << endl;

    return 0;
}

// Función para separar la cadena en palabras (tokens)
int separarPalabras(char cadena[], char *vectorPalabras[])
{
    int numPalabras = 0;
    // Usa strchr para encontrar el inicio de la siguiente palabra
    char *token = cadena;

    // Recorre la cadena sustituyendo espacios por '\0' y guardando punteros
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == ' ')
        {
            cadena[i] = '\0'; // Marca el fin de la palabra
            vectorPalabras[numPalabras++] = token; // Guarda el puntero al inicio de la palabra
            
            // Avanza 'token' al caracter siguiente, que es el inicio de la próxima palabra
            token = &cadena[i + 1]; 
        }
    }
    // Guarda el puntero de la última palabra
    vectorPalabras[numPalabras++] = token; 

    return numPalabras;
}

// Función que intercambia dos palabras en la cadena por posición
void intercambiarPalabras(char cadena[], int pos1, int pos2)
{
    // Array de punteros donde guardaremos las palabras
    char *palabras[MAX_PALABRAS]; 
    char temp[MAX_LONG_CADENA];
    
    // Almacenar temporalmente la cadena original
    strcpy(temp, cadena); 

    int totalPalabras = separarPalabras(temp, palabras);

    // Verificar que las posiciones sean válidas
    if (pos1 < 0 || pos1 >= totalPalabras || pos2 < 0 || pos2 >= totalPalabras)
    {
        cout << "Error: Posiciones fuera de rango." << endl;
        return;
    }
    
    // Intercambiar las palabras en el array de punteros
    char *tempPtr = palabras[pos1];
    palabras[pos1] = palabras[pos2];
    palabras[pos2] = tempPtr;

    // Reconstruir la cadena original en 'cadena'
    cadena[0] = '\0'; // Inicializar la cadena de resultado

    for (int i = 0; i < totalPalabras; i++)
    {
        strcat(cadena, palabras[i]); // Añade la palabra
        // Añade un espacio después de cada palabra, excepto la última
        if (i < totalPalabras - 1)
        {
            strcat(cadena, " "); 
        }
    }
}