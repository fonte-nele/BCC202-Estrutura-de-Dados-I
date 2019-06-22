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
	return TContato_Binaria(contato,0,contato->n-1,pesq,comp);
}

int TContato_Binaria(TContato* contato,int esq,int dir,unsigned long int pesq,int *comp)
{
	int meio = (esq+dir)/2;
	if(contato->v[meio].telefone!=pesq && esq>=dir)
	{
		return -1;
	}
	else
	{
		if(pesq>contato->v[meio].telefone)
		{
			(*comp)++;
			return TContato_Binaria(contato,meio+1,dir,pesq,comp);
		}
		else
		{
			if(pesq<contato->v[meio].telefone)
			{
				(*comp)++;
				return TContato_Binaria(contato,esq,meio-1,pesq,comp);
			}
			else
			{
				(*comp)++;
				return meio;
			}
		}
	}
}