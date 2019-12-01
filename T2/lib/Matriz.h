//Header para manipular matrizes na heap

/*
Funcao que aloca uma matriz NxN na heap
args: (int)Numero de linha/colunas
return: (int**) Endereco da matriz
*/
int **aloca_m_quad(int n);

/*
Funcao que libera uma matriz N x N da heap
args: (int**) Matriz desejada, (int) Numero de linhas/colunas
*/
void libera_m_quad(int **matriz, int n);

/*
Funcao que printa uma matriz NxN
args: (int**) Matriz desejada, (int) Numero de linhas/colunas
*/
void printa_matriz(int **matriz, int n);