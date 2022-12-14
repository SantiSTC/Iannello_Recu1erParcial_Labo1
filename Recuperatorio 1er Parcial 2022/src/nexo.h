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

/// @brief Muestra los datos de una moto.
/// @param unaMoto Recibe los datos de una moto.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @param listaClientes Recibe la lista de clientes de motos.
/// @param sizeClientes Recibe el tamaño de la lista de clientes.
void MostrarUnaMoto(eMoto unaMoto, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Muestra la lista de motos.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @param listaClientes Recibe la lista de clientes de motos.
/// @param sizeClientes Recibe el tamaño de la lista de clientes.
void MostrarListaMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Pide todos los campos de una moto para cargarla.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @return Retorna una moto con todos sus campos cargados.
eMoto CargarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Carga una moto a la lista.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @return Retorna el indice en el que se guardo la moto en la lista.

int CargarListaMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Permite modificar los datos de una moto.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @return Retorna -1 si no se pudo modificar, 1 si si se pudo.
int ModificarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Permite la baja logica de una moto de la lista.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @param listaClientes Recibe la lista de clientes de motos.
/// @param sizeClientes Recibe el tamaño de la lista de clientes.
/// @return 1 si se pudo, 0 si no.
int EliminarMoto(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Ordena las motos por ID y las muestra.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @param listaClientes Recibe la lista de clientes de motos.
/// @param sizeClientes Recibe el tamaño de la lista de clientes.
/// @return 1 si se pudo, 0 si no.
int OrdenarYListarMotos(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Muestra los datos de un trabajo.
/// @param unTrabajo Recibe los datos de un trabajo.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaServicios Recibe la lista de servicios disponibles.
/// @param sizeServicios Recibe el tamaño de la lista de servicios.
void MostrarUnTrabajo(eTrabajo unTrabajo, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios);

/// @brief Muestra la lista de trabajos.
/// @param listaTrabajos Recibe la lista de trabajos activos.
/// @param sizeTrabajos Recibe el tamaño de la lista de trabajos.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaServicios Recibe la lista de servicios disponibles.
/// @param sizeServicios Recibe el tamaño de la lista de servicios.
/// @return 1 si se pudo, 0 si no.
int MostrarListaTrabajos(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios);

/// @brief Pide todos los datos de un trabajo para cargarlo.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaServicios Recibe la lista de servicios disponibles.
/// @param sizeServicios Recibe el tamaño de la lista de servicios.
/// @return Retorna un trabajo con todos sus campos cargados.

eTrabajo CargarUnTrabajo(eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Carga un trabajo a la lista.
/// @param listaTrabajos Recibe la lista de trabajos activos.
/// @param sizeTrabajos Recibe el tamaño de la lista de trabajos.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaServicios Recibe la lista de servicios disponibles.
/// @param sizeServicios Recibe el tamaño de la lista de servicios.
/// @return Retorna el indice en el que se guardo el trabajo en la lista.
int CargarListaTrabajos(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Muestra las motos de un color elegido por el usuario.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @param listaClientes Recibe la lista de clientes de motos.
/// @param sizeClientes Recibe el tamaño de la lista de clientes.
/// @return 1 si se pudo, 0 si no.
int MostrarMotosDeUnColor(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Informa el promedio de puntaje de un tipo de moto elegido por el usuario.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @return 1 si se pudo, 0 si no.
int InformarPromedioPuntajeDeUnTipo(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos);

/// @brief Informa la o las motos con mayor cilindrada.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @param listaClientes Recibe la lista de clientes de motos.
/// @param sizeClientes Recibe el tamaño de la lista de clientes.
/// @return 1 si se pudo, 0 si no.
int InformarMayorCilindrada(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Muestra las motos separadas por tipo.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @param listaClientes Recibe la lista de clientes de motos.
/// @param sizeClientes Recibe el tamaño de la lista de clientes.
/// @return 1 si se pudo, 0 si no.
int MostrarMotosPorTipo(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Muestra las motos de un color y tipo especificos elegido por el usuario.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @param listaClientes Recibe la lista de clientes de motos.
/// @param sizeClientes Recibe el tamaño de la lista de clientes.
/// @return 1 si se pudo, 0 si no.
int MostrarMotosDeUnColorYUnTipo(eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief Muestra el color mas elegido para las motos.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @return 1 si se pudo, 0 si no.
int MostrarColorMasElegido(eMoto listaMotos[], int sizeMotos, eColor listaColores[], int sizeColores);

/// @brief Muestra los trabajos que se le realizaron a una moto en especifico.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @param listaClientes Recibe la lista de clientes de motos.
/// @param sizeClientes Recibe el tamaño de la lista de clientes.
/// @param listaServicios Recibe la lista de servicios disponibles.
/// @param sizeServicios Recibe el tamaño de la lista de servicios.
/// @return 1 si se pudo, 0 si no.
int MostrarTrabajosDeUnaMoto(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes, eServicio listaServicios[], int sizeServicios);

/// @brief Muestra la suma de importes de los servicios realizados a una moto en especifico.
/// @param listaTrabajos Recibe la lista de trabajos activos.
/// @param sizeTrabajos Recibe el tamaño de la lista de trabajos.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaTipos Recibe la lista de tipos de motos.
/// @param sizeTipos Recibe el tamaño de la lista de tipos.
/// @param listaColores Recibe la lista de colores de motos.
/// @param sizeColores Recibe el tamaño de la lista de colores.
/// @param listaClientes Recibe la lista de clientes de motos.
/// @param sizeClientes Recibe el tamaño de la lista de clientes.
/// @param listaServicios Recibe la lista de servicios disponibles.
/// @param sizeServicios Recibe el tamaño de la lista de servicios.
/// @return 1 si se pudo, 0 si no.
int InformarSumaImportesServiciosDeUnaMoto(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes, eServicio listaServicios[], int sizeServicios);

/// @brief Muestra las motos a las que se le realizo un servicio en especifico elegido por el usuario.
/// @param listaTrabajos Recibe la lista de trabajos activos.
/// @param sizeTrabajos Recibe el tamaño de la lista de trabajos.
/// @param listaMotos Recibe la lista de motos.
/// @param sizeMotos Recibe el tamaño de la lista de motos.
/// @param listaServicios Recibe la lista de servicios disponibles.
/// @param sizeServicios Recibe el tamaño de la lista de servicios.
/// @return 1 si se pudo, 0 si no.
int MostrarMotosDeUnServicio(eTrabajo listaTrabajos[], int sizeTrabajos, eMoto listaMotos[], int sizeMotos, eServicio listaServicios[], int sizeServicios);

/// @brief Muestras los servicios realizados en una fecha especifica.
/// @param listaTrabajos Recibe la lista de trabajos activos.
/// @param sizeTrabajos Recibe el tamaño de la lista de trabajos.
/// @param listaServicios Recibe la lista de servicios disponibles.
/// @param sizeServicios Recibe el tamaño de la lista de servicios.
/// @return 1 si se pudo, 0 si no.
int MostrarServiciosDeUnaFecha(eTrabajo listaTrabajos[], int sizeTrabajos, eServicio listaServicios[], int sizeServicios);

#endif /* NEXO_H_ */
