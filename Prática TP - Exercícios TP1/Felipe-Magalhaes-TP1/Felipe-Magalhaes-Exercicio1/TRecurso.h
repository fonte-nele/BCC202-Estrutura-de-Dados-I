#ifndef TRECURSO_H
#define TRECURSO_H
#include <iostream>
using namespace std;

typedef struct
{
	int tipo;
	double capacidade;
	double EmUso;
	double velocidade;
}TRecurso;

void Inicializar_Recurso(TRecurso**);

int TRecurso_getTipo(TRecurso*);
double TRecurso_getCapacidade(TRecurso*);
double TRecurso_getEmUso(TRecurso*);
double TRecurso_getVelocidade(TRecurso*);

void TRecurso_setTipo(TRecurso*,int);
void TRecurso_setCapacidade(TRecurso*,double);
void TRecurso_setEmUso(TRecurso*,double);
void TRecurso_setVelocidade(TRecurso*,double);

int estaDisponivel(TRecurso*,double);
int reservar(TRecurso*,double);
int liberar_recurso(TRecurso*,double);
double calcularTempo(TRecurso*,double);

void liberar_memoria (TRecurso*);

#endif