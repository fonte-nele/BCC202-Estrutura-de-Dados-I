/*
  Feito por Felipe Fontenele de Ávila Magalhães
  Data: 10/01/2016
  Matéria: Estrutura de Dados I  
*/
#include"exe1.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 1                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se o conceito de pilhas e filas, sendo possivel as seguintes op:||"<<endl;
	cout<<"  || Inicializar uma pilha, verificar se ela eh vazia, inserir um item no topo da pilha       ||"<<endl;
	cout<<"  || Retirar um item no topo da pilha, retornar o tamanho da pilha e limpar a pilha.          ||"<<endl;
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
				cout<<"Preencha a pilha:\n"<<endl;
				cout<<"Digite o numero que deseja inserir:"<<endl;
				cin>>numero->num;
				TPilha_Filas(fila1,fila2,numero);
				TPilha_Imprimir(fila1);
				break;
			}
			case 4:
			{
				if(TPilha_Pop(fila1,numero))
				{
					cout<<"Apos as alteracoes a pilha ficou dessa forma:\n";
					TPilha_Imprimir(fila1);
				}
				else
				{
					cout<<"\nPilha esta vazia..."<<endl<<endl;
				}
				break;
			}
			case 5:
			{
				cout<<"\n\nO TAMANHO DA PILHA EH: "<<TPilha_Tamanho(fila1);
				cout<<endl<<endl;
				break;
			}
			case 6:
			{
				TPilha_Limpa(fila1);
				TPilha_Limpa(fila2);
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