#include <iostream>
#include <cmath>

int main() {

    using namespace std;
    int edad, m, v, j, s;

    cout << "Inserte su edad: ";
    cin >> edad;

    m = (edad * 365) / 88;

    cout << "Tu edad en Mercurio es " << m << endl;

    v = (edad * 365) / 225;

    cout << "Tu edad en Venus es " << v << endl;

    j = (edad * 365) / 4380;

    cout << "Tu edad en Jupiter es " << j << endl;

    s = (edad * 365) / 10767;

    cout << "Tu edad en Saturno es " << s << endl;

    return 0;
    
}

