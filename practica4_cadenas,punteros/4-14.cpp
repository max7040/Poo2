#include <iostream>
const int MAX = 255;
// funciones prototipo
int longcad(char s[MAX]); // Emula a strlen()
int comparacad(char s1[MAX], char s2[MAX]); // Emula a strcmp()
void copiacad(char dest[MAX], char orig[MAX]); // Emula a strcpy()
using namespace std;

int main() // Mis_Func_Cadenas.cpp
{
    char cadena[MAX];
    cadena[0] = '\0';
    cout << "\n<1> longcad(cadena) = " << longcad(cadena) << endl;
    copiacad(cadena, "Algoritmos y Programacion");
    cout << "\n<2> cadena: " << cadena << endl;
    cout << "\n<3> longcad(cadena) = " << longcad(cadena) << endl;
    cout << "\n<4> comparacad(cadena, " << "Algoritmos y Programacion) = ";
    cout << comparacad(cadena, "Algoritmos y Programacion") << endl;
    cout << "\n<5> comparacad(cadena, " << "Programacion) = ";
    cout << comparacad(cadena, "Programacion") << endl;
    return 0;
}

int longcad(char s[MAX])
{
    int i = 0;
    while (s[i] != '\0') // mientras s[i] no sea fin de cadena
        i++;
    return i; // devuelve el número de caracteres
}

int comparacad(char s1[MAX], char s2[MAX])
{
    int i = 0;
    for (; s1[i] != '\0' && s1[i] == s2[i]; i++)
        ;
    return (int)(s1[i] - s2[i]); // retorna la diferencia de las cadenas
}

void copiacad(char dest[MAX], char orig[MAX])
{
    int i = 0;
    for (; orig[i] != '\0'; i++)
        dest[i] = orig[i]; // copia caracter a caracter
    dest[i] = '\0';
}