#include "Fraccion.hpp"
#include <iostream>
#include <stdexcept>

int main() {
	std::cout << "Calculadora de fracciones.\n\n";
	std::cout << "Crear una fraccion:\n";

	std::cout << "Ingresa un numerador: ";
	int num{};
	std::cin >> num;

	std::cout << "Ingresa un denominador: ";
	int den{};

	try {
		Fraccion f(num, den);
	}

	catch (const std::invalid_argument& e) {
		std::cout << e.what();
	}

	
}