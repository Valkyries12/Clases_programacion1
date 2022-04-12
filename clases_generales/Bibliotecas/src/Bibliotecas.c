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

#include "UTN.h"


int main(void) {
	setbuf(stdout, NULL);
	puts("!!!probando!!!"); /* prints !!!Hello World!!! */
	char pLetra;
	int verificaFuncion;

	verificaFuncion = UTN_verificarSiNo(&pLetra, 2);
	printf("error es: %d", verificaFuncion);
	printf("pLetra es: %c", pLetra);
	return EXIT_SUCCESS;
}
