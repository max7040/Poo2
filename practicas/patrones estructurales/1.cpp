 #include <iostream>
using namespace std;

// Clase que trabaja con soles
class PagoSoles {
public:
    void pagarEnSoles(double monto) {
        cout << "Pago realizado en soles: S/ " << monto << endl;
    }
};

// Adaptador que convierte dólares a soles
class AdaptadorPago {
    PagoSoles* pago;
    const double tipoCambio = 3.80; // 1 dólar = 3.80 soles
public:
    AdaptadorPago(PagoSoles* p) : pago(p) {}
    void pagarEnDolares(double montoDolares) {
        double montoSoles = montoDolares * tipoCambio;
        cout << "Convirtiendo $" << montoDolares << " a S/ " << montoSoles << endl;
        pago->pagarEnSoles(montoSoles);
    }
};

int main() {
    PagoSoles pagoS;
    AdaptadorPago adaptador(&pagoS);
    adaptador.pagarEnDolares(100.0);
    return 0;
}