/*
 * Objetivo: Iniciar la introduccion a la POO
 * Utilizando el operador de resolucion o ambito :: para escribir el codigo de
 * las funciones miembros fuera de la clase.
 */

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class persona{
private:     // datos miembros
    char nombre[40];
    short edad;
public:      // funciones miembros
    void setDatos();
    void getDatos();
};

void persona :: setDatos(){
    cout << "\nIngrese nombre: ";
   gets(nombre); //cin.getline(nombre,40);
    cout << "Ingrese la edad: ";
    cin >> edad;
}

void persona :: getDatos(){
    cout<<"\nNombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
}

int main(){  // Clase_Persona_3.cpp
    persona per;  // objeto del tipo persona
    per.setDatos();
    per.getDatos();
    cout<<endl;
    return 0;
}