#include <iostream>
#include <string.h>
const int N = 20;
const int M = 20;
int GeneraVectorCadena(char c[], char vc[N][M], char car);
using namespace std;

int main() // Matriz_Cadenas_071.cpp
{
    char C[] = "Electron, tipo de particula elemental de carga negativa que forma parte de la familia de los leptones y que, junto con los protones y los neutrones, forma los atomos y las moleculas. Los electrones estan presentes en todos los atomos y cuando son arrancados del atomo se llaman electrones libres";
    char vc[N][M];
    char car = 'e';
    int npals;
    
    cout << "\nPalabras en el vector de cadenas:" << endl;
    npals = GeneraVectorCadena(C, vc, car);
    cout << "\n\nNumero de palabras almacenadas en el vector = " << npals << endl << endl;
    return 0;
}

int GeneraVectorCadena(char C[], char vc[N][M], char car)
{
    int i = 0, j = 0, k = 0, ContPal = 0;
    char palab[20];
    
    // Añadir un espacio al final para procesar la última palabra
    strcat(C, " "); 
    
    while (C[i] != '\0')
    {
        // Saltar espacios en blanco
        while (C[i] == ' ')
        {
            i++;
        }
        
        // Sacando cada palabra
        j = 0;
        while (C[i] != ' ' && C[i] != '\0')
        {
            palab[j] = C[i];
            j++;
            i++;
        }
        
        palab[j] = '\0'; // fin de palabra
        
        // si mi primer caracter de palabra es igual a car
        if (palab[0] == car)
        {
            // se mete en el vector de cadenas
            strcpy(vc[k], palab);
            k++;
            cout << k << ": " << vc[k-1] << endl; // imprime palabra almacenada en el vector
            ContPal++;
        }
    }
    return ContPal;
}