
/**
	\file funciones.h
	\brief Prototipos de funciones de funciones.c 
	\author Leandro Bellone
	\date 2017.11.20
	\version 1.0.0
*/

//----------------
//--- Includes ---
//----------------
#include "structs.h"

//----------------
//-- Prototipos --
//----------------

#ifndef FUNCIONESERVER_H
#define FUNCIONESSERVER_H

void crear_lista_ordenada_mayor_a_menor(nodo **INI,datos jugador1);
void mostrar_lista(nodo **INI);
void liberar_memoria_lista(nodo **INI);
int crear_listas_desde_archivo(nodo **INI,FILE *file1);
int guardar_lista_en_archivo(nodo **INI,FILE *file1);
int guardar_lista_en_archivo_pacman(nodo **INI,FILE *file1);
void Crear_paquete(nodo **INI,char *s);

#endif
