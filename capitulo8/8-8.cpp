// Archivo principal.cpp donde se define la funcion main()
// Programa de prueba para la clase Arreglo
#include <iostream>
#include "Arreglo1.h"

using namespace std;

int main() // principal.cpp
{
    Arreglo enteros1( 7 ); // Instanciar arreglo de 7 elementos
    Arreglo enteros2;     // Arreglo predeterminado de 10 elementos

    // Imprime el tamaño de enteros1 y su contenido
    cout << "Tamnio de enteros1: " << enteros1.obtieneTamanio() << endl;
    cout << "\nArreglo despues de la inicializacion:\n" << enteros1;

    // Imprime el tamaño de enteros2 y su contenido
    cout << "\nTamnio de enteros2: " << enteros2.obtieneTamanio() << endl;
    cout << "\nArreglo despues de la inicializacion:\n" << enteros2;

    // Introduce e imprime enteros1 y enteros2
    cout << "\nIntroduzca 17 enteros:\n";
    cin >> enteros1 >> enteros2;

    cout << "\nenteros1:\n" << enteros1
         << "\nenteros2:\n" << enteros2;

    // Utiliza el operador de desigualdad (!=) sobrecargado
    cout << "\nEvaluando: enteros1 != enteros2\n";
    if ( enteros1 != enteros2 )
        cout << "\nenteros1 y enteros2 no son iguales\n";

    // Crea el arreglo enteros3 utilizando enteros1 como un inicializador;
    // imprime su tamaño y su contenido
    Arreglo enteros3( enteros1 ); // llama al constructor de copia
    cout << "\nTamaño de enteros3 es " << enteros3.obtieneTamanio() << endl;
    cout << "\nArreglo despues de la inicializacion:\n" << enteros3;

    // Uso del operador de asignacion (=) sobrecargado
    cout << "\nAsignacion de enteros2 a enteros1:\n";
    enteros1 = enteros2; // observe que el destino es mas pequeño

    cout << "\nenteros1:\n" << enteros1
         << "\nenteros2:\n" << enteros2;

    // Utiliza el operador de igualdad (==) sobrecargado
    cout << "\nEvaluando: enteros1 == enteros2\n";
    if ( enteros1 == enteros2 )
        cout << "\nenteros1 y enteros2 son iguales\n";
    else
        cout << "\nenteros1 y enteros2 no son iguales\n";

    // Uso del operador de subindices [] sobrecargado para crear un rvalue
    cout << "\nenteros1[5] es " << enteros1[ 5 ] << endl;

    // Uso del operador de subindices [] sobrecargado para crear un lvalue
    cout << "\nAsignacion del entero 1000 a enteros1[5]\n";
    enteros1[ 5 ] = 1000; // llama a enteros1.operator[]( 5 )

    cout << "\nenteros1:\n" << enteros1;

    // Intento de uso de un subindice fuera de rango
    cout << "\nIntenta asignar el entero 1500 a enteros1[15]\n";
    enteros1[ 15 ] = 1500;

    return 0;
}