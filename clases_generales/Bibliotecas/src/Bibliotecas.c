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
	char tel[8];
	char numeroDocumento[8];
	char mail[250];
	char numerof[] = ".22";

	setbuf(stdout, NULL);
	puts("!!!probando!!!"); /* prints !!!Hello World!!! */
	codigoError = utn_esNumerico(numerof);
//	codigoError = utn_esNumerico(palabra);
//	codigoError = utn_getFloat(&numerof, "\nIngrese una temp: ", "\nHa ocurrido un error", 70, -20, 3);
	printf("%d", codigoError);


	return EXIT_SUCCESS;
};
