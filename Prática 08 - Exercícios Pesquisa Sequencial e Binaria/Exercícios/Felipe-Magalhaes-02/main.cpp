/*
	Feito por: Felipe Fontenele de Ávila Magalhães
	Data: 13/01/2016
	Disciplina: Estrutura de Dados I
*/
#include"contato.h"
#include"pesq_sequencial.h"
#include"pesq_binaria.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 1                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se os conceitos de pesquisa sequencial e binaria. O programa    ||"<<endl;
	cout<<"  || eh uma agenda, na qual insere contatos com os seguintes campos: nome, telefone e niver.  ||"<<endl;
	cout<<"  || Logo apos, eh feito uma pesquisa sequencial e binaria nos contatos de acordo com um tel. ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	TContato* contato, *contato2;
	TDados* dados;
	contato = new TContato;
	contato2 = new TContato;
	dados = new TDados;
	int i,j,num_casos,num_contatos,quant_pesq,pos,comp2=0;
	unsigned long int numero_tel;
	TContato_Construir_Sequencial(contato);
	TContato_Construir_Binario(contato2);
	cout<<"\nDigite o numero de casos para teste:\n";
	cin>>num_casos;
	for(i=0;i<num_casos;i++)
	{
		cout<<"\nDigite a quantidade de contatos que deseja inserir:\n";
		cin>>num_contatos;
		cout<<"\nDigite o numero de pesquisas a serem feitas:\n";
		cin>>quant_pesq;
		for(j=0;j<num_contatos;j++)
		{
			cout<<"\n\nCONTATO "<<j+1<<" :"<<endl;
			cout<<"\nDigite o nome do contato(SEM ESPACOS):"<<endl;
			cin>>dados->nome;
			cout<<"\nDigite a data de aniversario do contato(MMDD):"<<endl;
			cin>>dados->niver;
			cout<<"\nDigite o numero de telefone do contato(SOMENTE NUMEROS) :"<<endl;
			cin>>dados->telefone;
			TContato_Inserir_Sequencial(contato,dados);
			TContato_Inserir_Binario(contato2,dados);
		}
		for(j=0;j<quant_pesq;j++)
		{
			cout<<"\n\nPESQUISA "<<j+1<<" :"<<endl;
			cout<<"\nDigite o numero de telefone(SOMENTE NUMEROS) que deseja pesquisar:\n";
			cin>>numero_tel;
			TContato_Pesquisar_Sequencial(contato,numero_tel);
			pos=TContato_Pesquisar_Binario(contato2,numero_tel,&comp2);
			cout<<"\nPESQUISA BINARIA:"<<endl;
			if(pos==-1)
			{
				cout<<endl<<numero_tel;
				cout<<"\nNAO ENCONTRADO "<<-1<<" "<<comp2<<endl;
				comp2=0;
			}
			else
			{
				cout<<endl<<numero_tel<<endl;
				cout<<contato2->v[pos].nome<<" "<<setfill('0')<<setw(4)<<contato2->v[pos].niver<<" "<<pos<<" "<<comp2<<endl;
				comp2=0;
			}
		}
	}
	delete []contato->v;
	delete contato;
	delete []contato2->v;
	delete contato2;
	delete dados;
	return 0;
}