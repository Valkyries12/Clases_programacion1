/*
 ============================================================================
 Name        : practica_parcial.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "asociado.h"

#define TRUE 1
#define FALSE 0
#define cantidadAsociados 3

int main(void) {
	int codigoError;
	int opcionMenu;
	int numeroAsociado;
	Asociado asociados[cantidadAsociados];

	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA ===");

	inicializarAsociado(asociados, cantidadAsociados);
	do {
		codigoError = utn_getInt(&opcionMenu, "\n1- Alta del asociado \n2- Modificar asociado \n3- Eliminar asociado \n4- Nueva llamada \n5- Asignar ambulancia \n6- Informar \n7- Salir \n\nIngrese una opción: ", "\nError. Reintente", 7, 1, 3);
		switch (opcionMenu) {
			case 1:
				puts("\n === Alta de asociado === \n");
				codigoError = cargarAsociado(asociados, cantidadAsociados);
				utn_imprimirMensajes(codigoError, "\nSe ha cargado un asociado con éxito\n", "\nHa ocurrido un error al cargar un asociado\n");
				break;
			case 2:
				if (hayAlgoCargado(asociados, cantidadAsociados)) {
					puts("\n === Modificar asociado === \n");
					numeroAsociado = utn_getInt(&numeroAsociado, "\nIngrese el número de asociado: ", "\nError al ingresar número de asociado o no existe", 99999, 757, 3);
					do {
						printf("\n\n ASOCIADO Nº %d\n\n", numeroAsociado);
						codigoError = modificarAsociado(asociados, numeroAsociado, opcionMenu, cantidadAsociados);
						utn_imprimirMensajes(codigoError, "\nSe ha modificado el asociado\n", "\nHa ocurrido un error al modificar el asociado");
					} while(opcionMenu != 3 && codigoError == 0);
				} else {
					puts("\nDebe haber al menos un asociado\n");
				}

				break;
			case 3:
				puts("\n === Eliminar asociado === \n");
				break;
			case 4:
				puts("\n === Nueva llamada === \n");
				break;
			case 5:
				puts("\n === Asignar ambulancia === \n");
				break;
			case 6:
				puts("\n === Informar === \n");
				break;
			default:
				break;
		}
	} while(opcionMenu != 7 && codigoError == 0);


	puts("\n\nSaliendo....\n\n");
	puts("=== FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}
