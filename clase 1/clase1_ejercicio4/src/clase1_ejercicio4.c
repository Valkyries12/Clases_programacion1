/*
 ============================================================================
 Name        : clase1_ejercicio4.c
 Author      : Nicol?s Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * d-Operadores Logicos
Aplicando el concepto de Operadores L?gicos con valores booleanos en el condicional:
Solicitar un n?mero al usuario
Informar si el mismo es par o impar.
 * */



#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numeroUsuario;

	printf("escriba un n?mero: ");
	scanf("%d", &numeroUsuario);

	if (numeroUsuario % 2 == 0) {
		printf("%d es par", numeroUsuario);
	} else {
		printf("%d es impar", numeroUsuario);
	}

	puts("\n Fin del programa");

	return EXIT_SUCCESS;
}
