/*
  Feito por Felipe Fontenele de Ávila Magalhães
  Data: 31/12/2015
  Matéria: Estrutura de Dados I  
*/
#include"fila_array.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 1                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se o conceito de filas, sendo possivel as seguintes operacoes: ||"<<endl;
	cout<<"  || Inicializar uma fila, verificar se ela eh vazia, inserir um item no final da fila       ||"<<endl;
	cout<<"  || Retirar um item no inicio da fila, retornar o tamanho da fila e limpar a fila.          ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	TConta* conta;
	TFila* fila;
	int op;
	Inicializar_TConta(&conta);
	Inicializar_TFila(&fila);
	
	do{
		op = Menu();
		switch(op)
		{
			case 1:
			{
				TFila_Inicia(fila);
				cout<<"\nFEITO COM SUCESSO..."<<endl;
				cout<<"A FILA FOI INICIALIZADA."<<endl<<endl;
				break;
			}
			case 2:
			{
				if(TFila_EhVazia(fila))
				{
					cout<<"\nA FILA ESTA VAZIA."<<endl<<endl;
				}
				else
				{
					cout<<"\nA FILA NAO ESTA VAZIA."<<endl<<endl;
				}
				break;
			}
			case 3:
			{
				cout<<endl;
				cout<<"========================FILA======================="<<endl<<endl;
				cout<<"Preencha a fila:\n"<<endl;
				cout<<"Digite o numero da conta:"<<endl;
				cin>>conta->num_conta;
				cout<<"Digite o saldo da conta:"<<endl;
				cin>>conta->saldo;
				if(TFila_Enfileirar(fila,conta))
				{
					cout<<"\nDADOS INSERIDOS COM SUCESSO."<<endl<<endl;
					TFila_Imprimir(fila);
				}
				else
				{
					cout<<"\nNAO FOI POSSIVEL ADICIONAR OS DADOS. FILA CHEIA."<<endl<<endl;
				}
				break;
			}
			case 4:
			{
				if(TFila_EhVazia(fila))
				{
					cout<<"\nFila esta vazia..."<<endl<<endl;
				}
				else
				{
					if(TFila_Desenfileirar(fila,conta))
					{
						cout<<"FEITO COM SUCESSO..."<<endl<<endl;
					}
					else
					{
						cout<<"FALHA NA EXECUCAO DA RETIRADA..."<<endl<<endl;
					}
					cout<<"Apos as alteracoes a fila ficou dessa forma:\n";
					TFila_Imprimir(fila);
				}
				break;
			}
			case 5:
			{
				cout<<"\n\nO TAMANHO DA FILA EH: "<<TFila_Tamanho(fila);
				cout<<endl<<endl;
				break;
			}
			case 6:
			{
				TFila_Limpa(fila);
				break;
			}
			case 7:
			{
				TFila_Imprimir(fila);
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
	liberar_memoria_TFila(fila);
	return 0;
}