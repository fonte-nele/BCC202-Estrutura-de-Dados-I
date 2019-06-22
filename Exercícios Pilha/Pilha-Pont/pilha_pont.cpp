#include"pilha_pont.h"

void Inicializar_TConta(TConta** conta)
{
	(*conta) = new TConta;
}

void Inicializar_TPilha(TPilha** pilha)
{
	(*pilha) = new TPilha;
}

int Menu()
{
	int escolha;
	cout<<"  ============================MENU============================"<<endl;
	cout<<" ||                                                          ||"<<endl;
    cout<<" ||                                                          ||"<<endl;
	cout<<" || 1 - Inicializar a pilha.                                 ||"<<endl;
    cout<<" || 2 - Verificar se a pilha esta vazia.                     ||"<<endl;
    cout<<" || 3 - Inserir dados bancarios no topo da pilha.            ||"<<endl;
	cout<<" || 4 - Retirar dados bancarios no topo da pilha.            ||"<<endl;
    cout<<" || 5 - Retornar o tamanho da pilha.                         ||"<<endl;
	cout<<" || 6 - Limpar dados da pilha.                               ||"<<endl;
	cout<<" || 7 - Imprimir a pilha.                                    ||"<<endl;
	cout<<" || 8 - Sair.                                                ||"<<endl;
	cout<<" ||                                                          ||"<<endl;
	cout<<"  ============================MENU============================"<<endl;
    cout<<endl;
	cout<<"  Escolha: ";  
	cin>>escolha;
    cin.ignore();
    return escolha;
}

void TPilha_Inicia(TPilha* pilha)
{
	pilha -> topo = new TCelula;
	pilha -> fundo = pilha -> topo;
	pilha -> topo -> prox = NULL;
	pilha -> tamanho = 0;
}

bool TPilha_EhVazia(TPilha* pilha)
{
	if(pilha->fundo == pilha->topo)
	{
		if(pilha->tamanho == 0)
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

void TPilha_Push(TPilha* pilha, TConta* conta)
{
	TCelula* aux;
	aux = new TCelula;
	pilha->topo->item.num_conta = conta->num_conta;
	pilha->topo->item.saldo = conta->saldo;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;
}

bool TPilha_Pop(TPilha* pilha, TConta* conta)
{
	if(TPilha_EhVazia(pilha))
	{
		return false;
	}
	TCelula *aux;
	aux = pilha->topo;
	pilha->topo = aux->prox;
	conta->num_conta = aux->prox->item.num_conta;
	conta->saldo = aux->prox->item.saldo;
	delete aux;
	pilha->tamanho--;
	return true;
}

int TPilha_Tamanho(TPilha* pilha)
{
	return pilha->tamanho;
}

void TPilha_Limpa(TPilha* pilha)
{
	TConta conta;
	if(TPilha_EhVazia(pilha))
	{
		cout<<"\nPilha esta vazia..."<<endl<<endl;
	}
	else
	{
		while(TPilha_Pop(pilha,&conta));
		cout<<"\nA PILHA FICOU LIMPA."<<endl<<endl;
	}
}

void TPilha_Imprimir(TPilha* pilha)
{
	int i=1;
	TCelula *aux;
	aux = pilha->topo->prox;
	if(TPilha_EhVazia(pilha))
	{
		cout<<"\nA pilha esta vazia..."<<endl;
	}
	else
	{
		cout<<"\nOs dados na pilha sao:"<<endl;
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

void liberar_memoria_TPilha(TPilha* pilha)
{
	delete pilha;
}