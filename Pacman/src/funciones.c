
/**
	\file funciones.c.
	\brief Funciones de todo el juego.
	\author Leandro Bellone.
	\date 2017.11.20.
	\version 10.0.0.
*/
//--------------
//-- Includes --
//--------------
#include <allegro.h>
#include <stdio.h>
#include "structs.h"
#include "defines.h"
//--------------------
//--Global Variables--
//--------------------
volatile int segundoss=0;
volatile int segundosbit=0;
volatile int minutoss=0;
volatile int segundos2=1;
volatile int segundos3=1;
volatile int segundos4=0;
volatile int segundostramp=0;

int auxiliarmusica=0;
int debug=0;
int mutiar=0;
int auxbit=1;


FONT *fuente;
PALETTE pal;
/**BITMPAS DEL JUEGO*/
//-----------------
/**PANTALLA LOAD:*/
BITMAP *load1;
BITMAP *load2;
BITMAP *load3;
BITMAP *load4;
BITMAP *load5;
//------------------
/**BITMAPS ESSENSIAL:*/
BITMAP *comida;
BITMAP *bonus;
BITMAP *caja;
BITMAP *muro;
BITMAP *fantasma;
BITMAP *fantasma2;
BITMAP *imagenFANTASMA;
BITMAP *imagenFANTASMA2;
BITMAP *pacman;
BITMAP *imagenPACMAN;
BITMAP *muertePACMAN;
BITMAP *buffer;
BITMAP *puntuacion;
BITMAP *vida;
BITMAP *imagenFANTASMA_AZUL;
BITMAP *muerteFANTASMA;

//-----------------
/**BITMAPS MENU 2:*/
BITMAP *pmenu_a;
BITMAP *pmenu_b;
BITMAP *pmenu_c;
BITMAP *pmenu_d;
BITMAP *im_menu_a;
BITMAP *im_menu_b;
BITMAP *im_menu_c;
BITMAP *im_menu_d;
//-----------------
/**BITMAPS MENU INICIO:*/
BITMAP *fondomute1;
BITMAP *fondomute2;
BITMAP *fondomute3;
BITMAP *fondomute4;
BITMAP *imagenmute1;
BITMAP *imagenmute2;
BITMAP *imagenmute3;
BITMAP *imagenmute4;
BITMAP *imagenFONDO1;
BITMAP *imagenFONDO2;
BITMAP *imagenFONDO3;
BITMAP *imagenFONDO4;
BITMAP *imagenFONDO5;
BITMAP *imagenFONDO6;
BITMAP *imagenCURSOR;
BITMAP *imagenPUNTUACION;
BITMAP *cursor;
BITMAP *fondo1;
BITMAP *fondo2;
BITMAP *fondo3;
BITMAP *fondo4;
BITMAP *fondo5;
BITMAP *fondo6;
BITMAP *puntuacion;
//-----------------
/**BITMAP CARTEL PAUSA:*/
BITMAP *imagenPAUSA;
BITMAP *pausa;
//-----------------
/**BITMAP CARTEL READY:*/
BITMAP *imagenREADY;
BITMAP *ready;
//-----------------
/**BITMAP CARTEL LVL2:*/
BITMAP *imagenLVL2;
BITMAP *LVL2;
//-----------------
/**BITMAP PANTALLA WIN Y LOSE:*/
BITMAP *pantallawin;
BITMAP *win;
BITMAP *pantallalose;
BITMAP *lose;
BITMAP *lose2;
BITMAP *lose3;
//-----------------
/**BITMAP MENU ERROR CONEXION:*/
BITMAP *ERROR_CONEXION;
BITMAP *pantallaERROR_CONEXION;
BITMAP *ERROR_CONEXION2;
BITMAP *pantallaERROR_CONEXION2;
//-----------------
/**BITMAP MENU SCORE:*/
BITMAP *PUNTOcolor;
BITMAP *DOSPUNTOScolor;
BITMAP *CEROcolor;
BITMAP *UNOcolor;
BITMAP *DOScolor;
BITMAP *TREScolor;
BITMAP *CUATROcolor;
BITMAP *CINCOcolor;
BITMAP *SEIScolor;
BITMAP *SIETEcolor;
BITMAP *OCHOcolor;
BITMAP *NUEVEcolor;
BITMAP *Acolor;
BITMAP *Bcolor;
BITMAP *Ccolor;
BITMAP *Dcolor;
BITMAP *Ecolor;
BITMAP *Fcolor;
BITMAP *Gcolor;
BITMAP *Hcolor;
BITMAP *Icolor;
BITMAP *Jcolor;
BITMAP *Kcolor;
BITMAP *Lcolor;
BITMAP *Mcolor;
BITMAP *Ncolor;
BITMAP *Ocolor;
BITMAP *Pcolor;
BITMAP *Qcolor;
BITMAP *Rcolor;
BITMAP *Scolor;
BITMAP *Tcolor;
BITMAP *Ucolor;
BITMAP *Vcolor;
BITMAP *Wcolor;
BITMAP *Xcolor;
BITMAP *Ycolor;
BITMAP *Zcolor;
BITMAP *DOSPUNTOS;
BITMAP *CERO;
BITMAP *UNO;
BITMAP *DOS;
BITMAP *TRES;
BITMAP *CUATRO;
BITMAP *CINCO;
BITMAP *SEIS;
BITMAP *SIETE;
BITMAP *OCHO;
BITMAP *NUEVE;
BITMAP *A;
BITMAP *B;
BITMAP *C;
BITMAP *D;
BITMAP *E;
BITMAP *F;
BITMAP *G;
BITMAP *H;
BITMAP *I;
BITMAP *J;
BITMAP *K;
BITMAP *L;
BITMAP *M;
BITMAP *N;
BITMAP *O;
BITMAP *P;
BITMAP *Q;
BITMAP *R;
BITMAP *S;
BITMAP *T;
BITMAP *U;
BITMAP *V;
BITMAP *W;
BITMAP *X;
BITMAP *Y;
BITMAP *Z;
BITMAP *PUNTO;
BITMAP *BARRA;
BITMAP *fondo;
BITMAP *fondoA;
BITMAP *fondoB;
BITMAP *fondoC;
BITMAP *fondoD;
BITMAP *fondoE;
BITMAP *fondoF;
BITMAP *fondoG;
BITMAP *fondoH;
BITMAP *fondoI;
BITMAP *fondoJ;
BITMAP *fondoK;
BITMAP *fondoL;
BITMAP *fondoM;
BITMAP *fondoN;
BITMAP *fondoO;
BITMAP *fondoP;
BITMAP *fondoQ;
BITMAP *fondoR;
BITMAP *fondoS;
BITMAP *fondoT;
BITMAP *fondoU;
BITMAP *fondoV;
BITMAP *fondoW;
BITMAP *fondoX;
BITMAP *fondoY;
BITMAP *fondoZ;
BITMAP *fondoUNO;
BITMAP *fondoDOS;
BITMAP *fondoTRES;
BITMAP *fondoCUATRO;
BITMAP *fondoCINCO;
BITMAP *fondoSEIS;
BITMAP *fondoSIETE;
BITMAP *fondoOCHO;
BITMAP *fondoNUEVE;
BITMAP *fondoCERO;
BITMAP *fondoPUNTO;
BITMAP *fondoBARRA;
BITMAP *fondoDEL;
BITMAP *fondoSTART;
BITMAP *pantallaUSUARIO;
BITMAP *fondoscore;
BITMAP *fondoscore2;
BITMAP *fondoSCORE;
//-----------------------------------------
/**BITMAP MENU RANKING*/
BITMAP *nranking;
BITMAP *Nranking;
BITMAP *Aranking;
BITMAP *Rranking;
BITMAP *Dranking;
BITMAP *Lranking;
BITMAP *Tranking;
BITMAP *Iranking;
BITMAP *Oranking;
BITMAP *Eranking;
BITMAP *Sranking;
BITMAP *Kranking;
BITMAP *Granking;
BITMAP *PUNTOranking;
BITMAP *fondoRANKING;
//-----------------------------------------
/**MUSICAS:*/
SAMPLE *m_muerte_pacman;
SAMPLE *m_muerte_fantasma;
SAMPLE *m_bonus;
SAMPLE *m_menu;
SAMPLE *m_comer;
SAMPLE *m_come_bonus;
SAMPLE *m_finish_bonus;
SAMPLE *m_pause; 
SAMPLE *m_game_over;
SAMPLE *m_load;

//*************************************************************************************************************************************************************
//-----------------------------------------
/**MAPAS LVL 1:*/

char mapa2[20][30]={ 
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "X            XXX            X",
  "X XXXXX XXXX XXX XXXX XXXXX X",
  "X XXXXX XXXX XXX XXXX XXXXX X",
  "X                           X",
  "X XXXXX X XXXXXXXXX X XXXXX X",
  "X       X    XXX    X       X",
  "XXXXXXX XXXX XXX XXXX XXXXXXX",
  "c     X X     >    !X X     c",
  "XXXXXXX X XXXX XXXX X XXXXXXX",
  "          X       X          ",
  "XXXXXXX X X       X X XXXXXXX",
  "c     X X XXXXXXXXX X X     c",
  "XXXXXXX X          <X XXXXXXX",
  "X       X XXXXXXXXX X       X",
  "X X XXX      XXX      XXX X X",
  "X X XXXXXXXX XXX XXXXXXXX X X",
  "X X       XX     XX       X X",
  "X   XXXXX    XXX    XXXXX   X",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  };
 
//-----------------------------------------

char usuario[23][30]={
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
  };
  
//-----------------------------------------
  
char mapa[21][30]={ 
  
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "XOoooooooooooXXXoooooooooooOX",
  "XoXXXXXoXXXXoXXXoXXXXoXXXXXoX",
  "XoXXXXXoXXXXoXXXoXXXXoXXXXXoX",
  "XoooooooooooooooooooooooooooX",
  "XoXXXXXoXoXXXXXXXXXoXoXXXXXoX",
  "XoooooooXooooXXXooooXoooooooX",
  "XXXXXXXoXXXXoXXXoXXXXoXXXXXXX",
  "ccccccXoXoooooooooooXoXcccccc",
  "XXXXXXXoXoXXXXcXXXXoXoXXXXXXX",
  "nnnnnnnoooX>gg|gg!Xooonnnnnnn",
  "XXXXXXXoXoX|ggggg<XoXoXXXXXXX",
  "ccccccXoXoXXXXXXXXXoXoXcccccc",
  "XXXXXXXoXooooonoooooXoXXXXXXX",
  "XoooooooXoXXXXXXXXXoXoooooooX",
  "XoXoXXXooooooXXXooooooXXXoXoX",
  "XoXoXXXXXXXXoXXXoXXXXXXXXoXoX",
  "XoXoooooooXXoooooXXoooooooXoX",
  "XOooXXXXXooooXXXooooXXXXXooOX",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "                             ",
  
};


//-----------------------------------------------------------

/**MAPAS LVL 2:*/
  
char mapalvl2[20][30]={ 
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "X  X   X    XXXXX    X   X  X",
  "XX   X X XX  XXX  XX X X   XX",
  "XXXXXX X XXX XXX XXX X XXXXXX",
  "X        X   XXX   X        X",
  "X XXXXXXXX XXXXXXX XXXXXXXX X",
  "X       XX         XX       X",
  "XXXXXXX XXXXXXXXXXXXX XXXXXXX",
  "c     X X!    >    !X X     c",
  "XXXXXXX X XXXX XXXX X XXXXXXX",
  "        X X       X X        ",
  "XXXXXXX X X       X X XXXXXXX",
  "c     X X XXXXXXXXX X X     c",
  "XXXXXXX X>    !    <X XXXXXXX",
  "X       XXXXXX!XXXXXX       X",
  "X XXXXX               XXXXX X",
  "X XXXXXXXXXX  X  XXXXXXXXXX X",
  "X  XX    XX  XXX  XX    XX  X",
  "XX    XX    XXXXX    XX    XX",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  };
  
//-----------------------------------------
  
char mapaf2lvl2[20][30]={ 
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "X  X   X    XXXXX    X   X  X",
  "XX   X X XX  XXX  XX X X   XX",
  "XXXXXX X XXX XXX XXX X XXXXXX",
  "X        X   XXX   X        X",
  "X XXXXXXXX XXXXXXX XXXXXXXX X",
  "X       XX         XX       X",
  "XXXXXXX XXXXXXXXXXXXX XXXXXXX",
  "c     X X!    >    !X X     c",
  "XXXXXXX X XXXX XXXX X XXXXXXX",
  "        X X       X X        ",
  "XXXXXXX X X       X X XXXXXXX",
  "c     X X XXXXXXXXX X X     c",
  "XXXXXXX X>    !    <X XXXXXXX",
  "X       XXXXXX!XXXXXX       X",
  "X XXXXX               XXXXX X",
  "X XXXXXXXXXX XXX XXXXXXXXXX X",
  "X  XX    XX  XXX  XX    XX  X",
  "XX    XX    XXXXX    XX    XX",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  };

//-----------------------------------------
  
char scorepantalla[23][30]={
    "                            ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "   1.\0                     ",
    "     \0                     ",
    "   2.\0                     ",
    "     \0                     ",
    "   3.\0                     ",
    "     \0                     ",
    "   4.\0                     ",
    "     \0                     ",
    "   5.\0                     ",
    "     \0                     ",
    "   6.\0                     ",
    " \0                         ",
    " \0                         ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
  };

//-----------------------------------------
  
char scorepantalla2[23][30]={
    "                            ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "   1.\0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
  };
 
  
//-----------------------------------------
  
char scorepantallaN[23][30]={
    "                            ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
    "   1.\0                     ",
    "     \0                     ",
    "   2.\0                     ",
    "     \0                     ",
    "   3.\0                     ",
    "     \0                     ",
    "   4.\0                     ",
    "     \0                     ",
    "   5.\0                     ",
    "     \0                     ",
    "   6.\0                     ",
    " \0                         ",
    " \0                         ",
    "     \0                     ",
    "     \0                     ",
    "     \0                     ",
  };
 
  
char scorepantallaR[23][30]={
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "                            ",
    "     \0                     ",
    "     \0                     ",
    "                            ",
    "                            ",
    "                            ",
  };
  
//-----------------------------------------
  
char mapal2[21][30]={ 
  
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "XOoXoooXooooXXXXXooooXoooXoOX",
  "XXoooXoXoXXooXXXooXXoXoXoooXX",
  "XXXXXXoXoXXXoXXXoXXXoXoXXXXXX",
  "XooooooooXoooXXXoooXooooooooX",
  "XoXXXXXXXXoXXXXXXXoXXXXXXXXoX",
  "XoooooooXXoooooooooXXoooooooX",
  "XXXXXXXoXXXXXXXXXXXXXoXXXXXXX",
  "ccccccXoXoooooooooooXoXcccccc",
  "XXXXXXXoXoXXXXcXXXXoXoXXXXXXX",
  "gggggggoXoX>gg|gg!XoXoggggggg",
  "XXXXXXXoXoX|ggggg<XoXoXXXXXXX",
  "ccccccXoXoXXXXXXXXXoXoXcccccc",
  "XXXXXXXoXooooo!oooooXoXXXXXXX",
  "XoooooooXXXXXXoXXXXXXoooooooX",
  "XoXXXXXoooooooooooooooXXXXXoX",
  "XoXXXXXXXXXXoXXXoXXXXXXXXXXoX",
  "XooXXooooXXooXXXooXXooooXXooX",
  "XXoooOXXooooXXXXXooooXXOoooXX",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  };


//********************************************************************************************************************************************************           
                                                                    /**INICIA BITMAPS DEL LOAD.*/

/**
	\fn  void init_bitmaps_load(void)
	\brief Carga los bitmpas para la pantalla de load.
	\date 2017.11.20
	\return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/
void init_bitmaps_load(void){
    
    load1=load_bitmap("assets/Imagenes/PantallaLoading/loding1.bmp",NULL);
    load2=load_bitmap("assets/Imagenes/PantallaLoading/loding2.bmp",NULL);
    load3=load_bitmap("assets/Imagenes/PantallaLoading/loding3.bmp",NULL);
    load4=load_bitmap("assets/Imagenes/PantallaLoading/loding4.bmp",NULL);  
    load5=load_bitmap("assets/Imagenes/PantallaLoading/loding5.bmp",NULL); 
    m_load=load_wav("assets/Sonidos/load.wav");
    
   
}


//*********************************************************************************************************************************************************           
                                                                /**INICIA TODOS LOS BITMAPS DEL JUEGO.*/
                                                                
/**
	\fn  void init_bitmaps(void)
	\brief Carga los bitmpas y la musica de todo el juego .
	\date 2017.11.20
	\return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/                                                               

void init_bitmaps(void){
  
        
    fuente=load_font("assets/Fuentes/minecraft.pcx",pal,NULL);
    
//----------------------------------------------------------------------------------------------------------   
/**MENU2:*/ 
    
    pmenu_a=create_bitmap(870,630);
    pmenu_b=create_bitmap(870,630);
    pmenu_c=create_bitmap(870,630);
    pmenu_d=create_bitmap(870,630);
    im_menu_a=load_bitmap("assets/Imagenes/Menu2/menu.bmp",NULL);
    im_menu_b=load_bitmap("assets/Imagenes/Menu2/menu1.bmp",NULL);
    im_menu_c=load_bitmap("assets/Imagenes/Menu2/menu2.bmp",NULL);
    im_menu_d=load_bitmap("assets/Imagenes/Menu2/menu3.bmp",NULL);  
    
//---------------------------------------------------------   
/**READY:*/
    
    ready=create_bitmap(180,40);
    imagenREADY=load_bitmap("assets/Imagenes/WinYLose/ready.bmp",NULL); 
    
//--------------------------------------------------------- 
/**PAUSA:*/
    
    pausa=create_bitmap(180,40);
    imagenPAUSA=load_bitmap("assets/Imagenes/WinYLose/pausa.bmp",NULL);
    
//---------------------------------------------------------
/**LVL2:*/
    
    LVL2=create_bitmap(180,40);
    imagenLVL2=load_bitmap("assets/Imagenes/WinYLose/LVL2.bmp",NULL);
    
//---------------------------------------------------------  
/**MENU:*/

    blit(load1,screen,0,0,0,0,870,630);
    
    fondomute1=create_bitmap(870,630);
    fondomute2=create_bitmap(870,630);
    fondomute3=create_bitmap(870,630);
    fondomute4=create_bitmap(870,630);
    fondo1=create_bitmap(870,630);
    fondo2=create_bitmap(870,630);
    fondo3=create_bitmap(870,630);
    fondo4=create_bitmap(870,630);
    fondo5=create_bitmap(870,630);
    fondo6=create_bitmap(870,630);
    imagenFONDO1=load_bitmap("assets/Imagenes/MenuInicio/FONDO1.bmp",NULL);
    imagenFONDO2=load_bitmap("assets/Imagenes/MenuInicio/FONDO2.bmp",NULL);
    imagenFONDO3=load_bitmap("assets/Imagenes/MenuInicio/FONDO3.bmp",NULL);
    imagenFONDO4=load_bitmap("assets/Imagenes/MenuInicio/FONDO4.bmp",NULL);
    imagenFONDO5=load_bitmap("assets/Imagenes/MenuControles/FONDO5.bmp",NULL);
    imagenFONDO6=load_bitmap("assets/Imagenes/MenuControles/FONDO6.bmp",NULL);
    imagenmute1=load_bitmap("assets/Imagenes/MenuInicio/FONDO1Nmute.bmp",NULL);
    imagenmute2=load_bitmap("assets/Imagenes/MenuInicio/FONDO2Nmute.bmp",NULL);
    imagenmute3=load_bitmap("assets/Imagenes/MenuInicio/FONDO3Nmute.bmp",NULL);
    imagenmute4=load_bitmap("assets/Imagenes/MenuInicio/FONDO4Nmute.bmp",NULL);
    
//------------------------------------------------------------------
/**CURSOR:*/
    
    cursor=create_bitmap(12,22);
    imagenCURSOR=load_bitmap("assets/Imagenes/Cursor/cursor.bmp",NULL);
    
//-------------------------------------------------------------
//PUNTUACION:
    
    puntuacion=create_bitmap(870,30);
    vida=load_bitmap("assets/Imagenes/Contador/VIDA.bmp",NULL);
    imagenPUNTUACION=load_bitmap("assets/Imagenes/Contador/puntos1.bmp",NULL);
    
    
    
    
    
    
    
//----------------------------------------------------------  
/**ESSENSIAL:*/ 
    
    buffer=create_bitmap(870,630);
    pacman=create_bitmap(33,33);
    fantasma=create_bitmap(30,30);
    fantasma2=create_bitmap(30,30);
    muerteFANTASMA=create_bitmap(30,30);
    imagenFANTASMA_AZUL=load_bitmap("assets/Imagenes/Fantasmas/fantasma4.bmp",NULL);
    muertePACMAN=load_bitmap("assets/Imagenes/Essensial/muerte.bmp",NULL);
    muro=load_bitmap("assets/Imagenes/Essensial/muro.bmp",NULL);
    comida=load_bitmap("assets/Imagenes/Essensial/comida.bmp",NULL);
    
    blit(load2,screen,0,0,0,0,870,630);
    
    bonus=load_bitmap("assets/Imagenes/Essensial/bonus.bmp",NULL);
    imagenFANTASMA=load_bitmap("assets/Imagenes/Fantasmas/fantasma1.bmp",NULL);
    imagenFANTASMA2=load_bitmap("assets/Imagenes/Fantasmas/fantasma2.bmp",NULL);
    caja=load_bitmap("assets/Imagenes/Essensial/caja.bmp",NULL);
    imagenPACMAN=load_bitmap("assets/Imagenes/Essensial/pacman.bmp",NULL);
    
    
//------------------------------------------------------------
/**WIN Y LOSE:*/
    
    pantallalose=create_bitmap(870,630);
    pantallawin=create_bitmap(870,630);
    win=load_bitmap("assets/Imagenes/WinYLose/WIN.bmp",NULL);
    lose=load_bitmap("assets/Imagenes/WinYLose/LOSE.bmp",NULL);
    lose2=load_bitmap("assets/Imagenes/WinYLose/LOSE2.bmp",NULL);
    lose3=load_bitmap("assets/Imagenes/WinYLose/LOSE3.bmp",NULL);
    
