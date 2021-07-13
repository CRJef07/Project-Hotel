#ifndef CONTENEDORA_H
#define CONTENEDORA_H

#include "Habitacion.h"

class Contenedora {
public:
	Contenedora();
	~Contenedora();

	bool verificarHabitaciones(string);//------------SI

	void ponerIDHab();//------------SI

	string toStringMatriz();//------------SI

	string impremeCodigo();//------------SI

	string imprimeHab(string);//------------SI

	void ingresarInfoyCliente(string, Cliente*, Informacion*);//------------SI

	void cambiarEstado(string);//------------SI

	void cambiarCant(string, int);//------------SI

	int cobrarIncluido();//------------SI

	float cobrarNoIncluido();//------------SI

	bool horaCorrecta(int);//------------SI

	int habLibres();//------------SI

	int habMantenimiento();//------------SI

	int habOcupadas();//------------SI

	bool liberar(string);//------------SI

	int cantAdultos();//------------SI

	int cantMenores();//------------SI

	bool mantenimiento(string);



private:
	Habitacion* matriz[5][10];
	//filas [5] columnas [10]

	/*N es el n�mero de pisos y M es el n�mero de habitaciones por piso
	Adem�s donde cada celda de la matriz pueda tener un puntero que "pueda ver"
	o apuntar a un objeto de la clase Habitaci�n.*/
};
#endif
