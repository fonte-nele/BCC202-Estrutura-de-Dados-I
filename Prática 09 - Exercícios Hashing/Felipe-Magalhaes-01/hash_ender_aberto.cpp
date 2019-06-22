#include "hash_ender_aberto.h"

void Hash_Inicia_Aberto(Enderecamento end,pesos pes)
{
	int i;
	for(i=0; i<10; i++)
	{
		end[i].chave[i] = 0;
	}
	for(i=0;i<10;i++)
	{
		pes[i] = rand() %100;
	}
}

int h(int *m,int *p)
{
	int i;
	unsigned int soma=0;
	
	for(i=0; i<10; i++)
	{
		soma += m[i] * p[i];
	}
	return (soma % tam2);
}

int Enderecamento_Pesquisa(Enderecamento end,int *chave,pesos p)
{
	int i = 0;
	int ini = h(chave,p);
	
	while(end[(ini+i)%tam].chave != chave && i<tam)
	{
		i++;
	}
	if(end[(ini+i)%tam].chave != chave)
	{
		return (ini+i) % tam;
	}
	//Pesquisa sem sucesso!!!
	return -1;
}

int Enderecamento_Insere(Enderecamento end,TItemEnd item,pesos p)
{
	if(Enderecamento_Pesquisa(end,item.chave,p)== -1)
	{
		//Chave ja existe!!!
		return 0;
	}
	int i = 0;
	int ini = h(item.chave,p);
	
	if(i<tam)
	{
		end[(ini+i)%tam] = item;
		return 1;
	}
	return 0;
}

void Enderecamento_Pesquisa2(Enderecamento end,int *chave, pesos pes)
{
	int result;
	result = Enderecamento_Pesquisa(end,chave,pes);
	if(result==-1)
	{
		cout<<endl;
		cout<<"TABELA HASH(ENDERECAMENTO ABERTO):"<<endl;
		for(int k=0; k<10; k++)
		{
			cout<<chave[k];
		}
		cout<<endl;
		cout<<"NAO ENCONTRADO -1 1"<<endl;
	}
}