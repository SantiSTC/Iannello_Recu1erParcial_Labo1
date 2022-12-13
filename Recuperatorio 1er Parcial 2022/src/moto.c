/*
 * moto.c
 *
 *  Created on: 12 dic. 2022
 *      Author: Santiago
 */

#include "moto.h"

int PedirIdMoto(eMoto listaMotos[], int sizeMotos)
{
	char idAux[10];
	int validar;
	int id;

	validar = getStringNumeros("Ingrese un ID: ", idAux);
	id = atoi(idAux);
	while(validar == 0 || id < 0)
	{
		validar = getStringNumeros("ERROR, Ingrese un ID valido: ", idAux);
		id = atoi(idAux);
	}
	for(int i=0; i<sizeMotos; i++)
	{
		if(id == listaMotos[i].id)
		{
			validar = getStringNumeros("ERROR, este ID ya existe... Ingrese un ID valido: ", idAux);
			id = atoi(idAux);
		}
	}

	return id;
}

int PedirIdMotoExistente(eMoto listaMotos[], int sizeMotos)
{
	char idAux[10];
	int validar;
	int id;
	int retorno = -1;

	validar = getStringNumeros("Ingrese un ID: ", idAux);
	id = atoi(idAux);
	while(validar == 0 || id < 0)
	{
		validar = getStringNumeros("ERROR, Ingrese un ID valido: ", idAux);
		id = atoi(idAux);
	}
	for(int i=0; i<sizeMotos; i++)
	{
		if(id == listaMotos[i].id)
		{
			retorno = id;
			break;
		}
	}

	return retorno;
}

int BuscarEspacio(eMoto listaMotos[], int sizeMotos)
{
	int index = -1;

	for(int i = 0; i < sizeMotos; i++)
	{
		if(listaMotos[i].estado == LIBRE)
	    {
			index = i;
	        break;
	    }
	}

	return index;
}

void InicializarMotos(eMoto listaMotos[], int sizeMotos)
{
	int index;

	index = BuscarEspacio(listaMotos, sizeMotos);
	for(int i=0; i<sizeMotos; i++)
	{
		if(index != -1)
		{
			listaMotos[i].estado = LIBRE;
		}
	}
}
