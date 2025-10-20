#include <iostream>
const int MAX = 255;
// funciones prototipo
int longcad(char *s);
int comparacad(char *s1, char *s2);
void copiacad(char *dest, char *orig);
using namespace std;

int main() // Mis_Func_Cadenas_3.cpp
{
    char Cadena[MAX];
    Cadena[0] = '\0';
    cout << "\n<1> longcad(Cadena) = " << longcad(Cadena) << endl;
    copiacad(Cadena, "Algoritmos y Programacion");
    cout << "\n<2> cadena: " << Cadena << endl;
    cout << "\n<3> longcad(Cadena) = " << longcad(Cadena) << endl;
    cout << "\n<4> comparacad(Cadena, " << "Algoritmos y Programacion) = ";
    cout << comparacad(Cadena, "Algoritmos y Programacion") << endl;
    cout << "\n<5> comparacad(Cadena, " << "Algoritmos) = ";
    cout << comparacad(Cadena, "Algoritmos") << endl;
    return 0;
}

int longcad(char *s)
{
    int i = 0;
    while (*s++)
        i++;
    return i;
}

int comparacad(char *s1, char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (int)(*s1 - *s2);
}

void copiacad(char *dest, char *orig)
{
    while (*dest++ = *orig++)
        ;
}