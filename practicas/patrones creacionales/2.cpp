#include <iostream>
#include <memory>
using namespace std;

// Clase base
class Transporte {
public:
    virtual void mover() = 0;
    virtual ~Transporte() {}
};

// Clases concretas
class Auto : public Transporte {
public:
    void mover() override {
        cout << "Conduciendo un auto 🚗" << endl;
    }
};

class Bicicleta : public Transporte {
public:
    void mover() override {
        cout << "Pedaleando una bicicleta 🚲" << endl;
    }
};

class Avion : public Transporte {
public:
    void mover() override {
        cout << "Volando un avión ✈️" << endl;
    }
};

// Fábrica
class TransporteFactory {
public:
    static unique_ptr<Transporte> crearTransporte(const string& tipo) {
        if (tipo == "auto") return make_unique<Auto>();
        else if (tipo == "bicicleta") return make_unique<Bicicleta>();
        else if (tipo == "avion") return make_unique<Avion>();
        else return nullptr;
    }
};

// Prueba
int main() {
    auto transporte1 = TransporteFactory::crearTransporte("auto");
    auto transporte2 = TransporteFactory::crearTransporte("bicicleta");
    auto transporte3 = TransporteFactory::crearTransporte("avion");

    transporte1->mover();
    transporte2->mover();
    transporte3->mover();

    return 0;
}
