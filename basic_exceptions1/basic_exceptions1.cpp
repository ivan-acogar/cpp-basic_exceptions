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
			--i;
		}
	}

	while (true) {
		std::cout << "=== Menu de operaciones ===\n\n";
		std::cout << "1) suma de fracciones\n";
		std::cout << "2) resta de fracciones\n";
		std::cout << "3) multiplicacion de fracciones\n";
		std::cout << "4) division de fracciones\n";
	}
}