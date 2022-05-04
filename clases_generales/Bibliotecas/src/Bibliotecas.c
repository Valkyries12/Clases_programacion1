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
	int codigoError;
	char palabra[24];
	int numero;
	char letra;

	setbuf(stdout, NULL);
	puts("!!!probando!!!"); /* prints !!!Hello World!!! */

//	codigoError = utn_esNumerico(palabra);
	codigoError = utn_getString(palabra, "\nIngrese una palabra: ", "\n error", 3, 24);
	printf("%s", palabra);


	return EXIT_SUCCESS;
};
