#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sansano.h"
#include "CartaCurso.h"
#include "lista.h"
#include <time.h>


/******** Funcion:crearUsuario********************
Descripcion: Crea un usuario sansano / jugador o computadora.
Parametros:Sansano *player, char *nombre, void * deck // (el tipo de 
usuario que se quiere crear, con el nombre de este y un void el cual 
apunta al mazo de el jugador.)
Retorno: nada
************************************************/
void crearUsuario(Sansano *player, char *nombre, void * deck){
	player->nombre = nombre;
	player->prioridad = 3000;
	player->mazo = deck;
}

/******** Funcion: usarAprobar********************
Descripcion:Funcion que se encarga de utilizar los puntos de defensa
de la carta y curar la vida del usuario que la invoca.
Parametros:void *carta, void *jugador// (carta con sus caract, y el
usuario a curar.)
Retorno:nada
************************************************/
void usarAprobar(void *carta, void *jugador){
	Sansano * jugadorAUX = (Sansano *) jugador;
	CartaCurso * cartaAUX = (CartaCurso *) carta;
	(jugadorAUX->prioridad)+=(cartaAUX->defensa);
	if (jugadorAUX->prioridad > 3000){
		jugadorAUX->prioridad=3000;
	}
}

/******** Funcion: usarReprobar ********************
Descripcion:Funcion que se encarga de utilizar los puntos de ataque 
de la carta en cuestion y restar ese valor a la vida del oponente.
Parametros:void *carta, void *enemigo // (Carta para sus caract, y el
enmigo a que se le aplicara el ataque)
Retorno: nada
************************************************/
void usarReprobar(void *carta, void *enemigo){
	Sansano * enemigoAUX = (Sansano *) enemigo;
	CartaCurso * cartaAUX = (CartaCurso *) carta;
	(enemigoAUX->prioridad)-=(cartaAUX->ataque);
	if (enemigoAUX->prioridad < 0){
		enemigoAUX->prioridad=0;
	}
}

/******** Funcion: elegirOpcion ********************
Descripcion:Genera un numero aleatorio entre 0 y 1 , para la decision de 
la computadora 0= atacar , 1= defender.
Parametros: nada
Retorno: numero aleatorio.
************************************************/
int elegirOpcion(){
	int opcion;
	opcion=rand() % 2;
	return opcion;

}
