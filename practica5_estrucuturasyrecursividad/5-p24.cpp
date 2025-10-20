#include <iostream>
using namespace std;

void imprimirEnBaseB(int n, int b);

int main() {
    cout << "25 en base 8: "; imprimirEnBaseB(25, 8); cout << endl; // Salida: 31
    cout << "42 en base 2: "; imprimirEnBaseB(42, 2); cout << endl; // Salida: 101010
    
    return 0;
}

// Función que imprima recursivamente el número entero en la base b.
void imprimirEnBaseB(int n, int b) {
    // Manejar el caso de n=0
    if (n == 0) {
        return;
    }

    // Llamada recursiva con el cociente (se llama antes de imprimir para obtener el orden correcto)
    imprimirEnBaseB(n / b, b);
    
    // Imprime el residuo (el dígito en la base b)
    cout << n % b;
}
#include <iostream>
#include <string>
#include <cctype> // Para tolower
#include <cstring> // Para strlen (si se usa char*)
using namespace std;

// Función que recibe una cadena de caracteres (char*) y devuelve el número de consonantes.
int contarConsonantes(const char* s);

int main() {
    const char* cadena = "El murcielago";
    cout << "La cadena \"" << cadena << "\" tiene " << contarConsonantes(cadena) << " consonantes." << endl; // Esperado: 8
    
    return 0;
}

// Función auxiliar para verificar si un carácter es una consonante
bool esConsonante(char c) {
    char lowerC = tolower(c);
    // Verificamos si es una letra Y no es una vocal (incluyendo vocales con acento)
    if (isalpha(lowerC)) {
        if (lowerC != 'a' && lowerC != 'e' && lowerC != 'i' && lowerC != 'o' && lowerC != 'u') {
             // Es una letra y no es vocal -> es consonante
            return true;
        }
    }
    return false;
}

// Implementación recursiva: devuelve el número de consonantes
int contarConsonantes(const char* s) {
    // Caso base: Si la cadena está vacía (apunta al terminador nulo '\0')
    if (*s == '\0') {
        return 0;
    }

    // 1. Contar la consonante actual (0 o 1)
    int cuentaActual = esConsonante(*s) ? 1 : 0;
    
    // 2. Llamada recursiva con el resto de la cadena (s + 1 apunta al siguiente carácter)
    return cuentaActual + contarConsonantes(s + 1);
}