//----------------------------------------------------------   
/**ERROR CONEXION:*/
    
    pantallaERROR_CONEXION=create_bitmap(870,630);
    ERROR_CONEXION=load_bitmap("assets/Imagenes/ErrorConexion/errorconexion.bmp",NULL);
    pantallaERROR_CONEXION2=create_bitmap(870,630);
    ERROR_CONEXION2=load_bitmap("assets/Imagenes/ErrorConexion/errorconexion2.bmp",NULL);

//----------------------------------------------------------   
/**INGRESO USUARIO:*/
    
     blit(load3,screen,0,0,0,0,870,630);
    
    PUNTOcolor=load_bitmap("assets/Imagenes/MenuUsuario/PUNTOcolor.bmp",NULL);
    DOSPUNTOScolor=load_bitmap("assets/Imagenes/MenuUsuario/DOSPUNTOScolor.bmp",NULL);
    UNOcolor=load_bitmap("assets/Imagenes/MenuUsuario/1color.bmp",NULL);
    DOScolor=load_bitmap("assets/Imagenes/MenuUsuario/2color.bmp",NULL);
    TREScolor=load_bitmap("assets/Imagenes/MenuUsuario/3color.bmp",NULL);
    CUATROcolor=load_bitmap("assets/Imagenes/MenuUsuario/4color.bmp",NULL);
    CINCOcolor=load_bitmap("assets/Imagenes/MenuUsuario/5color.bmp",NULL);
    SEIScolor=load_bitmap("assets/Imagenes/MenuUsuario/6color.bmp",NULL);
    SIETEcolor=load_bitmap("assets/Imagenes/MenuUsuario/7color.bmp",NULL);
    OCHOcolor=load_bitmap("assets/Imagenes/MenuUsuario/8color.bmp",NULL);
    NUEVEcolor=load_bitmap("assets/Imagenes/MenuUsuario/9color.bmp",NULL);
    CEROcolor=load_bitmap("assets/Imagenes/MenuUsuario/0color.bmp",NULL);
    Acolor=load_bitmap("assets/Imagenes/MenuUsuario/Acolor.bmp",NULL);
    Bcolor=load_bitmap("assets/Imagenes/MenuUsuario/Bcolor.bmp",NULL);
    Ccolor=load_bitmap("assets/Imagenes/MenuUsuario/Ccolor.bmp",NULL);
    Dcolor=load_bitmap("assets/Imagenes/MenuUsuario/Dcolor.bmp",NULL);
    Ecolor=load_bitmap("assets/Imagenes/MenuUsuario/Ecolor.bmp",NULL);
    Fcolor=load_bitmap("assets/Imagenes/MenuUsuario/Fcolor.bmp",NULL);
    Gcolor=load_bitmap("assets/Imagenes/MenuUsuario/Gcolor.bmp",NULL);
    Hcolor=load_bitmap("assets/Imagenes/MenuUsuario/Hcolor.bmp",NULL);
    Icolor=load_bitmap("assets/Imagenes/MenuUsuario/Icolor.bmp",NULL);
    Jcolor=load_bitmap("assets/Imagenes/MenuUsuario/Jcolor.bmp",NULL);
    Kcolor=load_bitmap("assets/Imagenes/MenuUsuario/Kcolor.bmp",NULL);
    Lcolor=load_bitmap("assets/Imagenes/MenuUsuario/Lcolor.bmp",NULL);
    Mcolor=load_bitmap("assets/Imagenes/MenuUsuario/Mcolor.bmp",NULL);    
    Ncolor=load_bitmap("assets/Imagenes/MenuUsuario/Ncolor.bmp",NULL);
    Ocolor=load_bitmap("assets/Imagenes/MenuUsuario/Ocolor.bmp",NULL);
    Pcolor=load_bitmap("assets/Imagenes/MenuUsuario/Pcolor.bmp",NULL);
    Qcolor=load_bitmap("assets/Imagenes/MenuUsuario/Qcolor.bmp",NULL);
    Rcolor=load_bitmap("assets/Imagenes/MenuUsuario/Rcolor.bmp",NULL);
    Scolor=load_bitmap("assets/Imagenes/MenuUsuario/Scolor.bmp",NULL);
    Tcolor=load_bitmap("assets/Imagenes/MenuUsuario/Tcolor.bmp",NULL);
    Ucolor=load_bitmap("assets/Imagenes/MenuUsuario/Ucolor.bmp",NULL);
    Vcolor=load_bitmap("assets/Imagenes/MenuUsuario/Vcolor.bmp",NULL);
    Wcolor=load_bitmap("assets/Imagenes/MenuUsuario/Wcolor.bmp",NULL);
    Xcolor=load_bitmap("assets/Imagenes/MenuUsuario/Xcolor.bmp",NULL);
    Ycolor=load_bitmap("assets/Imagenes/MenuUsuario/Ycolor.bmp",NULL);
    Zcolor=load_bitmap("assets/Imagenes/MenuUsuario/Zcolor.bmp",NULL);
    

   
    blit(load5,screen,0,0,0,0,870,630);
    
    
    
    DOSPUNTOS=load_bitmap("assets/Imagenes/MenuUsuario/DOSPUNTOS.bmp",NULL);
    UNO=load_bitmap("assets/Imagenes/MenuUsuario/1.bmp",NULL);
    DOS=load_bitmap("assets/Imagenes/MenuUsuario/2.bmp",NULL);
    TRES=load_bitmap("assets/Imagenes/MenuUsuario/3.bmp",NULL);
    CUATRO=load_bitmap("assets/Imagenes/MenuUsuario/4.bmp",NULL);
    CINCO=load_bitmap("assets/Imagenes/MenuUsuario/5.bmp",NULL);
    SEIS=load_bitmap("assets/Imagenes/MenuUsuario/6.bmp",NULL);
    SIETE=load_bitmap("assets/Imagenes/MenuUsuario/7.bmp",NULL);
    OCHO=load_bitmap("assets/Imagenes/MenuUsuario/8.bmp",NULL);
    NUEVE=load_bitmap("assets/Imagenes/MenuUsuario/9.bmp",NULL);
    CERO=load_bitmap("assets/Imagenes/MenuUsuario/0.bmp",NULL);
    A=load_bitmap("assets/Imagenes/MenuUsuario/A.bmp",NULL);
    B=load_bitmap("assets/Imagenes/MenuUsuario/B.bmp",NULL);
    C=load_bitmap("assets/Imagenes/MenuUsuario/C.bmp",NULL);
    D=load_bitmap("assets/Imagenes/MenuUsuario/D.bmp",NULL);
    E=load_bitmap("assets/Imagenes/MenuUsuario/E.bmp",NULL);
    F=load_bitmap("assets/Imagenes/MenuUsuario/F.bmp",NULL);
    G=load_bitmap("assets/Imagenes/MenuUsuario/G.bmp",NULL);
    H=load_bitmap("assets/Imagenes/MenuUsuario/H.bmp",NULL);
    I=load_bitmap("assets/Imagenes/MenuUsuario/I.bmp",NULL);
    J=load_bitmap("assets/Imagenes/MenuUsuario/J.bmp",NULL);
    K=load_bitmap("assets/Imagenes/MenuUsuario/K.bmp",NULL);
    L=load_bitmap("assets/Imagenes/MenuUsuario/L.bmp",NULL);
    M=load_bitmap("assets/Imagenes/MenuUsuario/M.bmp",NULL);    
    N=load_bitmap("assets/Imagenes/MenuUsuario/N.bmp",NULL);
    O=load_bitmap("assets/Imagenes/MenuUsuario/O.bmp",NULL);
    P=load_bitmap("assets/Imagenes/MenuUsuario/P.bmp",NULL);
    Q=load_bitmap("assets/Imagenes/MenuUsuario/Q.bmp",NULL);
    R=load_bitmap("assets/Imagenes/MenuUsuario/R.bmp",NULL);
    S=load_bitmap("assets/Imagenes/MenuUsuario/S.bmp",NULL);
    T=load_bitmap("assets/Imagenes/MenuUsuario/T.bmp",NULL);
    U=load_bitmap("assets/Imagenes/MenuUsuario/U.bmp",NULL);
    V=load_bitmap("assets/Imagenes/MenuUsuario/V.bmp",NULL);
    W=load_bitmap("assets/Imagenes/MenuUsuario/W.bmp",NULL);
    X=load_bitmap("assets/Imagenes/MenuUsuario/X.bmp",NULL);
    Y=load_bitmap("assets/Imagenes/MenuUsuario/Y.bmp",NULL);
    Z=load_bitmap("assets/Imagenes/MenuUsuario/Z.bmp",NULL);
    PUNTO=load_bitmap("assets/Imagenes/MenuUsuario/PUNTO.bmp",NULL);
    BARRA=load_bitmap("assets/Imagenes/MenuUsuario/BARRRA.bmp",NULL);
    fondo=load_bitmap("assets/Imagenes/MenuUsuario/SCORE.bmp",NULL);
    fondoA=load_bitmap("assets/Imagenes/MenuUsuario/SCORE1.bmp",NULL);
    fondoB=load_bitmap("assets/Imagenes/MenuUsuario/SCORE2.bmp",NULL);
    fondoC=load_bitmap("assets/Imagenes/MenuUsuario/SCORE3.bmp",NULL);
    
    
    
    blit(load4,screen,0,0,0,0,870,630);
    
    
    fondoD=load_bitmap("assets/Imagenes/MenuUsuario/SCORE4.bmp",NULL);
    fondoE=load_bitmap("assets/Imagenes/MenuUsuario/SCORE5.bmp",NULL);
    fondoF=load_bitmap("assets/Imagenes/MenuUsuario/SCORE6.bmp",NULL);
    fondoG=load_bitmap("assets/Imagenes/MenuUsuario/SCORE7.bmp",NULL);
    fondoH=load_bitmap("assets/Imagenes/MenuUsuario/SCORE8.bmp",NULL);
    fondoI=load_bitmap("assets/Imagenes/MenuUsuario/SCORE9.bmp",NULL);
    fondoJ=load_bitmap("assets/Imagenes/MenuUsuario/SCORE10.bmp",NULL);
    fondoK=load_bitmap("assets/Imagenes/MenuUsuario/SCORE11.bmp",NULL);
    fondoL=load_bitmap("assets/Imagenes/MenuUsuario/SCORE12.bmp",NULL);
    fondoM=load_bitmap("assets/Imagenes/MenuUsuario/SCORE13.bmp",NULL);
    fondoN=load_bitmap("assets/Imagenes/MenuUsuario/SCORE14.bmp",NULL);
    fondoO=load_bitmap("assets/Imagenes/MenuUsuario/SCORE15.bmp",NULL);
    fondoP=load_bitmap("assets/Imagenes/MenuUsuario/SCORE16.bmp",NULL);
    fondoQ=load_bitmap("assets/Imagenes/MenuUsuario/SCORE17.bmp",NULL);
    fondoR=load_bitmap("assets/Imagenes/MenuUsuario/SCORE18.bmp",NULL);
    fondoS=load_bitmap("assets/Imagenes/MenuUsuario/SCORE19.bmp",NULL);
    fondoT=load_bitmap("assets/Imagenes/MenuUsuario/SCORE20.bmp",NULL);
    fondoU=load_bitmap("assets/Imagenes/MenuUsuario/SCORE21.bmp",NULL);
    fondoV=load_bitmap("assets/Imagenes/MenuUsuario/SCORE22.bmp",NULL);
    fondoW=load_bitmap("assets/Imagenes/MenuUsuario/SCORE23.bmp",NULL);
    fondoX=load_bitmap("assets/Imagenes/MenuUsuario/SCORE24.bmp",NULL);
    fondoY=load_bitmap("assets/Imagenes/MenuUsuario/SCORE25.bmp",NULL);
    fondoZ=load_bitmap("assets/Imagenes/MenuUsuario/SCORE26.bmp",NULL);
    fondoUNO=load_bitmap("assets/Imagenes/MenuUsuario/SCORE27.bmp",NULL);
    fondoDOS=load_bitmap("assets/Imagenes/MenuUsuario/SCORE28.bmp",NULL);
    fondoTRES=load_bitmap("assets/Imagenes/MenuUsuario/SCORE29.bmp",NULL);
    fondoCUATRO=load_bitmap("assets/Imagenes/MenuUsuario/SCORE30.bmp",NULL);
    fondoCINCO=load_bitmap("assets/Imagenes/MenuUsuario/SCORE31.bmp",NULL);
    fondoSEIS=load_bitmap("assets/Imagenes/MenuUsuario/SCORE32.bmp",NULL);
    fondoSIETE=load_bitmap("assets/Imagenes/MenuUsuario/SCORE33.bmp",NULL);
    fondoOCHO=load_bitmap("assets/Imagenes/MenuUsuario/SCORE34.bmp",NULL);
    fondoNUEVE=load_bitmap("assets/Imagenes/MenuUsuario/SCORE35.bmp",NULL);
    fondoCERO=load_bitmap("assets/Imagenes/MenuUsuario/SCORE36.bmp",NULL);
    fondoPUNTO=load_bitmap("assets/Imagenes/MenuUsuario/SCORE37.bmp",NULL);
    fondoBARRA=load_bitmap("assets/Imagenes/MenuUsuario/SCORE38.bmp",NULL);
    fondoDEL=load_bitmap("assets/Imagenes/MenuUsuario/SCORE39.bmp",NULL);
    fondoSTART=load_bitmap("assets/Imagenes/MenuUsuario/SCORE40.bmp",NULL);
    fondoscore=load_bitmap("assets/Imagenes/FondoScore/fondoscore.bmp",NULL);
    fondoscore2=load_bitmap("assets/Imagenes/FondoScore/fondoscore2.bmp",NULL);
    fondoSCORE=create_bitmap(870,630);
    pantallaUSUARIO=create_bitmap(870,630);
    
    
    blit(load2,screen,0,0,0,0,870,630); 
    
    nranking=load_bitmap("assets/Imagenes/MenuUsuario/nranking.bmp",NULL);
    Nranking=load_bitmap("assets/Imagenes/MenuUsuario/Nranking.bmp",NULL);
    Sranking=load_bitmap("assets/Imagenes/MenuUsuario/Sranking.bmp",NULL);
    Dranking=load_bitmap("assets/Imagenes/MenuUsuario/Dranking.bmp",NULL);
    Eranking=load_bitmap("assets/Imagenes/MenuUsuario/Eranking.bmp",NULL);
    Tranking=load_bitmap("assets/Imagenes/MenuUsuario/Tranking.bmp",NULL);
    Iranking=load_bitmap("assets/Imagenes/MenuUsuario/Iranking.bmp",NULL);
    Kranking=load_bitmap("assets/Imagenes/MenuUsuario/Kranking.bmp",NULL);
    Granking=load_bitmap("assets/Imagenes/MenuUsuario/Granking.bmp",NULL);
    Aranking=load_bitmap("assets/Imagenes/MenuUsuario/Aranking.bmp",NULL);
    Oranking=load_bitmap("assets/Imagenes/MenuUsuario/Oranking.bmp",NULL);
    Rranking=load_bitmap("assets/Imagenes/MenuUsuario/Rranking.bmp",NULL);
    Lranking=load_bitmap("assets/Imagenes/MenuUsuario/Lranking.bmp",NULL);
    PUNTOranking=load_bitmap("assets/Imagenes/MenuUsuario/PUNTOranking.bmp",NULL);
    fondoRANKING=create_bitmap(870,630);

    
//----------------------------------------------------------------------
/**MUSICAS:*/
    m_muerte_fantasma=load_wav("assets/Sonidos/muertefantasma.wav");
    m_muerte_pacman=load_wav("assets/Sonidos/muertepacman.wav");
    m_menu=load_wav("assets/Sonidos/menum.wav");
    m_bonus=load_wav("assets/Sonidos/bonus_time.wav");
    m_comer=load_wav("assets/Sonidos/comer.wav");
    m_come_bonus=load_wav("assets/Sonidos/comebonus.wav");
    m_finish_bonus=load_wav("assets/Sonidos/finishtime.wav");
    m_pause=load_wav("assets/Sonidos/pause.wav");
    m_game_over=load_wav("assets/Sonidos/gameover.wav");
    
//-------------------------------------------------------------------------

    
    }
    
    
    




//*********************************************************************************************************************************************************           
                                                                /**DESTRUYE TODOS LOS BITMAPS DEL JUEGO.*/
/**
	\fn  void destroy_bitmaps(void)
	\brief Destruye todos los recursos del juego.
	\date 2017.11.20
	\return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/  

void destroy_bitmaps(void){
  

//----------------------------------------------------------------------------------------------------------   
/**MENU2:*/ 
    
    destroy_bitmap(pmenu_a);
    destroy_bitmap(pmenu_b);
    destroy_bitmap(pmenu_c);
    destroy_bitmap(pmenu_d);
    destroy_bitmap(im_menu_a);
    destroy_bitmap(im_menu_b);
    destroy_bitmap(im_menu_c);
    destroy_bitmap(im_menu_d);
    
//---------------------------------------------------------   
/**READY:*/
    
    destroy_bitmap(ready);
    destroy_bitmap(imagenREADY);
    
//--------------------------------------------------------- 
/**PAUSA:*/
    
    destroy_bitmap(pausa);
    destroy_bitmap(imagenPAUSA);
    
//---------------------------------------------------------
/**LVL2:*/
    
    destroy_bitmap(LVL2);
    destroy_bitmap(imagenLVL2);
    
//---------------------------------------------------------  
/**MENU:*/
    
    destroy_bitmap(fondomute1);
    destroy_bitmap(fondomute2);
    destroy_bitmap(fondomute3);
    destroy_bitmap(fondomute4);
    destroy_bitmap(fondo1);
    destroy_bitmap(fondo2);
    destroy_bitmap(fondo3);
    destroy_bitmap(fondo4);
    destroy_bitmap(fondo5);
    destroy_bitmap(fondo6);
    destroy_bitmap(imagenFONDO1);
    destroy_bitmap(imagenFONDO2);
    destroy_bitmap(imagenFONDO3);
    destroy_bitmap(imagenFONDO4);
    destroy_bitmap(imagenFONDO5);
    destroy_bitmap(imagenFONDO6);
    destroy_bitmap(imagenmute1);
    destroy_bitmap(imagenmute2);
    destroy_bitmap(imagenmute3);
    destroy_bitmap(imagenmute4);
    
//------------------------------------------------------------------
/**CURSOR:*/
    
    destroy_bitmap(cursor);
    destroy_bitmap(imagenCURSOR);
    
//-------------------------------------------------------------
/**PUNTUACION:*/
    
    destroy_bitmap(puntuacion);
    destroy_bitmap(vida);
    destroy_bitmap(imagenPUNTUACION);
    
//----------------------------------------------------------  
/**ESSENSIAL:*/    
    
    destroy_bitmap(buffer);
    destroy_bitmap(pacman);
    destroy_bitmap(fantasma);
    destroy_bitmap(fantasma2);
    destroy_bitmap(muerteFANTASMA);
    destroy_bitmap(imagenFANTASMA_AZUL);
    destroy_bitmap(muertePACMAN);
    destroy_bitmap(muro);
    destroy_bitmap(comida);
    destroy_bitmap(bonus);
    destroy_bitmap(imagenFANTASMA);
    destroy_bitmap(imagenFANTASMA2);
    destroy_bitmap(caja);
    destroy_bitmap(imagenPACMAN);
    
    
//------------------------------------------------------------
/**WIN Y LOSE:*/
    
    destroy_bitmap(pantallalose);
    destroy_bitmap(pantallawin);
    destroy_bitmap(win);
    destroy_bitmap(lose);
    destroy_bitmap(lose2);
    destroy_bitmap(lose3);
    
//----------------------------------------------------------   
/**ERROR CONEXION:*/
    
    destroy_bitmap(pantallaERROR_CONEXION);
    destroy_bitmap(ERROR_CONEXION);
    destroy_bitmap(pantallaERROR_CONEXION2);
    destroy_bitmap(ERROR_CONEXION2);

