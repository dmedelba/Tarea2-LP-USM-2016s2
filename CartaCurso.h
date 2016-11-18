#ifndef _CARTACURSO_H_INCLUDED_
#define _CARTACURSO_H_INCLUDED_

typedef struct {
	char * nombre, * descripcion;
	int ataque, defensa;
	void (*reprobar)(void *,void *);//Los parametros son la carta y el enemigo
	void(*aprobar)(void *,void *);//Los parametros son la carta y el jugador
}CartaCurso;


void crearMazo(void *lista,int alfa); 
void crearCarta(int numero, CartaCurso *carta);


#endif