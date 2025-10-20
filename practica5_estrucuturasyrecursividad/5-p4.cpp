#include <iostream>
using namespace std;

// 1. Definicion de la estructura Fecha
struct Fecha {
    int dia;
    int mes;
    int year;
};

// 2. Función para determinar si un año es bisiesto
bool esBisiesto(int year) {
    // Un año es bisiesto si es divisible por 4,
    // excepto si es divisible por 100 pero no por 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 3. Función para validar si la fecha es correcta
bool validarFecha(Fecha f) {
    if (f.year < 1) return false; // El año debe ser positivo

    if (f.mes < 1 || f.mes > 12) return false; // Mes entre 1 y 12

    // Array con el número de días en cada mes (índice 0 no usado, Ene=1, Feb=2...)
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Ajustar los días de Febrero si el año es bisiesto
    if (f.mes == 2 && esBisiesto(f.year)) {
        diasPorMes[2] = 29;
    }

    // Verificar si el día está dentro del rango para ese mes
    if (f.dia < 1 || f.dia > diasPorMes[f.mes]) {
        return false;
    }

    return true; // La fecha es válida
}

int main() {
    Fecha fecha1, fecha2;

    // Primer objeto Fecha
    cout << "--- Ingrese la primera fecha (dd mm aaaa) ---" << endl;
    cin >> fecha1.dia >> fecha1.mes >> fecha1.year;
    
    if (validarFecha(fecha1)) {
        cout << "Fecha 1 (" << fecha1.dia << "/" << fecha1.mes << "/" << fecha1.year << ") es VALIDA." << endl;
    } else {
        cout << "Fecha 1 (" << fecha1.dia << "/" << fecha1.mes << "/" << fecha1.year << ") es INVALIDA." << endl;
    }

    // Segundo objeto Fecha (Ejemplo de año bisiesto)
    cout << "\n--- Ingrese la segunda fecha (dd mm aaaa) ---" << endl;
    cin >> fecha2.dia >> fecha2.mes >> fecha2.year;
    
    if (validarFecha(fecha2)) {
        cout << "Fecha 2 (" << fecha2.dia << "/" << fecha2.mes << "/" << fecha2.year << ") es VALIDA." << endl;
    } else {
        cout << "Fecha 2 (" << fecha2.dia << "/" << fecha2.mes << "/" << fecha2.year << ") es INVALIDA." << endl;
    }

    return 0;
}