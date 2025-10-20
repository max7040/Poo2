#include <iostream>
#include <ctype.h> // Para tolower

using namespace std;

int main()
{
    char cadena[256];
    int fuertes = 0;
    int debiles = 0;

    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(cadena, 256);

    // Recorrer la cadena
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        // Convertir a minúscula para simplificar la comparación
        char c = tolower(cadena[i]);

        if (c == 'a' || c == 'e' || c == 'o')
        {
            fuertes++;
        }
        else if (c == 'i' || c == 'u')
        {
            debiles++;
        }
    }

    cout << "\nReporte de Vocales:\n";
    cout << "Vocales Fuertes (A, E, O): " << fuertes << endl;
    cout << "Vocales Debiles (I, U): " << debiles << endl;

    return 0;
}