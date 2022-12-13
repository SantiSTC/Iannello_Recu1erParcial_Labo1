/*
 * trabajo.h
 *
 *  Created on: 12 dic. 2022
 *      Author: Santiago
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

#include "inputs.h"

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	int idMoto;
	int idServicio;
	eFecha fecha;
	int estado;
}eTrabajo;

int BuscarEspacioTrabajos(eTrabajo listaTrabajos[], int sizeTrabajos);
int ObtenerIDTrabajos();


#endif /* TRABAJO_H_ */
