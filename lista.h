#ifndef _LISTA_H_INCLUDED_
#define _LISTA_H_INCLUDED_


typedef struct ElementoLista{
    CartaCurso *carta;
    struct ElementoLista *siguiente;
}Elemento;
 
typedef struct ListaIdentificar{
    Elemento *inicio;
    Elemento *fin;
    Elemento *actual;
    int tamano;
}Lista;

void incializacion(Lista *lista);
/*inicializa la lista*/

int InsercionEnListaVacia(Lista *lista, CartaCurso *carta); 
/*insertar en inicio de la lista vacia*/

int InsercionFinLista(Lista *lista, CartaCurso *carta); 
/*insertar en fin de la lista*/

Elemento* obtenerInicio(Lista *lista);
/*obtiene el primer elemento*/

void destruir(Lista * lista);
/*libera la memoria heap*/

#endif