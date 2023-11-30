#include <iostream>
#include <string>

class CtaBanc {
private:
    std::string nombre;
    double saldo;

public:
    // Constructores
    CtaBanc() : nombre(""), saldo(0.0) {}
    CtaBanc(std::string nombre, double saldo) : nombre(nombre), saldo(saldo) {}

    // Métodos getters y setters
    std::string getNombre() const { return nombre; }
    double getSaldo() const { return saldo; }

    void setNombre(std::string nuevoNombre) { nombre = nuevoNombre; }
    void setSaldo(double nuevoSaldo) { saldo = nuevoSaldo; }

    // Métodos adicionales
    void deposita(double cantidad) { saldo += cantidad; }

    bool retira(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
            return true;
        }
        else {
            std::cout << "No se puede realizar el retiro. Saldo insuficiente." << std::endl;
            return false;
        }
    }

    void muestra() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Saldo: " << saldo << std::endl;
    }
};

int main() {
    // Solicitar datos al usuario
    std::string nombre;
    double saldoInicial;

    std::cout << "Ingrese el nombre: ";
    std::getline(std::cin, nombre);

    std::cout << "Ingrese el saldo inicial: ";
    std::cin >> saldoInicial;

    // Crear un objeto CtaBanc con los datos proporcionados
    CtaBanc cuenta(nombre, saldoInicial);

    // Probar los métodos
    cuenta.muestra();

    double cantidadDeposito;
    std::cout << "Ingrese la cantidad a depositar: ";
    std::cin >> cantidadDeposito;
    cuenta.deposita(cantidadDeposito);
    cuenta.muestra();

    double cantidadRetiro;
    std::cout << "Ingrese la cantidad a retirar: ";
    std::cin >> cantidadRetiro;
    cuenta.retira(cantidadRetiro);
    cuenta.muestra();

    return 0;
}
