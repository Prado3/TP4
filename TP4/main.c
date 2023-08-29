#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "alumno.h"
#include <time.h>
#define ESC 27
#define ARCHI_ALUMNO "alumno.dat"

void menu();
int mostrarOpciones();

int main()
{
    menu();

    return 0;
}

void menu(){
    char opSalir;
    int opcion=0;

    do{
        system("cls");
        opcion=mostrarOpciones();
        switch(opcion){
        case 1:
            cargarArchivoRandom(ARCHI_ALUMNO);
            mostrarArchivo(ARCHI_ALUMNO);
        }
        printf("\n Ingrese ESC para salir del programa");
        printf("\n Ingrese ENTER para volver al menu");
        opSalir=getch();
    }while(opSalir!=ESC);
}

int mostrarOpciones(){
    int i=0;
    printf("\n ======================================================");
    printf("\n 1 = Crear archivo cargado(solo si no se creo antes)");
    printf("\n 2 = Leer un archivo y pasarlo a una lista");
    printf("\n ======================================================");
    printf("\n Ingrese la opcion a seleccionar: ");
    scanf("%d",&i);
    return i;
}

