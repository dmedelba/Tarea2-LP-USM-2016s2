#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sansano.h"
#include "CartaCurso.h"
#include "lista.h"

/******** Funcion: inicializacion ********************
Descripcion: Inicia la lista(mazo)
Parametros: Lista *lista
Retorno: nada
************************************************/
void incializacion(Lista *lista){
    lista->inicio = NULL;
    lista->fin= NULL;
    lista->tamano = 0;
}

/******** Funcion: InsercionEnListaVacia ********************
Descripcion:Inserta un elemento cuando la lista esta vacia.
Parametros:Lista *lista, CartaCurso *cartaca
Retorno:nada 
************************************************/
int InsercionEnListaVacia(Lista *lista, CartaCurso *cartaca){
    Elemento *nuevo_elemento;
    if((nuevo_elemento = (Elemento *)malloc(sizeof(Elemento)))==NULL)
        return -1;
    nuevo_elemento->carta= cartaca;
    nuevo_elemento->siguiente = NULL;
    lista->inicio = nuevo_elemento;
    lista->fin = nuevo_elemento;
    lista->actual = nuevo_elemento;
    lista->tamano++;
    return 0;
}
/******** Funcion:ObtenerInicio ********************
Descripcion: Obtiene el elemento inicial de la lista(mazo).
Parametros: Lista *lista
Retorno: Retorna el elemento inicial de la lista.
************************************************/
Elemento* obtenerInicio(Lista *lista){
    Elemento *sup_elemento;
    sup_elemento = lista->inicio;
    lista->inicio=lista->inicio->siguiente;
    if(lista->tamano==1)
        lista->fin = NULL;
    lista->tamano--;
    return sup_elemento;
}

/******** Funcion:InsercionFinLista ********************
Descripcion: Inserta un elemento al final de la lista (cartaca).
Parametros:Lista *lista , CartaCurso *cartaca 
Retorno: retorna 0 al momento de haber agregado la carta
************************************************/
int InsercionFinLista(Lista *lista, CartaCurso *cartaca){
    Elemento *nuevo_elemento;
    if((nuevo_elemento = (Elemento *)malloc(sizeof(Elemento)))==NULL)
        return -1;
    lista->actual->siguiente = nuevo_elemento;
    nuevo_elemento->siguiente = NULL;
    nuevo_elemento->carta=cartaca;
 
    lista->fin = nuevo_elemento;
    lista->actual = nuevo_elemento;
    lista->tamano++;
    return 0;
}

/******** Funcion: Destruir ********************
Descripcion: Liberamos memoria utilizada por la lista.
Parametros:Lista *lista
Retorno: nada , solo aplica free.
************************************************/
void destruir(Lista * lista){
  	while (lista->tamano > 0){
		Elemento *sup_elemento;
		sup_elemento = lista->inicio;
		lista->inicio=lista->inicio->siguiente;
		if(lista->tamano==1)
		    lista->fin = NULL;
		free(sup_elemento->carta);
		free(sup_elemento);
		lista->tamano--;
	}
}
