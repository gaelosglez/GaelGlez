#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class LibroCalificaciones {
private:
    string nombre, matricula;
    double promedio;

public:
    LibroCalificaciones();
    LibroCalificaciones(string nom, string mat);

    string getNombre();
    string getMatricula();

    void setNombre(string nom);
    void setMatricula(string mat);

};

LibroCalificaciones::LibroCalificaciones() {
    nombre = " ";
    matricula = " ";
}

LibroCalificaciones::LibroCalificaciones(string nom, string mat){
    nombre = nom;
    matricula = mat;
}

void LibroCalificaciones::setNombre(string nom) {
    nombre = nom;
}
string LibroCalificaciones::getNombre(){
    return nombre;
}
string LibroCalificaciones::getMatricula() {
    return matricula;
}
void LibroCalificaciones::setMatricula(string mat) {
    matricula = mat;
}



int main() {
    LibroCalificaciones estudiante;
    string nombre, matricula;
    double promedio, calificacion, sumaCal, numCal;
    char opcion;

    sumaCal = 0;
    numCal = 0;


    do {
        cout << "a)Agregar estudiantes" << endl;
        cout << "b)Agregar calificaciones" << endl;
        cout << "c)Mostrar calificaciones" << endl;
        cout << "d)Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 'a': {

            cout << "Nombre de estudiante: ";
            cin >> nombre;
            cout << "Ingrese su matricula: ";
            cin >> matricula;
            estudiante.setNombre(nombre);
            estudiante.setMatricula(matricula);
            break;
        }

        case 'b': {
            cout << "Mas calificaciones" << endl;

            for (int i = 1; i <= 3; i++) {
                cout << "Ingrese calificacion: ";
                cin >> calificacion;
                sumaCal = sumaCal + calificacion;
                numCal += 1;
            }
            break;
        }

        case 'c': {
            cout << "Mostrar calificaciones" << endl;

            promedio = sumaCal / numCal;
            cout << "El promedio es igual a: " << promedio << endl;

            if (promedio >= 95 or promedio == 100) {
                cout << "Clasificacion es igual a Tipo A+" << endl;
            }
            else if (promedio >= 90 or promedio == 94.99) {
                cout << "Clasificacion es igual a Tipo A" << endl;
            }
            else if (promedio >= 80 or promedio == 89.99) {
                cout << "Clasificacion es igual a Tipo B" << endl;
            }
            else if (promedio >= 70 or promedio == 79.99) {
                cout << "Clasificacion es igual a Tipo C" << endl;
            }
            else {
                cout << "Clasificacion es igual a Tipo D" << endl;
            }

            break;
        }
        }
    } while (opcion != 'd');

    return 0;
}
