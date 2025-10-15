#include <iostream>
#include <cstring>  // Para strcpy, strcat
using namespace std;

class Nacimiento {
private:
    int dia, mes, anual;

public:
    // Pide al usuario la fecha de nacimiento
    void Leer() {
        cout << "Ingrese fecha de nacimiento (dd mm aaaa): ";
        cin >> dia >> mes >> anual;

        while (!VerificarFecha()) {
            cout << "Fecha incorrecta. Intente nuevamente (dd mm aaaa): ";
            cin >> dia >> mes >> anual;
        }
    }

    // Asigna los parámetros enviados a los datos miembros
    void SalvarFecha(int d, int m, int a) {
        dia = d;
        mes = m;
        anual = a;
    }

    // Verifica si la fecha es válida
    bool VerificarFecha() {
        if (mes < 1 || mes > 12) return false;
        if (dia < 1) return false;

        int diasMes;
        switch (mes) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                diasMes = 31; break;
            case 4: case 6: case 9: case 11:
                diasMes = 30; break;
            case 2:
                diasMes = (Bisiesto() ? 29 : 28);
                break;
            default:
                diasMes = 0;
        }
        return (dia <= diasMes);
    }

    // Muestra la fecha en formato dd/mm/aa
    void Mostrar() {
        cout << "Fecha de nacimiento: " << dia << "/" << mes << "/" << anual << endl;
    }

    // Retorna true si el año es bisiesto
    bool Bisiesto() {
        return (anual % 400 == 0) || (anual % 4 == 0 && anual % 100 != 0);
    }

    // Retorna el año
    int LoadAnual() {
        return anual;
    }
};

// -----------------------------------------------------

class Persona : public Nacimiento {
private:
    char Ape[25], Nom[20];
    int Edad;

public:
    // Pide nombres, apellidos y calcula edad
    void Leer() {
        cout << "Ingrese apellido: ";
        cin >> Ape;
        cout << "Ingrese nombre: ";
        cin >> Nom;

        // Llamamos al método Leer() de la clase base
        Nacimiento::Leer();

        int actual;
        cout << "Ingrese el año actual: ";
        cin >> actual;

        Edad = actual - LoadAnual();
    }

    // Muestra los datos de la persona
    void Mostrar() {
        cout << "\n===== DATOS DE LA PERSONA =====\n";
        cout << "Nombre completo: " << NombreCompleto() << endl;
        cout << "Edad: " << Edad << " años" << endl;
        Nacimiento::Mostrar();
    }

    // Devuelve el nombre completo
    char* NombreCompleto() {
        static char completo[50];
        strcpy(completo, Ape);
        strcat(completo, " ");
        strcat(completo, Nom);
        return completo;
    }
};

// -----------------------------------------------------
int main() {
    Persona p;
    p.Leer();
    p.Mostrar();
    return 0;
}
