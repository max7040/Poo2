#include <iostream>

using namespace std;

class Complejo {
    float real;
    float imag;
public:
    Complejo() {} // constructor
    Complejo(float, float); // constructor
    void print();
    friend Complejo operator+(const Complejo &, const Complejo &);
    ~Complejo(); // destructor
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

Complejo operator+(const Complejo &x, const Complejo &y)
{
    return Complejo(x.real + y.real, x.imag + y.imag);
}

Complejo::~Complejo()
{
    // El destructor está vacío aquí, lo que indica que no hay recursos dinámicos que liberar manualmente.
    // Para fines de depuración o demostración, podrías añadir un cout aquí.
}

int main()
{
    Complejo x(1.0, 3.0), y(2.0, 1.0);
    Complejo z;

    cout << "Sobrecarga de Operadores con friend" << endl;
    cout << "\nComplejo 1: ";
    x.print();
    cout << "\nComplejo 2: ";
    y.print();

    z = x + y; //llamando a la sobrecargo para +

    cout << "\nSuma: ";
    z.print();
    cout << endl;

    // Las llamadas explícitas a destructores no son comunes ni recomendables
    // en C++ a menos que se maneje memoria directamente (ej. con new/delete)
    // y para objetos asignados dinámicamente. Para objetos en el stack como x,y,z,
    // los destructores se llaman automáticamente al salir del scope.
    // ~x.Complejo();
    // ~y.Complejo();
    // ~z.Complejo();

    return 0;
}