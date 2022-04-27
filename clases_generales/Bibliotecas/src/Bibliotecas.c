/*
 ============================================================================
 Name        : Bibliotecas.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "utn.h"


int main(void) {
	int numeros[6] = {10,5,1,45,21,56};
	setbuf(stdout, NULL);
	puts("!!!probando!!!"); /* prints !!!Hello World!!! */

	utn_ordenarArrayMenorAMayor(numeros, 6);
	utn_imprimirEnterosArray(numeros, 6);

	return EXIT_SUCCESS;
};
