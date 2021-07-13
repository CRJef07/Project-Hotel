#include "Control.h"

void Control::menu() {//---------------------------INICIO METODO MENU----------------------------------------
	Contenedora cont1;
	string opc;
	setlocale(LC_ALL, "spanish");

	do {
		try {
			system("cls");
			cont1.ponerIDHab();
			cout << "\t\tBIENVENIDO AL HOTEL PURA VIDA" << endl;
			cout << "Por favor ingrese alguna de las siguientes opciones" << endl;
			//cout << "0 - Mostrar todas las habitaciones" << endl;
			cout << "1 - Habitaciones libres" << endl;
			cout << "2 - Habitaciones en mantenimiento" << endl;
			cout << "3 - Habitaciones ocupadas" << endl;
			cout << "4 - Reservar habitacion" << endl;
			cout << "5 - Liberar habitacion" << endl;
			cout << "6 - Cantidad de personas adultas" << endl;
			cout << "7 - Cantidad de niños" << endl;
			cout << "8 - Sub-Menu" << endl;
			cout << "9 - SALIR" << endl;
			//cout << "10 - Poner habitacion en mantenimiento" << endl;
			cout << "Opción digitada:  ";
			getline(cin, opc);

			if (opc != "0" && opc != "1" && opc != "2" && opc != "3" && opc != "4" && opc != "5" && opc != "6" && opc != "7" && opc != "8" && opc != "10" && opc != "11") {
				throw opc;
			}

			switch (stoi(opc)) {
			case 0:
				system("cls");
				cout << cont1.toStringMatriz() << endl;
				system("pause");
				break;

			case 1:
				cout << endl << "La cantidad de habitaciones libres es: " << cont1.habLibres() << endl;
				system("pause");
				break;

			case 2:
				cout << endl << "La cantidad de habitaciones en mantenimiento es: " << cont1.habMantenimiento() << endl;
				system("pause");
				break;

			case 3:
				cout << endl << "La cantidad de habitaciones ocupadas es: " << cont1.habOcupadas() << endl;
				system("pause");
				break;

			case 4:
				system("cls");
				reservar(cont1);
				system("pause");
				break;

			case 5:
				system("cls");
				liberar(cont1);
				system("pause");
				break;

			case 6:
				system("cls");
				cout << "La cantidad total de adultos en el hotel el dia de hoy es: " << cont1.cantAdultos() << endl;
				system("pause");
				break;

			case 7:
				system("cls");
				cout << "La cantidad total de niños en el hotel el dia de hoy es: " << cont1.cantMenores() << endl;
				system("pause");
				break;

			case 8:
				system("cls");
				subMenu(cont1);
				break;
			
				//no existe el case 9

			case 10:
				system("cls");
				cambiarMantenimiento(cont1);
				system("pause");
				break;

			case 11:
				system("cls");
				verEspecifica(cont1);
				system("pause");
				break;
			}
		}
		catch (string opc) {}
	//} while (true);
	} while (opc != "9");
}

void Control::reservar(Contenedora& cont1) {//---------- ---------- ---------- INICIO DEL MÉTODO ---------- ---------- ----------
	string ID = "", nombre = "", tipoPago = "", numeroCuenta = "";
	string tel = "";
	int cantAd = 0, cantNi = 0, cantDias = 0;
	bool incluido = false;
	string incluir = "";
	string IDHab = "";
	int CantHab = 0;
	int horaEntrada = 0;
	string salir = "";


	cout << "¿Cuántas personas van a ingresar a la habitacion?" << endl;
	cout << "Cantidad:  ";
	cin >> CantHab;

	while (CantHab < 1 || CantHab > 4) {
		system("cls");
		cout << "¿Cuántas personas van a ingresar a la habitacion?" << endl;
		cout << "Cantidad:  ";
		cin >> CantHab;
	}

	cout << endl << "Cantidad de adultos:  "; cin >> cantAd;
	cout << "\nCantidad de niños:  "; cin >> cantNi;

	while (CantHab != cantAd + cantNi) {
		system("cls");
		cout << "La cantidad de adultos y niños debe ser igual a la cantidad previamente ingresada" << endl << endl;
		cout << "Cantidad ingresada anteriormente: " << CantHab << endl << endl;
		cout << "Ingrese de nuevo los datos" << endl << endl;
		cout << "Cantidad de adultos:  "; cin >> cantAd;
		cout << "\nCantidad de niños:  "; cin >> cantNi;
		system("cls");
	}

	system("cls");
	cout << cont1.impremeCodigo() << endl;

	cout << "La cantidad de habitaciones libres es: " << cont1.habLibres() << endl << endl;

	cout << "¿Qué habitacion desea? "; cin >> IDHab;
	IDHab[0] = toupper(IDHab[0]);


	if (cont1.verificarHabitaciones(IDHab) == true) {//verifica si la habitacion existe
		cont1.cambiarEstado(IDHab);//CAMBIA EL ESTADO DE LA HABITACION
		system("cls");
		cout << "\t\tDatos del cliente:" << endl << endl;

		cout << "\nIdentificación:  ";
		cin.ignore();
		getline(cin, ID);

		cout << "\nNombre:  ";
		getline(cin, nombre);

		cout << "\nMétodo de pago:  ";
		getline(cin, tipoPago);

		cout << "\nSi su método de pago es con tarjeta, ingrese un 0 en el número de cuenta";
		cout << "\nNúmero cuenta:  ";
		getline(cin, numeroCuenta);

		cout << "\nNúmero teléfono:  ";
		getline(cin, tel);

		system("cls");
		cout << "\t\tDatos de la habitacion:" << endl << endl;

		cout << "\nCantidad de días:  "; cin >> cantDias;

		while (cantDias == 0) {
			cout << endl;
			cout << "\t\tERROR!!!" << endl;
			cout << "LA CANTIDAD DE DIAS NO PUEDE SER MENOR A 1" << endl;
			cout << "Digite de nuevo la cantidad de días:  "; cin >> cantDias;
		}
		cout << "\n¿Desea el servicio todo incluido?  " << endl;
		cout << "1 - SI " << endl;
		cout << "2 - NO " << endl;
		cout << "Opcion: ";

		cin.ignore();
		getline(cin, incluir);

		if (incluir == "1") {
			incluido = 1;
		}
		else if (incluir == "2") {
			incluido = 0;
		}
		else {
			system("cls");
			cout << endl << "Usted digitó una opcion no válida" << endl;
			cout << "La opcion se contará como SIN INCLUIR" << endl << endl;
		}

		if (incluido == 0) {
			cout << endl;
			horaEntrada = pedirHora(cont1);
			cout << endl;
		}

		Cliente* C1 = new Cliente(ID, nombre, tipoPago, numeroCuenta, tel);
		Informacion* Info1 = new Informacion(cantAd, cantNi, cantDias, incluido, horaEntrada);
		cont1.ingresarInfoyCliente(IDHab, C1, Info1);

		cont1.cambiarCant(IDHab, CantHab);
		cout << cont1.imprimeHab(IDHab) << endl;
	}
	else {
		system("cls");
		cout << "El ID ingresado no existe ó la habitación no está libre" << endl << endl;
		cout << "Por favor verifique el ID de la habitación" << endl << endl;
		cout << "\t\t¿Desea salir del menú para reservar?" << endl << endl;
		cout << "1 - NO" << endl << endl;
		cout << "2 - SI" << endl << endl;
		cout << "Opción ingresada:  ";

		cin.ignore();
		getline(cin, salir);
		system("cls");

		if (salir == "1") {
			reservar(cont1);
		}
	}
}//---------- ---------- ---------- FIN DEL MÉTODO ---------- ---------- ----------

