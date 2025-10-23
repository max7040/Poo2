 #include <iostream>
#include <vector>
using namespace std;

// Interfaz Estrategia
class EstrategiaOrdenamiento {
public:
    virtual void ordenar(vector<int>& datos) = 0;
};

// Estrategia concreta: Burbuja
class Burbuja : public EstrategiaOrdenamiento {
public:
    void ordenar(vector<int>& datos) override {
        for (size_t i = 0; i < datos.size(); i++)
            for (size_t j = 0; j < datos.size() - 1; j++)
                if (datos[j] > datos[j + 1])
                    swap(datos[j], datos[j + 1]);
    }
};

// Estrategia concreta: QuickSort
class QuickSort : public EstrategiaOrdenamiento {
private:
    void quick(vector<int>& d, int izq, int der) {
        int i = izq, j = der, pivote = d[(izq + der) / 2];
        while (i <= j) {
            while (d[i] < pivote) i++;
            while (d[j] > pivote) j--;
            if (i <= j) swap(d[i++], d[j--]);
        }
        if (izq < j) quick(d, izq, j);
        if (i < der) quick(d, i, der);
    }
public:
    void ordenar(vector<int>& datos) override {
        quick(datos, 0, datos.size() - 1);
    }
};

// Contexto
class Ordenador {
private:
    EstrategiaOrdenamiento* estrategia;
public:
    void setEstrategia(EstrategiaOrdenamiento* e) {
        estrategia = e;
    }
    void ejecutar(vector<int>& datos) {
        estrategia->ordenar(datos);
    }
};

int main() {
    vector<int> numeros = {5, 2, 9, 1, 6};
    Ordenador o;

    Burbuja burbuja;
    QuickSort quick;

    cout << "Usando burbuja: ";
    o.setEstrategia(&burbuja);
    o.ejecutar(numeros);
    for (int n : numeros) cout << n << " ";

    cout << "\nUsando quicksort: ";
    numeros = {5, 2, 9, 1, 6};
    o.setEstrategia(&quick);
    o.ejecutar(numeros);
    for (int n : numeros) cout << n << " ";
}