//----------------------------------------------------------   
/**INGRESO USUARIO:*/
    
    
    destroy_bitmap(PUNTOcolor);
    destroy_bitmap(DOSPUNTOScolor);
    destroy_bitmap(UNOcolor);
    destroy_bitmap(DOScolor);
    destroy_bitmap(TREScolor);
    destroy_bitmap(CUATROcolor);
    destroy_bitmap(CINCOcolor);
    destroy_bitmap(SEIScolor);
    destroy_bitmap(SIETEcolor);
    destroy_bitmap(OCHOcolor);
    destroy_bitmap(NUEVEcolor);
    destroy_bitmap(CEROcolor);
    destroy_bitmap(Acolor);
    destroy_bitmap(Bcolor);
    destroy_bitmap(Ccolor);
    destroy_bitmap(Dcolor);
    destroy_bitmap(Ecolor);
    destroy_bitmap(Fcolor);
    destroy_bitmap(Gcolor);
    destroy_bitmap(Hcolor);
    destroy_bitmap(Icolor);
    destroy_bitmap(Jcolor);
    destroy_bitmap(Kcolor);
    destroy_bitmap(Lcolor);
    destroy_bitmap(Mcolor);    
    destroy_bitmap(Ncolor);
    destroy_bitmap(Ocolor);
    destroy_bitmap(Pcolor);
    destroy_bitmap(Qcolor);
    destroy_bitmap(Rcolor);
    destroy_bitmap(Scolor);
    destroy_bitmap(Tcolor);
    destroy_bitmap(Ucolor);
    destroy_bitmap(Vcolor);
    destroy_bitmap(Wcolor);
    destroy_bitmap(Xcolor);
    destroy_bitmap(Ycolor);
    destroy_bitmap(Zcolor);
    destroy_bitmap(DOSPUNTOS);
    destroy_bitmap(UNO);
    destroy_bitmap(DOS);
    destroy_bitmap(TRES);
    destroy_bitmap(CUATRO);
    destroy_bitmap(CINCO);
    destroy_bitmap(SEIS);
    destroy_bitmap(SIETE);
    destroy_bitmap(OCHO);
    destroy_bitmap(NUEVE);
    destroy_bitmap(CERO);
    destroy_bitmap(A);
    destroy_bitmap(B);
    destroy_bitmap(C);
    destroy_bitmap(D);
    destroy_bitmap(E);
    destroy_bitmap(F);
    destroy_bitmap(G);
    destroy_bitmap(H);
    destroy_bitmap(I);
    destroy_bitmap(J);
    destroy_bitmap(K);
    destroy_bitmap(L);
    destroy_bitmap(M);    
    destroy_bitmap(N);
    destroy_bitmap(O);
    destroy_bitmap(P);
    destroy_bitmap(Q);
    destroy_bitmap(R);
    destroy_bitmap(S);
    destroy_bitmap(T);
    destroy_bitmap(U);
    destroy_bitmap(V);
    destroy_bitmap(W);
    destroy_bitmap(X);
    destroy_bitmap(Y);
    destroy_bitmap(Z);
    destroy_bitmap(PUNTO);
    destroy_bitmap(BARRA);
    destroy_bitmap(fondo);
    destroy_bitmap(fondoA);
    destroy_bitmap(fondoB);
    destroy_bitmap(fondoC);    
    destroy_bitmap(fondoD);
    destroy_bitmap(fondoE);
    destroy_bitmap(fondoF);
    destroy_bitmap(fondoG);
    destroy_bitmap(fondoH);
    destroy_bitmap(fondoI);
    destroy_bitmap(fondoJ);
    destroy_bitmap(fondoK);
    destroy_bitmap(fondoL);
    destroy_bitmap(fondoM);
    destroy_bitmap(fondoN);
    destroy_bitmap(fondoO);
    destroy_bitmap(fondoP);
    destroy_bitmap(fondoQ);
    destroy_bitmap(fondoR);
    destroy_bitmap(fondoS);
    destroy_bitmap(fondoT);
    destroy_bitmap(fondoU);
    destroy_bitmap(fondoV);
    destroy_bitmap(fondoW);
    destroy_bitmap(fondoX);
    destroy_bitmap(fondoY);
    destroy_bitmap(fondoZ);
    destroy_bitmap(fondoUNO);
    destroy_bitmap(fondoDOS);
    destroy_bitmap(fondoTRES);
    destroy_bitmap(fondoCUATRO);
    destroy_bitmap(fondoCINCO);
    destroy_bitmap(fondoSEIS);
    destroy_bitmap(fondoSIETE);
    destroy_bitmap(fondoOCHO);
    destroy_bitmap(fondoNUEVE);
    destroy_bitmap(fondoCERO);
    destroy_bitmap(fondoPUNTO);
    destroy_bitmap(fondoBARRA);
    destroy_bitmap(fondoDEL);
    destroy_bitmap(fondoSTART);
    destroy_bitmap(fondoscore);
    destroy_bitmap(fondoscore2);
    destroy_bitmap(fondoSCORE);
    destroy_bitmap(pantallaUSUARIO);
    
//----------------------------------------------------------------------   
/**RANKING*/
    
    destroy_bitmap(nranking);
    destroy_bitmap(Nranking);
    destroy_bitmap(Sranking);
    destroy_bitmap(Dranking);
    destroy_bitmap(Eranking);
    destroy_bitmap(Tranking);
    destroy_bitmap(Iranking);
    destroy_bitmap(Kranking);
    destroy_bitmap(Granking);
    destroy_bitmap(Aranking);
    destroy_bitmap(Oranking);
    destroy_bitmap(Rranking);
    destroy_bitmap(Lranking);
    destroy_bitmap(PUNTOranking);
    destroy_bitmap(fondoRANKING);

    
//----------------------------------------------------------------------
/**LOAD*/
    
    destroy_bitmap(load1);
    destroy_bitmap(load2);
    destroy_bitmap(load3);
    destroy_bitmap(load4);
    destroy_bitmap(load5);
    
    
//----------------------------------------------------------------------
/**MUSICA:*/
    
    destroy_sample(m_muerte_fantasma);
    destroy_sample(m_muerte_pacman);
    destroy_sample(m_menu);
    destroy_sample(m_bonus);
    destroy_sample(m_comer);
    destroy_sample(m_come_bonus);
    destroy_sample(m_finish_bonus);
    destroy_sample(m_pause);
    destroy_sample(m_game_over);
    destroy_sample(m_load);
    
 
//----------------------------------------------------------------------
/**FUENTE:*/ 
    
    destroy_font (fuente);
    
    
    if(debug==1)
        fprintf(stdout,"BITMAPS DESTRUIDOS\n");
    
}



//*********************************************************************************************************************************************************           
                                                                    /**INICIA PANTALLA DE LOAD.*/
/**
	\fn  void init_pantalla_load(void)
	\brief Imprime la pantalla de Load.
	\date 2017.11.20
	\return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/                                                         

void init_pantalla_load(void){
    int i=0;
    
    play_sample(m_load,200,150,800,1);
   
    for(i=0;i<2;i++){
        blit(load1,screen,0,0,0,0,870,630);
        rest(150);
        blit(load2,screen,0,0,0,0,870,630);
        rest(150);
        blit(load3,screen,0,0,0,0,870,630);
        rest(150);
        blit(load5,screen,0,0,0,0,870,630);
        rest(150);
        blit(load4,screen,0,0,0,0,870,630);
        rest(150);
        if(i==0){
            init_bitmaps();
                }
                    }

    stop_sample(m_load);
   
}


//***************************************************************************************************************************************************************
                                                    /**ESCRIBE EN LA PANTALLA EL NOMBRE DEL USUARIO:*/

/**
	\fn  void init_pantallaUSUARIO(int pantalla)
	\brief La funcion ingreso usuario escribe en la matris usuario el nombre del usuario y esta funcion revisa esa matris y coloca el nombre del usuario en la pantalla. Tambien se encarga de leer la matris de score y mostrar en pantalla la lista de mejores puntajes.
	\date 2017.11.20
	\return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/ 

void init_pantallaUSUARIO(int pantalla){
    int i=0,j=0;

if(pantalla==PANTALLA_USUARIO){
    
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='A'){
                blit(A,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='B'){
                blit(B,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }  
     for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='C'){
                blit(C,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='D'){
                blit(D,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='E'){
                blit(E,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='F'){
                blit(F,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='G'){
                blit(G,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='H'){
                blit(H,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='I'){
                blit(I,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='J'){
                blit(J,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='K'){
                blit(K,buffer,0,0,(i*30),(j*30),30,30); 
                                }
                            }
                        }
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='L'){
                blit(L,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='M'){
               blit(M,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        } 
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='N'){
               blit(N,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='O'){
                blit(O,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                                                
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='P'){
                blit(P,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                                                
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='Q'){
                blit(Q,buffer,0,0,(i*30),(j*30),30,30);           
                                }
                            }
                        }
                                                
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='R'){
                blit(R,buffer,0,0,(i*30),(j*30),30,30);           
                                }
                            }
                        }
                                                
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='S'){
                blit(S,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                                                
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='T'){
                blit(T,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                                                
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='U'){
                blit(U,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                                                
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='V'){
                blit(V,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                                                
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='W'){
                blit(W,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                                                
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='X'){
                blit(X,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                                                
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='Y'){
                blit(Y,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                                                
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='Z'){
                blit(Z,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                                                
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='.'){
                blit(PUNTO,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='1'){
                blit(UNO,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='2'){
                blit(DOS,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='3'){
                blit(TRES,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='4'){
                blit(CUATRO,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='5'){
                blit(CINCO,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='6'){
                blit(SEIS,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='7'){
                blit(SIETE,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='8'){
                blit(OCHO,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='9'){
                blit(NUEVE,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }
                        
                        
    for(i=0;i<32;i++){                                              
        for(j=0;j<22;j++){                                          
            if(usuario[j][i]=='0'){
                blit(CERO,buffer,0,0,(i*30),(j*30),30,30);            
                                }
                            }
                        }  
                        
}
    else{
        if(pantalla==PANTALLA_SCORE2){
            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='A'){
                            blit(A,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='B'){
                            blit(B,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }  
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='C'){
                            blit(C,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='D'){
                            blit(D,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='E'){
                            blit(E,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='F'){
                            blit(F,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='G'){
                            blit(G,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='H'){
                            blit(H,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='I'){
                            blit(I,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='J'){
                            blit(J,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='K'){
                            blit(K,buffer,0,0,(i*30),(j*30),30,30); 
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='L'){
                            blit(L,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='M'){
                        blit(M,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    } 
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='N'){
                        blit(N,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='O'){
                            blit(O,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='P'){
                            blit(P,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='Q'){
                            blit(Q,buffer,0,0,(i*30),(j*30),30,30);           
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='R'){
                            blit(R,buffer,0,0,(i*30),(j*30),30,30);           
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='S'){
                            blit(S,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='T'){
                            blit(T,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='U'){
                            blit(U,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='V'){
                            blit(V,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='W'){
                            blit(W,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='X'){
                            blit(X,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='Y'){
                            blit(Y,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='Z'){
                            blit(Z,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='.'){
                            blit(PUNTO,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }                
                                    
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]==':'){
                            blit(DOSPUNTOS,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='1'){
                            blit(UNO,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='2'){
                            blit(DOS,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='3'){
                            blit(TRES,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='4'){
                            blit(CUATRO,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='5'){
                            blit(CINCO,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='6'){
                            blit(SEIS,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='7'){
                            blit(SIETE,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='8'){
                            blit(OCHO,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='9'){
                            blit(NUEVE,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla2[j][i]=='0'){
                            blit(CERO,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }                   
                                
                            
                                    }
        else{
            if(pantalla==PANTALLA_SCORE){
            
                    for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='A'){
                            blit(A,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='B'){
                            blit(B,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }  
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='C'){
                            blit(C,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='D'){
                            blit(D,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='E'){
                            blit(E,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='F'){
                            blit(F,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='G'){
                            blit(G,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='H'){
                            blit(H,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='I'){
                            blit(I,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='J'){
                            blit(J,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='K'){
                            blit(K,buffer,0,0,(i*30),(j*30),30,30); 
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='L'){
                            blit(L,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='M'){
                        blit(M,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    } 
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='N'){
                        blit(N,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='O'){
                            blit(O,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='P'){
                            blit(P,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='Q'){
                            blit(Q,buffer,0,0,(i*30),(j*30),30,30);           
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='R'){
                            blit(R,buffer,0,0,(i*30),(j*30),30,30);           
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='S'){
                            blit(S,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='T'){
                            blit(T,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='U'){
                            blit(U,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='V'){
                            blit(V,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='W'){
                            blit(W,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='X'){
                            blit(X,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='Y'){
                            blit(Y,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='Z'){
                            blit(Z,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='.'){
                            blit(PUNTO,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }                
                                    
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]==':'){
                            blit(DOSPUNTOS,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='1'){
                            blit(UNO,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='2'){
                            blit(DOS,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='3'){
                            blit(TRES,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='4'){
                            blit(CUATRO,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='5'){
                            blit(CINCO,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='6'){
                            blit(SEIS,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='7'){
                            blit(SIETE,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='8'){
                            blit(OCHO,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='9'){
                            blit(NUEVE,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantalla[j][i]=='0'){
                            blit(CERO,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    } 
                                }
            else{
                if(pantalla==PANTALLA_SCORE3){
            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='A'){
                            blit(Acolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='B'){
                            blit(Bcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }  
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='C'){
                            blit(Ccolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='D'){
                            blit(Dcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='E'){
                            blit(Ecolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='F'){
                            blit(Fcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='G'){
                            blit(Gcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='H'){
                            blit(Hcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='I'){
                            blit(Icolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='J'){
                            blit(Jcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='K'){
                            blit(Kcolor,buffer,0,0,(i*30),(j*30),30,30); 
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='L'){
                            blit(Lcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='M'){
                        blit(Mcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    } 
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='N'){
                        blit(Ncolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='O'){
                            blit(Ocolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='P'){
                            blit(Pcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='Q'){
                            blit(Qcolor,buffer,0,0,(i*30),(j*30),30,30);           
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='R'){
                            blit(Rcolor,buffer,0,0,(i*30),(j*30),30,30);           
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='S'){
                            blit(Scolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='T'){
                            blit(Tcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='U'){
                            blit(Ucolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='V'){
                            blit(Vcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='W'){
                            blit(Wcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='X'){
                            blit(Xcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='Y'){
                            blit(Ycolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='Z'){
                            blit(Zcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                               
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='.'){
                            blit(PUNTOcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }               
                               
                                                            
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]==':'){
                            blit(DOSPUNTOScolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='1'){
                            blit(UNOcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='2'){
                            blit(DOScolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='3'){
                            blit(TREScolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='4'){
                            blit(CUATROcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='5'){
                            blit(CINCOcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='6'){
                            blit(SEIScolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='7'){
                            blit(SIETEcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='8'){
                            blit(OCHOcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='9'){
                            blit(NUEVEcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaN[j][i]=='0'){
                            blit(CEROcolor,buffer,0,0,(i*30),(j*30),30,30);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='N'){
                            blit(Nranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='n'){
                            blit(nranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }                    
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='a'){
                            blit(Aranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='e'){
                            blit(Eranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='d'){
                            blit(Dranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='i'){
                            blit(Iranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='o'){
                            blit(Oranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='s'){
                            blit(Sranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='t'){
                            blit(Tranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='r'){
                            blit(Rranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='l'){
                            blit(Lranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                                    
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='g'){
                            blit(Granking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                                    
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='k'){
                            blit(Kranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                
                for(i=0;i<30;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(scorepantallaR[j][i]=='.'){
                            blit(PUNTOranking,buffer,0,0,(i*15),(j*30),TAM,TAM);            
                                            }
                                        }
                                    }
                                    
                                            }
                }
            }
            
    }
}

//***************************************************************************************************************************************************
                                                        /**IMPRIME EL MENU DE USUARIO:*/
                                                        
                                                        
