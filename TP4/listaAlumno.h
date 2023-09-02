#ifndef LISTAALUMNO_H_INCLUDED
#define LISTAALUMNO_H_INCLUDED

#include "alumno.h"

typedef struct{
    stAlumno dato;
    struct nodo* sig;
}nodo;

nodo* inicLista();
nodo* crearNodo(stAlumno dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* neuvo);
void muestraNodo(nodo* nodoCliente);
void muestraLista(nodo* lista);
int cuentaNodos(nodo* lista);
void muestraListaRecursiva(nodo* lista);
nodo* agregarAlPrincipioDidactica(nodo* lista, nodo* nuevo);
int cuentaNodosRecursivoConFiltro(nodo* lista);
int cuentaNodosRecursivo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);


#endif // LISTAALUMNO_H_INCLUDED
