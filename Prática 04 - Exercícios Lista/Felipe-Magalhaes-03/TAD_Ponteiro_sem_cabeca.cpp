#include "TAD_Ponteiro_sem_cabeca.h"

void Inicializar_TConta(TConta** dados)
{
	(*dados) = new TConta;
}

void Inicializar_TLista(TLista** lista)
{
	(*lista) = new TLista;
}

void TLista_Inicia(TLista* lista)
{
	lista -> primeiro = NULL;
	lista -> ultimo = NULL;
}

bool TLista_EhVazia(TLista* lista)
{
	if(lista->primeiro == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TLista_Insere(TLista* lista,TConta* conta)
{
	TCelula *novo = new TCelula;
	novo -> item.num_conta = conta->num_conta;
	novo -> item.saldo = conta->saldo;
	
	novo -> prox = NULL;
	if(TLista_EhVazia(lista))
	{
		lista->primeiro = novo;
		lista->ultimo = novo;
	}
	else
	{
		lista->ultimo->prox = novo;
		lista->ultimo = novo;
	}
	return true;
}

bool TLista_RetiraPrimeiro(TLista* lista,TConta* conta)
{
	if(TLista_EhVazia(lista))
	{
		return false;
	}
	TCelula *aux;
	aux = lista->primeiro;
	*conta = aux->item;
	lista->primeiro = lista->primeiro->prox;
	delete aux;
	if(lista->primeiro == NULL)
	{
		lista->ultimo = NULL;
		//Lista vazia!!!
	}
	return true;
}

void TLista_Imprimir(TLista* lista)
{
	int i=1;
	TCelula* aux;
	aux = lista->primeiro;
	cout<<"\nOs dados na lista sao:\n";
	while(aux != NULL)
	{
		cout<<"\nCONTA BANCARIA "<<i<<" : "<<aux->item.num_conta<<endl;
		cout<<"SALDO: "<<aux->item.saldo<<endl<<endl;
		aux = aux->prox;
		i++;
	}
	
	
}

void liberar_memoria_TConta(TConta* dados)
{
	delete dados;
}

void liberar_memoria_TLista(TLista* lista)
{
	delete lista;
}