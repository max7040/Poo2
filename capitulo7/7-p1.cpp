#include <iostream>
#include "persona.h"
#include "alumno_unmsm.h"

int main() {
    // Ejemplo de uso de la clase persona
    persona p1("Maria Lopez", 25, 'F', "Soltera");
    p1.print();
    cout << "Nombre de p1 (usando get): " << p1.getNombre() << endl;
    p1.setEdad(26);
    cout << "Nueva edad de p1: " << p1.getEdad() << endl;

    cout << "\n----------------------------------------\n";

    // Ejemplo de uso de la clase alumno_unmsm
    float notas_juan[] = {15.0f, 12.5f, 18.0f, 10.0f, 14.5f};
    float creditos_juan[] = {3.0f, 4.0f, 3.0f, 2.0f, 4.0f};

    alumno_unmsm al1("Juan Perez", 20, 'M', "Soltero",
                     "20230001", notas_juan, creditos_juan);
    al1.print();

    cout << "\n----------------------------------------\n";

    // Modificar una nota y volver a imprimir para ver el cambio en el promedio
    al1.setNotaCurso(1, 16.0f); // Cambiar la nota del curso 2 (indice 1)
    cout << "Despues de cambiar la nota del Curso 2:" << endl;
    al1.print();

    cout << "\n----------------------------------------\n";

    // Crear un alumno usando el constructor por defecto y luego sets
    alumno_unmsm al2;
    al2.setNombre("Ana Garcia");
    al2.setEdad(21);
    al2.setSexo('F');
    al2.setEstadoCivil("Casada");
    al2.setCodigo("20220005");
    float notas_ana[] = {10.0f, 11.0f, 13.0f, 14.0f, 9.0f};
    float creditos_ana[] = {3.0f, 3.0f, 3.0f, 2.0f, 1.0f};
    al2.setNotasCursos(notas_ana);
    al2.setPesosCreditos(creditos_ana);
    al2.print();

    return 0;
}