/*
 * nexo.c
 *
 *  Created on: 12 dic. 2022
 *      Author: Santiago
 */

#include "nexo.h"

void MostrarUnaMoto(eMoto unaMoto, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	for(int i=0; i<sizeTipos; i++)
	{
		for(int j=0; j<sizeColores; j++)
		{
			for(int x=0; x<sizeClientes; x++)
			{
				if(listaTipos[i].id == unaMoto.idTipo && listaColores[j].id == unaMoto.idColor && unaMoto.idCliente == listaClientes[x].id)
				{
					printf("| %-3d| %-13s | %-10s | %-11s | %-10d | %-7d | %-11s |\n", unaMoto.id, unaMoto.marca, listaTipos[i].descripcion, listaColores[j].nombre, unaMoto.cilindrada, unaMoto.puntaje, listaClientes[x].nombreCliente);
				}
			}
		}
	}
}

void MostrarListaMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	printf("======================================================================================\n"
			"| ID |     Marca     |    Tipo    |    Color    | Cilindrada | Puntaje |   Cliente   |\n"
			"======================================================================================\n");

	for(int i=0; i<sizeMotos; i++)
	{
		if(listaMotos[i].estado == OCUPADO)
		{
			MostrarUnaMoto(listaMotos[i], listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
		}
	}

	printf("======================================================================================\n");
}

eMoto CargarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	eMoto unaMoto;

	unaMoto.id = PedirIdMoto(listaMotos, sizeMotos);
	PedirMarca(unaMoto.marca);
	unaMoto.idTipo = PedirIdTipo(listaTipos, sizeTipos);
	unaMoto.idColor = PedirIdColor(listaColores, sizeColores);
	unaMoto.idCliente = PedirIdCliente(listaClientes, sizeClientes);
	unaMoto.cilindrada = PedirCilindrada();
	unaMoto.puntaje = PedirPuntaje();

	unaMoto.estado = OCUPADO;

	return unaMoto;
}

int CargarListaMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	int index = BuscarEspacio(listaMotos, sizeMotos);

	if(index != -1)
	{
		listaMotos[index] = CargarMoto(listaMotos, sizeMotos, listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
	}

	return index;
}

int ModificarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	int opcion;
	int idMoto;
	int retorno = 0;

	MostrarListaMotos(listaMotos, sizeMotos, listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
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

int EliminarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	int retorno = 0;
	int idMoto;

	MostrarListaMotos(listaMotos, sizeMotos, listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
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

int OrdenarYListarMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
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

	MostrarListaMotos(listaMotos, sizeMotos, listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);

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

eTrabajo CargarUnTrabajo(eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	eTrabajo unTrabajo;

	unTrabajo.id = ObtenerIDTrabajos();
	MostrarListaMotos(listaMotos, sizeMotos, listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
	unTrabajo.idMoto = PedirIdMotoExistente(listaMotos, sizeMotos);
	MostrarListaServicios(listaServicios, sizeServicios);
	unTrabajo.idServicio = PedirIdServicios(listaServicios, sizeServicios);
	unTrabajo.fecha.dia = PedirDia();
	unTrabajo.fecha.mes = PedirMes();
	unTrabajo.fecha.anio = PedirAnio();

	unTrabajo.estado = OCUPADO;

	return unTrabajo;
}

int CargarListaTrabajos(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	int index;

	index = BuscarEspacioTrabajos(listaTrabajos, sizeTrabajos);

	if(index != -1)
	{
		listaTrabajos[index] = CargarUnTrabajo(listaMotos, sizeMotos, listaServicios, sizeServicios, listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
	}

	return index;
}

int MostrarMotosDeUnColor(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	int retorno = 0;
	int idColor;

	idColor = PedirIdColor(listaColores, sizeColores);

	printf("======================================================================================\n"
			"| ID |     Marca     |    Tipo    |    Color    | Cilindrada | Puntaje |   Cliente   |\n"
			"======================================================================================\n");


	for(int i=0; i<sizeMotos; i++)
	{
		if(listaMotos[i].idColor == idColor)
		{
			MostrarUnaMoto(listaMotos[i], listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
		}
	}

	retorno = 1;

	printf("======================================================================================\n");

	return retorno;
}

int InformarPromedioPuntajeDeUnTipo(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos)
{
	int retorno = 0;
	int idTipo;
	int contador = 0;
	int sumador = 0;
	float promedio;

	idTipo = PedirIdTipo(listaTipos, sizeTipos);

	for(int i=0; i<sizeMotos; i++)
	{
		if(listaMotos[i].idTipo == idTipo)
		{
			contador++;
			sumador += listaMotos[i].puntaje;
		}
	}

	promedio = sumador / contador;

	printf("El promedio de puntaje para el tipo seleccionado es: %.2f", promedio);
	retorno = 1;

	return retorno;
}

int InformarMayorCilindrada(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	int retorno = 0;
	int mayor = 0;

	for(int i=0; i<sizeMotos; i++)
	{
		if(listaMotos[i].cilindrada > mayor)
		{
			mayor = listaMotos[i].cilindrada;
		}
	}

	printf("======================================================================================\n"
			"| ID |     Marca     |    Tipo    |    Color    | Cilindrada | Puntaje |   Cliente   |\n"
			"======================================================================================\n");

	for(int i=0; i<sizeMotos; i++)
	{
		if(listaMotos[i].cilindrada == mayor)
		{
			MostrarUnaMoto(listaMotos[i], listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
			retorno = 1;
		}
	}

	printf("======================================================================================\n");

	return retorno;
}

int MostrarMotosPorTipo(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	int retorno = 0;

	for(int i=0; i<sizeTipos; i++)
	{
		printf("                         <  %s  >\n", listaTipos[i].descripcion);

		printf("======================================================================================\n"
				"| ID |     Marca     |    Tipo    |    Color    | Cilindrada | Puntaje |   Cliente   |\n"
				"======================================================================================\n");

		for(int j=0; j<sizeMotos; j++)
		{
			if(listaMotos[j].idTipo == listaTipos[i].id)
			{
				MostrarUnaMoto(listaMotos[j], listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
				retorno = 1;
			}
		}

		printf("======================================================================================\n");
	}

	return retorno;
}

int MostrarMotosDeUnColorYUnTipo(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	int retorno = 0;
	int idTipo;
	int idColor;
	int flag = 0;
	int contador = 0;

	idTipo = PedirIdTipo(listaTipos, sizeTipos);
	idColor = PedirIdColor(listaColores, sizeColores);

	printf("======================================================================================\n"
			"| ID |     Marca     |    Tipo    |    Color    | Cilindrada | Puntaje |   Cliente   |\n"
			"======================================================================================\n");

	for(int i=0; i<sizeMotos; i++)
	{
		if(listaMotos[i].idTipo == idTipo && listaMotos[i].idColor == idColor)
		{
			MostrarUnaMoto(listaMotos[i], listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
			contador++;
			flag = 1;
		}

		retorno = 1;
	}

	if(flag == 0)
	{
		printf("| No se han encontrado motos de ese color y tipo especificos...                       |\n");
	}

	printf("======================================================================================\n");

	printf("Hay %d motos de el color y tipo elegidos.\n", contador);

	return retorno;
}

int MostrarColorMasElegido(eMoto listaMotos[], int sizeMotos, eColor listaColores[], int sizeColores)
{
	int retorno = 0;
	int contador = 0;
	int contador2 = 0;
	int mayor = 0;

	for(int i=0; i<sizeColores; i++)
	{
		contador = 0;

		for(int j=0; j<sizeMotos; j++)
		{
			if(listaMotos[j].idColor == listaColores[i].id)
			{
				contador++;
			}
		}

		if(contador > mayor)
		{
			mayor = contador;
		}
	}

	printf("===================\n"
			"|  ID   |  Color  |\n"
			"===================\n");

	for(int i=0; i<sizeColores; i++)
	{
		contador2 = 0;

		for(int j=0; j<sizeMotos; j++)
		{
			if(listaMotos[j].idColor == listaColores[i].id)
			{
				contador2++;
			}
		}

		if(contador2 == mayor)
		{
			MostrarUnColor(listaColores[i]);
			retorno = 1;
		}
	}

	printf("===================\n");

	return retorno;
}

int MostrarTrabajosDeUnaMoto(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes, eServicio listaServicios[], int sizeServicios)
{
	int retorno = 0;
	int idMoto;

	MostrarListaMotos(listaMotos, sizeMotos, listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
	idMoto = PedirIdMotoExistente(listaMotos, sizeMotos);

	printf("===========================================\n"
			"| ID | ID Moto |  Servicio  |    Fecha    |\n"
			"===========================================\n");

	for(int i=0; i<sizeTrabajos; i++)
	{
		if(listaTrabajos[i].idMoto == idMoto)
		{
			MostrarUnTrabajo(listaTrabajos[i], listaMotos, sizeMotos, listaServicios, sizeServicios);
			retorno = 1;
		}
	}

	printf("===========================================\n");

	return retorno;
}

int InformarSumaImportesServiciosDeUnaMoto(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes, eServicio listaServicios[], int sizeServicios)
{
	int retorno = 0;
	int idMoto;
	float sumador = 0;

	MostrarListaMotos(listaMotos, sizeMotos, listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
	idMoto = PedirIdMotoExistente(listaMotos, sizeMotos);

	for(int i=0; i<sizeTrabajos; i++)
	{
		for(int j=0; j<sizeServicios; j++)
		{
			if(idMoto == listaTrabajos[i].idMoto && listaServicios[j].id == listaTrabajos[i].idServicio)
			{
				sumador += listaServicios[j].precio;
				retorno = 1;
			}
		}
	}

	printf("La suma de importes para la moto indicada es de: %.2f", sumador);

	return retorno;
}

int MostrarMotosDeUnServicio(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios)
{
	int retorno = 0;
	int idServicio;

	MostrarListaServicios(listaServicios, sizeServicios);
	idServicio = PedirIdServicios(listaServicios, sizeServicios);

	printf("===============================\n"
			"| ID |   Marca   |   Fecha    |\n"
			"===============================\n");

	for(int i=0; i<sizeTrabajos; i++)
	{
		for(int j=0; j<sizeServicios; j++)
		{
			for(int x=0; x<sizeMotos; x++)
			{
				if(idServicio == listaServicios[j].id && listaTrabajos[i].idServicio == listaServicios[j].id && listaTrabajos[i].idMoto == listaMotos[x].id)
				{
					printf("| %-3d| %-9s | %d/%2d/%d |\n", listaMotos[x].id, listaMotos[x].marca, listaTrabajos[i].fecha.dia, listaTrabajos[i].fecha.mes, listaTrabajos[i].fecha.anio);
					retorno = 1;
				}
			}
		}
	}

	printf("===============================\n");

	return retorno;
}

int MostrarServiciosDeUnaFecha(eTrabajo listaTrabajos[], int sizeTrabajos, eServicio listaServicios[], int sizeServicios)
{
	int retorno = 0;
	int dia = PedirDia();
	int mes = PedirMes();
	int anio = PedirAnio();
	int flag = 0;

	printf("===============================\n"
			"|  ID   |  Servicio  | Precio |\n"
			"===============================\n");

	for(int i=0; i<sizeTrabajos; i++)
	{
		for(int j=0; j<sizeServicios; j++)
		{
			if(listaTrabajos[i].fecha.dia == dia && listaTrabajos[i].fecha.mes == mes && listaTrabajos[i].fecha.anio == anio && listaTrabajos[i].idServicio == listaServicios[j].id)
			{
				MostrarUnServicio(listaServicios[j]);
				flag = 1;
			}
		}

		retorno = 1;
	}

	if(flag == 0)
	{
		printf("| No se han encontrado servicios en esta fecha...\n");
	}

	printf("===============================\n");

	return retorno;
}









