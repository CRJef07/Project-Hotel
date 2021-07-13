#include "Habitacion.h"

Habitacion::Habitacion() {
	identificadorHabitacion = " ";
	estadoOcupacion = 'L';
	cantOcupacion = 0; //de 1 a 4
	punteroCliente = new Cliente;
	punteroInfo = new Informacion;
}

Habitacion::~Habitacion() {
	delete punteroCliente;
	delete punteroInfo;
}

void Habitacion::setIdentificadorHabitacion(string id) {
	identificadorHabitacion = id;
}
void Habitacion::setEstadoOcupacion(char estado) {
	estadoOcupacion = estado;
}
void Habitacion::setCantOcupacion(int cant) {
	cantOcupacion = cant;
}

string Habitacion::getIdentificadorHabitacion() {
	return identificadorHabitacion;
}
char Habitacion::getEstadoOcupacion() {
	return estadoOcupacion;
}
int Habitacion::getCantOcupacion() {
	return cantOcupacion;
}
void Habitacion::setPunteroCliente(Cliente* ptrCli) {
	punteroCliente = ptrCli;
}
void Habitacion::setPunteroInfo(Informacion* ptrInfo) {
	punteroInfo = ptrInfo;
}
Cliente* Habitacion::getPtrCliente() {
	return punteroCliente;
}
Informacion* Habitacion::getPtrInfo() {
	return punteroInfo;
}

string Habitacion::toStringHabitacion() {
	setlocale(LC_ALL, "spanish");
	/*IMPRIME, PERO TIENE EN CONSIDERACIÓN SI EL PUNTERO DEL CLIENTE Y EL PUNTERO DE LA INFORMACIÓN
	ESTÁN APUNTANDO A NULO O NO*/
	stringstream h;

	h << "El número de la habitacion es: " << identificadorHabitacion << endl;

	if (estadoOcupacion == 'L') {

		h << "La habitación está libre" << endl;

		h << endl << "----------------------------------" << endl;

	}
	else if (estadoOcupacion == 'M') {

		h << "La habitación está en mantenimiento" << endl;

		/*matriz[i][j]->getPtrCliente()->setIdCliente("MANTENIMIENTO");*/

		h << "El ID para liberar la habitación es: " << punteroCliente->getIdCliente();

		h << endl << "----------------------------------" << endl;

	}
	else {
		h << "La habitación está ocupada" << endl;

		h << "La cantidad de ocupantes es: " << cantOcupacion << endl;

		if (punteroCliente != nullptr) {
			h << "\n\t\t La información del cliente es: \n" << punteroCliente->toStringCliente() << endl;
		}
		else {
			h << "No hay un cliente registrado en esta habitación" << endl;
		}

		if (punteroInfo != nullptr) {
			h << "\t\t La información de la habitación es: \n" << punteroInfo->toStringInfo() << endl;
		}
		else {
			h << "No hay un informacion registrada de esta habitación" << endl;
		}
		h << endl << "----------------------------------" << endl;
	}
	return h.str();
}
