/*
 * utn.c
 *
 *  Created on: 14 abr 2022
 *      Author: Nicolás Caruso
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define TRUE 1
#define FALSE 0

int utn_getInt(int * pNumeroIngresado, char * mensaje, char * mensajeError, int maximo, int minimo, int maximoDeReintentos){

	int auxNumeroIngresado;
	int codigoError;
	codigoError = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			maximoDeReintentos--;
			printf("%s", mensaje);
			if(scanf("%d", &auxNumeroIngresado) == 1 && auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo) {
				*pNumeroIngresado = auxNumeroIngresado;
				codigoError = 0;
				break;

			} else{
				printf("%s", mensajeError);
			}
			fflush(stdin);

		}while(maximoDeReintentos > 0);
	}

	return codigoError;
}



int utn_getFloat(float * pNumeroIngresado, char * mensaje, char * mensajeError, float maximo, float minimo, int maximoDeReintentos){

	float auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%f", &auxNumeroIngresado);
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

int utn_getCaracter(char * pCaracterIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos){

	char buffer;
	int retorno;
	retorno = -1;

	if(pCaracterIngresado != NULL && mensaje != NULL && mensajeError != NULL &&  maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &buffer);

			maximoDeReintentos--;

			if(sizeof(buffer) >= minimo && sizeof(buffer) <= maximo){
						*pCaracterIngresado = buffer;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}


int utn_loguear(int * pIsLogged, int intentosMaximos) {
	char usuario;
	char contrasenia;
	int auxIsLogged;
	int codigoError;
	int intentos;
	intentos = 0;
	codigoError = -1;

	if (pIsLogged != NULL && intentosMaximos > 1) {
		printf("\n === LOGIN ===");
		while(intentos < intentosMaximos) {
			if (*pIsLogged) {
					printf("\n Usted se encuentra logueado\n");
					intentos = intentosMaximos;
					codigoError = 0;
			} else {
				printf("\nIngrese usuario: ");
				fflush(stdin);
				scanf("%c", &usuario);

				printf("\nIngrese contrasenia: ");
				fflush(stdin);
				scanf("%c", &contrasenia);

			}

			if (usuario == 'q' && contrasenia == 'q') {
				auxIsLogged = TRUE;
				printf("\n Bienvenido al sistema \n\n");
				*pIsLogged = auxIsLogged;
				intentos = intentosMaximos;
				codigoError = 0;
			} else {
				auxIsLogged = FALSE;
				*pIsLogged = auxIsLogged;
				intentos++;
				printf("\n Datos incorrectos. \n");
			}
		}
	}


	return codigoError;

}


int utn_hacerDescuento(float monto, int descuento, float * pValorFinal) {
	int codigoError;
	float auxPValorFinal;
	float resultado;
	codigoError = -1;

	if (pValorFinal != NULL && descuento > 0 && monto > 0) {
		resultado = (monto * descuento) / 100;
		resultado = monto - resultado;
		auxPValorFinal = resultado;
		* pValorFinal = auxPValorFinal;
		codigoError = 0;
	}

	return codigoError;
}


int utn_sumarInteres(float monto, int interes, float * pValorFinal) {
	int codigoError;
	float auxPValorFinal;
	float resultado;
	codigoError = -1;

	if (pValorFinal != NULL && interes > 0 && monto > 0) {
		resultado = (monto * interes) / 100;
		resultado = monto + resultado;
		auxPValorFinal = resultado;
		* pValorFinal = auxPValorFinal;
		codigoError = 0;
	}


	return codigoError;
}


void utn_verificarSiHayError(int respuesta, int * pHayError) {
	int auxRespuesta;
	auxRespuesta = respuesta;
	* pHayError = auxRespuesta;


}


void utn_imprimirMensajes(int  hayError, char * mensaje, char * mensajeError) {
	if (mensaje != NULL && mensajeError != NULL) {
		if (hayError == 0) {
			printf("%s", mensaje);
		} else {
			if (hayError == -1)
			printf("%s", mensajeError);
		}
	}

}


int utn_calcularAPrecioBitcoin(float monto, float precioBitcoin, float * pValorFinal) {
	int codigoError;
	float resultado;
	float auxPValorFinal;

	codigoError = -1;

	if ( pValorFinal != NULL && monto > 0 && precioBitcoin > 0) {
		resultado = monto / precioBitcoin;
		auxPValorFinal = resultado;
		* pValorFinal = auxPValorFinal;
		codigoError = 0;
	}


	return codigoError;

}


int utn_calcularPrecioPorKilometro(int kilometro, float precio, float * pValorFinal) {
	int codigoError;
	float resultado;
	float auxPValorFinal;

	codigoError = -1;

	if (pValorFinal != NULL && kilometro > 349 && precio > 5099.26) {
		resultado = precio / kilometro;
		auxPValorFinal = resultado;
		* pValorFinal = auxPValorFinal;
		codigoError = 0;
	}


	return codigoError;
}



int utn_contarPositivos(int arr[], int * cantidadPositivos, int longitudArray) {
	int contador;
	int codigoError;
	contador = 0;
	codigoError = -1;

	if(arr != NULL && cantidadPositivos != NULL && longitudArray > 1) {
		for(int i = 0; i < longitudArray; i++) {
			if(arr[i] > 0) {
				contador++;
			}
		}
		codigoError = 0;
	}

	if(codigoError == 0) {
		* cantidadPositivos = contador;
	}

	return codigoError;
}

int utn_contarNegativos(int arr[], int * cantidadNegativos, int longitudArray) {
	int contador;
	int codigoError;
	contador = 0;
	codigoError = -1;

	if(arr != NULL && cantidadNegativos != NULL && longitudArray > 1) {
		for(int i = 0; i < longitudArray; i++) {
			if(arr[i] < 0) {
				contador++;
			}
		}
		codigoError = 0;
	}

	if(codigoError == 0) {
		* cantidadNegativos = contador;
	}

	return codigoError;
}


int utn_inicializarArrayDeEnteros(int arr[], int len, int valorInicial) {
	int codigoError;
	codigoError = -1;

	if (len > 0) {
		for(int i = 0; i < len ; i++) {
			arr[i] = valorInicial;
		}
		codigoError = 0;
	}

	return codigoError;
}



int utn_sumarEnterosParesDelArray(int arr[], int len, int * resultadoSuma) {
	int codigoError;
	int resultado;

	resultado = 0;
	codigoError = -1;
	if (arr != NULL  && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i] % 2 == 0) {
				resultado += arr[i];
			}
		}
		* resultadoSuma = resultado;
		codigoError = 0;
	}


	return codigoError;
}



int utn_calcularEnteroMayorImpar(int arr[], int len, int * mayorImpar) {
	int codigoError;
	int mayor;

	mayor = arr[0];
	codigoError = -1;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i] >= mayor) {
				mayor = arr[i];
			}
		}

		* mayorImpar = mayor;
		codigoError = 0;
	}


	return codigoError;
}


int utn_imprimirEnterosArray(int arr[], int len) {
	int codigoError;

	codigoError = -1;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			printf("\n%d", arr[i]);
		}
		codigoError = 0;
	}


	return codigoError;
}



int utn_imprimirEnterosParesArray(int arr[], int len) {
	int codigoError;

	codigoError = -1;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i] % 2 == 0) {
				printf("\n%d", arr[i]);
			}
		}
		codigoError = 0;
	}

	return codigoError;
}



int utn_imprimirEnterosDePosicionesImparesArray(int arr[],int len) {
	int codigoError;

	codigoError = -1;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (i % 2 != 0) {
				printf("\n%d", arr[i]);
			}
		}
		codigoError = 0;
	}

	return codigoError;
}


int utn_cargarEnteroEnIndiceAleatorio(int arr[], int len, int valor , int indice) {
	int codigoError;

	codigoError = -1;

	if (arr != NULL && len > 0 && indice > -1) {
		if (arr[indice] > -1) {
			arr[indice] = valor;
			codigoError = 0;
		}

	}

	return codigoError;

}


int utn_calcularMenorEntero(int arr[], int len, int * pMenor, char tipo) {
	int codigoError;
	int menor;
	int bandera;

	codigoError = -1;
	menor = arr[0];
	bandera = FALSE;

	if (arr != NULL && len > 0 && pMenor != NULL) {
		for(int i = 0; i < len; i++) {
			switch (tipo) {
				case '+':
					if (arr[i] >= 0 && arr[i] <= menor) {
						menor = arr[i];
						if (!bandera) {
							bandera = TRUE;
						}
					}
					break;
				case '-':
					if (arr[i] < 0 && arr[i] <= menor) {
						menor = arr[i];
						if (!bandera) {
							bandera = TRUE;
						}
					}
					break;
				case '=':
					if (arr[i] <= menor) {
						menor = arr[i];
						if (!bandera) {
							bandera = TRUE;
						}
					}
					break;
				default:
					puts("\nTipo operador inválido, solo + - =");
					break;
			}
		}
		if (bandera) {
			*pMenor = menor;
			codigoError = 0;
		}
	}

	return codigoError;
}



int utn_calcularMayorEntero(int arr[], int len, int * pMayor, char tipo) {
	int codigoError;
	int mayor;
	int bandera;

	codigoError = -1;
	mayor = arr[0];
	bandera = FALSE;

	if (arr != NULL && len > 0 && pMayor != NULL) {
		for(int i = 0; i < len; i++) {
			switch (tipo) {
				case '+':
					if (arr[i] >= 0 && arr[i] >= mayor) {
						mayor = arr[i];
						if (!bandera) {
							bandera = TRUE;
						}
					}
					break;
				case '-':
					if (arr[i] < 0 && arr[i] >= mayor) {
						mayor = arr[i];
						if (!bandera) {
							bandera = TRUE;
						}
					}
					break;
				case '=':
					if (arr[i] >= mayor) {
						mayor = arr[i];
						if (!bandera) {
							bandera = TRUE;
						}
					}
					break;
				default:
					puts("\nTipo operador inválido, solo + - =");
					break;
			}
		}
		if (bandera) {
			*pMayor = mayor;
			codigoError = 0;
		}
	}

	return codigoError;
}



int utn_ordenarArrayMenorAMayor(int arr[], int len) {
	int codigoError;
	int estaOrdenado;
	int aux;

	codigoError = -1;


	if (arr != NULL && len > 0) {

		do{
			estaOrdenado = TRUE;
			len--;
			for(int i = 0; i < len; i++) {
				if (arr[i] > arr[i+1]){
					aux = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = aux;
					estaOrdenado = FALSE;
				}
			}
		} while(!estaOrdenado);
		codigoError = 0;
	}


	return codigoError;
}



int utn_ordenarArrayMayorAMenor(int arr[], int len) {
	int codigoError;
	int estaOrdenado;
	int aux;

	codigoError = -1;


	if (arr != NULL && len > 0) {

		do{
			estaOrdenado = TRUE;
			len--;
			for(int i = 0; i < len; i++) {
				if (arr[i] < arr[i+1]){
					aux = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = aux;
					estaOrdenado = FALSE;
				}
			}
		} while(!estaOrdenado);
		codigoError = 0;
	}


	return codigoError;
}



int utn_imprimirString(char arr[]) {
	int codigoError;
	int i;

	i = 0;
	codigoError = -1;
	if (arr != NULL) {
		while(arr[i] != '\0') {
			printf("%c", arr[i]);
			i++;
		}
		codigoError = 0;
	}


	return codigoError;
}


int utn_tieneSoloLetras(char arr[]) {
	int hasLetters;
	int i;

	i = 0;
	hasLetters = TRUE;
	if (arr != NULL) {
		while(arr[i] != '\0') {
			if(!((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z'))) {
				hasLetters = FALSE;
				break;
			}
			i++;
		}
	}

	return hasLetters;
}



int utn_esNumerico(char arr[]){
	int hasNumbers;
	int i;

	i = 0;
	hasNumbers = TRUE;
	if (arr != NULL) {
		while(arr[i] != '\0') {
			if (arr[i] < '0' || arr[i] > '9') {
				hasNumbers = FALSE;
				break;
			}
			i++;
		}
	}

	return hasNumbers;
}

