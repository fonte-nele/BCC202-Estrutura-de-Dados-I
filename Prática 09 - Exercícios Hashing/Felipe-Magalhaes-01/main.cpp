/*
	Feito por: Felipe Fontenele de Ávila Magalhães
	Data: 13/03/2016
	Disciplina: Estrutura de Dados I
	Prof.(a): Amanda Savio Nascimento Silva
*/
#include"contato.h"
#include"pesq_sequencial.h"
#include"pesq_binaria.h"
#include"hash_lista_encadeada.h"
#include"hash_ender_aberto.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 1                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se os conceitos de pesquisa sequencial, binaria e hashing. O    ||"<<endl;
	cout<<"  || programa consiste basicamente no funcionamento de uma agenda, na qual insere-se dados de ||"<<endl;
	cout<<"  || contatos.Logo apos, aplica-se uma pesquisa sequencial, binaria e hashing nos contatos de ||"<<endl;
	cout<<"  || acordo com um numero de telefone informado pelo usuario, retornando os dados caso exista,||"<<endl;
	cout<<"  || caso contrario retorna -1.   												             ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	TContato *contato, *contato2;
	TDados* dados;
	THash* hash;
	TItem* item;
	Enderecamento end;
	TItemEnd item_end;
	pesos pes;
	contato = new TContato;
	contato2 = new TContato;
	dados = new TDados;
	hash = new THash;
	item = new TItem;
	int i,j,num_casos,num_contatos,quant_pesq,pos,comp2=0;
	unsigned long int numero_tel;
	cout<<"\nDigite o numero de casos para teste:\n";
	cin>>num_casos;
	for(i=0;i<num_casos;i++)
	{
		TContato_Construir_Sequencial(contato);
		TContato_Construir_Binario(contato2);
		cout<<"\nDigite a quantidade de contatos que deseja inserir:\n";
		cin>>num_contatos;
		cout<<"\nDigite o numero de pesquisas a serem feitas:\n";
		cin>>quant_pesq;		
		THash_Inicia(hash,tam,tam);
		Hash_Inicia_Aberto(end,pes);
		
		for(j=0;j<num_contatos;j++)
		{
			cout<<"\n\nCONTATO "<<j+1<<" :"<<endl;
			cout<<"\nDigite o nome do contato(SEM ESPACOS):"<<endl;
			cin>>dados->nome;
			cout<<"\nDigite a data de aniversario do contato(Formato MMDD):"<<endl;
			cin>>dados->niver;
			cout<<"\nDigite o numero de telefone do contato(SOMENTE NUMEROS):"<<endl;
			cin>>dados->telefone;
			TContato_Inserir_Sequencial(contato,dados);
			TContato_Inserir_Binario(contato2,dados);
			item->contato_hash = *dados;
			item_end.cont_hash_aberto = *dados;
			for(int k=9;k>=0;k--)
			{
				item->chave[k] = dados->telefone%10;
				item_end.chave[k] = dados->telefone%10;
				dados->telefone = dados->telefone/10;
			}
			if(THash_Insere(hash,item));
			if(Enderecamento_Insere(end,item_end,pes));
		}
		
		for(j=0;j<quant_pesq;j++)
		{
			cout<<"\n\nPESQUISA "<<j+1<<" :"<<endl;
			cout<<"\nDigite o numero de telefone(SOMENTE NUMEROS) que deseja pesquisar:\n";
			cin>>numero_tel;
			cout<<"\n===============RESULTADO PESQUISA==============="<<endl;
			TContato_Pesquisar(contato,numero_tel);
			pos=TContato_Pesquisar_Binario(contato2,numero_tel,&comp2);
			cout<<"\nPESQUISA BINARIA:"<<endl;
			if(pos==-1)
			{
				cout<<numero_tel;
				cout<<"\nNAO ENCONTRADO "<<-1<<" "<<comp2<<endl;
				comp2=0;
			}
			else
			{
				cout<<numero_tel<<endl;
				cout<<contato2->v[pos].nome<<" "<<setfill('0')<<setw(4)<<contato2->v[pos].niver<<" "<<pos<<" "<<comp2<<endl;
				comp2=0;
			}
			int temp[10];
			for(int k=9; k>=0; k--)
			{
				temp[k] = numero_tel%10;
				numero_tel = numero_tel/10;
			}
			THash_Pesquisa(hash,temp,item);
			Enderecamento_Pesquisa2(end,temp,pes);
			cout<<endl<<"TABELA HASH(ENDERECAMENTO ABERTO):"<<endl;
			if(pos==-1)
			{
				for(int a=0; a<10; a++)
				{
					cout<<temp[a];
				}
				cout<<"\nNAO ENCONTRADO "<<-1<<" "<<comp2+1<<endl;
				comp2=0;
			}
			else
			{
				for(int a=0; a<10; a++)
				{
					cout<<temp[a];
				}
				cout<<endl;
				cout<<contato2->v[pos].nome<<" "<<setfill('0')<<setw(4)<<contato2->v[pos].niver<<" 1 "<<comp2+1<<endl;
				comp2=0;
			}
		}
	}
	delete []contato->v;
	delete contato;
	delete []contato2->v;
	delete contato2;
	delete dados;
	delete hash;
	delete item;
	return 0;
}