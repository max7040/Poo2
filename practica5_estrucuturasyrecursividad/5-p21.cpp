#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Prototipo de la función recursiva que devuelve la cadena podada.
string quitarEspacios(string s);

int main() {
    string cadena = "   cadena recursiva   ";
    cout << "Original: \"" << cadena << "\"" << endl;
    cout << "Podada: \"" << quitarEspacios(cadena) << "\"" << endl; // Salida: "cadena recursiva"

    cadena = "solo_un_espacio ";
    cout << "Original: \"" << cadena << "\"" << endl;
    cout << "Podada: \"" << quitarEspacios(cadena) << "\"" << endl; // Salida: "solo_un_espacio"
    
    return 0;
}

// Escribe una función recursiva que reciba una cadena s y proceda a quitar los 
// espacios en blanco que comience al inicio y al final de la cadena.
string quitarEspacios(string s) {
    // Caso base 1: Cadena vacía
    if (s.empty()) {
        return s;
    }
    
    // Eliminar espacios del inicio
    if (s.front() == ' ') {
        // Llamada recursiva con la cadena a partir del segundo caracter
        return quitarEspacios(s.substr(1));
    }
    
    // Eliminar espacios del final (solo si ya no hay espacios al inicio)
    if (s.back() == ' ') {
        // Llamada recursiva con la cadena sin el último caracter
        return quitarEspacios(s.substr(0, s.length() - 1));
    }

    // Caso base 2: No hay espacios al inicio ni al final, la cadena está limpia
    return s;
}