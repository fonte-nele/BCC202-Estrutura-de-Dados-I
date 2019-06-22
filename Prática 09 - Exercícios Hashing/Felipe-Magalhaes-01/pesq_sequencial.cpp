#include"pesq_sequencial.h"

void TContato_Construir_Sequencial(TContato* contato)
{
	contato->n=0;
	contato->max=100;
	contato->v=new TDados[contato->max];
}

void TContato_Inserir_Sequencial(TContato* contato,TDados* dados)
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
	cout<<"\nPESQUISA SEQUENCIAL:"<<endl;
	for(i=contato->n-1;i>=0;i--)
	{
		comp++;
		if(contato->v[i].telefone==pesq)
		{
			aux++;
			cout<<pesq<<endl;
			cout<<contato->v[i].nome<<" "<<setfill('0')<<setw(4)<<contato->v[i].niver<<" "<<i<<" "<<comp<<endl;
			break;
		}
	}
	if(aux==-1)
	{
		cout<<pesq<<endl;
		cout<<"NAO ENCONTRADO "<<aux<<" "<<comp<<endl;
	}
}