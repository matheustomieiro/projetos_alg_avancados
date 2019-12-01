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
int N, Count = 0;

int max_com_restricoes(){

}

int degraus(int degrau_atual, int degraus_restantes){
    if(degraus_restantes<0) return -INF;
    if(degrau_atual == N) return 0;
    if(MEMO[degrau_atual][degraus_restantes] != -1){
        Count++;
        return MEMO[degrau_atual][degraus_restantes];
    }
    //TODO: SUBSTITUIR max por max_com_restricoes
    MEMO[degrau_atual][degraus_restantes] = max(degraus(degrau_atual+1,degraus_restantes-1),degraus(degrau_atual+2,degraus_restantes-2));
    if(degrau_atual == 0){
        return Count;
    }
    Count++;
    return MEMO[degrau_atual][degraus_restantes];
}


int main(int argc, char *argv[]){
    printf("Digite o numero de degraus: ");
    scanf("%d",&N);
    MEMO = aloca_m_quad(N);
    printf("Numero de possibilidades: %d\n",degraus(0,N-1));
    libera_m_quad(MEMO, N);
    return 0;
}


