#ifndef TJOGADOR_H
#define TJOGADOR_H

#include <iostream>
#include <string>
using namespace std;

typedef struct 
{
	char nome[50];
	int jogos;
	int pontos;
	int faltas;
	int cartoes;
}TJogador;

void TJogador_Inicia(TJogador**);
char* TJogador_getNome(TJogador*);
int TJogador_getJogos(TJogador*);
int TJogador_getPontos(TJogador*);
int TJogador_getFaltas(TJogador*);
int TJogador_getCartoes(TJogador*);
void TJogador_setNome(TJogador*,char*);
void TJogador_setJogos(TJogador*,int);
void TJogador_setPontos(TJogador*,int);
void TJogador_setFaltas(TJogador*,int);
void TJogador_setCartoes(TJogador*,int);
float TJogador_calculaScore(TJogador*);

#endif