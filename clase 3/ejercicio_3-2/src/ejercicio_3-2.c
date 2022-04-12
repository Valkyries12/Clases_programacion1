/*
 ============================================================================
 Name        : ejercicio_3-2.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Ejercicio 3-2:
Crear una función que muestre por pantalla
 el número flotante que recibe como parámetro.
 * */

#include <stdio.h>
#include <stdlib.h>

void mostrarFlotante(float numero);

int main(void) {
	system("cls");
	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA ===");

	mostrarFlotante(3.46);

	puts("\n === FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}

void mostrarFlotante(float numero) {
	printf("El número es: %.2f", numero);
}
