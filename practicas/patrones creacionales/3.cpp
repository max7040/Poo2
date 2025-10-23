#include <iostream>
#include <string>
using namespace std;

// Producto final
class Combo {
public:
    string hamburguesa;
    string bebida;
    string papas;

    void mostrar() {
        cout << "Combo: " << hamburguesa << ", " << bebida << ", " << papas << endl;
    }
};

// Builder
class ComboBuilder {
private:
    Combo combo;
public:
    ComboBuilder& agregarHamburguesa(const string& tipo) {
        combo.hamburguesa = tipo;
        return *this;
    }

    ComboBuilder& agregarBebida(const string& bebida) {
        combo.bebida = bebida;
        return *this;
    }

    ComboBuilder& agregarPapas(const string& tipo) {
        combo.papas = tipo;
        return *this;
    }

    Combo obtenerCombo() {
        return combo;
    }
};

// Prueba
int main() {
    ComboBuilder builder;
    Combo combo1 = builder.agregarHamburguesa("Doble carne 🍔")
                           .agregarBebida("Coca-Cola 🥤")
                           .agregarPapas("Grandes 🍟")
                           .obtenerCombo();

    combo1.mostrar();
    return 0;
}
