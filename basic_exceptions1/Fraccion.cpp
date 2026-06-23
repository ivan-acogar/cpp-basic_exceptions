#include "Fraccion.hpp"
#include <iostream>
#include <stdexcept>

Fraccion::Fraccion() {
	numerador = 0;
	denominador = 1;
}

Fraccion::Fraccion(int num, int den) {
	if (den == 0) {
		throw std::invalid_argument("El denominador no puede ser 0.");
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

void Fraccion::reducir_fraccion() {
	while (denominador != 0) {
		int residuo = numerador % denominador;
		numerador = denominador;
		denominador = residuo;
	}
}

void Fraccion::suma_fracciones(Fraccion& f2) {
	int numerador_f1{};
	int numerador_f2{};

	int denominador_comun = this->denominador * f2.denominador;
	numerador_f1 = this->numerador * f2.denominador;
	numerador_f2 = f2.numerador * this->denominador;
	int numerador_final = numerador_f1 + numerador_f2;

	Fraccion resultado(numerador_final, denominador_comun);
	resultado.reducir_fraccion();

	std::cout << "Resultado de suma: " << resultado.numerador << " / " << resultado.denominador;
}