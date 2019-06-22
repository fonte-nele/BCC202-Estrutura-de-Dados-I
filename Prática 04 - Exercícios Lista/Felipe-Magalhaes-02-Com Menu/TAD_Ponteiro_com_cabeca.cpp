#include "TAD_Ponteiro_com_cabeca.h"

void Inicializar_TConta(TConta** dados)
{
	(*dados) = new TConta;
}

void Inicializar_TLista(TLista** lista)
{
	(*lista) = new TLista;
}

int Menu()
{
    int escolha;
	cout<<"  ============================MENU============================"<<endl;
	cout<<" ||                                                          ||"<<endl;
    cout<<" ||                                                          ||"<<endl;
	cout<<" || 1 - Iniciar a lista.                                     ||"<<endl;
    cout<<" || 2 - Verificar se a lista esta vazia.                     ||"<<endl;
    cout<<" || 3 - Inserir dados bancarios no inicio da lista.          ||"<<endl;
	cout<<" || 4 - Inserir dados bancarios no final da lista.           ||"<<endl;
	cout<<" || 5 - Retirar dados bancarios no inicio da lista.          ||"<<endl;
	cout<<" || 6 - Retirar dados bancarios no final da lista.           ||"<<endl;
    cout<<" || 7 - Imprimir a lista.                                    ||"<<endl;
	cout<<" || 8 - Sair.                                                ||"<<endl;
	cout<<" ||                                                          ||"<<endl;
	cout<<"  ============================MENU============================"<<endl;
    cout<<endl;
	cout<<"  Escolha: ";  
	cin>>escolha;
    cin.ignore();
    return escolha;
}

void TLista_Inicia(TLista* lista)
{
	lista->primeiro = new TCelula;
	lista->ultimo = lista->primeiro;
	lista->primeiro->prox = NULL;
}

bool TLista_EhVazia(TLista* lista)
{
	if(lista->primeiro == lista->ultimo)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TLista_Inserir_Final(TLista* lista,TConta* conta)
{
	lista->ultimo->prox = new TCelula;
	lista->ultimo = lista->ultimo->prox;
	lista->ultimo->item.num_conta = conta->num_conta;
	lista->ultimo->item.saldo = conta->saldo;
	lista->ultimo->prox = NULL;
}

void TLista_Inserir_Primeiro(TLista* lista,TConta* conta)
{
	TCelula* prim = lista->primeiro->prox;
	TCelula* novo= new TCelula;
	if(novo==NULL)
	{
		cout<<"FALHA NA EXECUCAO..."<<endl;
	}
	lista->primeiro->prox = novo;
	novo->prox = prim;
	novo->item.num_conta = conta->num_conta;
	novo->item.saldo = conta->saldo;
	if(lista->ultimo == lista->primeiro)
	{
		lista->ultimo = novo;
	}
	
}

void TLista_RetiraPrimeiro(TLista* lista,TConta* conta)
{
	if(TLista_EhVazia(lista))
	{
		cout<<"\nA lista esta vazia."<<endl;
	}
	TCelula* aux;
	aux = lista->primeiro->prox;
	*conta = aux->item;
	lista->primeiro->prox = aux->prox;
	delete aux;
}

void TLista_RetiraUltimo(TLista* lista,TConta* conta)
{
	if(TLista_EhVazia(lista))
	{
		cout<<"\nA lista esta vazia."<<endl;
	}
	TCelula* aux;
	TCelula* novo;
	novo = lista->primeiro->prox;
	aux = novo->prox;
	
	while(aux->prox!=NULL)
	{
		novo = novo->prox;
		aux = aux->prox;
	}
	delete aux;
	novo->prox = NULL;
}

void TLista_Imprimir(TLista* lista)
{
	int i=1;
	TCelula *aux;
	aux = lista->primeiro->prox;
	cout<<"\nOs dados na lista sao:\n";
	while(aux != NULL)
	{
		cout<<"\nCONTA BANCARIA "<<i<<" : "<<aux->item.num_conta<<endl;
		cout<<"SALDO: "<<aux->item.saldo<<endl<<endl;
		aux = aux->prox;
		i++;
	}
}

void liberar_memoria_TConta(TConta* dados)
{
	delete dados;
}

void liberar_memoria_TLista(TLista* lista)
{
	delete lista;
}