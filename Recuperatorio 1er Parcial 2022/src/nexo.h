/*
 * nexo.h
 *
 *  Created on: 12 dic. 2022
 *      Author: Santiago
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "inputs.h"
#include "moto.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"

void MostrarUnaMoto(eMoto unaMoto, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
void MostrarListaMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
eMoto CargarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
int CargarListaMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
int ModificarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
int EliminarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
int OrdenarYListarMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
void MostrarUnTrabajo(eTrabajo unTrabajo, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios);
int MostrarListaTrabajos(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios);
eTrabajo CargarUnTrabajo(eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
int CargarListaTrabajos(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
int MostrarMotosDeUnColor(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
int InformarPromedioPuntajeDeUnTipo(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos);
int InformarMayorCilindrada(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
int MostrarMotosPorTipo(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
int MostrarMotosDeUnColorYUnTipo(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);
int MostrarColorMasElegido(eMoto listaMotos[], int sizeMotos, eColor listaColores[], int sizeColores);
int MostrarTrabajosDeUnaMoto(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes, eServicio listaServicios[], int sizeServicios);
int InformarSumaImportesServiciosDeUnaMoto(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes, eServicio listaServicios[], int sizeServicios);
int MostrarMotosDeUnServicio(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios);
int MostrarServiciosDeUnaFecha(eTrabajo listaTrabajos[], int sizeTrabajos, eServicio listaServicios[], int sizeServicios);

#endif /* NEXO_H_ */
