/*
 ============================================================================
 Name        : Ejercicio2_2.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 */
/*
 * Ejercicio 2-2:
Ingresar 10 números enteros, distintos de cero.
Mostrar:Cantidad de pares e impares.
El menor número ingresado.
De los pares el mayor número ingresado.
Suma de los positivos.
Producto de los negativos.*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1;
#define FALSE 0;

int main(void) {
	setbuf(stdout, NULL);
	int bufferInt;
	int cantidadPares = 0;
	int cantidadImpares = 0;
	int menorNumero;
	int mayorNumeroPar;
	int sumaPositivos = 0;
	int productoNegativos = 1;
	int flagMinimo = TRUE;
	int flagMaximoPar = TRUE;

	for(int i = 0; i < 10; i++) {
		printf("Ingrese el %d número, debe ser distinto de cero: " , i+1);
		scanf("%d", &bufferInt);
		//Ingreso hasta que no sea 0
		while(bufferInt == 0) {
			printf("\n Por favor ingrese un número distinto a cero: ");
			scanf("%d", &bufferInt);
		};

		//cuenta si es par o impar
		if (bufferInt %2 == 0) {
			cantidadPares += 1;
			//agarro como maximo el primer par
			if (flagMaximoPar) {
				mayorNumeroPar = bufferInt;
				flagMaximoPar = FALSE;
			};
			//calculo el maximo par en cada iteracion
			if (bufferInt > mayorNumeroPar) {
				mayorNumeroPar = bufferInt;
			};
		} else {
			cantidadImpares += 1;
		};

		//tomo el primer numero como minimo
		if (flagMinimo) {
			menorNumero = bufferInt;
			flagMinimo = FALSE;
		};

		// calculo el minimo en cada iteracion
		if (bufferInt < menorNumero) {
			menorNumero = bufferInt;
		}

		//sumo positivos o multiplico negativos
		if (bufferInt > 0) {
			sumaPositivos += bufferInt;
		} else {
			productoNegativos *= bufferInt;
		};
	}


	printf("\n Cantidad de pares: %d", cantidadPares);
	printf("\n Cantidad de impares: %d", cantidadImpares);
	printf("\n Menor número ingresado: %d", menorNumero);
	printf("\n Mayor número par ingresado: %d", mayorNumeroPar);
	printf("\n Suma positivos: %d", sumaPositivos);
	printf("\n Producto negativos: %d", productoNegativos);

	puts("\n FIN DEL PROGRAMA");

	return EXIT_SUCCESS;
}
