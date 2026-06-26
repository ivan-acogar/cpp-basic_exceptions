#include "Fraccion.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
	std::vector <Fraccion*> fracciones;
	std::cout << "=== Calculadora de fracciones ===\n\n";

	for (int i = 0; i <= 1; ++i) {

		std::cout << "Crear fraccion numero (" << i + 1 << "):\n";

		std::cout << "Ingresa un numerador: ";
		int num{};
		std::cin >> num;

		std::cout << "Ingresa un denominador: ";
		int den{};
		std::cin >> den;

		try {
			fracciones.push_back(new Fraccion(num, den));
			Fraccion* f = fracciones[i];
			f->imprimir_fraccion();
		}

		catch (const std::invalid_argument& e) {
			std::cout << e.what();
			std::cin.clear();
			std::cin.ignore();
			--i;
		}
	}

	while (true) {
		std::cout << "=== Menu de operaciones ===\n\n";
		std::cout << "1) suma de fracciones\n";
		std::cout << "2) resta de fracciones\n";
		std::cout << "3) multiplicacion de fracciones\n";
		std::cout << "4) division de fracciones\n";
		std::cout << "5) salir\n\n";

		try {
			Fraccion* f1 = fracciones[0];
			Fraccion* f2 = fracciones[1];

			std::cout << "Elige una opcion: ";
			int option{};
			std::cin >> option;
			std::cout << "\n";

			if (std::cin.fail())
			{
				throw std::invalid_argument("Debe ingresar un numero entero dentro del rango.\n\n");
			}
			if (option == 1) {
				f1->suma_fracciones(*f2);
			}
			if (option == 2) {
				f1->resta_fracciones(*f2);
			}
			if (option == 3) {
				f1->multiplicacion_fraccion(*f2);
			}
			if (option == 4) {
				f1->division_fraccion(*f2);
			}
			if (option == 5) {
				std::cout << "Saliendo del programa.\n\n";
				break;
			}
		}

		catch (const std::invalid_argument& e) {
			std::cout << e.what();
			std::cin.clear();
			std::cin.ignore();
		}
	}
}