#include"mergesort.h"

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

void MergeSort(TNumero* v,int n,int* comp,int* mov)
{
	MergeSort_ordena(v,0,n-1,comp,mov);
}

void MergeSort_ordena(TNumero* v,int esq,int dir,int* comp,int* mov)
{
	if(esq>=dir)
	{
		return;
	}
	int meio= (esq + dir)/2;
	MergeSort_ordena(v,esq,meio,comp,mov);
	MergeSort_ordena(v,meio+1,dir,comp,mov);
	MergeSort_intercala(v,esq,meio,dir,comp,mov);
	return;
}

void MergeSort_intercala(TNumero* v,int esq,int meio,int dir,int *comp,int *mov)
{
	int i,j,k;
	TNumero* a;
	TNumero* b;
	int a_tam = meio -esq+1;
	int b_tam = dir - meio;
	a = new TNumero[a_tam];
	b = new TNumero[b_tam];
	for(i=0;i<a_tam;i++)
	{
		a[i]=v[i+esq];
	}
	for(i=0;i<b_tam;i++)
	{
		b[i]=v[i+meio+1];
	}
	for(i=0,j=0,k=esq;k<=dir;k++)
	{
		if(i==a_tam)
		{
			v[k]=b[j++];
			(*mov)++;
		}
		else
		{
			if(j==b_tam)
			{
				v[k]=a[i++];
				(*mov)++;
			}
			else
			{
				if(a[i].chave<b[j].chave)
				{
					v[k]=a[i++];
					(*mov)++;
					(*comp)++;
				}
				else
				{
					v[k]=b[j++];
					(*mov)++;
					(*comp)++;
				}
			}
		}
	}
	delete []a;
	delete []b;
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