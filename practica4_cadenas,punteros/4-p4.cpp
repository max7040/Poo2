#include <iostream>
#include <string.h> // Para strcpy y strcat
#include <stdio.h>  // Para gets()

using namespace std;

// Prototipe de la función
void generaRepetida(char resultado[], const char s[], int n);

int main()
{
    char S[100];      // Cadena a repetir
    char resultado[500]; // Cadena donde se guardará el resultado
    int N;            // Factor de multiplicación
    
    cout << "Ingrese la cadena S: ";
    gets(S);
    
    cout << "Ingrese el factor de multiplicacion N: ";
    cin >> N;
    
    generaRepetida(resultado, S, N);
    
    cout << "\nCadena S original: " << S << endl;
    cout << "Factor N: " << N << endl;
    cout << "Cadena generada: " << resultado << endl;
    
    return 0;
}

/*
 * Genera la cadena S N veces y la guarda en 'resultado'.
 * Usa el array 'resultado' como array de caracteres (cadena).
 */
void generaRepetida(char resultado[], const char s[], int n)
{
    // 1. Inicializar la cadena resultado a vacía
    resultado[0] = '\0'; 
    
    // 2. Repetir N veces
    for (int i = 0; i < n; i++)
    {
        // Concatenar la cadena S al final de la cadena resultado
        strcat(resultado, s);
    }
}