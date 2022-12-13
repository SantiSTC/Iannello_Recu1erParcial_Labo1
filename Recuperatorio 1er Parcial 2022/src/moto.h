/*
 * moto.h
 *
 *  Created on: 12 dic. 2022
 *      Author: Santiago
 */

#ifndef MOTO_H_
#define MOTO_H_

#include "inputs.h"

typedef struct
{
	int id;
	char marca[21];
	int idTipo;
	int idColor;
	int cilindrada;
	int puntaje;
	int estado;
}eMoto;

int PedirIdMoto(eMoto listaMotos[], int sizeMotos);
int BuscarEspacio(eMoto listaMotos[], int sizeMotos);
void InicializarMotos(eMoto listaMotos[], int sizeMotos);
int PedirIdMotoExistente(eMoto listaMotos[], int sizeMotos);



#endif /* MOTO_H_ */
