#include "Complex_Miembro.h"

// ------------------------------------
// Sobrecarga como Funciones Miembro
// ------------------------------------

// Resta: (a + bi) - (c + di) = (a - c) + (b - d)i
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

// Producto: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
Complex Complex::operator*(const Complex& other) const {
    double r = (real * other.real) - (imag * other.imag);
    double i = (real * other.imag) + (imag * other.real);
    return Complex(r, i);
}

// División: (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c^2 + d^2)
Complex Complex::operator/(const Complex& other) const {
    double divisor = other.real * other.real + other.imag * other.imag;

    // Se asume que el divisor no es cero para simplificar el ejemplo.
    if (divisor == 0.0) {
        // En un código real, se manejaría un error o excepción.
        cerr << "Error: Division por cero complejo!" << endl;
        return Complex(0.0, 0.0);
    }

    double r = (real * other.real + imag * other.imag) / divisor;
    double i = (imag * other.real - real * other.imag) / divisor;

    return Complex(r, i);
}

// Función de impresión
void Complex::print() const {
    cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i";
}

// ------------------------------------
// Programa de Prueba (main)
// ------------------------------------

int main() {
    Complex a(5.0, 3.0); // 5 + 3i
    Complex b(2.0, -1.0); // 2 - 1i

    cout << "--- Sobrecarga Miembro ---" << endl;

    cout << "A = "; a.print(); cout << endl;
    cout << "B = "; b.print(); cout << endl;

    // Resta
    Complex resta = a - b;
    cout << "A - B = "; resta.print(); cout << " (Resultado: 3 + 4i)" << endl;

    // Producto
    Complex producto = a * b;
    cout << "A * B = "; producto.print(); cout << " (Resultado: 13 + 1i)" << endl;

    // División
    Complex division = a / b;
    cout << "A / B = "; division.print(); cout << " (Resultado: 1.4 + 2.2i)" << endl;

    return 0;
}