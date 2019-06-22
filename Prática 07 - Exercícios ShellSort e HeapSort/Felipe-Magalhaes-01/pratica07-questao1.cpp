#include"pratica07-questao1.h"

void Inicializar(TNumero** num,int n)
{
	(*num) = new TNumero[n];
}

void Inserir(TNumero* v1,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"\nPreencha o vetor, posicao "<<i+1<<" :"<<endl;
		cin>>v1[i].chave;
	}
}

void Copiar_Vetores(TNumero* v,TNumero* aux,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		aux[i].chave=v[i].chave;
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
				mov[0]+=3;
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
			comp[1]+=1;
			if(num[j].chave<num[min].chave)
			{
				min=j;
			}
			if(i!=min)
			{
				aux=num[min];
				num[min]=num[i];
				num[i]=aux;
				mov[1]+=3;
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
			comp[2]+=1;
		}
		while(j>=0 && aux.chave<num[j].chave)
		{
			num[j+1]=num[j];
			j--;
			comp[2]+=1;
			mov[2]+=1;
		}
		num[j+1]=aux;
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
			comp[3]+=1;
		}
		else
		{		
			if(j==b_tam)
			{
				v[k]=a[i++];
				comp[3]+=1;
			}
			else
			{
				comp[3]+=1;
				if(a[i].chave<b[j].chave)
				{
					v[k]=a[i++];
					mov[3]+=1;	
				}
				else
				{
					v[k]=b[j++];
					mov[3]+=1;
				}
			}
		}
	}
	delete []a;
	delete []b;
}

void QuickSort(TNumero* v,int n,int* comp,int* mov)
{
	QuickSort_ordena(v,0,n-1,comp,mov);
}

void QuickSort_ordena(TNumero* v,int esq,int dir,int* comp,int* mov)
{
	int i,j;
	QuickSort_particao(v,esq,dir,&i,&j,comp,mov);
	if(esq<j)
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
		while(!(pivo.chave<=v[*i].chave))
		{
			(*i)++;
			comp[4]+=1;
		}
		while(pivo.chave<v[*j].chave)
		{
			(*j)--;
			comp[4]+=1;
		}
		if(*i<=*j)
		{
			aux=v[*i];
			v[*i]=v[*j];
			v[*j]=aux;
			(*i)++;
			(*j)--;
			comp[4]+=1;
			mov[4]+=3;
		}
	}while(*i<=*j);
}

void ShellSort01(TNumero* num,int n,int* comp,int* mov)
{
	int i,j,h;
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
			mov[5]+=1;
			comp[5]+=1;
			while(num[j-h].chave>aux.chave)
			{
				mov[5]+=1;
				num[j]=num[j-h];
				j-=h;
				if(j<h)
				{
					break;
				}
			}
			num[j]=aux;
			mov[5]+=1;
		}
	}while(h!=1);
}

void ShellSort02(TNumero* num,int n,int* comp,int* mov)
{
	int i,j,h;
	TNumero aux;
	//Sequencia de HIBBARD-1963!!!
	//1,3,7,15,31,63...
	//Fonte: Wikipedia
	for(h=1;h<n;h=2*h+1);
	
	do{
		h=(h-1)/3;
		for(i=h;i<n;i++)
		{
			aux=num[i];
			j=i;
			mov[6]+=1;
			comp[6]+=1;
			while(num[j-h].chave>aux.chave)
			{
				mov[6]+=1;
				num[j]=num[j-h];
				j-=h;
				if(j<h)
				{
					break;
				}
			}
			num[j]=aux;
			mov[6]+=1;
		}
	}while(h!=1);
}

void ShellSort03(TNumero* num,int n,int* comp,int* mov)
{
	int i,j,h;
	TNumero aux1;
	//Sequencia de PAPERNOV & STASEVICH - 1965!!!
	//1,3,5,9,17,33,65...
	//Fonte: Wikipedia
	for(h=3;h<n;h=2*h-1);
	
	do{
		h=(h-1)/3;
		for(i=h;i<n;i++)
		{
			aux1=num[i];
			j=i;
			mov[7]+=1;
			comp[7]+=1;
			while(num[j-h].chave>aux1.chave)
			{
				mov[7]+=1;
				num[j]=num[j-h];
				j-=h;
				if(j<h)
				{
					break;
				}
			}
			num[j]=aux1;
			mov[7]+=1;
		}
	}while(h!=1);
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