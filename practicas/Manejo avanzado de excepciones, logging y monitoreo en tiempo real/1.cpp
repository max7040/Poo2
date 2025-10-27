#include <iostream>
#include <fstream>
#include <stdexcept>
#include <ctime>
// Excepción personalizada
class DivisionByZeroException : public std::runtime_error {
public:
 DivisionByZeroException()
 : std::runtime_error("Error: División entre cero detectada.")
{}
};
// Logger simple
class Logger {
private:
 std::ofstream logfile;
public:
 Logger(const std::string& filename) {
 logfile.open(filename, std::ios::app);
 }
 ~Logger() {
 if (logfile.is_open()) logfile.close();
 }
 void log(const std::string& message) {
 time_t now = time(0);
 logfile << "[" << ctime(&now) << "] " << message << std::endl;
 }
};
// Función que genera una excepción
double dividir(double a, double b) {
 if (b == 0) throw DivisionByZeroException();
 return a / b;
}
int main() {
 Logger logger("system.log");
 try {
 std::cout << "Intentando dividir 10 / 0 ..." << std::endl;
 double resultado = dividir(10, 0);
 std::cout << "Resultado: " << resultado << std::endl;
 }
 catch (const DivisionByZeroException& ex) {
 std::cerr << ex.what() << std::endl;
 logger.log(ex.what()); // Se registra el error en el log
 }
 catch (const std::exception& ex) {
 std::cerr << "Excepción genérica: " << ex.what() << std::endl;
 logger.log("Excepción genérica: " + std::string(ex.what()));
 }
 logger.log("Ejecución finalizada correctamente.");
 std::cout << "Verifica el archivo system.log para los registros."
<< std::endl;
 return 0;
}
