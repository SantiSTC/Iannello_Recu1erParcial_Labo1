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
	int flagAlta = 0;
	int flagTrabajos = 0;
	int opcionInformes;

	eTipo listaTipos[T_T] = {{1000, "Enduro"}, {1001, "Chopera"}, {1002, "Scooter"}, {1003, "Vintage"}};

	eColor listaColores[T_C] = {{10000, "Gris"},{10001, "Negro"},{10002, "Azul"},{10003, "Blanco"},{10004, "Rojo"}};

	eServicio listaServicios[T_S] = {{20000, "Limpieza", 450},{20001, "Ajuste", 300},{20002, "Balanceo", 150},{20003, "Cadena", 390}};

	eMoto listaMotos[T_M] = {{33, "Yamaha", 1000, 10000, 1, 750, 9, OCUPADO},
							{11, "Honda", 1001, 10001, 2, 125, 8, OCUPADO},
							{44, "Motomel", 1002, 10002, 3, 600, 10, OCUPADO},
							{66, "Yamaha", 1003, 10003, 4, 125, 5, OCUPADO},
							{55, "BMW", 1000, 10004, 5, 600, 7, OCUPADO},
							{22, "Honda", 1003, 10001, 1, 750, 9, OCUPADO}};

	eTrabajo listaTrabajos[T_TR] = {{1, 33, 20000, {12,10,2020}, OCUPADO},
									{2, 11, 20001, {11,10,2020}, OCUPADO},
									{3, 55, 20000, {10,10,2020}, OCUPADO},
									{4, 55, 20003, {13,10,2020}, OCUPADO},
									{5, 44, 20001, {14,10,2020}, OCUPADO},
									{6, 33, 20002, {15,10,2020}, OCUPADO}};

	eCliente listaClientes[T_CL] = {{1, "Pablo", "Masculino", OCUPADO},{2, "Esteban", "Masculino", OCUPADO},{3, "German", "Masculino", OCUPADO},{4, "Laura", "Femenino", OCUPADO},{5, "Monica", "Femenino", OCUPADO}};

	do
	{
		opcion = MostrarMenu();

		switch(opcion)
		{
			case 1:
				retorno = CargarListaMotos(listaMotos, T_M, listaTipos, T_T, listaColores, T_C, listaClientes, T_CL);
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
					retorno = ModificarMoto(listaMotos, T_M, listaTipos, T_T, listaColores, T_C, listaClientes, T_CL);
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
					retorno = EliminarMoto(listaMotos, T_M, listaTipos, T_T, listaColores, T_C, listaClientes, T_CL);
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
					retorno = OrdenarYListarMotos(listaMotos, T_M, listaTipos, T_T, listaColores, T_C, listaClientes, T_CL);
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
					retorno = CargarListaTrabajos(listaTrabajos, T_TR, listaMotos, T_M, listaServicios, T_S, listaTipos, T_T, listaColores, T_C, listaClientes, T_CL);
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
				if(flagAlta == 1)
				{
					if(flagTrabajos == 1)
					{
						opcionInformes = MostrarMenuInformes();

						switch(opcionInformes)
						{
							case 1:
								MostrarMotosDeUnColor(listaMotos, T_M, listaTipos, T_T, listaColores, T_C, listaClientes, T_CL);
							break;
							case 2:
								InformarPromedioPuntajeDeUnTipo(listaMotos, T_M, listaTipos, T_T);
							break;
							case 3:
								InformarMayorCilindrada(listaMotos, T_M, listaTipos, T_T, listaColores, T_C, listaClientes, T_CL);
							break;
							case 4:
								MostrarMotosPorTipo(listaMotos, T_M, listaTipos, T_T, listaColores, T_C, listaClientes, T_CL);
							break;
							case 5:
								MostrarMotosDeUnColorYUnTipo(listaMotos, T_M, listaTipos, T_T, listaColores, T_C, listaClientes, T_CL);
							break;
							case 6:
								MostrarColorMasElegido(listaMotos, T_M, listaColores, T_C);
							break;
							case 7:
								MostrarTrabajosDeUnaMoto(listaTrabajos, T_TR, listaMotos, T_M, listaTipos, T_T, listaColores, T_C, listaClientes, T_CL, listaServicios, T_S);
							break;
							case 8:
								InformarSumaImportesServiciosDeUnaMoto(listaTrabajos, T_TR, listaMotos, T_M, listaTipos, T_T, listaColores, T_C, listaClientes, T_CL, listaServicios, T_S);
							break;
							case 9:
								MostrarMotosDeUnServicio(listaTrabajos, T_TR, listaMotos, T_M, listaServicios, T_S);
							break;
							case 10:
								MostrarServiciosDeUnaFecha(listaTrabajos, T_TR, listaServicios, T_S);
							break;
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
		}

	}while(opcion != 11);


	return 0;
}
