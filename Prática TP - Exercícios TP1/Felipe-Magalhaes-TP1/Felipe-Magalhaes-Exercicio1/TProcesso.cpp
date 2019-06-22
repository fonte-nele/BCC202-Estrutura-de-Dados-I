#include "TProcesso.h"
#include "TTarefa.h"
void Inicializar_Processo(TProcesso**processo, int num_tar)
{
	*processo = new TProcesso;
	TProcesso_setConclusao(*processo, 0);
	(*processo) -> contador = 0;
	(*processo)-> vetor_tarefa = new TTarefa*[num_tar];
	(*processo)-> maquina = 0;
	(*processo)->temp_proc = 0;
	//Inicializo o vetor da struct TProcesso.
	for(int i=1;i<4;i++)
	{
		(*processo)->v[i] = 0;
	}
	//Inicializo o vetor de tarefas do TTarefa
	for(int j=0;j<num_tar;j++)
	{
		Inicializar_Tarefa(&(*processo)->vetor_tarefa[j]);
	}
}

void somar_demanda(TProcesso* processo,int tipo, double dem)
{
	//Somar demanda de cada tipo.
	processo -> v[tipo] += dem;
}

double result_demanda(TProcesso* processo, int tipo)
{
	//Retorna a soma da demanda de cada tipo
	return processo->v[tipo];
}

TTarefa** TProcesso_getTarefas(TProcesso* processo)
{
	return processo -> vetor_tarefa;
}

int TProcesso_getConclusao(TProcesso* processo)
{
	return processo -> conclusao_processo;
}

void TProcesso_setTarefas(TProcesso* processo, TTarefa** quant)
{
	processo -> vetor_tarefa[processo->contador]->recurso_tarefa = (*quant)->recurso_tarefa;
	processo -> vetor_tarefa[processo->contador]->demanda = (*quant)->demanda;
	processo -> contador += 1;
}

void TProcesso_setConclusao(TProcesso* processo, int valor)
{
	processo -> conclusao_processo = valor;
}

void AddTarefa(TProcesso* processo, TTarefa* tarefa)
{
	//Adiciona tarefa ao vetor da struct TProcesso na posição do contador.
	processo -> vetor_tarefa[processo->contador]->recurso_tarefa = tarefa->recurso_tarefa;
	processo -> vetor_tarefa[processo->contador]->demanda = tarefa->demanda;

	//Incrementa o contador.
	processo -> contador += 1;
	//Soma a demanda
	somar_demanda(processo,tarefa->recurso_tarefa,tarefa->demanda);
}

void executar_processo(TProcesso* processo)
{
	for(int i=0;i<(processo->contador);i++)
	{
		executar_tarefa(processo->vetor_tarefa[i]);
	}
	//Altero o campo de conclusão.
	TProcesso_setConclusao(processo, 1);
}

void liberar_memoria_tarefa(TProcesso* processo, int quant)
{
	int i;
	for(i=0;i<quant;i++)
	{
		delete []processo -> vetor_tarefa[i];
	}
	delete processo -> vetor_tarefa;
	delete processo;
}
