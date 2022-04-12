/*
 ============================================================================
 Name        : ejercicio1.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 * Un programa que pida un numero al usuario , despues pida una operacion (+ - * /)
y despues que pida otro numero. Segun la operacion ingresada, se llamara una funcion que ejecute
la operacion sumar(), restar(), multiplicar(),dividir().
y luego mostrar al usuario el resultado. El mostrar resultado NOOOO puede estar dentro de
las funciones que creen para hacer las operaciones. En la funcion dividir
 validar que no divida por cero
 */


#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int sumar(int num1, int num2);
int restar(int num1, int num2);
int multiplicar(int num1, int num2);
int dividir(int num1, int num2);
int pedirNumero(void);
char pedirOperacion(void);
void mostrarResultado(int resultado);


int main(void) {
	setbuf(stdout, NULL);
	printf("====INICIO DEL PROGRAMA====");
	int bandera = TRUE;
	int numero1;
	int numero2;
	char operando;
	int resultado;
	char pregunta;

	printf("\n Desea hacer una operacion? [s/n]: ");
	fflush(stdin);
	scanf("%c", &pregunta);

	if (pregunta == 's') {
		bandera = TRUE;
	} else {
		bandera = FALSE;
	}

	while(bandera) {
		numero1 = pedirNumero();
		operando = pedirOperacion();
		numero2 = pedirNumero();

		switch (operando) {
			case '+':
				resultado = sumar(numero1, numero2);
				mostrarResultado(resultado);
			break;
			case '-':
				resultado = restar(numero1, numero2);
				mostrarResultado(resultado);
			break;
			case '*':
				resultado = multiplicar(numero1, numero2);
				mostrarResultado(resultado);
			break;
			case '/':
				resultado = dividir(numero1, numero2);
				mostrarResultado(resultado);
			break;
			default:
				printf("\n Operando incorrecto, trate de nuevo");
			break;
		}

		printf("\n Desea hacer una operacion? [s/n]: ");
		fflush(stdin);
		scanf("%c", &pregunta);

		if (pregunta == 's') {
			bandera = TRUE;
		} else {
			bandera = FALSE;
		}
	}

	printf("\n ====FIN DEL PROGRAMA====");
	return EXIT_SUCCESS;
}

int sumar(int num1, int num2) {
	return num1 + num2;
}

int restar(int num1,int num2){
	return num2 - num1;
}

int multiplicar(int num1, int num2) {
	return num1 * num2;
}

int dividir(int num1, int num2) {
	if (num2 == 0) {
		printf("\nNo se puede dividir por cero");
		return 0;
	} else {
		return num1 / num2;
	}
}

int pedirNumero(void) {
	int bufferInt;
	printf("\nPor favor ingrese un número: ");
	scanf("%d", &bufferInt);
	return bufferInt;
}

char pedirOperacion(void) {
	char operando;
	printf("\nPor favor ingrese una operación: [+, -, *, /] ");
	fflush(stdin);
	scanf("%c", &operando);
	return operando;
}

void mostrarResultado(int resultado) {
	printf("\nEl resultado de la operacion es: %d", resultado);
}
