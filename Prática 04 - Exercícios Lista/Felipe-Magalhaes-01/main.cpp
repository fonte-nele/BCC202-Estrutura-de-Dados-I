#include "TAD_Array.h"
#include<cctype>
int main()
{
	TLista* lista1;
	TLista* lista2;
	TConta* dados;
	int pos,chave;
	Inicializar_TConta(&dados);
	Inicializar_TLista(&lista1);
	Inicializar_TLista(&lista2);
	TLista_Faz_Vazia(lista1);
	TLista_Faz_Vazia(lista2);
	cout<<"\nLISTA 1..."<<endl<<endl;
	Preencher_Lista(lista1,dados);
	TLista_Imprimir(lista1);
	cout<<"Digite a chave que deseja procurar na lista:\n"<<endl;
	cin>>chave;
	TLista_Pesquisar(lista1,chave);
	cout<<"Qual a posicao da lista que deseja retirar?\n";
	cin>>pos;
	while(pos<=0 || pos > lista1->ultimo)
	{
		cout<<"POSICAO INVALIDA...TENTE NOVAMENTE"<<endl<<endl;
		cout<<"Qual a posicao da lista que deseja retirar?\n";
		cin>>pos;
	}
	if(TLista_Retira(lista1,pos-1,dados))
	{
		cout<<"FEITO COM SUCESSO..."<<endl<<endl;
	}
	else
	{
		cout<<"FALHA NA EXECUCAO DA RETIRADA..."<<endl<<endl;
	}
	cout<<"Apos as alteracoes a lista ficou dessa forma:\n";
	TLista_Imprimir(lista1);
	
	
	cout<<"\nLISTA 2..."<<endl<<endl;
	Preencher_Lista(lista2,dados);
	TLista_Imprimir(lista2);
	cout<<"Digite a chave que deseja procurar na lista:\n"<<endl;
	cin>>chave;
	TLista_Pesquisar(lista2,chave);
	cout<<"Qual a posicao da lista que deseja retirar?\n";
	cin>>pos;
	while(pos<=0 || pos > lista2->ultimo)
	{
		cout<<"POSICAO INVALIDA...TENTE NOVAMENTE"<<endl<<endl;
		cout<<"Qual a posicao da lista que deseja retirar?\n";
		cin>>pos;
	}
	if(TLista_Retira(lista2,pos-1,dados))
	{
		cout<<"FEITO COM SUCESSO..."<<endl<<endl;
	}
	else
	{
		cout<<"FALHA NA EXECUCAO DA RETIRADA..."<<endl<<endl;
	}
	cout<<"Apos as alteracoes a lista ficou dessa forma:\n";
	TLista_Imprimir(lista2);
	
	Concatenar_Listas(lista1,lista2);
	
	liberar_memoria_TLista(lista1);
	liberar_memoria_TLista(lista2);
	liberar_memoria_TConta(dados);
	return 0;
}