/**
	\fn  void Ingreso_Usuario(char* nombre)
	\brief Escribe en la matris usuario el nombre del usuario y lo guarda en la Variable NOMBRE.
	\date 2017.11.20
	\return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/ 
                                                        
void Ingreso_Usuario(char* nombre){

    int escape=0,l=0,salida_score=1,click=0,i=0,aux=0;

    
    for(i=0;i<7;i++)
        nombre[i]=' ';

while(!escape){
        
        if(mouse_y>376 && mouse_y<403 && mouse_x>59 && mouse_x<84){
            blit(fondoA,pantallaUSUARIO,0,0,0,0,870,630); 
            blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
            init_pantallaUSUARIO(PANTALLA_USUARIO);
            if(mouse_b & 1){
                do{
                if(!mouse_b & 1){
                    salida_score=0;
                    if(l<=6){
                            l++;
                                }
                    if(l==1)
                        usuario[9][13]='A';  
                    else{        
                        if(l==2)
                            usuario[9][14]='A';  
                        else{
                            if(l==3)
                                usuario[9][15]='A'; 
                            else{
                                if(l==4)
                                    usuario[9][16]='A'; 
                                else{
                                    if(l==5)
                                        usuario[9][17]='A'; 
                                    else{
                                        if(l==6)
                                            usuario[9][18]='A';
                                        }   
                                    }
                                }
                            }   
                        }
                                        }  
                }while(salida_score);
                 salida_score=1;   
                                }
                                                                    }
                                                                    
        else{
            if(mouse_y>376 && mouse_y<403 && mouse_x>115 && mouse_x<138){
            blit(fondoB,pantallaUSUARIO,0,0,0,0,870,630); 
            blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
            init_pantallaUSUARIO(PANTALLA_USUARIO);
            if(mouse_b & 1){
                do{
                if(!mouse_b & 1){
                    salida_score=0;
                    if(l<=6){
                                                l++;
                                                    }
                    if(l==1)
                        usuario[9][13]='B';  
                    else{        
                        if(l==2)
                            usuario[9][14]='B';  
                        else{
                            if(l==3)
                                usuario[9][15]='B'; 
                            else{
                                if(l==4)
                                    usuario[9][16]='B'; 
                                else{
                                    if(l==5)
                                        usuario[9][17]='B'; 
                                    else{
                                        if(l==6)
                                            usuario[9][18]='B';
                                        }   
                                    }
                                }
                            }   
                        }
                                        }  
                }while(salida_score);
                 salida_score=1;
                                }
                                                                    }
                                                                    
            else{
                if(mouse_y>373 && mouse_y<403 && mouse_x>165 && mouse_x<188){
                blit(fondoC,pantallaUSUARIO,0,0,0,0,870,630); 
                blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                init_pantallaUSUARIO(PANTALLA_USUARIO);
                if(mouse_b & 1){
                    do{
                    if(!mouse_b & 1){
                        salida_score=0;
                        if(l<=6){
                                                l++;
                                                    }
                        if(l==1)
                            usuario[9][13]='C';  
                        else{        
                            if(l==2)
                                usuario[9][14]='C';  
                            else{
                                if(l==3)
                                    usuario[9][15]='C'; 
                                else{
                                    if(l==4)
                                        usuario[9][16]='C'; 
                                    else{
                                        if(l==5)
                                            usuario[9][17]='C'; 
                                        else{
                                            if(l==6)
                                                usuario[9][18]='C';
                                            }   
                                        }
                                    }
                                }   
                            }
                                        }  
                    }while(salida_score);
                        salida_score=1;
                                }
                                                                    }   
                                                                    
                else{
                    if(mouse_y>373 && mouse_y<403 && mouse_x>218 && mouse_x<248){
                    blit(fondoD,pantallaUSUARIO,0,0,0,0,870,630); 
                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                    if(mouse_b & 1){
                        do{
                        if(!mouse_b & 1){
                            salida_score=0;
                            if(l<=6){
                                                l++;
                                                    }
                            if(l==1)
                                usuario[9][13]='D';  
                            else{        
                                if(l==2)
                                    usuario[9][14]='D';  
                                else{
                                    if(l==3)
                                        usuario[9][15]='D'; 
                                    else{
                                        if(l==4)
                                            usuario[9][16]='D'; 
                                        else{
                                            if(l==5)
                                                usuario[9][17]='D'; 
                                            else{
                                                if(l==6)
                                                    usuario[9][18]='D';
                                                }   
                                            }
                                        }
                                    }   
                                }
                                            }  
                        }while(salida_score);
                            salida_score=1;
                                    }
                                                                        }  
                                                                        
                    else{
                        if(mouse_y>373 && mouse_y<403 && mouse_x>276 && mouse_x<300){
                        blit(fondoE,pantallaUSUARIO,0,0,0,0,870,630); 
                        blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                        init_pantallaUSUARIO(PANTALLA_USUARIO);
                        if(mouse_b & 1){
                            do{
                            if(!mouse_b & 1){
                                salida_score=0;
                                if(l<=6){
                                    l++;
                                        }
                                if(l==1)
                                    usuario[9][13]='E';  
                                else{        
                                    if(l==2)
                                        usuario[9][14]='E';  
                                    else{
                                        if(l==3)
                                            usuario[9][15]='E'; 
                                        else{
                                            if(l==4)
                                                usuario[9][16]='E'; 
                                            else{
                                                if(l==5)
                                                    usuario[9][17]='E'; 
                                                else{
                                                    if(l==6)
                                                        usuario[9][18]='E';
                                                    }   
                                                }
                                            }
                                        }   
                                    }
                                                }  
                            }while(salida_score);
                                salida_score=1;
                                        }
                                                                                }                                          
                                                                                                                
                        else{
                            if(mouse_y>373 && mouse_y<403 && mouse_x>330 && mouse_x<354){
                            blit(fondoF,pantallaUSUARIO,0,0,0,0,870,630); 
                            blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                            init_pantallaUSUARIO(PANTALLA_USUARIO);
                            if(mouse_b & 1){
                                do{
                                if(!mouse_b & 1){
                                    salida_score=0;
                                    if(l<=6){
                                                l++;
                                                    }
                                    if(l==1)
                                        usuario[9][13]='F';  
                                    else{        
                                        if(l==2)
                                            usuario[9][14]='F';  
                                        else{
                                            if(l==3)
                                                usuario[9][15]='F'; 
                                            else{
                                                if(l==4)
                                                    usuario[9][16]='F'; 
                                                else{
                                                    if(l==5)
                                                        usuario[9][17]='F'; 
                                                    else{
                                                        if(l==6)
                                                            usuario[9][18]='F';
                                                        }   
                                                    }
                                                }
                                            }   
                                        }
                                                    }  
                                }while(salida_score);
                                    salida_score=1;
                                            }
                                                                                    }
                                                                                    
                                                                                    
                            else{
                                if(mouse_y>373 && mouse_y<403 && mouse_x>384 && mouse_x<407){
                                blit(fondoG,pantallaUSUARIO,0,0,0,0,870,630); 
                                blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                init_pantallaUSUARIO(PANTALLA_USUARIO);
                                if(mouse_b & 1){
                                    do{
                                    if(!mouse_b & 1){
                                        salida_score=0;
                                        if(l<=6){
                                                l++;
                                                    }
                                        if(l==1)
                                            usuario[9][13]='G';  
                                        else{        
                                            if(l==2)
                                                usuario[9][14]='G';  
                                            else{
                                                if(l==3)
                                                    usuario[9][15]='G'; 
                                                else{
                                                    if(l==4)
                                                        usuario[9][16]='G'; 
                                                    else{
                                                        if(l==5)
                                                            usuario[9][17]='G'; 
                                                        else{
                                                            if(l==6)
                                                                usuario[9][18]='G';
                                                            }   
                                                        }
                                                    }
                                                }   
                                            }
                                                        }  
                                    }while(salida_score);
                                        salida_score=1;
                                                }
                                                                                        }  
                                else{
                                    if(mouse_y>373 && mouse_y<403 && mouse_x>438 && mouse_x<462){
                                    blit(fondoH,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='H';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='H';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='H'; 
                                                    else{
                                                        if(l==4)
                                                           usuario[9][16]='H'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='H'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='H';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }  
                                                                                            
                                else{
                                    if(mouse_y>373 && mouse_y<403 && mouse_x>495 && mouse_x<516){
                                    blit(fondoI,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='I';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='I';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='I'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='I'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='I'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='I';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }   
                                else{
                                    if(mouse_y>373 && mouse_y<403 && mouse_x>546 && mouse_x<571){
                                    blit(fondoJ,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='J';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='J';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='J'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='J'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='J'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='J';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }   
                                else{
                                    if(mouse_y>374 && mouse_y<403 && mouse_x>600 && mouse_x<623){
                                    blit(fondoK,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='K';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='K';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='K'; 
                                                    else{
                                                        if(l==4)
                                                           usuario[9][16]='K'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='K'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='K';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }     
                                                                                            
                                else{
                                    if(mouse_y>373 && mouse_y<403 && mouse_x>654 && mouse_x<677){
                                    blit(fondoL,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='L';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='L';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='L'; 
                                                    else{
                                                        if(l==4)
                                                           usuario[9][16]='L'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='L'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='L';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            } 
                                else{
                                    if(mouse_y>373 && mouse_y<403 && mouse_x>706 && mouse_x<732){
                                    blit(fondoM,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                           if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='M';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='M';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='M'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='M'; 
                                                        else{
                                                            if(l==5)
                                                               usuario[9][17]='M'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='M';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            } 
                                else{
                                    if(mouse_y>373 && mouse_y<403 && mouse_x>760 && mouse_x<784){
                                    blit(fondoN,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='N';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='N';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='N'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='N'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='N'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='N';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            } 
                                else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>60 && mouse_x<84){
                                    blit(fondoO,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='O';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='O';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='O'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='O'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='O'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='O';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            } 
                                else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>114 && mouse_x<140){
                                    blit(fondoP,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='P';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='P';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='P'; 
                                                    else{
                                                        if(l==4)
                                                           usuario[9][16]='P'; 
                                                        else{
                                                            if(l==5)
                                                               usuario[9][17]='P'; 
                                                            else{
                                                                if(l==6)
                                                                   usuario[9][18]='P';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }   
                                else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>170 && mouse_x<194){
                                    blit(fondoQ,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='Q';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='Q';  
                                                else{
                                                    if(l==3)
                                                       usuario[9][15]='Q'; 
                                                    else{
                                                        if(l==4)
                                                          usuario[9][16]='Q'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='Q'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='Q';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            } 
                                else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>222 && mouse_x<246){
                                    blit(fondoR,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='R';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='R';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='R'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='R'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='R'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='R';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            } 
                                else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>276 && mouse_x<300){
                                    blit(fondoS,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                               usuario[9][13]='S';  
                                            else{        
                                                if(l==2)
                                                   usuario[9][14]='S';  
                                                else{
                                                    if(l==3)
                                                       usuario[9][15]='S'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='S'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='S'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='S';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }   
                                else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>333 && mouse_x<353){
                                    blit(fondoT,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='T';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='T';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='T'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='T'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='T'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='T';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            } 
                                else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>384 && mouse_x<408){
                                    blit(fondoU,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='U';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='U';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='U'; 
                                                    else{
                                                        if(l==4)
                                                           usuario[9][16]='U'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='U'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='U';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }   
                                else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>438 && mouse_x<462){
                                    blit(fondoV,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                               usuario[9][13]='V';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='V';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='V'; 
                                                    else{
                                                        if(l==4)
                                                           usuario[9][16]='V'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='V'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='V';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }  
                                else{
                                    if(mouse_y>414 && mouse_y<437 && mouse_x>492 && mouse_x<516){
                                    blit(fondoW,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='W';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='W';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='W'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='W'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='W'; 
                                                            else{
                                                                if(l==6)
                                                                   usuario[9][18]='W';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }   
                                                                                            
                                else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>546 && mouse_x<570){
                                    blit(fondoX,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='X';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='X';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='X'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='X'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='X'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='X';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }
                                                                                            
                                else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>604 && mouse_x<624){
                                    blit(fondoY,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='Y';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='Y';  
                                                else{
                                                    if(l==3)
                                                       usuario[9][15]='Y'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='Y'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='Y'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='Y';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }  
                                else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>654 && mouse_x<679){
                                    blit(fondoZ,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='Z';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='Z';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='Z'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='Z'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='Z'; 
                                                            else{
                                                                if(l==6)
                                                                   usuario[9][18]='Z';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }
                                  else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>711 && mouse_x<732){
                                    blit(fondoUNO,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='1';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='1';  
                                                else{
                                                    if(l==3)
                                                       usuario[9][15]='1'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='1'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='1'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='1';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }  
                                                                                            
                                else{
                                    if(mouse_y>413 && mouse_y<437 && mouse_x>761 && mouse_x<786){
                                    blit(fondoDOS,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='2';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='2';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='2'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='2'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='2'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='2';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }    
                                                                                            
                                 else{
                                    if(mouse_y>447 && mouse_y<474 && mouse_x>59 && mouse_x<84){
                                    blit(fondoTRES,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='3';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='3';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='3'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='3'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='3'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='3';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }  
                                                                                            
                                                                                            
                                                                                            
                                else{
                                    if(mouse_y>447 && mouse_y<474 && mouse_x>113 && mouse_x<139){
                                    blit(fondoCUATRO,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='4';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='4';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='4'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='4'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='4'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='4';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }  
                                                                                            
                                                                                            
                                else{
                                    if(mouse_y>447 && mouse_y<474 && mouse_x>168 && mouse_x<192){
                                    blit(fondoCINCO,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='5';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='5';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='5'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='5'; 
                                                        else{
                                                            if(l==5)
                                                               usuario[9][17]='5'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='5';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }  
                                                                                            
                                else{
                                    if(mouse_y>447 && mouse_y<474 && mouse_x>221 && mouse_x<248){
                                    blit(fondoSEIS,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='6';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='6';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='6'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='6'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='6'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='6';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }  
                                                                                            
                               else{
                                    if(mouse_y>447 && mouse_y<474 && mouse_x>275 && mouse_x<300){
                                    blit(fondoSIETE,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='7';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='7';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='7'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='7'; 
                                                        else{
                                                            if(l==5)
                                                               usuario[9][17]='7'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='7';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }  
                                                                                            
                                                                                            
                                else{
                                    if(mouse_y>447 && mouse_y<474 && mouse_x>330 && mouse_x<354){
                                    blit(fondoOCHO,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='8';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='8';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='8'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='8'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='8'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='8';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }  
                                                                                            
                                                                                            
                                else{
                                    if(mouse_y>447 && mouse_y<474 && mouse_x>375 && mouse_x<408){
                                    blit(fondoNUEVE,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='9';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='9';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='9'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='9'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='9'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='9';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }  
                                                                                            
                                                                                            
                                else{
                                    if(mouse_y>447 && mouse_y<474 && mouse_x>438 && mouse_x<462){
                                    blit(fondoCERO,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='0';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='0';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='0'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='0'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='0'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='0';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            }  
                                                                                            
                                                                                                                    
                                                                                            
                                else{
                                    if(mouse_y>450 && mouse_y<472 && mouse_x>490 && mouse_x<510){
                                    blit(fondoPUNTO,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                            if(l==1)
                                                usuario[9][13]='.';  
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]='.';  
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]='.'; 
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]='.'; 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]='.'; 
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]='.';
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                            }  
                                        }while(salida_score);
                                            salida_score=1;
                                                    }
                                                                                            } 
                                                                                            
                                else{
                                    if(mouse_y>455 && mouse_y<475 && mouse_x>549 && mouse_x<568){
                                    blit(fondoBARRA,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            salida_score=0;
                                            if(l<=6){
                                                l++;
                                                    }
                                                if(l==1)
                                                    usuario[9][13]=' ';  
                                                else{        
                                                    if(l==2)
                                                        usuario[9][14]=' ';  
                                                    else{
                                                        if(l==3)
                                                            usuario[9][15]=' '; 
                                                        else{
                                                            if(l==4)
                                                                usuario[9][16]=' '; 
                                                            else{
                                                                if(l==5)
                                                                    usuario[9][17]=' '; 
                                                                else{
                                                                    if(l==6)
                                                                        usuario[9][18]=' ';
                                                                    }   
                                                                }
                                                            }
                                                        }   
                                                    }
                                                                }  
                                            }while(salida_score);
                                                salida_score=1;
                                                        }
                                                                                            }
                                else{
                                    if(mouse_y>448 && mouse_y<473 && mouse_x>600 && mouse_x<678){
                                    blit(fondoDEL,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        do{
                                        if(!mouse_b & 1){
                                            click++;
                                           if(click==1){
                                            if(l==1)
                                                usuario[9][13]=' ';                                                     
                                            else{        
                                                if(l==2)
                                                    usuario[9][14]=' ';                                                                                                        
                                                else{
                                                    if(l==3)
                                                        usuario[9][15]=' ';                                                        
                                                    else{
                                                        if(l==4)
                                                            usuario[9][16]=' ';                                                                 
                                                        else{
                                                            if(l==5)
                                                                usuario[9][17]=' ';                                                                                                                                   
                                                            else{
                                                                if(l==6)
                                                                    usuario[9][18]=' ';                                                                                                                                           
                                                                }   
                                                            }
                                                        }
                                                    }   
                                                }
                                                if(l>=1)
                                                    l--;
                                                            }
                                                if(click!=1){
                                                    click=0;
                                                    if(l==1)
                                                        usuario[9][13]=' ';                                                        
                                                    else{       
                                                        if(l==2)
                                                            usuario[9][14]=' ';                                                                                                                            
                                                        else{
                                                            if(l==3)
                                                                usuario[9][15]=' ';                                                                                                                                    
                                                            else{
                                                                if(l==4)
                                                                    usuario[9][16]=' '; 
                                                                else{
                                                                    if(l==5)
                                                                        usuario[9][17]=' ';
                                                                    else{
                                                                        if(l==6)
                                                                            usuario[9][18]=' ';                                                                                                                                                           
                                                                        }   
                                                                    }
                                                                }
                                                            }   
                                                        }
                                                if(l>=1)    
                                                    l--;
                                                        }
                                            salida_score=0;
                                                            }
                                            init_pantallaUSUARIO(PANTALLA_USUARIO); 
                                            }while(salida_score);
                                                salida_score=1;
                                                        }
                                                                                            }
                                                                                            
                                else{
                                    if(mouse_y>504 && mouse_y<528 && mouse_x>666 && mouse_x<797){
                                    blit(fondoSTART,pantallaUSUARIO,0,0,0,0,870,630); 
                                    blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                                    init_pantallaUSUARIO(PANTALLA_USUARIO);
                                    if(mouse_b & 1){
                                        escape=1;
                                        
                                    }
                                                                                            }                                               
                                                                                            
                                                                                            
                                                                                            
                                                                                            
            else{
                clear(buffer);
                blit(fondo,pantallaUSUARIO,0,0,0,0,870,630); 
                blit(pantallaUSUARIO,buffer,0,0,0,0,870,630);
                init_pantallaUSUARIO(PANTALLA_USUARIO);
                }
                                     }
                                     }
                                     }
                                     } 
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                     }
                                    }
                                }
                            }
                        }
                    }
                }
            }
    
        blit(imagenCURSOR,cursor,0,0,0,0,12,22);
        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,12,22);
        blit(buffer,screen,0,0,0,0,870,630);
       
       
        
                        
}


//-------------------------------

    if(usuario[9][13]=='.')
        nombre[0]='.';
    
    if(usuario[9][14]=='.')
        nombre[1]='.';
    
    if(usuario[9][15]=='.')
        nombre[2]='.';
    
    if(usuario[9][16]=='.')
        nombre[3]='.';
    
    if(usuario[9][17]=='.')
        nombre[4]='.';
    
    if(usuario[9][18]=='.')
        nombre[5]='.';

//-------------------------------------------------

for(i=0;i<26;i++){
if(usuario[9][13]==(char)(65+i))
    aux=1;

if(usuario[9][13]==(char)(48+i))
    aux=2;

if(aux==1){
    nombre[0]=(char)(65+i);
    aux=0;
            }
            
if(aux==2){
    nombre[0]=(char)(48+i);
    aux=0;
            }
                } 
//-------------------------------

for(i=0;i<26;i++){
if(usuario[9][14]==(char)(65+i))
    aux=1;

if(usuario[9][14]==(char)(48+i))
    aux=2;

if(aux==1){
    nombre[1]=(char)(65+i);
    aux=0;
            }
            
if(aux==2){
    nombre[1]=(char)(48+i);
    aux=0;
            }
                } 
//---------------------------------

for(i=0;i<26;i++){
if(usuario[9][15]==(char)(65+i))
    aux=1;

if(usuario[9][15]==(char)(48+i))
    aux=2;

if(aux==1){
    nombre[2]=(char)(65+i);
    aux=0;
            }
            
if(aux==2){
    nombre[2]=(char)(48+i);
    aux=0;
            }
                }  
//---------------------------------

for(i=0;i<26;i++){
if(usuario[9][16]==(char)(65+i))
    aux=1;

if(usuario[9][16]==(char)(48+i))
    aux=2;

if(aux==1){
    nombre[3]=(char)(65+i);
    aux=0;
            }
            
if(aux==2){
    nombre[3]=(char)(48+i);
    aux=0;
            }
                } 
                
//----------------------------------

for(i=0;i<26;i++){
if(usuario[9][17]==(char)(65+i))
    aux=1;

if(usuario[9][17]==(char)(48+i))
    aux=2;

if(aux==1){
    nombre[4]=(char)(65+i);
    aux=0;
            }
            
if(aux==2){
    nombre[4]=(char)(48+i);
    aux=0;
            }
                } 
                
//-----------------------------------     

for(i=0;i<26;i++){
if(usuario[9][18]==(char)(65+i))
    aux=1;

if(usuario[9][18]==(char)(48+i))
    aux=2;

if(aux==1){
    nombre[5]=(char)(65+i);
    aux=0;
            }
            
if(aux==2){
    nombre[5]=(char)(48+i);
    aux=0;
            }
                } 
//----------------------------------

if(debug==1) printf("%s/\n",nombre);

if(strcmp(nombre,"       ")==0){
    strcpy(nombre,"______");
                             }

if(debug==1) printf("%s/\n",nombre);

stop_sample(m_menu);      

}

//**********************************************************************************************************************************************************
                                                                        /**MENU DE 2:*/
                                                                                                                                            

/**
	\fn  void Ingreso_Usuario(char* nombre)
	\brief Muestra el menu.
	\date 2017.11.20
	\return devuelve STARTAGAIN = 1, EXIT = 0 o CONTINUE = -1.
	\bug No verifica el rango de los números ingresados.
*/ 
      

int menu_2(void){
    
    int salida=0,devolver=0;
    
    
    auxbit=1;
    stop_sample(m_comer);
    
    stop_sample(m_bonus);
    if(mutiar!=1)
        play_sample(m_menu,100,150,800,1);
    
    while(!salida){ 
    
        if(mouse_y>380 && mouse_y<406 && mouse_x>363 && mouse_x<532){
            blit(im_menu_a,pmenu_a,0,0,0,0,870,630); 
            blit(pmenu_a,buffer,0,0,0,0,870,630);
            if(mouse_b & 1){
                salida=1;
                devolver=CONTINUE;
                            }
        }
                            
        else{   
            if(mouse_y>430 && mouse_y<450 && mouse_x>328 && mouse_x<560){
                blit(im_menu_b,pmenu_b,0,0,0,0,870,630);
                blit(pmenu_b,buffer,0,0,0,0,870,630);
                if(mouse_b & 1){
                    salida=1;
                    devolver=STARTAGAIN;
                            }
                                                                        }
            else{   
                if(mouse_y>480 && mouse_y<500 && mouse_x>402 && mouse_x<489){
                    blit(im_menu_c,pmenu_c,0,0,0,0,870,630);
                    blit(pmenu_c,buffer,0,0,0,0,870,630);
                    if(mouse_b & 1){
                        salida=1;
                        devolver=EXIT;
                            }                                                         
                                                                            }
                else{
                    blit(im_menu_d,pmenu_d,0,0,0,0,870,630);
                    blit(pmenu_d,buffer,0,0,0,0,870,630);
                    }
                }                                                         
            }
                     
        blit(imagenCURSOR,cursor,0,0,0,0,12,22);
        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,12,22);
        blit(buffer,screen,0,0,0,0,870,630);
        
            }
            
    stop_sample(m_menu);

    
clear(buffer);
clear(screen);

return devolver;
}

//********************************************************************************************************************************************************
                                                /**CONTADORES DE MINUTOS Y SEGUNDOS*/

                                                

//*************************************************

/**
	\fn  void seg(void)
	\brief Timer de segundos (cuenta hasta 60).
	\date 2017.11.20
    \return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/ 

void seg(void){
    segundoss++;
    if(segundoss==60){
           segundoss=0;
                    }
}
END_OF_FUNCTION(seg);

//*************************************************

/**
	\fn  void seg2(void)
	\brief Timer de segundos (cuenta hasta 20).
	\date 2017.11.20
    \return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/

void seg2(void){
    segundos2++;
    if(segundos2==21){
           segundos2=0;
                    }
}
END_OF_FUNCTION(seg2);

//**************************************************

/**
	\fn  void seg3(void)
	\brief Timer de segundos (cuenta hasta 20).
	\date 2017.11.20
    \return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/

void seg3(void){
    segundos3++;
    if(segundos3==21){
           segundos3=0;
                    }
}
END_OF_FUNCTION(seg3);


//**************************************************
/**
	\fn  void segtramp(void)
	\brief Timer de segundos (cuenta hasta 20) utilizado para cambiar los muros cada 20 segundos.
	\date 2017.11.20
    \return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/

void segtramp(void){
    segundostramp++;
    if(segundostramp==21){
           segundostramp=0;
                    }
}
END_OF_FUNCTION(segtramp);

//***************************************************

/**
	\fn  void min(void)
	\brief Timer de minutos.
	\date 2017.11.20
    \return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/

void min(void){
    minutoss++;
}
END_OF_FUNCTION(min);


//**********************************************************************************************************************************************************
                                                    /**TIEMPO:*/

/**
	\fn int tiempo(struct tiempos *time,int estado_timer)
	\brief Funcion que mide el tiempo que tardas en hacer el nivel, recive flags de la pausa o el  menu para parar el tiempo, tambien recieve la struct tiempo para guardar los minutos y segundos para luego armar el nodo de la lista que se manda al servidor y hacer la pantalla de score.
	\date 2017.11.20
    \return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/

int tiempo(struct tiempos *time,int estado_timer){
    
    (*time).segundos=segundoss;
    (*time).minutos=minutoss;
       
    LOCK_VARIABLE(segundoss);
    LOCK_VARIABLE(minutoss);
    LOCK_FUNCTION(seg);
    LOCK_FUNCTION(min);
   
    if(estado_timer==PAUSAR_TIMER){
        install_int_ex(seg,SECS_TO_TIMER(-1));
        install_int_ex(min,SECS_TO_TIMER(-1));
        
        if((*time).segundos<10)
            textprintf_ex(screen, fuente, 700, 608, makecol(255,255, 255),1, "00:0%d:0%d",minutoss,segundoss);               
            else
                textprintf_ex(screen, fuente, 700, 608, makecol(255,255, 255),1, "00:0%d:%d",minutoss,segundoss);
            
        return segundoss;
    }

    if(estado_timer==REINICIAR_TIMER){
        segundoss=0;
        minutoss=0;
        (*time).segundos=0;
        (*time).minutos=0;
                        }  
    else{
        install_int_ex(seg,SECS_TO_TIMER(1));
        install_int_ex(min,SECS_TO_TIMER(60));
        }

    if((*time).segundos<10)
        textprintf_ex(screen, fuente, 700, 608, makecol(255,255, 255),1, "00:0%d:0%d",(*time).minutos,(*time).segundos);               
        else
            textprintf_ex(screen, fuente, 700, 608, makecol(255,255, 255),1, "00:0%d:%d",(*time).minutos,(*time).segundos);
        
    
return 0;
}

//**********************************************************************************************************************************************************
                                                      /**IMPRIME LAS VIDAS Y LOS PUNTOS EN PANTALLA:*/

