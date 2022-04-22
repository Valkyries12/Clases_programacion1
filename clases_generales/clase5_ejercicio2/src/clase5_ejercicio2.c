/*
 ============================================================================
 Name        : clase5_ejercicio2.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Ejercicio 5-2:
 * 	Pedir el ingreso de 10 números enteros entre -1000 y 1000.
 *  Determinar:Cantidad de positivos y negativos.
 *  Sumatoria de los pares.
 *  El mayor de los impares.
 *  Listado de los números ingresados.
 *  Listado de los números pares.
 *  Listado de los números de las posiciones impares.
 *  Se deberán utilizar funciones y arrays.
 * */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define LONGITUD 10



int main(void) {
	int numeros[LONGITUD];
	int cantidadPositivos;
	int cantidadNegativos;
	int sumatoriaPares;
	int imparMayor;
	int codigoError;

	cantidadPositivos = 0;
	cantidadNegativos = 0;
	sumatoriaPares = 0;


	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA === \n\n");

	//inicializo array
	codigoError = utn_inicializarArrayDeEnteros(numeros, LONGITUD, 0);
	utn_imprimirMensajes(codigoError, "\nArray inicializado con exito\n", "\nHa sucedido un error al inicializar el array\n");

	//cargo array de enteros
	for(int i = 0; i < LONGITUD; i++) {
		codigoError = utn_getInt(&numeros[i], "\nIngresa un numero entero: ", "\nNúmero incorrecto. Intenta nuevamente", 1001, -1001, 3);
	}
	utn_imprimirMensajes(codigoError, "\nArray cargado con exito", "\nHa sucedido un error al cargar el array");
	if (codigoError == 0) {
		//cuento cantidad positivos
		codigoError = utn_contarPositivos(numeros, &cantidadPositivos, LONGITUD);
		utn_imprimirMensajes(codigoError, "\nPositivos contados con exito", "\nHa sucedido un error al contaro positivos");
		printf("\nCantidad de positivos: %d", cantidadPositivos);

		//cuento cantidad negativos
		codigoError = utn_contarNegativos(numeros, &cantidadNegativos, LONGITUD);
		utn_imprimirMensajes(codigoError, "\nNegativos contados con exito", "\nHa sucedido un error al contar negativos");
		printf("\nCantidad de negativos: %d", cantidadNegativos);

		//sumo pares
		codigoError = utn_sumarEnterosParesDelArray(numeros, LONGITUD, &sumatoriaPares);
		utn_imprimirMensajes(codigoError, "\nSe han sumado los pares correctamente", "\nHa ocurrido un error al sumar");

		//mayor impar
		codigoError = utn_calcularEnteroMayorImpar(numeros, LONGITUD, &imparMayor);
		utn_imprimirMensajes(codigoError, "\nSe ha calculado el mayor con exito", "\nHa ocurrido un error calculando el mayor impar");
		if(codigoError == 0) {
			printf("\nel mayor impar es: %d", imparMayor);
		}

		//imprimo todos los valores del arr
		codigoError = utn_imprimirEnterosArray(numeros, LONGITUD);
		utn_imprimirMensajes(codigoError, "\nSe han impreso los valores", "\nHa ocurrido un error al imprimir los valores");

		//imprimo los numeros pares del arr
		codigoError = utn_imprimirEnterosParesArray(numeros, LONGITUD);
		utn_imprimirMensajes(codigoError, "\nSe han listado los valores pares", "\nHa ocurrido un error al listar los valores pares");

		//imprimo valores de las posiciones impares
		codigoError = utn_imprimirEnterosDePosicionesImparesArray(numeros, LONGITUD);
		utn_imprimirMensajes(codigoError, "\nSe han listado los valores de posiciones impares", "\nHa ocurrido un error al listar posiciones impares");
	} else {
		puts("\nOops ha sucedido un error =(\n");
	}

	puts("\n\n=== FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}







