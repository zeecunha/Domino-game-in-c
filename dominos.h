/**
 *  @file dominos.h
 *  @brief implementação de todas as funções do Programa.
 *
 *
 *  @author José Cunha (28018@ufp.edu.pt), Filipe Laranjeira (26388@ufp.edu.pt)
*/


#ifndef DOMINOS_H_INCLUDED
#define DOMINOS_H_INCLUDED

void create_dominoes(int parts[][2], int hSize, int nh[hSize][2]);
void printHand(int hSize, int nh[hSize][2]);
void printHandStrings(int hSize, int nh[hSize][2]);
//int* getPeaceByIndex(int parts[][2], int index, int peca[]);
int getIndexPeace(int parts[][2], int peca[]);
void store_into_matrix(int newHand[][2], int hSize, int parts[28][2], int matrixHands[28][28],int linha);
void cleanMatrix(int matrix[28][28]);
void printMatrix(int matrix[28][28]);
int isRepeated(int hSize, int nh[hSize][2], int p[2]);
int randNumber();
void permute(int *v, const int first, const int t);
void cleanArray(int v[], int size);
void print(const int *v, const int size);
int sizeArray(int v[],int size);
void printHandPlayers(int hSize, int nh[][2]);
void print_parts(int parts[][2]);


#endif // DOMINOS_H_INCLUDED
