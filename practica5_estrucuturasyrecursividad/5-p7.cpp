#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct punto {
    float x;
    float y;
};

// Calcula la longitud del segmento (distancia)
float longitudSegmento(punto p1, punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Calcula la pendiente de la recta
float pendienteRecta(punto p1, punto p2) {
    if (p2.x == p1.x) {
        return NAN; // Pendiente indefinida (recta vertical)
    }
    return (p2.y - p1.y) / (p2.x - p1.x);
}

// Calcula el área del triángulo (Fórmula de Shoelace/Determinante)
float areaTriangulo(punto p1, punto p2, punto p3) {
    float area = 0.5 * abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)));
    return area;
}

int main() {
    punto p1 = {1.0, 1.0};
    punto p2 = {4.0, 5.0};
    punto p3 = {1.0, 5.0};

    cout << fixed << setprecision(2);
    cout << "\n--- Puntos ---" << endl;
    cout << "P1: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "P2: (" << p2.x << ", " << p2.y << ")" << endl;
    cout << "P3: (" << p3.x << ", " << p3.y << ")" << endl;
    
    // Longitud
    float longitud = longitudSegmento(p1, p2);
    cout << "\nLongitud del segmento P1-P2: " << longitud << endl;

    // Pendiente
    float pendiente = pendienteRecta(p1, p2);
    if (isnan(pendiente)) {
        cout << "Pendiente de P1-P2: Indefinida" << endl;
    } else {
        cout << "Pendiente de P1-P2: " << pendiente << endl;
    }

    // Área del Triángulo
    float area = areaTriangulo(p1, p2, p3);
    cout << "Area del triangulo P1-P2-P3: " << area << endl;

    return 0;
}