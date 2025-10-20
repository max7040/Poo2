#include <iostream>
using namespace std;
int main() // Cadena_9.cpp
{
    char s[] = "Rosita Linda";
    cout << "Cadena impresa con espacios en blanco entre caracteres:\n";
    // Observa el uso de la función sizeof para determinar el número de
    // caracteres de la cadena
    for (int i = 0; i < sizeof(s) / sizeof(char); i++)
        cout << s[i] << " ";
    cout << "\n" << endl;
    return 0;
}