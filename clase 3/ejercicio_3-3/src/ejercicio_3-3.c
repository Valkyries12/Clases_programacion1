/*
 ============================================================================
 Name        : ejercicio_3-3.c
 Author      : Nicol�s Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Ejercicio 3-3:
Crear una funci�n que pida el ingreso de un entero y lo retorne.
 * */

#include <stdio.h>
#include <stdlib.h>

int pedirNumero(void);

int main(void) {
	int numero;

	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA ===");

	numero = pedirNumero();
	printf("El n�mero es: %d", numero);

	puts("\n\n === FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}

int pedirNumero() {
	int numero;
	printf("\n Por favor ingrese un n�mero: ");
	scanf("%d", &numero);
	return numero;
}
