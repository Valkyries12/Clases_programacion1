/*
 ============================================================================
 Name        : parcialito.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int devolverNumero(int * num1, int* num2);

int main(void) {
	int menor;
	int num1;
	int num2;
	num1 = 5;
	num2 = 10;
	menor = devolverNumero(&num1, &num2);
	return EXIT_SUCCESS;
}

int devolverNumero(int *num1, int* num2) {
	int auxNum;
	int menor;
	if (num1 > num2) {
		auxNum = *num1;
		*num1 = auxNum;
	} else {
		menor = num2;
	}
	return menor;
}

