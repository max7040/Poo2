#include <iostream>
#include <cmath> // para M_PI

using namespace std;

// Mostrar uso de funciones set y get
class Circulo {
public:
    void setRadio(float a);     // asignar el radio
    float getRadio();           // recuperar el radio
    double area();              // calcular y devolver area
    double perimetro();         // calcular y devolver perimetro
    void print();               // funciones de utileria

private:
    float radio;
};

// usando el operador de resolucion o ambito ::
void Circulo::setRadio(float a) { // asignar el radio
    radio = a;
}

float Circulo::getRadio() { // recuperar el radio
    return radio;
}

double Circulo::area() {
    return M_PI * radio * radio;
}

double Circulo::perimetro() {
    return 2 * M_PI * radio;
}

void Circulo::print() {
    cout << "El area es: " << area() << endl;
    cout << "El perimetro es: " << perimetro() << endl;
}

// programa principal
int main() { // Clase_Circulo_1.cpp
    float r;
    Circulo cir;
    cout << "\nIngrese radio: ";
    cin >> r;

    // llamando a setRadio()
    cir.setRadio(r);

    cout << "\nRadio = " << cir.getRadio() << endl;
    cir.print();

    cout << endl;
    return 0;
}