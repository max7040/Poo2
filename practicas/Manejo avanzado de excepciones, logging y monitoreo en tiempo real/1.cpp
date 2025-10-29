#include <iostream>
#include <fstream>   // para escribir en archivos
#include <stdexcept> // para excepciones
#include <ctime>     // para obtener fecha y hora
#include <thread>    // para simular monitoreo en tiempo real
#include <chrono>    // para pausas de tiempo
#include <cstring>   // para manipular cadenas (ctime usa esto)

using namespace std;

// EXCEPCIONES PERSONALIZADAS

// Error: división entre cero
class DivisionByZeroException : public runtime_error {
public:
    DivisionByZeroException()
        : runtime_error("Error: División entre cero detectada.") {}
};

// Error: número negativo
class NegativeValueException : public runtime_error {
public:
    NegativeValueException()
        : runtime_error("Error: Se detectó un número negativo.") {}
};


// CLASE LOGGER (para registrar eventos en un archivo)
class Logger {
private:
    ofstream logfile;  // flujo de salida hacia el archivo log
public:
    Logger(const string& filename) {
        logfile.open(filename, ios::app);
    }

    ~Logger() {
        if (logfile.is_open()) logfile.close();
    }

    void log(const string& message) {
        time_t now = time(0);//segundos 1/1/1970 S Op Unix
        char* dt = ctime(&now);//"Wed Oct 29 16:05:43 2025\n"
        dt[strlen(dt) - 1] = '\0';  // elimina el salto de línea de ctime
        logfile << "[" << dt << "] " << message << endl;
    }
};

// FUNCIÓN DE DIVISIÓN (lanza excepciones si hay error)
double dividir(double a, double b) {
    if (b == 0)
        throw DivisionByZeroException();
    if (a < 0 || b < 0)
        throw NegativeValueException();
    return a / b;
}


// FUNCIÓN PRINCIPAL (versión interactiva)
int main() {
    Logger logger("system.log");
    cout << "=== MONITOREO EN TIEMPO REAL ===\n";
    cout << "Ingrese pares de números para dividir (escriba 'q' para salir)\n\n";

    while (true) {
        string entradaA, entradaB;
        cout << "Número A: ";
        cin >> entradaA;
        if (entradaA == "q" || entradaA == "Q") break; // salir del programa

        cout << "Número B: ";
        cin >> entradaB;
        if (entradaB == "q" || entradaB == "Q") break;

        try {
            // convierte las entradas a double
            double a = stod(entradaA);
            double b = stod(entradaB);
            //stod string->double - <string> 
            // realiza la división
            double resultado = dividir(a, b);

            cout << "Resultado: " << a << " / " << b << " = " << resultado << endl;

            // registra en el log
            logger.log("Operación exitosa: " + to_string(a) + " / " + to_string(b) + 
                       " = " + to_string(resultado));
            //to_string (int,double)->string - <string>
        }
        catch (const invalid_argument&) {
            cerr << "Error: Entrada no numérica detectada.\n";
            logger.log("Error: Entrada no numérica detectada.");
        }
        catch (const exception& ex) {
            cerr << ex.what() << endl;
            logger.log(string("Excepción: ") + ex.what());
        }

        // simula tiempo real (espera 1 segundo)
        this_thread::sleep_for(chrono::seconds(1));//pausa por 1 segundo 
        //namespace  sleep_for(tiempo) seconds objeto temp 

        cout << "---------------------------------------------\n";
    }

    cout << "\nMonitoreo finalizado. Revisa el archivo 'system.log'.\n";
    logger.log("Monitoreo finalizado correctamente.");
    return 0;
}
