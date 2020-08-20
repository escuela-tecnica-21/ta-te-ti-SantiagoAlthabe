#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

void jugar_contra_humano() {
    int puntos_x = 0;
    int puntos_O = 0;
    int vector_tateti[9];
    while(puntos_x != 3 && puntos_O != 3){
        int tateti = 1; //condicion de corte
        int jugador_actual = 0;
        int error_al_elegir_casillero; //0 -> esta todo bien, 3 -> hubo error
        int lugar_elegido;
        inicializar_vector(vector_tateti);
        int chequeo;
        while(tateti == 1) {
            error_al_elegir_casillero = 0;
            if(jugador_actual == 0) {
                textcolor(15);
                printf("Turno de jugador X:\n");
                printf("\n");
            }
            else{
                textcolor(15);
                printf("Turno de jugador O:\n");
                printf("\n");
            }
            textcolor(15);
            printf("Ingrese la fila en la que desea insertar la ficha o -1 para salir:\n");
            scanf("%d", &lugar_elegido);
            if(lugar_elegido == -1) {
                printf("\n");
                textcolor(11);
                printf("EL JUEGO SE FINALIZO\n");
                printf("\n");
                printf(" HECHO POR: SANTIAGO ALTHABE\n");
                return;
            }
            //
            printf("\n");
            //Pongo la ficha del jugador en el tablero, 1 -> jugador1, 0 -> jugador0
            if(vector_tateti[lugar_elegido] != 1 && vector_tateti[lugar_elegido]!= 0) {
                if(jugador_actual == 0) {
                    vector_tateti[lugar_elegido] = 0;
                }
                else{
                    vector_tateti[lugar_elegido] = 1;
                }
            }
            else{
                error_al_elegir_casillero = 3;
            }
            imprimir_vector(vector_tateti);
            chequeo = hay_ganador(vector_tateti);
            if(chequeo == 0) {
                textcolor(15);
                printf("GANO LA RONDA EL JUGADOR X\n");
                tateti = 0; //actualizo condicion de corte
                puntos_x ++; //se le suma un punto al jugador
            }
            if(chequeo == 1) {
                textcolor(15);
                printf("GANO LA RONDA EL JUGADOR O\n");
                tateti = 0;
                puntos_O ++;
            }
            if(chequeo == -1) {
                textcolor(15);
                printf("LA RONDA TERMINO EN EMPATE\n");
                tateti = 0;
            }

            //Cambia el turno a el otro jugador
            if(error_al_elegir_casillero == 0){
                if(jugador_actual == 0) {
                    jugador_actual = 1;
                }
                else{
                    jugador_actual = 0;
                }
            }
            else{
                textcolor(15);
                printf("ERROR CASILLERO OCUPADO\n");
                printf("\n");
            }
            printf("\n");
            textcolor(15);
            printf("PUNTAJES:\n");
            textcolor(11);
            printf("JUGADOR X: %d\n", puntos_x);
            textcolor(12);
            printf("JUGADOR O: %d\n", puntos_O);
            printf("\n");
        }
    }
    printf("\n");
    if(puntos_x == 5) {
        textcolor(15);
        printf("GANO EL JUEGO EL JUGADOR X\n");
    }
    else{
        textcolor(15);
        printf("GANO EL JUEGO EL JUGADOR O\n");
    }
    printf("\n");
    textcolor(15);
    printf("\n");
    printf(" HECHO POR: SANTIAGO ALTHABE\n");
    printf("FIN DEL JUEGO\n");
}

