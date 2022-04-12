/*
 * utn.h
 *
 *  Created on: 7 abr 2022
 *      Author: Nicol�s Caruso
 */

#ifndef UTN_H_
#define UTN_H_

/// @brief verifica que el n�mero ingresado este dentro del rango descripto
/// @param pNumeroIngresado Puntero a variable donde se escribir� el valor
///  ingresado en el caso de ser correcto.
/// @param mensaje Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al
///  usuario datos por consola.
/// @param mensajeError Puntero a cadena de caracteres con mensaje de error
///  en el caso de que el dato ingresado no sea v�lido.
/// @param maximo Valor m�ximo admitido (inclusive)
/// @param minimo Valor m�nimo admitido (inclusive)
/// @param maximoDeReintentos Cantidad de veces que se le volver� a pedir al usuario
///  que ingrese un dato en caso de error.
/// @return retorna 0 para success y -1 si fallo
int UTN_getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,int maximo, int minimo, int maximoDeReintentos);


/// @brief verifica si la opcion elegida es s o n
///
/// @param pLetra -> puntero a variable donde se escribir� el valor ingresado si es correcto
/// @param maximoIntentos -> cantidad de reintentos permitidos
/// @return retorna 0 para success y -1 si fallo
int UTN_verificarSiNo(char * pLetra, int maximoIntentos);


#endif /* UTN_H_ */
