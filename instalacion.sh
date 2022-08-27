#!/bin/bash
echo "Script de Instalacion de programas:\n";
while true; do
echo
read -p "Desea instalar las dependencias? [S\n] " yn
case $yn in
s) 
i=0;
break;;

n)
i=1;
#break;;
exit;;

S) 
i=0;
break;;

N) 
i=1;
#break;;
exit;;

si)
i=0;
break;;


no) 
i=1;
#break;;
exit;;

SI) 
i=0;
break;;


NO) 
i=1;
#break;;
exit;;

Si)
i=0;
break;;


No)
i=1;
#break;;
exit;;


*) echo "por favor responda si o no\n";;
esac
done
#if [ i = 0 ]; then
#actualizar
sudo apt-get update
#instalar
echo "Se instalara Allegro 4:\n"
sudo apt-get install liballegro4.2-dev
#fi
clear
echo "Instalacion finalizada.\n"
echo "\n\n\n"
echo "Script de compilacion:";
while :
do
echo "Escoja una opcion:"
echo "1. Compilar pacman"
echo "2. Compilar Server"
echo "3. Compilar ambas cosas"
echo "4. Eliminar ejecutable Pacman"
echo "5. Eliminar ejecutable Server"
echo "6. Eliminar ambos ejecutables"
echo "Escriba salir/exit para terminar."
echo -n "Seleccione una opcion [1 - 6]\n"
read opcion
case $opcion in

1)
cd pacman ;
make;
cd ..;
echo "Se compilo Pacman";;


2)
cd server;
make;
cd ..;
echo "Se compilo el Servidor";;


3)
cd pacman;
make;
cd ..;
cd server;
make;
cd ..;
echo "Se compilo Pacman y el Servidor";;


4)
cd pacman;
make clean;
cd ..;
echo "Se elimino el ejecutable de Pacman";;


5)
cd server;
make clean;
cd ..;
echo "Se elimino el ejecutable del Servidor";;


6)
cd pacman;
make clean;
cd ..;
cd server;
make clean;
cd ..;
echo "Se elimino el ejecutable de Pacman y del Servidor";;


Salir)  echo "Cerrando el script."  ;
exit 1;;
salir)  echo "Cerrando el script."  ;
exit 1;;
exit)  echo "Cerrando el script."  ;
exit 1;;
SALIR)  echo "Cerrando el script."  ;
exit 1;;
EXIT)  echo "Cerrando el script."  ;
exit 1;;
Exit)  echo "Cerrando el script."  ;
exit 1;;
*) echo "No igreso una opcion valida";
echo "Presiona una tecla para continuar...";
read foo;;
esac
done

