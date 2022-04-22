/*
 ============================================================================
 Name        : clase5_ejercicio1.c
 Author      : Nicol�s Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Ejercicio 5-1:Pedir el ingreso de 5 n�meros. Mostrarlos y calcular la sumatoria de los mismos.
 * */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA ===\n");
	int numeros[5];
	int suma;
	int longitudArr;
	int bufferInt;
	int codigoError;

	longitudArr = 5;
	suma = 0;

	for(int i = 0; i < longitudArr; i++) {
		codigoError = utn_getInt(&bufferInt, "Ingrese un n�mero entero: ", "Nu�mero incorrecto, intente nuevamente", 999, 1, 3);
		if (codigoError == 0) {
			numeros[i] = bufferInt;
		} else {
			puts("\n oops ha ocurrido un error \n");
		}
	}

	for(int i = 0; i < longitudArr; i++) {
		printf("\nEn el �ndice %d est� el n�mero %d", i, numeros[i]);
		suma += numeros[i];
	}

	printf("\nLa suma de todos los n�meros es: %d\n", suma);



	puts("\n\n=== FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}
