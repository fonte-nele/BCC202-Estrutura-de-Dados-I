#include "hash_lista_encadeada.h"

void THash_Inicia(THash *hash,int num1,int num2)
{
	int i;
	hash->n = 0;
	hash->num_listas = num1;
	hash->num_pesos = num2;
	
	hash->vetor_listas = new TLista[num1];
	for(i=0; i<num1; i++)
	{
		TLista_Inicia(&hash->vetor_listas[i]);
	}
	
	hash->vetor_pesos = new int [num2];
	for(i=0; i<num2; i++)
	{
		hash->vetor_pesos[i] = rand() % 1000;
	}
}

int THash_H(THash *hash,int *chave)
{
	int i;
	unsigned int soma=0;
	
	for(i=0; i<10; i++)
	{
		soma += chave[i] * hash->vetor_pesos[i%hash->num_pesos];
	}
	return (soma % hash->num_listas);
}

void THash_Pesquisa(THash *hash,int *chave,TItem *x)
{
	int comp=0,flag=0;
	TCelula *aux = THash_PesquisaCelula(hash,chave,&comp);
	if(aux == NULL)
	{
		flag++;
		cout<<endl;
		cout<<"TABELA HASH(LISTA ENCADEADA):"<<endl;
		for(int i=0; i<10; i++)
		{
			cout<<chave[i];
		}
		cout<<endl;
		cout<<"NAO ENCONTRADO -1 "<<comp<<endl;
	}
	if(flag==0)
	{
		*x = aux->prox->item;
		cout<<endl;
		cout<<"TABELA HASH(LISTA ENCADEADA):"<<endl;
		cout<<aux->prox->item.contato_hash.telefone<<endl;
		cout<<aux->prox->item.contato_hash.nome<<" "<<setfill('0')<<setw(4)<<aux->prox->item.contato_hash.niver<<" 1 "<<comp<<endl;
	}
}

TCelula* THash_PesquisaCelula(THash *hash,int *pesq, int *comp)
{
	int i = THash_H(hash,pesq);
	TCelula *aux;

	if(TLista_EhVazia(&hash->vetor_listas[i]))
	{
		(*comp)++;
		return NULL;
	}
	aux = hash->vetor_listas[i].primeiro;
	while(aux->prox->prox != NULL && pesq==aux->prox->item.chave)
	{
		(*comp)++;
		aux = aux->prox;
	}
	if(pesq!=aux->prox->item.chave)
	{
		(*comp)++;
		return aux;
	}
	else
	{
		return NULL;
	}
}

bool THash_Insere(THash *hash,TItem *x)
{
	int comp=0;
	if(THash_PesquisaCelula(hash,x->chave,&comp)==NULL)
	{
		TLista_Insere(&hash->vetor_listas[THash_H(hash,x->chave)],x);
		hash->n++;
		return true;
	}
	return false;
}

bool TLista_EhVazia(TLista* lista)
{
	if(lista->ultimo == lista->primeiro)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TLista_Inicia(TLista* lista)
{
	lista -> primeiro = new TCelula;
	lista -> ultimo = lista -> primeiro;
	lista -> primeiro -> prox = NULL;
}

void TLista_Insere(TLista* lista,TItem* x)
{
	lista -> ultimo->prox = new TCelula;
	lista -> ultimo = lista -> ultimo->prox;
	lista -> ultimo->item.contato_hash.nome = x->contato_hash.nome;
	lista -> ultimo->item.contato_hash.niver = x->contato_hash.niver;
	lista -> ultimo->item.contato_hash.telefone = x->contato_hash.telefone;
	lista -> ultimo->prox = NULL;
}