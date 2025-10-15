#include <iostream>
#include <cmath> // Para la función sin()

// Definición de PI ya que M_PI no siempre está disponible
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

// clase derivada
class seno : public angulo {
public:
    // La declaración de la función miembro valor
    void valor(int ang);
};

// Implementación de la función miembro valor (¡Corregida!)
void seno::valor(int ang) {
    // Establece el ángulo en la clase base
    set_ang(ang);

    // Muestra el ángulo actual
    cout << "\nSeno(" << get_ang() << "): ";

    // *** CORRECCIÓN CRUCIAL: Conversión de Grados a Radianes ***
    // El argumento de sin() DEBE ser el ángulo en radianes.
    // Fórmula: radianes = grados * (PI / 180)
    // Se usa 180.0 para forzar la división de punto flotante.
    double radianes = get_ang() * PI / 180.0;
    
    // Imprime el valor del seno
    cout << sin(radianes);
}

int main() {
    // Herencia_Angulo_1.cpp
    seno x; // objeto de la clase seno
    
    // Calcula y muestra el seno de 90 grados
    x.valor(90); // ángulo de 90 grados (Seno de 90 grados = 1.0)
    
    // Prueba con otro ángulo: 30 grados (Seno de 30 grados = 0.5)
    x.valor(30); 
    
    cout << endl << endl;
    return 0;
}