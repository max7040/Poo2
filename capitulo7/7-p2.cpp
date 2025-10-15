#include <iostream>
#include "artista.h"
#include "cantante.h"

using namespace std;

int main() {
    // Ejemplo de un Artista
    fecha f1 = {10, 5, 1980};
    artista a1("Leonardo Da Vinci", f1, "Italia", 'M');
    a1.imprimir();

    cout << "\n----------------------------------------\n";

    // Ejemplo de un Cantante usando el constructor con parametros
    fecha f2 = {20, 10, 1990};
    cantante c1("Shakira Mebarak", f2, "Colombia", 'F', "Pop Latino");
    c1.addCancion("Waka Waka");
    c1.addCancion("Hips Don't Lie");
    c1.imprimir();

    cout << "\n----------------------------------------\n";

    // Ejemplo de un Cantante usando el metodo ingresar()
    cantante c2;
    cout << "\nIngresando datos para un nuevo cantante:" << endl;
    c2.ingresar(); // Esto pedira los datos de artista y luego los de cantante
    c2.imprimir();

    cout << "\n----------------------------------------\n";

    // Ejemplo de uso de getgenero
    char genero_obtenido[15];
    c1.getgenero(genero_obtenido);
    cout << "El genero musical de " << c1.getNombre() << " es: " << genero_obtenido << endl;

    return 0;
}