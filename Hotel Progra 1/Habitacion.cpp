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
	/*IMPRIME, PERO TIENE EN CONSIDERACI�N SI EL PUNTERO DEL CLIENTE Y EL PUNTERO DE LA INFORMACI�N
	EST�N APUNTANDO A NULO O NO*/
	stringstream h;

	h << "El n�mero de la habitacion es: " << identificadorHabitacion << endl;

	if (estadoOcupacion == 'L') {

		h << "La habitaci�n est� libre" << endl;

		h << endl << "----------------------------------" << endl;

	}
	else if (estadoOcupacion == 'M') {

		h << "La habitaci�n est� en mantenimiento" << endl;

		/*matriz[i][j]->getPtrCliente()->setIdCliente("MANTENIMIENTO");*/

		h << "El ID para liberar la habitaci�n es: " << punteroCliente->getIdCliente();

		h << endl << "----------------------------------" << endl;

	}
	else {
		h << "La habitaci�n est� ocupada" << endl;

		h << "La cantidad de ocupantes es: " << cantOcupacion << endl;

		if (punteroCliente != nullptr) {
			h << "\n\t\t La informaci�n del cliente es: \n" << punteroCliente->toStringCliente() << endl;
		}
		else {
			h << "No hay un cliente registrado en esta habitaci�n" << endl;
		}

		if (punteroInfo != nullptr) {
			h << "\t\t La informaci�n de la habitaci�n es: \n" << punteroInfo->toStringInfo() << endl;
		}
		else {
			h << "No hay un informacion registrada de esta habitaci�n" << endl;
		}
		h << endl << "----------------------------------" << endl;
	}
	return h.str();
}