void colocar_ficha_maquina(int vector_tateti[3][3]) {
    //SE FIJA SI GANA
    //Gana en la primera fila
    if(vector_tateti[0] == 1 && vector_tateti[2] == 1 && vector_tateti[2] != 0 && vector_tateti[2] != 1) {
        matriz_tateti[2] = 1;
    }
    else if(vector_tateti[0] == 1 && vector_tateti[1] != 0 && vector_tateti[1] != 1 && vector_tateti[2] == 1) {
        vector_tateti[1] = 1;
    }
    else if(vector_tateti[0] != 1 && vector_tateti[0] != 0 && vector_tateti[1] == 1 && vector_tateti[2] == 1) {
        vector_tateti[0] = 1;
    }
    //Gana en la segunda fila
    else if(vector_tateti[1] == 1 && vector_tateti[4] == 1 && vector_tateti[5] != 0 && vector_tateti[5] != 1) {
        vector_tateti[5] = 1;
    }
    else if(vector_tateti[3] == 1 && vector_tateti[4] != 0 && vector_tateti[4] != 1 && vector_tateti[5] == 1) {
        vector_tateti[4] = 1;
    }
    else if(vector_tateti[3] != 1 && vector_tateti[3] != 0 && vector_tateti[4] == 1 && vector_tateti[5] == 1) {
        vector_tateti[3] = 1;
    }
    //Gana en la tercera fila
    else if(vector_tateti[6] == 1 && vector_tateti[7] == 1 && vector_tateti[8] != 0 && vector_tateti[8] != 1) {
        vector_tateti[8] = 1;
    }
    else if(vector_tateti[6] == 1 && vector_tateti[7] != 0 && vector_tateti[7] != 1 && vector_tateti[8] == 1) {
        vector_tateti[7] = 1;
    }
    else if(vector_tateti[6] != 1 && vector_tateti[6] != 0 && vector_tateti[7] == 1 && vector_tateti[8] == 1) {
        vector_tateti[6] = 1;
    }
    //Gana en la primera columna
    else if(vector_tateti[0] == 1 && vector_tateti[3] == 1 && vector_tateti[6] != 0 && vector_tateti[6] != 1) {
        vector_tateti[6] = 1;
    }
    else if(vector_tateti[0] == 1 && vector_tateti[3] != 0 && vector_tateti[3] != 1 && vector_tateti[6] == 1) {
        vector_tateti[3] = 1;
    }
    else if(vector_tateti[0] != 1 && vector_tateti[0] != 0 && vector_tateti[3] == 1 && vector_tateti[6] == 1) {
        vector_tateti[0] = 1;
    }
    //Gana en la segunda columna
    else if(vector_tateti[1] == 1 && vector_tateti[4] == 1 && vector_tateti[7] != 0 && vector_tateti[7] != 1) {
        vector_tateti[7] = 1;
    }
    else if(vector_tateti[1] == 1 && vector_tateti[4] != 0 && vector_tateti[4] != 1 && vector_tateti[7] == 1) {
        vector_tateti[4] = 1;
    }
    else if(vector_tateti[1] != 1 && vector_tateti[1] != 0 && vector_tateti[4] == 1 && vector_tateti[7] == 1) {
        vector_tateti[1] = 1;
    }
    //Gana en la tercera columna
    else if(vector_tateti[2] == 1 && vector_tateti[5] == 1 && vector_tateti[8] != 0 && vector_tateti[8] != 1) {
        vector_tateti[8] = 1;
    }
    else if(vector_tateti[2] == 1 && vector_tateti[5] != 0 && vector_tateti[5] != 1 && vector_tateti[8] == 1) {
        vector_tateti[5] = 1;
    }
    else if(vector_tateti[2] != 1 && vector_tateti[2] != 0 && vector_tateti[5] == 1 && vector_tateti[8] == 1) {
        vector_tateti[2] = 1;
    }
    //Gana en la diagonal izquierda inferior derecha superior
    else if(vector_tateti[6] == 1 && vector_tateti[4] == 1 && vector_tateti[2] != 0 && vector_tateti[2] != 1) {
        vector_tateti[2] = 1;
    }
    else if(vector_tateti[6] == 1 && vector_tateti[4] != 0 && vector_tateti[4] != 1 && vector_tateti[2] == 1) {
        vector_tateti[4] = 1;
    }
    else if(vector_tateti[6] != 0 && vector_tateti[6] != 1 && vector_tateti[4] == 1 && vector_tateti[2] == 1) {
        vector_tateti[6] = 1;
    }
    //Gana en la diagonal izquierda superior derecha inferior
    else if(vector_tateti[0] == 1 && vector_tateti[4] == 1 && vector_tateti[8] != 0 && vector_tateti[8] != 1) {
        vector_tateti[8] = 1;
    }
    else if(vector_tateti[0] == 1 && vector_tateti[4] != 0 && vector_tateti[4] != 1 && vector_tateti[8] == 1) {
        vector_tateti[4] = 1;
    }
    else if(vector_tateti[0] != 0 && vector_tateti[0] != 1 && vector_tateti[4] == 1 && vector_tateti[8] == 1) {
        vector_tateti[0] = 1;
    }
    //SE FIJA SI PIERDE
    else if(vector_tateti[0] == 0 && vector_tateti[1] == 0 && vector_tateti[2] != 1 && vector_tateti[2] != 0) {
        vector_tateti[2] = 1;
     }
     else if(vector_tateti[0] == 0 && vector_tateti[1] != 1 && vector_tateti[1] != 0 && vector_tateti[2] == 0) {
        vector_tateti[1] = 1;
     }
     else if(matriz_tateti[0] != 1 && matriz_tateti[0] != 0 && matriz_tateti[1] == 0 && matriz_tateti[2] == 0) {
        matriz_tateti[0] = 1;
     }
     //Gana en la segunda fila
     else if(vector_tateti[3] == 0 && vector_tateti[4] == 0 && vector_tateti[5] != 1 && vector_tateti[5] != 0) {
        vector_tateti[5] = 1;
     }
     else if(vector_tateti[3] == 0 && vector_tateti[4] != 1 && vector_tateti[4] != 0 && vector_tateti[5] == 0) {
        vector_tateti[4] = 1;
     }
     else if(vector_tateti[3] != 1 && vector_tateti[3] != 0 && vector_tateti[4] == 0 && vector_tateti[5] == 0) {
        vector_tateti[3] = 1;
     }
     //Gana en la tercera fila
     else if(vector_tateti[6] == 0 && vector_tateti[7] == 0 && vector_tateti[8] != 1 && vector_tateti[8] != 0) {
        vector_tateti[8] = 1;
     }
    else if(vector_tateti[6] == 0 && vector_tateti[7] != 1 && vector_tateti[7] != 0 && vector_tateti[8] == 0) {
        vector_tateti[7] = 1;
    }
    else if(vector_tateti[6] != 1 && vector_tateti[6] != 0 && vector_tateti[7] == 0 && vector_tateti[8] == 0) {
        vector_tateti[6] = 1;
    }
    //Gana en la primera columna
    else if(vector_tateti[0] == 0 && vector_tateti[3] == 0 && vector_tateti[6] != 1 && vector_tateti[6] != 0) {
        vector_tateti[6] = 1;
    }
    else if(vector_tateti[0] == 0 && vector_tateti[3] != 1 && vector_tateti[3] != 0 && vector_tateti[6] == 0) {
        vector_tateti[3] = 1;
    }
    else if(vector_tateti[0] != 1 && vector_tateti[0] != 0 && vector_tateti[3] == 0 && vector_tateti[6] == 0) {
        vector_tateti[0] = 1;
    }
    //Gana en la segunda columna
    else if(vector_tateti[1] == 0 && vector_tateti[4] == 0 && vector_tateti[7] != 1 && vector_tateti[7] != 0) {
        vector_tateti[7] = 1;
    }
    else if(vector_tateti[1] == 0 && vector_tateti[4] != 1 && vector_tateti[4] != 0 && vector_tateti[7] == 0) {
        vector_tateti[4] = 1;
    }
    else if(vector_tateti[1] != 1 && vector_tateti[1] != 0 && vector_tateti[4] == 0 && vector_tateti[7] == 0) {
        vector_tateti[1] = 1;
    }
    //Gana en la tercera columna
    else if(vector_tateti[2] == 0 && vector_tateti[5] == 0 && vector_tateti[8] != 1 && vector_tateti[8] != 0) {
        vector_tateti[8] = 1;
    }
    else if(vector_tateti[2] == 0 && vector_tateti[5] != 1 && vector_tateti[5] != 0 && vector_tateti[8] == 0) {
        vector_tateti[5] = 1;
    }
    else if(vector_tateti[2] != 1 && vector_tateti[2] != 0 && vector_tateti[5] == 0 && vector_tateti[8] == 0) {
        vector_tateti[2] = 1;
    }
    //Gana en la diagonal izquierda inferior derecha superior
    else if(vector_tateti[6] == 0 && vector_tateti[4] == 0 && vector_tateti[2] != 1 && vector_tateti[2] != 0) {
        vector_tateti[2] = 1;
    }
    else if(vector_tateti[6] == 0 && vector_tateti[4] != 1 && vector_tateti[4] != 0 && vector_tateti[2] == 0) {
        vector_tateti[4] = 1;
    }
    else if(vector_tateti[6] != 1 && vector_tateti[6] != 0 && vector_tateti[4] == 0 && vector_tateti[2] == 0) {
        vector_tateti[6] = 1;
    }
    //Gana en la diagonal izquierda superior derecha inferior
    else if(vector_tateti[0] == 0 && vector_tateti[4] == 0 && vector_tateti[8] != 1 && vector_tateti[8] != 0) {
        vector_tateti[8] = 1;
    }
    else if(vector_tateti[0] == 0 && vector_tateti[4] != 1 && vector_tateti[4] != 0 && vector_tateti[8] == 0) {
        vector_tateti[4] = 1;
    }
    else if(vector_tateti[0] != 1 && vector_tateti[0] != 0 && vector_tateti[4] == 0 && vector_tateti[8] == 0) {
        vector_tateti[0] = 1;
    }
    //TRATA DE COLACAR LA FIJA DONDE PUEDA
    else if(vector_tateti[0] != 1 && vector_tateti[0] != 0){
        vector_tateti[0][0] = 1;
    }
    else if(vector_tateti[1] != 1 && vector_tateti[1] != 0){
        vector_tateti[1] = 1;
    }
    else if(vector_tateti[2] != 1 && vector_tateti[2] != 0){
        vector_tateti[2] = 1;
    }
    else if(vector_tateti[3] != 1 && vector_tateti[3] != 0){
        vector_tateti[3] = 1;
    }
    else if(vector_tateti[4] != 1 && vector_tateti[4] != 0){
        vector_tateti[4] = 1;
    }
    else if(vector_tateti[5] != 1 && vector_tateti[5] != 0){
        vector_tateti[5] = 1;
    }
    else if(vector_tateti[6] != 1 && vector_tateti[6] != 0){
        vector_tateti[6] = 1;
    }
    else if(vector_tateti[7] != 1 && vector_tateti[7] != 0){
        vector_tateti[7] = 1;
    }
    else if(vector_tateti[8] != 1 && vector_tateti[8] != 0){
        vector_tateti[8] = 1;
    }
}

