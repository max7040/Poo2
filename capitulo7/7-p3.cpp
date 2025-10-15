#include <iostream>
#include <string> // Para trabajar con std::string si se prefiere

#include "Nacimiento.h"
#include "Persona.h"

using namespace std;

int main() {
    // Ejemplo de uso de la clase Nacimiento
    cout << "--- Prueba de Clase Nacimiento ---" << endl;
    Nacimiento fecha_ejemplo;
    fecha_ejemplo.Salvarfecha(29, 2, 2024); // Año bisiesto
    cout << "Fecha guardada: "; fecha_ejemplo.Mostrar(); cout << endl;
    cout << "¿Es bisiesto el anio " << fecha_ejemplo.LoadAnual() << "? "
         << (fecha_ejemplo.Bisiesto() ? "Si" : "No") << endl;

    Nacimiento fecha_invalida;
    fecha_invalida.Salvarfecha(30, 2, 2023); // Fecha invalida
    cout << "Fecha (despues de intento invalido): "; fecha_invalida.Mostrar(); cout << endl;

    cout << "\n----------------------------------------\n";

    // Ejemplo de uso de la clase Persona
    cout << "--- Prueba de Clase Persona ---" << endl;

    // Persona usando constructor con parametros
    Persona p1("Gomez", "Ana", 15, 3, 1995);
    p1.Mostrar();
    cout << "Nombre Completo de p1: " << p1.NombreCompleto() << endl;

    cout << "\n----------------------------------------\n";

    // Persona usando el metodo Leer() interactivo
    Persona p2;
    // cin.ignore() es importante si hay inputs previos y se usa cin.getline()
    // en este main, no hay problema porque Leer() lo maneja internamente despues de la fecha.
    cout << "\nIngresando datos para una nueva persona (p2):" << endl;
    p2.Leer(); // Solicita apellidos, nombres y fecha de nacimiento
    p2.Mostrar();
    cout << "Nombre Completo de p2: " << p2.NombreCompleto() << endl;

    cout << "\n----------------------------------------\n";

    // Modificar datos de p1 y volver a mostrar
    cout << "\nModificando datos de p1:" << endl;
    p1.setApellidos("Perez");
    p1.setNombres("Juan");
    // Si se modifica la fecha de nacimiento directamente, se deberia recalcular la edad.
    // En este diseño, la edad se calcula al construir o al llamar a Leer().
    // Para cambiar la fecha y recalcular la edad, se tendria que exponer calcularEdad()
    // o hacer un setter para la fecha.
    cout << "p1 despues de modificacion:" << endl;
    p1.Mostrar();


    return 0;
}