#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "alumno.h"
#include <time.h>
#define ESC 27

void cargarArchivoRandom(char nombreArchivo[]){
    stAlumno alumno;
    srand(time(NULL));
    int num=0;
    int i=0;
    FILE* archi=fopen(nombreArchivo,"a+b");

    if(archi){
        while(i<10){
            i++;
            num=rand()%20;
            getName(alumno.nombre,num);
            getDni(alumno.dni,num);
            alumno.edad=getEdad(num);
            fwrite(&alumno,sizeof(stAlumno),1,archi);
            fclose(archi);
            FILE* archi=fopen(nombreArchivo,"a+b");
        }
        fclose(archi);
    }

}

void getName(char n[],int numRan){
    char names[][20]={"Amalio","Juan","Roberto","Antonio","Pedro","Fernando","Jacinto","Anibal","Antonio","Atalayo",
                           "Bertino","Anastasio","Amor","Arturo","Diego","Mario","Tamaro","Adolfo","Alfonso","Pedro","Alfredo",
                           "Rolando","Mauro","Amancio","Benicio","Bertin","Ildefonso","Amilcar","Cuchuflito","Jazmino",
                           "Remilgo"};
    strcpy(n,names[numRan]);
}

void getDni(char d[],int numRan){
    char dnis[][20]={"28740858","29651813","40184442","26104249","32997809","35794895","27589790","38354542","34180521","24021740",
                           "30462341","39294102","27810158","26978925","31489645","30170275","41543371","29233430","23010622","23278318","36174131",
                           "27711944","37790238","29343879","27116347","38697631","35025026","31928840","37681104","37977745",
                           "29810168"};
    strcpy(d,dnis[numRan]);
}

int getEdad(int numRand){
    int edades[20]={18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};

    return edades[numRand];
}

void mostrarAlumno(stAlumno alumno){
    printf("\n=======================");
    printf("\n Nombre:...%s",alumno.nombre);
    printf("\n DNI:......%s",alumno.dni);
    printf("\n Edad:.....%d",alumno.edad);
    printf("\n=======================");
}

void mostrarArchivo(char nombreArchivo[]){
    stAlumno alumno;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0){
            mostrarAlumno(alumno);
        }
        fclose(archi);
    }
}


