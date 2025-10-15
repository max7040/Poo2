#include <iostream> // Para entrada/salida como cout, ostream

using namespace std;

class Complejo {
private: 
    float real;
    float imag;

public:
    // Constructores
    Complejo() {} // Constructor por defecto
    Complejo(float, float); // Constructor parametrizado

    // Declaración de funciones amigas para sobrecarga de operadores
    // Operador binario +
    friend Complejo operator+(const Complejo&, const Complejo&);
    // Operador binario -
    friend Complejo operator-(const Complejo&, const Complejo&);
    // Operador unario para el conjugado (aquí se usa como '!')
    friend Complejo operator!(const Complejo&);
    // Operador unario para el opuesto (aquí se usa como '-')
    friend Complejo operator-(const Complejo&);

    // Sobrecarga del operador de extracción de flujo << (para imprimir)
    friend ostream& operator<<(ostream&, const Complejo&);

    // Un método 'print' alternativo, aunque se prefiere 'operator<<'
    void print();
};

// Definición del constructor parametrizado
Complejo::Complejo(float a, float b)
{
    real = a;
    imag = b;
}

// Definición de un método print (ahora usa 'this' para llamar al operador<<)
void Complejo::print()
{
    cout << *this << endl; // Imprime el objeto actual usando el operador << sobrecargado
}


// Implementación de la función amiga para la suma (operador binario +)
// (x + y)
Complejo operator+(const Complejo &x, const Complejo &y)
{
    return Complejo(x.real + y.real, x.imag + y.imag);
}

// Implementación de la función amiga para la resta (operador binario -)
// (x - y)
Complejo operator-(const Complejo &x, const Complejo &y)
{
    return Complejo(x.real - y.real, x.imag - y.imag);
}

// Implementación de la función amiga para el conjugado (operador unario !)
// !x (conjuga el complejo x)
Complejo operator!(const Complejo &x)
{
    // El conjugado de (a + bi) es (a - bi)
    return Complejo(x.real, -x.imag);
}

// Implementación de la función amiga para el opuesto (operador unario -)
// -x (niega el complejo x)
Complejo operator-(const Complejo &x)
{
    // El opuesto de (a + bi) es (-a - bi)
    return Complejo(-x.real, -x.imag);
}


// Implementación de la función amiga para el operador de inserción de flujo <<
// Permite imprimir objetos Complejo directamente con 'cout << complejo_obj;'
ostream& operator<<(ostream& os, const Complejo& p)
{
    os << p.real; // Imprime la parte real
    if (p.imag >= 0) {
        os << " + "; // Si la parte imaginaria es positiva o cero, añade "+"
    } else {
        os << " - "; // Si es negativa, añade "-" (el signo ya estará en p.imag)
    }
    os << abs(p.imag) << "i"; // Imprime el valor absoluto de la parte imaginaria y la 'i'
    return os; // Devuelve el ostream para permitir encadenamiento (cout << c1 << c2;)
}


int main()
{
    Complejo x(4.0, 3.0); // x = 4 + 3i
    Complejo y(2.0, -1.0); // y = 2 - 1i
    Complejo z, w, t;       // Objetos para almacenar resultados

    cout << "Aplicando la suma con +" << endl;
    cout << "Sumando dos complejos:" << endl;
    x.print(); // Muestra el valor de x (usa el operador <<)
    cout << " + " << endl;
    y.print(); // Muestra el valor de y
    z = x + y; // Llama al operador binario +
    cout << " = " << endl;
    z.print(); // Muestra el resultado de la suma
    cout << endl;

    cout << "Aplicando la resta con -" << endl;
    cout << "Restando dos complejos:" << endl;
    x.print(); // Muestra el valor de x
    cout << " - " << endl;
    y.print(); // Muestra el valor de y
    z = x - y; // Llama al operador binario -
    cout << " = " << endl;
    z.print(); // Muestra el resultado de la resta
    cout << endl;

    cout << "Usando operador - unario para el opuesto del complejo 1:" << endl;
    t = -x; // Llama al operador unario - (opuesto)
    t.print(); // Muestra el complejo negado (-4 - 3i)
    cout << endl;

    cout << "\nUsando operador ! unario para el conjugado del complejo 1:" << endl;
    t = !y; // Llama al operador unario ! (conjugado)
    t.print(); // Muestra el complejo conjugado de y (2 + 1i)
    cout << endl;

    return 0;
}