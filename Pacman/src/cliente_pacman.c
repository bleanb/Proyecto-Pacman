/**
	\file cliente_pacman.c.
	\brief Cliente del juego que se encarga de la Comunicacion con el servidor.
	\author Leandro Bellone.
	\date 2017.11.20.
	\version 10.0.0.
*/

//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include "structs.h"


/**
	\fn int cliente(int argc, char *argv[],struct tiempos tiemposs, struct auxiliar puntos,char *nombre,char **score)
	\brief Se encarga de la Comunicacion con el servidor, envia el nodo con los datos del usuario y recive la lista del ranking.
	\date 2017.11.20
    \return Retorna -1 en caso de error y 0 en cualquier otro caso.
	\bug No verifica el rango de los números ingresados.
*/ 

int cliente(int argc, char *argv[],struct tiempos tiemposs, struct auxiliar puntos,char *nombre,char **score)
{
    int sockfd,portno,n,debug=0;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *buffer,*lista,*s,*aux;
    
    
    lista=NULL;
    s=NULL;
    aux=NULL;
    buffer=NULL;
    
     
//---------------------------------------------------------------------------------------------------------
/**Inicializo variables*/
    
    lista=(char*)calloc(1024,1);
    s=(char*)calloc(1024,1);
    aux=(char*)calloc(1024,1);
    buffer=(char*)calloc(1024,1);
    
    if(aux==NULL) fprintf(stderr,"ERROR, reservando memoria con calloc\n");
    if(s==NULL) fprintf(stderr,"ERROR, reservando memoria con calloc\n");
    if(buffer==NULL) fprintf(stderr,"ERROR, reservando memoria con calloc\n");
    if(lista==NULL) fprintf(stderr,"ERROR, reservando memoria con calloc\n");

     
//---------------------------------------------------------------------------------------------------------
/**Abro el socket*/
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0){
        fprintf(stderr,"ERROR abriendo el socket\n");
        return -1;
                   }
                   
     
//---------------------------------------------------------------------------------------------------------
/**Busco el servidor y Me conecto al servidor*/
    

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR servidor no encontrado\n");
        return -1;
    }

    memset((void *) &serv_addr, '\0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);

    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr,"ERROR en la conexion\n");
        return -1;
                                                                               }
                                                                               
     
//---------------------------------------------------------------------------------------------------------
/**Armo el nodo que voy a enviar*/
    
   
    strcpy(s,nombre);
    strcat(s,"/");
    sprintf(aux,"%d",puntos.puntoss);
    strcat(s,aux);
    strcat(s,"/");
    strcat(s,"0");
    strcat(s,":");
    memset((void *) aux, '\0', 1024);
    sprintf(aux,"%d",tiemposs.minutos);
    strcat(s,aux);
    strcat(s,":");
    memset((void *) aux, '\0', 1024);
    sprintf(aux,"%d",tiemposs.segundos);
    strcat(s,aux);
    strcat(s,"-");
    
     
//---------------------------------------------------------------------------------------------------------
/**Comunicacion con el servidor.*/
    
    
    if(debug==1) printf("s:%s\n",s);
    
    n=write(sockfd,s,strlen(s));                                    /**Envio el nodo del jugador actual por el socket.*/
        
    if(n<0) fprintf(stderr,"ERROR escribiendo en el socket\n");
    
    n=0;
    
    n=read(sockfd, lista, 1024);                                    /**Recivo la lista actualizada del servidor.*/

    if(n<0) fprintf(stderr,"ERROR leyendo en el socket\n");
            
    n=0;

    if(debug==1) fprintf(stderr,"%s\n",lista);
    
    strcpy(*score,lista);                                           /**Copio la lista recivida en el vector que la va a manejar.*/
    
    
    memset((void *) buffer, '\0', 1024);                            
    memset((void *) lista, '\0', 1024);
    memset((void *) aux, '\0', 1024);
    memset((void *) s, '\0', 1024);
    
    free(s);
    free(lista);
    free(aux);
    free(buffer);

    
    close(sockfd);
    
return 0;
}
