#include <iostream>
#include "email.h"
#include "agenda.h"
#include "contato.h"

int main()
{
	int cod, num,n,i,j,tel,maximo,l,k=1;
	string nome1,op,classif,nome2,nome3,nome4,email1;
	Contato *cont;
	Email *email;
	Agenda *agenda;
	cout<<"\nDigite a quantidade maxima de contatos para a agenda:\n";
	cin>>maximo;
	criar_agenda (&agenda, maximo);
	for(i=0;i<maximo;i++)
	{
		cout<<"\nDigite o primeiro nome de um contato para adicionar:\n";
		cin.ignore();
		getline(cin,nome1);
		criar_contato(&cont,nome1);
		cout<<"\nQuantos telefones o contato possui?\n";
		cin>>tel;
		for(l=0;l<tel;l++)
		{
			cout<<"\nDigite o codigo,numero(somente numeros),operadora e classificacao do celular "<<l+1<<" :\n";
			cin>>cod>>num;
			cin.ignore();
			getline(cin,op);
			getline(cin,classif);
			adicionar_telefone (&cont,num,cod,op,classif);
		}
		cout<<"\nQuantos emails esse contato possui?\n";
		cin>>n;
		for(j=0;j<n;j++)
		{
			cout<<"\nDigite o email do contato:\n";
			cin.ignore();
			getline(cin,email1);
			adicionar_email(&email,email1,n);
		}
		
		cout<<"\nA capacidade restante da agenda eh de: "<<capacidade_agenda(&agenda,k)<<" contatos.\n";
		cout<<"\nO numero de contatos cadastrados eh: "<<(maximo - capacidade_agenda(&agenda,k))<<endl;
		k++;
	}
	cin.ignore();
	cout<<"\nDigite o nome para pesquisar se ha contato cadastrado:\n";
	getline(cin,nome2);
	retornar_nome(&cont, nome2);
	cout<<"\nDigite o nome do contato cadastrado e um nome que deseja altera-lo:\n";
	getline(cin,nome3);
	getline(cin,nome4);
	modificar_nome(&cont, nome3, nome4);
	cout<<"\nA capacidade restante da agenda eh de: "<<capacidade_agenda(&agenda,k-1)<<" contatos.\n";
	cout<<"\nO numero de contatos cadastrados eh: "<<(maximo - capacidade_agenda(&agenda,k-1))<<endl;
	return 0;
}