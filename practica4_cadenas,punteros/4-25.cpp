#include <iostream>
using namespace std;
const int N = 10;

int main() // Asignacion_Dinamica_3.cpp
{
    int *px, i;
    px = new int[N]; // px es arreglo de punteros dinamico
    
    // cargando el array
    for (i = 0; i < N; i++)
        px[i] = i * 2 + 1;
    
    // recorrer y mostrar el array
    cout << "\nArreglo de Punteros Dinamico\n" << endl;
    for (i = 0; i < N; i++)
    {
        cout << "Elemento " << i << " valor " << px[i] << " direccion " << px + i << endl;
    }
    return 0;
}