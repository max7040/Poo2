#include <iostream>
#include <vector> // Aunque el problema usa un array fijo, uso vector para simplicidad
using namespace std;

// Array de denominaciones: [200, 100, 50, 20, 10, 5, 1]
// El ejercicio original usa un array simple int monedas[]. Aquí usamos un vector.
void despiece(const int monedas[], int n, int valor);

int main() {
    // Array del enunciado
    const int monedas[] = {200, 100, 50, 20, 10, 5, 1};
    int n = 7; // Tamaño del array
    int valor;

    cout << "Ingrese valor -> ";
    cin >> valor;

    int valorTotalBilletes = 0;
    cout << "--------------------" << endl;
    
    // La función despiece modificada para devolver el total de billetes/monedas
    despiece(monedas, n, valor); 
    
    // Calculamos el total de billetes/monedas para imprimir la ultima linea
    int totalBilletes = 0;
    int tempValor = valor;
    for(int i = 0; i < n; ++i) {
        totalBilletes += tempValor / monedas[i];
        tempValor %= monedas[i];
    }
    
    cout << "el despiece es: " << totalBilletes << " billetes" << endl;

    return 0;
}

// Implementación de la función recursiva
// n: Tamaño restante del array (o índice actual si se maneja al reves)
// En esta implementación, 'n' es el número de elementos RESTANTES a procesar.
void despiece(const int monedas[], int n, int valor) {
    // Caso base: Si ya no hay denominaciones que procesar o el valor es 0
    if (n == 0 || valor == 0) {
        return;
    }

    // El índice de la denominación actual es (7 - n) si el tamaño total es 7
    int indiceActual = 7 - n;
    int denominacion = monedas[indiceActual];
    
    // 1. Calcular la cantidad de billetes/monedas de esta denominación
    int cantidad = valor / denominacion;
    
    // 2. Imprimir el resultado para esta denominación (si la cantidad > 0)
    if (cantidad > 0) {
        cout << cantidad << " billete(s) de " << denominacion << endl;
    }

    // 3. Calcular el valor restante
    int valorRestante = valor % denominacion;

    // 4. Llamada recursiva con una denominación menos (n-1) y el valor restante
    despiece(monedas, n - 1, valorRestante);
}