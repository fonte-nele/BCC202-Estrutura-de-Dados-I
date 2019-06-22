#include"pratica06.h"

void Inicializar(TNumero** num,int n)
{
	(*num) = new TNumero[n];
}

void Inserir(TNumero* v1,TNumero* v2,TNumero* v3,int n)
{
	int i;
	for(i=0; i<n;i++)
	{
		cout<<"\nPreencha o vetor, posicao "<<i+1<<" :"<<endl;
		cin>>v1[i].chave;
		v2[i].chave=v1[i].chave;
		v3[i].chave=v1[i].chave;
	}
}

void Bolha(TNumero* num,int n,int *comp,int *mov)
{
	int i,j,troca;
	TNumero aux;
	for(i=0;i<n-1;i++)
	{
		troca=0;
		for(j=1;j<n-i;j++)
		{
			(*comp)++;
			if(num[j].chave<num[j-1].chave)
			{
				aux=num[j];
				num[j]=num[j-1];
				num[j-1]=aux;
				troca++;
				(*mov)+=3;
			}
		}
		if(troca==0)
		{
			break;
		}
	}
}

void Selection(TNumero* num,int n,int *comp,int *mov)
{
	int i,j,min;
	TNumero aux;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			(*comp)++;
			if(num[j].chave<num[min].chave)
			{
				min=j;
			}
			if(i!=min)
			{
				aux=num[min];
				num[min]=num[i];
				num[i]=aux;
				(*mov)+=3;
			}
		}
	}
}

void Insertion(TNumero* num,int n,int *comp,int *mov)
{
	int i,j;
	TNumero aux;
	//Sem sentinela.
	for(i=1;i<n;i++)
	{
		aux=num[i];
		j=i-1;
		if(aux.chave>num[j].chave)
		{
			(*comp)++;
		}
		while(j>=0 && aux.chave<num[j].chave)
		{
			num[j+1]=num[j];
			j--;
			(*comp)++;
			(*mov)++;
		}
		num[j+1]=aux;
	}
}

void Imprimir(TNumero* num,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<num[i].chave<<" ";
	}
}

void Liberar_memoria(TNumero* num)
{
	delete []num;
}