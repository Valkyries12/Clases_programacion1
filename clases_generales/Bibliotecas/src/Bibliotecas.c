/*
 ============================================================================
 Name        : Bibliotecas.c
 Author      : Nicol�s Caruso
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

	setbuf(stdout, NULL);
	puts("!!!probando!!!"); /* prints !!!Hello World!!! */

//	codigoError = utn_esNumerico(palabra);
	codigoError = utn_getMail(mail, "\nIngrese su mail: ", "\nHa ocurrido un error", 3);
	printf("%s", mail);


	return EXIT_SUCCESS;
};