/**
	\fn void init_puntuacion(int vidas,int cont)
	\brief Imprime en pantalla la franja que tiene las vidas, el puntaje y el timer.
	\date 2017.11.20
    \return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/

void init_puntuacion(int vidas,int cont){
    
    if(vidas==5){
    blit(imagenPUNTUACION,puntuacion,0,0,0,0,870,30);
    blit(vida,puntuacion,0,0,0,0,30,30);
    blit(vida,puntuacion,0,0,30,0,30,30);
    blit(vida,puntuacion,0,0,60,0,30,30);
    blit(vida,puntuacion,0,0,90,0,30,30);
    blit(vida,puntuacion,0,0,120,0,30,30);
    blit(puntuacion,screen,0,0,0,(20*30),870,30);
    }
    if(vidas==4){
    blit(imagenPUNTUACION,puntuacion,0,0,0,0,870,30);
    blit(vida,puntuacion,0,0,0,0,30,30);
    blit(vida,puntuacion,0,0,30,0,30,30);
    blit(vida,puntuacion,0,0,60,0,30,30);
    blit(vida,puntuacion,0,0,90,0,30,30);
    blit(puntuacion,screen,0,0,0,(20*30),870,30);

    }
    if(vidas==3){
    blit(imagenPUNTUACION,puntuacion,0,0,0,0,870,30);
    blit(vida,puntuacion,0,0,0,0,30,30);
    blit(vida,puntuacion,0,0,30,0,30,30);
    blit(vida,puntuacion,0,0,60,0,30,30);
    blit(puntuacion,screen,0,0,0,(20*30),870,30);

    }
    if(vidas==2){
    blit(imagenPUNTUACION,puntuacion,0,0,0,0,870,30);
    blit(vida,puntuacion,0,0,0,0,30,30);
    blit(vida,puntuacion,0,0,30,0,30,30);
    blit(puntuacion,screen,0,0,0,(20*30),870,30);

    }
    if(vidas==1){
    blit(imagenPUNTUACION,puntuacion,0,0,0,0,870,30);
    blit(vida,puntuacion,0,0,0,0,30,30);
    blit(puntuacion,screen,0,0,0,(20*30),870,30);

    }
    if(vidas==0){
    blit(imagenPUNTUACION,puntuacion,0,0,0,0,870,30);
    blit(puntuacion,screen,0,0,0,(20*30),870,30);

    }
    if(vidas==10){
    blit(imagenPUNTUACION,puntuacion,0,0,0,0,870,30);
    blit(vida,puntuacion,0,0,0,0,30,30);
    blit(vida,puntuacion,0,0,30,0,30,30);
    blit(vida,puntuacion,0,0,60,0,30,30);
    blit(vida,puntuacion,0,0,90,0,30,30);
    blit(vida,puntuacion,0,0,120,0,30,30);
    blit(vida,puntuacion,0,0,150,0,30,30);
    blit(vida,puntuacion,0,0,180,0,30,30);
    blit(vida,puntuacion,0,0,210,0,30,30);
    blit(vida,puntuacion,0,0,240,0,30,30);
    blit(vida,puntuacion,0,0,270,0,30,30);
    blit(puntuacion,screen,0,0,0,(20*30),870,30);

    }
    if(vidas==9){
    blit(imagenPUNTUACION,puntuacion,0,0,0,0,870,30);
    blit(vida,puntuacion,0,0,0,0,30,30);
    blit(vida,puntuacion,0,0,30,0,30,30);
    blit(vida,puntuacion,0,0,60,0,30,30);
    blit(vida,puntuacion,0,0,90,0,30,30);
    blit(vida,puntuacion,0,0,120,0,30,30);
    blit(vida,puntuacion,0,0,150,0,30,30);
    blit(vida,puntuacion,0,0,180,0,30,30);
    blit(vida,puntuacion,0,0,210,0,30,30);
    blit(vida,puntuacion,0,0,240,0,30,30);
    blit(puntuacion,screen,0,0,0,(20*30),870,30);

    }
    if(vidas==8){
    blit(imagenPUNTUACION,puntuacion,0,0,0,0,870,30);
    blit(vida,puntuacion,0,0,0,0,30,30);
    blit(vida,puntuacion,0,0,30,0,30,30);
    blit(vida,puntuacion,0,0,60,0,30,30);
    blit(vida,puntuacion,0,0,90,0,30,30);
    blit(vida,puntuacion,0,0,120,0,30,30);
    blit(vida,puntuacion,0,0,150,0,30,30);
    blit(vida,puntuacion,0,0,180,0,30,30);
    blit(vida,puntuacion,0,0,210,0,30,30);
    blit(puntuacion,screen,0,0,0,(20*30),870,30);
 
    }
    if(vidas==7){
    blit(imagenPUNTUACION,puntuacion,0,0,0,0,870,30);
    blit(vida,puntuacion,0,0,0,0,30,30);
    blit(vida,puntuacion,0,0,30,0,30,30);
    blit(vida,puntuacion,0,0,60,0,30,30);
    blit(vida,puntuacion,0,0,90,0,30,30);
    blit(vida,puntuacion,0,0,120,0,30,30);
    blit(vida,puntuacion,0,0,150,0,30,30);
    blit(vida,puntuacion,0,0,180,0,30,30);
    blit(puntuacion,screen,0,0,0,(20*30),870,30);

    }
    if(vidas==6){
    blit(imagenPUNTUACION,puntuacion,0,0,0,0,870,30);
    blit(vida,puntuacion,0,0,0,0,30,30);
    blit(vida,puntuacion,0,0,30,0,30,30);
    blit(vida,puntuacion,0,0,60,0,30,30);
    blit(vida,puntuacion,0,0,90,0,30,30);
    blit(vida,puntuacion,0,0,120,0,30,30);
    blit(vida,puntuacion,0,0,150,0,30,30);
    blit(puntuacion,screen,0,0,0,(20*30),870,30);
    
    }

    
       textprintf_ex(screen, fuente, 400, 608, makecol(255,255, 255),1, "%d", cont);
     

}


//********************************************************************************************************************************************************** 
                                                                /**IMPRIME EL FANTASMA 1.*/

/**
	\fn void init_fantasma(struct movimiento fantasma1,struct auxiliar puntos,int efecto)
	\brief Imprime en pantalla al fantasma1.
	\date 2017.11.20
    \return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/

void init_fantasma(struct movimiento fantasma1,struct auxiliar puntos,int efecto){
    
        LOCK_VARIABLE(segundos3);
        LOCK_FUNCTION(seg3);
        install_int_ex(seg3,MSEC_TO_TIMER(100));
    
       
         
        if(puntos.bonus==0){
            blit(imagenFANTASMA,fantasma,0,0,0,0,30,30);
            draw_sprite(buffer,fantasma,fantasma1.x,fantasma1.y);
                            }
        if(puntos.bonus==1){
            blit(imagenFANTASMA_AZUL,fantasma,0,0,0,0,30,30);
            draw_sprite(buffer,fantasma,fantasma1.x,fantasma1.y);
                            }
        if(efecto==1&&(segundos3%2==1)){
            if(debug==1)
                printf("parpadeo fantasma\n");
            
            blit(imagenFANTASMA,fantasma,0,0,0,0,30,30);
            draw_sprite(buffer,fantasma,fantasma1.x,fantasma1.y);
                                     }
            
}


//**********************************************************************************************************************************************************
                                                                /**IMPRIME EL FANTASMA 2.*/
            
/**
	\fn void init_fantasma2(struct movimiento fantasmaa2,struct auxiliar puntos,int efecto)
	\brief Imprime en pantalla al fantasma2.
	\date 2017.11.20
    \return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/ 

void init_fantasma2(struct movimiento fantasmaa2,struct auxiliar puntos,int efecto){
    
        LOCK_VARIABLE(segundos3);
        LOCK_FUNCTION(seg3);
        install_int_ex(seg3,MSEC_TO_TIMER(100));
    
        if(puntos.bonus==0){
            blit(imagenFANTASMA2,fantasma2,0,0,0,0,30,30);
            draw_sprite(buffer,fantasma2,fantasmaa2.x,fantasmaa2.y);
                            }
        if(puntos.bonus==1){
            blit(imagenFANTASMA_AZUL,fantasma2,0,0,0,0,30,30);
            draw_sprite(buffer,fantasma2,fantasmaa2.x,fantasmaa2.y);
                            }
        if(efecto==1&&segundos3%2==1){
            
            if(debug==1)
                printf("parpadeo fantasma\n");
        
            blit(imagenFANTASMA2,fantasma2,0,0,0,0,30,30);
            draw_sprite(buffer,fantasma2,fantasmaa2.x,fantasmaa2.y);
                                    }
                                    
}



//**********************************************************************************************************************************************************
                                                                /**IMPRIME EL MAPA.*/

/**
	\fn struct efectoo init_mapa(struct movimiento pacmann,struct movimiento fantasma1,struct movimiento fantasma2,struct auxiliar *p ,int inicio,struct efectoo efecto,int estado_timer,int nivel)
	\brief Imprime en pantalla el mapa.
	\date 2017.11.20
    \return Retorna la struct efecto que contiene la cantidad de bolitas comidas y si comio la bolita bonus.
	\bug No verifica el rango de los números ingresados.
*/    

struct efectoo init_mapa(struct movimiento pacmann,struct movimiento fantasma1,struct movimiento fantasma2,struct auxiliar *p ,int inicio,struct efectoo efecto,int estado_timer,int nivel){
    int i=0,j=0,aux=0;
   
    
        LOCK_VARIABLE(segundos3);
        LOCK_FUNCTION(seg3);
        install_int_ex(seg3,MSEC_TO_TIMER(1000));
        
        
if(nivel==NIVEL1){
    
    if(inicio==REDIBUJAR){                                                              //!< Condicion de REDIBUJAR el mapa.
        
        for(i=0;i<32;i++){                                                              //      
            for(j=0;j<22;j++){                                                          /**REECOLOCO LAS COMIDAS CHIQUITAS.*/
                if(mapa[j][i]==' '){                                                    //
                    mapa[j][i]='o';                                                     //
                    draw_sprite(buffer,comida,(i*30),(j*30));                           //
                                }                                                       //
                            }                                                           //
                        }                                                               //
                                                                                        //
//----------------------------------------------------------------------------------------------------------                          
                        
        for(i=0;i<32;i++){                                                              //
            for(j=0;j<22;j++){                                                          /**REECOLOCO LAS COMIDAS GRANDES.*/
                if(mapa[j][i]=='C'){                                                    //
                    mapa[j][i]='O';                                                     //
                    draw_sprite(buffer,comida,(i*30),(j*30));                           //
                                }                                                       //
                            }                                                           //
                        }   
                        
                        
        if(estado_timer==0){                                                            //
            if(debug==1)                                                                //
                printf("\n\nEntre a la CONDICION de receteo de time\n\n");              //
                                                                                        /**PONGO EL TIMER EN CERO.*/
            install_int_ex(seg2,SECS_TO_TIMER(-1));                                     //
            segundos2=0;                                                                //
            (*p).bonus=0;                                                               //
            return efecto;                                                              //
                        }           
    }
   
//----------------------------------------------------------------------------------------------------------     
    
    else{
        if(inicio==MAPEADO_NORMAL){                                         //!< Condicion de DIBUJAR el mapa.
            for(i=0;i<32;i++){                                              //
                for(j=0;j<22;j++){                                          /*COLOCO LAS PAREDES.*/
                    if(mapa[j][i]== 'X' ){                                  //
                        draw_sprite(buffer,muro,(i*30),(j*30));             //
                                        }                                   //
                                }                                           //
                            }   
                            
//----------------------------------------------------------------------------------------------------------                                                                      
            
            for(i=0;i<32;i++){                                              //
                for(j=0;j<22;j++){                                          /**COLOCO LAS COMIDAS.*/
                    if(mapa[j][i]=='o'){                                    //
                        draw_sprite(buffer,comida,(i*30),(j*30));           //
                            if((pacmann.x/30)==i && (pacmann.y/30)==j && pacmann.x%30==0 && pacmann.y%30==0){ //
                                mapa[j][i]=' ';                             //
                                (*p).puntoss+=1;                            //
                                efecto.cont++;                              //
                                                                            //
                                            }                               //
                                }                                           //
                                }                                           //
            }   
            
//----------------------------------------------------------------------------------------------------------       
            
            for(i=0;i<32;i++){                                              //
                for(j=0;j<22;j++){                                          //      
                    if(mapa[j][i]=='O'){                                    /**COLOCO LAS COMIDAS MAS GRANDES.*/  
                        if(segundos3%2==0){                                 //
                            draw_sprite(buffer,bonus,(i*30),(j*30));        //
                                            }                               //
                        if((pacmann.x/30)==i && (pacmann.y/30)==j && pacmann.x%30==0 && pacmann.y%30==0){         //
                                mapa[j][i]='C';                             //
                                (*p).puntoss+=10;                           //
                                (*p).bonus=1;                               //
                                aux=1;                                      //
                                efecto.cont++;
                                if(mutiar!=1)                               //
                                    play_sample(m_come_bonus,100,150,1000,0);//
                                                                            //
                                                        }                   //          
                                        }                                   //
                                }                                           //  
                            } 
                            
//----------------------------------------------------------------------------------------------------------
            
            for(i=0;i<32;i++){                                              //
                for(j=0;j<22;j++){                                          //
                    if(mapa[j][i]=='c'){                                    /**COLOCO LAS CAJAS QUE BLOQUEAN.*/
                        draw_sprite(buffer,caja,(i*30),(j*30));             //
                                        }                                   //
                                }                                           //
                            } 
                            
//----------------------------------------------------------------
        
        
            if(debug==1)                                                    //
                printf("estado_timer %d\n",estado_timer);                   //
                                                                            //
            if(estado_timer==2){                                            //
                install_int_ex(seg2,SECS_TO_TIMER(-1));                     /**PAUSEO EL TIMER.*/
                                                                            //
                if(debug==1)                                                //
                    printf("segundos2 %d\n",segundos2);                     //
                                                                            //
                return efecto;                                              //
                                }
                                
        
            
            if(aux==1)                                                          
                segundos2=1;
            
            aux=0;
            
            if(debug==1)                                                    //
                printf("%d\n",segundos2);                                   //
                                                                            //
            if((*p).bonus==1){                                              //SE ENCARGAR EL TEMA DE LA MUSICA DEL MODO COMER A LOS FANTASMAS
                    LOCK_VARIABLE(segundos2);                               //Y TAMBIEN EL TIEMPO QUE DURA ESE MODO QUE ES 20 SEGUNDOS.
                    LOCK_FUNCTION(seg2);                                    //
                    install_int_ex(seg2,SECS_TO_TIMER(1));                  //
                if(segundos2>=20){                                          //
                    efecto.efectof=1;                                       //
                    auxiliarmusica++;                                       //
                                }                                           //
                else{                                                       //  
                    efecto.efectof=0;                                       //
                    auxiliarmusica=0;                                       //
                    }                                                       //
                                                                            //
                if(segundos2==0){                                           //
                    (*p).bonus=0;                                           //
                    remove_int(seg2);                                       //
                    segundos2=1;                                            //
                                }
                            }
    
                                    }
                                    
                                
            }
    
    
   
    
return efecto;

}
else{
    
    if(nivel==NIVEL2){                                      
        
            if(inicio==REDIBUJAR){                                                  //!< Condicion de REDIBUJAR el mapa del nivel2.
                
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(mapal2[j][i]==' '){
                            mapal2[j][i]='o';
                            draw_sprite(buffer,comida,(i*30),(j*30));           
                                        }
                                    }
                                }
                                
//----------------------------------------------------------------------------------------------------------                          
                                
                for(i=0;i<32;i++){                                              
                    for(j=0;j<22;j++){                                          
                        if(mapal2[j][i]=='C'){                                    
                            mapal2[j][i]='O';
                            draw_sprite(buffer,comida,(i*30),(j*30));            
                                        }
                                    }
                                }
                                
                if(estado_timer==0){
                    if(debug==1)
                        printf("entre a la CONDICION de receteo de time\n\n\n\n\n\n\n\n\n\n\n");
                    
                    install_int_ex(seg2,SECS_TO_TIMER(-1));
                    segundos2=0;
                    (*p).bonus=0;
                    return efecto;
                                } 
                                
                    }
        
//----------------------------------------------------------------------------------------------------------     
            
            else{
                if(inicio==MAPEADO_NORMAL){
                    
                    for(i=0;i<32;i++){                                              //
                        for(j=0;j<22;j++){                                          /**COLOCO LAS PAREDES.*/
                            if(mapal2[j][i]== 'X' ){                                //
                                draw_sprite(buffer,muro,(i*30),(j*30));             //
                                                }                                   //
                                        }                                           //
                                    }   
                                    
        //----------------------------------------------------------------------------------------------------------                                                                      
                    
                    for(i=0;i<32;i++){                                              //
                        for(j=0;j<22;j++){                                          /**COLOCO LAS COMIDAS.*/
                            if(mapal2[j][i]=='o'){ 
                                draw_sprite(buffer,comida,(i*30),(j*30));           //
                                    if((pacmann.x/30)==i && (pacmann.y/30)==j && pacmann.x%30==0 && pacmann.y%30==0){  //
                                        mapal2[j][i]=' ';                           //
                                        (*p).puntoss+=1;                            //
                                        efecto.cont++;                              //
                                        if(debug==1)                                //
                                            fprintf(stderr,"cont:%d\n",efecto.cont);//
                                                                                    //
                                                    }                               //
                                        }                                           //
                                        }                                           //
                    }   
                    
        //----------------------------------------------------------------------------------------------------------       
                    
                    for(i=0;i<32;i++){                                                //
                        for(j=0;j<22;j++){                                            //      
                            if(mapal2[j][i]=='O'){                                    /**COLOCO LAS COMIDAS MAS GRANDES.*/  
                                if(segundos3%2==0)
                                    draw_sprite(buffer,bonus,(i*30),(j*30));  
                                
                                if((pacmann.x/30)==i && (pacmann.y/30)==j && pacmann.x%30==0 && pacmann.y%30==0){     //
                                        mapal2[j][i]='C';                             //
                                        (*p).puntoss+=10; 
                                        (*p).bonus=1;
                                        aux=1;
                                        efecto.cont++;
                                        if(mutiar!=1)
                                            play_sample(m_come_bonus,100,150,1000,0);
                                    
                                                                }                     //          
                                                }                                     //
                                        }                                             //  
                                    } 
                                    
        //----------------------------------------------------------------------------------------------------------
                    
                    for(i=0;i<32;i++){                                              //
                        for(j=0;j<22;j++){                                          //
                            if(mapal2[j][i]=='c'){                                  /**COLOCO LAS CAJAS QUE BLOQUEAN.*/
                                draw_sprite(buffer,caja,(i*30),(j*30));             //
                                                }                                   //
                                        }                                           //
                                    } 
                                    
        //--------------------------
                
                
                if(debug==1)
                    printf("estado_timer %d\n",estado_timer);
                
                    if(estado_timer==2){
                        install_int_ex(seg2,SECS_TO_TIMER(-1));
                        if(debug==1)
                            printf("segundos2 %d\n",segundos2);
                        
                        return efecto;
                                        }
                                        
                
                    
                    if(aux==1)
                        segundos2=1;
                    
                    aux=0;
                    
                    if(debug==1)
                        printf("%d\n",segundos2);
                    
                    if((*p).bonus==1){
                            LOCK_VARIABLE(segundos2);
                            LOCK_FUNCTION(seg2);
                            install_int_ex(seg2,SECS_TO_TIMER(1));
                        if(segundos2>=20){
                            efecto.efectof=1;
                            auxiliarmusica++;
                                        }
                        else{
                            efecto.efectof=0;
                            auxiliarmusica=0;
                            }
                        
                        if(segundos2==0){
                            (*p).bonus=0;
                            remove_int(seg2);
                            segundos2=1;
                                        }
                                                    }
            
                                        }
            }
            
            
        
            
        return efecto;

                    }
    }

return efecto;
}


//**********************************************************************************************************************************************************
                                                                /**IMPRIME PANTALLA.*/

/**
	\fn void init_pantalla(void)
	\brief Imprime la pantalla.
	\date 2017.11.20
    \return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/    
                                                                
                                                                
void init_pantalla(void){
    
    blit(buffer,screen,0,0,0,0,870,600);
    
}

//**********************************************************************************************************************************************************
                                    /**MUSICA DE COMER AL PACMAN.*/
                                    
/**
	\fn void musica_bonus(struct auxiliar puntos,int i,struct efectoo efecto)
	\brief Reproduce sonidos del juego.
	\date 2017.11.20
    \return Funcion void , no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/ 

void musica_bonus(struct auxiliar puntos,int i,struct efectoo efecto){
    
    if(mutiar==1){
     stop_sample(m_bonus);
     stop_sample(m_finish_bonus);
    }
    else{
        
    if(i==1){
        if(puntos.bonus==1)
            play_sample(m_bonus,100,150,1000,1);
    }
            
    if(i==0){
        stop_sample(m_bonus);
            }
            
    if(auxiliarmusica==1){        
        if(efecto.efectof==1){
            stop_sample(m_bonus);
            play_sample(m_finish_bonus,100,150,1000,0);
                            }
            }
    
    }
}

//********************************************************************************************************************************************************** 
                                                                /**IMPRIME EL CHOQUE ENTRE PACMAN Y EL FANTASMA.*/
              
                                                                
/**
	\fn int choquef1(struct movimiento pacmann,struct movimiento* fantasma,struct movimiento* fantasma2,int anteriorpx,int anteriorpy,int vidas,struct auxiliar* p,struct efectoo efecto,int estado_timer,int anteriorfpx,int anteriorfpy,int nivel)
	\brief Se encarga de resolver el choque de Pacman con el fantasma1, si choco en modo bonus o en modo normal.
	\date 2017.11.20
    \return Retorna choq = 1 si choco con el fantasma en modo normal y choq = 0 si choco en modo bonus y mayor que 1 si no choco .
	\bug No verifica el rango de los números ingresados.
*/     
                                                        
int choquef1(struct movimiento pacmann,struct movimiento* fantasma,struct movimiento* fantasma2,int anteriorpx,int anteriorpy,int vidas,struct auxiliar* p,struct efectoo efecto,int estado_timer,int anteriorfpx,int anteriorfpy,int nivel){
    int i=0,j=0,choq=3;

if(nivel==NIVEL1){
    if((*p).bonus==0){
            if((pacmann.x==(*fantasma).x && pacmann.y+20==(*fantasma).y) ||(pacmann.x+20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y-20==(*fantasma).y) ||(pacmann.x-20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y/10==(*fantasma).y) ||(pacmann.x/10==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y==(*fantasma).y) || (anteriorpx==(*fantasma).x && anteriorpy==(*fantasma).y && (*fantasma).dir!=pacmann.dir)){
                if(mutiar!=1)
                    play_sample(m_muerte_pacman,100,150,1000,0);
                for(i=0;i<=5;i++){
                clear(pacman);
                clear(buffer);
                init_mapa(pacmann,(*fantasma),(*fantasma2),p,0,efecto,estado_timer,NIVEL1);
                blit(muertePACMAN,pacman,(33*i),0,0,0,33,33);
                draw_sprite(buffer,pacman,pacmann.x,pacmann.y);
                init_puntuacion(vidas,(*p).puntoss);
                init_pantalla();
                rest(70);
                                    }
                                    
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='>'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='<'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='|'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='!'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
                            
            mapa2[8][14]='>';
            mapa2[8][19]='!';
            mapa2[13][19]='<';
                                           
                                   
                                    
                choq=1;
                
                                                                                    }
            
                }
        
    if((*p).bonus==1){
     
    if(segundos2<=2){
        for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='>'){                                    
                        mapa2[j][i]='<';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='<'){                                    
                        mapa2[j][i]='>';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='|'){                                    
                        mapa2[j][i]='!';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='!'){                                    
                        mapa2[j][i]='|';
                                    }
                                }
                            }
    }
    else{
          for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='>'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='<'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='|'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='!'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
    }
        
        if((pacmann.x==(*fantasma).x && pacmann.y+20==(*fantasma).y) ||(pacmann.x+20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y-20==(*fantasma).y) ||(pacmann.x-20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y==(*fantasma).y) || (anteriorpx==(*fantasma).x && anteriorpy==(*fantasma).y && (*fantasma).dir!=pacmann.dir)){
                if(mutiar!=1)
                    play_sample(m_muerte_fantasma,100,150,1000,0);
                clear(buffer);
                (*fantasma).x=anteriorfpx;
                (*fantasma).y=anteriorfpy;
                init_mapa(pacmann,(*fantasma),(*fantasma2),p,0,efecto,estado_timer,NIVEL1);
                init_fantasma2((*fantasma2),(*p),0);
                init_fantasma((*fantasma),(*p),0);
                draw_sprite(buffer,pacman,pacmann.x,pacmann.y);
                init_puntuacion(vidas,(*p).puntoss);
                init_pantalla();
                rest(70);
                choq=0;
                }
                    }
        