void jugar_contra_maquina() {
    int puntos_x = 0;
    int puntos_O = 0;
    int matriz_tateti[3][3];
    while(puntos_x != 3 && puntos_O != 3){
        int tateti = 1; //condicion de corte
        int jugador_actual = 0;
        int error_al_elegir_casillero; //0 -> esta todo bien, 3 -> hubo error
        int lugar_elegido;
        inicializar_vector(vector_tateti);
        int chequeo;
        while(tateti == 1) {
            error_al_elegir_casillero = 0;
            if(jugador_actual == 0) {
                textcolor(15);
                printf("Turno de jugador X:\n");
                printf("\n");
                textcolor(15);
                printf("Ingrese la fila en la que desea insertar la ficha o -1 para salir:\n");
                scanf("%d", &lugar_elegido);
                if(lugar_elegido == -1) {
                    printf("\n");
                    textcolor(11);
                    printf("EL JUEGO SE FINALIZO\n");
                    printf("\n");
                    printf(" HECHO POR: SANTIAGO ALTHABE\n");
                    return;
                }

                printf("\n");
                //Pongo la ficha del jugador en el tablero, 1 -> jugador1, 0 -> jugador0
                if(vector_tateti[lugar_elegido] != 1 && vector_tateti[lugar_elegido] != 0) {
                    if(jugador_actual == 0) {
                        vector_tateti[lugar_elegido] = 0;
                    }
                    else{
                        vector_tateti[lugar_elegido] = 1;
                    }
                }
                else{
                    error_al_elegir_casillero = 3;
                }
            }

            //TURNO MAQUINA
            else{
                textcolor(15);
                printf("Turno de maquina O:\n");
                printf("\n");
                colocar_ficha_maquina(vector_tateti);
            }

            imprimir_vector(vector_tateti);
            chequeo = hay_ganador(vector_tateti);
            if(chequeo == 0) {
                textcolor(15);
                printf("GANO LA RONDA EL JUGADOR X\n");
                tateti = 0; //actualizo condicion de corte
                puntos_x ++; //se le suma un punto al jugador
            }
            if(chequeo == 1) {
                textcolor(15);
                printf("GANO LA RONDA EL JUGADOR O\n");
                tateti = 0;
                puntos_O ++;
            }
            if(chequeo == -1) {
                textcolor(15);
                printf("LA RONDA TERMINO EN EMPATE\n");
                tateti = 0;
            }

            //Cambia el turno a el otro jugador
            if(error_al_elegir_casillero == 0){
                if(jugador_actual == 0) {
                    jugador_actual = 1;
                }
                else{
                    jugador_actual = 0;
                }
            }
            else{
                textcolor(15);
                printf("ERROR CASILLERO OCUPADO\n");
                printf("\n");
            }
            printf("\n");
            textcolor(15);
            printf("PUNTAJES:\n");
            textcolor(11);
            printf("JUGADOR X: %d\n", puntos_x);
            textcolor(12);
            printf("MAQUINA O: %d\n", puntos_O);
            printf("\n");
        }
    }
    printf("\n");
    if(puntos_x == 5) {
        textcolor(15);
        printf("GANO EL JUEGO EL JUGADOR X\n");
    }
    else{
        textcolor(15);
        printf("GANO EL JUEGO LA MAQUINA O\n");
    }
    // Nombre:::
    printf("\n");
    textcolor(15);
    printf("\n");
    printf(" HECHO POR: SANTIAGO ALTHABE\n");
    printf("FIN DEL JUEGO\n");

}

