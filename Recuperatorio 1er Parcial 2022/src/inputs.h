/*
 * inputs.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Santiago
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#define LIBRE 0
#define OCUPADO 1

int MostrarMenu();
int ElegirOpcion(int max, int min);
int MenuModificacion();
int MostrarMenuInformes();
int PedirID();
void PedirMarca(char marca[]);
int PedirCilindrada();
int PedirPuntaje();
int PedirDia();
int PedirMes();
int PedirAnio();
void PedirString(char* mensaje, char* nombre);
void PedirSexo(char* mensaje, char* nombre);

#endif /* INPUTS_H_ */
