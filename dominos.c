/**
 *  @file dominos.c
 *  @brief implementação de todas as funções do Programa.
 *
 *
 *  @author José Cunha (28018@ufp.edu.pt), Filipe Laranjeira (26388@ufp.edu.pt)
*/

#include <stdio.h>
#include <stdlib.h>
#include "dominos.h"

	/**
     * FUNÇÃO PARA CRIAR OS CONJUNTOS DE PEÇAS;
     *
     * @param parts	- todas as pecas
     * @param hSize	- tamanho pretendido
	 * @param nh - nova mao criada
     * @return
     */


void create_dominoes(int parts[][2], int hSize, int nh[][2])
{
    int aux[2];
    int key = 0;
    int i,j;
    for (i = 0; i < hSize; i++) //até ao tamanho da mao pretendida
    {
        for (j = 0; j < 1; ++j)
        {
            key = randNumber(); //chama a funcao random e guarda em key
            aux[j] = parts[key][j]; //"grava" na variavel aux, o lado esquedo da peça
            aux[j + 1] = parts[key][j + 1]; //"grava" na variavel aux +1, o lado direito da peça
            if (isRepeated(hSize, nh, aux) == 1)     //verificar se é repetido. Manda o tamanho da mao, a nova mao nh e o o vetor aux
            {
                i--;    //se for igual, decrementa o i, para voltar a "tentar"
            }
            else        //se nao for repetido
            {
                nh[i][j] = parts[key][j];    //lado esquerdo
                nh[i][j + 1] = parts[key][j + 1];    //lado direito
            }
        }
    }
}


/**
     * IMPRIMIR A MAO COMO INTEIROS;
     *
     * @param hsize	- tamanho pretendido
     * @param nh	- nova mao criada
     * @return
     */


void printHand(int hSize, int nh[][2])
{
    int i, j;
    printf("\n MAO RECEBIDA \n");
    for (i = 0; i < hSize; i++) //ATÉ AO TAMANHO DA MAO PRETENDIDO
    {
        for (j = 0; j < 1; j++)
        {
            printf("[ %d ][ %d ]\n", nh[i][j], nh[i][j + 1]); //lado esquerdo -- lado direito        }
        }
    }
}



/**
     * IMPRIMIR A MÃO COMO CHARS;
     *
     * @param hSize	- tamanho pretendido
	 * @param nh - nova mao criada
     * @return
     */


void printHandStrings(int hSize, int nh[][2])
{
    int i, j;
    int ascii='0';   // o ascii do zero.
    printf("\n MAO RECEBIDA \n");
    for (i = 0; i < hSize; i++) //ATÉ AO TAMANHO DA MAO PRETENDIDO
    {
        for (j = 0; j < 1; j++)
        {
            printf("[ %c %c ]\n", nh[i][j] + ascii, nh[i][j + 1] + ascii); //lado esquerdo -- lado direito
        }
    }
}


/**
     * FUNÇÃO QUE DADO UM INDEX, RETORNA A PEÇA;
     *
     * @param parts	- todas as pecas
     * @param index	- index da peca
	 * @param peca - peca
     * @return
     */


int* getPeaceByIndex(int parts[][2], int index, int peca[])
{
    peca[0] = parts[index][0];  //LADO ESQUERDO
    peca[1] = parts[index][1];  //LADO DIREITO
    return peca;
}


/**
     * FUNÇAO QUE RETORNA O INDEX DE UMA PEÇA;
     *
     * @param parts	- todas as pecas
	 * @param peca - peca
     * @return
     */


int getIndexPeace(int parts[][2], int peca[])
{
    int i=0;
    for(i=0; i<28; i++) //ATE 28 PEÇAS
    {
        if (parts[i][0] == peca[0] && parts[i][1] == peca[1])  //peca[0]->esq, peca[1]->dt
        {
            return i;   //INDICE DA PEÇA
        }
    }
    return -1;
}

/**
     * GUARDAR AS MAOS NUMA MATRIX AUXILIAR;
     *
     * @param newHand	- a nova mao gerada
	 * @param hSize - tamanho da mao
	 * @param parts - todas as pecas
	 * @param matrixHands - matrix para armazenar a mao
	 * @param linha - a linha onde se vai armazenar a mao
     * @return
     */


void store_into_matrix(int newHand[][2], int hSize, int parts[28][2], int matrixHands[28][28],int linha)
{
    int i, newHandIndex;
    for(i=0; i<hSize; i++)  //ATÉ AO TAMANHO DA MÃO
    {
        newHandIndex=getIndexPeace(parts, newHand[i]);  //VAI BUSCAR O INDEX DA PEÇA E GUARDA EM newHandIndex
        matrixHands[linha][i] = newHandIndex;   //GUARDA O INDEX DA PEÇA NA LINHA CORRESPONDENTE À MÃO
        //CADA ITERACAO DO I, CORRESPONDE A UMA LINHA DA MATRIX 28X28
    }
}


