#include <iostream>
using namespace std;

// función recursiva potencia x a la y
float potenrec(float x, int n);

int main() {
    int x, n;
    cout << "\nIngrese base y exponente enteros positivos: ";
    cin >> x >> n;

    cout << endl << x << " a la " << n << " = " << potenrec(x, n) << endl;
    return 0;
}

float potenrec(float x, int n) {
    if (n == 0) // caso base
        return 1;
    else // caso general
        return (x * potenrec(x, n - 1)); // llamada recursiva
}