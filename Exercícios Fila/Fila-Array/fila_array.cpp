#include"fila_array.h"

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
	fila->primeiro = 0;
	fila->ultimo = fila->primeiro;
}

bool TFila_EhVazia(TFila* fila)
{
	if(fila->ultimo == fila->primeiro)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TFila_Enfileirar(TFila* fila, TConta* conta)
{
	if(fila->ultimo == MAX)
	{
		return false;
	}
	else
	{
		fila->item[fila->ultimo].num_conta = conta->num_conta;
		fila->item[fila->ultimo].saldo = conta->saldo;
		fila->ultimo++;
		return true;
	}
}

bool TFila_Desenfileirar(TFila* fila, TConta* conta)
{
	if(TFila_EhVazia(fila))
	{
		return false;
	}
	else
	{
		TFila aux;
		for(int i=fila->primeiro;i<fila->ultimo;i++)
		{
			aux.item[aux.primeiro] = fila->item[fila->primeiro+1];
			fila->item[fila->primeiro] = aux.item[aux.primeiro];
			aux.primeiro++;
		}
		fila->ultimo -= 1;
		return true;
	}
}

int TFila_Tamanho(TFila* fila)
{
	int i,cont=0;
	for(i=fila->primeiro;i<fila->ultimo;i++)
	{
		cont++;
	}
	return cont;
}

void TFila_Limpa(TFila* fila)
{
	TConta conta;
	if(TFila_EhVazia(fila))
	{
		cout<<"\nFila esta vazia..."<<endl<<endl;
	}
	else
	{
		while(TFila_Desenfileirar(fila,&conta));
		cout<<"\nA FILA FICOU LIMPA."<<endl<<endl;
	}
}

void TFila_Imprimir(TFila* fila)
{
	int i;
	if(TFila_EhVazia(fila))
	{
		cout<<"\nFila esta vazia..."<<endl<<endl;	
	}
	else
	{
		cout<<"\nOs dados na fila sao:\n\n";
		for(i=fila->primeiro;i<fila->ultimo;i++)
		{
			cout<<"CONTA BANCARIA "<<i+1<<" : "<<fila->item[i].num_conta<<endl;
			cout<<"SALDO: "<<fila->item[i].saldo<<endl<<endl;
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