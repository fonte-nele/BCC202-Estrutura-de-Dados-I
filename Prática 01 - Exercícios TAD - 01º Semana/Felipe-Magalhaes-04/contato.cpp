#include "contato.h"

void criar_contato (Contato **cont, string nome)
{
	int i=0;
	(*cont) = new Contato;
	(*cont) -> nome[i++] = nome;
}

void retornar_nome (Contato **cont, string nome)
{
	int j=0;
	for(int i=0; i<10; i++)
	{	
		if((*cont)->nome[i] == nome)
		{
			j++;
		}
	}
	if(j >= 1)
	{
		cout<<"\nO contato "<<nome<<" existe"<<endl<<endl;
	}
	else
	{
		cout<<"\nO contato "<<nome<<" nao existe."<<endl<<endl;
	}
}

void adicionar_telefone (Contato **cont, int num, int cod, string op, string classif)
{
	int i=0;
	(*cont) -> codigo[i++] = cod;
	(*cont) -> numero[i++] = num;
	(*cont) -> operadora[i++] = op;
	(*cont) -> classificacao[i++] = classif;
}

void modificar_nome (Contato **cont, string velha, string nova)
{
	int j=0;
	for(int i=0; i<10; i++)
	{
		if((*cont)->nome[i]==velha)
		{
			(*cont)->nome[i] = nova;
			j++;
		}
	}
	if(j==0)
	{
		cout<<"\nO nome do contato digitado nao consta na base de dados."<<endl;
	}
	else
	{
		cout<<"\nTroca de nomes efetuado com sucesso."<<endl;
	}
}

void liberar_memoria (Contato **cont)
{
	delete (*cont);
}