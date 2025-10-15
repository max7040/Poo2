#include <iostream>

using namespace std;

class Complejo {
public:
    // Constructores
    Complejo() {}
    Complejo(float real_val, float imag_val);

    // Método para imprimir el complejo
    void print();

    // Sobrecarga del operador binario +
    Complejo operator+(const Complejo &otro);

    // Sobrecarga del operador binario -
    Complejo operator-(const Complejo &otro);

    // Sobrecarga del operador unario -
    Complejo operator-();

private:
    float real;
    float imag;
};

// Definición del constructor parametrizado
Complejo::Complejo(float real_val, float imag_val)
{
    real = real_val;
    imag = imag_val;
}

// Definición del método print
void Complejo::print()
{
    cout << real << " + " << imag << "i" << endl;
}

// Definición del operador binario +
// (this) + otro
Complejo Complejo::operator+(const Complejo &otro)
{
    // Suma las partes reales y las partes imaginarias
    return Complejo(real + otro.real, imag + otro.imag);
}

// Definición del operador binario -
// (this) - otro
Complejo Complejo::operator-(const Complejo &otro)
{
    // Resta las partes reales y las partes imaginarias
    return Complejo(real - otro.real, imag - otro.imag);
}

// Definición del operador unario -
// -(this)
Complejo Complejo::operator-()
{
    // Niega tanto la parte real como la imaginaria
    return Complejo(real, -imag);
}

int main()
{
    // Crear objetos Complejo
    Complejo x(3.0, 1.0); // x = 3 + 1i
    Complejo y(2.0, 4.0); // y = 2 + 4i
    Complejo z, t;       // Objetos para almacenar resultados

    cout << "Aplicando la suma con +" << endl;
    cout << "Sumando dos complejos:" << endl;
    x.print(); // Muestra el valor de x
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

    cout << "Usando el - unario" << endl;
    cout << "Usando operador - unario para el primer complejo:" << endl;
    t = -x; // Llama al operador unario -
    // o puedes escribir t = x.operator-(); pero -x es más natural
    t.print(); // Muestra el complejo negado
    cout << endl;

    return 0; // El programa finaliza con éxito
}