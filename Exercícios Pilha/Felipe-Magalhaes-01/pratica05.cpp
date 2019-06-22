#include"pratica05.h"
#include<cmath>

void Inicializar_TCalc(TCalc** conta)
{
	(*conta) = new TCalc;
}

void Inicializar_TPilha(TPilha** pilha)
{
	(*pilha) = new TPilha;
}

int Menu()
{
	int escolha;
	cout<<endl;
	cout<<"  ======================MENU CALCULADORA======================"<<endl;
	cout<<" ||                                                          ||"<<endl;
    cout<<" ||                                                          ||"<<endl;
	cout<<" || 1 - Empilhar numero na pilha.                            ||"<<endl;
    cout<<" || 2 - Escolher sinal(+,-,*,/ ou ^) para operacao na pilha. ||"<<endl;
    cout<<" || 3 - Escolher sinal '='(IMPRIMIR RESULTADO).              ||"<<endl;
	cout<<" || 4 - Escolher sinal ';'(SAIR).                            ||"<<endl;
	cout<<" ||                                                          ||"<<endl;
	cout<<"  ======================MENU CALCULADORA======================"<<endl;
    cout<<endl;
	cout<<"  Escolha: ";  
	cin>>escolha;
    cin.ignore();
    return escolha;
}

void TPilha_Inicia(TPilha* pilha)
{
	pilha -> topo = new TCelula;
	pilha -> fundo = pilha -> topo;
	pilha -> topo -> prox = NULL;
	pilha -> tamanho = 0;
}

bool TPilha_EhVazia(TPilha* pilha)
{
	if(pilha->fundo == pilha->topo)
	{
		if(pilha->tamanho == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void TPilha_Push(TPilha* pilha, TCalc* conta)
{
	TCelula* aux;
	aux = new TCelula;
	pilha->topo->item.num = conta->num;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;
}

double TPilha_Pop(TPilha* pilha, TCalc* conta)
{
	double valor;
	valor = pilha->topo->prox->item.num;
	TCelula* aux;
	aux = pilha->topo;
	pilha->topo = aux->prox;
	conta->num = aux->prox->item.num;
	delete aux;
	pilha->tamanho--;
	return valor;
}

int TPilha_Tamanho(TPilha* pilha)
{
	return pilha->tamanho;
}

void TPilha_Limpa(TPilha* pilha)
{
	TCalc conta;
	if(TPilha_EhVazia(pilha))
	{
		cout<<endl;
	}
	else
	{
		while(TPilha_Pop(pilha,&conta));
		cout<<endl;
	}
}

void TPilha_Imprimir(TPilha* pilha)
{
	int i=1;
	TCelula *aux;
	aux = pilha->topo->prox;
	if(TPilha_EhVazia(pilha))
	{
		cout<<"\nENTRADA INCOSISTENTE."<<endl;
	}
	else
	{
		cout<<"\nOs dados na pilha sao:"<<endl<<endl;
		while(aux != NULL)
		{
			cout<<"NUMERO: "<<aux->item.num<<endl<<endl;
			aux = aux->prox;
			i++;
		}
	}	
}

void liberar_memoria_TCalc(TCalc* conta)
{
	delete conta;
}

void liberar_memoria_TPilha(TPilha* pilha)
{
	delete pilha;
}