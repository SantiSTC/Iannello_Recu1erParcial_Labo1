/*
 * servicio.h
 *
 *  Created on: 12 dic. 2022
 *      Author: Santiago
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

#include "inputs.h"

typedef struct
{
	int id;
	char descripcion[26];
	float precio;
}eServicio;

void MostrarUnServicio(eServicio unServicio);
int MostrarListaServicios(eServicio listaeServicios[], int sizeServicios);
int PedirIdServicios(eServicio listaServicios[], int sizeServicios);

#endif /* SERVICIO_H_ */
