#include<iostream>
#include<string>
#include <vector>
using namespace std;
//Examen Gael González Rebolledo 

class Usuario {
public:
    string nombre;
    string contrasena;

    Usuario(string nom, string con) {
        nombre = nom;
        contrasena = con;
    }

    bool verificarContrasena(string con) {
        return contrasena == con;
    }
};

class Empleado {
public:
    string nombre;
    double salarioBase, bonos, deducciones;
    Empleado();
    Empleado(string nom, double sal, double bon, double ded);

    string getNombre();
    double getSalarioBase();
    double getBonos();
    double getDeducciones();

    void setNombre(string nom);
    void setSalarioBase(double sal);
    void setBonos(double bon);
    void setDeducciones(double ded);

    double calcularSalario() {
        return salarioBase + bonos - deducciones;
    }
};

Empleado::Empleado() {
    nombre = " ";
    salarioBase = 0;
    bonos = 0;
    deducciones = 0;
}

Empleado::Empleado(string nom, double sal, double bon, double ded) {
    nombre = nom;
    salarioBase = sal;
    bonos = bon;
    deducciones = ded;
}

void Empleado::setNombre(string nom) {
    nombre = nom;
}
string Empleado::getNombre() {
    return nombre;
}
double Empleado::getSalarioBase() {
    return salarioBase;
}
double Empleado::getBonos() {
    return bonos;
}
double Empleado::getDeducciones() {
    return deducciones;
}
void Empleado::setSalarioBase(double sal) {
    salarioBase = sal;
}
void Empleado::setBonos(double bon) {
    bonos = bon;
}
void Empleado::setDeducciones(double ded) {
    deducciones = ded;
}

class SistemaNomina {
public:
    vector<Empleado> empleados;

    void agregarEmpleado(Empleado e) {
        empleados.push_back(e);
    }

    Empleado buscarEmpleado(string nombre) {
        for (int i = 0; i < empleados.size(); i++) {
            if (empleados[i].nombre == nombre) {
                return empleados[i];
            }
        }
        return Empleado("", 0, 0, 0);
    }

    void eliminarEmpleado(string nombre) {
        for (int i = 0; i < empleados.size(); i++) {
            if (empleados[i].nombre == nombre) {
                empleados.erase(empleados.begin() + i);
                break;
            }
        }
    }

    void modificarEmpleado(string nombre, double salarioBase, double bonos, double deducciones) {
        for (int i = 0; i < empleados.size(); i++) {
            if (empleados[i].nombre == nombre) {
                empleados[i].setSalarioBase(salarioBase);
                empleados[i].setBonos(bonos);
                empleados[i].setDeducciones(deducciones);
                break;
            }
        }
    }
};

int main() {
    SistemaNomina sistema;
    string nombreUsuario;
    string contrasena;

    cout << "Registro de usuario" << endl;
    cout << "Registre su nombre de usuario: ";
    cin >> nombreUsuario;
    cout << "Registre su contrasena: ";
    cin >> contrasena;
    Usuario usuario(nombreUsuario, contrasena);  // Crea un usuario con el nombre y la contraseña ingresados

    string nombreIngresado;
    string contrasenaIngresada;

    cout << "Inicio de sesion" << endl;
    cout << "Ingrese su nombre de usuario: ";
    cin >> nombreIngresado;
    cout << "Ingrese su contrasena: ";
    cin >> contrasenaIngresada;

    if (nombreIngresado == usuario.nombre && usuario.verificarContrasena(contrasenaIngresada)) {
        string nombre;
        double salarioBase, bonos, deducciones;
        char opcion;

        do {
            cout << "MENU" << endl;
            cout << "1. Agregar empleado" << endl;
            cout << "2. Buscar empleado" << endl;
            cout << "3. Modificar empleado" << endl;
            cout << "4. Eliminar empleado" << endl;
            cout << "5. Salir" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion;

            switch (opcion)
            {
            case '1': {

                cout << "Ingrese el nombre del empleado: ";
                cin >> nombre;
                cout << "Ingrese el salario base: ";
                cin >> salarioBase;
                cout << "Ingrese los bonos: ";
                cin >> bonos;
                cout << "Ingrese las deducciones: ";
                cin >> deducciones;
                sistema.agregarEmpleado(Empleado(nombre, salarioBase, bonos, deducciones));
                break;
            }

            case '2': {
                cout << "Ingrese el nombre del empleado que se quiere buscar: ";
                cin >> nombre;
                Empleado e = sistema.buscarEmpleado(nombre);
                cout << "El salario de " << e.nombre << " es " << e.calcularSalario() << endl;
                break;
            }

            case '3': {
                cout << "Ingrese el nombre del empleado que se quiere modificar: ";
                cin >> nombre;
                cout << "Ingrese el nuevo salario base: ";
                cin >> salarioBase;
                cout << "Ingrese los nuevos bonos: ";
                cin >> bonos;
                cout << "Ingrese las nuevas deducciones: ";
                cin >> deducciones;
                sistema.modificarEmpleado(nombre, salarioBase, bonos, deducciones);
                break;
            }

            case '4': {
                cout << "Ingrese el nombre del empleado a eliminar: ";
                cin >> nombre;
                sistema.eliminarEmpleado(nombre);
                break;
            }
            }
        } while (opcion != '5');
    }
    else {
        cout << "Nombre de usuario o contrasena incorrectos." << endl;
    }

    return 0;
}
