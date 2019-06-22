#include "TJogador.h"
#include<string.h>

void TJogador_Inicia(TJogador** jogador)
{
	(*jogador) = new TJogador;
	TJogador_setJogos(*jogador, 0);
	TJogador_setPontos(*jogador, 0);
	TJogador_setFaltas(*jogador, 0);
	TJogador_setCartoes(*jogador, 0);
}

char* TJogador_getNome(TJogador *jogador)
{
	return jogador->nome;
}

int TJogador_getJogos(TJogador *jogador)
{
	return jogador->jogos;
}

int TJogador_getPontos(TJogador *jogador)
{
	return jogador->pontos;
}

int TJogador_getFaltas(TJogador *jogador)
{
	return jogador->faltas;
}

int TJogador_getCartoes(TJogador *jogador)
{
	return jogador->cartoes;
}

void TJogador_setNome(TJogador *jogador, char* nome)
{
	strcpy(jogador->nome, nome);
}

void TJogador_setJogos(TJogador *jogador, int valor)
{
	jogador->jogos = valor;
}

void TJogador_setPontos(TJogador *jogador, int valor)
{
	jogador->pontos = valor;
}

void TJogador_setFaltas(TJogador *jogador, int valor)
{
	jogador->faltas = valor;
}

void TJogador_setCartoes(TJogador *jogador, int valor)
{
	jogador->cartoes = valor;
}

float TJogador_calculaScore(TJogador *jogador)
{
	float score = (4*TJogador_getJogos(jogador))+(6*TJogador_getPontos(jogador))-(0.5*TJogador_getFaltas(jogador))-TJogador_getCartoes(jogador);
	return score;
}