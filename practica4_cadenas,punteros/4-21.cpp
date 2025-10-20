#include <iostream>
#include <stdio.h> // para gets(), puts()
#include <string.h> // para strcat(), strlen(), strcpy()
const int N = 25; // 25 filas
const int M = 80; // 80 columnas
void guardaPalabrasLongitudN(char cad[], char vector[N][M], int n);
void imprimeVectorCadenas(char vector[N][M], int k);
using namespace std;

int main() // Matriz_Cadenas_2.cpp
{
    char cad[256], vector[N][M];
    int n;
    cout << "\nIngrese una cadena: ";
    gets(cad);
    cout << "\nIngrese longitud de las palabras a buscar y guardar en el vector de cadenas: ";
    cin >> n;
    guardaPalabrasLongitudN(cad, vector, n);
    return 0;
}

void guardaPalabrasLongitudN(char cad[], char vector[N][M], int n)
{
    int i = 0, j = 0, k = 0; // indices
    char palab[M];
    
    // añade un espacio en blanco al final para asegurar que la última palabra sea procesada
    strcat(cad, " "); 
    
    while (cad[i] != '\0')
    {
        // Saltar espacios en blanco
        while (cad[i] == ' ')
        {
            i++;
        }
        
        // Sacar las palabras
        j = 0;
        while (cad[i] != ' ' && cad[i] != '\0')
        {
            palab[j] = cad[i];
            j++;
            i++;
        }
        
        palab[j] = '\0'; // Añade la marca de fin de cadena
        
        if (strlen(palab) == n)
        {
            // guardar palabra en el vector de cadenas
            strcpy(vector[k], palab);
            k++;
        }
    }
    imprimeVectorCadenas(vector, k);
}

void imprimeVectorCadenas(char vector[N][M], int k)
{
    cout << "\nVector de cadenas formado\n" << endl;
    for (int i = 0; i < k; i++)
    {
        puts(vector[i]);
    }
    cout << endl << endl;
    cout << "Se tienen " << k << " cadenas en el vector" << endl;
}