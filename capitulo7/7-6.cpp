#include <iostream>
#include <cmath> // para M_PI

using namespace std;

// Mostrar uso de constructores y destructores
class circulo {
public:
    circulo();              // constructor por defecto
    circulo(float a);       // constructor alternativo
    double area();          // calcula y devuelve el area
    double perimetro();     // calcula y devuelve el perimetro
    ~circulo();             // destructor

private:
    float radio;
};

// usando el operador de resolucion o ambito ::
circulo::circulo() {
    radio = 0;
}

circulo::circulo(float a) {
    radio = a;
}

double circulo::area() {
    return M_PI * radio * radio;
}

double circulo::perimetro() {
    return 2 * M_PI * radio;
}

circulo::~circulo() {
    cout << "\nObjeto destruyendose...!" << endl;
}

// programa principal
int main() {
    float r = 2.5;

    // Declarando el objeto cir y activando el constructor
    circulo cir(r);

    cout << "\nEl area es: " << cir.area() << endl;
    cout << "El perimetro es: " << cir.perimetro() << endl;

    // activando el destructor
    cir.~circulo();

    cout << endl;
    return 0;
}