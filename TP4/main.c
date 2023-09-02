#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "alumno.h"
#include "listaAlumno.h"
#include <time.h>
#define ESC 27
#define ARCHI_ALUMNO "alumno.dat"
#define DIM 30

void menu();
int mostrarOpciones();
nodo* cargarLista(nodo* lista,char nombreArchivo[]);
void pasarListaArchivo(char nombreArchivo[],nodo* lista);
int pasarArchiArreglo(stAlumno alumnos[],int dim, char nombreArchi[]);
void mostrarArregloAlumno(stAlumno arreglo[], int validos);
nodo* arregloALista(stAlumno arreglo[], int validos, nodo* lista);
nodo* agregarEnOrdenDni(nodo* lista, nodo* nuevo);

int main()
{

    menu();

    return 0;
}

void menu(){
    char opSalir;
    int opcion=0;
    nodo* lista = inicLista();
    stAlumno alumnos[DIM];
    int validos=0;
    do{
        system("cls");
        opcion=mostrarOpciones();
        switch(opcion){
        case 1:
            cargarArchivoRandom(ARCHI_ALUMNO);
            mostrarArchivo(ARCHI_ALUMNO);
            break;
        case 2:
            lista = cargarLista(lista,ARCHI_ALUMNO);
            break;
        case 3:
            muestraLista(lista);
            break;
        case 4:
            mostrarArchivo(ARCHI_ALUMNO);
            break;
        case 5:
            pasarListaArchivo(ARCHI_ALUMNO,lista);
            break;
        case 6:
            validos = pasarArchiArreglo(alumnos,DIM,ARCHI_ALUMNO);
            printf("\n %d", validos);
            break;
        case 7:
            OrdenacionporSeleccion(alumnos,validos);
            break;
        case 8:
            mostrarArregloAlumno(alumnos,validos);
            break;
        case 9:
            lista = arregloALista(alumnos,validos,lista);
            break;
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
    printf("\n 3 = Muestra una lista");
    printf("\n 4 = Mostrar archivo");
    printf("\n 5 = Pasar lista archivo");
    printf("\n 6 = Pasar archivo a arreglo");
    printf("\n 7 = ordenamiento por seleccion");
    printf("\n 8 = muestra arreglo");
    printf("\n 9 = pasar arreglo a lista");
    printf("\n ======================================================");
    printf("\n Ingrese la opcion a seleccionar: ");
    scanf("%d",&i);
    return i;
}

nodo* cargarLista(nodo* lista,char nombreArchivo[]){
    stAlumno alumno;

    FILE* archi = fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&alumno,sizeof(alumno),1,archi)>0){
            lista = agregarAlPrincipio(lista,crearNodo(alumno));
        }
    }
    return lista;
}

void pasarListaArchivo(char nombreArchivo[],nodo* lista){
    FILE* archi=fopen(nombreArchivo,"a+b");
    nodo* aux = lista;
    if(archi){
        while(aux){
            fwrite(&aux->dato,sizeof(aux->dato),1,archi);
            aux = aux->sig;
        }
        fclose(archi);
    }
}

int pasarArchiArreglo(stAlumno alumnos[],int dim, char nombreArchi[]){
    FILE* archi = fopen(nombreArchi,"rb");
    int v=0;
    stAlumno alumno;
    if(archi){
        while(v<dim && fread(&alumno,sizeof(stAlumno),1,archi)>0){
            alumnos[v]=alumno;
            v++;
        }
        fclose(archi);
    }
    return v;
}

int PosMenor (stAlumno arreglo[], int pos, int validos){
    int menor=arreglo[pos].edad;
    int posmenor=pos;
    int i=pos+1;
        while (i<validos){
            if(menor>arreglo[i].edad){
                menor=arreglo[i].edad;
                posmenor=i;
            }
            i++;
        }
    return posmenor;
}

void OrdenacionporSeleccion (stAlumno arreglo[], int validos){
    stAlumno aux;
    int posmenor;
    int i=0;
        while (i<validos-1){
            posmenor=PosMenor(arreglo,i,validos);
            aux=arreglo[posmenor];
            arreglo[posmenor]=arreglo[i];
            arreglo[i]=aux;
            i++;
        }

}
void mostrarArregloAlumno(stAlumno arreglo[], int validos){
    for(int i=0;i<validos;i++){
        mostrarAlumno(arreglo[i]);
    }
}

nodo* arregloALista(stAlumno arreglo[], int validos, nodo* lista){
    int i=0;
    while(i<validos){
        //lista = agregarAlPrincipio(lista,crearNodo(arreglo[i]));
        lista = agregarAlFinal(lista,crearNodo(arreglo[i]));
    }
    return lista;
}

nodo* agregarEnOrdenDni(nodo* lista, nodo* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        if(atoi(nuevo->dato.dni) <= atoi(lista->dato.dni)){
            lista = agregarAlPrincipio(lista,nuevo);
        }else{
            nodo* ante = lista;
            nodo* aux = lista->sig;
            while(aux && atoi(nuevo->dato.dni ) > atoi(aux->dato.dni)){
                ante = aux;
                aux = aux->sig;
            }
            nuevo->sig=aux;
            ante->sig = nuevo;
        }
    }
    return lista;
}




