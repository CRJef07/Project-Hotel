#ifndef INFORMACION_H
#define INFORMACION_H

#include <iostream>
#include <sstream>
#include <string>
#include "windows.h"
#include <locale.h>

using namespace std;

class Informacion {
public:
	Informacion();
	Informacion(int cantAdultos, int cantNinnos, int diasEstancia, bool todoIncluido, int hora);
	~Informacion();

	//void setCantAdultos(const int &cantAdultos);
	void setCantAdultos(int cantAdultos);
	void setCantNinnos(int cantNinnos);
	void setDiasEstancia(int diasEstancia);
	void setTodoIncluido(bool todoIncluido);
	void setHora(int hora);

	//const int & getCantAdultos() const;
	int getCantAdultos();
	int getCantNinnos();
	int getDiasEstancia();
	bool getTodoIncluido();
	int getHora();

	string toStringInfo();
private:
	int cantAdultos;
	int cantNinnos;
	int diasEstancia;
	bool todoIncluido;
	int hora;
};
#endif
