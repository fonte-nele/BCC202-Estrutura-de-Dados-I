/*
  Feito por Felipe Fontenele de Ávila Magalhães
  Data: 01/01/2016
  Matéria: Estrutura de Dados I  
*/
#include"fila-pont.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 2                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se o conceito de filas, sendo possivel as seguintes operacoes: ||"<<endl;
	cout<<"  || Inicializar uma fila, verificar se ela eh vazia, inserir um item no final da fila       ||"<<endl;
	cout<<"  || Retirar um item no inicio da fila, retornar o tamanho da fila e limpar a fila.          ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	TFila* fila;
	TConta* conta;
	int op;
	Inicializar_TFila(&fila);
	Inicializar_TConta(&conta);
	TFila_Inicia(fila);
	
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
				cout<<"=======================FILA======================="<<endl<<endl;
				cout<<"Preencha a fila:\n"<<endl;
				cout<<"Digite o numero da conta:"<<endl;
				cin>>conta->num_conta;
				cout<<"Digite o saldo da conta:"<<endl;
				cin>>conta->saldo;
				TFila_Enfileirar(fila,conta);
				TFila_Imprimir(fila);
				break;
			}
			case 4:
			{
				if(TFila_Desenfileirar(fila,conta))
				{
					cout<<"Apos as alteracoes a fila ficou dessa forma:\n";
					TFila_Imprimir(fila);
				}
				else
				{
					cout<<"\nA fila esta vazia..."<<endl<<endl;
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