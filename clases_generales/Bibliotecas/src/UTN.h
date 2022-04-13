/*
 * utn.h
 *
 *  Created on: 7 abr 2022
 *      Author: Nicol�s Caruso
 */

#ifndef UTN_H_
#define UTN_H_

/// @brief Solicita un n�mero al usuario, lo valida, verifica y devuelve el resultado
///
/// @param pNumeroIngresado Puntero al resultado alli se dejara el numero ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado en caso de error
/// @param maximo Valor maximo aceptado
/// @param minimo Valor m�nimo aceptado
/// @param maximoDeReintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int UTN_getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,int maximo, int minimo, int maximoDeReintentos);

/// @brief Solicita una letra al usuario, lo valida, verifica y devuelve el resultado
///
/// @param pCaracterIngresado Puntero al resultado alli se dejara el caracter ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado en caso de error
/// @param maximo Valor maximo aceptado
/// @param minimo Valor m�nimo aceptado
/// @param maximoDeReintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int UTN_getCaracter(int * pCaracterIngresado,char * mensaje,char * mensajeError, int maximo, int minimo, int maximoDeReintentos);

/// @brief verifica si la opcion elegida es s o n
///
/// @param pLetra -> puntero a variable donde se escribir� el valor ingresado si es correcto
/// @param maximoIntentos -> cantidad de reintentos permitidos
/// @return retorna 0 para success y -1 si fallo
int UTN_verificarSiNo(char * pLetra, int maximoIntentos);


#endif /* UTN_H_ */
