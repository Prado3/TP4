#include "listaAlumno.h"
#include <stdio.h>
#include <stdlib.h>

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stAlumno dato){
    nodo* nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

nodo* agregarAlPrincipioDidactica(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista = nuevo;
    }else{
        nuevo->sig=lista;
        lista=nuevo;
    }
    return lista;
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevo){
    nuevo->sig=lista;
    return nuevo;
}

void muestraNodo(nodo* nodoCliente){
    printf("\n _____ %p", nodoCliente);
    mostrarAlumno(nodoCliente->dato);
    printf("\n >>>>>>> %p", nodoCliente->sig);

}

void muestraLista(nodo* lista){
    nodo* aux = lista;
    while(aux){
        muestraNodo(aux);
        aux = aux->sig;
    }
}

void muestraListaRecursiva(nodo* lista){
    if(lista){
        muestraNodo(lista);
        muestraListaRecursiva(lista->sig);
    }
}

int cuentaNodos(nodo* lista){
    int cont=0;
    nodo* aux = lista;
    while(aux){
        cont++;
        aux = aux->sig;
    }
    return cont;
}

int cuentaNodosRecursivo(nodo* lista){
    int cont=0;
    if(lista){
        cont = 1 + cuentaNodosRecursivo(lista->sig);
    }
    return cont;
}

int cuentaNodosRecursivoConFiltro(nodo* lista){
    int cont=0;
    if(lista){
        if(lista->dato.edad >20){
        cont = 1 + cuentaNodosRecursivoConFiltro(lista->sig);
        }else{
        cont = cuentaNodosRecursivoConFiltro(lista->sig);
        }
    }
    return cont;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    lista->sig=nuevo;
    return lista;
}
