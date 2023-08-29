#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct{
    char nombre[20];
    char dni[10];
    int edad;
}stAlumno;

void cargarArchivoRandom(char nombreArchivo[]);
void getName(char n[],int numRan);
void getDni(char d[],int numRan);
int getEdad(int numRand);
void mostrarAlumno(stAlumno alumno);
void mostrarArchivo(char nombreArchivo[]);
#endif // ALUMNO_H_INCLUDED
