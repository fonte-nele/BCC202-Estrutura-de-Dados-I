/*
  Feito por: Felipe Fontenele de Ávila Magalhães
  Matrícula: 15.1.4331
  Data: 08/02/2016
  Matéria: Estrutura de Dados I  
*/
#include"exe1.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 1                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se o conceito de PILHA e FILA, sendo que uma pilha foi          ||"<<endl;
	cout<<"  || implementada utilizando duas filas auxiliares. A cada PUSH da pilha, eh transferido      ||"<<endl;
	cout<<"  || todos os elementos da FILA 1 para a FILA 2, em seguida devolve os elementos da FILA 2    ||"<<endl;
	cout<<"  || para a FILA 1. O POP da pilha retira um elemento da FILA 1, que eh o ultimo a ser        ||"<<endl;
	cout<<"  || adicionado, caracterizando uma pilha. Alem disso, o programa permite outras funcoes como:||"<<endl;
	cout<<"  || Inicializar uma pilha, verificar se a mesma esta vazia, retornar o tamanho da pilha e a  ||"<<endl;
	cout<<"  || funcao de limpar os dados da pilha.                                                      ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	TPilha* fila1,*fila2;
	TNumero* numero;
	int op;
	Inicializar_TPilha(&fila1);
	Inicializar_TPilha(&fila2);
	Inicializar_TNumero(&numero);
	TPilha_Inicia(fila1);
	TPilha_Inicia(fila2);
	
	do{
		op = Menu();
		switch(op)
		{
			case 1:
			{
				TPilha_Inicia(fila1);
				TPilha_Inicia(fila2);
				cout<<"\nFEITO COM SUCESSO..."<<endl;
				cout<<"A PILHA FOI INICIALIZADA."<<endl<<endl;
				break;
			}
			case 2:
			{
				if(TPilha_EhVazia(fila1))
				{
					if(TPilha_EhVazia(fila2))
					{
						cout<<"\nA PILHA ESTA VAZIA."<<endl<<endl;
					}
					else
					{
						cout<<"\nA PILHA NAO ESTA VAZIA."<<endl<<endl;
					}
				}
				else
				{
					cout<<"\nA PILHA NAO ESTA VAZIA."<<endl<<endl;
				}
				break;
			}
			case 3:
			{
				cout<<endl;
				cout<<"=======================PILHA======================="<<endl<<endl;
				cout<<"Digite o numero que deseja inserir na pilha:"<<endl;
				cin>>numero->num;
				TPilha_Push(fila1,fila2,numero);
				TPilha_Imprimir(fila1);
				break;
			}
			case 4:
			{
				if(TPilha_Pop(fila1,numero))
				{
					if(TPilha_Tamanho(fila1)==0)
					{
						cout<<"\nFEITO COM SUCESSO."<<endl;
						cout<<"\nA PILHA FICOU VAZIA..."<<endl<<endl;
					}
					else
					{
						cout<<"\nFEITO COM SUCESSO."<<endl;
						cout<<"\nApos as alteracoes a pilha ficou dessa forma:\n";
						TPilha_Imprimir(fila1);
					}
				}
				else
				{
					cout<<"\nIMPOSSIVEL RETIRAR POIS A PILHA ESTA VAZIA..."<<endl<<endl;
				}
				break;
			}
			case 5:
			{
				if(!TPilha_EhVazia(fila1) && TPilha_Tamanho(fila1)!=0)
				{
					cout<<"\nO TAMANHO DA PILHA EH: "<<TPilha_Tamanho(fila1)<<endl<<endl;
				}
				else
				{
					cout<<"\nTAMANHO 0 POIS A PILHA ESTA VAZIA..."<<endl<<endl;
				}
				break;
			}
			case 6:
			{
				if(!TPilha_EhVazia(fila1))
				{
					TPilha_Inicia(fila1);
					TPilha_Inicia(fila2);
					cout<<"\nA PILHA FICOU LIMPA."<<endl<<endl;
				}
				else
				{
					cout<<"\nIMPOSSIVEL LIMPAR POIS A PILHA ESTA VAZIA..."<<endl<<endl;
				}
				break;
			}
			case 7:
			{
				TPilha_Imprimir(fila1);
				break;
			}
			case 8:
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
		
	}while(op!=8);
	
	liberar_memoria_TNumero(numero);
	liberar_memoria_TPilha(fila1);
	liberar_memoria_TPilha(fila2);
	return 0;
}