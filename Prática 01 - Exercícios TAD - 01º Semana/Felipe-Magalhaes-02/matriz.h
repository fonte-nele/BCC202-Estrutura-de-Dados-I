#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
using namespace std;
typedef struct
{
	int linha;
	int coluna;
	float *elementos;
}Matriz;

void criar_matriz (Matriz**,int, int);
void adicionar_elemento (Matriz**,float, int, int);
float acessar_elemento (Matriz**,int, int);
int getNumeroLinha(Matriz**);
int getNumeroColuna(Matriz**);
void liberar_memoria (Matriz**);

#endif