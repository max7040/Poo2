#include <iostream>
#include <string.h> // Para strlen (aunque no es estrictamente necesaria)
#include <ctype.h>  // Para tolower

using namespace std;

int main()
{
    char cadena[256];
    char vocal;
    int contador = 0;

    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(cadena, 256); // Usamos cin.getline para leer toda la línea

    cout << "Ingrese la vocal a buscar (a, e, i, o, u): ";
    cin >> vocal;

    // Convertir la vocal de búsqueda a minúscula para una búsqueda insensible a mayúsculas
    char vocal_minuscula = tolower(vocal);

    // Recorrer la cadena
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        // Convertir el caracter actual de la cadena a minúscula para la comparación
        if (tolower(cadena[i]) == vocal_minuscula)
        {
            contador++;
        }
    }

    cout << "\nLa vocal '" << vocal << "' aparece " << contador << " veces en la cadena." << endl;
    return 0;
}