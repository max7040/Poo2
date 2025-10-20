#include <iostream>
#include <stdio.h> // para getch()
using namespace std;

// cuenta recursivamente la ocurrencia de un caracter en una cadena
int contador(char ch, char s[]);

int main() {
    char ch;
    char s[80];

    cout << "Ingrese cadena: ";
    cin.getline(s, 80);

    cout << "\nIngrese caracter a contar: ";
    ch = getchar(); // leer caracter desde la entrada

    cout << "\nCantidad de ocurrencias del caracter '" << ch << "' es: "
         << contador(ch, s) << endl;
    return 0;
}

int contador(char ch, char s[]) {
    if (s[0] == '\0') // caso base (fin de cadena)
        return 0;
    else { // caso general
        if (ch == s[0]) // si hay ocurrencia
            return 1 + contador(ch, &s[1]);
        else
            return contador(ch, &s[1]);
    }
}