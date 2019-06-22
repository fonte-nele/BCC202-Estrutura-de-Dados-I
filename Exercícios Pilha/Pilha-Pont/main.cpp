/*
  Feito por Felipe Fontenele de Ávila Magalhães
  Data: 03/01/2016
  Matéria: Estrutura de Dados I  
*/
#include"pilha_pont.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 2                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se o conceito de pilhas, sendo possivel as seguintes operacoes: ||"<<endl;
	cout<<"  || Inicializar uma pilha, verificar se ela eh vazia, inserir um item no topo da pilha       ||"<<endl;
	cout<<"  || Retirar um item no topo da pilha, retornar o tamanho da pilha e limpar a pilha.          ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	TPilha* pilha;
	TConta* conta;
	int op;
	Inicializar_TPilha(&pilha);
	Inicializar_TConta(&conta);
	TPilha_Inicia(pilha);
	
	do{
		op = Menu();
		switch(op)
		{
			case 1:
			{
				TPilha_Inicia(pilha);
				cout<<"\nFEITO COM SUCESSO..."<<endl;
				cout<<"A PILHA FOI INICIALIZADA."<<endl<<endl;
				break;
			}
			case 2:
			{
				if(TPilha_EhVazia(pilha))
				{
					cout<<"\nA PILHA ESTA VAZIA."<<endl<<endl;
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
				cout<<"Preencha a pilha:\n"<<endl;
				cout<<"Digite o numero da conta:"<<endl;
				cin>>conta->num_conta;
				cout<<"Digite o saldo da conta:"<<endl;
				cin>>conta->saldo;
				TPilha_Push(pilha,conta);
				TPilha_Imprimir(pilha);
				break;
			}
			case 4:
			{
				if(TPilha_Pop(pilha,conta))
				{
					cout<<"Apos as alteracoes a pilha ficou dessa forma:\n";
					TPilha_Imprimir(pilha);
				}
				else
				{
					cout<<"\nPilha esta vazia..."<<endl<<endl;
				}
				break;
			}
			case 5:
			{
				cout<<"\n\nO TAMANHO DA PILHA EH: "<<TPilha_Tamanho(pilha);
				cout<<endl<<endl;
				break;
			}
			case 6:
			{
				TPilha_Limpa(pilha);
				break;
			}
			case 7:
			{
				TPilha_Imprimir(pilha);
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
	
	liberar_memoria_TConta(conta);
	liberar_memoria_TPilha(pilha);
	return 0;
}