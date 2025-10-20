#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> // Para gets, system("cls")

using namespace std;

const int MAX_LIBROS = 50;

// Estructura para representar el objeto principal: Libro
struct Libro {
    char titulo[50];
    char autor[50];
    char editorial[50];
    int cantidad;
    float precio_unitario;
};

// --- Prototipos de Funciones ---
void ingresarMaterial(Libro stock[], int &n);
void buscarPorTitulo(const Libro stock[], int n, const char busqueda[]);
void buscarPorAutor(const Libro stock[], int n, const char busqueda[]);
void imprimirLista(const Libro stock[], int n);
void imprimirListaPorAutor(const Libro stock[], int n);
void valorDelStock(const Libro stock[], int n);
void mostrarMenu(Libro stock[], int &n);
void imprimirLibro(const Libro &l);

// --- Funciones de Utilidad ---

// Función para imprimir un solo libro
void imprimirLibro(const Libro &l) {
    cout << "\n----------------------------" << endl;
    cout << "Titulo: " << l.titulo << endl;
    cout << "Autor: " << l.autor << endl;
    cout << "Editorial: " << l.editorial << endl;
    cout << "Cantidad en Stock: " << l.cantidad << endl;
    cout << "Precio Unitario: $" << l.precio_unitario << endl;
}

// Función para el ingreso de material
void ingresarMaterial(Libro stock[], int &n) {
    if (n >= MAX_LIBROS) {
        cout << "\nError: La biblioteca ha alcanzado su capacidad maxima." << endl;
        return;
    }

    cout << "\n--- Ingreso de Nuevo Material ---" << endl;
    fflush(stdin); 
    
    cout << "Titulo: "; gets(stock[n].titulo);
    cout << "Autor: "; gets(stock[n].autor);
    cout << "Editorial: "; gets(stock[n].editorial);
    cout << "Cantidad: "; cin >> stock[n].cantidad;
    cout << "Precio Unitario: "; cin >> stock[n].precio_unitario;
    
    n++;
    cout << "\nLibro ingresado con exito!" << endl;
}

// Función para imprimir la lista completa de material
void imprimirLista(const Libro stock[], int n) {
    cout << "\n--- LISTA COMPLETA DE MATERIAL (" << n << " libros) ---" << endl;
    if (n == 0) {
        cout << "No hay libros en el stock." << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << "ID: " << i + 1;
        imprimirLibro(stock[i]);
    }
}

// Función para imprimir la lista por autor (misma lógica que la anterior, podría ser más compleja con ordenamiento)
void imprimirListaPorAutor(const Libro stock[], int n) {
    // Nota: Para una implementación simple, solo imprimimos la lista completa.
    // Una implementación más avanzada requeriría ordenar por autor.
    cout << "\n--- LISTA DE MATERIAL (Orden sin implementar) ---" << endl;
    imprimirLista(stock, n);
}

// Función para búsqueda de material por Título
void buscarPorTitulo(const Libro stock[], int n, const char busqueda[]) {
    cout << "\n--- Busqueda por Titulo: " << busqueda << " ---" << endl;
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        // strcmp devuelve 0 si las cadenas son iguales
        if (strcmp(stock[i].titulo, busqueda) == 0) {
            imprimirLibro(stock[i]);
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontro ningun libro con ese titulo." << endl;
    }
}

// Función para búsqueda de material por Autor
void buscarPorAutor(const Libro stock[], int n, const char busqueda[]) {
    cout << "\n--- Busqueda por Autor: " << busqueda << " ---" << endl;
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(stock[i].autor, busqueda) == 0) {
            imprimirLibro(stock[i]);
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontro ningun libro de ese autor." << endl;
    }
}

// Función para el Valor del Stock
void valorDelStock(const Libro stock[], int n) {
    float valorTotal = 0.0;
    for (int i = 0; i < n; i++) {
        valorTotal += stock[i].cantidad * stock[i].precio_unitario;
    }
    cout << "\n--- VALOR TOTAL DEL STOCK ---" << endl;
    cout << "El valor total de todos los libros en stock es: $" << valorTotal << endl;
}

// --- Menú y Función Principal ---

void mostrarMenu(Libro stock[], int &n) {
    int opcion;
    char busqueda[50];
    
    do {
        system("cls"); // Limpiar pantalla (funciona en la mayoría de consolas)
        cout << "======= MENU DE BIBLIOTECA =======" << endl;
        cout << "1. Ingresar Material (Titulo, Autor, Editorial, etc.)" << endl;
        cout << "2. Imprimir Lista de Material" << endl;
        cout << "3. Busqueda por Titulo" << endl;
        cout << "4. Busqueda por Autor" << endl;
        cout << "5. Imprimir Lista (Por Autor - sin ordenar)" << endl;
        cout << "6. Valor del Stock" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        fflush(stdin);

        switch (opcion) {
            case 1:
                ingresarMaterial(stock, n);
                break;
            case 2:
                imprimirLista(stock, n);
                break;
            case 3:
                cout << "\nIngrese Titulo a buscar: "; gets(busqueda);
                buscarPorTitulo(stock, n, busqueda);
                break;
            case 4:
                cout << "\nIngrese Autor a buscar: "; gets(busqueda);
                buscarPorAutor(stock, n, busqueda);
                break;
            case 5:
                imprimirListaPorAutor(stock, n);
                break;
            case 6:
                valorDelStock(stock, n);
                break;
            case 0:
                cout << "\nSaliendo de la biblioteca. Adios!" << endl;
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo." << endl;
        }
        if (opcion != 0) {
            cout << "\nPresione ENTER para continuar...";
            cin.get();
        }
    } while (opcion != 0);
}

int main() {
    Libro stock[MAX_LIBROS];
    int numLibros = 0;

    mostrarMenu(stock, numLibros);

    return 0;
}