//0 si gano el jugar 0, 1 si gano el jugador 1, 9 si no gano nadie, -1 si el juego se trabo
int hay_ganador(int matriz[3][3]) {
	//horizontales
	int linea0 = vector[0] + vector[1] + vector[2];
	int linea1 = vector[3] + vector[4] + vector[5];
	int linea2 = vector[6] + vector[7] + vector[8];
	//verticales
	int linea3 = vector[0] + vector[3] + vector[6];
	int linea4 = vector[1] + vector[4] + vector[7];
	int linea5 = vector[2] + vector[5] + vector[8];
	//Diagonales
	int linea6 = vector[0] + vector[4] + vector[8];
	int linea7 = vector[6] + vector[4] + vector[2];

	if(linea0 == 0 || linea1 == 0 || linea2 == 0 || linea3 == 0 || linea4 == 0 || linea5 == 0 || linea6 == 0 || linea7 == 0){
		return 0;
	}
	if(linea0 == 3 || linea1 == 3 || linea2 == 3 || linea3 == 3 || linea4 == 3 || linea5 == 3 || linea6 == 3 || linea7 == 3){
		return 1;
	}
	int suma_vector = 0;
	for(int i = 0; i < 3; i ++) {
		for(int j = 0; j < 3; j ++) {
			suma_vector += vector[i];
		}
	}
	if(suma_vector == 4) {
		return -1;
	}
	return 9;
}

