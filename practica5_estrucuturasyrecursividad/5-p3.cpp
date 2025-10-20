#include <iostream>
#include <string.h>
#include <stdio.h> // Para fflush

using namespace std;

struct Alumno {
    char CodigoMat[10];
    char Nombre[40];
    float Nota1, Nota2, Nota3;
};

// Funciones definidas por el usuario

void leerAlumno(Alumno &a) {
    cout << "\nCodigo de Matricula: "; cin >> a.CodigoMat;
    cout << "Nombre: "; fflush(stdin); cin.getline(a.Nombre, 40);
    cout << "Nota 1: "; cin >> a.Nota1;
    cout << "Nota 2: "; cin >> a.Nota2;
    cout << "Nota 3: "; cin >> a.Nota3;
}

float calcularPromedio(Alumno a) {
    return (a.Nota1 + a.Nota2 + a.Nota3) / 3.0;
}

void imprimirAlumno(Alumno a) {
    cout << "\n--- Alumno: " << a.CodigoMat << " ---" << endl;
    cout << "Nombre: " << a.Nombre << endl;
    cout << "Notas: " << a.Nota1 << ", " << a.Nota2 << ", " << a.Nota3 << endl;
    cout << "Promedio: " << calcularPromedio(a) << endl;
}

void leerGrupo(Alumno grupo[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Ingrese datos del Alumno " << i + 1 << " ---" << endl;
        leerAlumno(grupo[i]);
    }
}

void imprimirGrupo(Alumno grupo[], int n) {
    for (int i = 0; i < n; i++) {
        imprimirAlumno(grupo[i]);
    }
}

int main() {
    int N;
    cout << "Ingrese la cantidad de alumnos: ";
    cin >> N;

    Alumno grupo[N]; // Array de estructuras

    leerGrupo(grupo, N);
    imprimirGrupo(grupo, N);

    return 0;
}