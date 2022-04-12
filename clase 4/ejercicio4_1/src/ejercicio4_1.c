/*
 ============================================================================
 Name        : ejercicio4_1.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Ejercicio 4-1:
Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un número.
Por ejemplo:
5! = 5*4*3*2*1 = 120
*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int calcularFactorial(int num);
int pedirNumero(void);

int main(void) {
	setbuf(stdout, NULL);
	int bufferInt;
	int factorial;
	puts("=== INICIO PROGRAMA ===");

	bufferInt = pedirNumero();
	factorial = calcularFactorial(bufferInt);

	printf("\nel factorial de %d es: %d", bufferInt, factorial);
	printf("\n=== FIN PROGRAMA ===");
	return EXIT_SUCCESS;
}


int pedirNumero(void) {
	int bufferInt;
	printf("Por favor ingrese un número: ");
	scanf("%d", &bufferInt);
	return bufferInt;
}

int calcularFactorial(int num) {
	int acum = 1;
	for(int i = 0; i < num; i++) {
		acum *= i +1;
	}
	return acum;
}
