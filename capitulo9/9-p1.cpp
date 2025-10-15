#include <iostream>
#include <string>
#include <vector> // Necesario para la clase derivada

using namespace std;

// CLASE BASE: PERSONA
class persona {
protected:
    string nombre;
    int edad;
    char sexo; // 'M' o 'F'
    string estado_civil;

public:
    // 1. Constructor por defecto
    persona() : nombre(""), edad(0), sexo(' '), estado_civil("") {}

    // 2. Constructor parametrizado (el que inicializa todos los atributos)
    persona(string n, int e, char s, string ec) :
        nombre(n), edad(e), sexo(s), estado_civil(ec) {}

    // 3. Constructor de copia (Opcional, pero incluido para cumplir con los 3)
    persona(const persona& otra) :
        nombre(otra.nombre), edad(otra.edad), sexo(otra.sexo), estado_civil(otra.estado_civil) {}

    // Funciones SET
    void setNombre(string n) { nombre = n; }
    void setEdad(int e) { edad = e; }
    void setSexo(char s) { sexo = s; }
    void setEstadoCivil(string ec) { estado_civil = ec; }

    // Funciones GET
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    char getSexo() const { return sexo; }
    string getEstadoCivil() const { return estado_civil; }

    // Función PRINT
    virtual void print() const {
        cout << "--- Datos Personales ---" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Estado Civil: " << estado_civil << endl;
    }

    // Destructor virtual (Buena práctica en clases base)
    virtual ~persona() {}
};// CLASE DERIVADA: ALUMNO_UNMSM
class alumno_unmsm : public persona {
private:
    string codigo;
    vector<int> notas_curso; // 5 cursos
    vector<int> peso_curso;  // 5 creditajes

public:
    // Constructor parametrizado (llama al constructor de la clase base)
    alumno_unmsm(string n, int e, char s, string ec, string cod, const vector<int>& notas, const vector<int>& pesos)
        : persona(n, e, s, ec), codigo(cod), notas_curso(notas), peso_curso(pesos) {
        // Asegurar que solo hay 5 elementos, si fuera necesario
    }

    // Constructor por defecto
    alumno_unmsm() : persona(), codigo("") {
        notas_curso.resize(5, 0); // Inicializa 5 notas a 0
        peso_curso.resize(5, 0);  // Inicializa 5 creditajes a 0
    }

    // Funciones SET
    void setCodigo(string cod) { codigo = cod; }
    void setNotas(const vector<int>& notas) { notas_curso = notas; }
    void setPesos(const vector<int>& pesos) { peso_curso = pesos; }

    // Funciones GET
    string getCodigo() const { return codigo; }
    const vector<int>& getNotas() const { return notas_curso; }
    const vector<int>& getPesos() const { return peso_curso; }

    // Función para el PROMEDIO PONDERADO
    double promedio_ponderado() const {
        if (notas_curso.size() != 5 || peso_curso.size() != 5) {
            cerr << "Error: Faltan datos de cursos. Se espera 5 notas y 5 creditajes." << endl;
            return 0.0;
        }

        double suma_productos = 0.0;
        int suma_pesos = 0;

        for (size_t i = 0; i < 5; ++i) {
            suma_productos += (double)notas_curso[i] * peso_curso[i];
            suma_pesos += peso_curso[i];
        }

        if (suma_pesos == 0) return 0.0;
        
        return suma_productos / suma_pesos;
    }
    
    // Sobreescritura de la función PRINT
    void print() const override {
        persona::print(); // Llama a la función print de la clase base
        cout << "--- Datos de Alumno ---" << endl;
        cout << "Código: " << codigo << endl;
        cout << "Notas (Créditos): ";
        for (size_t i = 0; i < notas_curso.size(); ++i) {
            cout << notas_curso[i] << " (" << peso_curso[i] << ") ";
        }
        cout << endl;
        cout << "Promedio Ponderado: " << promedio_ponderado() << endl;
    }
};
int main() {
    // Datos de ejemplo para el alumno
    vector<int> notas_ejemplo = {15, 12, 18, 14, 16};
    vector<int> creditos_ejemplo = {4, 3, 5, 4, 3};

    // Crear un objeto alumno_unmsm
    alumno_unmsm alumno1("Juan Pérez", 20, 'M', "Soltero", "20230001", notas_ejemplo, creditos_ejemplo);

    // Imprimir datos y promedio
    alumno1.print();

    // Modificar un dato y volver a imprimir
    alumno1.setEstadoCivil("Casado");
    cout << "\n--- Datos después de modificar el Estado Civil ---" << endl;
    alumno1.print();

    return 0;
}