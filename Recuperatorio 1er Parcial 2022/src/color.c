/*
 * color.c
 *
 *  Created on: 12 dic. 2022
 *      Author: Santiago
 */

#include "color.h"

void MostrarUnColor(eColor unColor)
{
	printf("| %-5d | %-7s |\n", unColor.id, unColor.nombre);
}

int MostrarListaColores(eColor listaColores[], int sizeColores)
{
	int retorno = 0;

	printf("===================\n"
			"|  ID   |  Color  |\n"
			"===================\n");

	for(int i=0; i<sizeColores; i++)
	{
		MostrarUnColor(listaColores[i]);
		retorno = 1;
	}

	printf("===================\n");

	return retorno;
}

int PedirIdColor(eColor listaColores[], int sizeColores)
{
	int idAux;

	MostrarListaColores(listaColores, sizeColores);

	idAux = PedirID();
	while(idAux < 10000 || idAux > 10005)
	{
		printf("ERROR, ");
		idAux = PedirID();
	}

	return idAux;
}

