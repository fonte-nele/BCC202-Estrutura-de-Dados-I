/*
  Feito por Felipe Fontenele de Ávila Magalhães
  Data: 20/12/2015
  Matéria: Estrutura de Dados I  
*/
#include "TAD_Ponteiro_sem_cabeca.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                           EXERCICIO 3                                                  "<<endl;
	cout<<"   ==================================================================================================== "<<endl;
	cout<<"  || Neste programa, trabalha-se o conceito de listas, ponteiro sem cabeca, sendo possivel as         ||"<<endl;
	cout<<"  || seguintes operacoes: Iniciar uma lista, verificar se a lista esta vazia, inserir um item no      ||"<<endl;
	cout<<"  || final da lista, retirar um item no inicio da lista e imprimir dados da lista.                    ||"<<endl;
	cout<<"   ==================================================================================================== "<<endl<<endl;
	
	
	TLista* lista;
	TConta* dados;
	int op;
	Inicializar_TConta(&dados);
	Inicializar_TLista(&lista);
	TLista_Inicia(lista);
	
	do{
		op = Menu();
		switch(op)
		{
			case 1:
			{
				TLista_Inicia(lista);
				cout<<"\nFEITO COM SUCESSO..."<<endl;
				cout<<"A LISTA FOI INICIALIZADA."<<endl<<endl;
				break;
			}
			case 2:
			{
				if(TLista_EhVazia(lista))
				{
					cout<<"\nA LISTA ESTA VAZIA."<<endl<<endl;
				}
				else
				{
					cout<<"\nA LISTA NAO ESTA VAZIA."<<endl<<endl;
				}
				break;
			}
			case 3:
			{
				cout<<endl;
				cout<<"========================LISTA========================"<<endl<<endl;
				cout<<"\nDigite o numero da conta bancaria(somente numeros):\n";
				cin>>dados->num_conta;
				cout<<"\nDigite o saldo da conta "<<dados->num_conta<<" :\n";
				cin>>dados->saldo;
				cout<<"\n\nDADOS INSERIDOS NO FINAL DA LISTA..."<<endl;
				TLista_Insere(lista,dados);
				TLista_Imprimir(lista);
				break;
			}
			case 4:
			{
				if(TLista_EhVazia(lista))
				{
					cout<<"\nLista esta vazia..."<<endl<<endl;
				}
				else
				{
					cout<<"\n\nFOI RETIRADO O PRIMEIRO ITEM DA LISTA..."<<endl;
					TLista_RetiraPrimeiro(lista,dados);
					cout<<"Apos as alteracoes a lista ficou dessa forma:\n";
					TLista_Imprimir(lista);
				}
				break;
			}
			case 5:
			{
				TLista_Imprimir(lista);
				break;
			}
			case 6:
			{
				cout<<"\nPROGRAMA FINALIZADO COM SUCESSO..."<<endl<<endl;
				break;
			}
			default:
			{
				cout<<"\nOPCAO INVALIDA. FAVOR TENTAR NOVAMENTE..."<<endl<<endl;
				break;
			}
		}
	}while(op!=6);
	
	liberar_memoria_TLista(lista);
	liberar_memoria_TConta(dados);
	return 0;
}