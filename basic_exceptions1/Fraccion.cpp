#include "Fraccion.hpp"
#include <iostream>

Fraccion::Fraccion() {
	numerador = 0;
	denominador = 1;
}

Fraccion::Fraccion(int num, int den) {
	numerador = num;
	denominador = den;
}

void Fraccion::reducir_fraccion() {
	int i{1};
	while (numerador % i == 0 || denominador % i == 0) {
		numerador /= i;
		denominador /= i;
		i++;
	}
}

void Fraccion::suma_fracciones(Fraccion& f2) {
	int numerador_f1{};
	int numerador_f2{};

	int denominador_comun = this->denominador * f2.denominador;
	numerador_f1 = this->numerador * f2.denominador;
	numerador_f2 = f2.numerador * this->denominador;
	int numerador_final = numerador_f1 + numerador_f2;

	reducir_fraccion();

	std::cout << "Resultado de suma: " << numerador_final << " / " << denominador_comun;
}