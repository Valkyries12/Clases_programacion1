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
	int codigo;
	char palabra[] = {'2','3','\0' };
	setbuf(stdout, NULL);
	puts("!!!probando!!!"); /* prints !!!Hello World!!! */

	codigo = utn_esNumerico(palabra);
	printf("%d", codigo);

	return EXIT_SUCCESS;
};
