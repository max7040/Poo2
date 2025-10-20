#include <iostream>
const int MAX = 255;
// funciones prototipo
int longcad(char *s);
int comparacad(char *s1, char *s2);
void copiacad(char *dest, char *orig);
using namespace std;

int main() // Mis_Func_Cadenas_2.cpp
{
    char cadena[MAX];
    cadena[0] = '\0';
    cout << "\n<1> longcad(cadena) = " << longcad(cadena) << endl;
    copiacad(cadena, "Algoritmos y Programacion");
    cout << "\n<2> cadena: " << cadena << endl;
    cout << "\n<3> longcad(cadena) = " << longcad(cadena) << endl;
    cout << "\n<4> comparacad(cadena, " << "Algoritmos y Programacion) = ";
    cout << comparacad(cadena, "Algoritmos y Programacion") << endl;
    cout << "\n<5> comparacad(cadena, " << "Algoritmos) = ";
    cout << comparacad(cadena, "Algoritmos") << endl;
    return 0;
}

int longcad(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

int comparacad(char *s1, char *s2)
{
    int i = 0;
    for (; s1[i] != '\0' && s1[i] == s2[i]; i++)
        ;
    return (int)(s1[i] - s2[i]);
}

void copiacad(char *dest, char *orig)
{
    int i = 0;
    for (; orig[i] != '\0'; i++)
        dest[i] = orig[i];
    dest[i] = '\0';
}