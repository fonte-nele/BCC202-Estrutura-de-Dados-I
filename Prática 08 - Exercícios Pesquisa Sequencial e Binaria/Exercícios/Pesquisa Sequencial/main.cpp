/*
	Feito por: Felipe Fontenele de Ávila Magalhães
	Data: 08/01/2016
	Disciplina: Estrutura de Dados I
*/
#include"contato.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 1                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se os conceitos de pesquisa sequencial e binaria. O programa    ||"<<endl;
	cout<<"  || eh estilo uma agenda, na qual insere contatos com os seguintes campos: nome, telefone e  ||"<<endl;
	cout<<"  || aniversario.Logo apos, eh feito uma pesquisa sequencial nos contatos de acordo com um tel||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	TContato* contato;
	TDados* dados;
	contato = new TContato;
	dados = new TDados;
	int i,j,num_casos,num_contatos,quant_pesq;
	unsigned long int numero_tel;
	TContato_Construir(contato);
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
			TContato_Inserir(contato,dados);
		}
		for(j=0;j<quant_pesq;j++)
		{
			cout<<"\n\nPESQUISA "<<j+1<<" :"<<endl;
			cout<<"\nDigite o numero de telefone(SOMENTE NUMEROS) que deseja pesquisar:\n";
			cin>>numero_tel;
			TContato_Pesquisar(contato,numero_tel);
		}
	}
	
	delete []contato->v;
	delete contato;
	delete dados;
	return 0;
}