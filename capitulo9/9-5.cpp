#include <iostream>
#include <cmath> // Para sqrt y pow

using namespace std;

// --- Clase Base: Punto (2D) ---
class Punto {
public:
    Punto() {}
    Punto(int, int);
    ~Punto() {}
    
    void setx(int a) { x = a; }
    void sety(int b) { y = b; }
    
    int getx() const { return x; }
    int gety() const { return y; }
    
    // Declaración de la función amiga para la distancia 2D
    friend double distancia(Punto, Punto);

protected:
    int x;
    int y;
};

// Implementación del constructor de Punto
Punto :: Punto(int a, int b) {
    x = a;
    y = b;
}

// Implementación de la distancia 2D
double distancia(Punto p1, Punto p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// --- Clase Derivada: Punto3D (3D) ---
class Punto3D: public Punto {
private:
    int z;
public:
    Punto3D() {}
    Punto3D(int x0, int y0, int z0) : Punto(x0, y0) { z = z0; } // Llama al constructor base
    ~Punto3D() {}

    void setz(int z0) { z = z0; }
    int getz() const { return z; }

    // *** CORRECCIÓN CRUCIAL: Declaración de la función amiga para la distancia 3D ***
    // Esto permite que la función distancia(Punto3D, Punto3D) acceda a los miembros privados de Punto3D.
    friend double distancia(Punto3D, Punto3D);
};

// Implementación de la distancia 3D
double distancia(Punto3D p1, Punto3D p2) {
    // La fórmula de la distancia 3D
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

// --- Función Principal ---
int main() {
    // Herencia_Punto_1.cpp
    
    // 1. Cálculo de Distancia 2D
    Punto p1(1, 1), p2(2, 2);
    double dis = distancia(p1, p2); // Llama a distancia(Punto, Punto)
    
    cout << "\nHerencia con la Clase Punto:" << endl;
    cout << "\n*** Punto 2D ***" << endl;
    cout << "\nCoordenadas de P1 (" << p1.getx() << ", " << p1.gety() << ")" << endl;
    cout << "Coordenadas de P2 (" << p2.getx() << ", " << p2.gety() << ")" << endl;
    cout << "Distancia entre p1 y p2: " << dis << endl;
    
    // 2. Cálculo de Distancia 3D
    Punto3D p3(2, 1, 3), p4(0, 0, 0);
    dis = distancia(p3, p4); // Llama a distancia(Punto3D, Punto3D)
    
    cout << "\n*** Punto 3D ***" << endl;
    cout << "Coordenadas de P3 (" << p3.getx() << ", " << p3.gety() << ", " << p3.getz() << ")" << endl;
    cout << "Coordenadas de P4 (" << p4.getx() << ", " << p4.gety() << ", " << p4.getz() << ")" << endl;
    cout << "Distancia entre p3 y p4: " << dis << endl;
    
    return 0;
}