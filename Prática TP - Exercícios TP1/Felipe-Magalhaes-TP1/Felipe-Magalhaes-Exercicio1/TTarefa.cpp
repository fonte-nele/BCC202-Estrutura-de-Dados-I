#include "TTarefa.h"

void Inicializar_Tarefa(TTarefa** tarefa)
{
	*tarefa = new TTarefa;
	TTarefa_setRecurso(*tarefa, 0);
	TTarefa_setDemanda(*tarefa, 0);
	TTarefa_setConclusao(*tarefa, 0);
}

int TTarefa_getRecurso(TTarefa* tarefa)
{
	return tarefa -> recurso_tarefa;
}

double TTarefa_getDemanda(TTarefa* tarefa)
{
	return tarefa -> demanda;
}

int TTarefa_getConclusao(TTarefa* tarefa)
{
	return tarefa -> conclusao_tarefa;
}

void TTarefa_setRecurso(TTarefa* tarefa, int RECURSO)
{
	tarefa -> recurso_tarefa = RECURSO;
}

void TTarefa_setDemanda(TTarefa* tarefa, double quant)
{
	tarefa -> demanda = quant;
}

void TTarefa_setConclusao(TTarefa* tarefa, int valor)
{
	tarefa -> conclusao_tarefa = valor;
}

void executar_tarefa(TTarefa* tarefa)
{
	tarefa -> conclusao_tarefa = 1;
}