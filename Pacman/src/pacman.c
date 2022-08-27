/**
	\file pacman.c.
	\brief Loop del game.
	\author Leandro Bellone.
	\date 2017.11.20.
	\version 10.0.0.
*/
//--------------
//-- Includes --
//--------------
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
#include "defines.h"


#define GANAR1 0    /**poner 200 si quiere ganar antes el lvl1.*/ 
#define GANAR2 0    /**poner 190 si quiere ganar antes el lvl2.*/
/**
\def GANAR1 variando el valor de este define modificas la cantidad de bolitas que tenes que comer para pasar el nivel 1.
\def GANAR2 variando el valor de este define modificas la cantidad de bolitas que tenes que comer para pasar el nivel 2.
*/

//*************************************************************************************************************************************************************

/**
	\fn int main(int argc, char *argv[])
	\brief Recibe como argumento del main el numero de ip del servidor y el numero de puerto al que debe conocetar el scoket.Se encarga de el loop del juego.
	\author Landro Bellone
	\date 2017.11.20
	\return Retorna 0 (cero). 
	\bug No verifica el rango de los números ingresados.
*/

/**
    \var velocidad Variable que tiene la velocidad del pacman y los fantasmas.
    \var vidas Variable que tiene la cantidad de vidas de Pacman.
    \var choq Variable que tiene el estado de pacman, si choco con un fantasma o no.
    \var anteriorpx , anteriorpy , anteriorfpy , anteriorfpx , anteriorf2py , anteriorf2px Variables que contienen las componentes x,y de la pocicion de los fantasmas y Pacman.
    \var empezar_de_nuevo Variable que tiene el estado de si tiene que empezar de nuevo el juego. 
    \var volver_empezar Variable que tiene el estado de si tiene que empezar de nuevo el juego. 
    \var exit , salir , salir2 Variables que tienen el estado true o false para salir de un loop.
    \var serveroff Variable que indica si se pudo ingreso un ip y puerto para jugar con el SERVIDOR.
    \var estado_timer Variable que tiene los estados del timer (Pausa del timer, reinicio del timer, timer en accion).
    \var lvl2   Variable para ingresar al lvl 2.
    \var nombre String que contiene el nombre del usuario que va a jugar.
*/

int main(int argc, char *argv[]) {
 
/**DECLARACION DE VARIABLES.*/    

      
    int velocidad=25;
    int inicio=0,pausa=0,vidas=5,choq=3,debug=0;
    int anteriorpx=0,anteriorpy=0,anteriorfpx=0,anteriorfpy=0,anteriorf2px=0,anteriorf2py=0;
    int salir=0,salir2=0,aux=0,empezar_de_nuevo=0,volver_empezar=0,exit=0;
    int estado_timer=1,i=0,lvl2=0,terminar=0,conexion=0,serveroff=0;
    char nombre[7],*score;
    struct movimiento pacman,fantasma1,fantasma2,*fantasma1p,*fantasma2p;
    struct tiempos tiemposs, *times=NULL;
    struct auxiliar puntos;
    struct efectoo efecto;
    
    score=(char*)malloc(2000);
    
    fantasma1p=&fantasma1;
    fantasma2p=&fantasma2;
    times=&tiemposs;
    
    
/**Inicio el vector:*/  
    for(i=0;i<2000;i++)
        score[i]='\0';
    
    for(i=0;i<7;i++)
        nombre[i]='A';
    
/**Inicio las struct:*/      

    pacman.x=30*14;
    pacman.y=30*13;
    pacman.dir=0;
    fantasma1.x=30*15;
    fantasma1.y=30*10;
    fantasma1.dir=0;
    fantasma2.x=30*13;
    fantasma2.y=30*11;
    fantasma2.dir=0;
    puntos.puntoss=0;
    puntos.bonus=0;
    efecto.cont=GANAR1;
    efecto.efectof=0;
    
    
    if (argc < 3) {
        fprintf(stderr,"SI QUIERES JUGAR CON SERVIDOR NECESITAS USAR:\nUsar %s /*IP DEL SERVIDOR*/ /*NUMERO DE PUERTO*/\n", argv[0]);
        serveroff=1;
                   }
                   
   
   
    
//---------------------------------------------------------------------------------------------------------- 
/**INICIO ALLEGRO:*/
    
    srand(time(NULL));                                         //!< Inicia la semilla para la funcion rand(); para los movimientos aleatoreos de los fantasmas.
    allegro_init();                                            //!< Inicia a allegro.
    install_sound(100,100,"");                                 //!< Inicia la musica con el volumen en 100,100.
    install_mouse();                                           //!< Inicia el mause.
    install_keyboard();                                        //!< Inicia el teclado.
    install_timer();                                           //!< Inicia los timers.
    set_color_depth(32);                                       //!< Fija un color para la transparencia.
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,870,630,0,0);         //!< Crea una ventana con las dimenciones 870x630
        
    init_bitmaps_load();                                       //!< Inicia los bitmaps de la pantalla de loading
    init_pantalla_load();                                      //!< Inicia la pantalla de loading (dentro de esta funcion tambien inicia los bitmaps de todo el juego, mientras muestra la pantalla de loading).
    

    i=0;
    
