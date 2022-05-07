/*
 * asociado.h
 *
 *  Created on: 5 may 2022
 *      Author: Nicolás Caruso
 */

#ifndef ASOCIADO_H_
#define ASOCIADO_H_
#define TRUE 1
#define FALSE 0

typedef struct {
	int idAsociado;
	int numeroDocumento;
	char nombre[50];
	char apellido[50];
	int edad;
	int isEmpty;
}Asociado;


/// @brief  Inicializa cada asociado del array. Setea isEmpty en FALSE
///
/// @param arr -> array de asociados
/// @param len -> longitud del array
/// @return Retorna (0) en caso de exito, (-1) en caso de error
int inicializarAsociado(Asociado arr[], int len);


/// @brief Busca el indice del primer asociado encontrado que tenga la propiedad isEmpty en TRUE
///
/// @param arr -> array de asociados
/// @param len -> longitud del array
/// @return retorna el indice del asociado en caso de encontrarlo. Si no (-1)
int buscarEspacioLibre(Asociado arr[], int len);


/// @brief Busca el indice del asociado mediante un id
///
/// @param arr -> array de asociados
/// @param id -> id del asociado
/// @param len -> longitud del array
/// @return -> En caso de encontrarlo devuelve el indice, en caso de no encontrarlo (-1)
int buscarIndicePorId(Asociado arr[], int id, int len);


/// @brief Carga un asociado al array
///
/// @param arr -> array de asociados
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int cargarAsociado(Asociado arr[], int len);


/// @brief Elimina un asociado del array
///
/// @param arr -> array de asociados
/// @param id -> id del asociado a eliminar
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int eliminarAsociado(Asociado arr[], int id, int len);


/// @brief Modifica nombre o apellido del asociado
///
/// @param arr -> array de asociados
/// @param id ->id del asociado a modificar
/// @param opcionMenu -> opcion a modificar
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int modificarAsociado(Asociado arr[], int id, int opcionMenu, int len);


/// @brief Incrementa el id por un, lo hace autoincremental
///
int incrementarId(void);

#endif /* ASOCIADO_H_ */
