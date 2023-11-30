#include <iostream>
#include <cmath>

int main() {
	double C, F; //double es igual a float
	using namespace std;

	cout << "Inserte el valor inicial en grados Celsius: ";
	cin >> C;

	F = (9 * C / 5) + 32;

	cout << C << " grados Celsius equivalen a " << F << " grados Farenheit";

	return 0;
}