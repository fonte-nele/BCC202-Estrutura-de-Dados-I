#include "TComputador.h"
#include "TTarefa.h"
#include "TRecurso.h"

void Inicializar_Computador(TComputador** computador,int num_rec,int num_proc)
{
	*computador = new TComputador;
	(*computador) -> cont_recurso = 0;
	(*computador) -> cont_processo = 0;
	(*computador) -> n_proc = num_proc;
	(*computador) -> n_recurso = num_rec;
	(*computador) -> vetor_recurso = new TRecurso*[num_rec];
	(*computador) -> vetor_processo = new TProcesso*[num_proc];
	(*computador) -> temp_total = 0;
	
	//Inicializar o vetor de recursos.
	for(int i=0; i<num_rec;i++)
	{
		Inicializar_Recurso(&(*computador)->vetor_recurso[i]);
	}
}

int verificar_disponibilidade(TComputador* comp,int tipo,double demanda)
{
	int disp=0;
	if(demanda==0)
	{
		return 1;
	}
	for(int i=0; i<comp->n_recurso;i++)
	{
		if(comp->vetor_recurso[i]->tipo == tipo)
		{
			if(estaDisponivel(comp->vetor_recurso[i], demanda)==1)
			{
				disp = 1;
				break;
			}
		}			
	}
	return disp;
}

void addRecurso(TComputador* computador,TRecurso* recurso)
{
	computador -> vetor_recurso[computador->cont_recurso] = recurso;
	computador -> cont_recurso = computador -> cont_recurso + 1;
}

void addProcesso(TComputador* computador,TProcesso* processo)
{
	computador -> vetor_processo[computador->cont_processo] = processo;
	computador -> cont_processo += 1;
	
	for(int i=0; i<(processo->contador);i++)
	{
		TTarefa* temp = processo->vetor_tarefa[i];
		for(int j=0; j<(computador->n_recurso);j++)
		{
			if(temp->recurso_tarefa == computador->vetor_recurso[j]->tipo)
			{
				if((reservar(computador->vetor_recurso[j],temp->demanda)))
				{
					//Se conseguir reservar já pode sair desse for.
					break;
				}
			}
		}
	}
}

void executar_computador(TComputador* computador,int id_comp)
{
	for(int i=0;i<(computador->cont_processo);i++)
	{
		double cont_tempo=0;
		executar_processo(computador->vetor_processo[i]);
		for(int j=0; j<computador->vetor_processo[i]->contador;j++)
		{
			TTarefa* temp = computador->vetor_processo[i]->vetor_tarefa[j];
			
			for(int k=0; k<(computador->n_recurso);k++)
			{
				if(temp->recurso_tarefa == computador->vetor_recurso[k]->tipo)
				{
					if((liberar_recurso(computador->vetor_recurso[k],temp->demanda)))
					{
						cont_tempo+= calcularTempo(computador->vetor_recurso[k],temp->demanda);
						//Se conseguir liberar, já pode sair do laço.
						break;
					}
				}
			}
			computador->vetor_processo[i] ->temp_proc = cont_tempo;
		}
		computador->temp_total += computador->vetor_processo[i] ->temp_proc;
	}
}

void liberar_memoria_computador(TComputador*comp, int num)
{
	int j;
	for(j=0;j<num;j++)
	{
		delete [] comp->vetor_recurso[j];
		delete [] comp->vetor_processo[j];
	}
	delete comp->vetor_recurso;
	delete comp->vetor_processo;
	delete comp;
}