#include <iostream>
#include <string.h>
#include <limits> // Para numeric_limits
using namespace std;

const int N = 50;

struct alumno {
    char codigo[10];
    char nombre[40];
    char curso[30];
    int notas[4]; // Array de 4 notas
};

// Prototipos
float obtenerPromedioAjustado(const alumno &a);
void mayorPromedio(alumno a[], int n);
void buscaAlumno(alumno a[], int n, char cod[]);
void imprimirDatosAlumno(const alumno &a, float promedio);

// Función auxiliar para obtener el promedio eliminando la nota más baja
float obtenerPromedioAjustado(const alumno &a) {
    if (a.notas[0] == 0 && a.notas[1] == 0 && a.notas[2] == 0 && a.notas[3] == 0) return 0.0;

    int minNota = a.notas[0];
    int suma = 0;

    // Encontrar la nota mínima
    for (int i = 0; i < 4; i++) {
        if (a.notas[i] < minNota) {
            minNota = a.notas[i];
        }
        suma += a.notas[i];
    }
    
    // Suma total menos la nota más baja, dividido por 3
    return (float)(suma - minNota) / 3.0;
}

void imprimirDatosAlumno(const alumno &a, float promedio) {
    cout << "\n--- Datos del Alumno ---" << endl;
    cout << "Codigo: " << a.codigo << endl;
    cout << "Nombre: " << a.nombre << endl;
    cout << "Curso: " << a.curso << endl;
    cout << "Promedio (ajustado): " << promedio << endl;
}

// Función para encontrar e imprimir el alumno con el mayor promedio
void mayorPromedio(alumno a[], int n) {
    if (n == 0) {
        cout << "\nNo hay alumnos registrados." << endl;
        return;
    }
    
    int indiceMayor = 0;
    float maxPromedio = obtenerPromedioAjustado(a[0]);

    for (int i = 1; i < n; i++) {
        float promedioActual = obtenerPromedioAjustado(a[i]);
        if (promedioActual > maxPromedio) {
            maxPromedio = promedioActual;
            indiceMayor = i;
        }
    }
    
    cout << "\n--- Alumno con el Mayor Promedio (" << maxPromedio << ") ---" << endl;
    imprimirDatosAlumno(a[indiceMayor], maxPromedio);
}

// Función para buscar un alumno por código
void buscaAlumno(alumno a[], int n, char cod[]) {
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].codigo, cod) == 0) {
            float promedio = obtenerPromedioAjustado(a[i]);
            imprimirDatosAlumno(a[i], promedio);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "\nError: Alumno con codigo " << cod << " no existe." << endl;
    }
}

int main() {
    // Simulacion de datos
    alumno grupo[] = {
        {"A001", "Ana Gomez", "Calculo", {15, 18, 10, 19}}, // Promedio (sin 10): 17.33
        {"A002", "Luis Perez", "Fisica", {12, 11, 14, 13}}, // Promedio (sin 11): 13.0
        {"A003", "Eva Diaz", "Programacion", {19, 20, 18, 17}} // Promedio (sin 17): 19.0 (Mayor)
    };
    int numAlumnos = 3;
    char codigoBuscar[] = "A001";

    // Encontrar el alumno con mayor promedio
    mayorPromedio(grupo, numAlumnos);

    // Buscar un alumno
    cout << "\n--- Busqueda por Codigo (" << codigoBuscar << ") ---";
    buscaAlumno(grupo, numAlumnos, codigoBuscar);

    return 0;
}