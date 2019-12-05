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
int N, NR, Max = -INF, aux, Count = 0;
int *VARG;

int degraus(int degrau_atual, int degraus_restantes){
    if(degraus_restantes<0) return -INF;
    if(degrau_atual == N) return 1;
    if(MEMO[degrau_atual][degraus_restantes] != -1){
        Count++;
        return MEMO[degrau_atual][degraus_restantes];
    }
    for(int i=0; i<NR; i++){
        aux = degraus(degrau_atual+VARG[i], degraus_restantes-VARG[i]);
        if(aux > Max){
            Count++;
            Max = aux;
        }
    }
    Count++;
    MEMO[degrau_atual][degraus_restantes] = Max;
    if(degrau_atual == 0){
        return Count;
    }
    return MEMO[degrau_atual][degraus_restantes];
}


int main(int argc, char *argv[]){
    printf("Digite o numero de degraus: ");
    scanf("%d",&N);
    printf("Digite o numero de restricoes: ");
    scanf("%d",&NR);
    VARG = (int*)malloc(NR*sizeof(int));
    printf("Digite a lista de restricoes, seperando itens por espaços\n");
    for(int i=0; i<NR; i++){
        scanf("%d",&VARG[i]);
    }
    MEMO = aloca_m_quad(N);
    printf("Numero de possibilidades: %d\n",degraus(0,N-1)-1);
    libera_m_quad(MEMO, N);
    free(VARG);
    return 0;
}


