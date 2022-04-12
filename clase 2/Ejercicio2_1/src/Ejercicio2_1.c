/*
 ============================================================================
 Name        : Ejercicio2_1.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la aplicación con distintos valores.
Ejemplo 1:  3 - 5 - 7 - 9 - 1
Ejemplo 2:  2 - 1 - 8 -1 - 2
 * */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int bufferInt;
	int contador = 0;
	int promedio;
	int acumulador = 0;

	for(int i = 0; i < 5; i++) {
		printf("Ingrese el %d numero:", i+1);
		scanf("%i", &bufferInt);
		contador++;
		acumulador += bufferInt;
	};

	promedio = acumulador / contador;
	printf("El promedio es: %f", (float)promedio);
	puts("\n FIN DEL PROGRAMA");
	return EXIT_SUCCESS;
}
