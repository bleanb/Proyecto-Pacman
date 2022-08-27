#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
    
    fprintf(stderr,"Ejecute: %s CLEAR para borrar el directorio de configuracion\n",argv[0]);
    
    if (argc<2){
        fprintf(stderr,"Se instalaran las dependencias para el Pacman:\n");
        fprintf(stderr,"Instalando libreria Allegro 4:\n");
        system("sudo apt-get install liballegro4.2-dev");
        system("clear");
        fprintf(stderr,"Allegro 4 instalado correctamente.\n");
                }
                
    if (argc==2){
        if(strstr(argv[1],"CLEAR")!=NULL){
            system("cd .. && rm -R Config");
            fprintf(stderr,"Directorio borrado correctamente\n");
                                        }
        else{
            if(strstr(argv[1],"Clear")!=NULL){
                system("cd .. && rm -R Config");
                fprintf(stderr,"Directorio borrado correctamente\n");
                                            }
            else{
                if(strstr(argv[1],"clear")!=NULL){
                    system("cd .. && rm -R Config");
                    fprintf(stderr,"Directorio borrado correctamente\n");
                                                }  
                                                
                else fprintf(stderr,"ERROR, INGRESO PARAMETRO ERRONEO\nEjecute: %s CLEAR para borrar el directorio de configuracion\n",argv[0]);
                }
            }
                }
                
    if (argc>2){   
        fprintf(stderr,"ERROR, INGRESO PARAMETROS DE MÁS\nEjecute: %s CLEAR para borrar el directorio de configuracion\n",argv[0]);
                }
}
