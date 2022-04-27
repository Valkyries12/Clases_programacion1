/*
 ============================================================================
 Name        : clase5_ejercicio3.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Ejercicio 5-3:Realizar un programa que permita el ingreso de 10 números enteros distintos de cero.
 *  La carga deberá ser aleatoria (todos los elementos se inicializarán en cero por default.
 *  Determinar el promedio de los positivos,
 *   y del menor de los negativos la suma de los antecesores.
 *  Utilizar funciones y arrays.
 * */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "operaciones_aritmeticas.h"

#define CANTIDAD_NUMEROS 10
#define TRUE 1
#define FALSE 0

int main(void) {
	int numeros[CANTIDAD_NUMEROS];
	int codigoError;
	char respuestaUsuario;
	int respuestaIndice;
	int respuestaValor;
	int promedio;
	int menorEnteroNegativo;
	int sumaAntecesores;

	sumaAntecesores = 0;

	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA ===\n");

	// inicializo array
	codigoError = utn_inicializarArrayDeEnteros(numeros, CANTIDAD_NUMEROS, 0);
	utn_imprimirMensajes(codigoError, "\n Se ha inicializado el array correctamente", "\nHa ocurrido un error al inicializar el array");

	// cargo indices aleatorios


	do {
		//respuesta usuario s/n
		codigoError = utn_getCaracter(&respuestaUsuario, "\nDesea seguir? s/n: ", "\nRespuesta incorrecta reintente", 1 , 1, 3);
		utn_imprimirMensajes(codigoError, "\nSe ha registrado la respuesta", "\nHa ocurrido un error en la respuesta");
		//respuesta valor
		if (respuestaUsuario == 's') {
			codigoError = utn_getInt(&respuestaValor, "\nIngrese un valor: ", "\nHa ocurrido un error", 1000, -1000, 3);
			utn_imprimirMensajes(codigoError, "\nValor correcto", "\nHa ocuurrido un error con el valor");
			// respuesta indice
			codigoError = utn_getInt(&respuestaIndice, "\nIngrese posicion: ", "\nHa ocurrido un error", CANTIDAD_NUMEROS, 0, 3);
			utn_imprimirMensajes(codigoError, "\nIndice correcto", "\nHa ocurrido un error seleccionando posicion");
			if (codigoError == -1) {
				break;
			}
			codigoError = utn_cargarEnteroEnIndiceAleatorio(numeros, CANTIDAD_NUMEROS, respuestaValor, respuestaIndice);
			utn_imprimirMensajes(codigoError, "\nSe ha hecho una carga aleatoria", "\nHa sucedido un error al hacer carga aleatoria");
			if (codigoError == -1) {
				break;
			}
		}

	} while(respuestaUsuario == 's');

	//calculo promedio positivos
	codigoError = promedioDeEnteros(numeros, &promedio, CANTIDAD_NUMEROS, '+');
	utn_imprimirMensajes(codigoError, "\nSe ha calculado el promedio", "\nHa sucedido un error al calcular el promedio");
	printf("\n\nEl promedio de positivos es: %d", promedio);

	//calculo menor entero negativo
	codigoError = utn_calcularMenorEntero(numeros, CANTIDAD_NUMEROS, &menorEnteroNegativo, '-');
	utn_imprimirMensajes(codigoError, "\nSe ha calculado el menor", "\nHa sucedido un error al calcular el menor");
	printf("\n\nEl menor negativo es: %d", menorEnteroNegativo);

	//suma antecesores del menor negativo
	for(int i = menorEnteroNegativo; i < 0; i++ ) {
		sumaAntecesores += i;
	}
	printf("\n\nLos antecesores del menor negativo es: %d", sumaAntecesores);

	utn_imprimirEnterosArray(numeros, CANTIDAD_NUMEROS);

	puts("\n=== FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}
