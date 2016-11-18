#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sansano.h"
#include "CartaCurso.h"
#include "lista.h"
#include <time.h>

/******** Funcion: crearCarta ********************
Descripcion: Crea la carta segun numero entregado, hay 6 tipos de cartas.
creando en base a la struc CartaCurso, se rellena su iformacion.
Parametros: int numero, Carta *Curso// (numero entre el 0 y 5 de los cuales 
cada uno corresponde a una carta, y la carta que se creara.)
Retorno: nada
************************************************/
void crearCarta(int numero, CartaCurso *carta){
	if (numero==0){
		carta->nombre="Matematicas";
		carta->descripcion="Ataque: 550 puntos de prioridad.\n    Defensa: Cura 200 puntos de prioridad.";
		carta->ataque= 550;
		carta->defensa= 200;
	}
	else if (numero==1){
		carta->nombre="Fisica";
		carta->descripcion="Ataque: 450 puntos de prioridad.\n    Defensa: Cura 150 puntos de prioridad.";
		carta->ataque= 450;
		carta->defensa= 150;

	}
	else if (numero==2){
		carta->nombre="Lenguajes de Programacion";
		carta->descripcion="Ataque: 510 puntos de prioridad.\n    Defensa: Cura 180 puntos de prioridad.";
		carta->ataque= 510;
		carta->defensa= 180;

	}
	else if (numero==3){
		carta->nombre="Programacion";
		carta->descripcion="Ataque: 110 puntos de prioridad.\n    Defensa: Cura 300 puntos de prioridad.";
		carta->ataque= 110;
		carta->defensa= 300;

	}
	else if (numero==4){
		carta->nombre="Estructuras Discretas";
		carta->descripcion="Ataque: 470 puntos de prioridad.\n    Defensa: Cura 160 puntos de prioridad.";
		carta->ataque= 470;
		carta->defensa= 160;

	}
	else if (numero==5){
		carta->nombre="Estructuras de Datos";
		carta->descripcion="Ataque: 430 puntos de prioridad.\n    Defensa: Cura 120 puntos de prioridad.";
		carta->ataque=430;
		carta->defensa= 120;

	}

}
/******** Funcion: crearMazo ********************
Descripcion: crea el mazo del usuario y de la computadora en esta tarea, haciendo
que el orden de este sea aleatorio.
Parametros: void *lista , int alfa // (puede recibir cualquier estructura donde almacenar un mazo,
por eso el void,pero en este caso de la tarea, se utiliza una lista; el int alfa es para
crear un random diferente para que los dos mazos no sean iguales.)
Retorno: nada
************************************************/
void crearMazo(void *lista,int alfa){
	srand(time(NULL)); 
	int numero; 
	int pro=0,mat=0,lp=0,ed=0,edd=0,fis=0;
	int i;
	for (i = 0; i < 20; i++){
		CartaCurso *carton;
		numero=rand() % 6;
		numero=numero+alfa;
		if (numero>6){
			numero=rand() % 6;
		}
		if (numero==0 && mat<1){
			mat++;
			carton = (CartaCurso *) malloc (sizeof(CartaCurso));
			crearCarta(numero, carton);
			if (i==0){
				InsercionEnListaVacia(lista,carton);
			}
			else{
				InsercionFinLista(lista,carton);
			}
		}
		else if(numero==1 && fis<4){
			fis++;
			carton = (CartaCurso *) malloc (sizeof(CartaCurso));
			crearCarta(numero, carton);
			if (i==0){
				InsercionEnListaVacia(lista,carton);
			}
			else{
				InsercionFinLista(lista,carton);
			}
		}
		else if(numero==2 && lp<2){
			lp++;
			carton = (CartaCurso *) malloc (sizeof(CartaCurso));
			crearCarta(numero, carton);
			if (i==0){
				InsercionEnListaVacia(lista,carton);
			}
			else{
				InsercionFinLista(lista,carton);
			}
		}
		else if(numero==3 && pro<6){
			pro++;
			carton = (CartaCurso *) malloc (sizeof(CartaCurso));
			crearCarta(numero, carton);
			if (i==0){
				InsercionEnListaVacia(lista,carton);
			}
			else{
				InsercionFinLista(lista,carton);
			}
		}
		else if(numero==4 && ed<3){
			ed++;
			carton = (CartaCurso *) malloc (sizeof(CartaCurso));
			crearCarta(numero, carton);
			if (i==0){
				InsercionEnListaVacia(lista,carton);
			}
			else{
				InsercionFinLista(lista,carton);
			}
		}
		else if (numero==5 && edd<4){
			edd++;
			carton = (CartaCurso *) malloc (sizeof(CartaCurso));
			crearCarta(numero, carton);
			if (i==0){
				InsercionEnListaVacia(lista,carton);
			}
			else{
				InsercionFinLista(lista,carton);
			}
		}
		else{
			i=i-1;
		}

	}
}
