/*
 * asociado.c
 *
 *  Created on: 5 may 2022
 *      Author: Nicolás Caruso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asociado.h"
#include "utn.h"

#define TRUE 1
#define FALSE 0

int inicializarAsociado(Asociado arr[], int len) {
	int codigoError;

	codigoError = -1;
	if(arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			arr[i].isEmpty = 1;
		}
		codigoError = 0;
	}

	return codigoError;
}



int buscarEspacioLibre(Asociado arr[], int len) {
	int indice;

	indice = -1;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i].isEmpty == TRUE) {
				indice = i;
				break;
			}
		}
	}

	return indice;
}



int buscarIndicePorId(Asociado arr[], int id, int len) {
	int indice;

	indice = -1;
	if (arr != NULL && id > 0 && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i].idAsociado == id && arr[i].isEmpty == 0) {
				indice = i;
				break;
			} else {
				printf("\nNo se ha encontrado el asociado nº%d\n", id);
			}
		}
	}

	return indice;
}



int cargarAsociado(Asociado arr[], int len) {
	int codigoError;
	int indice;
	int numeroDocumento;
	int edad;

	codigoError = -1;
	if (arr != NULL && len > 0) {
		indice = buscarEspacioLibre(arr, len);
		if (indice != -1) {
			//pido los datos
			codigoError = utn_getDocumento(&numeroDocumento, "\nIngrese DNI: ", "\nEl documento debe tener 8 dígitos\n", 3);
			if (codigoError == 0) {
				codigoError = utn_getString(arr[indice].nombre, "\nIngrese nombre del asociado: ", "\nDatos inválidos o debe tener al menos 4 caracteres\n", 3, 4);
			}
			if (codigoError == 0) {
				codigoError = utn_getString(arr[indice].apellido, "\nIngrese apellido del asociado: ", "\nDatos inválidos o debe tener al menos 4 caracteres\n", 3, 4);
			}
			if (codigoError == 0) {
				codigoError = utn_getInt(&edad, "\nIngrese la edad del asociado: ", "\nHa sucedido un error al ingresar la edad\n", 100, 1, 3);
			}

			//asigno los datos
			if (codigoError == 0) {
				arr[indice].idAsociado = incrementarId();
//				puts("\nSe ha cargado un asociado\n");
			} else {
//				puts("\nOops ha sucedido un error inesperado =(\n");
				codigoError = -1;
			}

		} else {
			puts("\nNo se puede cargar más asociados\n");
		}
	}


	return codigoError;
}




int eliminarAsociado(Asociado arr[], int id, int len) {
	int codigoError;
	int indice;

	codigoError = -1;
	if (arr != NULL && id > 0 && len > 0) {
		indice = buscarIndicePorId(arr, id, len);
		if (indice != -1) {
			arr[indice].isEmpty = TRUE;
			codigoError = 0;
		}
	}

	return codigoError;
}



int modificarAsociado(Asociado arr[], int id, int opcionMenu, int len) {
	int codigoError;
	int indice;
	char nuevoNombre[50];
	char nuevoApellido[50];

	codigoError = -1;
	if (arr != NULL && id > 0 && opcionMenu > 0 && len > 0) {
		indice = buscarIndicePorId(arr, id, len);
		if (indice != -1) {
			switch (opcionMenu) {
				case 1:
					codigoError = utn_getString(nuevoNombre, "\nIngrese nuevo nombre: ", "\nHa sucedido un error al modificar el nombre\n", 3, 4);
					if (codigoError == 0) {
						strncpy(arr[indice].nombre, nuevoNombre, sizeof(nuevoNombre));
						puts("\nNombre modificado con éxito\n");
					}
					break;
				case 2:
					codigoError = utn_getString(nuevoApellido, "\nIngrese nuevo apellido: ", "\nHa sucedido un error al modificar el apellido\n", 3, 4);
					if (codigoError == 0) {
						strncpy(arr[indice].apellido, nuevoApellido, sizeof(nuevoApellido));
						puts("\nApellido modificado con éxito\n");
					}
					break;
				default:
					break;
			}
		}
	}

	return codigoError;
}


int hayAlgoCargado(Asociado arr[], int len) {
	int hayAlgo;

	hayAlgo = FALSE;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (!arr[i].isEmpty) {
				hayAlgo = TRUE;
				break;
			}
		}
	}

	return hayAlgo;
}


int incrementarId(void) {
	static int id = 756;
	id++;

	return id;
}


