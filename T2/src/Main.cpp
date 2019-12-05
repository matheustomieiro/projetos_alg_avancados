#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h> 
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
int INF = __INT_MAX__;
int N, NR;
int *VARG;

int degraus(int degrau_atual, int degraus_restantes){
    if(degraus_restantes < 0) return 0;
    if(degraus_restantes == 0) return 1;
    if(MEMO[degrau_atual][degraus_restantes] != 0) return MEMO[degrau_atual][degraus_restantes];
    for(int i=0; i<NR; i++){
        MEMO[degrau_atual][degraus_restantes] += degraus(degrau_atual+VARG[i], degraus_restantes-VARG[i]);
    }

    return MEMO[degrau_atual][degraus_restantes];
}


int main(int argc, char *argv[]){
    printf("Digite o numero de degraus: ");
    scanf("%d",&N);
    N = N + 1;
    printf("Digite o numero de restricoes: ");
    scanf("%d",&NR);
    VARG = (int*)malloc(NR*sizeof(int));
    printf("Digite a lista de restricoes, seperando itens por espaços\n");
    for(int i=0; i<NR; i++){
        scanf("%d",&VARG[i]);
    }
    MEMO = aloca_m_quad(N);
    //AQUI
    printa_matriz(MEMO,N);
    printf("Numero de possibilidades: %d\n", degraus(0,N-1));
    printa_matriz(MEMO,N);
    //AQUI
    libera_m_quad(MEMO, N);
    free(VARG);
    return 0;
}


