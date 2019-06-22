#include "TAD_Array.h"

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
	cout<<" || 1 - Limpar a lista 1.                                    ||"<<endl;
	cout<<" || 2 - Limpar a lista 2.                                    ||"<<endl;
    cout<<" || 3 - Verificar se a lista 1 esta vazia.                   ||"<<endl;
    cout<<" || 4 - Verificar se a lista 2 esta vazia.                   ||"<<endl;
    cout<<" || 5 - Inserir dados bancarios na lista 1.                  ||"<<endl;
	cout<<" || 6 - Inserir dados bancarios na lista 2.                  ||"<<endl;
	cout<<" || 7 - Retirar dados de acordo com uma posicao na lista 1.  ||"<<endl;
	cout<<" || 8 - Retirar dados de acordo com uma posicao na lista 2.  ||"<<endl;
    cout<<" || 9 - Concatenar duas listas.                              ||"<<endl;
	cout<<" || 10 - Pesquisar dados por uma chave na lista 1.           ||"<<endl;
	cout<<" || 11 - Pesquisar dados por uma chave na lista 2.           ||"<<endl;
	cout<<" || 12 - Sair.                                               ||"<<endl;
	cout<<" ||                                                          ||"<<endl;
	cout<<"  ============================MENU============================"<<endl;
    cout<<endl;
	cout<<"  Escolha: ";  
	cin>>escolha;
    cin.ignore();
    return escolha;
}

void TLista_Faz_Vazia(TLista* lista)
{
	lista -> primeiro = BEGIN;
	lista -> ultimo = lista -> primeiro;
}

bool TLista_Eh_Vazia(TLista* lista)
{
	if(lista->ultimo == lista->primeiro)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Preencher_Lista(TLista* lista,TConta* conta)
{
	cout<<"\nDigite o numero da conta bancaria(somente numeros):\n";
	cin>>conta->num_conta;
	cout<<"\nDigite o saldo da conta "<<conta->num_conta<<" :\n";
	cin>>conta->saldo;
	cout<<"\nDigite a chave para esta conta bancaria:\n";
	cin>>conta->chave;
	if(!TLista_Insere(lista,conta))
	{
		cout<<"\n\nNao eh possivel adicionar esses ultimos dados, pois a LISTA esta CHEIA..."<<endl;
	}
	else
	{
		cout<<"\nDADOS INSERIDOS COM SUCESSO."<<endl;
	}
}

bool TLista_Insere(TLista* lista,TConta* x)
{
	if(lista->ultimo == MAXTAM)
	{
		//Lista cheia!!!
		return false;
	}
	else
	{
		lista -> item[lista->ultimo].num_conta = x->num_conta;
		lista -> item[lista->ultimo].saldo = x->saldo;
		lista -> item[lista->ultimo].chave = x->chave;
		lista -> ultimo++;
	}
	return true;
}

bool TLista_Retira(TLista* lista,int pos,TConta *x)
{
	if(TLista_Eh_Vazia(lista) || pos >= lista -> ultimo)
	{
		return false;
	}
	int cont;
	*x = lista -> item[pos];
	lista -> ultimo--;
	for(cont = pos+1; cont<= lista->ultimo;cont++)
	{
		lista->item[cont-1] = lista -> item[cont];
	}
	return true;
}

void TLista_Imprimir(TLista* lista)
{
	int i;
	if(TLista_Eh_Vazia(lista))
	{
		cout<<"\nLista esta vazia..."<<endl<<endl;	
	}
	else
	{
		cout<<"\nOs dados na lista sao:\n\n";
		for(i=lista -> primeiro; i< lista->ultimo; i++)
		{
			cout<<"CONTA BANCARIA "<<i+1<<" : "<<lista->item[i].num_conta<<endl;
			cout<<"SALDO: "<<lista->item[i].saldo<<endl;
			cout<<"CHAVE: "<<lista->item[i].chave<<endl<<endl;
		}
	}
}

void TLista_Pesquisar(TLista* lista,int procura)
{
	int i,cont=1;
	if(TLista_Eh_Vazia(lista))
	{
		cout<<"\nLista esta vazia..."<<endl<<endl;
	}
	else
	{
		for(i = lista->primeiro; i< lista->ultimo;i++)
		{
			if(lista->item[i].chave == procura)
			{
				cout<<"A chave procurada foi encontrada no indice "<<i+1<<" da lista.\n";
				cout<<"\nDados:\n\n";
				cout<<"CONTA BANCARIA : "<<lista->item[i].num_conta<<endl;
				cout<<"SALDO: "<<lista->item[i].saldo<<endl;
				cout<<"CHAVE: "<<lista->item[i].chave<<endl<<endl;
				cont++;		
			}
		}
		if(cont==1)
		{
			cout<<"\nA chave procurada nao foi encontrada na lista."<<endl<<endl;
		}
	}
}

void Concatenar_Listas(TLista* lista1,TLista* lista2)
{
	TLista* aux;
	aux = lista1;
	int j=0;
	while(j!=lista2->ultimo)
	{
		if(aux->ultimo == MAXTAM)
		{
			cout<<"\n\nLista cheia..."<<endl;
			break;
		}
		aux -> item[aux->ultimo].num_conta = lista2->item[j].num_conta;
		aux -> item[aux->ultimo].saldo = lista2->item[j].saldo;
		aux -> item[aux->ultimo].chave = lista2->item[j].chave;
		aux -> ultimo++;
		j++;
	}
	cout<<"\nApos a concatenacao das duas listas:\n\n";
	TLista_Imprimir(aux);
	delete aux;
}

void liberar_memoria_TConta(TConta* dados)
{
	delete dados;
}

void liberar_memoria_TLista(TLista* lista)
{
	delete lista;
}