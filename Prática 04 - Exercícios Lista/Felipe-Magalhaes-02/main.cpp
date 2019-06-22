#include "TAD_Ponteiro_com_cabeca.h"
#include<cctype>
int main()
{
	TLista* lista;
	TConta* dados;
	int quant,i=0;
	char op,adicionar;
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
		
		cout<<"\nDeseja adicionar no inicio ou final da lista? I-inicio F-final\n";
		cin>>adicionar;
		
		while(toupper(adicionar)!='I' && toupper(adicionar)!='F')
		{
			cout<<"\nOPCAO INVALIDA. FAVOR TENTAR NOVAMENTE...."<<endl;
			cout<<"\nDeseja adicionar no inicio ou final da lista? I-inicio F-final\n";
			cin>>adicionar;
		}
		
		if(toupper(adicionar)=='I')
		{
			cout<<"\n\nDADOS INSERIDOS NO INICIO DA LISTA..."<<endl;
			TLista_Inserir_Primeiro(lista,dados);
			TLista_Imprimir(lista);
		}
		else
		{
			cout<<"\n\nDADOS INSERIDOS NO FINAL DA LISTA..."<<endl;
			TLista_Inserir_Final(lista,dados);
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
	
	cout<<"Deseja retirar os dados no inicio ou no final da lista? I-inicio F-final\n";
	cin>>adicionar;
	
	while(toupper(adicionar)!='I' && toupper(adicionar)!='F')
	{
		cout<<"\nOPCAO INVALIDA. FAVOR TENTAR NOVAMENTE...."<<endl;
		cout<<"\nDeseja retirar os dados no inicio ou no final da lista? I-inicio F-final\n";
		cin>>adicionar;
	}
	
	if(toupper(adicionar)=='I')
	{
		cout<<"\n\nFOI RETIRADO O PRIMEIRO ITEM DA LISTA..."<<endl;
		TLista_RetiraPrimeiro(lista,dados);
		TLista_Imprimir(lista);
	}
	else
	{
		cout<<"\n\nFOI RETIRADO O FINAL ITEM DA LISTA..."<<endl;
		TLista_RetiraUltimo(lista,dados);
		TLista_Imprimir(lista);
	}
	
	liberar_memoria_TLista(lista);
	liberar_memoria_TConta(dados);
	return 0;
}