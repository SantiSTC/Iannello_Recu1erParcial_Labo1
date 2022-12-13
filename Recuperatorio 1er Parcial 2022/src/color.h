/*
 * color.h
 *
 *  Created on: 12 dic. 2022
 *      Author: Santiago
 */

#ifndef COLOR_H_
#define COLOR_H_

#include "inputs.h"

typedef struct
{
	int id;
	char nombre[21];
}eColor;

void MostrarUnColor(eColor unColor);
int MostrarListaColores(eColor listaColores[], int sizeColores);
int PedirIdColor(eColor listaColores[], int sizeColores);

#endif /* COLOR_H_ */
