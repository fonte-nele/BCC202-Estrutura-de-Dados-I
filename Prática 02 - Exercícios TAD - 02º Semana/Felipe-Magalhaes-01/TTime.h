#ifndef TTIME_H
#define TTIME_H

#include "TJogador.h"

typedef struct 
{
	char nome[50];
	TJogador **jogadores;
	int vitorias;
	int derrotas;
	int empates;
	float score;
	float pontos;
}TTime;

void TTime_Inicia(TTime**);
char* TTime_getNome(TTime*);
TJogador** TTime_getJogadores(TTime*);
int TTime_getVitorias(TTime*);
int TTime_getDerrotas(TTime*);
int TTime_getEmpates(TTime*);
void TTime_setNome(TTime*,char*);
void TTime_setJogadores(TTime*,TJogador**);
void TTime_setVitorias(TTime*,int);
void TTime_setDerrotas(TTime*,int);
void TTime_setEmpates(TTime*,int);
float TTime_calculaScore(TTime*,int);
float TTime_calculaPontos(TTime*);
void TTime_libera(TTime*,int);

#endif
