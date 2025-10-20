#include <iostream>
#include <string.h>
#include <stdio.h> // Para fflush y gets
#include <limits>  // Para numeric_limits
using namespace std;

// Constante para el tamaño del arreglo
const int MAX_AUTOS = 100;

// Estructura para el automóvil
struct Automovil {
    char marca[30];
    char color[20];
    int anio_fabricacion;
    float kilometros_recorridos;
};

// --- Prototipos de Funciones ---
void ingresarDatos(Automovil autos[], int &n);
void calcularPromedioKilometros(const Automovil autos[], int n);

// ----------------------------------------------------------------------

// 1. Ingreso de datos (interactivo)
void ingresarDatos(Automovil autos[], int &n) {
    char continuar;
    
    cout << "--- Ingreso de Datos de Automoviles ---" << endl;
    cout << "Ingrese la cantidad de autos a registrar (Max: " << MAX_AUTOS << "): ";
    cin >> n;

    if (n > MAX_AUTOS) {
        n = MAX_AUTOS;
        cout << "Se ajusta la cantidad a " << MAX_AUTOS << "." << endl;
    }
    
    if (n <= 0) {
        cout << "No se registraran autos." << endl;
        return;
    }

    // Limpiar el buffer después de cin para que gets funcione correctamente
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; i++) {
        cout << "\n--- Automovil " << i + 1 << " ---" << endl;
        
        cout << "Marca: "; 
        // Se usa cin.getline en lugar de gets para mejor seguridad
        cin.getline(autos[i].marca, 30);
        
        cout << "Color: "; 
        cin.getline(autos[i].color, 20);
        
        cout << "Anio de Fabricacion: "; 
        cin >> autos[i].anio_fabricacion;
        
        cout << "Kilometros Recorridos: "; 
        cin >> autos[i].kilometros_recorridos;
        
        // Limpiar buffer después de las lecturas numéricas
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// 2. y 3. Cálculo del promedio de kilómetros de la marca del auto más antiguo
void calcularPromedioKilometros(const Automovil autos[], int n) {
    if (n == 0) {
        cout << "\nNo hay autos registrados." << endl;
        return;
    }

    // --- Paso 1: Encontrar el año más antiguo ---
    int anioMasAntiguo = autos[0].anio_fabricacion;
    int indiceMasAntiguo = 0;

    for (int i = 1; i < n; i++) {
        if (autos[i].anio_fabricacion < anioMasAntiguo) {
            anioMasAntiguo = autos[i].anio_fabricacion;
            indiceMasAntiguo = i;
        }
    }

    char marcaMasAntigua[30];
    // Copiar la marca del auto más antiguo
    strcpy(marcaMasAntigua, autos[indiceMasAntiguo].marca);

    cout << "\n--- Resultado del Analisis ---" << endl;
    cout << "El auto mas antiguo es un " << marcaMasAntigua << " del anio " << anioMasAntiguo << "." << endl;

    // --- Paso 2: Calcular el promedio de los autos con esa marca ---
    float sumaKilometros = 0.0;
    int contadorAutosMismaMarca = 0;

    for (int i = 0; i < n; i++) {
        // Comparar la marca (strcmp devuelve 0 si las cadenas son iguales)
        if (strcmp(autos[i].marca, marcaMasAntigua) == 0) {
            sumaKilometros += autos[i].kilometros_recorridos;
            contadorAutosMismaMarca++;
        }
    }

    // --- Paso 3: Imprimir el resultado ---
    if (contadorAutosMismaMarca > 0) {
        float promedio = sumaKilometros / contadorAutosMismaMarca;
        cout << "\nLa marca a promediar es: " << marcaMasAntigua << " (" << contadorAutosMismaMarca << " autos)" << endl;
        cout << "El promedio de kilometros recorridos para esta marca es: " << promedio << " km" << endl;
    } else {
        // Esto solo ocurriría si el auto más antiguo no tiene marca o hay un error lógico.
        cout << "\nError: No se encontraron autos con la marca " << marcaMasAntigua << "." << endl;
    }
}

// ----------------------------------------------------------------------

int main() {
    Automovil registro[MAX_AUTOS];
    int numRegistrados = 0;

    ingresarDatos(registro, numRegistrados);
    calcularPromedioKilometros(registro, numRegistrados);

    return 0;
}