/*
 ============================================================================
 Name        : 3_1.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Ejercicio 3-1:
Crear una función que permita determinar si un número es par o no.
 La función retorna 1 en caso afirmativo y 0 en caso contrario. Probar en el main.
 * */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int esPar(int num);
int pedirNumero(void);

int main(void) {
	int numero;
	int esNumeroPar;

	system("cls");
	setbuf(stdout, NULL);
	puts("\n=== INICIO DEL PROGRAMA ===");

	numero = pedirNumero();
	esNumeroPar = esPar(numero);

	if (esNumeroPar) {
		puts("\n Es número par!!");
	} else {
		puts("\n Es número impar!!");
	}

	return EXIT_SUCCESS;
}

int esPar(int num) {
	int esNumeroPar;
	if (num % 2 == 0) {
		esNumeroPar = TRUE;
	} else {
		esNumeroPar = FALSE;
	}
	return esNumeroPar;
}

int pedirNumero(void) {
	int bufferInt;
	printf("\n Por favor ingrese un número: ");
	scanf("%d", &bufferInt);
	return bufferInt;
}
