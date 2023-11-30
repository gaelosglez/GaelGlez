#include <iostream>
#include <string>

class Automovil {
private:
    int velocidad, kilometraje; // Atributo de la clase
    std::string modelo, color, marca;

public:

    // Método para encender el motor del automóvil
    void encender() {
        std::cout << "El motor se ha encendido" << std::endl;
    }

    // Método para establecer la velocidad del automóvil
    void setVelocidad(int v) {
        std::cout << "A que velocidad iria el carro? ";
        std::cin >> v;
        velocidad = v;
    }

    // Método para obtener la velocidad del automóvil
    int getVelocidad() {
        return velocidad;
    }

    // Método para establecer que se frena el automóvil
    void setFrenar(int f) {
        kilometraje = f;
    }

    // Método para obtener el frenado del automóvil
    int getFrenar() {
        return kilometraje;
    }

    // Método para apagar el motor del automóvil
    void apagar() {
        std::cout << "El motor se ha apagado" << std::endl;
    }
};

int main() {
    Automovil miAuto; // Crear un objeto de la clase Automovil
    int vel1, fre;
    std::string mod1, col1, mar1;

    std::cout << "Coloca modelo del carro: ";
    std::cin >> mod1;

    std::cout << "Coloca la marca: ";
    std::cin >> mar1;

    std::cout << "Que color te gustaria que tuviera? ";
    std::cin >> col1;

    vel1 = 1;
    fre = 0;

    miAuto.encender(); // Encender el motor
    miAuto.setVelocidad(vel1); // Establecer la velocidad a 60 km/h

    std::cout << "Velocidad del carro: " << miAuto.getVelocidad() << " km/h" << std::endl;

    miAuto.setFrenar(fre); // Establecer la velocidad a 0 km/h
    miAuto.apagar(); // Encender el motor

    std::cout << "Velocidad del carro: " << miAuto.getFrenar() << " km/h" << std::endl;

    return 0;
}