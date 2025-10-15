/* Herencia con la clase CPersona y sus clases derivada CAlumno */
#include <iostream>
#include <string.h> // Para funciones de cadena (aunque ya incluido por cstring en los headers)
#include "Persona.h" // Incluye la definicion de CPersona
#include "Alumno.h"  // Incluye la definicion de CAlumno

using namespace std;

int main() {
    // Crea un objeto de la clase CPersona
    CPersona pp("Juan Rosales Tapia", "98004523", 17);
    pp.Print(); // Imprime los datos de la persona

    cout << "\n----------------------------------------\n";

    // Crea un objeto de la clase CAlumno
    // Nota: Cuando se crea 'industrial', se pediran las 4 notas por consola.
    CAlumno industrial("Juan Rosales Tapia", "98004523", 17, "0817456", "Electronica Industrial");
    industrial.Print(); // Imprime los datos del alumno (incluyendo los de persona y los propios del alumno)

    return 0;
}