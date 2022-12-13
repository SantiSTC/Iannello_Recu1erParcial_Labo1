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

void MostrarUnaMoto(eMoto unaMoto, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores);
void MostrarListaMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores);
eMoto CargarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores);
int CargarListaMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores);
int ModificarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores);
int EliminarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores);
int OrdenarYListarMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores);
void MostrarUnTrabajo(eTrabajo unTrabajo, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios);
int MostrarListaTrabajos(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios);
eTrabajo CargarUnTrabajo(eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores);
int CargarListaTrabajos(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores);

#endif /* NEXO_H_ */
