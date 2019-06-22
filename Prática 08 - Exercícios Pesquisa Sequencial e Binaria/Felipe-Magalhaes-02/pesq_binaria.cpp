#include"pesq_binaria.h"

void TContato_Construir_Binario(TContato* contato)
{
	contato->n=0;
	contato->max=100;
	contato->v=new TDados[contato->max];
}

void TContato_Inserir_Binario(TContato* contato,TDados* dados)
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

int TContato_Pesquisar_Binario(TContato* contato,unsigned long int pesq,int *comp2)
{
	return TContato_Binaria(contato,0,contato->n-1,pesq,comp2);
}

int TContato_Binaria(TContato* contato,int esq,int dir,unsigned long int pesq,int *comp2)
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
			(*comp2)++;
			return TContato_Binaria(contato,meio+1,dir,pesq,comp2);
		}
		else
		{
			if(pesq<contato->v[meio].telefone)
			{
				(*comp2)++;
				return TContato_Binaria(contato,esq,meio-1,pesq,comp2);
			}
			else
			{
				(*comp2)++;
				return meio;
			}
		}
	}
}