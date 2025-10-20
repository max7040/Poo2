#include <iostream>
#include <string.h>
using namespace std;

// Estructura Fecha (como en el Ej. 10)
struct fecha {
    int dia, mes, year;
};

// Estructura Tiempo (para la hora)
struct tiempo {
    int hora, minuto;
};

// Estructura Clima (anidada)
struct clima {
    fecha f;
    tiempo t;
    float temperatura;
};

// Prototipo de funciones
void leerRegistro(clima c[], int n);
void imprimirRegistro(clima c[], int n);
float calcularPromedio(clima c[], int n);

const int DIAS_SEMANA = 7;

int main() {
    clima semana[DIAS_SEMANA];

    leerRegistro(semana, DIAS_SEMANA);
    imprimirRegistro(semana, DIAS_SEMANA);
    
    float promedio = calcularPromedio(semana, DIAS_SEMANA);
    cout << "\nPromedio de temperaturas de la semana: " << promedio << " C" << endl;

    return 0;
}

void leerRegistro(clima c[], int n) {
    cout << "--- Registro de Temperaturas Semanal ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nDia " << i + 1 << endl;
        cout << "Fecha (dd mm aaaa): ";
        cin >> c[i].f.dia >> c[i].f.mes >> c[i].f.year;
        cout << "Hora (hh mm): ";
        cin >> c[i].t.hora >> c[i].t.minuto;
        cout << "Temperatura registrada: ";
        cin >> c[i].temperatura;
    }
}

void imprimirRegistro(clima c[], int n) {
    cout << "\n--- Temperaturas Registradas ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Dia " << i + 1 << ": ";
        cout << c[i].f.dia << "/" << c[i].f.mes << "/" << c[i].f.year << " ";
        cout << c[i].t.hora << ":" << c[i].t.minuto << " ";
        cout << c[i].temperatura << " C" << endl;
    }
}

float calcularPromedio(clima c[], int n) {
    float suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += c[i].temperatura;
    }
    return suma / n;
}