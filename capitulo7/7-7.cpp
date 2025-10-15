#include <iostream>
#include <cmath> // Necesario para funciones matemáticas como fabs, sqrt, pow

using namespace std;

//Mostrar el uso de funciones virtuales con respecto a la clase base
//observe que area es una funcion virtual
class Base {
public:
    // Funcion virtual pura. Hace a Base una clase abstracta.
    // Obliga a las clases derivadas a implementar su propia version de area().
    virtual void area() = 0;
};

class Derivada1 : public Base {
public:
    void area(); // Implementa area para el calculo del area de un triangulo
};

void Derivada1::area() {
    //puntos del triangulo
    float x1 = 2.0, x2 = 3.2, x3 = 2.8;
    float y1 = 1.5, y2 = 3.5, y3 = 0.5;

    // Formula del area de un triangulo dadas sus coordenadas (metodo de la lazada o shoelace)
    // Se divide entre 2.0 para asegurar la division de flotantes.
    float A = fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    cout << "\nEl area del triangulo es: " << A << endl;
}

class Derivada2 : public Base {
public:
    void area(); // Implementa area para el calculo del area de un rectangulo
};

void Derivada2::area() {
    //puntos del rectangulo
    float x1 = 0.0, y1 = 0.0; // Punto inferior izquierdo
    float x2 = 1.5, y2 = 0.0; // Punto inferior derecho
    float x3 = 1.5, y3 = 1.9; // Punto superior derecho
    float x4 = 0.0, y4 = 1.9; // Punto superior izquierdo

    float dist1, dist2;

    // Calcula la longitud del "largo" (distancia entre (x1,y1) y (x2,y2))
    dist1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); // largo
    // Calcula la longitud del "ancho" (distancia entre (x3,y3) y (x4,y4))
    // Nota: Aunque los puntos dados forman un rectángulo, la forma más sencilla
    // de calcular el área sería (x2-x1) * (y4-y1). Aquí se usa distancias entre puntos.
    dist2 = sqrt(pow(x3 - x4, 2) + pow(y3 - y4, 2)); // ancho

    float A = dist1 * dist2;
    cout << "El area del rectangulo es: " << A << endl;
}

class Derivada3 : public Base {
public:
    void area(); // Implementa area para el calculo del area de un poligono
};

void Derivada3::area() {
    int i;
    //puntos del poligono (un hexagono en este caso)
    float x[6], y[6];
    x[0] = 0.0; y[0] = 0.0; // P1
    x[1] = 3.0; y[1] = 0.0; // P2
    x[2] = 3.5; y[2] = 1.0; // P3
    x[3] = 3.0; y[3] = 2.0; // P4
    x[4] = 2.0; y[4] = 2.0; // P5
    x[5] = 0.0; y[5] = 1.0; // P6

    float A = 0.0;
    // Formula del area de un poligono (metodo de la lazada o shoelace)
    // Suma cruzada de coordenadas
    for (i = 0; i < 6; i++) {
        // (x[i] * y[i+1]) - (y[i] * x[i+1])
        // Para el ultimo punto, i+1 se refiere al primer punto (cierre del poligono)
        A += (x[i] * y[(i + 1) % 6]) - (y[i] * x[(i + 1) % 6]);
    }
    cout << "El area del poligono es: " << fabs(A / 2.0) << endl; //fabs para asegurar positivo
}

int main() // Herencia_Virtual.cpp
{
    Derivada1 deriv1;
    Derivada2 deriv2;
    Derivada3 deriv3;

    Base *ptr; // puntero a la clase base

    ptr = &deriv1; //asignar direccion de objeto Derivada1 al puntero de Base
    ptr->area(); //salida : area del triangulo (llama a Derivada1::area() por polimorfismo)

    ptr = &deriv2; //asignar direccion de objeto Derivada2 al puntero de Base
    ptr->area(); //salida : area del rectangulo (llama a Derivada2::area() por polimorfismo)

    ptr = &deriv3; //asignar direccion de objeto Derivada3 al puntero de Base
    ptr->area(); //salida : area del poligono (llama a Derivada3::area() por polimorfismo)

    cout << endl;
    return 0;
}