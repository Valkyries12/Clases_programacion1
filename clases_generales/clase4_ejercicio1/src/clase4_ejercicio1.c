/*
 ============================================================================
 Name        : clase4_ejercicio1.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * Nota:
Se deben hacer los ejercicios en orden. Al ingresar a cada punto de menú se debe indicar dónde estoy
 y al apretar una tecla salir del mismo. es decir que cada opción no tiene funcionalidad extra.
  En cualquier caso informar que está sucediendo: Ejemplo: "Primero se debe loguear".

A- Hacer el menú de un programa con las siguientes opciones: 1. Loguearse, 2. Comprar,
 3. Ver mis compras, 4. Vender, 5. Salir
B- Al menú anterior chequear que no pueda ingresar a ninguna opción si no se logueó
C- Al menú anterior chequear que no pueda ver sus compras, si no ingresó primero a comprar
 al menos una vez
D- Cuando se ingresa a la opción vender del menú, debe abrirse otro menú que
 contenga: 1. Vender 2. Hacer factura 3. Volver atrás
E- A lo anterior sumarle que haya compras para poder vender.
 (Si compré una vez y vendí una vez no puedo ingresar a vender).
F- Pasar las acciones de menú a funciones y llevarlas a una biblioteca
 * */


#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#define TRUE 1
#define FALSE 0


int UTN_loguear(int * isLogged, int intentosMaximos);

int main(void) {
	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA === \n");
	int opcionMenu;
	int respuesta;
	int	isLogged;
	int vecesCompradas;
	int cantidadCompras;
	cantidadCompras = 0;
	vecesCompradas = 0;
	isLogged = FALSE;

	do {
		respuesta = UTN_getInt(&opcionMenu,
					"1. Loguearse \n2. Comprar \n3. Ver mis compras \n4. Vender \n5. Salir \n\n Ingresa una opción: ",
					"\n\nOpción incorrecta. Por favor reintente nuevamente\n\n",
					5, 1, 3);

		if (respuesta == 0) {
			switch (opcionMenu) {
				case 1:
					UTN_loguear(&isLogged, 3);
					break;
				case 2:
					if (isLogged) {
						puts("*** COMPRAS ***\n");
						vecesCompradas++;
						cantidadCompras++;
					} else {
						puts("Necesitas loguearte primero\n");

					}
					break;
				case 3:
					if (!isLogged) {
						puts("Necesitas loguearte primero\n");
					} else {
						if (vecesCompradas == 0) {
							puts("Debes comprar algo para poder visualizar tus compras\n");
						} else {
							puts("*** VER TUS COMPRAS ***\n");
						}
					}
					break;
				case 4:
					if (!isLogged) {
						puts("Necesitas loguearte primero\n");
					} else {
						if (cantidadCompras == 0) {
							puts("\n Debes tener al menos una compra\n");
						} else {
							respuesta = UTN_getInt(&opcionMenu,
											"1. Vender \n2. Hacer factura \n3. Volver atras \n\n Ingresa una opción: ",
											"\n\nOpción incorrecta. Por favor reintente nuevamente\n\n",
											3, 1, 3);
							if (respuesta == 0) {
								switch (opcionMenu) {
									case 1:
										puts("\n *** VENDER ***\n");
										cantidadCompras --;

										break;
									case 2:
										puts("\n *** HACER FACTURA ***\n");
										break;
									case 3:
										puts("\n Volviendo al menu principal... \n");
										break;
									default:
										break;
								}
							}
						}
					}
					break;
				case 5:
					puts("Saliendo del sistema...\n");
					vecesCompradas = 0;
					isLogged = FALSE;
					break;
				default:

					break;
				}
		}
	} while(opcionMenu != 5);



	puts("\n=== FIN DEL PROGRAMA ===");

	return EXIT_SUCCESS;
}




