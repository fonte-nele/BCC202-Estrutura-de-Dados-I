#include"exe3.h"

void TPilha_Inicia(TPilha* pilha)
{
	pilha -> topo = new TCelula;
	pilha -> fundo = pilha -> topo;
	pilha -> topo -> prox = NULL;
	pilha -> tamanho = 0;
}

bool TPilha_EhVazia(TPilha* pilha)
{
	if(pilha->fundo == pilha->topo)
	{
		if(pilha->tamanho == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void TPilha_Empilha(TPilha* pilha, int numero)
{
	TCelula* aux;
	aux = new TCelula;
	pilha->topo->item.chave = numero;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;
}

void TPilha_Desempilha(TPilha* pilha, int* numero)
{
	if(TPilha_EhVazia(pilha))
	{
		cout<<"\nLISTA VAZIA...."<<endl;
	}
	TCelula *aux;
	aux = pilha->topo;
	pilha->topo = aux->prox;
	*numero = aux->prox->item.chave;
	delete aux;
	pilha->tamanho--;
}

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

void QuickSort_iter(TNumero* v,int n)
{
	TPilha pilha_dir,pilha_esq;
	int esq,dir,i,j;
	TPilha_Inicia(&pilha_dir);
	TPilha_Inicia(&pilha_esq);
	esq=0;
	dir=n-1;
	TPilha_Empilha(&pilha_dir,dir);
	TPilha_Empilha(&pilha_esq,esq);
	do{
		if(dir>esq)
		{
			QuickSort_particao(v,esq,dir,&i,&j);
			TPilha_Empilha(&pilha_dir,j);
			TPilha_Empilha(&pilha_esq,esq);
			esq=i;
		}
		else
		{
			TPilha_Desempilha(&pilha_dir,&dir);
			TPilha_Desempilha(&pilha_esq,&esq);
		}
	}while(!TPilha_EhVazia(&pilha_dir));
}

void QuickSort_particao(TNumero* v,int esq,int dir,int *i,int *j)
{
	TNumero pivo,aux;
	*i=esq;
	*j=dir;
	pivo=v[(*i+*j)/2];
	do{
		while(!(pivo.chave<=v[*i].chave))
		{
			(*i)++;
		}
		while(pivo.chave<v[*j].chave)
		{
			(*j)--;
		}
		if(*i<=*j)
		{
			aux=v[*i];
			v[*i]=v[*j];
			v[*j]=aux;
			(*i)++;
			(*j)--;
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