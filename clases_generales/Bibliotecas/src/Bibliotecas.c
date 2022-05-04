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

	setbuf(stdout, NULL);
	puts("!!!probando!!!"); /* prints !!!Hello World!!! */

//	codigoError = utn_esNumerico(palabra);
	codigoError = utn_getDocumento(numeroDocumento, "\nIngrese dni: ", "\nHa sucedido un error", 3, 8);
	printf("%s", numeroDocumento);


	return EXIT_SUCCESS;
};
