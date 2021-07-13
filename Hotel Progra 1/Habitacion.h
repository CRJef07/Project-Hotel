#ifndef HABITACION_H
#define HABITACION_H

#include "Informacion.h"
#include "Cliente.h"

class Habitacion {
public:
	Habitacion();
	~Habitacion();

	void setIdentificadorHabitacion(string id);
	void setEstadoOcupacion(char estadon);
	void setCantOcupacion(int cant); //de 1 a 4

	string getIdentificadorHabitacion();
	char getEstadoOcupacion();
	int getCantOcupacion();

	void setPunteroCliente(Cliente*);
	void setPunteroInfo(Informacion*);

	Cliente* getPtrCliente();
	Informacion* getPtrInfo();
	string toStringHabitacion();

private:
	string identificadorHabitacion;//A1-B2-C8-
	char estadoOcupacion; // Ocupada, Mantenimiento o Libre
	int cantOcupacion; //de 1 a 4

	Cliente* punteroCliente; // quien reserva
	Informacion* punteroInfo; //Info de la habitacion
};
#endif
