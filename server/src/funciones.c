
/**
	\file funciones.c
	\brief Contiene funciones que utiliza el servidor para manejar listas, etc.
	\author Leandro Bellone
	\date 2017.11.20
	\version 1.0.0
*/

//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int debug=0;
   
    
/**
	\fn  void crear_lista_ordenada_mayor_a_menor(nodo** INI,datos datos_jugador)
	\brief Recibe el inicio de la lista y el nodo a agregar.
	\date 2017.11.20
	\return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/
void crear_lista_ordenada_mayor_a_menor(nodo** INI,datos datos_jugador){
    
    nodo *p,*q,*s;
 
    
    p=(nodo*)malloc(sizeof(nodo));
    p->dato=datos_jugador;
    q=*INI;
    s=q;
    
    if(debug==1){
        fprintf(stdout,"\n");
        fprintf(stdout,"ARMANDO LA LISTA:\n");
        fprintf(stdout,"Punto igresado: %d\n",(p->dato.puntos));
                }
                
    if(q==NULL){
        *INI=p;
        p->sig=NULL;
                }
    else{
        while(q!=NULL){
            if(q->dato.puntos>=p->dato.puntos){ 
                if(q->sig==NULL){                  
                    q->sig=p;
                    p->sig=NULL;
                    break;
                                }
                if(q->sig->dato.puntos<p->dato.puntos){
                    p->sig=q->sig;
                    q->sig=p;
                    break;
                                                      }
                                                      
                                                }
            else{
                if(q->dato.puntos < p->dato.puntos){
                    *INI=p;
                    p->sig=q;
                    
                                                   }
                break;                            
                }
             
             
            s=q;
            q=q->sig;
                      }
        }

}
    
                                                                              

//******************************************************************************************************************************************************


/**
	\fn   mostrar_lista(nodo** INI)
	\brief Recibe el inicio de la lista y imprime todos los nodos.
	\date 2017.11.20
	\return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/

 void mostrar_lista(nodo** INI) {
     
      nodo *p; /* lo usamos para recorrer la lista */
      int i;
 
      i=0;
      p=*INI;
      printf("\nMostrando la lista completa:\n");
      while(p!=NULL) {
            fprintf(stdout,"Nombre: %s, Puntos: %d, Tiempo: %d:%d:%d\n",p->dato.nombre,p->dato.puntos,p->dato.tiempo.horas,p->dato.tiempo.minutos,p->dato.tiempo.segundos);
            p=p->sig;
            i++;
      }
      if (i==0) printf( "\nLa lista está vacía!!\n" );
 }
 
 

//******************************************************************************************************************************************************

/**
	\fn   void liberar_memoria_lista(nodo **INI)
	\brief Recibe el inicio de la lista y libera la memoria de cada nodo.
	\date 2017.11.20
	\return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/

 void liberar_memoria_lista(nodo **INI){
     
     
     nodo *p,*r;
     p=*INI;
     r=p;
    
     while (r!=NULL) {
         r=p->sig;
         free(p);
         p=r;
                    }
    if(debug==1)
        fprintf(stdout,"\nLista liberada!!\n");
    *INI=NULL;
     
 }
    
    

//******************************************************************************************************************************************************

/**
	\fn   int crear_listas_desde_archivo(nodo **INI,FILE *file1)
	\brief Recibe el inicio de la lista y el handle de un FILE. Abre el archivo en modo leactura y crea una lista con los datos del archivo.
	\date 2017.11.20
	\return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/


int crear_listas_desde_archivo(nodo **INI,FILE *file1){
    
    datos jugador={"    ",0,{0,0,00}};
    
    file1=fopen("assets/listaordenada.txt","r");
    
    if(file1==NULL){
        fprintf(stderr,"ERROR, Abriendo archivo de lectura\n");
        return -1;
                    }
                    
    while(!feof(file1)){
    
        fscanf(file1,"%s %d %d:%d:%d\n",jugador.nombre,&jugador.puntos,&jugador.tiempo.horas,&jugador.tiempo.minutos,&jugador.tiempo.segundos);
        if(strlen(jugador.nombre)==1)
            strcat(jugador.nombre,"     ");
        if(strlen(jugador.nombre)==2)
            strcat(jugador.nombre,"    ");
        if(strlen(jugador.nombre)==3)
            strcat(jugador.nombre,"   ");
        if(strlen(jugador.nombre)==4)
            strcat(jugador.nombre,"  ");
        if(strlen(jugador.nombre)==5)
            strcat(jugador.nombre," ");
        crear_lista_ordenada_mayor_a_menor(INI,jugador);
    
                        }
    if(debug==1){
        mostrar_lista(INI);
                }
                
    fclose(file1);
    
    return 0;
}


   
//******************************************************************************************************************************************************

/**
	\fn   int guardar_lista_en_archivo_pacman(nodo **INI,FILE *file1)
	\brief Recibe el inicio de la lista y el handle de un FILE. Abre el archivo en modo escritura y guarda la lista en el archivo (Actualiza el archivo).
	\date 2017.11.20
	\return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/    
    
int guardar_lista_en_archivo_pacman(nodo **INI,FILE *file1){
    
    int i=0,salir=0;
    nodo *p;
    
    file1=fopen("assets/listaordenada.txt","w");
    p=*INI;
    
    if(file1==NULL){
        fprintf(stderr,"ERROR, Abriendo archivo de escritura\n");
        return -1;
                    }
                                       
     do{
            fprintf(file1,"%s %d %d:%d:%d\n",p->dato.nombre,p->dato.puntos,p->dato.tiempo.horas,p->dato.tiempo.minutos,p->dato.tiempo.segundos);
            p=p->sig;
            i++;
            if(i==6)
                salir=1;
    }while(!salir);  
                
    fclose(file1);
    
return 0;
}

//******************************************************************************************************************************************************

/**
	\fn   void Crear_paquete(nodo **INI,char* s)
	\brief Recibe el inicio de la lista y un string donde se guarda el contenido de la lista separado por -,/,: para separar cada dato de los nodos.
	\date 2017.11.20
	\return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/ 

void Crear_paquete(nodo **INI,char* s){
    
    nodo *p; 
    char aux[2000];
    int i=0;
    
    for(i=0;i<=2000;i++){
     aux[i]='\0';   
    }
    
    
    
    p=*INI;
    while(p!=NULL) {
        strcat(s,p->dato.nombre);
        strcat(s,"/");
        sprintf(aux,"%d",p->dato.puntos);
        strcat(s,aux);
        strcat(s,"/");
        memset((void *) aux, '\0', 2000);
        sprintf(aux,"%d",p->dato.tiempo.horas);
        strcat(s,aux);
        strcat(s,":");
        memset((void *) aux, '\0', 2000);
        sprintf(aux,"%d",p->dato.tiempo.minutos);
        strcat(s,aux);
        strcat(s,":");
        memset((void *) aux, '\0', 2000);
        sprintf(aux,"%d",p->dato.tiempo.segundos);
        strcat(s,aux);
        strcat(s,"-");
        memset((void *) aux, '\0', 2000);
        p=p->sig;
            
      }
     
}
