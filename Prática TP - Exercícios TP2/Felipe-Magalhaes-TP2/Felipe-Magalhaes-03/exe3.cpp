#include"exe3.h"

void Inicializar(TNumero** num)
{
	(*num) = new TNumero[n];
}

void Copiar_Vetor(TNumero* v,TNumero* aux)
{
	long int i;
	for(i=0;i<n;i++)
	{
		aux[i].chave=v[i].chave;
	}
}

void Bolha(TNumero* num,unsigned long int *comp,unsigned long int *mov,int pos)
{
	long int i,j;
	int troca;
	TNumero aux;
	for(i=0;i<n-1;i++)
	{
		troca=0;
		for(j=1;j<n-i;j++)
		{
			comp[pos]+=1;
			if(num[j].chave<num[j-1].chave)
			{
				aux=num[j];
				num[j]=num[j-1];
				num[j-1]=aux;
				troca++;
				mov[pos]+=3;
			}
		}
		if(troca==0)
		{
			break;
		}
	}
}

void Selection(TNumero* num,unsigned long int *comp,unsigned long int *mov,int pos)
{
	long int i,j,min;
	TNumero aux;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			comp[pos]+=1;
			if(num[j].chave<num[min].chave)
			{
				min=j;
			}
			if(i!=min)
			{
				aux=num[min];
				num[min]=num[i];
				num[i]=aux;
				mov[pos]+=3;
			}
		}
	}
}

void Insertion(TNumero* num,unsigned long int *comp,unsigned long int *mov,int pos)
{
	long int i,j;
	TNumero aux;
	//Sem sentinela.
	for(i=1;i<n;i++)
	{
		aux=num[i];
		j=i-1;
		if(aux.chave>num[j].chave)
		{
			comp[pos]+=1;
		}
		while(j>=0 && aux.chave<num[j].chave)
		{
			num[j+1]=num[j];
			j--;
			comp[pos]+=1;
			mov[pos]+=1;
		}
		num[j+1]=aux;
	}
}

void MergeSort(TNumero* v,unsigned long int* comp,unsigned long int* mov,int pos)
{
	MergeSort_ordena(v,0,n-1,comp,mov,pos);
}

void MergeSort_ordena(TNumero* v,long int esq,long int dir,unsigned long int* comp,unsigned long int* mov,int pos)
{
	if(esq>=dir)
	{
		return;
	}
	int meio= (esq + dir)/2;
	MergeSort_ordena(v,esq,meio,comp,mov,pos);
	MergeSort_ordena(v,meio+1,dir,comp,mov,pos);
	MergeSort_intercala(v,esq,meio,dir,comp,mov,pos);
	return;
}

void MergeSort_intercala(TNumero* v,long int esq,long int meio,long int dir,unsigned long int *comp,unsigned long int *mov,int pos)
{
	long int i,j,k;
	TNumero* a;
	TNumero* b;
	long int a_tam = meio -esq+1;
	long int b_tam = dir - meio;
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
			comp[pos]+=1;
		}
		else
		{		
			if(j==b_tam)
			{
				v[k]=a[i++];
				comp[pos]+=1;
			}
			else
			{
				comp[pos]+=1;
				if(a[i].chave<b[j].chave)
				{
					v[k]=a[i++];
					mov[pos]+=1;	
				}
				else
				{
					v[k]=b[j++];
					mov[pos]+=1;
				}
			}
		}
	}
	delete []a;
	delete []b;
}

void QuickSort(TNumero* v,unsigned long int* comp,unsigned long int* mov,int pos)
{
	QuickSort_ordena(v,0,n-1,comp,mov,pos);
}

void QuickSort_ordena(TNumero* v,long int esq,long int dir,unsigned long int* comp,unsigned long int* mov,int pos)
{
	long int i,j;
	QuickSort_particao(v,esq,dir,&i,&j,comp,mov,pos);
	if(esq<j)
	{
		QuickSort_ordena(v,esq,j,comp,mov,pos);
	}
	if(i<dir)
	{
		QuickSort_ordena(v,i,dir,comp,mov,pos);
	}
}

void QuickSort_particao(TNumero* v,long int esq,long int dir,long int *i,long int *j,unsigned long int *comp,unsigned long int *mov,int pos)
{
	TNumero pivo,aux;
	*i=esq;
	*j=dir;
	pivo=v[(*i+*j)/2];
	do{
		while(!(pivo.chave<=v[*i].chave))
		{
			(*i)++;
			comp[pos]+=1;
		}
		while(pivo.chave<v[*j].chave)
		{
			(*j)--;
			comp[pos]+=1;
		}
		if(*i<=*j)
		{
			aux=v[*i];
			v[*i]=v[*j];
			v[*j]=aux;
			(*i)++;
			(*j)--;
			comp[pos]+=1;
			mov[pos]+=3;
		}
	}while(*i<=*j);
}

void ShellSort(TNumero* num,unsigned long int* comp,unsigned long int* mov,int pos)
{
	long int i,j,h;
	TNumero aux;
	//Sequencia de KNUTH-1973!!!
	//1,4,13,40,121...
	for(h=1;h<n;h=3*h+1);
	
	do{
		h=(h-1)/3;
		for(i=h;i<n;i++)
		{
			aux=num[i];
			j=i;
			mov[pos]+=1;
			comp[pos]+=1;
			while(num[j-h].chave>aux.chave)
			{
				mov[pos]+=1;
				num[j]=num[j-h];
				j-=h;
				if(j<h)
				{
					break;
				}
			}
			num[j]=aux;
			mov[pos]+=1;
		}
	}while(h!=1);
}

void Liberar_memoria(TNumero* num)
{
	delete []num;
}