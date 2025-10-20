#include <iostream>
#include <string>
#include <cstring> // Para strlen (aunque usamos char*)
#include <cctype>  // Para tolower y isalpha
using namespace std;

// Prototipo
int contarConsonantes(const char* s);

// Función auxiliar para verificar si un carácter es una consonante
bool esConsonante(char c) {
    char lowerC = tolower(c);
    
    // 1. Debe ser una letra
    if (!isalpha(lowerC)) {
        return false;
    }

    // 2. No debe ser una vocal
    if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
        return false;
    }
    
    // Es una letra y no es vocal -> es consonante
    return true;
}

// Implementación recursiva: devuelve el número de consonantes
int contarConsonantes(const char* s) {
    // Caso base: Si la cadena está vacía (apunta al terminador nulo '\0')
    if (*s == '\0') {
        return 0;
    }

    // 1. Determinar si el carácter actual es una consonante
    int cuentaActual = esConsonante(*s) ? 1 : 0;
    
    // 2. Llamada recursiva con el resto de la cadena (s + 1 apunta al siguiente carácter)
    return cuentaActual + contarConsonantes(s + 1);
}

int main() {
    const char* cadena1 = "El murcielago";
    cout << "La cadena \"" << cadena1 << "\" tiene " << contarConsonantes(cadena1) << " consonantes." << endl; // Salida: 8

    const char* cadena2 = "AEIOU 123";
    cout << "La cadena \"" << cadena2 << "\" tiene " << contarConsonantes(cadena2) << " consonantes." << endl; // Salida: 0
    
    return 0;
}