//*************************************************************************************************************************************************************    
/**MENU INICIO:*/ 

    exit=menu_inicio();                                       //!< Inicia el menu de inicio.
    if(exit==2)                                               
        vidas=10; 
    if(exit==0){                                              //!< Condicion de exit del juego en el menu.
        salir=1;
        terminar=1;
                }
    else{
        
        Ingreso_Usuario(nombre);                               //!< Inicia el menu de ingreso de nombre de usuario.
        init_pantallaUSUARIO(PANTALLA_USUARIO);                //!< Escribe en la pantalla el nombre ingresado.
        init_clear(_BUFFER);                                   //!< Limpia el buffer.
        
        
        if(debug==1)
            fprintf(stdout,"salgo de la pantalla de igreso usuario\n");
        
//*************************************************************************************************************************************************************    
/**EMPIEZA JUEGO:*/
                                                                    
    do{                                                           
        if(empezar_de_nuevo!=0){                            //!< Condicion de comienzo de nuevo.
            init_clear(_BUFFER);
            init_clear(_PACMAN);
            init_clear(_SCREEN);
            if(debug==1)
                fprintf(stdout,"\n\n\nEMPEZAR DE NUEVO\n\n\n\n\n\n");
            estado_timer=REINICIAR_TIMER;                   //!< Reinicia el timer.
            efecto=init_mapa(pacman,fantasma1,fantasma2,&puntos,REDIBUJAR,efecto,estado_timer,NIVEL1);  //!< Inicia el Mapeado.
            salir=0;
            efecto.cont=GANAR1;
            puntos.puntoss=0;
            vidas=5;
            pacman.x=30*14;
            pacman.y=30*13;
            fantasma1.x=30*15;
            fantasma1.y=30*10;
            fantasma2.x=30*13;
            fantasma2.y=30*11;
            inicio=0;
                 }

//----------------------------------------------------------------------------------------------------------  
       
    while (!salir){             //!< Loop principar del juego.
    
        
        tiempo(times,estado_timer);             //!< Empieza a contar el timer.
        estado_timer=EMPEZAR_TIMER;             //!< Timer en accion.  
        anteriorpx=pacman.x;
        anteriorpy=pacman.y;
        anteriorfpx=fantasma1.x;
        anteriorfpy=fantasma1.y;
        anteriorf2px=fantasma2.x;
        anteriorf2py=fantasma2.y;
        
        if(puntos.bonus==1)
            i++;
        if(puntos.bonus==0)
            i=0;
        
        if(pausa==1)
            i=0;
            
    
                
        musica_bonus(puntos,i,efecto);                          //!< Inicia la musica.
        
        if(pausa==1){                                           //!< Condicion de pausa.
                estado_timer=PAUSAR_TIMER;                      //!< Se pone pausa el timer.
                efecto=init_mapa(pacman,fantasma1,fantasma2,&puntos,MAPEADO_NORMAL,efecto,estado_timer,NIVEL1);                                                             
                init_pacman(pacman);                                                             
                init_fantasma(fantasma1,puntos,efecto.efectof);
                init_fantasma2(fantasma2,puntos,efecto.efectof);
                init_puntuacion(vidas,puntos.puntoss);
                tiempo(times,estado_timer);
                init_pausa();                                   //!< Imprime el cartel "READY".
                init_pantalla();                                //!< Imprime la pantalla.
                if(key[KEY_ESC]){                               //!< Condcion para entrar al menu.                                                                           
                    aux=menu_2();                                                                              
                    if(aux==0){                                                                                
                        salir=1;
                        empezar_de_nuevo=0;
                        terminar=1;
                                }
                    if(aux==1){
                        salir=1;
                        empezar_de_nuevo=1;
                        estado_timer=REINICIAR_TIMER;
                            }  
                                }                                
                if(key[KEY_LEFT]||key[KEY_RIGHT]||key[KEY_UP]||key[KEY_DOWN])                           
                    pausa=0;
                   
                     } 
                     
//----------------------------------------------------------------------------------------------------------                    
                    
        else{   
                if(inicio==0){ 
                     
                    init_fantasma(fantasma1,puntos,efecto.efectof);     //!< Inicia los fantasmas.
                    init_fantasma2(fantasma2,puntos,efecto.efectof);    //!< Inicia los fantasmas.
                    estado_timer=PAUSAR_TIMER;  
                    efecto=init_mapa(pacman,fantasma1,fantasma2,&puntos,MAPEADO_NORMAL,efecto,estado_timer,NIVEL1);       //!< Inicia el Mapeado.                                                   
                    init_pacman(pacman);                    //!< Inicia el Pacman.
                    init_puntuacion(vidas,puntos.puntoss);  //!< Inicia el la franja de puntajes , vida y timer.
                    init_ready();                           //!< Imprime el cartel "READY".
                    tiempo(times,estado_timer);
                    init_pantalla();                        //!< Imprime la pantalla.
                    if(key[KEY_ESC]){                       //!< Condcion para entrar al menu.                              
                        aux=menu_2();                                                                              
                        if(aux==0){                                                                                
                            salir=1;
                            empezar_de_nuevo=0;
                            terminar=1;
                                }
                        if(aux==1){
                            salir=1;
                            empezar_de_nuevo=1;
                            estado_timer=REINICIAR_TIMER;
                                    } 
                                        }
                    if(key[KEY_LEFT]||key[KEY_RIGHT]||key[KEY_UP]||key[KEY_DOWN])                           
                        inicio=100;                                                                         
                            }
                            
//----------------------------------------------------------------------------------------------------------                          
                        /**Movimiento de Pacman tomado por el teclado*/
                else{  
                   
                    if(key[KEY_LEFT]){                                                                   //!< IZQUIERDA.
                        pacman.dir=IZQUIERDA;        
                    }
                    if(key[KEY_RIGHT]){                                                                  //!< DERECHA.
                        pacman.dir=DERECHA;                                                                          
                    }
                    if(key[KEY_UP]){                                                                     //!< ARRIBA.
                        pacman.dir=ARRIBA;                                                                          
                    }
                    if(key[KEY_DOWN]){                                                                   //!< ABAJO.
                        pacman.dir=ABAJO;                                                                          
                    }
                    
                    pacman=movimiento_pacman(pacman,puntos);                                            //!< Imprime el movimiento del Pacman   
                    fantasma1=movimiento_fantasma1(fantasma1,fantasma2);                                //!< Imprime el movimiento del fantasma1.
                    fantasma2=movimiento_fantasma2(fantasma2,fantasma1);                                //!< Imprime el movimiento del fantasma2.
                    
                    
                    
//********************************************************************************************************************************************************     
                                                          /**ATAJOS:*/ 
                                                  
/**ATAJO PARA PACMAN.*/ 
                        
                    if(pacman.x<=-30){                      
                        pacman.x=870;
                                }
                    else{
                        if(pacman.x==870){
                        pacman.x=-30;
                                }
                        }
            
//---------------------------------------------------------------------------------------------------------- 
/**ATAJO PARA EL FANTASMA1.*/
                
                    if(fantasma1.x<=-30){                     
                        fantasma1.x=870;
                                }       
                    else{   
                        if(fantasma1.x==870){
                            fantasma1.x=-30;
                                    }
                        }
                                
//----------------------------------------------------------------------------------------------------------                   
/**ATAJO PARA EL FANTASMA2.*/

                    if(fantasma2.x<=-30){                     
                        fantasma2.x=870;
                                }       
                    else{
                        if(fantasma2.x==870){
                            fantasma2.x=-30;
                                    }
                        }
                                     
                    
//******************************************************************************************************************************************************** 
                    
    
                    init_clear(_BUFFER);                                                                            //!< Clear(buffer).borro el buffer de la panatalla.
                    tiempo(times,estado_timer);
                    efecto=init_mapa(pacman,fantasma1,fantasma2,&puntos,MAPEADO_NORMAL,efecto,estado_timer,NIVEL1); //!< Dibujo el mapa y cuento cuantas comidas hay dibujadas.
                    init_fantasma(fantasma1,puntos,efecto.efectof);                                                 //!< Dibujo al primer fantasma.
                    init_fantasma2(fantasma2,puntos,efecto.efectof);                                                //!< Dibujo al segundo fantasma.
                    init_pacman(pacman);                                                                            //!< Dibujo al pacman.
                    choq=choquef1(pacman,fantasma1p,fantasma2p,anteriorpx,anteriorpy,vidas,&puntos,efecto,estado_timer,anteriorfpx,anteriorfpy,NIVEL1);    
                    if(choq==1){                                                                //!< Condicion si choca con el primer fantasma.
                        vidas--;                                                                //!< Resto una vida.
                        rest(200);                                                              /**Colo al Pacman y a los fantasmas en su pocicion inicial*/
                        pacman.x=30*14;
                        pacman.y=30*13;
                        fantasma1.x=30*15;
                        fantasma1.y=30*10;
                        fantasma2.x=30*13;
                        fantasma2.y=30*11;                                                         
                        inicio=0;                                                               
                        if(debug==1)
                            fprintf(stdout,"PAUSA\nPunto=%d\nVidas=%d\n",puntos.puntoss,vidas);                           
                                }
                    if(choq==0){                                                                //!< Condicion si choca con el primer fantasma pero en modo bonus.
                        puntos.puntoss+=100;                                                    //!< Suma 100 puntos por comerte al fantasma.
                        fantasma1.x=30*13;                                                      /**Coloco al fantasma en su pocicion inicial*/
                        fantasma1.y=30*11;
                        fantasma1.dir=0;
                                }
            
                    choq=choquef2(pacman,fantasma2p,fantasma1p,anteriorpx,anteriorpy,vidas,&puntos,efecto,estado_timer,anteriorf2px,anteriorf2py,NIVEL1);//  
                    if(choq==1){                                                                //!< Condicion si choca con el segundo fantasma.
                        vidas--;                                                                //!< Resto una vida.
                        rest(200);                                                              /**Colo al Pacman y a los fantasmas en su pocicion inicial*/
                        pacman.x=30*14;
                        pacman.y=30*13;
                        fantasma1.x=30*15;
                        fantasma1.y=30*10;
                        fantasma2.x=30*13;
                        fantasma2.y=30*11;
                        inicio=0;
                        if(debug==1)
                            fprintf(stdout,"PAUSA\nPunto=%d\nVidas=%d\n",puntos.puntoss,vidas);
                            }
                     if(choq==0){                                                                 //!< Condicion si choca con el segundo fantasma pero en modo bonus.
                        puntos.puntoss+=100;                                                      //!< Suma 100 puntos por comerte al fantasma.
                        fantasma2.x=30*13;                                                        /**Coloco al fantasma en su pocicion inicial*/
                        fantasma2.y=30*11;
                        fantasma2.dir=0;
                                }
                            
                    tiempo(times,estado_timer);
                    init_puntuacion(vidas,puntos.puntoss);                                          //!< Coloca la franja con el puntaje, las vidas y el timer.
                    tiempo(times,estado_timer);
                    init_pantalla();                                                                //!< Imprime la pantalla.
                    //rest(velocidad);
                    if(inicio!=0){
                        init_bit(pacman);
                           }
                    tiempo(times,estado_timer);
                    init_puntuacion(vidas,puntos.puntoss); 
                    tiempo(times,estado_timer);
                    init_pantalla();
                    rest(velocidad);                                                                
            
//----------------------------------------------------------------------------------------------------------      
/**PAUSA DEL JUEGO (TECLA SPACE).*/

                    if(key[KEY_SPACE]){                                             
                        pausa=1;
                        init_clear(_BUFFER);
                        init_clear(_PACMAN);
                        if(debug==1)
                            fprintf(stdout,"PAUSA\nPunto=%d\nVidas=%d\n",puntos.puntoss,vidas);
                              }  
            
            
//----------------------------------------------------------------------------------------------------------  
/**PERDISTE.*/
        
                    if(vidas==0){                                           //!< Condicion en la que perdiste todas las vidas.
                         //AGREGAR CONEXCION CON EL SERVIDOR.
                        volver_empezar=init_lose();                         //!< Imprime la pantalla de PERDISTE.
                        if(volver_empezar==1){                              //!< Condicion de empezar de nuevo.
                            if(debug==1)
                                fprintf(stdout,"APRETASTE TRY AGAIN\n");
                            salir=1;
                            empezar_de_nuevo=1;
                            terminar=0;
                                        }
                        if(volver_empezar==0){                              //!< Condicion de EXIT.
                            salir=1;
                            empezar_de_nuevo=0;
                            terminar=1;
                                            }
                                }
                                
//----------------------------------------------------------------------------------------------------------                            
                    if(debug==1)
                        fprintf(stderr,"efecto.cont:%d\n",efecto.cont);   
                    
/**GANASTE el nivel 1.*/
                    
                    if(efecto.cont==211){                   //!<  Condicion en la que comiste todas las bolitas y GANASTE el nivel.                         
                        
                        init_clear(_BUFFER);                //!< Limpia el buffer.
                        init_clear(_PACMAN);                //!< Limpia el Pacman.
                        init_clear(_SCREEN);                //!< Limpia la Pantalla.
                        if(debug==1)    
                            fprintf(stderr,"EMPEZAR LVL 2\n\n\n\n\n\n");        //!< Empieza el nivel 2.  
                        estado_timer=EMPEZAR_TIMER;         //!< Timer en accion.          
                        efecto=init_mapa(pacman,fantasma1,fantasma2,&puntos,REDIBUJAR,efecto,estado_timer,NIVEL2);
                        salir=0;                        /**Colo a los fantasmas y a Pacman en su lugar inicial del nivel 2*/
                        efecto.cont=GANAR2;                   
                        puntos.bonus=0;
                        pacman.x=30*14;
                        pacman.y=30*13;
                        fantasma1.x=30*15;
                        fantasma1.y=30*10;
                        fantasma2.x=30*13;
                        fantasma2.y=30*11;
                        inicio=0;
                        musica_bonus(puntos,0,efecto);
                        lvl2=1;
                        salir2=0;
                    
                        if(lvl2==1){        
                            while(lvl2){            //!< LOOP GAME del nivel 2.   
                                init_pacman(pacman); 
                                init_fantasma(fantasma1,puntos,efecto.efectof);
                                init_fantasma2(fantasma2,puntos,efecto.efectof);
                                efecto=init_mapa(pacman,fantasma1,fantasma2,&puntos,MAPEADO_NORMAL,efecto,estado_timer,NIVEL2);
                                init_lvl2();
                                init_pantalla();
                                rest(200);
                                if(key[KEY_LEFT]||key[KEY_RIGHT]||key[KEY_UP]||key[KEY_DOWN])  
                                    lvl2=0;
                                        }
                                    }
                                    while(!salir2){
                                                    
                                            trampas(REINICIAR_TIMER);                   //!< Inicia el cambio de los muros.
                                            tiempo(times,estado_timer);
                                            estado_timer=EMPEZAR_TIMER;
                                            anteriorpx=pacman.x;
                                            anteriorpy=pacman.y;
                                            anteriorfpx=fantasma1.x;
                                            anteriorfpy=fantasma1.y;
                                            anteriorf2px=fantasma2.x;
                                            anteriorf2py=fantasma2.y;
                                            
                                            musica_bonus(puntos,i,efecto);
                                            
                                            if(pausa==1){ 
                                                    estado_timer=PAUSAR_TIMER;
                                                    trampas(estado_timer);
                                                    efecto=init_mapa(pacman,fantasma1,fantasma2,&puntos,MAPEADO_NORMAL,efecto,estado_timer,NIVEL2);                                                             
                                                    init_pacman(pacman);                                                             
                                                    init_fantasma(fantasma1,puntos,efecto.efectof);
                                                    init_fantasma2(fantasma2,puntos,efecto.efectof);
                                                    init_puntuacion(vidas,puntos.puntoss);
                                                    tiempo(times,estado_timer);
                                                    init_pausa();
                                                    init_pantalla();  
                                                    if(key[KEY_ESC]){ 
                                                        aux=menu_2();                                                                              
                                                        if(aux==0){                                                                                
                                                            salir=1;
                                                            salir2=1;
                                                            empezar_de_nuevo=0;
                                                            terminar=1;
                                                                    }
                                                        if(aux==1){
                                                            salir=1;
                                                            salir2=1;
                                                            empezar_de_nuevo=1;
                                                            estado_timer=REINICIAR_TIMER;
                                                                }  
                                                                    }                                
                                                    if(key[KEY_LEFT]||key[KEY_RIGHT]||key[KEY_UP]||key[KEY_DOWN])                           
                                                        pausa=0;
                                                    
                                                        } 
                                                        
//----------------------------------------------------------------------------------------------------------                    
                                                        
                                            else{   
                                                    if(inicio==0){ 
                                                        init_fantasma(fantasma1,puntos,efecto.efectof);
                                                        init_fantasma2(fantasma2,puntos,efecto.efectof);
                                                        estado_timer=PAUSAR_TIMER;
                                                        efecto=init_mapa(pacman,fantasma1,fantasma2,&puntos,MAPEADO_NORMAL,efecto,estado_timer,NIVEL2);                                                          
                                                        init_pacman(pacman);  
                                                        init_puntuacion(vidas,puntos.puntoss);
                                                        init_ready();
                                                        tiempo(times,estado_timer);
                                                        trampas(estado_timer);
                                                        init_pantalla();
                                                        if(key[KEY_ESC]){                                                                              
                                                            aux=menu_2(); 
                                                            trampas(estado_timer);
                                                            if(aux==0){                                                                                
                                                                salir=1;
                                                                salir2=1;
                                                                empezar_de_nuevo=0;
                                                                terminar=1;
                                                                    }
                                                            if(aux==1){
                                                                salir=1;
                                                                salir2=1;
                                                                empezar_de_nuevo=1;
                                                                estado_timer=REINICIAR_TIMER;
                                                                        } 
                                                                            }
                                                        if(key[KEY_LEFT]||key[KEY_RIGHT]||key[KEY_UP]||key[KEY_DOWN])                           
                                                            inicio=100;                                                                         
                                                                }
                                                                
//----------------------------------------------------------------------------------------------------------                          
                        /**Movimiento de pacman por teclado*/
                                              
                                                    else{  
                                                    
                                                        if(key[KEY_LEFT]){                                                                   /**IZQUIERDA.*/
                                                            pacman.dir=0;        
                                                        }
                                                        if(key[KEY_RIGHT]){                                                                  /**DERECHA.*/
                                                            pacman.dir=1;                                                                          
                                                        }
                                                        if(key[KEY_UP]){                                                                     /**ARRIBA.*/
                                                            pacman.dir=2;                                                                          
                                                        }
                                                        if(key[KEY_DOWN]){                                                                   /**ABAJO.*/
                                                            pacman.dir=3;                                                                          
                                                        }
                                                        
                                                        pacman=movimiento_pacmanlvl2(pacman,puntos);
                                                        fantasma1=movimiento_fantasma1lvl2(fantasma1,fantasma2);
                                                        fantasma2=movimiento_fantasma2lvl2(fantasma2,fantasma1);
                                                        
                                                        
                                                        
//********************************************************************************************************************************************************     
                                                                                            /*ATAJOS de nivel 2:*/ 
                                                                                    
/**ATAJO PARA PACMAN.*/ 
                                                            
                                                        if(pacman.x<=-30){                      
                                                            pacman.x=870;
                                                                    }
                                                        else{
                                                            if(pacman.x==870){
                                                            pacman.x=-30;
                                                                    }
                                                            }
                                                
//---------------------------------------------------------------------------------------------------------- 
/**ATAJO PARA EL FANTASMA1.*/
                                                    
                                                        if(fantasma1.x<=-30){                     
                                                            fantasma1.x=870;
                                                                    }       
                                                        else{   
                                                            if(fantasma1.x==870){
                                                                fantasma1.x=-30;
                                                                        }
                                                            }
                                                            
//----------------------------------------------------------------------------------------------------------                   
/**ATAJO PARA EL FANTASMA2.*/ 

                                                        if(fantasma2.x<=-30){                     
                                                            fantasma2.x=870;
                                                                    }       
                                                        else{
                                                            if(fantasma2.x==870){
                                                                fantasma2.x=-30;
                                                                        }
                                                            }
                                                                        
                                                        
                                                            
                                            
                                                            
//******************************************************************************************************************************************************** 
                                                         
                                        
                                                        init_clear(_BUFFER);                                                         //!<Clear(buffer).borro el buffer de la panatalla.
                                                        tiempo(times,estado_timer);
                                                        efecto=init_mapa(pacman,fantasma1,fantasma2,&puntos,MAPEADO_NORMAL,efecto,estado_timer,NIVEL2);//!<Dibujo el mapa y cuento cuantas comidas hay dibujadas.
                                                        init_fantasma(fantasma1,puntos,efecto.efectof);                                                 //!<Dibujo al primer fantasma.
                                                        init_fantasma2(fantasma2,puntos,efecto.efectof);                                              //!<Dibujo al segundo fantasma.
                                                        init_pacman(pacman);                                                 //!<Dibujo al pacman.
                                                        choq=choquef1(pacman,fantasma1p,fantasma2p,anteriorpx,anteriorpy,vidas,&puntos,efecto,estado_timer,anteriorfpx,anteriorfpy,NIVEL2);    
                                                        if(choq==1){                                                                //!< Condicion si choca con el primer fantasma.
                                                            vidas--;                                                                //!< Resto una vida.
                                                            rest(200);                                                              /**Colo al Pacman y a los fantasmas en su pocicion inicial*/
                                                            pacman.x=30*14;
                                                            pacman.y=30*13;
                                                            fantasma1.x=30*15;
                                                            fantasma1.y=30*10;
                                                            fantasma2.x=30*13;
                                                            fantasma2.y=30*11;                                                         
                                                            inicio=0;   
                                                            if(debug==1)                                                            
                                                                fprintf(stdout,"Puntos=%d\nVidas=%d\n",puntos.puntoss,vidas);                            
                                                                    }
                                                        if(choq==0){
                                                            puntos.puntoss+=100;
                                                            fantasma1.x=30*13;
                                                            fantasma1.y=30*11;
                                                            fantasma1.dir=0;
                                                                    }
                                                
                                                        choq=choquef2(pacman,fantasma2p,fantasma1p,anteriorpx,anteriorpy,vidas,&puntos,efecto,estado_timer,anteriorf2px,anteriorf2py,NIVEL2); 
                                                            if(choq==1){                                                                //!< Condicion si choca con el segundo fantasma.
                                                            vidas--;                                                                //!< Resto una vida.
                                                            rest(200);                                                              /**Colo al Pacman y a los fantasmas en su pocicion inicial*/
                                                            pacman.x=30*14;
                                                            pacman.y=30*13;
                                                            fantasma1.x=30*15;
                                                            fantasma1.y=30*10;
                                                            fantasma2.x=30*13;
                                                            fantasma2.y=30*11;
                                                            inicio=0;
                                                            if(debug==1)
                                                                fprintf(stdout,"Puntos=%d\nVidas=%d\n",puntos.puntoss,vidas);
                                                                }
                                                        if(choq==0){
                                                            puntos.puntoss+=100;
                                                            fantasma2.x=30*13;
                                                            fantasma2.y=30*11;
                                                            fantasma2.dir=0;
                                                                    }
                                                                
                                                        tiempo(times,estado_timer);
                                                        init_puntuacion(vidas,puntos.puntoss);          
                                                        tiempo(times,estado_timer);
                                                        init_pantalla();
                                                        if(inicio!=0){
                                                            init_bit(pacman);
                                                                }
                                                        tiempo(times,estado_timer);
                                                        init_puntuacion(vidas,puntos.puntoss); 
                                                        tiempo(times,estado_timer);
                                                        init_pantalla();
                                                        rest(velocidad);
                                                
//----------------------------------------------------------------------------------------------------------      
/**PAUSA DEL JUEGO (TECLA DE SPACE).*/

                                                        if(key[KEY_SPACE]){ 
                                                            pausa=1;
                                                            init_clear(_BUFFER);
                                                            init_clear(_PACMAN);
                                                            if(debug==1)
                                                                fprintf(stdout,"PAUSA\nPunto=%d\nVidas=%d\n",puntos.puntoss,vidas);
                                                                }  
                                                
                                                
//----------------------------------------------------------------------------------------------------------  
/**VIDAS Y PUNTOS POR TERMINAL.*/
                                           
                      
                                                        if(vidas==0){                    //!< Condicion en la que perdiste todas las vidas.
                                                            //AGREGAR CONEXCION CON EL SERVIDOR.
                                                            volver_empezar=init_lose(); //!< Imprime la pantalla de PERDISTE.
                                                            if(volver_empezar==1){      //!< Condicion de empezar de nuevo.
                                                                salir=1;
                                                                salir2=1;
                                                                empezar_de_nuevo=1;
                                                                            }
                                                            if(volver_empezar==0){
                                                                salir=1;
                                                                salir2=1;
                                                                empezar_de_nuevo=0;
                                                                terminar=1;
                                                                    }
                                                                                    }
                                                                    
//----------------------------------------------------------------------------------------------------------                            
                                                    if(debug==1)
                                                        fprintf(stdout,"efecto.cont:%d\n",efecto.cont);  
                                                    
                                                    if(efecto.cont==198){
                                                        if(serveroff!=1)
                                                            conexion=cliente(argc,argv,tiemposs,puntos,nombre,&score);
                                                        
                                                        musica_bonus(puntos,0,efecto);
                                                        init_win();
                                                        if(conexion==ERROR_EN_CONEXION||serveroff==1){
                                                            if(debug==1)
                                                                fprintf(stdout,"entre a error conexion\n"); 
                                                
                                                            init_error_conexion(tiemposs,puntos,nombre);
                                                            
                                                                                        }
                                                        else{
                                                            if(debug==1)
                                                                fprintf(stdout,"estoy entrando a score_pantalla();\n");
                                                            score_pantalla(score,tiemposs,puntos,nombre);
                                                            }
                                                        
                                                        
                                                        salir=1;
                                                        salir2=1;
                                                        empezar_de_nuevo=0;
                                                        terminar=1;
                                                                         
                                                                            } 
                                                                
//---------------------------------------------------------------------------------------------------------- 
/**MENU2.*/            

                                                        if(key[KEY_ESC]){  
                                                            estado_timer=PAUSAR_TIMER;
                                                            efecto=init_mapa(pacman,fantasma1,fantasma2,&puntos,MAPEADO_NORMAL,efecto,estado_timer,NIVEL2);
                                                            tiempo(times,estado_timer);
                                                            trampas(estado_timer);
                                                            aux=menu_2();                                                                              
                                                            if(aux==0){                                                                                
                                                                salir=1;
                                                                salir2=1;
                                                                empezar_de_nuevo=0;
                                                                terminar=1;
                                                                }
                                                            if(aux==1){
                                                                salir2=1;
                                                                salir=1;
                                                                if(debug==1)
                                                                    fprintf(stdout,"start again tocado\n");
                                                                empezar_de_nuevo=1;
                                                                estado_timer=REINICIAR_TIMER;
                                                                    }  
                                                                        }
                                                    
//---------------------------------------------------------------------------------------------------------- 

                                            }
                                        }
                                            }
                                    
                               } 
                            
//---------------------------------------------------------------------------------------------------------- 
/**MENU2.*/            
            
                    if(key[KEY_ESC]){  
                        estado_timer=PAUSAR_TIMER;
                        efecto=init_mapa(pacman,fantasma1,fantasma2,&puntos,MAPEADO_NORMAL,efecto,estado_timer,NIVEL1);
                        tiempo(times,estado_timer);
                        aux=menu_2();                                                                              
                        if(aux==0){                                                                                
                            salir=1;
                            empezar_de_nuevo=0;
                            terminar=1;
                            }
                        if(aux==1){
                            salir=1;
                            if(debug==1)
                                fprintf(stdout,"start again tocado\n");
                            empezar_de_nuevo=1;
                            estado_timer=REINICIAR_TIMER;
                                  }  
                                    }
                            
//---------------------------------------------------------------------------------------------------------- 

                        }
                    }
                }
        }while(!terminar);
    }
    
    free(score);                     //!< libero la memoria usada.
    
    destroy_bitmaps();              //!< Destruye todos los bitmas.
    
    if(debug==1)
        fprintf(stdout,"bitmas destruidos\n");
    
    allegro_exit();                  //!< Cierro Allegro.
    if(debug==1)
        fprintf(stdout,"allegro cerrado\n");
    
       
    if(debug==1)
        fprintf(stdout,"salgo por el final\n");
    
return 0;
}END_OF_MAIN();
  
