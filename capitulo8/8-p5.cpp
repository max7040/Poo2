#include "Matriz.h"
#include <stdexcept> // Para excepciones (runtime_error)

// ------------------------------------
// IMPLEMENTACIÓN DE MÉTODOS PRIVADOS Y DE GESTIÓN DE MEMORIA
// ------------------------------------

void Matriz::liberarMemoria() {
    if (datos != nullptr) {
        for (int i = 0; i < filas; ++i) {
            delete[] datos[i];
        }
        delete[] datos;
        datos = nullptr;
    }
}

void Matriz::inicializarMemoria(int m, int n) {
    filas = m;
    columnas = n;
    datos = new double*[filas];
    for (int i = 0; i < filas; ++i) {
        datos[i] = new double[columnas](); // El '()' inicializa a cero
    }
}

// ------------------------------------
// IMPLEMENTACIÓN DE CONSTRUCTORES Y DESTRUCTOR
// ------------------------------------

// Constructor por defecto/parámetros
Matriz::Matriz(int m, int n) : filas(0), columnas(0), datos(nullptr) {
    if (m > 0 && n > 0) {
        inicializarMemoria(m, n);
    } else {
        throw std::invalid_argument("Las dimensiones de la matriz deben ser positivas.");
    }
}

// Constructor de copia
Matriz::Matriz(const Matriz& otra) : filas(0), columnas(0), datos(nullptr) {
    inicializarMemoria(otra.filas, otra.columnas);

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            datos[i][j] = otra.datos[i][j];
        }
    }
}

// Destructor
Matriz::~Matriz() {
    liberarMemoria();
}

// ------------------------------------
// IMPLEMENTACIÓN DE ENTRADA/SALIDA
// ------------------------------------

void Matriz::llenar() {
    cout << "Ingrese los " << filas * columnas << " elementos de la matriz " 
         << filas << "x" << columnas << ":" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> datos[i][j];
        }
    }
}

void Matriz::imprimir() const {
    cout << "Matriz " << filas << "x" << columnas << ":" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << setw(8) << fixed << setprecision(2) << datos[i][j];
        }
        cout << endl;
    }
}

// ------------------------------------
// IMPLEMENTACIÓN DE SOBRECARGA DE OPERADORES
// ------------------------------------

// Operador de Asignación (=)
Matriz& Matriz::operator=(const Matriz& otra) {
    // 1. Verificar auto-asignación
    if (this == &otra) {
        return *this;
    }

    // 2. Liberar memoria antigua si las dimensiones son diferentes
    if (filas != otra.filas || columnas != otra.columnas) {
        liberarMemoria();
        inicializarMemoria(otra.filas, otra.columnas);
    }

    // 3. Copiar los datos
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            datos[i][j] = otra.datos[i][j];
        }
    }

    return *this;
}

// Operador de Suma (+)
Matriz Matriz::operator+(const Matriz& otra) const {
    if (filas != otra.filas || columnas != otra.columnas) {
        throw std::runtime_error("Error: La suma requiere matrices de las mismas dimensiones.");
    }

    Matriz resultado(filas, columnas);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado.datos[i][j] = datos[i][j] + otra.datos[i][j];
        }
    }
    return resultado;
}

// Operador de Resta (-)
Matriz Matriz::operator-(const Matriz& otra) const {
    if (filas != otra.filas || columnas != otra.columnas) {
        throw std::runtime_error("Error: La resta requiere matrices de las mismas dimensiones.");
    }

    Matriz resultado(filas, columnas);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado.datos[i][j] = datos[i][j] - otra.datos[i][j];
        }
    }
    return resultado;
}

// Operador de Multiplicación (*)
Matriz Matriz::operator*(const Matriz& otra) const {
    // Validación: La columna de la matriz izquierda (this->columnas) debe ser igual
    // a la fila de la matriz derecha (otra.filas).
    if (columnas != otra.filas) {
        throw std::runtime_error("Error: La multiplicacion requiere que columnas de la primera matriz sean iguales a las filas de la segunda.");
    }

    // La matriz resultante es: this->filas x otra.columnas
    Matriz resultado(filas, otra.columnas);

    for (int i = 0; i < filas; ++i) { // Fila de la Matriz A
        for (int j = 0; j < otra.columnas; ++j) { // Columna de la Matriz B
            double suma = 0.0;
            for (int k = 0; k < columnas; ++k) { // Recorrido para la suma de productos
                suma += datos[i][k] * otra.datos[k][j];
            }
            resultado.datos[i][j] = suma;
        }
    }
    return resultado;
}

// Operador de Igualdad (==)
bool Matriz::operator==(const Matriz& otra) const {
    // 1. Verificar dimensiones
    if (filas != otra.filas || columnas != otra.columnas) {
        return false;
    }

    // 2. Verificar elemento por elemento
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            // Usar una pequeña tolerancia para flotantes si fuera necesario,
            // pero para este ejercicio usaremos igualdad estricta.
            if (datos[i][j] != otra.datos[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Operador de Desigualdad (!=)
bool Matriz::operator!=(const Matriz& otra) const {
    return !(*this == otra); // Se define en términos del operador ==
}

// ------------------------------------
// PROGRAMA DE PRUEBA (main)
// ------------------------------------

int main() {
    try {
        // Inicialización y Asignación
        Matriz A(2, 2);
        Matriz B(2, 2);
        Matriz C(2, 3);
        
        cout << "Llenando Matriz A (2x2):" << endl;
        A.llenar(); // Ej: 1 2 / 3 4
        cout << "\nLlenando Matriz B (2x2):" << endl;
        B.llenar(); // Ej: 5 6 / 7 8
        
        cout << "\n--- Matrices Iniciales ---" << endl;
        A.imprimir();
        B.imprimir();

        // Prueba de Suma y Resta
        Matriz Suma = A + B;
        cout << "\n--- Suma (A + B) ---" << endl;
        Suma.imprimir();

        Matriz Resta = A - B;
        cout << "\n--- Resta (A - B) ---" << endl;
        Resta.imprimir();

        // Prueba de Multiplicación
        Matriz D(2, 2); // Matriz para la multiplicacion 2x2 * 2x2
        D = A * B;
        cout << "\n--- Multiplicacion (A * B) ---" << endl;
        D.imprimir(); // (1*5+2*7) (1*6+2*8) / (3*5+4*7) (3*6+4*8) = 19 22 / 43 50

        // Prueba de Asignación (=)
        Matriz E(1, 1);
        E = A; // E ahora es una copia de A
        cout << "\n--- Asignacion (E = A) ---" << endl;
        E.imprimir();

        // Prueba de Igualdad (==) y Desigualdad (!=)
        cout << "\n--- Comparacion ---" << endl;
        cout << "A == E: " << (A == E ? "Verdadero" : "Falso") << endl;
        cout << "A != B: " << (A != B ? "Verdadero" : "Falso") << endl;
        cout << "A == C (Dimensiones diferentes): " << (A == C ? "Verdadero" : "Falso") << endl;

    } catch (const std::exception& e) {
        cerr << "Excepcion: " << e.what() << endl;
    }

    return 0;
}