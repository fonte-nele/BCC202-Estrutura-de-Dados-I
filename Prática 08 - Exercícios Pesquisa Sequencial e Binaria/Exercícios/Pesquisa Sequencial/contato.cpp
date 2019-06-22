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

void TContato_Pesquisar(TContato* contato,unsigned long int pesq)
{
	int i,comp=0,aux=-1;
	for(i=contato->n-1;i>=0;i--)
	{
		comp++;
		if(contato->v[i].telefone==pesq)
		{
			aux++;
			cout<<endl<<pesq<<endl;
			cout<<contato->v[i].nome<<" "<<setfill('0')<<setw(4)<<contato->v[i].niver<<" "<<i<<" "<<comp<<endl;
			break;
		}
	}
	if(aux==-1)
	{
		cout<<endl<<pesq<<endl;
		cout<<"NAO ENCONTRADO "<<aux<<" "<<comp<<endl;
	}
}