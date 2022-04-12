/*
 ============================================================================
 Name        : a_funciones.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * a-Funciones
- Limpie la pantalla
- Asigne a la variable numero1 un valor solicitado al usuario
- Valide el mismo entre 10 y 100
- Realice un descuento del 5% a dicho valor a través de una función
 llamada realizarDescuento()
- Muestre el resultado por pantalla
 * */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int pedirNumero(void);
int validarNumero(int num, int *direccionDeNum);
void mostrarSiHayError(int error);
float realizarDescuento(int num);

int main(void) {
	int numero;
	int error;
	float numeroConDescuento;

	system("cls");
	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA ===");

	numero = pedirNumero();
	error = validarNumero(numero, &numero);
	mostrarSiHayError(error);
	if (!error) {
		numeroConDescuento = realizarDescuento(numero);
		printf("\nEl número con 5 por ciento  de descuento es: %.2f", numeroConDescuento);
	}


	puts("\n\n=== FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}

int pedirNumero(void) {
	int bufferInt;
	printf("\nPor favor ingrese un número: ");
	scanf("%d", &bufferInt);
	return bufferInt;
}

int validarNumero(int num, int *direccionDeNum) {
	int hayError;
	if (*direccionDeNum > 9 && *direccionDeNum < 101) {
		*direccionDeNum = num;
		hayError = FALSE;
	} else {
		hayError = TRUE;
	}
	return hayError;
}

void mostrarSiHayError(int error) {
	if(error) {
		printf("\nHay error, el número es inválido");
	} else {
		printf("\nNúmero correcto");
	}
}

float realizarDescuento(int num) {
	float resultado;
	resultado = num * 0.95;
	return resultado;
}
