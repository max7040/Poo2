#include <iostream>
#include <cmath> // Para sin(), cos()
#include <iomanip> // Para setprecision, setw, fixed

// *** CORRECCIÓN 1: Definición de PI ***
// Definimos PI ya que M_PI no siempre está disponible.
const double PI = 3.14159265358979323846;

using namespace std;

// clase base
class angulo {
public:
    void set_ang(int ang) { a = ang; }
    // Es recomendable devolver double si se va a usar en cálculos de punto flotante.
    int get_ang() { return a; } 

private:
    int a;
};

// *** CLASES DERIVADAS (tomadas de la imagen) ***

class seno:public angulo{
public:
    void valor(int ang);
};

class coseno:public angulo{
public:
    void valor(int ang);
};


// Implementación de la función seno::valor (¡Corregida!)
void seno::valor(int ang) {
    set_ang(ang);
    
    // *** CORRECCIÓN 2: Conversión correcta de Grados a Radianes ***
    // Argumento para sin(): grados * (PI / 180.0)
    double radianes = get_ang() * PI / 180.0;

    cout << "\nSeno (" << get_ang() << "): ";
    
    // *** CORRECCIÓN 3: Uso correcto de Manipuladores (fixed añadido) ***
    cout << fixed << setprecision(5) << setw(10) << sin(radianes);
}

// Implementación de la función coseno::valor (¡Corregida!)
void coseno::valor(int ang) {
    set_ang(ang);

    // *** CORRECCIÓN 2: Conversión correcta de Grados a Radianes ***
    // Argumento para cos(): grados * (PI / 180.0)
    double radianes = get_ang() * PI / 180.0;

    cout << "\nCoseno (" << get_ang() << "): ";

    // *** CORRECCIÓN 3: Uso correcto de Manipuladores (fixed añadido) ***
    cout << fixed << setprecision(5) << setw(10) << cos(radianes);
}


int main() {
    // Herencia_Angulo_3.cpp
    seno alfa;      // objeto de la clase seno
    coseno beta;    // objeto de la clase coseno
    
    int angulo_val, n;
    
    cout << "Cuantos angulos? ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        // *** CORRECCIÓN 4: Error de escritura en el prompt ***
        cout << "\nIngrese ángulo: "; 
        cin >> angulo_val;
        
        // Uso del objeto 'seno'
        alfa.valor(angulo_val);
        // Uso del objeto 'coseno'
        beta.valor(angulo_val);
        
        cout << endl;
    }
    
    cout << "\nFin del programa!" << endl;
    return 0;
}