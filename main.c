#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sansano.h"
#include "CartaCurso.h"
#include "lista.h"
#include <time.h>

int main(){
	char *nom, *pc="computador";
	nom = (char *) malloc (50);
	printf ("Bienvenidos a SansaStone\n");
	printf("Ingresa tu nombre (solo el nombre de pila):");
	scanf("%s",nom);
	printf("Bienvenido %s, que comience el desafio.\n", nom);
	//inicio mazo player
	Lista *lista;
	lista = (Lista *) malloc (sizeof (Lista));
	incializacion(lista);
	//inicio mazo del rival
	Lista *rival;
	rival = (Lista *) malloc (sizeof (Lista));
	incializacion(rival);
	//creo los mazos
	crearMazo(lista,0);
	crearMazo(rival,2);
	//creamos los usuarios

	//player
	Sansano *player;
	player = (Sansano *) malloc (sizeof(Sansano));
	crearUsuario(player,nom,lista);
	//pc
	Sansano *computador;
	computador = (Sansano *) malloc (sizeof(Sansano));
	crearUsuario(computador,pc,rival);

	//punteros a funcion
	typedef void (*puntero_a_funcion)(void * ,void *);
		puntero_a_funcion puntero_aprobar = usarAprobar;
		puntero_a_funcion puntero_reprobar = usarReprobar;



	//comienza el game
	printf("|-----------------Menu SansaStone-----------------|\n\n");
	int eleccion, elecPC;
	//char espacio;
	while(rival->tamano != 0){
		Elemento *cartarival;
		Elemento *cartaenjuego;
		cartaenjuego = obtenerInicio(lista);
		printf("|-----Estadisticas-----|\n");
		printf("|Tu vida actual:[%d] |\n",player->prioridad);
		printf("|Vida PC:[%d]        |\n",computador->prioridad);
		printf("|----------------------|\n\n");
		printf("|-------------------------------------------------|\n");
		printf(" Haz obtenido la carta:[%s]\n",cartaenjuego->carta->nombre);
		printf("    %s\n",cartaenjuego->carta->descripcion);
		printf("|-------------------------------------------------|\n");
		printf("Selecciona una opcion:\n");
		printf("	0.-Ataque.\n");
		printf("	1.-Defensa.\n");
		printf("     NO ingrese letras.\n");
		printf("Ingresa tu eleccion: ");
		scanf("%d",&eleccion);
		system("clear");
		int flag=1;
		while (flag){
			if(eleccion==0){
				(* puntero_reprobar)(cartaenjuego->carta,computador);
				flag=0;
				printf(" Tu carta causo %d de daño. Vida PC=[%d]\n\n",cartaenjuego->carta->ataque, computador->prioridad);
			}
			else if (eleccion==1){
				(* puntero_aprobar)(cartaenjuego->carta, player);
				flag=0;
				printf("Tu carta curo %d de vida. Vida actual=[%d]\n\n",cartaenjuego->carta->defensa, player->prioridad);
			}
			else{
				printf("Debe ingresar un numero valido (0 o 1).\n");
				printf("Intente nuevamente.\n");
				printf("Ingresa tu eleccion: ");
				scanf("%d",&eleccion);
			}
		}
		free(cartaenjuego->carta);
		free(cartaenjuego);
		if(computador->prioridad==0 || player->prioridad==0){
			printf("Vidas finales: \n");
			printf("Computador: %d\n", computador->prioridad);
			printf("Tu vida: %d\n", player->prioridad);
			if (player->prioridad==0){
				printf("|--------------------------------------|\n");
				printf("| GameOver: Ha ganado la computadora.  |\n");
				printf("|--------------------------------------|\n");
			}
			else{
				printf("|-------------------------------------|\n");
				printf("| ENHORABUENA!!! | CONGRATULATIONS!!! |\n");
				printf("|             Has Ganado              |\n");
				printf("|-------------------------------------|\n");
			}
			break;
		}
		cartarival=obtenerInicio(rival);
		elecPC= elegirOpcion();
		if(elecPC==0){
			(* puntero_reprobar)(cartarival->carta,player);
			printf("|---------------------Informacion computadora---------------------|\n");
			printf("  A la computadora le ha salido la carta [%s].\n",cartarival->carta->nombre);
			printf("  La computadora ha decidido atacar dejando tu prioridad en: %d\n", player->prioridad);
			printf("|-----------------------------------------------------------------|\n\n");
			}
		else if (elecPC==1){
			(* puntero_aprobar)(cartarival->carta, computador);
			printf("|---------------------Informacion computadora---------------------|\n");
			printf("  A la computadora le ha salido la carta [%s].\n",cartarival->carta->nombre);
			printf("  La computadora ha decidido curarse, su actual vida es : %d\n", computador->prioridad);
			printf("|-----------------------------------------------------------------|\n\n");
		}
		if(computador->prioridad==0 || player->prioridad==0){
			printf("Vidas finales: \n");
			printf("Computador: %d\n", computador->prioridad);
			printf("Tu vida: %d\n", player->prioridad);
			if (player->prioridad==0){
				printf("GameOver: Ha ganado la computadora\n");
			}
			else{
				printf("|-------------------------------------|\n");
				printf("| ENHORABUENA!!! | CONGRATULATIONS!!! |\n");
				printf("|             Has Ganado              |\n");
				printf("|-------------------------------------|\n");
			}
			break;
		}
		free(cartarival->carta);
		free(cartarival);
	}
	if ((player->prioridad)>0 && (computador->prioridad)>0){
		printf("Se han acabado las cartas, las vidas finales son:\n");
		printf("Computador: %d\n", computador->prioridad);
		printf("Tu vida: %d\n", player->prioridad);
		if((player->prioridad)>(computador->prioridad)){
			printf("|-------------------------------------|\n");
			printf("| ENHORABUENA!!! | CONGRATULATIONS!!! |\n");
			printf("|             Has Ganado              |\n");
			printf("|-------------------------------------|\n");
		}
		else if((player->prioridad)==(computador->prioridad)){
			printf("|-----------|\n");
			printf("| EMPATE!!!!|\n");
			printf("|-----------|\n");

		}
		else{
			printf("|--------------------------------------|\n");
			printf("| GameOver: Ha ganado la computadora.  |\n");
			printf("|--------------------------------------|\n");
		}
	}
	free(player);
	free(computador);
	free(nom);
	destruir(lista);
	destruir(rival);
	free(lista);
	free(rival);
    return 0;
}
