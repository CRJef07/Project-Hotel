#ifndef CONTROL_H
#define CONTROL_H
#include "Contenedora.h"

//SOLO TIENE MÉTODOS, NO TIENE ATRIBUTOS
class Control {
public:
	void menu();
	void reservar(Contenedora&);
	void liberar(Contenedora&);
	void subMenu(Contenedora&);
	int pedirHora(Contenedora&);
	void cambiarMantenimiento(Contenedora&);
	void verEspecifica(Contenedora&);
};
#endif
