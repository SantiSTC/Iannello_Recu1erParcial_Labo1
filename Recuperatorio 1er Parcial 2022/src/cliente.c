/*
 * cliente.c
 *
 *  Created on: 26 oct. 2022
 *      Author: Santiago
 */

#include "cliente.h"

void MostrarUnCliente(eCliente unCliente)
{
	printf("  %d    %-13s   %-22s\n", unCliente.id, unCliente.nombreCliente, unCliente.sexoCliente);
}

void MostrarListaClientes(eCliente listaClientes[], int sizeClientes)
{
	printf("====================================\n"
			"| ID |    Nombre    |     Sexo     |\n"
			"====================================\n");

	for(int i=0; i<sizeClientes; i++)
	{
		if(listaClientes[i].isEmpty == OCUPADO)
		{
			MostrarUnCliente(listaClientes[i]);
		}
	}

	printf("====================================\n");
}

int PedirIdCliente(eCliente listaClientes[], int sizeClientes)
{
	int retorno = -1;
	char idAux[10];
	int validar;
	int id;

	MostrarListaClientes(listaClientes, sizeClientes);

	validar = getStringNumeros("Ingrese el ID de un cliente: ", idAux);
	id = atoi(idAux);
	while(validar == 0 || id < 0)
	{
		validar = getStringNumeros("ERROR, Ingrese el ID de un cliente: ", idAux);
		id = atoi(idAux);
	}
	for(int i=0; i<sizeClientes; i++)
	{
		if(id == listaClientes[i].id)
		{
			retorno = id;
			break;
		}
	}

	return retorno;

}
