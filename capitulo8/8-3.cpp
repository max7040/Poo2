#include <iostream>

using namespace std;

class Complejo {
public:
    Complejo() {} // constructor
    Complejo(float, float); // constructor
    void print();
    //funcion operadora miembro
    Complejo operator+(const Complejo &);

private:
    float real;
    float imag;
};

Complejo::Complejo(float a, float b)
{
    real = a;
    imag = b;
}

void Complejo::print()
{
    cout << real << " + " << imag << "i" << endl;
}

// Definición de la función operadora miembro
Complejo Complejo::operator+(const Complejo &y)
{
    // 'this->real' y 'this->imag' se refieren al objeto actual (el operando izquierdo)
    // 'y.real' y 'y.imag' se refieren al objeto pasado como argumento (el operando derecho)
    return Complejo(real + y.real, imag + y.imag);
}

int main()
{
    Complejo x(1.0, 3.0), y(2.0, 1.0);
    Complejo z;

    cout << "Sobrecarga de Operadores con funciones operadoras miembros" << endl;
    cout << "\nComplejo 1: ";
    x.print();
    cout << "\nComplejo 2: ";
    y.print();

    z = x + y; // Uso del operador + sobrecargado

    cout << "\nSuma:\t";
    z.print();
    cout << endl;

    return 0;
}