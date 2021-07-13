#include "Contenedora.h"


Contenedora::Contenedora() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			matriz[i][j] = new Habitacion;//HABITACION VACIA
		}
	}
}

Contenedora::~Contenedora() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			delete matriz[i][j];
		}
	}
}

bool Contenedora::verificarHabitaciones(string idHab) {
	/*SI EL ID DE LA HABITACIÓN ES IGUAL AL ID POR PARÁMETROS, RETURN TRUE
	CASO CONTRARIO RETURN FALSE*/

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getIdentificadorHabitacion() == idHab) {
				if (matriz[i][j]->getEstadoOcupacion() == 'L') {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	return false;
}

void Contenedora::ponerIDHab() {

	for (int i = 0; i < 10; i++) {//recorrer habitaciones piso 1
		stringstream x;
		x << "A" << i + 1;//A1
		matriz[0][i]->setIdentificadorHabitacion(x.str());
	}
	for (int i = 0; i < 10; i++) {//recorrer habitaciones piso 2
		stringstream x;
		x << "B" << i + 1;
		matriz[1][i]->setIdentificadorHabitacion(x.str());
	}
	for (int i = 0; i < 10; i++) {//recorrer habitaciones piso 3
		stringstream x;
		x << "C" << i + 1;
		matriz[2][i]->setIdentificadorHabitacion(x.str());
	}
	for (int i = 0; i < 10; i++) {//recorrer habitaciones piso 4
		stringstream x;
		x << "D" << i + 1;
		matriz[3][i]->setIdentificadorHabitacion(x.str());
	}
	for (int i = 0; i < 10; i++) {//recorrer habitaciones piso 5
		stringstream x;
		x << "E" << i + 1;
		matriz[4][i]->setIdentificadorHabitacion(x.str());
	}
}

string Contenedora::toStringMatriz() {
	stringstream M;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			M << matriz[i][j]->toStringHabitacion() << endl;
		}
	}
	return M.str();
}

string Contenedora::impremeCodigo() {
	setlocale(LC_ALL, "spanish");
	stringstream codigo;

	//codigo << "\t\tMOSTRANDO TODAS LAS HABITACIONES" << endl << endl;
	codigo << "Si hay alguna habitacion libre o en mantenimiento aparece el siguiente símbolo:  " << char(126) << endl << endl;


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getEstadoOcupacion() == 'L') {
				codigo << "   " << matriz[i][j]->getIdentificadorHabitacion() << "   ";
			}
			else {
				codigo << "    " << char(126) << "   ";// 206 197 176 177 178 157 126
			}
		}
		codigo << endl << endl;
	}
	return codigo.str();
}

string Contenedora::imprimeHab(string idh) {
	system("cls");
	stringstream x;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getIdentificadorHabitacion() == idh) {
				x << matriz[i][j]->toStringHabitacion();
			}
		}
	}
	return x.str();
}

void Contenedora::ingresarInfoyCliente(string idh, Cliente* C, Informacion* I) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getIdentificadorHabitacion() == idh) {
				matriz[i][j]->setPunteroCliente(C);
				matriz[i][j]->setPunteroInfo(I);
			}
		}
	}
}

void Contenedora::cambiarEstado(string ID) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getIdentificadorHabitacion() == ID) {
				matriz[i][j]->setEstadoOcupacion('O');
			}
		}
	}
}

void Contenedora::cambiarCant(string ID, int can) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getIdentificadorHabitacion() == ID) {
				matriz[i][j]->setCantOcupacion(can);
			}
		}
	}
}

