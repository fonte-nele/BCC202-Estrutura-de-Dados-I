/*
  Feito por Felipe Fontenele de Ávila Magalhães
  Data: 20/12/2015
  Matéria: Estrutura de Dados I  
*/
#include "TAD_Array.h"
int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 1                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se o conceito de listas, sendo possivel as seguintes operacoes:                                                                          ||"<<endl;
	cout<<"  || Fazer a lista ficar vazia, verificar se ela eh vazia, inserir um item no final da lista                                                                                      ||"<<endl;
	cout<<"  || Retirar um item da lista, concatenar duas listas e pesquisar um elemento da lista.                                                                                      ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	TLista* lista1;
	TLista* lista2;
	TConta* dados;
	int op,pos,chave;
	Inicializar_TConta(&dados);
	Inicializar_TLista(&lista1);
	Inicializar_TLista(&lista2);
	
	do{
		op = Menu();
		switch(op)
		{
			case 1:
			{
				TLista_Faz_Vazia(lista1);
				cout<<"\nFEITO COM SUCESSO..."<<endl;
				cout<<"A LISTA 1 FICOU VAZIA."<<endl<<endl;
				break;
			}
			case 2:
			{
				TLista_Faz_Vazia(lista2);
				cout<<"\nFEITO COM SUCESSO..."<<endl;
				cout<<"A LISTA 2 FICOU VAZIA."<<endl<<endl;
				break;
			}
			case 3:
			{
				if(TLista_Eh_Vazia(lista1))
				{
					cout<<"\nA LISTA 1 ESTA VAZIA."<<endl<<endl;
				}
				else
				{
					cout<<"\nA LISTA 1 NAO ESTA VAZIA."<<endl<<endl;
				}
				break;
			}
			case 4:
			{
				if(TLista_Eh_Vazia(lista2))
				{
					cout<<"\nA LISTA 2 ESTA VAZIA."<<endl<<endl;
				}
				else
				{
					cout<<"\nA LISTA 2 NAO ESTA VAZIA."<<endl<<endl;
				}
				break;
			}
			case 5:
			{
				cout<<endl;
				cout<<"======================LISTA 1======================"<<endl<<endl;
				Preencher_Lista(lista1,dados);
				TLista_Imprimir(lista1);
				break;
			}
			case 6:
			{
				cout<<endl;
				cout<<"======================LISTA 2======================"<<endl<<endl;
				Preencher_Lista(lista2,dados);
				TLista_Imprimir(lista2);
				break;
			}
			case 7:
			{
				if(TLista_Eh_Vazia(lista1))
				{
					cout<<"\nLista 1 esta vazia..."<<endl<<endl;
				}
				else
				{
					cout<<"Qual a posicao da lista 1 que deseja retirar?\n";
					cin>>pos;
					while(pos<=0 || pos > lista1->ultimo)
					{
						cout<<"POSICAO INVALIDA...TENTE NOVAMENTE"<<endl<<endl;
						cout<<"Qual a posicao da lista 1 que deseja retirar?\n";
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
					cout<<"Apos as alteracoes a lista 1 ficou dessa forma:\n";
					TLista_Imprimir(lista1);
				}
				break;
			}
			case 8:
			{
				if(TLista_Eh_Vazia(lista2))
				{
					cout<<"\nLista 2 esta vazia..."<<endl<<endl;	
				}
				else
				{
					cout<<"Qual a posicao da lista 2 que deseja retirar?\n";
					cin>>pos;
					while(pos<=0 || pos > lista2->ultimo)
					{
						cout<<"POSICAO INVALIDA...TENTE NOVAMENTE"<<endl<<endl;
						cout<<"Qual a posicao da lista 2 que deseja retirar?\n";
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
					cout<<"Apos as alteracoes a lista 2 ficou dessa forma:\n";
					TLista_Imprimir(lista2);
				}
				break;
			}
			case 9:
			{
				Concatenar_Listas(lista1,lista2);
				break;
			}
			case 10:
			{
				cout<<"Digite a chave que deseja procurar na lista 1:\n"<<endl;
				cin>>chave;
				TLista_Pesquisar(lista1,chave);
				break;
			}
			case 11:
			{
				cout<<"Digite a chave que deseja procurar na lista 2:\n"<<endl;
				cin>>chave;
				TLista_Pesquisar(lista2,chave);
				break;
			}
			case 12:
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
		
	}while(op!=12);
	
	liberar_memoria_TLista(lista1);
	liberar_memoria_TLista(lista2);
	liberar_memoria_TConta(dados);
	return 0;
}