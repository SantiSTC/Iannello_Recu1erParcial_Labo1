/*
 * servicio.c
 *
 *  Created on: 12 dic. 2022
 *      Author: Santiago
 */

#include "servicio.h"

void MostrarUnServicio(eServicio unServicio)
{
	printf("| %-6d| %-10s | %-6.2f |\n", unServicio.id, unServicio.descripcion, unServicio.precio);
}

int MostrarListaServicios(eServicio listaeServicios[], int sizeServicios)
{
	int retorno = 0;

	printf("===============================\n"
			"|  ID   |  Servicio  | Precio |\n"
			"===============================\n");

	for(int i=0; i<sizeServicios; i++)
	{
		MostrarUnServicio(listaeServicios[i]);
		retorno = 1;
	}

	printf("===============================\n");

	return retorno;
}

int PedirIdServicios(eServicio listaServicios[], int sizeServicios)
{
	int validar;
	int id;
	char idAux[10];
	int retorno = -1;

	validar = getStringNumeros("Ingrese un ID: ", idAux);
	id = atoi(idAux);
	while(validar == 0 || id < 0)
	{
		validar = getStringNumeros("ERROR, Ingrese un ID valido: ", idAux);
		id = atoi(idAux);
	}

	for(int i=0; i<sizeServicios; i++)
	{
		if(id == listaServicios[i].id)
		{
			retorno = id;
			break;
		}
	}

	return retorno;
}