void Control::liberar(Contenedora& cont1) {
	string id = " ";
	cout << "Favor ingrese el ID del cliente" << endl;
	cin >> id;
	if (cont1.liberar(id) == true) {
		cout << "Habitación eliminada de forma exitosa" << endl;
	}
	else {
		cout << "Error al eliminar la habitación" << endl;
	}
}

void Control::subMenu(Contenedora& cont1) {
	string opcionSubMenu;

	do {
		try {
			system("cls");
			cout << "Bienvenido al sub-menu para saber cuanto dinero recaudo el hotel el día de hoy" << endl;
			cout << "Por favor digite una opción" << endl;
			cout << "1 - Clientes con todo incluido" << endl;
			cout << "2 - Clientes sin todo incluido" << endl;
			cout << "3 - Todos los clientes" << endl;
			cout << "4 - SALIR DEL SUB-MENU" << endl;
			cout << "Opcion ingresada:  ";
			getline(cin, opcionSubMenu);

			if (opcionSubMenu != "1" && opcionSubMenu != "2" && opcionSubMenu != "3" && opcionSubMenu != "4") {
				throw opcionSubMenu;
			}

			switch (stoi(opcionSubMenu)) {
			case 1:
				cout << endl << "El monto de los clientes CON todo incluido es: ";
				cout << cont1.cobrarIncluido() << endl << endl;
				system("pause");
				break;

			case 2:
				cout << endl << "El monto de los clientes SIN todo incluido es: ";
				cout << cont1.cobrarNoIncluido() << endl << endl;
				system("pause");
				break;

			case 3:
				cout << endl << "El monto total recaudado es:  " << cont1.cobrarIncluido() + cont1.cobrarNoIncluido() << endl << endl;
				system("pause");
				break;

			case 4:
				break;//SALIR DEL SUBMENU

			default:
				system("cls");
				cout << "OPCION NO VALIDA!" << endl;
				system("pause");
				break;
			}
		}
		catch (string opc) {}
	} while (opcionSubMenu != "4");
}

int Control::pedirHora(Contenedora& cont1) {
	int hora = 0;
	cout << "Digite una hora de entrada en formato 24 hrs" << endl;
	cin >> hora;

	if (cont1.horaCorrecta(hora) == true) {
		return hora;//recursividad

	}
	system("cls");
	cout << "\t\tERROR AL INGRESAR LA HORA " << endl;
	pedirHora(cont1);

}

void Control::cambiarMantenimiento(Contenedora& cont1) {
	cout << "\t\tMENÚ MANTENIMIENTO " << endl << endl;
	cout << cont1.impremeCodigo() << endl << endl;
	string ID;
	cout << "¿Qué Habitación desea poner en mantenimiento? ";
	cin >> ID;
	ID[0] = toupper(ID[0]);
	if (cont1.mantenimiento(ID) == true) {
		cout << endl << "Habitacion puesta en mantenimiento exitosamente" << endl;
		cout << "El ID para liberar la habitación es: 'MANTENIMIENTO'" << endl << endl;
	}
	else {
		cout << "Habitacion no puesta en mantenimiento" << endl;
	}
}

void Control::verEspecifica(Contenedora& cont1) {
	cout << "\t\tMENÚ HABITACIÓN ESPECÍFICA " << endl << endl;
	cout << cont1.impremeCodigo() << endl << endl;
	string ID;
	cout << "¿Cuál habitación desea ver?   ";
	getline(cin, ID);
	ID[0] = toupper(ID[0]);
	cout << cont1.imprimeHab(ID) << endl;
}
