#include <iostream>
#include <vector>
#include <algorithm> // Necesario para std::swap en QuickSort/particion

using namespace std;

// Función para imprimir el array
void printArray(const vector<int>& a, const string& msg) {
    cout << msg << ": [";
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << (i == a.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

// -----------------------------------------------------
// a) Método de la Burbuja
void burbuja(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// -----------------------------------------------------
// b) Método de Inserción
void insercion(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && temp < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

// -----------------------------------------------------
// c) Método de Selección
void seleccion(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(a[i], a[min_idx]);
        }
    }
}

// -----------------------------------------------------
// d) Método de Shell
void shellSort(vector<int>& a) {
    int n = a.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

// -----------------------------------------------------
// e) Método de Quicksort
int particion(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = particion(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

// Función principal
int main() {
    // Array original del problema 1
    vector<int> original = {9, 7, 1, 3, 5, 4, 8, 2};
    int n = original.size();

    cout << "--- 1. ALGORITMOS DE ORDENACION ---" << endl;
    printArray(original, "Array Inicial");

    // 1a) Burbuja
    vector<int> arr_burbuja = original;
    burbuja(arr_burbuja);
    printArray(arr_burbuja, "Burbuja");

    // 1b) Insercion
    vector<int> arr_insercion = original;
    insercion(arr_insercion);
    printArray(arr_insercion, "Insercion");
    
    // 1c) Seleccion
    vector<int> arr_seleccion = original;
    seleccion(arr_seleccion);
    printArray(arr_seleccion, "Seleccion");
    
    // 1d) Shell
    vector<int> arr_shell = original;
    shellSort(arr_shell);
    printArray(arr_shell, "ShellSort");

    // 1e) QuickSort
    vector<int> arr_quick = original;
    quickSort(arr_quick, 0, n - 1);
    printArray(arr_quick, "QuickSort");

    return 0;
}