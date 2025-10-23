 #include <iostream>
#include <functional>
using namespace std;

// Decorador: añade validación antes de ejecutar la función
function<double(double, double)> validarDivision(function<double(double, double)> func) {
    return [func](double a, double b) {
        if (b == 0) {
            cout << "Error: No se puede dividir entre cero.\n";
            return 0.0;
        }
        return func(a, b);
    };
}

// Función base
double dividir(double a, double b) {
    return a / b;
}

int main() {
    auto divisionSegura = validarDivision(dividir);
    cout << "Resultado 1: " << divisionSegura(10, 2) << endl;
    cout << "Resultado 2: " << divisionSegura(10, 0) << endl;
    return 0;
}
