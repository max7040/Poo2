#include <iostream>
#include <cmath>
using namespace std;

struct complejo {
    float real;
    float imag;
};

complejo suma(complejo x, complejo y) {
    return {x.real + y.real, x.imag + y.imag};
}

complejo resta(complejo x, complejo y) {
    return {x.real - y.real, x.imag - y.imag};
}

complejo producto(complejo x, complejo y) {
    float r = x.real * y.real - x.imag * y.imag;
    float i = x.real * y.imag + x.imag * y.real;
    return {r, i};
}

complejo division(complejo x, complejo y) {
    float denominador = y.real * y.real + y.imag * y.imag;
    if (denominador == 0) {
        cout << "Error: Division por cero!" << endl;
        return {0.0, 0.0};
    }
    float r = (x.real * y.real + x.imag * y.imag) / denominador;
    float i = (x.imag * y.real - x.real * y.imag) / denominador;
    return {r, i};
}

float modulo(complejo x) {
    return sqrt(x.real * x.real + x.imag * x.imag);
}

void imprimir(complejo z) {
    cout << z.real << (z.imag >= 0 ? " + " : " - ") << abs(z.imag) << "i";
}

int main() {
    complejo a = {3, 2}; // 3 + 2i
    complejo b = {1, 4}; // 1 + 4i
    complejo z;

    z = suma(a, b);
    cout << "Suma: "; imprimir(a); cout << " + "; imprimir(b); cout << " = "; imprimir(z); cout << endl;

    z = resta(a, b);
    cout << "Resta: "; imprimir(a); cout << " - "; imprimir(b); cout << " = "; imprimir(z); cout << endl;

    z = producto(a, b);
    cout << "Producto: "; imprimir(a); cout << " * "; imprimir(b); cout << " = "; imprimir(z); cout << endl;

    z = division(a, b);
    cout << "Division: "; imprimir(a); cout << " / "; imprimir(b); cout << " = "; imprimir(z); cout << endl;

    cout << "Modulo de a: " << modulo(a) << endl;

    return 0;
}