#ifndef TPROCESSO_H
#define TPROCESSO_H
#include "TRecurso.h"
#include "TTarefa.h"

typedef struct
{
	TTarefa** vetor_tarefa;
	int conclusao_processo;
	//Campos extras para ter um maior controle do programa.
	int contador;
	int v[3];
	int maquina;
	double temp_proc;
}TProcesso;

void Inicializar_Processo(TProcesso**,int);
void somar_demanda(TProcesso*,int,double);
double result_demanda(TProcesso*,int);

TTarefa** TProcesso_getTarefas(TProcesso*);
int TProcesso_getConclusao(TProcesso*);

void TProcesso_setTarefas(TProcesso*,TTarefa**);
void TProcesso_setConclusao(TProcesso*,int);

void AddTarefa(TProcesso*,TTarefa*);
void executar_processo(TProcesso*);

void liberar_memoria_tarefa(TProcesso*,int);
#endif