float Contenedora::cobrarNoIncluido() { // MÉTODO COBRO NORMAL
	float monto = 0;
	float montoA = 0, montoB = 0;

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 10; j++) {

			if (matriz[i][j]->getPtrInfo()->getTodoIncluido() == false) {

				if (matriz[i][j]->getPtrInfo()->getHora() >= 18) {//sea mayor o igual que 6pm

					switch (matriz[i][j]->getCantOcupacion()) {
					case 1:
						montoA += 150 - (150 * 0.25);
						montoB += 150 * (matriz[i][j]->getPtrInfo()->getDiasEstancia() - 1);
						monto += montoA + montoB;
						break;

					case 2:
						montoA += 250 - (250 * 0.2);
						montoB += 250 * (matriz[i][j]->getPtrInfo()->getDiasEstancia() - 1);
						monto += montoA + montoB;
						break;

					case 3:
						montoA += 350 - (350 * 0.15);
						montoB += 350 * (matriz[i][j]->getPtrInfo()->getDiasEstancia() - 1);
						monto += montoA + montoB;
						break;

					case 4:
						montoA += 450 - (450 * 0.1);
						montoB += 450 * (matriz[i][j]->getPtrInfo()->getDiasEstancia() - 1);
						monto += montoA + montoB;
						break;
					}//FIN SWITCH

				}
				else {//sea menor que 6pm

					switch (matriz[i][j]->getCantOcupacion()) {
					case 1:
						monto += 150 * matriz[i][j]->getPtrInfo()->getDiasEstancia();
						break;

					case 2:
						monto += 250 * matriz[i][j]->getPtrInfo()->getDiasEstancia();

						break;

					case 3:
						monto += 350 * matriz[i][j]->getPtrInfo()->getDiasEstancia();
						break;
					case 4:
						monto += 400 * matriz[i][j]->getPtrInfo()->getDiasEstancia();
						break;
					}//FIN SWITCH
				}
			}
		}
	}
	return monto;
}

int Contenedora::cobrarIncluido() { // MÉTODO COBRO NORMAL
	int totalAD = 0;
	int totalNI = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getPtrInfo()->getTodoIncluido() == true) {//SI ES TODO INCLUIDO
				//CUANDO SE METE AL TODO INCLUIDO PETA
				totalAD += (matriz[i][j]->getPtrInfo()->getCantAdultos() * 300) * matriz[i][j]->getPtrInfo()->getDiasEstancia();
				totalNI += (matriz[i][j]->getPtrInfo()->getCantNinnos() * 200) * matriz[i][j]->getPtrInfo()->getDiasEstancia();
			}
		}
	}
	return totalAD + totalNI;
}

bool Contenedora::horaCorrecta(int horaEntrada) {
	if (horaEntrada > 0 && horaEntrada < 24) {
		return true;
	}
	else {
		return false;
	}
}

int Contenedora::habLibres() {
	int contadorLibres = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getEstadoOcupacion() == 'L') {
				contadorLibres++;
			}
		}
	}
	return contadorLibres;
}

int Contenedora::habMantenimiento() {
	int contadorMantenimiento = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getEstadoOcupacion() == 'M') {
				contadorMantenimiento++;
			}
		}
	}
	return contadorMantenimiento;
}

int Contenedora::habOcupadas() {
	int contadorOcupadas = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getEstadoOcupacion() == 'O') {
				contadorOcupadas++;
			}
		}
	}
	return contadorOcupadas;
}

int Contenedora::cantAdultos() {
	int adultos = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getEstadoOcupacion() == 'O') {
				adultos += matriz[i][j]->getPtrInfo()->getCantAdultos();
			}
		}
	}
	return adultos;
}

int Contenedora::cantMenores() {
	int menores = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getEstadoOcupacion() == 'O') {
				menores += matriz[i][j]->getPtrInfo()->getCantNinnos();
			}
		}
	}
	return menores;
}

bool Contenedora::mantenimiento(string ID) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getEstadoOcupacion() != 'O') {
				if (matriz[i][j]->getIdentificadorHabitacion() == ID) {
					matriz[i][j]->setEstadoOcupacion('M');
					matriz[i][j]->getPtrCliente()->setIdCliente("MANTENIMIENTO");
					matriz[i][j]->getPtrCliente()->setFormaPago("0");
					matriz[i][j]->getPtrCliente()->setNombreCliente("0");
					matriz[i][j]->getPtrCliente()->setNumCuenta("0");
					matriz[i][j]->getPtrCliente()->setNumTel("0");
					matriz[i][j]->getPtrInfo()->setCantAdultos(0);
					matriz[i][j]->getPtrInfo()->setDiasEstancia(0);
					matriz[i][j]->getPtrInfo()->setHora(0);
					matriz[i][j]->getPtrInfo()->setCantNinnos(0);
					matriz[i][j]->getPtrInfo()->setTodoIncluido(0);
					return true;
				}
			}
		}
	}
	return false;
}



bool Contenedora::liberar(string IDCliente) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j]->getPtrCliente()->getIdCliente() == IDCliente) {
				delete matriz[i][j];
				matriz[i][j] = new Habitacion;
				return true;
			}
		}
	}
	return false;
}
