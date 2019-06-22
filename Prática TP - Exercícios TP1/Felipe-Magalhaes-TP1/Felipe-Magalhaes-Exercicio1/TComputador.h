#ifndef TCOMPUTADOR_H
#define TCOMPUTADOR_H
#include "TRecurso.h"
#include "TProcesso.h"

typedef struct
{
	TRecurso** vetor_recurso;
	TProcesso** vetor_processo;
	//Campos extras para haver um maior controle do código.
	int cont_recurso;
	int cont_processo;
	int n_proc;
	int n_recurso;
	double temp_total;
}TComputador;

void Inicializar_Computador(TComputador**,int,int);
int verificar_disponibilidade(TComputador*,int,double);
void addRecurso(TComputador*,TRecurso*);
void addProcesso(TComputador*,TProcesso*);
void executar_computador(TComputador*,int);

void liberar_memoria_computador(TComputador*,int);
#endif