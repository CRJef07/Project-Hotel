#include "Cliente.h"


Cliente::Cliente() {
	//CONSTRUCTOR SIN PARÁMETROS
	idCliente = "";
	nombreCliente = "";
	formaPago = "";
	numCuenta = "";
	numTel = "";
}

Cliente::Cliente(string idCliente, string nombreCliente, string formaPago, string numCuenta, string numTel) {
	//CONSTRUCTOR CON PARÁMETROS
	this->idCliente = idCliente;
	this->nombreCliente = nombreCliente;
	this->formaPago = formaPago;
	this->numCuenta = numCuenta;
	this->numTel = numTel;
}

Cliente::~Cliente() {}

void Cliente::setIdCliente(string idCliente) {
	this->idCliente = idCliente;

}
void Cliente::setNombreCliente(string nombreCliente) {
	this->nombreCliente = nombreCliente;

}
void Cliente::setFormaPago(string metPago) {
	this->formaPago = formaPago;

}
void Cliente::setNumCuenta(string numCuenta) {
	this->numCuenta = numCuenta;

}
void Cliente::setNumTel(string numTel) {
	this->numTel = numTel;
}

string Cliente::getIdCliente() {
	return idCliente;
}
string Cliente::getNombreCliente() {
	return nombreCliente;
}
string Cliente::getFormaPago() {
	return formaPago;
}
string Cliente::getNumCuenta() {
	return numCuenta;
}
string Cliente::getNumTel() {
	return numTel;
}

string Cliente::toStringCliente() {
	setlocale(LC_ALL, "spanish");
	stringstream c;

	c << "La identificación del cliente es: " << idCliente << endl;
	c << "El nombre del cliente es: " << nombreCliente << endl;
	c << "La forma de pago del cliente es: " << formaPago << endl;

	if (numCuenta != "0") {
		c << "El número de cuenta del cliente es: " << numCuenta << endl;
	}

	c << "El número de teléfono del cliente es: " << numTel << endl;

	return c.str();
}