void inicializar_vector(int vector[9]) {
	int valor = 7;
	for(int j = 0; j < 3; j ++) {
		for(int i = 0; i < 3; i ++) {
			vector[i] = valor;
			valor ++;
		}
	}
}
//
void imprimir_vector(int vector[9]) {
    textcolor(15);
	printf("-------------\n");
	for(int i = 0; i < 3; i ++) {
		if(vector[0][i] == 0){
            textcolor(15);
		    printf("|");
            textcolor(11);
			printf(" x ");
		}
		else if(vector[0][i] == 1){
		    textcolor(15);
            printf("|");
		    textcolor(12);
			printf(" o ");
		}
		else{
		    textcolor(15);
            printf("|");
		    textcolor(14);
			printf(" - ");
		}
	}
	textcolor(15);
	printf("|\n");
	for(int i = 0; i < 3; i ++) {
		if(vector[1][i] == 0){
			textcolor(15);
		    printf("|");
            textcolor(11);
			printf(" x ");
		}
		else if(vector[1][i] == 1){
			textcolor(15);
            printf("|");
		    textcolor(12);
			printf(" o ");
		}
		else{
			textcolor(15);
            printf("|");
		    textcolor(14);
			printf(" - ");
		}
	}
	textcolor(15);
	printf("|\n");
	for(int i = 0; i < 3; i ++) {
		if(vector[2][i] == 0){
			textcolor(15);
		    printf("|");
            textcolor(11);
			printf(" x ");
		}
		else if(vector[2][i] == 1){
			textcolor(15);
            printf("|");
		    textcolor(12);
			printf(" o ");
		}
		else{
			textcolor(15);
            printf("|");
		    textcolor(14);
			printf(" - ");
		}
	}
	textcolor(15);
	printf("|\n");
	textcolor(15);
	printf("-------------\n");
	}

//0 -> x, 1 -> o
int main(){
    int opcion;
    textcolor(15);
    printf("Desea jugar contra una persona o la maquina?\n");
    printf("\n");
    printf("0 -> persona\n");
    printf("\n");
    printf("1 -> maquina\n");
    printf("\n");
    scanf("%d", &opcion);
    printf("\n");
    printf("\n");
    if(opcion == 0){
        jugar_contra_humano();
    }
    else{
        jugar_contra_maquina();
    }


	return 0;
}

