///
///  @file main.c
///  @brief main for LP1 project1
///
///  José Cunha (28018@ufp.edu.pt), Filipe Laranjeira (26388@ufp.edu.pt)
///

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dominos.h"
#define MAX28 28

/// MENU DE JOGO


int main(int argc, const char *argv[])
{
    int matrixHands[28][28];
    int hSize = 0;
    int s = 0;
    int nHand = 0;
    int nPlayers = 0;
    int newHandIndex = 0;
    int parts[28][2] = {{0, 1},{0, 2},{0, 3},{0, 4},{0, 5},{0, 6},
        {1, 2},{1, 3},{1, 4},{1, 5},{1, 6},
        {2, 3},{2, 4},{2, 5},{2, 6},
        {3, 4},{3, 5},{3, 6},
        {4, 5},{4, 6},
        {5, 6},
        {0, 0},{1, 1},{2, 2},{3, 3},{4, 4},{5, 5},{6, 6}
    };
    //Set seed (semente)
    srand(time(NULL));

    do
    {
        printf("\n----- PROJETO LP1 : DOMINO -----\n");
        printf("\n-----  Escolha uma opcao:  -----\n");
        printf("1 - Uma mao\n");
        printf("2 - Duas ou mais maos\n");
        printf("3 - Imprimir uma mao em int e char\n");
        printf("4 - Imprimir uma mao e o respectivo index\n");
        printf("5 - Imprimir uma ou mais maos e o respectivo index e gravar na matriz 28x28\n");
        printf("6 - Inserir pecas, permutacao e imprimir\n");
        printf("7 - Definir pecas para N jogadores\n");
        printf("8 - Imprimir todas as pecas\n");
        printf("0 - Exit\n");
        printf("\n----- PROJETO LP1 : DOMINO  JOSE CUNHA - FILIPE LARANJEIRA -----\n");
        scanf("%d", &s);
        switch (s)
        {
        case 1:
        {
            printf("QUANTAS PECAS QUER?\n");
            scanf("%d", &hSize);    //tamanho da mao
            if (hSize != 7)
            {
                int newHand[hSize][2];  //nova mao com o tamanho pretendido
                create_dominoes(parts, hSize, newHand);    //criar dominos com o conjunto de peças, tamanho e a nova mao
                printHand(hSize, newHand);  //imprimir
            }
            else
            {
                printf("INSIRA UM NUMERO VALIDO");
            }
            break;
        }
        case 2:
            printf("QUANTAS MAOS QUER?\n");
            scanf("%d", &nHand);    //n de mao
            printf("QUANTAS PECAS QUER?\n");
            scanf("%d", &hSize);    //tamanho da mao
            if (nHand * hSize < 28)
            {
                int i;
                for(i=0; i<nHand; i++)  //ate ao numero de maos pretendido , faz o ciclo
                {
                    int newHand[hSize][2];  //nova mao
                    create_dominoes(parts, hSize, newHand);    //criar peças
                    printHand(hSize, newHand);  //imprimir
                }
            }
            else
            {
                //se passar as 28 peças e tamanho 7
                return printf("N MAOS X N PECAS > 28. POR FAVOR INSERIR NOVAS OPCOES!");
            }
            break;

        case 3:
        {
            printf("QUANTAS PECAS QUER?\n");
            scanf("%d", &hSize);    //tamanho da mao
            if (hSize != 7)
            {
                int newHand[hSize][2];  //nova mao com o tamanho pretendido
                create_dominoes(parts, hSize, newHand);    //criar dominos com tamanho e a nova mao
                printf("\n MAO EM INTEIRO \n");
                printHand(hSize, newHand);  //imprimir em inteiros
                printf("\n MAO EM CHAR \n");
                printHandStrings(hSize, newHand);   //imprimir em chars
            }
            else
            {
                printf("INSIRA UM NUMERO VALIDO");
            }
            break;
        }
        case 4:
        {
            printf("QUANTAS PECAS QUER?\n");
            scanf("%d", &hSize);    //tamanho da mao
            if (hSize != 7)
            {
                int newHand[hSize][2];  //nova mao com o tamanho pretendido
                create_dominoes(parts, hSize, newHand);    //criar dominos com tamanho e a nova mao
                printHand(hSize, newHand);  //imprimir
                int i;

                for(i=0; i<hSize; i++)  //até ao numero de peças pretendido
                {
                    newHandIndex=getIndexPeace(parts, newHand[i]);  //grava em newHandIndex, o index da peça [i]
                    printf("%d - INDEX: %d\n",i,newHandIndex);
                };
            }
            else
            {
                printf("INSIRA UM NUMERO VALIDO");
            }
            break;
        }
        case 5:
        {
            printf("QUANTAS MAOS QUER?\n");
            scanf("%d", &nHand);    //n de mao
            printf("QUANTAS PECAS QUER?\n");
            scanf("%d", &hSize);    //tamanho da mao
            if (nHand * hSize < 28) //o numero de maos x o numero de peças não pode ser maior que 28
            {
                int i=0, j=0;
                cleanMatrix(matrixHands);   //limpar a matriz
                for(i=0; i<nHand; i++)  //ate ao numero de maos pretendido , faz o ciclo
                {
                    int newHand[hSize][2];  //nova mao com o tamanho pretendido
                    create_dominoes(parts, hSize, newHand);    //criar dominos com tamanho e a nova mao
                    printHand(hSize, newHand);  //imprimir
                    for(j=0; j<nHand; j++)
                    {
                        printf("%d - INDEX: %d\n", j, getIndexPeace(parts, newHand[j])); //imprimir o index da peça
                    }
                    store_into_matrix(newHand, hSize, parts, matrixHands,i);    //funcao para guardar na matrix 28x28. Recebe a nova mao, o tamanho da mao, conjunto de peças, a matrix 28x28 e o i(que funciona como linha)
                }

                printMatrix(matrixHands);   //imrpimir a matrix
            }
            else
            {
                //se passar as 28 peças e tamanho 7
                return printf("N MAOS X N PECAS > 28. POR FAVOR INSERIR NOVAS OPCOES!");
            }
            break;
        }
        case 6:
        {
            //ESTA FUNCAO TEM DUAS VERSOES, OU O INSERIMOS OS NUMEROS NO V[] OU PEDIMOS AO UTILIZADOR PARA INSERIR (FUNCIONA PARCIALMENTE)

            //int v[]={22,11,21,13};

            int v[MAX28];
            int i=0, aux=0, tam=0;
            cleanArray(v,MAX28);    //limpar o vetor
            printf("INSIRA PECAS! Termine com 'x' \n");
            for(i=0; i<MAX28;i++)   //ate ao maximo de pecas
            {
                scanf("%d", &aux);  //guarda as peças em aux
                if(aux!='x')    //quando for diferente de x vai guardando em v[i]
                {
                    v[i]=aux;
                }else
                {
                    break;
                }
                aux='\0';
            }

            tam=sizeArray(v, MAX28);    //guarda o tamanho ocupado pelo array em tam

            permute(v, 0, tam);   //chama a funcao de permuta
            //permute(v, 0, sizeof(v)/sizeof(int));   //chama a funcao de permuta
            break;
        }

        case 7:
        {
            printf("QUANTOS JOGADORES PRETENDE?\n");
            scanf("%d", &nPlayers);    //n de mao
            printf("QUANTAS PECAS QUER EM CADA JOGADOR?\n");
            scanf("%d", &hSize);    //tamanho da mao
            if (nPlayers * hSize < 28)
            {
                int i;
                for(i=0; i<nPlayers; i++)  //ate ao numero de maos pretendido , faz o ciclo
                {
                    int newHand[hSize][2];  //nova mao
                    create_dominoes(parts, hSize, newHand);    //criar peças
                    printHandPlayers(hSize, newHand);  //imprimir
                }
            }
            else
            {
                //se passar as 28 peças e tamanho 7
                return printf("N MAOS X N PECAS > 28. POR FAVOR INSERIR NOVAS OPCOES!");
            }
            break;
        }

        case 8:
        {
            print_parts(parts);
            break;
        }

        default:
            break;
        }
    }
    while (s != 0);
    return 0;
}


