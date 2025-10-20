#include <iostream>
using namespace std;

// función que suma recursivamente los elementos de un array
int sumarec(int a[], int n);

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]); // Calcula el número de elementos

    cout << "\nSuma de elementos = " << sumarec(a, n) << endl;
    return 0;
}

int sumarec(int a[], int n) {
    if (n == 1) // caso base
        return a[0];
    else // caso general
        return a[n - 1] + sumarec(a, n - 1); // llamada recursiva
}