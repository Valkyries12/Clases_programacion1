/*
 ============================================================================
 Name        : Ejercicio2_3.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 2-3:
Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas,
 de cada persona debemos obtener los siguientes datos:
número de cliente,
estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
edad( solo mayores de edad, más de 17),
temperatura corporal (validar por favor)
y sexo ('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: el precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado "viudo" de más de 60 años.
b) el número de cliente y edad de la mujer soltera más joven.
c) cuánto sale el viaje total sin descuento.
d) si hay más del 50% de los pasajeros que tiene más de 60 años ,
 el precio final tiene un descuento del 25%, que solo mostramos si corresponde.
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

int main(void) {
	setbuf(stdout, NULL);

	int grupoPersonas;
	int precioPorPasajero = 600;
	//variables scanf
	int numeroCliente;
	char estadoCivil;
	int edad;
	float temperatura;
	char sexo;

	int cantidadViudosMayorSesenta = 0;
	int cantidadMayorSesenta = 0;
	int totalSinDescuento;
	float totalConDescuento;
	int numeroClienteSolteraMasJoven;
	int edadSolteraMasJoven;
	int flagSolteraMasJoven = TRUE;


	printf("Ingrese número de personas en el grupo: ");
	scanf("%d", &grupoPersonas);

	for (int i = 0; i < grupoPersonas; i++) {
		printf("\n Ingrese el número del cliente: ");
		scanf("%d", &numeroCliente);

		printf("\n Ingrese estado civi: s para soltero, c para casado o v para viudo ");
		scanf(" %c", &estadoCivil);
		//valido que solo sea c, s o v
		while(!(estadoCivil == 's' || estadoCivil == 'c' || estadoCivil == 'v')) {
			printf("\nPor favor ingrese un estado civil válido: s para soltero, c para casado o v para viudo ");
			scanf(" %c", &estadoCivil);
		};

		printf("\nIngrese la edad del pasajero ");
		scanf("%d", &edad);
		//valido que sea mayor de edad
		while(edad < 18) {
			printf("\nPor favor ingrese una edad válida ");
			scanf("%d", &edad);
		};

		printf("\nIngrese temperatura corporal del pasajero: ");
		scanf("%f", &temperatura);
		//valido que no tenga fiebre ni este muerto
		while(temperatura > 37 || temperatura < 34) {
			printf("Por favor ingresa una temperatura válida: ");
			scanf("%f", &temperatura);
		};

		printf("\nIngrese sexo del pasajero: f para femenino, m para masculino y o para no binario ");
		scanf(" %c", &sexo);
		//valido que solo se ingrese f, m u o
		while(!(sexo == 'f' || sexo == 'm' || sexo == 'o')) {
			printf("\nPor favor ingrese un sexo válido: f para femenino, m para masculino y o para no binario ");
			scanf(" %c", &sexo);
		};


		//verifico que sea mayor de 60
		if (edad > 60 ) {
			cantidadMayorSesenta += 1;
			//si es mayor de 60 y viudo
			if (estadoCivil == 'v') {
				cantidadViudosMayorSesenta += 1;
			};
		}
		//si es mujer
		if (sexo == 'f' && estadoCivil == 's') {
			if (flagSolteraMasJoven) {
				//seteo primera mujer como la mas joven
				numeroClienteSolteraMasJoven = numeroCliente;
				edadSolteraMasJoven = edad;
				flagSolteraMasJoven = FALSE;
			} else {
				//verifico si hay otra mas joven
				if (edadSolteraMasJoven < edad) {
					edadSolteraMasJoven = edad;
					numeroClienteSolteraMasJoven = numeroCliente;
				}
			}
		};
		//calculo el total sin descuento
		totalSinDescuento = grupoPersonas * precioPorPasajero;

	};

	printf("\n Cantidad de personas viudos y mayores de 60: %d", cantidadViudosMayorSesenta);
	printf("\n La mujer mas joven tiene %d años y es la numero %d", edadSolteraMasJoven, numeroClienteSolteraMasJoven);
	printf("\n El viaje sin descuento cuesta: %d", totalSinDescuento);
	//calculo si hay mas del 50% de pasajeros con mas de 60 años e imprimo
	if (cantidadMayorSesenta > (grupoPersonas / 2)) {
		totalConDescuento = totalSinDescuento * 0.75;
		printf("\n El viaje con descuento tiene un valor de: %.2f", totalConDescuento);
	}

	puts("\n FIN DEL PROGRAMA");

	return EXIT_SUCCESS;
}
