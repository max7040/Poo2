#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> // Para malloc o new si se usa C++ moderno

using namespace std;

const int MAX_VEHICULOS = 50; // Maximo de vehículos a registrar

struct Infraccion {
    char NroPlaca[10];
    char Marca[15];
    char Color[15];
    char FechaInfra[12]; // dd/mm/aaaa
    char Distrito[25];
    float MultaPagar;
};

// Prototipos de funciones
void almacenarDatos(Infraccion registro[], int &n);
void mostrarInformacion(Infraccion registro[], int n);
void mostrarVehiculosPorMarca(Infraccion registro[], int n, const char marca[]);
void determinarMultaMasAlta(Infraccion registro[], int n);

int main() {
    Infraccion registro[MAX_VEHICULOS];
    int n = 0; // Contador de vehiculos registrados
    
    // Asumir que solo se registran datos de Abril y sin más de 1 infracción.
    
    // a) Almacenar los datos
    almacenarDatos(registro, n);

    // b) Mostrar la información procesada
    mostrarInformacion(registro, n);

    // c) Mostrar todos los vehículos de una determinada marca y la cantidad que existen
    char marcaBuscar[15];
    cout << "\nIngrese la Marca del vehiculo a buscar: ";
    cin >> marcaBuscar;
    mostrarVehiculosPorMarca(registro, n, marcaBuscar);

    // d) Determinar el vehículo que pagará la multa más alta
    determinarMultaMasAlta(registro, n);

    return 0;
}

void almacenarDatos(Infraccion registro[], int &n) {
    char continuar;
    
    cout << "--- Registro de Infracciones de Abril (Simulacion) ---" << endl;

    do {
        if (n >= MAX_VEHICULOS) {
            cout << "Registro lleno. No se pueden agregar mas vehiculos." << endl;
            break;
        }

        cout << "\n--- Vehiculo " << n + 1 << " ---" << endl;
        
        cout << "Nro Placa: "; cin >> registro[n].NroPlaca;
        cout << "Marca: "; fflush(stdin); cin.getline(registro[n].Marca, 15);
        cout << "Color: "; cin.getline(registro[n].Color, 15);
        
        // Simulación: Fija la fecha de infracción a un día de Abril.
        strcpy(registro[n].FechaInfra, "15/04/2025");
        cout << "Fecha Infraccion: 15/04/2025" << endl;

        cout << "Distrito: "; cin.getline(registro[n].Distrito, 25);
        cout << "Monto Multa: "; cin >> registro[n].MultaPagar;

        n++;

        cout << "\nDesea ingresar otro vehiculo? (s/n): ";
        cin >> continuar;
        fflush(stdin); // Limpiar buffer
    } while (continuar == 's' || continuar == 'S');
}

void mostrarInformacion(Infraccion registro[], int n) {
    cout << "\n--- INFORMACION COMPLETA DEL REGISTRO ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nVehiculo " << i + 1 << endl;
        cout << "Placa: " << registro[i].NroPlaca << endl;
        cout << "Marca: " << registro[i].Marca << endl;
        cout << "Color: " << registro[i].Color << endl;
        cout << "Fecha: " << registro[i].FechaInfra << endl;
        cout << "Distrito: " << registro[i].Distrito << endl;
        cout << "Multa: " << registro[i].MultaPagar << endl;
    }
}

void mostrarVehiculosPorMarca(Infraccion registro[], int n, const char marca[]) {
    int contador = 0;
    cout << "\n--- Vehiculos de la marca " << marca << " ---" << endl;
    
    for (int i = 0; i < n; i++) {
        // Usar stricmp (no estandar pero comun) o convertir a mayusculas para la comparacion
        if (strcmp(registro[i].Marca, marca) == 0) {
            cout << "Placa: " << registro[i].NroPlaca << ", Multa: " << registro[i].MultaPagar << endl;
            contador++;
        }
    }
    cout << "\nCantidad de vehiculos de la marca " << marca << ": " << contador << endl;
}

void determinarMultaMasAlta(Infraccion registro[], int n) {
    if (n == 0) {
        cout << "\nNo hay vehiculos registrados." << endl;
        return;
    }

    int indiceMax = 0;
    float multaMax = registro[0].MultaPagar;

    for (int i = 1; i < n; i++) {
        if (registro[i].MultaPagar > multaMax) {
            multaMax = registro[i].MultaPagar;
            indiceMax = i;
        }
    }

    cout << "\n--- VEHICULO CON LA MULTA MAS ALTA ---" << endl;
    cout << "Placa: " << registro[indiceMax].NroPlaca << endl;
    cout << "Marca: " << registro[indiceMax].Marca << endl;
    cout << "Multa a pagar: " << registro[indiceMax].MultaPagar << endl;
    cout << "Todos sus datos:" << endl;
    cout << "Color: " << registro[indiceMax].Color << endl;
    cout << "Fecha: " << registro[indiceMax].FechaInfra << endl;
    cout << "Distrito: " << registro[indiceMax].Distrito << endl;
}