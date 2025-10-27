 #include <iostream>
#include <vector>
#include <string>
using namespace std;

// Clase base
class Elemento {
public:
    virtual void mostrar(int nivel = 0) = 0;
    virtual ~Elemento() {}
};

// Clase Archivo (objeto simple)
class Archivo : public Elemento {
    string nombre;
public:
    Archivo(string n) : nombre(n) {}
    void mostrar(int nivel = 0) override {
        cout << string(nivel, '-') << "Archivo: " << nombre << endl;
    }
};

// Clase Carpeta (objeto compuesto)
class Carpeta : public Elemento {
    string nombre;
    vector<Elemento*> elementos;
public:
    Carpeta(string n) : nombre(n) {}
    void add(Elemento* e) { elementos.push_back(e); }
    void mostrar(int nivel = 0) override {
        cout << string(nivel, '=') << "Carpeta: " << nombre << endl;
        for (auto e : elementos)
            e->mostrar(nivel + 3);
    }
    ~Carpeta() {
        for (auto e : elementos)
            delete e;
    }
};

int main() {
    Carpeta* raiz = new Carpeta("Proyectos");
    Carpeta* carpeta1 = new Carpeta("C++");
    Carpeta* carpeta2 = new Carpeta("Python");

    carpeta1->add(new Archivo("main.cpp"));
    carpeta1->add(new Archivo("adapter.cpp"));
    carpeta2->add(new Archivo("decorator.py"));

    raiz->add(carpeta1);
    raiz->add(carpeta2);
    raiz->mostrar();

    delete raiz;
    return 0;
}
