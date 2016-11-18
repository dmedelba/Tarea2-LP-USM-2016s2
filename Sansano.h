#ifndef _SANSANO_H_INCLUDED_
#define _SANSANO_H_INCLUDED_

typedef struct{
    char * nombre;
    int prioridad;
    void * mazo;
}Sansano;


void crearUsuario(Sansano *player, char *nombre, void *deck);
void usarAprobar(void *carta, void *jugador);
void usarReprobar(void *carta, void *enemigo);
int elegirOpcion();

#endif