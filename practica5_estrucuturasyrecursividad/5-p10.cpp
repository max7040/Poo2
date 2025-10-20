#include <iostream>
#include <string.h>
using namespace std;

// Estructuras proporcionadas
struct fecha {
    int dia, mes, year;
};

struct datos {
    float x, y; // coordenadas
    float prof; // profundidad
    fecha dia;
};

const int MAX_PUNTOS = 10;

// Prototipos de funciones
void almacenarInformacion(datos registro[], int &n);
void imprimirInformacion(datos registro[], int n);
void encontrarProfundidadExtrema(datos registro[], int n);
void imprimirPunto(const datos &d, int numPunto);

// ----------------------------------------------------------------------

void imprimirPunto(const datos &d, int numPunto) {
    cout << "Coordenadas (x,y) del punto " << numPunto << ": " << d.x << ", " << d.y << endl;
    cout << "Profundidad asociada: " << d.prof << " mts." << endl;
    cout << "Fecha: " << d.dia.dia << "/" << d.dia.mes << "/" << d.dia.year << endl;
}

// a) Almacenar toda la información levantada (Versión interactiva)
void almacenarInformacion(datos registro[], int &n) {
    char continuar;
    
    cout << "--- Ingreso de datos ---" << endl;
    cout << "Numero maximo de puntos: " << MAX_PUNTOS << endl;

    do {
        if (n >= MAX_PUNTOS) {
            cout << "\nRegistro lleno. Maximo de puntos alcanzado." << endl;
            break;
        }

        cout << "\n--- Punto de medicion " << n + 1 << " ---" << endl;
        
        // Uso de cin para números
        cout << "Ingrese coordenadas x, y: ";
        cin >> registro[n].x >> registro[n].y;
        
        cout << "Ingrese profundidad asociada: ";
        cin >> registro[n].prof;
        
        cout << "Ingrese fecha (dd mm aaaa): ";
        cin >> registro[n].dia.dia >> registro[n].dia.mes >> registro[n].dia.year;

        n++;

        cout << "\nDesea ingresar otro punto? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');
}

// b) Imprimir toda la información levantada
void imprimirInformacion(datos registro[], int n) {
    cout << "\n--- Impresion de datos ---" << endl;
    if (n == 0) {
        cout << "No hay puntos registrados." << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        imprimirPunto(registro[i], i + 1);
    }
}

// c) Encontrar e imprimir todos los datos de la máxima y la mínima profundidad
void encontrarProfundidadExtrema(datos registro[], int n) {
    if (n == 0) return; // No hay datos
    
    int indiceMin = 0;
    int indiceMax = 0;
    float profMin = registro[0].prof;
    float profMax = registro[0].prof;

    for (int i = 1; i < n; i++) {
        // Encontrar Mínima
        if (registro[i].prof < profMin) {
            profMin = registro[i].prof;
            indiceMin = i;
        }
        // Encontrar Máxima
        if (registro[i].prof > profMax) {
            profMax = registro[i].prof;
            indiceMax = i;
        }
    }

    cout << "\n--- Minima Profundidad ---" << endl;
    imprimirPunto(registro[indiceMin], indiceMin + 1);

    cout << "\n--- Maxima Profundidad ---" << endl;
    imprimirPunto(registro[indiceMax], indiceMax + 1);
}

// ----------------------------------------------------------------------

int main() {
    datos registro[MAX_PUNTOS];
    int numPuntos = 0;

    // a) Almacenar toda la información levantada (pide datos al usuario)
    almacenarInformacion(registro, numPuntos);

    if (numPuntos > 0) {
        // b) Imprimir toda la información levantada
        imprimirInformacion(registro, numPuntos);

        // c) Encontrar e imprimir todos los datos de la máxima y la mínima profundidad
        encontrarProfundidadExtrema(registro, numPuntos);
    } else {
        cout << "\nNo se registraron datos de profundidad." << endl;
    }

    return 0;
}