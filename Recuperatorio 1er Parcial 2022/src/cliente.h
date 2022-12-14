/*
 * cliente.h
 *
 *  Created on: 26 oct. 2022
 *      Author: Santiago
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "inputs.h"

typedef struct
{
	int id;
	char nombreCliente[50];
	char sexoCliente[20];
	int isEmpty;
}eCliente;

eCliente CargarCliente();
int CargarListaClientes(eCliente listaClientes[], int sizeClientes);
int PedirIdCliente(eCliente listaClientes[], int sizeClientes);
#endif /* CLIENTE_H_ */
