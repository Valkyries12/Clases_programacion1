/*
 ============================================================================
 Name        : ejercicio_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 b-Entrada/salida
Pedir el sueldo al usuario. Sumarle un 10% e informarle cu�l ser� su sueldo con aumento.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int sueldo;

	printf("Por favor ingrese su sueldo: ");
	scanf("%d", &sueldo);

	sueldo = sueldo * 1.10;

	printf("El sueldo con un 10 por ciento de aumento es %d", sueldo); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
