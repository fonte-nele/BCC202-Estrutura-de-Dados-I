#include "TRecurso.h"
#include "TProcesso.h"
#include "TComputador.h"
#include "TTarefa.h"

int main()
{
	int n_PC,quant_proc,quant_rec;
	int tipo_rec;
	int num_proc,tipo_tarefa,quant_tar;
	double veloc,demanda,capac;
	cout<<"Digite a quantidade de computadores:\n";
	cin>>n_PC;
	TComputador **comp = new TComputador*[n_PC];
	
	for(int i=0;i<n_PC;i++)
	{
		cout<<"\nDigite a quantidade de recursos e processos do computador "<<i+1<<" :\n";
		cin>>quant_rec>>quant_proc;
		Inicializar_Computador(&comp[i],quant_rec,quant_proc);

		for(int j=0;j<quant_rec;j++)
		{
			TRecurso *recurso = new TRecurso;
			Inicializar_Recurso(&recurso);
			cout<<"Digite o tipo de recurso:1-CPU, 2-Memoria, 3-Disco.\n";
			cin>>tipo_rec;

			while(tipo_rec<1 || tipo_rec>3)
			{
				cout<<"\nTipo de recurso invalido. FAVOR TENTAR NOVAMENTE....."<<endl;
				cout<<"\nDigite o tipo de recurso:1-CPU, 2-Memoria, 3-Disco.\n";
				cin>>tipo_rec;
	
			}
			cout<<"Digite a capacidade do recurso:\n";
			cin>>capac;
			cout<<"Digite a velocidade do recurso:\n";
			cin>>veloc;

			TRecurso_setTipo(recurso,tipo_rec);
			TRecurso_setCapacidade(recurso,capac);
			TRecurso_setVelocidade(recurso,veloc);
			addRecurso(comp[i],recurso);
		}	
	}
	cout<<"\n\nDigite a quantidade de processos:\n";
	cin>>num_proc;
	TProcesso **processo = new TProcesso*[num_proc];
	TTarefa* tarefa;
	Inicializar_Tarefa(&tarefa);
	
	for(int i=0;i<num_proc;i++)
	{
		cout<<"\n\nDigite a quantidade de tarefas do processo "<<i+1<<" :\n";
		cin>>quant_tar;

		Inicializar_Processo(&processo[i],quant_tar);
		
		for(int j=0;j<quant_tar;j++)
		{
			cout<<"Digite o tipo da tarefa:1-CPU, 2-Memoria, 3-Disco.\n";
			cin>>tipo_tarefa;

			while(tipo_tarefa<1 || tipo_tarefa>3)
			{
				cout<<"\nTipo de tarefa invalido. FAVOR TENTAR NOVAMENTE....."<<endl;
				cout<<"\nDigite o tipo de tarefa:1-CPU, 2-Memoria, 3-Disco.\n";
				cin>>tipo_tarefa;
	
			}
			cout<<"Digite a demanda:\n";
			cin>>demanda;

			TTarefa_setRecurso(tarefa,tipo_tarefa);
			TTarefa_setDemanda(tarefa,demanda);
			AddTarefa(processo[i],tarefa);
        }
	}
	delete tarefa;
	
	//Escalonador do sistema!!
	for(int i=0; i<num_proc;i++)
	{
		for(int j=0;j<n_PC;j++)
		{
			//Flag para verificar se o computador consegue adicionar tal processo.
			int aceitar = 1;
			for(int k=1 ;k<4;k++)
			{
				int DEMANDA = result_demanda(processo[i],k);
				if(verificar_disponibilidade(comp[j],k,DEMANDA)==0)
				{
					aceitar = 0;
					break;
				}
			}
			if(aceitar==1)
			{
				processo[i]->maquina = j+1;
				addProcesso(comp[j],processo[i]);
				break;
			}
		}
	}
	
	for(int i=0;i<n_PC;i++)
	{
		executar_computador(comp[i],i);
		cout<<"Computador: "<<i+1<<" ,Processos "<<comp[i]->cont_processo<<" ,Tempo total "<<comp[i]->temp_total<<endl;
	}
	
	for(int j=0; j<num_proc;j++)
	{	
		cout<<"\nProcesso "<<j+1<<" : Computador "<<processo[j]->maquina<<" ,Tempo de execucao "<<processo[j]->temp_proc<<endl;	
	}
	
	for(int i=0;i<n_PC;i++)
	{
		liberar_memoria_computador(comp[i], quant_rec);
	}
	
	return 0;
}