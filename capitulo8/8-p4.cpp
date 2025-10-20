#include "Polinomio.h"

// ------------------------------------
// IMPLEMENTACIÓN DE MÉTODOS AUXILIARES PRIVADOS
// ------------------------------------

// Busca un monomio con exponente 'ex'. Retorna el índice o -1 si no lo encuentra.
int Polinomio::find(float ex) const {
    for (int i = 0; i < size; ++i) {
        if (mons[i].exp == ex) {
            return i;
        }
    }
    return -1;
}

// Limpia el arreglo eliminando los monomios con coeficiente cero.
void Polinomio::clean() {
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (mons[i].coef != 0) {
            mons[newSize] = mons[i];
            newSize++;
        }
    }
    size = newSize;
}

// ------------------------------------
// IMPLEMENTACIÓN DE CONSTRUCTORES
// ------------------------------------

// Constructor por defecto (Polinomio vacío)
Polinomio::Polinomio() : size(0) {}

// Constructor de un solo monomio (float co, float ex)
Polinomio::Polinomio(float co, float ex) : size(0) {
    if (co != 0) {
        // Se asume la variable 'x' por defecto.
        add(co, ex);
    }
}

// Constructor de copia
Polinomio::Polinomio(const Polinomio &other) {
    size = other.size;
    for (int i = 0; i < size; ++i) {
        // Copia superficial de monomio (arriesgado por char*car, pero se sigue la estructura)
        mons[i].car = other.mons[i].car;
        mons[i].coef = other.mons[i].coef;
        mons[i].exp = other.mons[i].exp;
    }
}

// ------------------------------------
// IMPLEMENTACIÓN DE MÉTODOS PÚBLICOS ADD
// ------------------------------------

// Añade monomio, simplificando si ya existe el exponente
void Polinomio::add(const monomio &m) {
    add(m.coef, m.exp);
}

// Añade monomio por coeficiente y exponente
void Polinomio::add(float co, float ex) {
    if (co == 0) return;

    int index = find(ex);

    if (index != -1) {
        // El monomio existe, suma los coeficientes y limpia si es cero.
        mons[index].coef += co;
        clean();
    } else if (size < N) {
        // Es un monomio nuevo y hay espacio.
        mons[size] = monomio(co, ex);
        size++;
    } else {
        cerr << "Error: Polinomio lleno (N=" << N << "). No se pudo añadir el monomio." << endl;
    }
}

// ------------------------------------
// IMPLEMENTACIÓN DE OPERADORES BINARIOS (Devuelven nuevo objeto)
// ------------------------------------

// Operador de suma: Polinomio + Polinomio
Polinomio Polinomio::operator+(const Polinomio &other) const {
    Polinomio result = *this; // Copia inicial de *this

    for (int i = 0; i < other.size; ++i) {
        // Añade cada monomio del otro polinomio al resultado
        result.add(other.mons[i]);
    }

    return result;
}

// Operador de resta: Polinomio - Polinomio
Polinomio Polinomio::operator-(const Polinomio &other) const {
    Polinomio result = *this; // Copia inicial de *this

    for (int i = 0; i < other.size; ++i) {
        // Añade el monomio con coeficiente negado
        result.add(-other.mons[i].coef, other.mons[i].exp);
    }

    return result;
}

// ------------------------------------
// IMPLEMENTACIÓN DE OPERADORES DE ASIGNACIÓN (Modifican *this)
// ------------------------------------

// Operador de asignación: Polinomio = Polinomio
Polinomio Polinomio::operator=(const Polinomio &other) {
    if (this != &other) { // Verifica auto-asignación
        // Copia de los datos
        size = other.size;
        for (int i = 0; i < size; ++i) {
             // Copia superficial (igual que el constructor de copia)
            mons[i].car = other.mons[i].car;
            mons[i].coef = other.mons[i].coef;
            mons[i].exp = other.mons[i].exp;
        }
    }
    return *this;
}

// Operador de suma y asignación: Polinomio += Polinomio
Polinomio Polinomio::operator+=(const Polinomio &other) {
    for (int i = 0; i < other.size; ++i) {
        this->add(other.mons[i]);
    }
    return *this;
}

// Operador de resta y asignación: Polinomio -= Polinomio
Polinomio Polinomio::operator-=(const Polinomio &other) {
    for (int i = 0; i < other.size; ++i) {
        // Añade el monomio con coeficiente negado
        this->add(-other.mons[i].coef, other.mons[i].exp);
    }
    return *this;
}

// ------------------------------------
// IMPLEMENTACIÓN DE FUNCIÓN AMIGA PRINT
// ------------------------------------

// Imprime el polinomio en formato legible (ej: 3.0x^2 + 5.0)
void print(const Polinomio &pol) {
    if (pol.size == 0) {
        cout << "0";
        return;
    }

    for (int i = 0; i < pol.size; ++i) {
        float co = pol.mons[i].coef;
        float ex = pol.mons[i].exp;

        // Imprime el signo: '+' excepto para el primer monomio
        if (i > 0 && co > 0) {
            cout << " + ";
        } else if (co < 0) {
            // Imprime el signo '-' para coeficientes negativos
            if (i > 0) cout << " ";
            cout << "- ";
        }

        float abs_co = abs(co);

        // Imprime el coeficiente
        if (abs_co != 1 || ex == 0) {
            cout << abs_co;
        }

        // Imprime la variable 'x' y el exponente
        if (ex != 0) {
            if (abs_co != 1) { // Si el coeficiente no es 1, agrega un espacio
                cout << "";
            }
            cout << "x";
            if (ex != 1) {
                cout << "^" << ex;
            }
        }
    }
}

// ------------------------------------
// PROGRAMA DE PRUEBA (main)
// ------------------------------------

int main() {
    // Polinomio A: 3x^2 + 5x^1 - 2x^0
    Polinomio A(3.0, 2.0);
    A.add(5.0, 1.0);
    A.add(-2.0, 0.0);
    cout << "Polinomio A: "; print(A); cout << endl; // 3x^2 + 5x^1 - 2

    // Polinomio B: 2x^2 + 1x^0
    Polinomio B(2.0, 2.0);
    B.add(1.0, 0.0);
    cout << "Polinomio B: "; print(B); cout << endl; // 2x^2 + 1

    // 1. Prueba de Suma (+)
    Polinomio C = A + B;
    cout << "C = A + B: "; print(C); cout << endl; // 5x^2 + 5x^1 - 1

    // 2. Prueba de Resta (-)
    Polinomio D = A - B;
    cout << "D = A - B: "; print(D); cout << endl; // 1x^2 + 5x^1 - 3

    // 3. Prueba de Suma y Asignación (+=)
    A += B;
    cout << "A += B : "; print(A); cout << endl; // 5x^2 + 5x^1 - 1 (A modificado)

    // 4. Prueba de Resta y Asignación (-=)
    A -= B;
    cout << "A -= B : "; print(A); cout << endl; // 3x^2 + 5x^1 - 2 (A vuelve al original)

    // 5. Prueba de Asignación (=)
    Polinomio E;
    E = D;
    cout << "E = D: "; print(E); cout << endl; // 1x^2 + 5x^1 - 3

    return 0;
}
