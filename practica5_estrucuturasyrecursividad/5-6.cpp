#include <iostream>
#include <stdio.h> // para gets
using namespace std;

struct fecha {
    int dia, mes, year;
};

struct persona {
    char nombre[40];
    short edad;
    fecha fnac; // este campo es a su vez una estructura
    char direccion[45];
    char ocupacion[20];
};

void leerPersona(persona &p); // Paso por referencia
void imprimePersona(persona p);

int main() {
    struct persona p1;
    leerPersona(p1);
    imprimePersona(p1);
    return 0;
}

void leerPersona(persona &p) {
    cout << "\nLectura de datos de la persona" << endl;
    cout << "Ingresar nombre: "; fflush(stdin); gets(p.nombre);
    cout << "Ingresar la edad: "; cin >> p.edad;
    cout << "Ingresar fecha de nacimiento: "; fflush(stdin);
    cin >> p.fnac.dia >> p.fnac.mes >> p.fnac.year;
    cout << "Ingresar direccion: "; fflush(stdin); gets(p.direccion);
    cout << "Ingresar ocupacion: "; fflush(stdin); gets(p.ocupacion);
}

void imprimePersona(persona p) {
    cout << "\nDatos de la persona" << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Edad: " << p.edad << endl;
    cout << "Fecha de nacimiento: " << p.fnac.dia << "/" << p.fnac.mes << "/" << p.fnac.year << endl;
    cout << "Direccion: "; puts(p.direccion);
    cout << "Ocupacion: "; puts(p.ocupacion);
}