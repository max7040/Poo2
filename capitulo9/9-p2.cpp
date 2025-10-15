#include <iostream>
#include <cstring> // Para funciones de manejo de cadenas (strcpy, strcmp, etc.)

using namespace std;

// Estructura de Fecha
struct fecha { 
    int dia; 
    int mes; 
    int anio;
};

// --- Clase Base: artista ---
class artista {
private:
    char nombre[30];
    fecha fecnac;
    char paisnac[15];
    char sexo;

public:
    // Constructor
    artista(char n[30], fecha f, char p[15], char s) {
        strcpy(nombre, n);
        fecnac = f;
        strcpy(paisnac, p);
        sexo = s;
    }

    // Destructor (simple, ya que no hay asignación dinámica de memoria)
    ~artista() {
        // cout << "Destructor de artista llamado para: " << nombre << endl;
    }

    // Ingreso de los datos del artista
    virtual void ingresar() {
        cout << "\n--- Ingreso de Datos del Artista ---" << endl;
        cout << "Nombre: "; cin >> nombre;
        cout << "Fecha de Nacimiento (dd mm aaaa): "; 
        cin >> fecnac.dia >> fecnac.mes >> fecnac.anio;
        cout << "País de Nacimiento: "; cin >> paisnac;
        cout << "Sexo (M/F): "; cin >> sexo;
    }

    // Impresión de los datos del artista
    virtual void imprimir() {
        cout << "\n--- Datos del Artista ---" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Fecha de Nacimiento: " << fecnac.dia << "/" << fecnac.mes << "/" << fecnac.anio << endl;
        cout << "País de Nacimiento: " << paisnac << endl;
        cout << "Sexo: " << sexo << endl;
    }
    
    // Función auxiliar para obtener el nombre, útil para el constructor derivado
    const char* get_nombre() const { return nombre; }
    
protected:
    // Hacemos que los miembros sean accesibles para Cantante
    const fecha& get_fecnac() const { return fecnac; }
    const char* get_paisnac() const { return paisnac; }
    char get_sexo() const { return sexo; }
};

// --- Clase Derivada: cantante ---
class cantante : public artista {
private:
    char genero[15];
    // Matriz de 40 filas (canciones) y 200 columnas (longitud máx. de cada nombre)
    char canciones[40][200]; 
    int cantcanciones;

public:
    // Constructor de Cantante
    cantante(char n[30], fecha f, char p[15], char s, char g[15]) 
        // Llama al constructor de la clase base
        : artista(n, f, p, s), cantcanciones(0) {
        strcpy(genero, g);
    }

    // Destructor
    ~cantante() {
        // cout << "Destructor de cantante llamado para: " << get_nombre() << endl;
    }

    // Ingreso de los datos del cantante y sus canciones (Sobreescribe artist::ingresar)
    void ingresar() override {
        // Llamar a la función ingresar de la clase base para los datos personales
        artista::ingresar();
        
        cout << "Género Musical: "; cin >> genero;
        
        cout << "¿Cuántas canciones deseas ingresar (máx. 40)? ";
        cin >> cantcanciones;
        if (cantcanciones > 40) cantcanciones = 40;
        
        cin.ignore(); // Limpiar el buffer para getline
        for (int i = 0; i < cantcanciones; ++i) {
            cout << "Nombre de la canción " << i + 1 << ": ";
            // Usamos cin.getline para permitir espacios en los títulos de las canciones
            cin.getline(canciones[i], 200);
        }
    }

    // Impresión de los datos del cantante (Sobreescribe artist::imprimir)
    void imprimir() override {
        // Llama a la función imprimir de la clase base
        artista::imprimir(); 
        cout << "Género Musical: " << genero << endl;
        cout << "Cantidad de Canciones en Repertorio: " << cantcanciones << endl;
    }

    // Devolución del género musical del cantante (Copia el género al arreglo pasado por referencia)
    void getgenero(char g[15]) {
        strcpy(g, genero);
    }

    // Impresión de las canciones interpretadas por el cantante
    void repertorio() {
        cout << "\n--- Repertorio de Canciones de " << get_nombre() << " ---" << endl;
        if (cantcanciones == 0) {
            cout << "No se ha registrado ninguna canción." << endl;
            return;
        }
        for (int i = 0; i < cantcanciones; ++i) {
            cout << i + 1 << ". " << canciones[i] << endl;
        }
    }
};

// --- Función main de prueba ---
int main() {
    // Datos iniciales para el constructor
    char nombre_init[] = "Shakira";
    fecha fecha_init = {2, 2, 1977};
    char pais_init[] = "Colombia";
    char genero_init[] = "Pop";
    
    // Creación del objeto Cantante
    cantante ctdor(nombre_init, fecha_init, pais_init, 'F', genero_init);

    // 1. Ingreso de datos interactivo
    cout << "Realizando ingreso interactivo de datos:" << endl;
    ctdor.ingresar(); 

    // 2. Impresión de todos los datos
    ctdor.imprimir();

    // 3. Imprimir el repertorio
    ctdor.repertorio();
    
    // 4. Probar getgenero
    char gen[15];
    ctdor.getgenero(gen);
    cout << "\nGenero obtenido con getgenero: " << gen << endl;

    return 0;
}