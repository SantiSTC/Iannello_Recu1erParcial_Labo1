/*
 * nexo.c
 *
 *  Created on: 12 dic. 2022
 *      Author: Santiago
 */

#include "nexo.h"

void MostrarUnaMoto(eMoto unaMoto, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores)
{
	for(int i=0; i<sizeTipos; i++)
	{
		for(int j=0; j<sizeColores; j++)
		{
			if(listaTipos[i].id == unaMoto.idTipo && listaColores[j].id == unaMoto.idColor)
			{
				printf("| %-3d| %-13s | %-10s | %-11s | %-10d | %-7d |\n", unaMoto.id, unaMoto.marca, listaTipos[i].descripcion, listaColores[j].nombre, unaMoto.cilindrada, unaMoto.puntaje);
			}
		}
	}
}

void MostrarListaMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores)
{
	printf("========================================================================\n"
			"| ID |     Marca     |    Tipo    |    Color    | Cilindrada | Puntaje |\n"
			"========================================================================\n");

	for(int i=0; i<sizeMotos; i++)
	{
		if(listaMotos[i].estado == OCUPADO)
		{
			MostrarUnaMoto(listaMotos[i], listaTipos, sizeTipos, listaColores, sizeColores);
		}
	}

	printf("=========================================================================\n");
}

eMoto CargarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores)
{
	eMoto unaMoto;

	unaMoto.id = PedirIdMoto(listaMotos, sizeMotos);
	PedirMarca(unaMoto.marca);
	unaMoto.idTipo = PedirIdTipo(listaTipos, sizeTipos);
	unaMoto.idColor = PedirIdColor(listaColores, sizeColores);
	unaMoto.cilindrada = PedirCilindrada();
	unaMoto.puntaje = PedirPuntaje();

	unaMoto.estado = OCUPADO;

	return unaMoto;
}

int CargarListaMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores)
{
	int index = BuscarEspacio(listaMotos, sizeMotos);

	if(index != -1)
	{
		listaMotos[index] = CargarMoto(listaMotos, sizeMotos, listaTipos, sizeTipos, listaColores, sizeColores);
	}

	return index;
}

int ModificarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores)
{
	int opcion;
	int idMoto;
	int retorno = 0;

	MostrarListaMotos(listaMotos, sizeMotos, listaTipos, sizeTipos, listaColores, sizeColores);
	idMoto = PedirIdMotoExistente(listaMotos, sizeMotos);

	if(idMoto > -1)
	{
		for(int i=0; i<sizeMotos; i++)
		{
			if(idMoto == listaMotos[i].id)
			{
				opcion = MenuModificacion();

				switch(opcion)
				{
					case 1:
						listaMotos[i].idColor = PedirIdColor(listaColores, sizeColores);
						retorno = 1;
					break;
					case 2:
						listaMotos[i].puntaje = PedirPuntaje();
						retorno = 1;
					break;
				}
			}
		}
	}
	else
	{
		printf("El ID ingresado no pertenece a ninguna moto existente...\n");
	}

	return retorno;
}

int EliminarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores)
{
	int retorno = 0;
	int idMoto;

	MostrarListaMotos(listaMotos, sizeMotos, listaTipos, sizeTipos, listaColores, sizeColores);
	idMoto = PedirIdMotoExistente(listaMotos, sizeMotos);

	if(idMoto > -1)
	{
		for(int i=0; i<sizeMotos; i++)
		{
			if(idMoto == listaMotos[i].id)
			{
				listaMotos[i].estado = LIBRE;
				retorno = 1;
			}
		}
	}

	return retorno;
}

int OrdenarYListarMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores)
{
	int retorno = 0;
	eMoto aux;

	for(int i=0; i<sizeMotos-1; i++)
	{
		for(int j=i+1; j<sizeMotos; j++)
		{

			if(listaMotos[i].id > listaMotos[j].id)
			{
				aux = listaMotos[i];
				listaMotos[i] = listaMotos[j];
				listaMotos[j] = aux;
			}
			retorno = 1;
		}
	}

	MostrarListaMotos(listaMotos, sizeMotos, listaTipos, sizeTipos, listaColores, sizeColores);

	return retorno;
}

void MostrarUnTrabajo(eTrabajo unTrabajo, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios)
{
	for(int i=0; i<sizeServicios; i++)
	{
		if(unTrabajo.idServicio == listaServicios[i].id)
		{
				printf("| %-3d| %-7d | %-10s | %d/%2d/%-5d |\n", unTrabajo.id, unTrabajo.idMoto, listaServicios[i].descripcion, unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio);
		}
	}
}

int MostrarListaTrabajos(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios)
{
	int retorno = 0;

	printf("===========================================\n"
			"| ID | ID Moto |  Servicio  |    Fecha    |\n"
			"===========================================\n");

	for(int i=0; i<sizeTrabajos; i++)
	{
		if(listaTrabajos[i].estado == OCUPADO)
		{
			MostrarUnTrabajo(listaTrabajos[i], listaMotos, sizeMotos, listaServicios, sizeServicios);
			retorno = 1;
		}
	}

	printf("===========================================\n");

	return retorno;
}

eTrabajo CargarUnTrabajo(eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores)
{
	eTrabajo unTrabajo;

	unTrabajo.id = ObtenerIDTrabajos();
	MostrarListaMotos(listaMotos, sizeMotos, listaTipos, sizeTipos, listaColores, sizeColores);
	unTrabajo.idMoto = PedirIdMotoExistente(listaMotos, sizeMotos);
	MostrarListaServicios(listaServicios, sizeServicios);
	unTrabajo.idServicio = PedirIdServicios(listaServicios, sizeServicios);
	unTrabajo.fecha.dia = PedirDia();
	unTrabajo.fecha.mes = PedirMes();
	unTrabajo.fecha.anio = PedirAnio();

	unTrabajo.estado = OCUPADO;

	return unTrabajo;
}

int CargarListaTrabajos(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores)
{
	int index;

	index = BuscarEspacioTrabajos(listaTrabajos, sizeTrabajos);

	if(index != -1)
	{
		listaTrabajos[index] = CargarUnTrabajo(listaMotos, sizeMotos, listaServicios, sizeServicios, listaTipos, sizeTipos, listaColores, sizeColores);
	}

	return index;
}









