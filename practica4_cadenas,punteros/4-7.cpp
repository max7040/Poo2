#include <iostream>
#include <string.h>
using namespace std;
// Uso de las funciones strcat() y strncat()
int main() // Cadena_6.cpp
{
    char s1[100] = "Con todo lo bueno que";
    char s2[] = " significa heredaste una biblioteca.";
    char s3[] = " mejor aun es reunirla - Augustine Birrel";
    cout << "\nFunciones strcat() y strncat():" << endl;
    // strcat() concantena una cadena a otra
    strcat(s1, s2);
    cout << "\nConcatenar s2 en s1: ";
    cout << s1 << endl;
    
    // strcat()
    strcat(s1, s3);
    cout << "\nConcatenar s1 en s1: ";
    cout << s1 << endl;

    // strncat() Concantena los primeros n caracteres de una cadena
    // a otra
    cout << "\nParte de la s3 concatenada en s2: ";
    strncat(s2, s3, 10);
    cout << endl << s2 << endl;
    return 0;
}