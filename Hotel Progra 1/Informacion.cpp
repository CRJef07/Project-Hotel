#include "Informacion.h"

Informacion::Informacion() {
	//CONSTRUCTOR SIN PARÁMETROS
	cantAdultos = 0;
	cantNinnos = 0;
	diasEstancia = 0;
	todoIncluido = true;
	hora = 0;
}
Informacion::Informacion(int cantAdultos, int cantNinnos, int diasEstancia, bool todoIncluido, int hora) {
	//CONSTRUCTOR PARA LOS CLIENTES SIN TODO INCLUIDO
	this->cantAdultos = cantAdultos;
	this->cantNinnos = cantNinnos;
	this->diasEstancia = diasEstancia;
	this->todoIncluido = todoIncluido;
	this->hora = hora;
}

Informacion::~Informacion() {
	//DESTRUCTOR
}

/*
void Informacion::setCantAdultos(const int & cantAdultos) {
this->cantAdultos = cantAdultos;
}
*/

void Informacion::setCantAdultos(int cantAdultos) {
	this->cantAdultos = cantAdultos;
}
void Informacion::setCantNinnos(int cantNinnos) {
	this->cantNinnos = cantNinnos;
}
void Informacion::setDiasEstancia(int diasEstancia) {
	this->diasEstancia = diasEstancia;
}
void Informacion::setTodoIncluido(bool todoIncluido) {
	this->todoIncluido = todoIncluido;
}

void Informacion::setHora(int hora) {
	this->hora = hora;
}

/*
const int & Informacion::getCantAdultos() const {
return cantAdultos;
}
*/

int Informacion::getCantAdultos() {
	return cantAdultos;
}
int Informacion::getCantNinnos() {
	return cantNinnos;
}
int Informacion::getDiasEstancia() {
	return diasEstancia;
}
bool Informacion::getTodoIncluido() {
	return todoIncluido;
}

int Informacion::getHora() {
	return hora;
}

string Informacion::toStringInfo() {
	setlocale(LC_ALL, "spanish");
	stringstream i;

	i << "La cantidad de adultos es: " << cantAdultos << endl;
	i << "La cantidad de niños es: " << cantNinnos << endl;
	i << "La cantidad de días son: " << diasEstancia << endl;

	if (todoIncluido == 1) {
		i << "Es todo incluido " << endl;
	}
	else {
		i << "No es todo incluido " << endl;

		if (hora > 12) {
			i << "La hora de entrada es: " << hora - 12 << " pm" << endl;
		}
		else {
			i << "La hora de entrada es: " << hora << " am" << endl;
		}

	}

	return i.str();
}
