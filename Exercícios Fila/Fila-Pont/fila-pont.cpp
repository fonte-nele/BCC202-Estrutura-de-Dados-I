#include"fila-pont.h"

void Inicializar_TConta(TConta** conta)
{
	(*conta) = new TConta;
}

void Inicializar_TFila(TFila** fila)
{
	(*fila) = new TFila;
}

int Menu()
{
	int escolha;
	cout<<"  ============================MENU============================"<<endl;
	cout<<" ||                                                          ||"<<endl;
    cout<<" ||                                                          ||"<<endl;
	cout<<" || 1 - Inicializar a fila.                                  ||"<<endl;
    cout<<" || 2 - Verificar se a fila esta vazia.                      ||"<<endl;
    cout<<" || 3 - Inserir dados bancarios no final da fila.            ||"<<endl;
	cout<<" || 4 - Retirar dados bancarios no inicio da fila.           ||"<<endl;
    cout<<" || 5 - Retornar o tamanho da fila.                          ||"<<endl;
	cout<<" || 6 - Limpar dados da fila.                                ||"<<endl;
	cout<<" || 7 - Imprimir a fila.                                     ||"<<endl;
	cout<<" || 8 - Sair.                                                ||"<<endl;
	cout<<" ||                                                          ||"<<endl;
	cout<<"  ============================MENU============================"<<endl;
    cout<<endl;
	cout<<"  Escolha: ";  
	cin>>escolha;
    cin.ignore();
    return escolha;
}

void TFila_Inicia(TFila* fila)
{
	fila->primeiro = new TCelula;
	fila->ultimo = fila->primeiro;
	fila->primeiro->prox = NULL;
	fila->tamanho = 0;
}

bool TFila_EhVazia(TFila* fila)
{
	if(fila->ultimo == fila->primeiro)
	{
		if(fila->tamanho == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void TFila_Enfileirar(TFila* fila, TConta* conta)
{
	fila->ultimo->prox = new TCelula;
	fila->ultimo = fila->ultimo->prox;
	fila->ultimo->item.num_conta = conta->num_conta;
	fila->ultimo->item.saldo = conta->saldo;
	fila->ultimo->prox = NULL;
	fila->tamanho++;
}

bool TFila_Desenfileirar(TFila* fila, TConta* conta)
{
	if(TFila_EhVazia(fila))
	{
		return false;
	}
	else
	{
		TCelula* aux;
		aux = fila->primeiro->prox;
		fila->primeiro->prox = fila->primeiro->prox->prox;
		*conta = aux->item;
		delete aux;
		return true;
	}
}

int TFila_Tamanho(TFila* fila)
{
	return fila->tamanho;
}

void TFila_Limpa(TFila* fila)
{
	TFila_Inicia(fila);
	cout<<"\nA FILA FICOU LIMPA."<<endl<<endl;
}

void TFila_Imprimir(TFila* fila)
{
	int i=1;
	TCelula* aux;
	aux = fila->primeiro->prox;
	if(TFila_EhVazia(fila))
	{
		cout<<"\nA fila esta vazia..."<<endl;
	}
	else
	{
		cout<<"\nOs dados na fila sao:"<<endl;
		while(aux != NULL)
		{
			cout<<"\nCONTA BANCARIA "<<i<<" : "<<aux->item.num_conta<<endl;
			cout<<"SALDO: "<<aux->item.saldo<<endl<<endl;
			aux = aux->prox;
			i++;
		}
	}	
}

void liberar_memoria_TConta(TConta* conta)
{
	delete conta;
}

void liberar_memoria_TFila(TFila* fila)
{
	delete fila;
}