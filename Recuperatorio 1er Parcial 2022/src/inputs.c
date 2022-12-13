/*
 * inputs.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Santiago
 */

#include "inputs.h"

int MostrarMenu()
{
	int opcion;

	printf("\n----------------------------------------\n"
			"            Menu Principal\n"
			"1. Alta moto\n"
			"2. Modificar moto\n"
			"3. Baja moto\n"
			"4. Listar motos\n"
			"5. Listar tipos\n"
			"6. Listar colores\n"
			"7. Listar servicios\n"
			"8. Alta trabajos\n"
			"9. Listar trabajos\n"
			"10. Informe complementarios\n"
			"11. Salir\n"
			"----------------------------------------\n");

	opcion = ElegirOpcion(11, 1);

	return opcion;
}

int MenuModificacion()
{
	int opcion;

	printf("\n----------------------------------------\n"
			"             Modificaciones\n"
			"1. Color\n"
			"2. Puntaje\n"
			"----------------------------------------\n");

	opcion = ElegirOpcion(2, 1);

	return opcion;
}

int MostrarMenuInformes()
{
	int opcion;

	printf("\n----------------------------------------\n"
			"             Informes\n"
			"1. Mostrar motos de un color\n"
			"2. Promedio puntaje de un tipo\n"
			"3. Motos de mayor cilindrada\n"
			"4. Mostrar motos separadas por tipo\n"
			"5. Mostrar cantidad motos de un color y tipo\n"
			"6. Mostrar el color mas elegido\n"
			"----------------------------------------\n");
	opcion = ElegirOpcion(6, 1);

	return opcion;
}

int PedirID()
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

	return id;
}

int ElegirOpcion(int max, int min)
{
	char opcion[50];
	int validar;
	int opcionElegida;

	validar = getStringNumeros("Ingrese una opción: ", opcion);
	opcionElegida = atoi(opcion);
	while(validar == 0 || (opcionElegida > max || opcionElegida < min))
	{
		validar = getStringNumeros("ERROR, Ingrese una opción valida: ", opcion);
		opcionElegida = atoi(opcion);
	}

	return opcionElegida;
}

int PedirEntero()
{
	int unEntero;

	scanf("%d", &unEntero);

	while(isdigit(unEntero) != 0)
	{
		printf("ERROR, debe ingresar un numero\n");
		fflush(stdin);
		scanf("%d", &unEntero);
	}

	return unEntero;
}

void PedirMarca(char marca[])
{
	printf("Ingrese una marca: ");
	fflush(stdin);
	gets(marca);
}

int PedirCilindrada()
{
	char cilindradaAux[10];
	int validar;
	int cilindrada;

	validar = getStringNumeros("Ingrese una cilindrada (50 - 125 - 500 - 600 - 750): ", cilindradaAux);
	cilindrada = atoi(cilindradaAux);
	while(validar == 0 || (cilindrada != 50 && cilindrada != 125 && cilindrada != 500 && cilindrada != 600 && cilindrada != 750))
	{
		validar = getStringNumeros("ERROR, Ingrese una cilindrada valida (50 - 125 - 500 - 600 - 750): ", cilindradaAux);
		cilindrada = atoi(cilindradaAux);
	}

	return cilindrada;
}

int PedirPuntaje()
{
	char puntajeAux[10];
	int validar;
	int puntaje;

	validar = getStringNumeros("Ingrese un puntaje: ", puntajeAux);
	puntaje = atoi(puntajeAux);
	while(validar == 0 || (puntaje < 1 && puntaje > 10))
	{
		validar = getStringNumeros("ERROR, Ingrese un puntaje valido: ", puntajeAux);
		puntaje = atoi(puntajeAux);
	}

	return puntaje;
}

int PedirDia()
{
	int dia;

		printf("\nIngrese el dia: ");
		dia = PedirEntero();
		while(dia < 1 || dia > 31)
		{
			printf("\nERROR, Ingrese un dia valido: ");
			dia = PedirEntero();
		}

	return dia;
}

int PedirMes()
{
	int mes;

	printf("\nIngrese el mes: ");
	mes = PedirEntero();
	while(mes < 1 || mes > 12)
	{
		printf("\nERROR, Ingrese un mes valido: ");
		mes = PedirEntero();
	}

	return mes;
}

int PedirAnio()
{
	int anio;

	printf("\nIngrese el año: ");
	anio = PedirEntero();
	while(anio < 0 || anio > 10000)
	{
		printf("\nERROR, Ingrese un año valido: ");
		anio = PedirEntero();
	}

	return anio;
}

void PedirString(char* mensaje, char* nombre)
{
	int validar;

	validar= getStringLetras(mensaje, nombre);
	while(validar == 0 || strcmp(nombre, "")==0)
	{
		validar= getStringLetras(mensaje, nombre);
	}

}

void PedirSexo(char* mensaje, char* nombre)
{
	PedirString(mensaje, nombre);
	while(strcmp(nombre, "Masculino")!=0 && strcmp(nombre, "Femenino")!=0)
	{
		PedirString(mensaje, nombre);
	}
}


