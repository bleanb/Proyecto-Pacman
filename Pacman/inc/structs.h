/**
	\file structs.h
	\brief Prototipos de strcuts del juego. 
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

struct auxiliar{
    
    int puntoss;              /** Se cuentan los puntos del juego.*/
    int bonus;                /** Si esta en modo comer a los fantasmas se pone en 1.*/
    
};

/**struct que contiene las componentes x,y de la pocicion y la direccion */
struct movimiento{
    
    int x;
    int y;
    int dir;

};

/**strcut que tiene los datos del timer (minutos y segundos)*/
struct tiempos{ 
    
    int minutos;
    int segundos;
    
};


struct efectoo{
    
   int cont;                                /** Se cuentan la cantidad de comidas que se comio el pacman.*/
   int efectof;                             
    
};


#endif



 
