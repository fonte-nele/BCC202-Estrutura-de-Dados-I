#include "TTime.h"
#include<string.h>

void TTime_Inicia(TTime** time)
{
	*time = new TTime;
	TTime_setJogadores(*time, 0);
	TTime_setVitorias(*time, 0);
	TTime_setDerrotas(*time, 0);
	TTime_setEmpates(*time, 0);
}

char* TTime_getNome(TTime* time)
{
	return time->nome;
}

TJogador** TTime_getJogadores(TTime* time)
{
	return time->jogadores;
}

int TTime_getVitorias(TTime* time)
{
	return time->vitorias;
}

int TTime_getDerrotas(TTime* time)
{
	return time->derrotas;
}

int TTime_getEmpates(TTime* time)
{
	return time->empates;
}

void TTime_setNome(TTime* time, char* nome)
{
	strcpy(time->nome, nome);
}

void TTime_setJogadores(TTime* time, TJogador** jogadores)
{
	time->jogadores = jogadores;
}

void TTime_setVitorias(TTime* time, int vitorias)
{
	time->vitorias = vitorias;
}

void TTime_setDerrotas(TTime* time, int derrotas)
{
	time->derrotas = derrotas;
}

void TTime_setEmpates(TTime* time, int empates)
{
	time->empates = empates;
}

float TTime_calculaScore(TTime* time, int n_Jogadores)
{
	int i;
	float score = 0;
	for(i = 0 ; i < n_Jogadores ; i++)
	{
		score += TJogador_calculaScore(time->jogadores[i]);
	}
	score = score/n_Jogadores;
	time->score = score;
	return score;
}

float TTime_calculaPontos(TTime *time)
{
	float pontos = (3*TTime_getVitorias(time))+TTime_getEmpates(time);
	time->pontos = pontos;
	return pontos;
}

void TTime_libera(TTime *time, int n_Jogadores)
{
	int j;
	for(j=0;j<n_Jogadores;j++)
	{
		delete [] time->jogadores[j];
	}
	delete time->jogadores;
	delete time;
}