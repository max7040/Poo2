#include <iostream>
#include <stdio.h> // para putchar
#include <string.h> // para strlen
using namespace std;

void reversa_frase(char *s);

int main() {
    char s[] = "AMOR QUE BELLO ES AMARTE";
    
    cout << "\nCadena original: " << s << endl;
    cout << "\nCadena en reversa: ";
    reversa_frase(s);
    cout << endl;
    
    return 0;
}

void reversa_frase(char *s) {
    if (strlen(s) > 1) {
        // Llamada recursiva con el sub-string a partir del segundo caracter
        reversa_frase(&(s[1]));
    }
    // Imprime el primer caracter de la sub-cadena después de las llamadas recursivas
    putchar(s[0]);
}