#include <stdio.h>
#include <stdlib.h>
#include "../lib/Matriz.h"
#include <iostream>
using namespace std;

/*--------------------------------
Vamos definir as variaveis importantes
na recursao para montagem na PD
São elas: O degrau atual e o numero de degraus restantes.
Portanto a matriz de memorizacao conterah como primeiro
indice o degrau_atual e como segundo degraus_restantes
--------------------------------*/
int **MEMO;
int N;

int main(int argc, char *argv[]){
    printf("Digite o numero de degraus: ");
    scanf("%d",&N);
    MEMO = aloca_m_quad(N);
    printa_matriz(MEMO, N);
    libera_m_quad(MEMO, N);
    return 0;
}


