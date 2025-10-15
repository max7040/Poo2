/* 
 Objetivo: Introduccion a la POO
 En una struct todos los miembros son publicos.
*/

#include <iostream>
#include <string.h>
using namespace std;

struct persona {
    // datos miembros
    char nombre[40];
    short edad;

    // funciones miembros
    void setDatos(char nom[], short e) {
        strcpy(nombre, nom);
        edad = e;
    }

    void getDatos() {
        cout << "\nNombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

int main() {
    char nom[40];
    short ed;

    cout << "\nIngrese nombre: ";
    cin.getline(nom, 40);

    cout << "Ingrese la edad: ";
    cin >> ed;

    persona per;  // variable del tipo persona
    per.setDatos(nom, ed);
    per.getDatos();

    cout << endl;
    return 0;
}
