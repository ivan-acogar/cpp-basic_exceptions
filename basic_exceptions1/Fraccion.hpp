#ifndef FRACCION_HPP
#define FRACCION_HPP

class Fraccion {
private:
	int numerador;
	int denominador;
public:
	Fraccion();
	Fraccion(int num, int den);
	void reducir_fraccion();
	void suma_fracciones(Fraccion& f2);

};

#endif