
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

#ifndef FUNCIONES_H
#define FUNCIONES_H

//------------------------------------------------------------------------------------------
//SERVER/CLIENTE:

int cliente(int argc, char *argv[],struct tiempos tiemposs, struct auxiliar puntos,char *nombre,char **score);

//------------------------------------------------------------------------------------------
//BITMAPS:

void init_pantalla_load(void);

void init_bitmaps_load(void);

void init_pantalla(void);

void init_clear(int /*BUFFER*//*PACMAN*//*SCREEN...*/);

void init_bitmaps(void);

void destroy_bitmaps(void);

struct efectoo init_mapa(struct movimiento /*PACMAN*/,struct movimiento /*FANTASMA1*/,struct movimiento /*FANTASMA2*/,struct auxiliar *p ,int /*REDINUJAR*//*MAPEADO NORMAL*/,struct efectoo /*EFECTO*/,int /*ESTADO DEL TIMER*/,int /*NIVEL*/);



//------------------------------------------------------------------------------------------
//MENUES:

void init_error_conexion(struct tiempos /*TIEMPO*/, struct auxiliar /*PUNTOS*/,char* /*NOMBRE*/);

void score_en_error(struct tiempos /*TIEMPO*/, struct auxiliar /*PUNTOS*/,char* /*NOMBRE*/);

void init_pantallaUSUARIO(int /*PANTALLA_USUARIO*//*PANTALLA_SCORE*//*PANTALLA_SCORE2*/);

void Ingreso_Usuario(char* /*NOMBRE*/);

int menu_2(void);

int init_lose(void);

void init_win(void);

int menu_inicio(void);

void score_pantalla(char* /*LISTA DE SCORES*/,struct tiempos /*TIEMPO*/, struct auxiliar /*PUNTOS*/,char* /*NOMBRE*/);


//------------------------------------------------------------------------------------------
//TIEMPO:

void min(void);

void seg(void);

void seg2(void);

void seg3(void);

void segtramp(void);

int tiempo(struct tiempos* /*TIME*/ ,int /*ESTADO DEL TIMER*/);

//------------------------------------------------------------------------------------------
//PUNTUACION:

void init_puntuacion(int /*VIDAS*/,int /*CONTADOR DE COMIDA*/);

//------------------------------------------------------------------------------------------
//FANTASMAS:

int choquef1(struct movimiento /*PACMAN*/,struct movimiento* /*FANTASMA1*/,struct movimiento* /*FANTASMA2*/,int /*POS X ANTERIOR PACMAN*/,int /*POS X ANTERIOR PACMAN*/,int /*VIDA*/,struct auxiliar* p,struct efectoo /*EFECTO*/,int /*ESTADO DEL TIMER*/,int /*POS X ANTERIOR FANTASMA1*/,int /*POS Y ANTERIOR FANTASMA1*/,int /*NIVEL*/);

int choquef2(struct movimiento /*PACMAN*/,struct movimiento* /*FANTASMA1*/,struct movimiento* /*FANTASMA2*/,int /*POS X ANTERIOR PACMAN*/,int /*POS X ANTERIOR PACMAN*/,int /*VIDA*/,struct auxiliar* p,struct efectoo /*EFECTO*/,int /*ESTADO DEL TIMER*/,int /*POS X ANTERIOR FANTASMA1*/,int /*POS Y ANTERIOR FANTASMA1*/,int /*NIVEL*/);

void init_fantasma(struct movimiento /*FANTASMA1*/,struct auxiliar /*PUNTOS*/,int /*MODO COMER FANTASMA*/);

void init_fantasma2(struct movimiento /*FANTASMA2*/,struct auxiliar /*PUNTOS*/,int /*MODO COMER FANTASMA*/);

struct movimiento movimiento_fantasma1(struct movimiento /*FANTASMA1*/,struct movimiento /*FANTASMA2*/);

struct movimiento movimiento_fantasma2(struct movimiento /*FANTASMA1*/,struct movimiento /*FANTASMA2*/);


//------------------------------------------------------------------------------------------
//PACMAN:

void init_pacman(struct movimiento /*PACMAN*/);

void init_bit(struct movimiento /*PACMAN*/);

struct movimiento movimiento_pacman(struct movimiento /*PACMAN*/,struct auxiliar /*PUNTOS*/);


//------------------------------------------------------------------------------------------
//MUSICA:

void musica_bonus(struct auxiliar /*PUNTOS*/,int i,struct efectoo /*MODO COMER FANTASMA*/);

//------------------------------------------------------------------------------------------
//CARTELES:

int init_pausa(void);

int init_ready(void);


//*****************************************************************************************************************************************************
//*****************************************************************************************************************************************************

//NIVEL 2:

void trampas(int /*ESTADO DEL TIMER*/);

struct movimiento movimiento_pacmanlvl2(struct movimiento /*PACMAN*/,struct auxiliar /*PUNTOS*/);

struct movimiento movimiento_fantasma1lvl2(struct movimiento /*FANTASMA1*/,struct movimiento /*FANTASMA2*/);

struct movimiento movimiento_fantasma2lvl2(struct movimiento /*FANTASMA1*/,struct movimiento /*FANTASMA2*/);

void init_lvl2(void);



#endif
