/*
Matheus Tomieiro de Oliveira, 10734630
Victor Vieira Custodio Reis, 10734686
*/
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

//Declarando variaveis globais(Por conviniencia na reducao de argumentos da funcao recursiva)
int **MEMO;
int N, NR;
int *VARG;

/*
Funcao que calcula a quantidade de possibilidades de subir uma escada dado o degrau atual e
quantos degraus ainda faltam para o fim dela.
args: (int) degrau_atual, (int) degraus_restantes
return: (int) Numero de possibilidades de subit a escada [a partir dos indices passados por parametro]
*/
int degraus(int degrau_atual, int degraus_restantes){
    if(degraus_restantes < 0) return 0; //Caso Base 1: Quando ja se passou o ultimo degrau[nao ha mais caminho]
    if(degraus_restantes == 0) return 1; //Caso Base 2: Quando se estah no ultimo degrau[ha um caminho]    
    if(MEMO[degrau_atual][degraus_restantes] != 0) return MEMO[degrau_atual][degraus_restantes]; //Evitando redundancia
    
    for(int i=0; i<NR; i++){ //Rodadando para todas as restricoes
        if(VARG[i]<N) //Evitando casos onde a restricao eh maior que o numero de degraus
            MEMO[degrau_atual][degraus_restantes] += degraus(degrau_atual+VARG[i], degraus_restantes-VARG[i]);
            //Na linha acima, os casos sao somados para cada nivel da arvore [contabilizando niveis abaixo]
    }
    
    return MEMO[degrau_atual][degraus_restantes];
}


int main(int argc, char *argv[]){
    //Lendo informacoes relevantes
    printf("Digite o numero de degraus: ");
    scanf("%d",&N);
    printf("Digite o numero de restricoes: ");
    scanf("%d",&NR);
    VARG = (int*)malloc(NR*sizeof(int)); 
    printf("Digite a lista de restricoes, seperando itens por espaços\n");
    for(int i=0; i<NR; i++){
        scanf("%d",&VARG[i]);
    }

    MEMO = aloca_m_quad(N+1); //Alocando matriz quadrada MEMO na heap
    printf("\nNumero de possibilidades: %d\n\n", (degraus(0,N)));
    libera_m_quad(MEMO, N+1); //Liberando MEMO
    free(VARG);
    
    return 0;
}


