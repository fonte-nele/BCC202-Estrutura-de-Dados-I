#include"exe1.h"

void Inicializar_TNumero(TNumero** numero)
{
	(*numero) = new TNumero;
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
	cout<<" ||   1 - Inicializar a pilha.                               ||"<<endl;
    cout<<" ||   2 - Verificar se a pilha esta vazia.                   ||"<<endl;
    cout<<"  M   3 - Inserir(PUSH) numero no topo da pilha.             M"<<endl;
	cout<<"  E   4 - Retirar(POP) numero no topo da pilha.              E"<<endl;
    cout<<"  N   5 - Retornar o tamanho da pilha.                       N"<<endl;
	cout<<"  U   6 - Limpar dados da pilha.                             U"<<endl;
	cout<<" ||   7 - Imprimir a pilha.                                  ||"<<endl;
	cout<<" ||   8 - Sair.                                              ||"<<endl;
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
	if(pilha->fundo == pilha->topo || pilha->tamanho==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TPilha_Push(TPilha* fila1,TPilha* fila2,TNumero* numero)
{
	if(!TPilha_EhVazia(fila1))
	{
		//Transferencia dos dados da fila 1 para a fila2!!!
		TCelula *aux;
		aux = fila1->fundo->prox;
		while(aux != NULL)
		{
			fila2->topo->prox = new TCelula;
			fila2->topo=fila2->topo->prox;
			fila2->topo->item.num=aux->item.num;
			fila2->topo->prox=NULL;
			fila2->tamanho++;
			fila1->tamanho--;
			aux = aux->prox;
		}
		//Fila 1 fica sem nenhum dado nesse momento!!!
		TPilha_Inicia(fila1);
	}
	//Insercao do dado digitado pelo usuario na fila 1!!!
	fila1->topo->prox = new TCelula;
	fila1->topo = fila1->topo->prox;
	fila1->topo->item.num = numero->num;
	fila1->topo->prox = NULL;
	fila1->tamanho++;
	//Devolucao dos dados da fila 2 para a fila 1!!!
	TCelula *aux2;
	aux2 = fila2->fundo->prox;
	while(aux2!=NULL)
	{
		fila1->topo->prox=new TCelula;
		fila1->topo=fila1->topo->prox;
		fila1->topo->item.num=aux2->item.num;
		fila1->topo->prox=NULL;
		fila1->tamanho++;
		fila2->tamanho--;
		aux2=aux2->prox;
	}
	//Fila 2 fica sem nenhum dado nesse momento!!!
	TPilha_Inicia(fila2);
}

bool TPilha_Pop(TPilha* fila1, TNumero* numero)
{
	if(TPilha_EhVazia(fila1))
	{
		return false;
	}
	else
	{
		TCelula* aux;	
		aux = fila1->fundo->prox;
		fila1->fundo->prox = fila1->fundo->prox->prox;
		fila1->tamanho--;
		*numero = aux->item;
		if(fila1->tamanho==0)
		{
			TPilha_Inicia(fila1);
		}
		delete aux;
		return true;
	}
}

int TPilha_Tamanho(TPilha* pilha)
{
	return pilha->tamanho;
}

void TPilha_Limpa(TPilha* fila1)
{
	TNumero numero;
	if(TPilha_EhVazia(fila1))
	{
		cout<<"\nA PILHA ESTA VAZIA..."<<endl<<endl;
	}
	else
	{
		while(TPilha_Pop(fila1,&numero));
		cout<<"\nA PILHA FICOU LIMPA."<<endl<<endl;
	}
}

void TPilha_Imprimir(TPilha* pilha)
{
	TCelula *aux;
	aux = pilha->fundo->prox;
	if(TPilha_EhVazia(pilha))
	{
		cout<<"\nA PILHA ESTA VAZIA..."<<endl;
	}
	else
	{
		cout<<"\nOs dados na pilha sao:"<<endl;
		while(aux != NULL)
		{
			cout<<"\nNUMERO: "<<aux->item.num<<endl;
			aux = aux->prox;
		}
	}
	cout<<endl;
}

void liberar_memoria_TNumero(TNumero* numero)
{
	delete numero;
}

void liberar_memoria_TPilha(TPilha* pilha)
{
	delete pilha;
}