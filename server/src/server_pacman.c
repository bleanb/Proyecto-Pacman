/**
	\file server_pacman.c
	\brief SERVIDOR.
	\author Leandro Bellone
	\date 2017.11.20
	\version 10.0.0
*/
//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "funciones.h"


/**
	\fn int main(int argc, char *argv[])
	\brief Recibe como argumento del main el numero de puerto al que debe conocetar el scoket. Se encargar de gestionar los datos del juego con listas y enviarle datos al cliente.
	\author Landro Bellone
	\date 2017.11.20
	\return Retorna 0 (cero) si esta todo bien y -1 en caso de error.
	\bug No verifica el rango de los números ingresados.
*/


/**
    \var uno Variable para que no quede reservado el puerto.
    \var pid Variable ID para el fork.
    \var sockfd , newsockfd y puerto Son variables para sockets.
    \var n Variable auxuliar para saber la cantidad de datos leidos o enviados por read y write.
    \var salir Variable para terminar un ciclo while. 
    \var debug Variable para activar los comentarios en el terminal.    
    \var *p Puntero para partir el string recivido.
    \var *s String que almacena toda la lista con sus separadores para mandarlo por socket.
    \var *aux String de 1024 para guardar pedasos recividos por strtok.
    \var *nodo String para guardar el nodo del jugador que recive del Cliente.
    \var *salida String que guarda la palabra ingresada por el teclado para verificar si se escribio SALIR/EXIT.
*/

int main(int argc, char *argv[])
{

  /**Declaracion de variables*/

    int uno=1; 
    int pid=100;    
    int sockfd, newsockfd,puerto;  
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int n=0,salir=0,debug=0,i=0;
    char *p,*aux,*s,*box,*salida;
    
    datos jugador;
    nodo *INI=NULL;
    FILE *file1=NULL;
    
    p=NULL;
    s=NULL;
    aux=NULL;
    box=NULL;
    salida=NULL;
    
//---------------------------------------------------------------------------------------------------------
/** Inicializo variables*/
    
    s=(char*)calloc(1024,1);
    p=(char*)calloc(1024,1);
    box=(char*)calloc(1024,1);
    salida=(char*)calloc(1024,1);
    
    if(p==NULL) fprintf(stderr,"ERROR, reservando memoria con calloc\n");
    if(s==NULL) fprintf(stderr,"ERROR, reservando memoria con calloc\n");
    if(box==NULL) fprintf(stderr,"ERROR, reservando memoria con calloc\n");
    if(salida==NULL) fprintf(stderr,"ERROR, reservando memoria con calloc\n");

//-------------------------------------------------------------------------------------------------------
/**Validaciones de los argumentos*/
    
     if (argc < 2) {
         fprintf(stderr,"ERROR, no escribio el puerto.\n");
         fprintf(stderr,"Ingresar el numero de puerto como parametro, ejemplo: %s 4006\n",argv[0]);
         exit(-1);
                    }
      
//--------------------------------------------------------------------------------------------------------
/**Abriendo el socket*/

    sockfd=socket(AF_INET,SOCK_STREAM,0);
    
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (void*)&uno, (socklen_t)(sizeof(uno))); //!< Evita que quede recervado el socket luego de usarlo.
    
    if(sockfd<0) fprintf(stderr,"ERROR abriendo el socket\n");
  
//----------------------------------------------------------------------------------------------------------
/**Armando la estructura "sockaddr_in"*/
    
     puerto=atoi(argv[1]);
     serv_addr.sin_family=AF_INET;
     serv_addr.sin_addr.s_addr=INADDR_ANY;
     serv_addr.sin_port=htons(puerto);
     memset((void *)&(serv_addr.sin_zero),'\0',8); //!< Poner a cero el resto de la estructura
     
//-----------------------------------------------------------------------------------------------------------
/**conectando el socket*/
     
     if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0) fprintf(stderr,"ERROR conectando el socket\n");
     
