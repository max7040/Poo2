/* 
  Objetivo: Introduccion a la POO
  En una class los miembros se distinguen entre privados, públicos y/o protegidos,
  es decir: public, private y protected
*/

#include <iostream>
#include <string.h>
using namespace std;

class persona {
private:    // datos miembros
    char nombre[40];
    short edad;

public:     // funciones miembros
    void setDatos(char nom[], short e) {
        strcpy(nombre, nom);
        edad = e;
    }

    void getDatos() {
        cout << "\nNombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

int main() {   // Clase_Persona_2.cpp
    char nom[40];
    short ed;

    cout << "\nIngrese nombre: ";
    cin.getline(nom, 40);

    cout << "Ingrese la edad: ";
    cin >> ed;

    persona per;          // objeto del tipo persona
    per.setDatos(nom, ed);
    per.getDatos();

    cout << endl;
    return 0;
}
