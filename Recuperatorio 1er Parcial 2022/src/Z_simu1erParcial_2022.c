/*
 ============================================================================
 Name        : Z_simu1erParcial_2022.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

#define T_T 4
#define T_C 5
#define T_S 4
#define T_M 6
#define T_TR 100
#define T_CL 100

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int retorno;
	int flagAlta = 1;
	int flagTrabajos = 0;
	int opcionInformes;

	eTipo listaTipos[T_T] = {{1000, "Enduro"}, {1001, "Chopera"}, {1002, "Scooter"}, {1003, "Vintage"}};

	eColor listaColores[T_C] = {{10000, "Gris"},{10001, "Negro"},{10002, "Azul"},{10003, "Blanco"},{10004, "Rojo"}};

	eServicio listaServicios[T_S] = {{20000, "Limpieza", 450},{20001, "Ajuste", 300},{20002, "Balanceo", 150},{20003, "Cadena", 390}};

	eMoto listaMotos[6] = {{33, "Yamaha", 1000, 10000, 50, 9, OCUPADO},
							{11, "Honda", 1001, 10001, 125, 8, OCUPADO},
							{44, "Lolaso", 1002, 10002, 600, 10, OCUPADO},
							{66, "Tornado", 1003, 10003, 125, 5, OCUPADO},
							{55, "Wololo", 1000, 10004, 600, 7, OCUPADO},
							{22, "Trolaso", 1003, 10001, 750, 9, OCUPADO}};

	eTrabajo listaTrabajos[T_TR];

	do
	{
		opcion = MostrarMenu();

		switch(opcion)
		{
			case 1:
				retorno = CargarListaMotos(listaMotos, T_M, listaTipos, T_T, listaColores, T_C);
				if(retorno > -1)
				{
					flagAlta = 1;
					printf("Se ha cargado correctamente la moto...\n");
				}
				else
				{
					printf("No se ha podido cargar la moto...\n");
				}
			break;
			case 2:
				if(flagAlta == 1)
				{
					retorno = ModificarMoto(listaMotos, T_M, listaTipos, T_T, listaColores, T_C);
					if(retorno == 1)
					{
						printf("Se ha modificado correctamente la moto...\n");
					}
					else
					{
						printf("No se ha podido modificar la moto...\n");
					}
				}
				else
				{
					printf("Se debera cargar al menos una moto antes de ingresar a esta opcion...\n");
				}
			break;
			case 3:
				if(flagAlta == 1)
				{
					retorno = EliminarMoto(listaMotos, T_M, listaTipos, T_T, listaColores, T_C);
					if(retorno == 1)
					{
						printf("Se ha eliminado correctamente a la moto...\n");
					}
					else
					{
						printf("No se ha podido eliminar a la moto...\n");
					}
				}
				else
				{
					printf("Se debera cargar al menos una moto antes de ingresar a esta opcion...\n");
				}
			break;
			case 4:
				if(flagAlta == 1)
				{
					retorno = OrdenarYListarMotos(listaMotos, T_M, listaTipos, T_T, listaColores, T_C);
					if(retorno == 1)
					{
						printf("Se ha listado correctamente a las motos...\n");
					}
					else
					{
						printf("No se ha podido listar a las motos...\n");
					}
				}
				else
				{
					printf("Se debera cargar al menos una moto antes de ingresar a esta opcion...\n");
				}
			break;
			case 5:
				if(flagAlta == 1)
				{
					retorno = MostrarListaTipos(listaTipos, T_T);
					if(retorno == 1)
					{
						printf("Se ha listado correctamente a los tipos...\n");
					}
					else
					{
						printf("No se ha podido listar a los tipos...\n");
					}
				}
				else
				{
					printf("Se debera cargar al menos una moto antes de ingresar a esta opcion...\n");
				}
			break;
			case 6:
				if(flagAlta == 1)
				{
					retorno = MostrarListaColores(listaColores, T_C);
					if(retorno == 1)
					{
						printf("Se ha listado correctamente a los colores...\n");
					}
					else
					{
						printf("No se ha podido listar a los colores...\n");
					}
				}
				else
				{
					printf("Se debera cargar al menos una moto antes de ingresar a esta opcion...\n");
				}
			break;
			case 7:
				if(flagAlta == 1)
				{
					retorno = MostrarListaServicios(listaServicios, T_S);
					if(retorno == 1)
					{
						printf("Se ha listado correctamente a los servicios...\n");
					}
					else
					{
						printf("No se ha podido listar a los servicios...\n");
					}
				}
				else
				{
					printf("Se debera cargar al menos una moto antes de ingresar a esta opcion...\n");
				}
			break;
			case 8:
				if(flagAlta == 1)
				{
					retorno = CargarListaTrabajos(listaTrabajos, T_TR, listaMotos, T_M, listaServicios, T_S, listaTipos, T_T, listaColores, T_C);
					if(retorno > -1)
					{
						printf("Se ha cargado correctamente al trabajo...\n");
						flagTrabajos = 1;
					}
					else
					{
						printf("No se ha podido cargar al trabajo...\n");
					}
				}
				else
				{
					printf("Se debera cargar al menos una moto antes de ingresar a esta opcion...\n");
				}
			break;
			case 9:
				if(flagAlta == 1)
				{
					if(flagTrabajos == 1)
					{
						retorno = MostrarListaTrabajos(listaTrabajos, T_TR, listaMotos, T_M, listaServicios, T_S);
						if(retorno == 1)
						{
							printf("Se han mostrado correctamente los trabajos...\n");
						}
						else
						{
							printf("No se han podido mostrar los trabajos...\n");
						}
					}
					else
					{
						printf("Se debera cargar al menos un trabajo antes de ingresar a esta opcion...\n");
					}
				}
				else
				{
					printf("Se debera cargar al menos una moto antes de ingresar a esta opcion...\n");
				}
			break;
			case 10:
				opcionInformes = MostrarMenuInformes();

				switch(opcionInformes)
				{
					case 1:

					break;
					case 2:

					break;
					case 3:

					break;
					case 4:

					break;
					case 5:

					break;
					case 6:

					break;
				}
			break;
		}

	}while(opcion != 10);


	return 0;
}
