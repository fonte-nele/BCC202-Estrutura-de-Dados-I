#include <iostream>
#include "matriz.h"

void criar_matriz (Matriz **mat,int lin, int col)
{
	(*mat) = new Matriz;
	(*mat) -> linha = lin;
	(*mat) -> coluna = col;
	(*mat) -> elementos = new float [lin * col];
	//Inicializando com zeros para não imprimir lixo caso a coordenada que deseja procurar nao tenha valor.
	for(int i=0; i<(lin*col); i++)
	{
		(*mat) -> elementos[i]=0;
	}
}

void adicionar_elemento (Matriz **mat,float numero, int co1, int co2)
{
	(*mat) -> elementos [co1*(*mat)->coluna + co2] = numero;
}

float acessar_elemento (Matriz **mat, int co1, int co2)
{
	return (*mat) -> elementos [co1*(*mat)->coluna + co2];
}

int getNumeroLinha(Matriz **mat)
{
	return (*mat) -> linha;
}

int getNumeroColuna(Matriz **mat)
{
	return (*mat) -> coluna;
}

void liberar_memoria (Matriz **mat)
{
	delete [] (*mat) -> elementos;
	delete (*mat);
}