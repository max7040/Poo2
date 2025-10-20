#include <iostream>
#include <algorithm>
using namespace std;

int posicionMenor(const int arr[], int tam);

int main() {
    int datos[] = {15, 8, 22, 4, 30, 10};
    int tam = 6;
    
    // Posición 3 contiene el valor 4, que es el menor.
    cout << "La posicion del menor elemento es: " << posicionMenor(datos, tam) << endl; 
    
    return 0;
}

// Implementa una función que reciba como parámetros un arreglo y el tamaño de este 
// y que en forma recursiva devuelva la posición del menor elemento del array.
int posicionMenor(const int arr[], int tam) {
    // Caso base: Si solo queda un elemento, su posicion es 0 (relativo al sub-array)
    if (tam == 1) {
        return 0;
    }

    // Llamada recursiva para obtener la posicion del menor en el resto del array
    int posMenorResto = posicionMenor(arr, tam - 1);

    // Si el último elemento del array actual (arr[tam-1]) es menor que el elemento
    // en la posicionMenorResto, devolvemos la posicion del ultimo elemento (tam - 1).
    if (arr[tam - 1] < arr[posMenorResto]) {
        return tam - 1;
    } else {
        // Si no, devolvemos la posicionMenorResto (que es el indice en el sub-array)
        return posMenorResto;
    }
}