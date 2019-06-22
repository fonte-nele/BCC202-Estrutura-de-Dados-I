/*
  Feito por Felipe Fontenele de Ávila Magalhães
  Data: 03/01/2016
  Matéria: Estrutura de Dados I  
*/
#include"pratica05.h"
#include<cmath>

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 1                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se o conceito de pilhas, com as operacoes:Inicializar uma pilha,||"<<endl;
	cout<<"  || verificar se ela eh vazia, inserir um item no topo da pilha, retirar um item no topo da  ||"<<endl;
	cout<<"  || pilha, retornar o tamanho da pilha e limpar a pilha. Posteriormente, foi feito uma       ||"<<endl;
	cout<<"  || calculadora com operacoes pos-fixadas, consistindo em primeiro inserir os operandos para ||"<<endl;
	cout<<"  || depois inserir os operadores(+,-,*,/ e ^).                                               ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	TPilha* pilha;
	TCalc* conta;
	int op;
	char sinal;
	Inicializar_TPilha(&pilha);
	Inicializar_TCalc(&conta);
	TPilha_Inicia(pilha);
	
	do{
		op = Menu();
		switch(op)
		{
			case 1:
			{
				cout<<endl;
				cout<<"=======================PILHA======================="<<endl<<endl;
				cout<<"Preencha a pilha:\n"<<endl;
				cout<<"Digite o numero que deseja empilhar:"<<endl;
				cin>>conta->num;
				TPilha_Push(pilha,conta);
				break;
			}
			case 2:
			{
				cout<<endl;
				cout<<"=======================PILHA======================="<<endl<<endl;
				cout<<"Digite o sinal da operacao que deseja utilizar:"<<endl;
				cin>>sinal;
				while(sinal!='+' && sinal!='-' && sinal!='/' && sinal!='*' && sinal!='^')
				{
					cout<<"\nSINAL INVALIDO. FAVOR TENTAR NOVAMENTE..."<<endl;
					cout<<"Digite o sinal da operacao que deseja utilizar:"<<endl;
					cin>>sinal;
				}
				if(TPilha_EhVazia(pilha))
				{
					cout<<"\nENTRADA INCOSISTENTE."<<endl<<endl;
					TPilha_Limpa(pilha);
				}
				else
				{
					double n1=TPilha_Pop(pilha,conta);
					if(TPilha_EhVazia(pilha))
					{
						cout<<"\nENTRADA INCOSISTENTE."<<endl<<endl;
						TPilha_Limpa(pilha);
					}
					else
					{
						double n2=TPilha_Pop(pilha,conta);
						if(sinal=='+')
						{
							conta->num = n2+n1;
							TPilha_Push(pilha,conta);
						}
						else
						{
							if(sinal=='-')
							{
								conta->num = n2-n1;
								TPilha_Push(pilha,conta);
							}
							else
							{
								if(sinal=='*')
								{
									conta->num = n2*n1;
									TPilha_Push(pilha,conta);
								}
								else
								{
									if(sinal=='/')
									{
										conta->num = n2/n1;
										TPilha_Push(pilha,conta);
									}
									else
									{
										conta->num = pow(n2,n1);
										TPilha_Push(pilha,conta);
									}
								}
							}
						}
					}
				}
				break;
			}
			case 3:
			{
				if(TPilha_Tamanho(pilha) == 1)
				{
					TPilha_Imprimir(pilha);
					TPilha_Inicia(pilha);
				}
				else
				{
					cout<<"\nENTRADA INCOSISTENTE."<<endl;
					TPilha_Inicia(pilha);
				}
				break;
			}
			case 4:
			{
				cout<<"\nPROGRAMA CALCULADORA FINALIZADO COM SUCESSO..."<<endl<<endl;
				break;
			}
			default:
			{
				cout<<"\nOPCAO INVALIDA. FAVOR TENTAR NOVAMENTE..."<<endl<<endl;
				break;
			}
		}
	}while(op!=4);
	
	liberar_memoria_TCalc(conta);
	liberar_memoria_TPilha(pilha);
	return 0;
}