#include "Fraccion.hpp"
#include <iostream>
#include <stdexcept>

Fraccion::Fraccion() {
	numerador = 0;
	denominador = 1;
}

Fraccion::Fraccion(int num, int den) {
	if (den == 0) {
		throw std::invalid_argument("\nEl denominador no puede ser 0.\n\n");
	}
	else if (num == 0) {
		numerador = 0;
		denominador = 1;
	}
	else if (num > 0 and den < 0) {
		numerador = -num;
		denominador = -den;
	}
	else if (num < 0 and den < 0) {
		numerador = -num;
		denominador = -den;
	}
	else {
		numerador = num;
		denominador = den;
	}

	reducir_fraccion();
}

void const Fraccion::imprimir_fraccion() {
	std::cout << "\nFraccion: " << numerador << "/" << denominador << "\n\n";
}

void Fraccion::reducir_fraccion() {
	int a{ numerador };
	int b{ denominador };

	while (b != 0) {
		int residuo = a % b;
		a = b;
		b = residuo;
	}

	numerador /= a;
	denominador /= a;

}

void Fraccion::suma_fracciones(Fraccion& f2) {
	std::cout << "Suma seleccionada: " << this->numerador << "/" << this->denominador << " + " << f2.numerador << "/" << f2.denominador << "\n\n";

	int numerador_f1{};
	int numerador_f2{};

	int denominador_comun = this->denominador * f2.denominador;
	numerador_f1 = this->numerador * f2.denominador;
	numerador_f2 = f2.numerador * this->denominador;
	int numerador_final = numerador_f1 + numerador_f2;

	Fraccion resultado(numerador_final, denominador_comun);
	resultado.reducir_fraccion();

	std::cout << "Resultado de suma: " << resultado.numerador << " / " << resultado.denominador << "\n\n";
}

void Fraccion::resta_fracciones(Fraccion& f2) {
	std::cout << "Resta seleccionada: " << this->numerador << "/" << this->denominador << " - " << f2.numerador << "/" << f2.denominador << "\n\n";

	int numerador_f1{};
	int numerador_f2{};

	int denominador_comun = this->denominador * f2.denominador;
	numerador_f1 = this->numerador * f2.denominador;
	numerador_f2 = f2.numerador * this->denominador;
	int numerador_final = numerador_f1 - numerador_f2;

	Fraccion resultado(numerador_final, denominador_comun);
	resultado.reducir_fraccion();
	
	std::cout << "Resultado de la resta: " << resultado.numerador << " / " << resultado.denominador << "\n\n";
}

void Fraccion::division_fraccion(Fraccion& f2) {
	std::cout << "Division seleccionada: " << this->numerador << "/" << this->denominador << " entre " << f2.numerador << "/" << f2.denominador << "\n\n";

	if (f2.numerador == 0) {
		std::cout << "No se puede dividir entre cero.\n\n";
	}

	else {
		int new_numerador = this->numerador * f2.denominador;
		int new_denominador = this->denominador * f2.numerador;

		Fraccion resultado(new_numerador, new_denominador);
		resultado.reducir_fraccion();

		std::cout << "Resultado de la division: " << resultado.numerador << " / " << resultado.denominador << "\n\n";
	}
}

void Fraccion::multiplicacion_fraccion(Fraccion& f2) {
	std::cout << "Division seleccionada: " << this->numerador << "/" << this->denominador << " entre " << f2.numerador << "/" << f2.denominador << "\n\n";

	int new_numerador = this->numerador * f2.numerador;
	int new_denominador = this->denominador * f2.denominador;

	Fraccion resultado(new_numerador, new_denominador);
	resultado.reducir_fraccion();

	std::cout << "Resultado de la multiplicacion: " << resultado.numerador << " / " << resultado.denominador << "\n\n";
}