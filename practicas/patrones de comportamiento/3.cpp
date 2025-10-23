#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Receptor: el editor
class EditorTexto {
private:
    string contenido;
public:
    void escribir(const string& texto) {
        contenido += texto;
    }
    void mostrar() {
        cout << "Contenido actual: " << contenido << endl;
    }
    string getContenido() { return contenido; }
    void setContenido(const string& c) { contenido = c; }
};

// Interfaz de comando
class Comando {
public:
    virtual void ejecutar() = 0;
    virtual void deshacer() = 0;
};

// Comando concreto: Escribir
class ComandoEscribir : public Comando {
private:
    EditorTexto* editor;
    string textoAnterior;
    string nuevoTexto;
public:
    ComandoEscribir(EditorTexto* e, string txt) : editor(e), nuevoTexto(txt) {}
    void ejecutar() override {
        textoAnterior = editor->getContenido();
        editor->escribir(nuevoTexto);
    }
    void deshacer() override {
        editor->setContenido(textoAnterior);
    }
};

// Invocador
class Controlador {
private:
    stack<Comando*> historial;
public:
    void ejecutarComando(Comando* c) {
        c->ejecutar();
        historial.push(c);
    }
    void deshacer() {
        if (!historial.empty()) {
            historial.top()->deshacer();
            historial.pop();
        }
    }
};

int main() {
    EditorTexto editor;
    Controlador ctrl;

    ComandoEscribir c1(&editor, "Hola ");
    ComandoEscribir c2(&editor, "mundo!");

    ctrl.ejecutarComando(&c1);
    ctrl.ejecutarComando(&c2);
    editor.mostrar();

    cout << "Deshaciendo último comando...\n";
    ctrl.deshacer();
    editor.mostrar();
}
