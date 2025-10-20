#include <iostream>
#include <cmath> 
using namespace std;

class Caja {
    double longitud;
    double ancho, altura;

public:
    // ------------------------------------
    // Métodos Base Proporcionados
    // ------------------------------------
    void set(int l, int w, int h) { 
        longitud = l; 
        ancho = w; 
        altura = h; 
    }
    
    void get() { 
        cout << "\nLongitud " << longitud 
             << ", Ancho " << ancho 
             << ", Altura " << altura << endl; 
    }
    
    int volumen(void) { 
        return (int)(longitud * ancho * altura); 
    }

    // ------------------------------------
    // Declaración de Operadores
    // ------------------------------------
    
    // Operadores Amigos
    friend Caja operator+(Caja a, Caja b); 
    friend Caja operator+(int a, Caja b);  
    friend Caja operator*(int a, Caja b);  
    
    // Operadores Miembro
    Caja operator++();     // Prefijo
    Caja operator++(int);  // Posfijo
};

// ====================================================================
// IMPLEMENTACIÓN DE OPERADORES AMIGOS (Funciones Globales)
// ====================================================================

// 1. Sobrecarga: Caja + Caja (Suma las dimensiones)
Caja operator+(Caja a, Caja b) {
    Caja temp;
    temp.set(a.longitud + b.longitud, a.ancho + b.ancho, a.altura + b.altura);
    return temp;
}

// 2. Sobrecarga: int + Caja (Suma la constante a cada dimensión)
Caja operator+(int a, Caja b) {
    Caja temp;
    temp.set(b.longitud + a, b.ancho + a, b.altura + a);
    return temp;
}

// 3. Sobrecarga: int * Caja (Multiplica la constante por cada dimensión)
Caja operator*(int a, Caja b) {
    Caja temp;
    temp.set(b.longitud * a, b.ancho * a, b.altura * a);
    return temp;
}


// ====================================================================
// IMPLEMENTACIÓN DE OPERADORES MIEMBRO (Funciones de la Clase)
// ====================================================================

// 4. Sobrecarga: Incremento prefijo (++Caja)
Caja Caja::operator++() {
    // Incrementa las dimensiones antes de devolver
    set(longitud + 1, ancho + 1, altura + 1);
    return *this; 
}

// 5. Sobrecarga: Incremento posfijo (Caja++)
Caja Caja::operator++(int) {
    Caja temp = *this; // 1. Guarda el estado original
    
    // 2. Incrementa las dimensiones del objeto actual
    set(longitud + 1, ancho + 1, altura + 1);
    
    return temp; // 3. Devuelve el estado original
}


// ====================================================================
// FUNCIÓN PRINCIPAL (main)
// ====================================================================

int main() {
    Caja pequena, mediana, grande;
    Caja temp; 

    // Inicialización de las cajas
    pequena.set(2, 4, 5);
    mediana.set(5, 6, 8);
    grande.set(8, 10, 12);
    
    cout << "**** CLASE CAJAS ****" << endl;

    // --- Cajas Iniciales y Volumen ---
    cout << "\nPequeña:";
    pequena.get();
    cout << "El volumen de pequena es " << pequena.volumen() << "\n"; 

    cout << "\nMediana:";
    mediana.get();
    cout << "El volumen de mediana es " << mediana.volumen() << "\n"; 

    cout << "\nGrande:";
    grande.get();
    cout << "El volumen de grande es " << grande.volumen() << "\n"; 

    // --- Operación: Caja + Caja ---
    temp = pequena + mediana; 
    cout << "\npequena + mediana "; 
    temp.get();
    cout << "El nuevo volumen es " << temp.volumen() << "\n"; 

    // --- Operación: int + Caja ---
    temp = 10 + pequena;
    cout << "\n10 + pequena "; 
    temp.get();
    cout << "El nuevo volumen es " << temp.volumen() << "\n"; 

    // --- Operación: int * Caja ---
    temp = 4 * grande;
    cout << "\n4 * grande "; 
    temp.get();
    cout << "El nuevo volumen es " << temp.volumen() << "\n"; 

    // --- Operación: Incremento Prefijo ---
    ++pequena; 
    cout << "\nIncremento prefijo a pequena:"; 
    pequena.get();
    cout << "El volumen es " << pequena.volumen() << "\n"; 

    // --- Operación: Incremento Posfijo ---
    grande++; 
    cout << "\nIncremento posfijo a grande"; 
    grande.get(); 
    cout << "El volumen es " << grande.volumen() << "\n"; 

    return 0;
}