#include "pilha.h"

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
	pilha->topo = 0;
}

bool TPilha_EhVazia(TPilha* pilha)
{
	if(pilha->topo == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TPilha_Push(TPilha* pilha, TConta* conta)
{
	if(pilha->topo == MAX)
	{
		return false;
	}
	else
	{
		pilha->item[pilha->topo].num_conta = conta->num_conta;
		pilha->item[pilha->topo].saldo = conta->saldo;
		pilha->item[pilha->topo].chave = conta->chave;
		pilha->topo++;
		return true;
	}
}

bool TPilha_Pop(TPilha* pilha,TConta* conta)
{
	if(TPilha_EhVazia(pilha))
	{
		return false;
	}
	*conta = pilha->item[pilha->topo-1];
	pilha->topo--;
	return true;
}

int TPilha_Tamanho(TPilha* pilha)
{
	return pilha->topo;
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
	int i;
	if(TPilha_EhVazia(pilha))
	{
		cout<<"\nPilha esta vazia..."<<endl<<endl;	
	}
	else
	{
		cout<<"\nOs dados na pilha sao:\n\n";
		for(i=0; i< pilha->topo; i++)
		{
			cout<<"CONTA BANCARIA "<<i+1<<" : "<<pilha->item[i].num_conta<<endl;
			cout<<"SALDO: "<<pilha->item[i].saldo<<endl;
			cout<<"CHAVE: "<<pilha->item[i].chave<<endl<<endl;
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