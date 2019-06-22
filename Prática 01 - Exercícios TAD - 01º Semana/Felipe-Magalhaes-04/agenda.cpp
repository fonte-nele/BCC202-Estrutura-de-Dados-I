#include "agenda.h"

void criar_agenda (Agenda **a,int quant)
{
	(*a) = new Agenda;
	(*a) -> quant = quant;
	(*a) -> cont = NULL;
}

void inserir_contato(Agenda **a, Contato **c)
{
	string nome,op,classif;
	int num,cod;
	cin>>num>>cod;
	getline(cin,nome);
	getline(cin,op);
	getline(cin,classif);
	criar_contato (c, nome);
	adicionar_telefone (c,num,cod,op,classif);
}

void buscar_contato(Agenda **a, string nome, Contato **cont)
{
	for(int i=0; i<10; i++)
	{	
		if((*cont)->nome[i] == nome)
		{
			cout<<"O contato "<<nome<<" existe.\n";
		}
	}	
}

int quantidade_contatos(Agenda **a)
{
	return (*a)->quant; 
}

int capacidade_agenda(Agenda **a, int num)
{
	return ((*a)-> quant - num);
}

void liberar_memoria (Agenda **a)
{
	delete (*a);
}