#include <iostream>
#include <string.h>
using namespace std;

struct Alumno {
    char CodigoMat[10];
    char Nombre[40];
    float Nota1, Nota2, Nota3;
};

float calcularPromedio(Alumno a) {
    return (a.Nota1 + a.Nota2 + a.Nota3) / 3.0;
}

int main() {
    Alumno a;
    float promedio;

    // Lectura de datos
    cout << "Ingrese Codigo de Matricula: "; cin >> a.CodigoMat;
    cout << "Ingrese Nombre: "; fflush(stdin); cin.getline(a.Nombre, 40);
    cout << "Ingrese Nota 1: "; cin >> a.Nota1;
    cout << "Ingrese Nota 2: "; cin >> a.Nota2;
    cout << "Ingrese Nota 3: "; cin >> a.Nota3;

    promedio = calcularPromedio(a);

    // Impresión de datos
    cout << "\n--- Datos del Alumno ---" << endl;
    cout << "Codigo: " << a.CodigoMat << endl;
    cout << "Nombre: " << a.Nombre << endl;
    cout << "Notas: " << a.Nota1 << ", " << a.Nota2 << ", " << a.Nota3 << endl;
    cout << "Promedio: " << promedio << endl;

    return 0;
}