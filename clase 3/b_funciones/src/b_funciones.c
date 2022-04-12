/*
 ============================================================================
 Name        : b_funciones.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * b-Funciones
- Limpie la pantalla
- Asigne a las variables numero1 y numero2 los valores solicitados al usuario
- Valide los mismos entre 10 y 100
- Asigne a la variable operacion el valor solicitado al usuario
- Valide el mismo 's'-sumar, 'r'-restar
- Realice la operación de dichos valores a través de una función
- Muestre el resultado por pantalla
 * */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int solicitarNumero(void);
int validarNumero(int num, int *direccionNum);
char pedirOperacion(void);
int realizarOperacion(int num1, int num2, char operando);

int main(void) {
	system("cls");
	setbuf(stdout, NULL);
	puts("\n === INICIO DEL PROGRAMA ===");

	int numero1;
	int numero2;
	int isInvalidNumero1;
	int isInvalidNumero2;
	char operacion;
	int resultado;

	numero1 = solicitarNumero();
	numero2 = solicitarNumero();
	isInvalidNumero1 = validarNumero(numero1, &numero1);
	isInvalidNumero2 = validarNumero(numero2, &numero2);
	printf("valid1 es: %d", isInvalidNumero1);
	printf("valid2 es: %d", isInvalidNumero2);

	if (isInvalidNumero1 || isInvalidNumero2) {
		printf("\n Uno de los números de inválido");
	} else {
		operacion = pedirOperacion();
		resultado = realizarOperacion(numero1, numero2, operacion);
		printf("\n EL resultado es: %d", resultado);
	}
	puts("\n === FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}


int solicitarNumero(void) {
	int bufferInt;
	printf("\n Por favor ingrese un número: ");
	scanf("%d", &bufferInt);
	return bufferInt;
}

int validarNumero(int num, int *direccionNum) {
	int hayError;
	if (*direccionNum > 9 && *direccionNum < 101) {
		*direccionNum = num;
		hayError = FALSE;
	} else {
		hayError = TRUE;
	}
	return hayError;
}

char pedirOperacion() {
	char operando;
	printf("\n Por favor ingresa un operando [s, r]: ");
	scanf("%c", &operando);
	fflush(stdin);
	printf("\n operando es: %c", operando);
	while(!(operando == 's' || operando == 'r')) {
		printf("\n Reingrese operando [s, r]: ");
		fflush(stdin);
		scanf("%c", &operando);
	}
	return operando;
}

int realizarOperacion(int num1, int num2, char operando) {
	int resultado;
	if (operando == 's') {
		resultado = num1 + num2;
	} else {
		resultado = num2 - num1;
	}
	return resultado;
}
