/*
 * utn.c
 *
 *  Created on: 7 abr 2022
 *      Author: Nicolás Caruso
 */
#include <stdio.h>
#include <stdlib.h>

int UTN_getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos){

	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			maximoDeReintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}


int UTN_verificarSiNo(char * pLetra, int maximoIntentos) {
	char auxLetra;
	unsigned int intentos;
	int error;
	error = 0;
	intentos = 1;

	printf("Ingrese una opción... s/n: ");
	scanf("%c", &auxLetra);
	fflush(stdin);
	while(!(auxLetra == 's' || auxLetra == 'n') && intentos < maximoIntentos) {
		printf("Opción inválida. Por favor ingrese la opción correcta S/N: ");
		scanf("%c", &auxLetra);
		fflush(stdin);
		intentos ++;
		error = -1;
	}
	if (error == 0) {
		*pLetra = auxLetra;
	};

	return error;
}

