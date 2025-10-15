#include <iostream>
using namespace std;

// Muestra el concepto de clase base y clase derivada
// un auto es un vehiculo

// Clase base: Vehiculo
class Vehiculo { 
private:
    int Peso;
    int MaxVeloc;
    float Precio;

public:
    // Constructor por defecto
    Vehiculo() {} 
    
    // Constructor con parámetros
    Vehiculo(int, int, float);
    
    // Getters
    int getPeso() { return Peso; }
    int getMaxVeloc() { return MaxVeloc; }
    float getPrecio() { return Precio; }
    
    // Función de impresión (Print)
    void Print();
};

// Definición de funciones miembro de la clase base Vehiculo
Vehiculo :: Vehiculo(int pe, int maxV, float prec) {
    Peso = pe;
    MaxVeloc = maxV;
    Precio = prec;
}

void Vehiculo :: Print() {
    cout << "\nPeso: " << Peso << " Kg";
    cout << "\nVelocidad Maxima: " << MaxVeloc << " km/h";
    cout << "\nPrecio: " << Precio << " Dolares";
}

// Clase derivada: Auto
class Auto : public Vehiculo {
private:
    int NumeroCilindros;
    int PotenciaCaballos;
    int Desplazamiento;

public:
    // Constructor por defecto
    Auto() {} 
    
    // Constructor con parámetros (llama al constructor de la clase base)
    Auto(int, int, float, int, int, int);
    
    // Destructor (sin implementación ya que no se necesita en este ejemplo)
    ~Auto() {}

    // Getters
    int getNumeroCilindros() { return NumeroCilindros; }
    int getPotenciaCaballos() { return PotenciaCaballos; }
    int getDesplazamiento() { return Desplazamiento; }
    
    // Sobreescritura de la función de impresión (Print)
    void Print();
};

// Constructor de la clase derivada Auto
Auto :: Auto(int pe, int maxV, float prec, int NumCil, int PotCaba, int Despla) 
    : Vehiculo(pe, maxV, prec) // Llama al constructor de la clase base
{
    NumeroCilindros = NumCil;
    PotenciaCaballos = PotCaba;
    Desplazamiento = Despla;
}

// Print para la clase derivada (¡Corregido el carácter de escape!)
void Auto :: Print() {
    Vehiculo :: Print(); // Heredando e imprimiendo la información de la clase padre

    // ** Corrección del carácter de escape de \n **
    cout << "\nNumero de Cilindros: " << NumeroCilindros;
    cout << "\nCaballos de Potencia: " << PotenciaCaballos;
    cout << "\nDesplazamiento: " << Desplazamiento << " cm cubicos";
}

int main() {
    // Herencia_Vehiculo.cpp
    
    // Objeto de la clase base
    Vehiculo unVehiculo(4500, 120, 30000.00);
    cout << "\nUn Vehiculo: ";
    unVehiculo.Print();
    cout << endl;

    // Objeto derivado de vehiculo
    cout << "\nAhora con un objeto derivado de Vehiculo" << endl << endl;
    
    // Objeto de la clase derivada Auto (Peso, MaxV, Precio, NumCil, PotCaba, Desplazamiento)
    Auto unAuto(3500, 100, 12000.00, 6, 120, 300);
    
    cout << "\nUn Auto: ";
    unAuto.Print();
    cout << endl << endl;
    
    return 0;
}