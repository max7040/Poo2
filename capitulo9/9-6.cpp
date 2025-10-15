#include <iostream>
#include <cmath>
#include <conio.h> // Incluida en el código original, pero no necesaria
using namespace std;

// *** CORRECCIÓN 1: Clase Base con Herencia Virtual ***
// Se hace Empleado virtual para que Practicante solo tenga una copia de "edad".
class Empleado {
protected:
    int edad;
public:
    // Constructor de Empleado (para inicializar la edad virtual)
    Empleado(int n = 0) : edad(n) {}
    
    void setedad(int n) { edad = n; }
    int getedad() { return edad; }
};

// --- Clase Base Intermedia 1: Estudiante (Hereda virtualmente de Empleado) ---
class Estudiante : virtual public Empleado {
protected:
    int ident;
    int grado;
public:
    // Constructor (Establece sus propios miembros e inicializa el Empleado virtual)
    Estudiante(int n1, int n2, int n3) 
        : Empleado(n3), ident(n1), grado(n2) {}
    
    void setident(int n) { ident = n; }
    int getident() { return ident; }
    
    void setgrado(int n) { grado = n; }
    int getgrado() { return grado; }
    
    // getedad() y setedad() se heredan de Empleado.
};

// --- Clase Base Intermedia 2: Asalariado (Hereda virtualmente de Empleado) ---
class Asalariado : virtual public Empleado {
protected:
    float salario;
public:
    // Constructor (Inicializa el salario e inicializa el Empleado virtual)
    Asalariado(float sal = 0.0f, int n = 0) 
        : Empleado(n), salario(sal) {}
    
    void setsalario(float n) { salario = n; }
    float getsalario() { return salario; }

    // getedad() y setedad() se heredan de Empleado.
};

// --- Clase Derivada: Practicante (Herencia Múltiple) ---
class Practicante : public Estudiante, public Asalariado {
public:
    // Constructor: Inicializa las bases directas y la base virtual (Empleado)
    Practicante(int n1, int n2, int n3, float sal)
        : Empleado(n3), // Se inicializa la base virtual aquí
          Estudiante(n1, n2, n3), 
          Asalariado(sal, n3) {} // Pasa n3 solo por consistencia, no afecta la edad virtual

    void print();
};

void Practicante::print() {
    cout << "ident   : " << getident() << endl;
    
    // *** CORRECCIÓN 2: Uso de getedad() (Ahora es unambiguo gracias a 'virtual') ***
    cout << "edad    : " << getedad() << endl; 
    
    cout << "grado   : " << getgrado() << endl;
    cout << "salario : " << getsalario() << endl;
}

int main() {
    // Herencia_Empleado.cpp
    
    // *** CORRECCIÓN 3: Sintaxis de llamada y uso de float literal (f) ***
    // (ident, grado, edad, salario)
    Practicante pedro(2001, 5, 25, 1200.0f); 
    
    pedro.print();
    
    return 0;
}