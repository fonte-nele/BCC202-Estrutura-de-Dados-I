#ifndef TTAREFA_H
#define TTAREFA_H
#include "TRecurso.h"

typedef struct
{
	int recurso_tarefa;
	double demanda;
	int conclusao_tarefa;
}TTarefa;

void Inicializar_Tarefa(TTarefa**);

int TTarefa_getRecurso(TTarefa*);
double TTarefa_getDemanda(TTarefa*);
int TTarefa_getConclusao(TTarefa*);

void TTarefa_setRecurso(TTarefa*,int);
void TTarefa_setDemanda(TTarefa*,double);
void TTarefa_setConclusao(TTarefa*,int);

void executar_tarefa(TTarefa*);

#endif