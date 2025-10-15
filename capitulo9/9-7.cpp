#include <iostream>
#include <cmath> // Para sqrt, pow, y fabs
using namespace std;

// Clase Base: Define la interfaz polimórfica
class Base {
public:
    // Función virtual pura (convierte a Base en una clase abstracta)
    virtual void area() = 0;
};

// --- Clase Derivada 1: Área de un Triángulo (Fórmula del área de coordenadas) ---
class Derivada1 : public Base {
public:
    void area(); // Sobreescritura
};

void Derivada1::area() {
    // Puntos del triángulo
    float x1 = 2.0, x2 = 3.2, x3 = 2.8;
    float y1 = 1.5, y2 = 3.5, y3 = 0.5;

    // Fórmula del área de coordenadas de un triángulo
    float A = fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0f);
    cout << "\nEl Area del triangulo es: " << A << endl;
}

// --- Clase Derivada 2: Área de un Rectángulo (Cálculo por distancias) ---
class Derivada2 : public Base {
public:
    void area(); // Sobreescritura
};

void Derivada2::area() {
    // Puntos del rectángulo: P1(0,0), P2(1.5, 0), P3(1.5, 1.9), P4(0, 1.9)
    float x1 = 0.0, x2 = 1.5, x3 = 1.5, x4 = 0;
    float y1 = 0.0, y2 = 0.0, y3 = 1.9, y4 = 1.9;
    
    // Calcula la longitud (distancia entre P1 y P2)
    float dist1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // 1.5
    // Calcula la altura/ancho (distancia entre P4 y P1, o P3 y P2)
    float dist2 = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2)); // 1.9

    float A = dist1 * dist2;
    cout << "El area del rectangulo es: " << A << endl; // Área: 1.5 * 1.9 = 2.85
}

// --- Clase Derivada 3: Área de un Polígono (Fórmula del Cordón de Zapato) ---
class Derivada3 : public Base {
public:
    void area(); // Sobreescritura
};

void Derivada3::area() {
    // Define el polígono de 6 lados (n=6). Los arrays deben ser de tamaño [6].
    // Los puntos son: (0,0), (3,0), (3.5, 2), (3, 3), (2, 4), (0, 3)
    int n = 6;
    float x[6] = {0.0f, 3.0f, 3.5f, 3.0f, 2.0f, 0.0f};
    float y[6] = {0.0f, 0.0f, 2.0f, 3.0f, 4.0f, 3.0f};

    float A = 0.0f;
    
    // *** CORRECCIÓN 3: Fórmula del Cordón de Zapato (Shoelace Formula) ***
    // El bucle va hasta el penúltimo punto (i < n-1 o i < 5).
    for (int i = 0; i < n; i++) {
        // Usa módulo para i+1: (i+1) % n. Esto conecta el último punto (i=5) con el primero (0).
        int next = (i + 1) % n; 
        A += x[i] * y[next] - y[i] * x[next];
    }
    
    // El área es el valor absoluto de la mitad de la suma
    A = fabs(A / 2.0f);
    
    cout << "El area del poligono es: " << A << endl; 
}

// --- Función Principal (Main) ---
int main() {
    // Herencia_Virtual.cpp
    
    Derivada1 deriv1;
    Derivada2 deriv2;
    Derivada3 deriv3;
    
    // Puntero a la clase base (polimorfismo)
    Base *ptr; 
    
    // 1. Triángulo
    ptr = &deriv1; // Asignar dirección de Derivada1
    cout << "\nPolimorfismo con Base -> Derivada1 (Triángulo):" << endl;
    ptr->area();   // Llama a Derivada1::area()
    
    // 2. Rectángulo
    ptr = &deriv2; // Asignar dirección de Derivada2
    cout << "Polimorfismo con Base -> Derivada2 (Rectángulo):" << endl;
    ptr->area();   // Llama a Derivada2::area()
    
    // 3. Polígono
    ptr = &deriv3; // Asignar dirección de Derivada3
    cout << "Polimorfismo con Base -> Derivada3 (Polígono):" << endl;
    ptr->area();   // Llama a Derivada3::area()
    
    return 0;
}