 #include <iostream>
#include <vector>
#include <string>
using namespace std;

// Interfaz del observador
class Usuario {
public:
    virtual void recibirMensaje(const string& mensaje) = 0;
};

// Clase concreta del observador
class UsuarioConcreto : public Usuario {
private:
    string nombre;
public:
    UsuarioConcreto(string n) : nombre(n) {}
    void recibirMensaje(const string& mensaje) override {
        cout << nombre << " recibió: " << mensaje << endl;
    }
};

// Clase sujeto (Chat)
class Chat {
private:
    vector<Usuario*> usuarios;
public:
    void registrar(Usuario* u) {
        usuarios.push_back(u);
    }
    void notificar(const string& mensaje) {
        for (auto u : usuarios)
            u->recibirMensaje(mensaje);
    }
};

int main() {
    Chat chat;
    UsuarioConcreto u1("nombre1"), u2("nombre2"), u3("nombre3");

    chat.registrar(&u1);
    chat.registrar(&u2);
    chat.registrar(&u3);

    chat.notificar("Nuevo mensaje en el chat grupal!");
}
