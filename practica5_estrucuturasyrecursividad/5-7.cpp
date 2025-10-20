#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 50 // Usando #define en lugar de const int para compatibilidad con la imagen
using namespace std;

struct fecha {
    int dia, mes, year;
};

struct persona {
    char nombre[40];
    short edad;
    fecha fnac; // este campo es a su vez una estructura
    char direccion[45];
    char ocupacion[20];
};
// Prototipo de las funciones
void leerPersona(persona &p);
void imprimePersona(persona &p); // La imagen usa &p en el prototipo
void leerArrayPersonas(persona jov[], int n);
void imprimeArrayPersonas(persona jov[], int n);
void buscaPersona(persona jov[], int n, char nom[]);

int main() {
    persona jovenes[N]; // Declara un array de estructuras
    int n;
    char nom[40];

    cout << "\nIngrese cantidad de personas: ";
    cin >> n;
    cout << endl;

    leerArrayPersonas(jovenes, n);
    imprimeArrayPersonas(jovenes, n);

    cout << "\nIngrese nombre a buscar: "; gets(nom); // Asumiendo gets(nom) es correcto
    fflush(stdin); // Limpiar buffer después de cin para el gets(nom)
    gets(nom); // Se usa gets(nom) según la imagen, pero se necesita un gets después de cin

    buscaPersona(jovenes, n, nom);
    return 0;
}

void leerPersona(persona &p) {
    cout << "\nIngresar nombre: "; fflush(stdin); gets(p.nombre);
    cout << "Ingresar la edad (dd/mm/aaaa): "; cin >> p.edad;
    cout << "Ingresar fecha de nacimiento: "; fflush(stdin);
    cin >> p.fnac.dia >> p.fnac.mes >> p.fnac.year;
    cout << "Ingresar direccion: "; fflush(stdin); gets(p.direccion);
    cout << "Ingresar ocupacion: "; fflush(stdin); gets(p.ocupacion);
}

void imprimePersona(persona &p) {
    cout << "\nDatos de la persona" << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Edad: " << p.edad << endl;
    cout << "Fecha de nacimiento: " << p.fnac.dia << "/" << p.fnac.mes << "/" << p.fnac.year << endl;
    cout << "Direccion: "; puts(p.direccion);
    cout << "Ocupacion: "; puts(p.ocupacion);
}

void leerArrayPersonas(persona jov[], int n) {
    cout << "\nLectura de datos en el array de personas" << endl;
    for (int i = 0; i < n; i++) {
        fflush(stdin);
        leerPersona(jov[i]);
    }
}

void imprimeArrayPersonas(persona jov[], int n) {
    cout << "\nArray de personas" << endl;
    for (int i = 0; i < n; i++) {
        imprimePersona(jov[i]);
    }
}

// Función de Búsqueda (Fragmento de la Imagen 7c)
void buscaPersona(persona jov[], int n, char nom[]) {
    bool existe = false; // se asume que no existe
    
    strupr(nom); // pasando a mayusculas la cadena a buscar

    for (int i = 0; i < n; i++) {
        // La implementación en la imagen tiene un error: debe copiar el nombre antes de convertirlo a mayúsculas o usar una variable temporal para la comparación.
        // Asumiendo que `strupr` modifica el nombre original de la estructura `jov[i].nombre`, lo cual NO es recomendable.
        
        strupr(jov[i].nombre); // pasando a mayusculas

        if (strcmp(jov[i].nombre, nom) == 0) {
            existe = true;
            imprimePersona(jov[i]); // Llama a la función imprimePersona
        }
    }

    if (existe == false) {
        cout << "Persona no existe!..." << endl;
    }
}