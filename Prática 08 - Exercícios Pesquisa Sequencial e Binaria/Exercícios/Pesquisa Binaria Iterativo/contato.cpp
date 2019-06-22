#include"contato.h"
#include<iomanip>

void TContato_Construir(TContato* contato)
{
	contato->n=0;
	contato->max=100;
	contato->v=new TDados[contato->max];
}

void TContato_Inserir(TContato* contato,TDados* dados)
{
	if(contato->n==contato->max)
	{
		cout<<"\nNAO EH POSSIVEL INSERIR CONTATO, MEMORIA CHEIA."<<endl;
	}
	contato->v[contato->n].nome=dados->nome;
	contato->v[contato->n].niver=dados->niver;
	contato->v[contato->n].telefone=dados->telefone;
	contato->n++;
}

int TContato_Pesquisar(TContato* contato,unsigned long int pesq,int *comp)
{
	int i,esq,dir;
	if(contato->n==0)
	{
		return -1;
	}
	esq=0;
	dir=contato->n-1;
	do{
		i=(esq+dir)/2;
		if(pesq>contato->v[i].telefone)
		{
			esq=i+1;
		}
		else
		{
			dir=i-1;
		}
		(*comp)++;
	}while(pesq!=contato->v[i].telefone && esq<=dir);
	
	if(pesq==contato->v[i].telefone)
	{
		return i;
	}
	else
	{
		return -1;
	}
}