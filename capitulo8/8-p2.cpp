#include "Complex_Amiga.h"

// ------------------------------------
// Sobrecarga como Funciones Amigas
// ------------------------------------

// Resta: (a + bi) - (c + di) = (a - c) + (b - d)i
Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

// Producto: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
Complex operator*(const Complex& c1, const Complex& c2) {
    double r = (c1.real * c2.real) - (c1.imag * c2.imag);
    double i = (c1.real * c2.imag) + (c1.imag * c2.real);
    return Complex(r, i);
}

// División: (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c^2 + d^2)
Complex operator/(const Complex& c1, const Complex& c2) {
    double divisor = c2.real * c2.real + c2.imag * c2.imag;

    if (divisor == 0.0) {
        cerr << "Error: Division por cero complejo!" << endl;
        return Complex(0.0, 0.0);
    }

    double r = (c1.real * c2.real + c1.imag * c2.imag) / divisor;
    double i = (c1.imag * c2.real - c1.real * c2.imag) / divisor;

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

    cout << "--- Sobrecarga Amiga ---" << endl;

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