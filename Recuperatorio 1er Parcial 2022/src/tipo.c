/*
 * tipo.c
 *
 *  Created on: 12 dic. 2022
 *      Author: Santiago
 */

#include "tipo.h"

void MostrarUnTipo(eTipo unTipo)
{
	printf("| %-4d | %-8s |\n", unTipo.id, unTipo.descripcion);
}

int MostrarListaTipos(eTipo listaTipos[], int sizeTipos)
{
	int retorno = 0;

	printf("===================\n"
			"|  ID  |   Tipo   |\n"
			"===================\n");

	for(int i=0; i<sizeTipos; i++)
	{
		MostrarUnTipo(listaTipos[i]);
		retorno = 1;
	}

	printf("===================\n");

	return retorno;
}

int PedirIdTipo(eTipo listaTipos[], int sizeTipos)
{
	int idAux;

	MostrarListaTipos(listaTipos, sizeTipos);

	idAux = PedirID();
	while(idAux < 1000 || idAux > 1003)
	{
		printf("ERROR, ");
		idAux = PedirID();
	}

	return idAux;
}