/**
     * FUNCAO PARA LIMPAR MATRIZ AUXILIAR 28X28;
     *
	 * @param matrix - recebe a matrix para limpar
     * @return
     */

void cleanMatrix(int matrix[28][28])
{
    int i,j;
    for(i=0; i<28; i++) //MATRIX ATE 28
    {
        for (j=0; j<28; j++)    //MATRIX ATE 28
        {
            matrix[i][j] = '\0';
        }
    }
}


/**
     * FUNCAO PARA IMPRIMIR MATRIZ AUXILIAR 28X28;
     *
	 * @param matrix - recebe a matrix para a imprimir
     * @return
     */


void printMatrix(int matrix[28][28])
{
    int i,j;
    for(i=0; i<28; i++) //MATRIX ATE 28
    {
        for (j=0; j<28; j++)   //MATRIX ATE 28
        {
            printf("[%d] ",matrix[i][j]);
        }
        printf("\n");
    }
}

/**
     * FUNCAO DE VERIFICACAO DE REPETICAO;
     *
	 * @param hSize - tamanho da mao
	 * @param nh - a nova mao
	 * @param p - recebe a matrix aux onde estao as pecas para comparacao
     * @return
     */

int isRepeated(int hSize, int nh[][2], int p[2])
{
    int i, j;
    for (i = 0; i < hSize; i++) //ATÉ AO TAMANHO DA MAO
    {
        for (j = 0; j < 1; j++)
        {
            if ((nh[i][j] == p[j]) && (nh[i][j + 1] == p[j + 1]))     //SE O LADO ESQUERDO FOR IGUAL AO AUX PASSADO E O LADO DIREITO TB, RETORNA 1
            {
                return 1;
            }
        }
    }
    return 0;  // se for diferente return 0
}


/**
     * FUNCAO PARA EFETUAR O RANDOM DE PEÇAS;
     *
     * @return
     */

int randNumber()
{
    return (rand() % 28);
}

/**
     * FUNCAO PARA FAZER A PERMUTAÇÃO DE NUMEROS;
     *
	 * @param v - vetor onde estao as pecas armazenadas
	 * @param first - 0, ou seja, do inicio
	 * @param t - tamanho
     * @return
     */


void permute(int *v, const int first, const int t)
{
    int i=0, aux=0;
    if (first == t-1)  //quando passar o tamanho, imprime
    {
        print(v, t);
    }
    else
    {
        for (i = first; i < t; i++)         //first = 0 ... N=tamanho
        {
            aux = v[i];   // numero i = temp
            v[i] = v[first];  // numero i = first
            v[first] = aux;   //first = numero i
            permute(v, first+1, t);   //permutacao peca, first +, n=tamanho
            v[first] = v[i];  //first=numero i
            v[i] = aux; //voltar a por v[i] com o numero original
        }
    }
}


/**
     * FUNCAO PARA LIMPAR O ARRAY ONDE IREI GUARDAR AS PECAS PARA PERMUTACAO;
     *
	 * @param v - vetor onde estao as pecas armazenadas
	 * @param size - tamanho
     * @return
     */

void cleanArray(int v[], int size)
{
    int i=0;
    for(i=0; i<size; i++)
    {
        v[i]='\0';  //preencher com \0
    }
}


/**
     * FUNCAO PARA IMPRIMIR A PERMUTAÇÃO;
     *
	 * @param v - vetor onde estao as pecas armazenadas
	 * @param size - tamanho
     * @return
     */

void print(const int *v, const int size)
{
    int i=0;
    if (v != 0)
    {
        for (i = 0; i < size; i++)
        {
            printf("[%d]  ", v[i] );
        }
        printf("\n");
    }
}


/**
     * FUNCAO PARA DETERMINAR O TAMANHO DO ARRAY;
     *
	 * @param v - vetor onde estao as pecas armazenadas
	 * @param size - tamanho
     * @return
     */

int sizeArray(int v[],int size){
    int i=0,c=0;
    for(i=0;i<size;i++)
        if(v[i] != '\0')    //ate chegar ao \0
        {
            c++;
        }
    return c;
}


/**
     * IMPRIMIR A MAO POR JOGADOR;
     *
	 * @param hSize - quantidade de jogadors
	 * @param nh - nova mao
     * @return
     */

void printHandPlayers(int hSize, int nh[][2])
{
    int i, j;

     printf("\n JOGADOR \n");
    for (i = 0; i < hSize; i++) //ATÉ AO TAMANHO DA MAO PRETENDIDO
    {
        for (j = 0; j < 1; j++)
        {
            printf("[ %d ][ %d ]\n", nh[i][j], nh[i][j + 1]); //lado esquerdo -- lado direito        }
        }
    }
}

/**
     * FUNCAO PARA IMPRIMIR TODAS AS PECAS;
     *
	 * @param parts - todas as pecas
     * @return
     */

void print_parts(int parts[][2])
{
    int i=0;
    for(i=0; i<28; i++)
    {
        printf("[%d  %d] \n",parts[i][0],parts[i][1]);
    }
}





