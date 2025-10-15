#include <iostream>
#include <cmath> // Para las funciones sin() y cos()

// *** CORRECCIÓN 1: Definición de PI ***
// Definimos PI ya que M_PI no siempre está disponible.
const double PI = 3.14159265358979323846;

using namespace std;

// clase base
class angulo {
public:
    void set_ang(int ang) { a = ang; }
    int get_ang() { return a; }

private:
    int a;
};

// clases derivadas seno y coseno
class seno : public angulo {
public:
    void valor(int ang);
};

class coseno : public angulo {
public:
    void valor(int ang);
};

// Implementación de la función seno::valor (¡Corregida!)
void seno::valor(int ang) {
    // Establece el ángulo en la clase base
    set_ang(ang);

    cout << "\nSeno(" << get_ang() << "): ";

    // *** CORRECCIÓN 2: Conversión correcta de Grados a Radianes ***
    // Argumento para sin(): grados * (PI / 180.0)
    // Se usa 180.0 para forzar la división de punto flotante.
    double radianes = get_ang() * PI / 180.0;

    cout << sin(radianes);
}

// Implementación de la función coseno::valor (¡Corregida!)
void coseno::valor(int ang) {
    // Establece el ángulo en la clase base
    set_ang(ang);

    cout << "\nCoseno(" << get_ang() << "): ";

    // *** CORRECCIÓN 2: Conversión correcta de Grados a Radianes ***
    // Argumento para cos(): grados * (PI / 180.0)
    double radianes = get_ang() * PI / 180.0;

    cout << cos(radianes);
}

int main() {
    // Herencia_Angulo_2.cpp
    seno alfa;    // objeto de la clase seno
    coseno beta; // objeto de la clase coseno

    alfa.valor(30); // Seno de 30 grados (Debe ser 0.5)
    cout << endl;

    beta.valor(45); // Coseno de 45 grados (Debe ser ~0.707)
    cout << endl << endl;

    return 0;
}