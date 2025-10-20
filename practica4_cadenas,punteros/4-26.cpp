#include <iostream>
#include <cstdlib>
using namespace std;
const int N = 10;

int main() // punter6.cpp
{
    int *px, i, x[N];
    px = new int[N];
    
    // cargando el array
    for (i = 0; i < N; i++)
    {
        x[i] = i * 2 + 1;
        px[i] = x[i];
    }
    
    // recorrer y mostrar el array
    cout << "\nArreglo de Punteros Dinamico\n" << endl;
    px = &x[0];
    for (i = 0; i < N; i++)
    {
        cout << "Elemento " << i << " valor " << x[i] << " direccion " << px + i << endl;
    }
    return 0;
}