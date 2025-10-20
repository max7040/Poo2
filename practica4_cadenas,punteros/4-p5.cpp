#include <iostream>
#include <stdio.h> // Para gets()

using namespace std;

int main()
{
    char nombre[40];
    char ap_paterno[40];
    char ap_materno[40];

    // Entrada de datos
    cout << "Ingrese su nombre: ";
    gets(nombre); // Nombre

    cout << "Ingrese su apellido paterno: ";
    gets(ap_paterno); // Apellido paterno

    cout << "Ingrese su apellido materno: ";
    gets(ap_materno); // Apellido materno

    cout << "\n--- Datos Ingresados ---\n";
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido Paterno: " << ap_paterno << endl;
    cout << "Apellido Materno: " << ap_materno << endl;

    cout << "\n--- Orden Reportado ---\n";
    // Formato solicitado: Apellido paterno, apellido materno y nombre.
    cout << ap_paterno << ", " << ap_materno << " y " << nombre << endl;

    return 0;
}