/**
	\file strcust.h
	\brief Prototipos de strcust utilizadas por el servidor.
	\author Leandro Bellone
	\date 2017.11.20
	\version 1.0.0
*/

//----------------------------

//----------------
//-- Prototipos --
//----------------

#ifndef STRUCTS_H
#define STRUCTS_H


/**struct que contiene los datos del jugador*/
struct datos{
    
    char    nombre[7];
    int     puntos;
    struct time{
        
        int horas;
        int minutos;
        int segundos;   
                
    }tiempo;
    
};

typedef struct datos datos;


//-----------------------------

/**struct nodo de una lista*/
struct nodo{
    
    datos dato;
    struct nodo *sig;
       
};

typedef struct nodo nodo; 


//-----------------------------

#endif
