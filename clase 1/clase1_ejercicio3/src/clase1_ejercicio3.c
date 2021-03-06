/*
 ============================================================================
 Name        : clase1_ejercicio3.c
 Author      : Nicol?s Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * c-Control de Flujo
Pedirle al usuario su edad y su estado civil ('c'-casado, 's'-soltero, 'v'-viudo, 'd'-divorciado)
Si ingresa una edad menor a 18 a?os y un estado civil distinto a "Soltero",
mostrar el siguiente mensaje: 'Es muy peque?o para NO ser soltero.'
 * */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int edadUsuario;
	char estadoCivil;

	printf("Por favor ingrese la edad: ");
	scanf("%d", &edadUsuario);

	printf("Por favor ingrese su estado civil [c-casado, s-soltero, v-viudo, d-divorciado] :");
	scanf(" %c", &estadoCivil);

	if (edadUsuario < 18 && estadoCivil != 's') {
		puts("\n Es muy peque?o para NO ser soltero");
	}

	puts("Programa terminado");
	return EXIT_SUCCESS;
}
