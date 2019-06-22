#include "TAD_Ponteiro_sem_cabeca.h"
#include<cctype>

int main()
{
	TLista* lista;
	TConta* dados;
	int quant,i=0;
	char op;
	Inicializar_TConta(&dados);
	Inicializar_TLista(&lista);
	TLista_Inicia(lista);
	
	
	if(TLista_EhVazia(lista))
	{
		cout<<"Quantos dados bancarios deseja adicionar?\n";
		cin>>quant;
	}
	do{
		cout<<"\nDigite o numero da conta bancaria(somente numeros):\n";
		cin>>dados->num_conta;
		cout<<"\nDigite o saldo da conta "<<dados->num_conta<<" :\n";
		cin>>dados->saldo;
		
		if(TLista_Insere(lista,dados))
		{
			cout<<"\n\nDADOS INSERIDOS NO FINAL DA LISTA..."<<endl;
			TLista_Imprimir(lista);
		}
		if(i<quant-1)
		{
			cout<<"\nDeseja adicionar mais dados bancarios? S-sim N-nao\n";
			cin>>op;
			while(toupper(op)!='S' && toupper(op)!='N')
			{
				cout<<"\nOPCAO INVALIDA. FAVOR TENTAR NOVAMENTE...."<<endl;
				cout<<"\nDeseja adicionar mais dados bancarios? S-sim N-nao\n";
				cin>>op;
			}
		}
		
		i++;
	}while(i<quant && toupper(op)!='N');

	TLista_Imprimir(lista);
	
	if(TLista_RetiraPrimeiro(lista,dados))
	{
		cout<<"FOI RETIRADO O PRIMEIRO ITEM DA LISTA..."<<endl;
	}
	else
	{
		cout<<"FALHA NA EXECUCAO DA RETIRADA..."<<endl<<endl;
	}
	cout<<"Apos as alteracoes a lista ficou dessa forma:\n";
	TLista_Imprimir(lista);
	
	liberar_memoria_TLista(lista);
	liberar_memoria_TConta(dados);
	return 0;
}