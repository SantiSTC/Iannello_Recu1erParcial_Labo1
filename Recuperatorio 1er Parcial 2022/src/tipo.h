/*
 * tipo.h
 *
 *  Created on: 12 dic. 2022
 *      Author: Santiago
 */

#ifndef TIPO_H_
#define TIPO_H_

#include "inputs.h"

typedef struct
{
	int id;
	char descripcion[21];
}eTipo;

void MostrarUnTipo(eTipo unTipo);
int MostrarListaTipos(eTipo listaTipos[], int sizeTipos);
int PedirIdTipo(eTipo listaTipos[], int sizeTipos);

#endif /* TIPO_H_ */