return choq;            
}
else{
    if(nivel==NIVEL2){
                if((*p).bonus==0){
                    if((pacmann.x==(*fantasma).x && pacmann.y+20==(*fantasma).y) ||(pacmann.x+20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y-20==(*fantasma).y) ||(pacmann.x-20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y==(*fantasma).y) || (anteriorpx==(*fantasma).x && anteriorpy==(*fantasma).y && (*fantasma).dir!=pacmann.dir)){
                        if(mutiar!=1)
                            play_sample(m_muerte_pacman,100,150,1000,0);
                        for(i=0;i<=5;i++){
                        clear(pacman);
                        clear(buffer);
                        init_mapa(pacmann,(*fantasma),(*fantasma2),p,0,efecto,estado_timer,NIVEL2);
                        blit(muertePACMAN,pacman,(33*i),0,0,0,33,33);
                        draw_sprite(buffer,pacman,pacmann.x,pacmann.y);
                        init_puntuacion(vidas,(*p).puntoss);
                        init_pantalla();
                        rest(70);
                                            }
                                            
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='>'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='<'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='|'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='!'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                                    
                    mapalvl2[8][14]='>';
                    mapalvl2[8][19]='!';
                    mapalvl2[13][19]='<';
                    mapalvl2[13][14]='!'; 
                    mapal2[13][14]='!';
                                        
                                            
                        choq=1;
                        
                                                                                                                                                            }
                                                                                                                                                            
                    mapalvl2[8][14]='>';
                    mapalvl2[8][19]='!';
                    mapalvl2[13][19]='<';
                    mapal2[13][14]='!';                                                                                                                                       
                    
                        }
                
            if((*p).bonus==1){
            
            if(segundos2<=2){
                for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='>'){                                    
                                mapalvl2[j][i]='<';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='<'){                                    
                                mapalvl2[j][i]='>';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='|'){                                    
                                mapalvl2[j][i]='<';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='!'){                                    
                                mapalvl2[j][i]='|';
                                            }
                                        }
                                    }
            }
            else{
                for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='>'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='<'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='|'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='!'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                                    
                            
            }
                
                if((pacmann.x==(*fantasma).x && pacmann.y+20==(*fantasma).y) ||(pacmann.x+20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y-20==(*fantasma).y) ||(pacmann.x-20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y==(*fantasma).y) || (anteriorpx==(*fantasma).x && anteriorpy==(*fantasma).y && (*fantasma).dir!=pacmann.dir)){
                        if(mutiar!=1)
                            play_sample(m_muerte_fantasma,100,150,1000,0);
                        clear(buffer);
                        (*fantasma).x=anteriorfpx;
                        (*fantasma).y=anteriorfpy;
                        init_mapa(pacmann,(*fantasma),(*fantasma2),p,0,efecto,estado_timer,NIVEL2);
                        init_fantasma2((*fantasma2),(*p),0);
                        init_fantasma((*fantasma),(*p),0);
                        draw_sprite(buffer,pacman,pacmann.x,pacmann.y);
                        init_puntuacion(vidas,(*p).puntoss);
                        init_pantalla();
                        rest(70);
                        choq=0;
                        }
                        
                    
                            }
                            
                            
                
                
                return choq;            
                    }
    }
    
return choq;
}



//********************************************************************************************************************************************************** 
                                                                /**IMPRIME EL CHOQUE ENTRE PACMAN Y EL FANTASMA2.*/
                                                                
/**
	\fn int choquef2(struct movimiento pacmann,struct movimiento* fantasma,struct movimiento* fantasma2,int anteriorpx,int anteriorpy,int vidas,struct auxiliar* p,struct efectoo efecto,int estado_timer,int anteriorfpx,int anteriorfpy,int nivel)
	\brief Se encarga de resolver el choque de Pacman con el fantasma2, si choco en modo bonus o en modo normal.
	\date 2017.11.20
    \return Retorna choq = 1 si choco con el fantasma en modo normal y choq = 0 si choco en modo bonus y mayor que 1 si no choco .
	\bug No verifica el rango de los números ingresados.
*/      


int choquef2(struct movimiento pacmann,struct movimiento* fantasma,struct movimiento* fantasma2,int anteriorpx,int anteriorpy,int vidas,struct auxiliar* p,struct efectoo efecto,int estado_timer,int anteriorfpx,int anteriorfpy,int nivel){
    int i=0,j=0,choq=3;

if(nivel==NIVEL1){
    if((*p).bonus==0){
            if((pacmann.x==(*fantasma).x && pacmann.y+20==(*fantasma).y) ||(pacmann.x+20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y-20==(*fantasma).y) ||(pacmann.x-20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y==(*fantasma).y) || (anteriorpx==(*fantasma).x && anteriorpy==(*fantasma).y && (*fantasma).dir!=pacmann.dir)){ 
                if(mutiar!=1)
                    play_sample(m_muerte_pacman,100,150,1000,0);
                for(i=0;i<=5;i++){
                clear(pacman);
                clear(buffer);
                init_mapa(pacmann,(*fantasma),(*fantasma2),p,0,efecto,estado_timer,NIVEL1);
                blit(muertePACMAN,pacman,(33*i),0,0,0,33,33);
                draw_sprite(buffer,pacman,pacmann.x,pacmann.y);
                init_puntuacion(vidas,(*p).puntoss);
                init_pantalla();
                rest(70);
                                    }
                                    
                                    
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='>'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='<'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='|'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='!'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
                            
                            
        
            mapa2[8][14]='>';
            mapa2[8][19]='!';
            mapa2[13][19]='<';
                          
                            
                choq=1;
                
                                                                                                                                                    }
            
                }
        
    if((*p).bonus==1){
        
            if(segundos2<=2){
        for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='>'){                                    
                        mapa2[j][i]='<';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='<'){                                    
                        mapa2[j][i]='>';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='|'){                                    
                        mapa2[j][i]='!';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='!'){                                    
                        mapa2[j][i]='|';
                                    }
                                }
                            }
    }
    else{
          for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='>'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='<'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='|'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
            for(i=0;i<32;i++){                                              
                for(j=0;j<22;j++){                                          
                    if(mapa2[j][i]=='!'){                                    
                        mapa2[j][i]=' ';
                                    }
                                }
                            }
    }
        
        if((pacmann.x==(*fantasma).x && pacmann.y+20==(*fantasma).y) ||(pacmann.x+20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y-20==(*fantasma).y) ||(pacmann.x-20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y==(*fantasma).y) || (anteriorpx==(*fantasma).x && anteriorpy==(*fantasma).y && (*fantasma).dir!=pacmann.dir)){
                if(mutiar!=1)
                    play_sample(m_muerte_fantasma,100,150,1000,0);
                clear(buffer);
                (*fantasma).x=anteriorfpx;
                (*fantasma).y=anteriorfpy;
                init_mapa(pacmann,(*fantasma),(*fantasma2),p,0,efecto,estado_timer,NIVEL1);
                init_fantasma2((*fantasma2),(*p),0);
                init_fantasma((*fantasma),(*p),0);
                draw_sprite(buffer,pacman,pacmann.x,pacmann.y);
                init_puntuacion(vidas,(*p).puntoss);
                init_pantalla();
                rest(70);
                choq=0;
                }
                    }
        
return choq;            
}
else{
    if(nivel==NIVEL2){
                
            if((*p).bonus==0){
                    if((pacmann.x==(*fantasma).x && pacmann.y+20==(*fantasma).y) ||(pacmann.x+20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y-20==(*fantasma).y) ||(pacmann.x-20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y==(*fantasma).y) || (anteriorpx==(*fantasma).x && anteriorpy==(*fantasma).y && (*fantasma).dir!=pacmann.dir)){
                        if(mutiar!=1)
                            play_sample(m_muerte_pacman,100,150,1000,0);
                        for(i=0;i<=5;i++){
                        clear(pacman);
                        clear(buffer);
                        init_mapa(pacmann,(*fantasma),(*fantasma2),p,0,efecto,estado_timer,NIVEL2);
                        blit(muertePACMAN,pacman,(33*i),0,0,0,33,33);
                        draw_sprite(buffer,pacman,pacmann.x,pacmann.y);
                        init_puntuacion(vidas,(*p).puntoss);
                        init_pantalla();
                        rest(70);
                                            }
                                            
                                            
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='>'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='<'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='|'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='!'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                                    
                                    
                
                    mapaf2lvl2[8][14]='>';
                    mapaf2lvl2[8][19]='!';
                    mapaf2lvl2[13][19]='<';
                    mapaf2lvl2[13][14]='!';
                                
                                    
                        choq=1;
                        
                                                                                                                                                            }
                    
                        }
                
            if((*p).bonus==1){
                
                    if(segundos2<=2){
                for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='>'){                                    
                                mapalvl2[j][i]='<';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='<'){                                    
                                mapalvl2[j][i]='>';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='|'){                                    
                                mapalvl2[j][i]='!';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='!'){                                    
                                mapalvl2[j][i]='|';
                                            }
                                        }
                                    }
            }
            else{
                for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='>'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='<'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='|'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
                    for(i=0;i<32;i++){                                              
                        for(j=0;j<22;j++){                                          
                            if(mapalvl2[j][i]=='!'){                                    
                                mapalvl2[j][i]=' ';
                                            }
                                        }
                                    }
            }
                
                if((pacmann.x==(*fantasma).x && pacmann.y+20==(*fantasma).y) ||(pacmann.x+20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y-20==(*fantasma).y) ||(pacmann.x-20==(*fantasma).x && pacmann.y==(*fantasma).y) ||(pacmann.x==(*fantasma).x && pacmann.y==(*fantasma).y) || (anteriorpx==(*fantasma).x && anteriorpy==(*fantasma).y && (*fantasma).dir!=pacmann.dir)){
                        if(mutiar!=1)
                            play_sample(m_muerte_fantasma,100,150,1000,0);
                        clear(buffer);
                        (*fantasma).x=anteriorfpx;
                        (*fantasma).y=anteriorfpy;
                        init_mapa(pacmann,(*fantasma),(*fantasma2),p,0,efecto,estado_timer,NIVEL2);
                        init_fantasma2((*fantasma2),(*p),0);
                        init_fantasma((*fantasma),(*p),0);
                        draw_sprite(buffer,pacman,pacmann.x,pacmann.y);
                        init_puntuacion(vidas,(*p).puntoss);
                        init_pantalla();
                        rest(70);
                        choq=0;
                        }
                            }
                
                return choq;            
                    }
    }
    
return choq;
}
                
                
//**********************************************************************************************************************************************************
                                                        /**IMPRIME LA SECUENCIA DE MORDER DE PACMAN.*/

/**
	\fn void init_bit(struct movimiento pacmann)
	\brief Imprime la mordida del pacman.
	\date 2017.11.20
    \return Funcion void, no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/                                                          
                                                        
void init_bit(struct movimiento pacmann){
            

            blit(imagenPACMAN,pacman,(4*33),0,0,0,33,33);
            rest(100);
            masked_blit(pacman,buffer,0,0,pacmann.x,pacmann.y,33,33);

            if(mutiar!=1)
                if(auxbit==1){
                    play_sample(m_comer,100,150,1000,1);
                    auxbit=2;
                        }
            }
            
//**********************************************************************************************************************************************************           
                                                                /**IMPRIME EL CARTEL DE PAUSA.*/
/**
	\fn int init_pausa(void)
	\brief Imprime el cartel de PAUSA.
	\date 2017.11.20
    \return Funcion void, no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/ 

int init_pausa(void){
    int estado_timer=0;
    
    auxbit=1;
    stop_sample(m_comer);
    
    blit(imagenPAUSA,pausa,0,0,0,0,180,40);
    masked_blit(pausa,buffer,0,0,(12*30)-15,10*30,180,40);
    estado_timer=2;
    
return estado_timer; 

}

//**********************************************************************************************************************************************************
                                                                /**IMPRIME EL PACMAN.*/
/**
	\fn void init_pacman(struct movimiento pacmanst)
	\brief Imprime a Pacman en la pocicion reciva como argumento.
	\date 2017.11.20
    \return Funcion void, no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/           

void init_pacman(struct movimiento pacmanst){
    
            blit(imagenPACMAN,pacman,(pacmanst.dir*33),0,0,0,33,33);
            draw_sprite(buffer,pacman,pacmanst.x,pacmanst.y);

            }

//********************************************************************************************************************************************************** 
                                                                /**IMPRIME EL CARTEL DE READY.*/

                                                                
/**
	\fn int init_ready(void)
	\brief Imprime el cartel de READY.
	\date 2017.11.20
    \return Funcion void, no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/   

int init_ready(void){
    int estado_timer=0;
    
    auxbit=1;
    stop_sample(m_comer);
    
    blit(imagenREADY,ready,0,0,0,0,180,40);
    masked_blit(ready,buffer,0,0,(12*30)-15,10*30,180,40);
    
    estado_timer=2;

return estado_timer;
}

//**********************************************************************************************************************************************************           
                                                            /**BORRA EL BUFFER O PACMAN O EL CURSOR O LA PANTALLA.*/
                                                            
/**
	\fn void init_clear(int eleccion)
	\brief Borra el Buffer, pacman, cursor y la pantalla dependiendo del argumento recivido.
	\date 2017.11.20
    \return Funcion void, no tiene retorno.
	\bug No verifica el rango de los números ingresados.
*/   

void init_clear(int eleccion){
   
    if(eleccion==_BUFFER)
        clear(buffer);
    if(eleccion==_PACMAN)
        clear(pacman);
     if(eleccion==_CURSOR)
        clear(cursor);
     if(eleccion==_SCREEN)
         clear(screen);
     
}
 

//**********************************************************************************************************************************************************
                                                            /**PANTALLA DE LOSE.*/
                                                            
/**
	\fn int init_lose(void)
	\brief Imprime la panatalla de PERDISTE.
	\date 2017.11.20
    \return Retornal 0 si se apreto salir y 1 si se apreto comenzar de nuevo.
	\bug No verifica el rango de los números ingresados.
*/   
                                                
int init_lose(void){
   int salida=0,devolver=0;
   
    clear(screen);
    clear(buffer);
    auxbit=1;
    stop_sample(m_comer);
    
     if(mutiar!=1){
        play_sample(m_game_over,200,150,800,0);
                }
                
   while(!salida){ 
        
       if(mouse_y>435 && mouse_y<463 && mouse_x>340 && mouse_x<533){
            blit(lose2,pantallalose,0,0,0,0,870,630); 
            blit(pantallalose,buffer,0,0,0,0,870,630);
            blit(buffer,screen,0,0,0,0,870,630);
            if(mouse_b & 1){
                salida=1;
                devolver=1;
                            }
        }
        else{
            if(mouse_y>486 && mouse_y<528 && mouse_x>400 && mouse_x<474){
                blit(lose3,pantallalose,0,0,0,0,870,630); 
                blit(pantallalose,buffer,0,0,0,0,870,630);
                blit(buffer,screen,0,0,0,0,870,630);
                if(mouse_b & 1){
                    salida=1;
                    devolver=0;
                                }
                                                                        }
            else{
                blit(lose,pantallalose,0,0,0,0,870,630); 
                blit(pantallalose,buffer,0,0,0,0,870,630);
                blit(buffer,screen,0,0,0,0,870,630);
                }
            
            
            }
            
        blit(imagenCURSOR,cursor,0,0,0,0,12,22);
        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,12,22);
        blit(buffer,screen,0,0,0,0,870,630);
       
        }
 
        
return devolver;        
}

//**********************************************************************************************************************************************************
                                                            /**MOVIMIENTO DEL PACMAN*/
                                                            
/**
	\fn struct movimiento movimiento_pacman(struct movimiento pacmann,struct auxiliar puntos)
	\brief Imprime el movimiento del pacman y se encarga de dejar escrito en cada lugar donde estuvo pacman flechas para guiar al fantasma rojo.
	\date 2017.11.20
    \return Retornal 0 si se apreto salir y 1 si se apreto comenzar de nuevo.
	\bug No verifica el rango de los números ingresados.
*/   

struct movimiento movimiento_pacman(struct movimiento pacmann,struct auxiliar puntos){
        int auxiliarx=0,auxiliary=0;
               auxiliarx=pacmann.x;
               auxiliary=pacmann.y;
               
                    if(pacmann.dir==IZQUIERDA){
                        if(mapa2[auxiliary/30][(auxiliarx-10)/30]!='X'&&mapa[auxiliary/30][(auxiliarx-30)/30]!='c'&&auxiliary%30==0){                                          
                            mapa2[auxiliary/30][auxiliarx/30]='<';
                            pacmann.x-=10;
                        }
                                        }
                    if(pacmann.dir==DERECHA){
                        if(mapa2[auxiliary/30][(auxiliarx+30)/30]!='X'&&mapa[auxiliary/30][(auxiliarx+30)/30]!='c'&&auxiliary%30==0){
                            mapa2[auxiliary/30][auxiliarx/30]='>';
                            pacmann.x+=10;
                            
                            
                           
                                                            }
                            }
                            
                    if(pacmann.dir==ARRIBA){
                        if(mapa2[(pacmann.y-10)/30][pacmann.x/30]!='X'&&mapa[(pacmann.y-30)/30][pacmann.x/30]!='c'&&pacmann.x%30==0){
                            mapa2[pacmann.y/30][pacmann.x/30]='|';
                            pacmann.y-=10;
                            
                           
                                                                                                                                    }
                                                                                                    
                            }
                    if(pacmann.dir==ABAJO){
                        if(mapa2[(pacmann.y+30)/30][pacmann.x/30]!='X'&&mapa[(pacmann.y+30)/30][pacmann.x/30]!='c'&&pacmann.x%30==0){
                            mapa2[pacmann.y/30][pacmann.x/30]='!';
                            pacmann.y+=10;
                                                            }

                            }
                                    
                                    
                                    
                                
                if(debug==1)
                    printf("modo comer fantasmas: %d",puntos.bonus);
                    
                if(puntos.bonus==1){
                    if(pacmann.y==(8*30)&&pacmann.x>(8*30)&&pacmann.x<(20*30)){
                        mapa [10][14]='>';
                        
                                                                                }
                    else{
                        mapa [10][14]='|';
                    }                                                            
                                    }
                else{
                        mapa [10][14]='|';
                    }
                                        
return pacmann;

}

//**********************************************************************************************************************************************************
                                                            /**MOVIMIENTO DEL FANTASMA1*/
                                                            
/**
	\fn struct movimiento movimiento_fantasma1(struct movimiento fantasma1,struct movimiento fantasma2)
	\brief Imprime el movimiento del fantasma y lee las flechas en el suelo para salir de la casa y para seguir al pacman.
	\date 2017.11.20
    \return Retorna la struct con las pocicion del fantasma.
	\bug No verifica el rango de los números ingresados.
*/   

struct movimiento movimiento_fantasma1(struct movimiento fantasma1,struct movimiento fantasma2){
    
    int auxdir=0;
    

    if(mapa2[(fantasma1.y/30)][(fantasma1.x/30)]=='|'&&fantasma1.x%30==0&&fantasma1.y%30==0){                 /**CONDICION PARA QUE SALGA DE SU CASA.*/
        if(debug==1)
            fprintf(stderr,"me encontre  | \n");
        fantasma1.dir=2;                                        
                                                    }                            
                
    if(mapa2[(fantasma1.y/30)][(fantasma1.x/30)]=='!'&&fantasma1.x%30==0&&fantasma1.y%30==0){                 /**CONDICION PARA QUE SALGA DE SU CASA.*/
        if(debug==1)  
            fprintf(stderr,"me encontre  ! \n");
        fantasma1.dir=3;                                        
                                                    }
            
    if(mapa2[(fantasma1.y/30)][(fantasma1.x/30)]=='<'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 /**CONDICION PARA QUE SALGA DE SU CASA.*/
        if(debug==1) 
            fprintf(stderr,"me encontre  < \n");
        fantasma1.dir=0;                                        
                                                    }  
                                                    

    if(mapa2[(fantasma1.y/30)][(fantasma1.x/30)]=='>'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 /**CONDICION PARA QUE SALGA DE SU CASA.*/
        if(debug==1)  
            fprintf(stderr,"me encontre  > \n");
        fantasma1.dir=1;                                        
                                                    }  
    
    
    
    
    if(mapa[(fantasma1.y/30)][(fantasma1.x/30)]=='|'&&fantasma1.x%30==0&&fantasma1.y%30==0){                   /**CONDICION PARA QUE SALGA DE SU CASA.*/
        if(debug==1)
            fprintf(stderr,"me encontre  | \n");
        fantasma1.dir=2;                                        
                                                    }                            
                
