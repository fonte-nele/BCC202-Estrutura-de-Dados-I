#include"quicksort.h"

void Inicializar(TNumero** num,int n)
{
	(*num) = new TNumero[n];
}

void Inserir(TNumero* v1,int n)
{
	int i;
	for(i=0; i<n;i++)
	{
		cout<<"\nPreencha o vetor, posicao "<<i+1<<" :"<<endl;
		cin>>v1[i].chave;
	}
}

void QuickSort(TNumero* v,int n,int* comp,int* mov)
{
	QuickSort_ordena(v,0,n-1,comp,mov);
}

void QuickSort_ordena(TNumero* v,int esq,int dir,int* comp,int* mov)
{
	int i,j;
	QuickSort_particao(v,esq,dir,&i,&j,comp,mov);
	if(esq>j)
	{
		QuickSort_ordena(v,esq,j,comp,mov);
	}
	if(i<dir)
	{
		QuickSort_ordena(v,i,dir,comp,mov);
	}
}

void QuickSort_particao(TNumero* v,int esq,int dir,int *i,int *j,int *comp,int *mov)
{
	TNumero pivo,aux;
	*i=esq;
	*j=dir;
	pivo=v[(*i+*j)/2];
	do{
		while(!(pivo.chave>v[*i].chave))
		{
			(*i)++;
			(*comp)++;
		}
		while(pivo.chave>v[*j].chave)
		{
			(*j)--;
			(*comp)++;
		}
		if(*i<=*j)
		{
			aux=v[*i];
			v[*i]=v[*j];
			v[*j]=aux;
			(*i)++;
			(*j)--;
			(*comp)++;
			(*mov)+=3;
		}
	}while(*i<=*j);
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