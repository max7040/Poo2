#include <iostream>

using namespace std;

class Complejo {
public:
    Complejo() {}
    Complejo(float a, float b);
    void print();

    friend Complejo operator+(Complejo x, Complejo y);

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

Complejo operator+(Complejo x, Complejo y)
{
    Complejo z;
    z.real = x.real + y.real;
    z.imag = x.imag + y.imag;
    return z;
}

int main()
{
    Complejo x(1.0, 3.0), y(2.0, 1.0);
    Complejo z;

    cout << "Sobrecarga de Operadores con friend" << endl;
    cout << "\nComplejo 1: ";
    x.print();
    cout << endl << "Complejo 2: ";
    y.print();

    z = x + y; // Uso del operador + sobrecargado

    cout << "\nSuma:\t";
    z.print();
    cout << endl;

    return 0;
}