    if(mapa[(fantasma1.y/30)][(fantasma1.x/30)]=='!'&&fantasma1.x%30==0&&fantasma1.y%30==0){                   /**CONDICION PARA QUE SALGA DE SU CASA.*/
        if(debug==1) 
            fprintf(stderr,"me encontre  ! \n");
        fantasma1.dir=3;                                       
                                                    }
            
    if(mapa[(fantasma1.y/30)][(fantasma1.x/30)]=='<'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 /**CONDICION PARA QUE SALGA DE SU CASA.*/
        if(debug==1)
            fprintf(stderr,"me encontre  < \n");
        fantasma1.dir=0;                                      
                                                    }  
                                                    

    if(mapa[(fantasma1.y/30)][(fantasma1.x/30)]=='>'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 /**CONDICION PARA QUE SALGA DE SU CASA.*/
        if(debug==1)
            fprintf(stderr,"me encontre  > \n");
        fantasma1.dir=1;                                        
                                                    }  
      
//----------------------------------------------------------------------------------------------------------    
                                                    /**MOVIMIENTO ALEATORIO DEL FANTASMA*/

/**IZQUIERDA*/  

   if(fantasma1.dir==0){                                           
        if(fantasma1.y%30==0&&mapa2[fantasma1.y/30][(fantasma1.x-10)/30]!='X' && ((((fantasma1.x-10)/30)!=(fantasma2.x/30))||((fantasma1.y/30)!=(fantasma2.y/30))) ){                
                fantasma1.x-=10;
                                                                                                                           }
        else{  
            auxdir=rand()%1;
            if(fantasma1.x%30==0&&auxdir==1&&mapa2[(fantasma1.y-10)/30][fantasma1.x/30]!='X' && ((((fantasma1.y-30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30)))  ){
                    fantasma1.y-=10;
                                                                                                                                        }
            if(fantasma1.x%30==0&&auxdir==0&&mapa2[(fantasma1.y+30)/30][fantasma1.x/30]!='X' && ((((fantasma1.y+30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                    fantasma1.y+=10;
                                                                                                                                        }
            else{
                fantasma1.dir=(rand()%2)+1;
                }
            }                                   
                    }
     
//----------------------------------------------------------------------------------------------------------                  
/**DERECHA*/   

    if(fantasma1.dir==1){                                              
        if(fantasma1.y%30==0&&mapa2[fantasma1.y/30][(fantasma1.x+30)/30]!='X'&& ((((fantasma1.x+30)/30)!=(fantasma2.x/30))||((fantasma1.y/30)!=(fantasma2.y/30))) ){
                fantasma1.x+=10;
                                                                                                                            }
        else{                                   
            auxdir=rand()%1;
            if(fantasma1.x%30==0&&auxdir==1&&mapa2[(fantasma1.y-10)/30][fantasma1.x/30]!='X' && ((((fantasma1.y-30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                    fantasma1.y-=10;
                                                                                                                                        }
            if(fantasma1.x%30==0&&auxdir==0&&mapa2[(fantasma1.y+30)/30][fantasma1.x/30]!='X' && ((((fantasma1.y+30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                    fantasma1.y+=10;
                                                                                                                                        }
            else{
                fantasma1.dir=(rand()%2)+1;
                }
            }  
                        }          
                        
//----------------------------------------------------------------------------------------------------------   
/**ARRIBA*/ 

    if(fantasma1.dir==2){                                              
        if(fantasma1.x%30==0&&mapa2[(fantasma1.y-10)/30][fantasma1.x/30]!='X'&& ((((fantasma1.y-30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                fantasma1.y-=10;
                                                                                                                                                                }
        else{                                   
            fantasma1.dir=rand()%4;  
            if(fantasma1.dir==3)
                fantasma1.dir=rand()%4;
            }      
                        }
                        
//----------------------------------------------------------------------------------------------------------              
/**ABAJO*/   

    if(fantasma1.dir==3){                                            
            if(fantasma1.x%30==0&&mapa2[(fantasma1.y+30)/30][fantasma1.x/30]!='X'&& mapa2[(fantasma1.y+30)/30][fantasma1.x/30]!='|' && ((((fantasma1.y+30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                fantasma1.y+=10;
                                                    }
            else{                                   
                fantasma1.dir=rand()%3;
                if(fantasma1.dir==2)
                        fantasma1.dir=rand()%3;
                }                          
                        }  
             
             
return fantasma1;                            
}



//**********************************************************************************************************************************************************
                                                            /**MOVIMIENTO DEL FANTASMA2*/
                                                            
/**
	\fn struct movimiento movimiento_fantasma2(struct movimiento fantasma1,struct movimiento fantasma2)
	\brief Imprime el movimiento del fantasma y lee las flechas en el suelo para salir de la casa.
	\date 2017.11.20
    \return Retorna la struct con la pocicion del fantasma.
	\bug No verifica el rango de los números ingresados.
*/                                                              

struct movimiento movimiento_fantasma2(struct movimiento fantasma1,struct movimiento fantasma2){
    
    int auxdir=0;
    

    
    if(mapa[(fantasma1.y/30)][(fantasma1.x/30)]=='|'&&fantasma1.y%30==0&&fantasma1.x%30==0){                   //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=2;                                        
                                                    }                            
                
                            
    if(mapa[(fantasma1.y/30)][(fantasma1.x/30)]=='<'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=0;                                        
                                                    }  
                                                    

    if(mapa[(fantasma1.y/30)][(fantasma1.x/30)]=='>'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=1;                                        
                                                    }  
                                                    
//---------------------------------------------------------------------------------------------------------- 
                                        /**MOVIMIENTO ALEATORIO DEL FANTASMA*/


/**IZQUIERDA*/  

   if(fantasma1.dir==0){                                           
        if(fantasma1.y%30==0&&mapa2[fantasma1.y/30][(fantasma1.x-10)/30]!='X' && ((((fantasma1.x-10)/30)!=(fantasma2.x/30))||((fantasma1.y/30)!=(fantasma2.y/30))) ){                
                fantasma1.x-=10;
                                                                                                                           }
        else{  
            auxdir=rand()%1;
            if(fantasma1.x%30==0&&auxdir==1&&mapa2[(fantasma1.y-10)/30][fantasma1.x/30]!='X' && ((((fantasma1.y-30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30)))  ){
                    fantasma1.y-=10;
                                                                                                                                        }
            if(fantasma1.x%30==0&&auxdir==0&&mapa2[(fantasma1.y+30)/30][fantasma1.x/30]!='X' && ((((fantasma1.y+30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                    fantasma1.y+=10;
                                                                                                                                        }
            else{
                fantasma1.dir=(rand()%2)+1;
                }
            }                                   
                    }
     
//----------------------------------------------------------------------------------------------------------                  
/**DERECHA*/    

    if(fantasma1.dir==1){                                              
        if(fantasma1.y%30==0&&mapa2[fantasma1.y/30][(fantasma1.x+30)/30]!='X'&& ((((fantasma1.x+30)/30)!=(fantasma2.x/30))||((fantasma1.y/30)!=(fantasma2.y/30))) ){
                fantasma1.x+=10;
                                                                                                                            }
        else{                                   
            auxdir=rand()%1;
            if(fantasma1.x%30==0&&auxdir==1&&mapa2[(fantasma1.y-10)/30][fantasma1.x/30]!='X' && ((((fantasma1.y-30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                    fantasma1.y-=10;
                                                                                                                                        }
            if(fantasma1.x%30==0&&auxdir==0&&mapa2[(fantasma1.y+30)/30][fantasma1.x/30]!='X' && ((((fantasma1.y+30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                    fantasma1.y+=10;
                                                                                                                                        }
            else{
                fantasma1.dir=(rand()%2)+1;
                }
            }  
                        }          
                        
//----------------------------------------------------------------------------------------------------------   
/**ARRIBA*/

    if(fantasma1.dir==2){                                              
        if(fantasma1.x%30==0&&mapa2[(fantasma1.y-10)/30][fantasma1.x/30]!='X'&& ((((fantasma1.y-30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                fantasma1.y-=10;
                                                                                                                                                                }
        else{                                   
            fantasma1.dir=rand()%4;  
            if(fantasma1.dir==3)
                fantasma1.dir=rand()%4;
            }      
                        }
                        
//----------------------------------------------------------------------------------------------------------              
/**ABAJO*/   

    if(fantasma1.dir==3){                                            
            if(fantasma1.x%30==0&&mapa2[(fantasma1.y+30)/30][fantasma1.x/30]!='X'&& mapa2[(fantasma1.y+30)/30][fantasma1.x/30]!='|' && ((((fantasma1.y+30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                fantasma1.y+=10;
                                                    }
            else{                                   
                fantasma1.dir=rand()%3;
                if(fantasma1.dir==2)
                        fantasma1.dir=rand()%3;
                }                          
                        }  
             
             
return fantasma1;                            
}


//**********************************************************************************************************************************************************
                                                            /**PANTALLA SCORE.*/
                                                            

/**
	\fn void score_pantalla(char* score,struct tiempos tiemposs, struct auxiliar puntos,char* nombre)
	\brief Recibe la lista con los mejores puntajes y los imprime en la pantalla.
	\date 2017.11.20
    \return Funcion void, no retorna ningun valor.
	\bug No verifica el rango de los números ingresados.
*/ 

                                                            
void score_pantalla(char* score,struct tiempos tiemposs, struct auxiliar puntos,char* nombre){
    
    char *p,*listaux,*j1,*j2,*j3,*j4,*j5,*j6,*nombreauxiliar,*aux,lose[26]="No estas en el ranking...";
    int i=0,salida=0,contador=0;
    
    p=NULL;
    j1=NULL;
    j2=NULL;
    j3=NULL;
    j4=NULL;
    j5=NULL;
    j6=NULL;
    listaux=NULL;
    nombreauxiliar=NULL;
    aux=NULL;
    
    j1=(char*)calloc(256,1);
    j2=(char*)calloc(256,1);
    j3=(char*)calloc(256,1);
    j4=(char*)calloc(256,1);
    j5=(char*)calloc(256,1);
    j6=(char*)calloc(256,1);
    listaux=(char*)calloc(256,1);
    nombreauxiliar=(char*)calloc(256,1);
    aux=(char*)calloc(256,1);
    
    
    
    memset((void *) j1, '\0', 256);
    memset((void *) j2, '\0', 256);
    memset((void *) j3, '\0', 256);
    memset((void *) j4, '\0', 256);
    memset((void *) j5, '\0', 256);
    memset((void *) j6, '\0', 256);
    memset((void *) nombreauxiliar, '\0', 256);
    memset((void *) aux, '\0', 256);
    memset((void *) listaux, '\0', 256);
    
    
    if(debug==1)
        fprintf(stderr,"estoy empezando con score_pantalla();\n");
    
    clear(buffer);
    clear(screen);
    nombre[6]='\0';
    strcpy(nombreauxiliar,nombre);
    sprintf(aux,"%d",puntos.puntoss);
    strcat(nombreauxiliar," ");
    strcat(nombreauxiliar,aux);
    strcat(nombreauxiliar," ");
    strcat(nombreauxiliar,"0");
    strcat(nombreauxiliar,":");
    
    memset((void *) aux, '\0', 256);
       
    sprintf(aux,"%d",tiemposs.minutos);
    strcat(nombreauxiliar,aux);
    strcat(nombreauxiliar,":");

    memset((void *) aux, '\0', 256);
    
    sprintf(aux,"%d",tiemposs.segundos);
    strcat(nombreauxiliar,aux);
    
    
    if(debug==1)
        fprintf(stderr,"nombreauxiliar:%s\n",nombreauxiliar);
    
    
    
    strcpy(listaux,score);
    
    if(debug==1)
        fprintf(stderr,"estoy partiendo a j1\n");
     
    p=strtok(listaux,"-");
    strcpy(j1,p);
    
    if(debug==1)
        fprintf(stderr,"estoy partiendo a j2\n");
    
    p=strtok(NULL,"-");
    strcpy(j2,p);
    
    if(debug==1)
        fprintf(stderr,"estoy partiendo a j3\n");
    
    p=strtok(NULL,"-");
    strcpy(j3,p);
    
    p=strtok(NULL,"-");
    strcpy(j4,p);
    
    p=strtok(NULL,"-");
    strcpy(j5,p);
    
    p=strtok(NULL,"-");
    strcpy(j6,p);
    
    p=NULL;
    
    if(debug==1)
        fprintf(stderr,"estoy armando la lista en la pantalla\n");
    
    p=strtok(j1,"/");
    j1[strlen(p)]=' ';
    p=strtok(j1,"/");
    j1[strlen(p)]=' ';
    
    strcat(scorepantalla[7],j1);
    
    
    p=strtok(j2,"/");
    j2[strlen(p)]=' ';
    p=strtok(j2,"/");
    j2[strlen(p)]=' ';
    
    strcat(scorepantalla[9],j2);
    
    
    p=strtok(j3,"/");
    j3[strlen(p)]=' ';
    p=strtok(j3,"/");
    j3[strlen(p)]=' ';
    
    strcat(scorepantalla[11],j3);
    
    p=strtok(j4,"/");
    j4[strlen(p)]=' ';
    p=strtok(j4,"/");
    j4[strlen(p)]=' ';
    
    strcat(scorepantalla[13],j4);
    
    p=strtok(j5,"/");
    j5[strlen(p)]=' ';
    p=strtok(j5,"/");
    j5[strlen(p)]=' ';
    
    strcat(scorepantalla[15],j5);
    
    p=strtok(j6,"/");
    j6[strlen(p)]=' ';
    p=strtok(j6,"/");
    j6[strlen(p)]=' ';
    
    strcat(scorepantalla[17],j6);
    
    if(debug==1)
        fprintf(stderr,"estoy en la seleccion de posicion\n");
    
    if(debug==1){
        for(i=7;i<19;i++){
            printf("%s\n",scorepantalla[i]);
                        }
                    }
    if(strcmp(nombreauxiliar,j1)==0){
        if(debug==1)
            fprintf(stderr,"Eres el juegador numero 1\n%s\n%s\n",nombreauxiliar,j1);
        contador=1;
                                    }
    else{
        if(strcmp(nombreauxiliar,j2)==0){
            if(debug==1)
                fprintf(stderr,"Eres el juegador numero 2\n%s\n%s\n",nombreauxiliar,j2);
            contador=2;
                                        }
        else{
            if(strcmp(nombreauxiliar,j3)==0){
                if(debug==1)
                    fprintf(stderr,"Eres el juegador numero 3\n%s\n%s\n",nombreauxiliar,j3);
                contador=3;
                                            }
            else{
                if(strcmp(nombreauxiliar,j4)==0){
                    if(debug==1)
                        fprintf(stderr,"Eres el juegador numero 4\n%s\n%s\n",nombreauxiliar,j4);
                    contador=4;
                                                }
                else{
                    if(strcmp(nombreauxiliar,j5)==0){
                        if(debug==1)
                            fprintf(stderr,"Eres el juegador numero 5\n%s\n%s\n",nombreauxiliar,j5);
                        contador=5;
                                                    }
                    else{
                        if(strcmp(nombreauxiliar,j6)==0){
                            if(debug==1)
                                fprintf(stderr,"Eres el juegador numero 6\n%s\n%s\n",nombreauxiliar,j6);
                            contador=6;
                                                        }
                        else{
                            if(debug==1)
                                fprintf(stderr,"NO ESTAS DENTRO DE LOS MEJORES PUNTAJES\n");
                            contador=7;
                                    
                            }
                        }
                    }
                }
            }
        }
                
    
    if(contador==1){
        strcpy(scorepantalla[7],"                        ");
        strcat(scorepantallaN[7],j1);
                   }
    
    if(contador==2){
        strcpy(scorepantalla[9],"                        ");
        strcat(scorepantallaN[9],j2);
                   }
                   
    if(contador==3){
        strcpy(scorepantalla[11],"                        ");
        strcat(scorepantallaN[11],j3);
                   }
                   
    if(contador==4){
        strcpy(scorepantalla[13],"                        ");
        strcat(scorepantallaN[13],j4);
                   }
    
    if(contador==5){
        strcpy(scorepantalla[15],"                        ");
        strcat(scorepantallaN[15],j5);
                   }
                   
    if(contador==6){
        strcpy(scorepantalla[17],"                        ");
        strcat(scorepantallaN[17],j6);
                   }
                   
    
    if(contador==7){
        strcpy(scorepantalla[19],"                        ");
        strcat(scorepantallaR[19],lose);
                   }
                                 
    
    while(!salida){ 
        
         
                    
        if(mouse_y>560 && mouse_y<585 && mouse_x>716 && mouse_x<814){
            blit(fondoscore2,fondoSCORE,0,0,0,0,870,630); 
            blit(fondoSCORE,buffer,0,0,0,0,870,630);
            init_pantallaUSUARIO(PANTALLA_SCORE3);
            init_pantallaUSUARIO(PANTALLA_SCORE);
            if(mouse_b & 1){
                salida=1;
                stop_sample(m_menu);
                            }
                                                                    }
        
        else{
            blit(fondoscore,fondoSCORE,0,0,0,0,870,630);
            blit(fondoSCORE,buffer,0,0,0,0,870,630);
            init_pantallaUSUARIO(PANTALLA_SCORE3);
            init_pantallaUSUARIO(PANTALLA_SCORE);
            }
                                                                        
        blit(imagenCURSOR,cursor,0,0,0,0,12,22);
        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,12,22);
        blit(buffer,screen,0,0,0,0,870,630);
       
        
            }
    
   
 
                    
                    
    
}


//**********************************************************************************************************************************************************
                                                            /**PANTALLA WIN.*/
                                                            

/**
	\fn void init_win(void)
	\brief Imprime la pantalla de GANADOR.
	\date 2017.11.20
    \return Funcion void, no retorna ningun valor.
	\bug No verifica el rango de los números ingresados.
*/ 


void init_win(void){
    
    clear(buffer);
    clear(screen);
    
    auxbit=1;
    stop_sample(m_comer);
    
    if(mutiar!=1)
        play_sample(m_menu,100,150,800,1);
    
    blit(win,pantallawin,0,0,0,0,870,700);
    blit(pantallawin,buffer,0,0,0,0,870,700);
    blit(buffer,screen,0,0,0,0,870,700);
    rest(3000);
    
    clear(buffer);
    clear(screen);
    
    
    
}


//**********************************************************************************************************************************************************
                                                                        /**MENU DE INICIO.*/

/**
	\fn void init_win(void)
	\brief Imprime el Menu de inicio.
	\date 2017.11.20
    \return Retorna 0 si se apreto el boton exit y 1 si se apreto empezar el juego y 2 si se hizo la combinacion de teclas que te otorga 5 vidas extras.
	\bug No verifica el rango de los números ingresados.
*/ 
      
        
int menu_inicio(void){
    int salida=0,i=0,devolver=1,aux=0,agregar_vidas=0;
    volatile int mute=0;
    
    

    auxbit=1;
    stop_sample(m_comer);
    
    while(!salida){ 
        aux=0;
        mute=0;
       
        if(i==0)
            play_sample(m_menu,100,150,800,1);
        
        i++;
        
        if(mouse_y>370 && mouse_y<400 && mouse_x>335 && mouse_x<536){
            blit(imagenFONDO2,fondo2,0,0,0,0,870,630); 
            blit(fondo2,buffer,0,0,0,0,870,630);
            if(mouse_b & 1){
                salida=1;
                mute=1;
                mutiar=0;
                if(agregar_vidas==1)
                    devolver=2;
                if(agregar_vidas==0)
                    devolver=1;
                               }
                                                                    }
                                                                    
                                                        
         else{          
             
                    
            if(mouse_y>0 && mouse_y<40 && mouse_x>828 && mouse_x<866){
                blit(imagenFONDO1,fondo1,0,0,0,0,870,630);
                blit(fondo1,buffer,0,0,0,0,870,630);
                rest(90);
                if(mouse_b & 1){
                    rest(90);
                if(!mouse_b & 1){
                    if(debug==1)
                        fprintf(stderr,"dentro de mute\n");
                   
                    while(!mute){
                        
                        stop_sample(m_menu);
                        
                        aux=0;
                        if(mouse_y>370 && mouse_y<400 && mouse_x>335 && mouse_x<536){
                            blit(imagenmute2,fondomute2,0,0,0,0,870,630); 
                            blit(fondomute2,buffer,0,0,0,0,870,630);
                            if(mouse_b & 1){
                                mute=1;
                                salida=1;
                                mutiar=1;
                                if(agregar_vidas==1)
                                    devolver=2;
                                if(agregar_vidas==0)
                                    devolver=1;
                                            }
                                                                                    }
                                                                                    
                                                                        
                        else{          
                            
                            
                            if(mouse_y>0 && mouse_y<40 && mouse_x>828 && mouse_x<866){
                                blit(imagenmute1,fondomute1,0,0,0,0,870,630);
                                blit(fondomute1,buffer,0,0,0,0,870,630);
                                if(mouse_b & 1){
                                        mute=1;
                                        salida=0;
                                        i=0;
                                                }
                                                                                        }                                                                                          


                                else{   
                                    if(mouse_x>400 && mouse_x<483 && mouse_y>473 && mouse_y<497){
                                        blit(imagenmute3,fondomute3,0,0,0,0,870,630);
                                        blit(fondomute3,buffer,0,0,0,0,870,630);
                                        if(mouse_b & 1){
                                            salida=1;
                                            mute=1;
                                            devolver=0;
                                                    }
                                                                                    }
                                                                                    
                                                                                

                                        else{
                                            if(mouse_y>422 && mouse_y<451 && mouse_x>358 && mouse_x<522){
                                                blit(imagenmute4,fondomute4,0,0,0,0,870,630);
                                                blit(fondomute4,buffer,0,0,0,0,870,630);
                                                if(mouse_b & 1){
                                                    while(!aux){  
                                                        if(mouse_x>14 && mouse_x<115 && mouse_y>580 && mouse_y<610){
                                                            blit(imagenFONDO6,fondo6,0,0,0,0,870,630);
                                                            blit(fondo6,buffer,0,0,0,0,870,630);
                                                            if(mouse_b & 1){
                                                            aux=1;
                                                                            }    
                                                                                                                    }
                                                        else{
                                                                blit(imagenFONDO5,fondo5,0,0,0,0,870,630);
                                                                blit(fondo5,buffer,0,0,0,0,870,630);
                                                                }
                                                        blit(imagenCURSOR,cursor,0,0,0,0,12,22);
                                                        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,12,22);
                                                        blit(buffer,screen,0,0,0,0,870,630);
                                                                }
                                                                }
                                                                
                                            
                                                                                                        }
                                                                                                        
                                            else{                                        
                                                blit(imagenmute1,fondomute1,0,0,0,0,870,630);
                                                blit(fondomute1,buffer,0,0,0,0,870,630);
                                                if(key[KEY_UP]&&key[KEY_DOWN]){
                                                       rest(100);
                                                    if(key[KEY_RIGHT]&&key[KEY_LEFT]){ 
                                                            agregar_vidas=1;
                                                                                    }
                                                                                }
                                                }
                                }
                        }
                    }
                    blit(imagenCURSOR,cursor,0,0,0,0,12,22);
                    masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,12,22);
                    blit(buffer,screen,0,0,0,0,870,630);
                            
                                }
                
                                    }
                
                                }
                                if(debug==1)
                                    fprintf(stderr,"salgo de mute2\n");
                    
                                                                        }
                                                                         


                else{   
                    if(mouse_x>400 && mouse_x<483 && mouse_y>473 && mouse_y<497){
                        blit(imagenFONDO3,fondo3,0,0,0,0,870,630);
                        blit(fondo3,buffer,0,0,0,0,870,630);
                        if(mouse_b & 1){
                            salida=1;
                            devolver=0;
                                    }
                                                                    }
                                                                    
                                                                

                        else{
                            if(mouse_y>422 && mouse_y<451 && mouse_x>358 && mouse_x<522){
                                blit(imagenFONDO4,fondo4,0,0,0,0,870,630);
                                blit(fondo4,buffer,0,0,0,0,870,630);
                                if(mouse_b & 1){
                                    while(!aux){  
                                        if(mouse_x>14 && mouse_x<115 && mouse_y>580 && mouse_y<610){
                                            blit(imagenFONDO6,fondo6,0,0,0,0,870,630);
                                            blit(fondo6,buffer,0,0,0,0,870,630);
                                            if(mouse_b & 1){
                                            aux=1;
                                                            }    
                                                                                                    }
                                        else{
                                                blit(imagenFONDO5,fondo5,0,0,0,0,870,630);
                                                blit(fondo5,buffer,0,0,0,0,870,630);
                                                }
                                        blit(imagenCURSOR,cursor,0,0,0,0,12,22);
                                        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,12,22);
                                        blit(buffer,screen,0,0,0,0,870,630);
                                                }
                                                }
                                                
                            
                                                                                        }
                            else{                                        
                            blit(imagenFONDO1,fondo1,0,0,0,0,870,630);
                            blit(fondo1,buffer,0,0,0,0,870,630);
                            if(key[KEY_UP]&&key[KEY_DOWN]){
                                        agregar_vidas=1;
                                                            }
                                }
                            }
                    }
         }
        blit(imagenCURSOR,cursor,0,0,0,0,12,22);
        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,12,22);
        blit(buffer,screen,0,0,0,0,870,630);
        
    
   }
   
    
   

    clear(buffer);
    clear(screen);
    if(debug==1)
        fprintf(stderr,"mutiar:%d\n",mutiar);
    
    if(mutiar==1)
        stop_sample(m_menu);

    
    
return devolver;   
}



//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************

                                    /**FUNCIONES NIVEL 2:*/                                    
                                    
                                    
//**********************************************************************************************************************************************************
                                        /**FUNCION DE TRAMPAS.*/
                                        

/**
	\fn void trampas(int estado_timer)
	\brief Pone y saca muros cada 10 segundos para modificar el mapa del nivel 2.
	\date 2017.11.20
    \return Funcion void, no retorna ningun valor.
	\bug No verifica el rango de los números ingresados.
*/ 

void trampas(int estado_timer){
    
  
    
    if(estado_timer==2){
            
            LOCK_VARIABLE(segundostramp);
            LOCK_FUNCTION(segtramp);
        
            install_int_ex(segtramp,SECS_TO_TIMER(-1));
            
            if(debug==1){
                printf("se paro el tiempo\n");
                printf("segundos tramp: %d\n",segundostramp);
                        }
                        
                        }
            
    
    if(estado_timer==0){
            LOCK_VARIABLE(segundostramp);
            LOCK_FUNCTION(segtramp);
        
            install_int_ex(segtramp,SECS_TO_TIMER(1));
            
            if(debug==1)
                printf("segundos tramp: %d\n",segundostramp);
            
            
            if(segundostramp==10){
                
            mapal2[10][8]=' ';
            mapaf2lvl2[10][8]=' ';   
            mapalvl2[10][8]=' ';
            

            mapaf2lvl2[10][9]='<';  
            
            mapal2[10][20]=' ';
            mapaf2lvl2[10][20]=' ';   
            mapalvl2[10][20]=' ';
            
            
            mapal2[7][14]=' ';
            mapaf2lvl2[7][14]=' ';   
            mapalvl2[7][14]=' ';
            
            
                                }
            if(segundostramp==20){
                if(debug==1)
                    printf("volver el mapa como antes\n");
                
                mapal2[7][14]='X';
                mapaf2lvl2[7][14]='X';   
                mapalvl2[7][14]='X';
                
                mapal2[10][8]='X';
                mapaf2lvl2[10][8]='X';   
                mapalvl2[10][8]='X';
            
                mapaf2lvl2[10][9]=' '; 
                
                mapal2[10][20]='X';
                mapaf2lvl2[10][20]='X';   
                mapalvl2[10][20]='X';
                
                                }
            

            
                                    }
            
    
            
}


//**********************************************************************************************************************************************************
                                             /**MOVIMIENTO PACMAN LVL2.*/

/**
	\fn struct movimiento movimiento_pacmanlvl2(struct movimiento pacmann,struct auxiliar puntos)
	\brief Imprime el movimiento del pacman del nivel 2.
	\date 2017.11.20
    \return Retorna la strcut con la posicion de pacman.
	\bug No verifica el rango de los números ingresados.
*/ 

struct movimiento movimiento_pacmanlvl2(struct movimiento pacmann,struct auxiliar puntos){
        int auxiliarx=0,auxiliary=0;
               auxiliarx=pacmann.x;
               auxiliary=pacmann.y;
               
                    if(pacmann.dir==IZQUIERDA){
                        if(mapalvl2[auxiliary/30][(auxiliarx-10)/30]!='X'&&mapal2[auxiliary/30][(auxiliarx-30)/30]!='c'&&auxiliary%30==0){                                          
                            mapalvl2[auxiliary/30][auxiliarx/30]='<';
                            pacmann.x-=10;
                        }
                                        }
                    if(pacmann.dir==DERECHA){
                        if(mapalvl2[auxiliary/30][(auxiliarx+30)/30]!='X'&&mapal2[auxiliary/30][(auxiliarx+30)/30]!='c'&&auxiliary%30==0){
                            mapalvl2[auxiliary/30][auxiliarx/30]='>';
                            pacmann.x+=10;
                            
                            
                           
                                                            }
                            }
                            
                    if(pacmann.dir==ARRIBA){
                        if(mapalvl2[(pacmann.y-10)/30][pacmann.x/30]!='X'&&mapal2[(pacmann.y-30)/30][pacmann.x/30]!='c'&&pacmann.x%30==0){
                            mapalvl2[pacmann.y/30][pacmann.x/30]='|';
                            pacmann.y-=10;
                            
                           
                                                                                                                                    }
                                                                                                    
                            }
                    if(pacmann.dir==ABAJO){
                        if(mapalvl2[(pacmann.y+30)/30][pacmann.x/30]!='X'&&mapal2[(pacmann.y+30)/30][pacmann.x/30]!='c'&&pacmann.x%30==0){
                            mapalvl2[pacmann.y/30][pacmann.x/30]='!';
                            pacmann.y+=10;
                                                            }

                            }
                                    
                                    
                                    
                                
                if(debug==1)
                    printf("%d",puntos.bonus);
                    
                if(puntos.bonus==1){
                    if(pacmann.y==(8*30)&&pacmann.x>(8*30)&&pacmann.x<(20*30)){
                        mapal2[10][14]='>';
                        
                                                                                }
                    else{
                        mapal2[10][14]='|';
                    }                                                            
                                    }
                else{
                        mapal2[10][14]='|';
                    }
                                        
return pacmann;

}



//**********************************************************************************************************************************************************
                                              /**MOVIMIENTO FANTASMA 1 LVL2.*/


/**
	\fn struct movimiento movimiento_fantasma1lvl2(struct movimiento fantasma1,struct movimiento fantasma2)
	\brief Imprime el movimiento del fantasma1 del nivel 2.
	\date 2017.11.20
    \return Retorna la strcut con la posicion del fantasma.
	\bug No verifica el rango de los números ingresados.
*/ 

struct movimiento movimiento_fantasma1lvl2(struct movimiento fantasma1,struct movimiento fantasma2){
    
    int auxdir=0;
 
    
                                                    
                                                    
    if(mapal2[(fantasma1.y/30)][(fantasma1.x/30)]=='|'&&fantasma1.y%30==0&&fantasma1.x%30==0){                   //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=2;                                        
                                                    }                            
                
                            
    if(mapal2[(fantasma1.y/30)][(fantasma1.x/30)]=='<'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=0;                                        
                                                    }  
                                                    

    if(mapal2[(fantasma1.y/30)][(fantasma1.x/30)]=='>'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=1;                                        
                                                    }  
                                                    
                                                    
                                                    
    if(mapalvl2[(fantasma1.y/30)][(fantasma1.x/30)]=='|'&&fantasma1.y%30==0&&fantasma1.x%30==0){                   //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=2;                                        
                                                    }                            
                
                            
    if(mapalvl2[(fantasma1.y/30)][(fantasma1.x/30)]=='<'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=0;                                        
                                                    }  
                                                    

    if(mapalvl2[(fantasma1.y/30)][(fantasma1.x/30)]=='>'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=1;                                        
                                                    }  
                                                    
    if(mapalvl2[(fantasma1.y/30)][(fantasma1.x/30)]=='!'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=3;                                        
                                                    }  
                                                    
//----------------------------------------------------------------------------------------------------------                  
//IZQUIERDA  

   if(fantasma1.dir==0){                                           
        if(fantasma1.y%30==0&&mapalvl2[fantasma1.y/30][(fantasma1.x-10)/30]!='X' && ((((fantasma1.x-10)/30)!=(fantasma2.x/30))||((fantasma1.y/30)!=(fantasma2.y/30))) ){                
                fantasma1.x-=10;
                                                                                                                           }
        else{  
            auxdir=rand()%1;
            if(fantasma1.x%30==0&&auxdir==1&&mapalvl2[(fantasma1.y-10)/30][fantasma1.x/30]!='X' && ((((fantasma1.y-30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30)))  ){
                    fantasma1.y-=10;
                                                                                                                                        }
            if(fantasma1.x%30==0&&auxdir==0&&mapalvl2[(fantasma1.y+30)/30][fantasma1.x/30]!='X' && ((((fantasma1.y+30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                    fantasma1.y+=10;
                                                                                                                                        }
            else{
                fantasma1.dir=(rand()%2)+1;
                }
            }                                   
                    }
     
//----------------------------------------------------------------------------------------------------------                  
//DERECHA    

    if(fantasma1.dir==1){                                              
        if(fantasma1.y%30==0&&mapalvl2[fantasma1.y/30][(fantasma1.x+30)/30]!='X'&& ((((fantasma1.x+30)/30)!=(fantasma2.x/30))||((fantasma1.y/30)!=(fantasma2.y/30))) ){
                fantasma1.x+=10;
                                                                                                                            }
        else{                                   
            auxdir=rand()%1;
            if(fantasma1.x%30==0&&auxdir==1&&mapalvl2[(fantasma1.y-10)/30][fantasma1.x/30]!='X' && ((((fantasma1.y-30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                    fantasma1.y-=10;
                                                                                                                                        }
            if(fantasma1.x%30==0&&auxdir==0&&mapalvl2[(fantasma1.y+30)/30][fantasma1.x/30]!='X' && ((((fantasma1.y+30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                    fantasma1.y+=10;
                                                                                                                                        }
            else{
                fantasma1.dir=(rand()%2)+1;
                }
            }  
                        }          
                        
//----------------------------------------------------------------------------------------------------------   
//ARRIBA 

    if(fantasma1.dir==2){                                              
        if(fantasma1.x%30==0&&mapalvl2[(fantasma1.y-10)/30][fantasma1.x/30]!='X'&& ((((fantasma1.y-30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                fantasma1.y-=10;
                                                                                                                                                                }
        else{                                   
            fantasma1.dir=rand()%4;  
            if(fantasma1.dir==3)
                fantasma1.dir=rand()%4;
            }      
                        }
                        
//----------------------------------------------------------------------------------------------------------              
//ABAJO   

    if(fantasma1.dir==3){                                            
            if(fantasma1.x%30==0&&mapalvl2[(fantasma1.y+30)/30][fantasma1.x/30]!='X'&& mapa2[(fantasma1.y+30)/30][fantasma1.x/30]!='|' && ((((fantasma1.y+30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                fantasma1.y+=10;
                                                    }
            else{                                   
                fantasma1.dir=rand()%3;
                if(fantasma1.dir==2)
                        fantasma1.dir=rand()%3;
                }                          
                        }  
             
             
return fantasma1;                            
}




//**********************************************************************************************************************************************************
                                            /**MOVIMIENTO FANTASMA 2 LVL2.*/


/**
	\fn struct movimiento movimiento_fantasma2lvl2(struct movimiento fantasma1,struct movimiento fantasma2)
	\brief Imprime el movimiento del fantasma1 del nivel 2.
	\date 2017.11.20
    \return Retorna la strcut con la posicion del fantasma 2 del nivel 2.
	\bug No verifica el rango de los números ingresados.
*/ 


struct movimiento movimiento_fantasma2lvl2(struct movimiento fantasma1,struct movimiento fantasma2){
    
    int auxdir=0;
    
    if(mapal2[(fantasma1.y/30)][(fantasma1.x/30)]=='|'&&fantasma1.y%30==0&&fantasma1.x%30==0){                   //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=2;                                        
                                                    }                            
                
                            
    if(mapal2[(fantasma1.y/30)][(fantasma1.x/30)]=='<'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=0;                                        
                                                    }  
                                                    

    if(mapa2[(fantasma1.y/30)][(fantasma1.x/30)]=='>'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=1;                                        
                                                    }  
                                                    
    if(mapaf2lvl2[(fantasma1.y/30)][(fantasma1.x/30)]=='|'&&fantasma1.y%30==0&&fantasma1.x%30==0){                   //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=2;                                        
                                                    }                            
                
                            
    if(mapaf2lvl2[(fantasma1.y/30)][(fantasma1.x/30)]=='<'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=0;                                        
                                                    }  
                                                    

    if(mapaf2lvl2[(fantasma1.y/30)][(fantasma1.x/30)]=='>'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=1;                                        
                                                    }  
                                                         
     if(mapaf2lvl2[(fantasma1.y/30)][(fantasma1.x/30)]=='!'&&fantasma1.y%30==0&&fantasma1.x%30==0){                 //CONDICION PARA QUE SALGA DE SU CASA.
            
            fantasma1.dir=3;                                        
                                                    }                                                 
    
                                                    
//----------------------------------------------------------------------------------------------------------                  
//IZQUIERDA  

   if(fantasma1.dir==0){                                           
        if(fantasma1.y%30==0&&mapalvl2[fantasma1.y/30][(fantasma1.x-10)/30]!='X' && ((((fantasma1.x-10)/30)!=(fantasma2.x/30))||((fantasma1.y/30)!=(fantasma2.y/30))) ){                
                fantasma1.x-=10;
                                                                                                                           }
        else{  
            auxdir=rand()%1;
            if(fantasma1.x%30==0&&auxdir==1&&mapalvl2[(fantasma1.y-10)/30][fantasma1.x/30]!='X' && ((((fantasma1.y-30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30)))  ){
                    fantasma1.y-=10;
                                                                                                                                        }
            if(fantasma1.x%30==0&&auxdir==0&&mapalvl2[(fantasma1.y+30)/30][fantasma1.x/30]!='X' && ((((fantasma1.y+30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                    fantasma1.y+=10;
                                                                                                                                        }
            else{
                fantasma1.dir=(rand()%2)+1;
                }
            }                                   
                    }
     
//----------------------------------------------------------------------------------------------------------                  
//DERECHA    

    if(fantasma1.dir==1){                                              
        if(fantasma1.y%30==0&&mapalvl2[fantasma1.y/30][(fantasma1.x+30)/30]!='X'&& ((((fantasma1.x+30)/30)!=(fantasma2.x/30))||((fantasma1.y/30)!=(fantasma2.y/30))) ){
                fantasma1.x+=10;
                                                                                                                            }
        else{                                   
            auxdir=rand()%1;
            if(fantasma1.x%30==0&&auxdir==1&&mapalvl2[(fantasma1.y-10)/30][fantasma1.x/30]!='X' && ((((fantasma1.y-30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                    fantasma1.y-=10;
                                                                                                                                        }
            if(fantasma1.x%30==0&&auxdir==0&&mapalvl2[(fantasma1.y+30)/30][fantasma1.x/30]!='X' && ((((fantasma1.y+30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                    fantasma1.y+=10;
                                                                                                                                        }
            else{
                fantasma1.dir=(rand()%2)+1;
                }
            }  
                        }          
                        
//----------------------------------------------------------------------------------------------------------   
//ARRIBA 

    if(fantasma1.dir==2){                                              
        if(fantasma1.x%30==0&&mapalvl2[(fantasma1.y-10)/30][fantasma1.x/30]!='X'&& ((((fantasma1.y-30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                fantasma1.y-=10;
                                                                                                                                                                }
        else{                                   
            fantasma1.dir=rand()%4;  
            if(fantasma1.dir==3)
                fantasma1.dir=rand()%4;
            }      
                        }
                        
//----------------------------------------------------------------------------------------------------------              
//ABAJO   

    if(fantasma1.dir==3){                                            
            if(fantasma1.x%30==0&&mapalvl2[(fantasma1.y+30)/30][fantasma1.x/30]!='X'&& mapa2[(fantasma1.y+30)/30][fantasma1.x/30]!='|' && ((((fantasma1.y+30)/30)!=(fantasma2.y/30))||((fantasma1.x/30)!=(fantasma2.x/30))) ){
                fantasma1.y+=10;
                                                    }
            else{                                   
                fantasma1.dir=rand()%3;
                if(fantasma1.dir==2)
                        fantasma1.dir=rand()%3;
                }                          
                        }  
             
             
return fantasma1;                            
}

    
    
    
//**********************************************************************************************************************************************************
                                                      /**IMPRIME EL CARTEL DE LVL 2.*/
                                                      
/**
	\fn void init_lvl2(void)
	\brief Imprime el cartel de NIVEL 2.
	\date 2017.11.20
    \return Funcion void, no retorna ningun valor.
	\bug No verifica el rango de los números ingresados.
*/                                                  

void init_lvl2(void){
    
    
    blit(imagenLVL2,LVL2,0,0,0,0,180,40);
    masked_blit(LVL2,buffer,0,0,(12*30)-15,10*30,180,40);
    stop_sample(m_comer);

}


//**********************************************************************************************************************************************************
                                      /**IMPRIME EN LA PANTALLA ERROR CONEXION LOS PUNTAJES*/
                                      
                                      
/**
	\fn void score_en_error(struct tiempos tiemposs, struct auxiliar puntos,char *nombre)
	\brief Imprime el nombre del usuario en la pantalla de error en la conexion con el servidor.
	\date 2017.11.20
    \return Funcion void, no retorna ningun valor.
	\bug No verifica el rango de los números ingresados.
*/              

void score_en_error(struct tiempos tiemposs, struct auxiliar puntos,char *nombre){
    char score[1024],aux[1024];
    
    memset((void *) score, '\0', 1024);
    memset((void *) aux, '\0', 1024);
    
    strcpy(score,nombre);
    sprintf(aux,"%d",puntos.puntoss);
    strcat(score,aux);
    strcat(scorepantalla2[15],score);
    
    if(debug==1)
        fprintf(stderr,"%s\n",scorepantalla2[15]);
    
}


//**********************************************************************************************************************************************************
                                            /**IMPRIME PANTALLA ERROR CONEXION*/
                                            
/**
	\fn void init_error_conexion(struct tiempos tiemposs, struct auxiliar puntos,char *nombre)
	\brief Imprime la pantalla de error en la conexion con el servidor.
	\date 2017.11.20
    \return Funcion void, no retorna ningun valor.
	\bug No verifica el rango de los números ingresados.
*/   

void init_error_conexion(struct tiempos tiemposs, struct auxiliar puntos,char *nombre){
    
    int salida=0,i=0;
    
    
    
    clear(buffer);
    clear(screen);
    
    while(!salida){ 
    
        if(mouse_y>548 && mouse_y<575 && mouse_x>395 && mouse_x<481){
            blit(ERROR_CONEXION2,pantallaERROR_CONEXION2,0,0,0,0,870,630); 
            blit(pantallaERROR_CONEXION2,buffer,0,0,0,0,870,630);
            init_pantallaUSUARIO(PANTALLA_SCORE2); 
            if(mouse_b & 1){
                salida=1;
                            }
        }
        
        else{
            blit(ERROR_CONEXION,pantallaERROR_CONEXION,0,0,0,0,870,630);
            blit(pantallaERROR_CONEXION,buffer,0,0,0,0,870,630);
            if(i==0){
                score_en_error(tiemposs,puntos,nombre);
                    }
            init_pantallaUSUARIO(PANTALLA_SCORE2); 
            i++;
            }
                                                                        
        blit(imagenCURSOR,cursor,0,0,0,0,12,22);
        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,12,22);
        blit(buffer,screen,0,0,0,0,870,630);
        
            }
            

    
}


//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************