//-----------------------------------------------------------------------------------------------------------
 
    
    pid=fork();                              //!< Pido un proceso hijo.
    
    if(pid==0){             
        /**PROCESO HIJO:*/
        while(1){
            
            listen(sockfd,1);               //!< Espero a que alguien se conecte al socket (servidor).
            
            clilen=sizeof(cli_addr);
            
            fprintf(stdout,"Esperando conexiones...\n");
            
            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);     //!< Acepto la concexion del usuario .
            
            if(newsockfd<0) fprintf(stderr,"ERROR en aceptando la conexion\n");
            
            else fprintf(stdout,"Conexion Aceptada!\n");
            
            
    //-----------------------------------------------------------------------------------------------------------
            
            
            n=read(newsockfd,box,1024);                                  //!< Recivo el nodo del jugador actual.
            
            if(debug==1) fprintf(stdout,"Paquete recivido:\n%s\n",box);
                
            if(n<0) fprintf(stderr,"ERROR en la lectura del socket\n");
               
            n=0;
            
            strcpy(p,box);                                               //!< Copio el nodo en otro vector para partirlo
                
            
         /**Armo el nodo para ponerlo en la lista del servidor*/
            aux=strtok(p,"/:");     
            strcpy(jugador.nombre,aux);
            aux=strtok(NULL,"/:");
            jugador.puntos=atoi(aux);
            aux=strtok(NULL,"/:");
            jugador.tiempo.horas=atoi(aux);
            aux=strtok(NULL,"/:");
            jugador.tiempo.minutos=atoi(aux);
            aux=strtok(NULL,"/:");
            jugador.tiempo.segundos=atoi(aux);
            
            if(debug==1){
                fprintf(stdout,"Nodo cargado:\n");
                fprintf(stdout,"%s %d %d:%d:%d\n",jugador.nombre,jugador.puntos,jugador.tiempo.horas,jugador.tiempo.minutos,jugador.tiempo.segundos);
                        }  
                    
            crear_listas_desde_archivo(&INI,file1);                       //!< Creo una lista con los datos de un archivo.
            crear_lista_ordenada_mayor_a_menor(&INI,jugador);             //!< Agrego de forma ordenada el nodo del jugador actual.
            if(debug==1)
                mostrar_lista(&INI);                                      //!< Muestro la lista si estoy en modo debug.
            guardar_lista_en_archivo_pacman(&INI,file1);                  //!< Guardo la lista actualizada en el archivo(guardo 6 puntajes).
            liberar_memoria_lista(&INI);                                  //!< libero la memoria de la lista.
            crear_listas_desde_archivo(&INI,file1);                       //!< Creo la lista con los datos del archivo.
            if(debug==1)
                mostrar_lista(&INI);                                      //!< Muestro la lista si estoy en modo debug.
            guardar_lista_en_archivo_pacman(&INI,file1);                  //!< Guardo la lista en el archivo.
                    
                    
            Crear_paquete(&INI,s);                                  //!< Crea el paquete de informacion que se va a enviar.
                                                                            
            if(debug==1){
                fprintf(stdout,"paquete de informacion enviado:%s\n",s);
                fprintf(stdout,"cantidad de bytes enviados:%d\n",(int)strlen(s));
                        }
                    
            n=write(newsockfd,s,strlen(s));                               //!< Envio el paquete de informacion.
                    
            if(n<0) fprintf(stderr,"ERROR escribiendo en el socket\n");   
                        
            n=0;
            
          
            liberar_memoria_lista(&INI);                                  //!< Libero la memoria de la lista.
            
        
            memset((void *) box, '\0', 1024);
            memset((void *) s, '\0', 1024);
            memset((void *) p, '\0', 1024);
            
            fprintf(stdout,"Conexion Cerrada!\n\n");
            
                }
        
            }
    
    else{
     /**PROCESO PADRE:*/
        while(!salir){
            i++;
            if(i==1) fprintf(stdout,"Escriba: 'salir'/'exit' para cerrar el Servidor.\n\n");
            else fprintf(stdout,"Escriba: 'salir'/'exit' para cerrar el Servidor.\n");
            scanf("%s",salida); //!< Recivo del teclado la palabara clave para terminar los procesos.
            if(strstr(salida,"salir")!=NULL || strstr(salida,"exit")!=NULL || strstr(salida,"SALIR")!=NULL || strstr(salida,"EXIT")!=NULL){  //!< Verifico que se halla escrito la condicion de salida, para matar el proceso hijo y terminar el proceso padre.
                if(debug==1) fprintf(stdout,"Matando el proceso hijo\n");  
                    kill(pid,SIGTERM);              //!< Mato el proceso hijo.
                    salir=1;
                                                                                                                                           } 
            memset((void *) salida, '\0', 1024);                
                      }
     
        }
    
    if(debug==1) fprintf(stdout,"Saliendo...\n");
    
    free(p);            //!< libero la memoria utilizada por calloc.
    free(s);            //!< libero la memoria utilizada por calloc. 
    free(box);          //!< libero la memoria utilizada por calloc.
    free(salida);       //!< libero la memoria utilizada por calloc.
    close(newsockfd);   //!< cierror el socket.
    close(sockfd);      //!< cierror el socket.
    
return 0;            
    
}
    

    
