#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <sstream>
#include <string>
#include "windows.h"
#include <locale.h> //setlocale(LC_ALL, "spanish");
using namespace std;

class Cliente {
public:
	Cliente();
	Cliente(string idCliente, string nombreCliente, string formaPago, string numCuenta, string numTel);
	~Cliente();

	void setIdCliente(string idCliente);
	void setNombreCliente(string nombreCliente);
	void setFormaPago(string metPago);
	void setNumCuenta(string numCuenta);
	void setNumTel(string numTel);

	string getIdCliente();
	string getNombreCliente();
	string getFormaPago();
	string getNumCuenta();
	string getNumTel();

	string toStringCliente();
private:
	string idCliente;
	string nombreCliente;
	string formaPago;
	string numCuenta;
	string numTel;
};
#endif
