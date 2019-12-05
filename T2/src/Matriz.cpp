//A DOCUMENTACAO DESTE MODULO SE ENCONTRA NO .h NO DIRETORIO lib/

#include "../lib/Matriz.h"
#include <stdio.h>
#include <stdlib.h>

int **aloca_m_quad(int n){
    int **matriz;
    matriz = (int**)malloc(n*sizeof(int**));
    for(int i= 0; i<n; i++){
        matriz[i] = (int*)malloc(n*sizeof(int*));
    }
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            matriz[i][j] = 0;
        }    
    }
    return matriz;
}

void libera_m_quad(int **matriz, int n){
    for(int i=0; i<n; i++){
        free(matriz[i]);
    }
    free(matriz);
    return;
}

void printa_matriz(int **matriz, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return;
}