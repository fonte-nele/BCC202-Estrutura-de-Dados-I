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
	cout<<" || 1 - Inicializar a pilha.                                 ||"<<endl;
    cout<<" || 2 - Verificar se a pilha esta vazia.                     ||"<<endl;
    cout<<" || 3 - Inserir(PUSH) numero no topo da pilha.               ||"<<endl;
	cout<<" || 4 - Retirar(POP) numero no topo da pilha.                ||"<<endl;
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

void TPilha_Filas(TPilha* fila1,TPilha* fila2,TNumero* numero)
{
	if(!TPilha_EhVazia(fila1))
	{
		TCelula *aux;
		aux = fila1->topo->prox;
		while(aux != NULL)
		{
			fila2->fundo->prox = new TCelula;
			fila2->fundo=fila2->fundo->prox;
			fila2->fundo->item.num=aux->item.num;
			fila2->fundo->prox=NULL;
			fila2->tamanho++;
			fila1->tamanho--;
			aux = aux->prox;
		}
		TPilha_Inicia(fila1);
		
	}
	TPilha_Push(fila1,numero);
	TCelula *aux2;
	aux2 = fila2->topo->prox;
	while(aux2!=NULL)
	{
		fila1->fundo->prox=new TCelula;
		fila1->fundo=fila1->fundo->prox;
		fila1->fundo->item.num=aux2->item.num;
		fila1->fundo->prox=NULL;
		fila1->tamanho++;
		fila2->tamanho--;
		aux2=aux2->prox;
	}
	TPilha_Inicia(fila2);
}

void TPilha_Push(TPilha* fila, TNumero* numero)
{
	fila->fundo->prox = new TCelula;
	fila->fundo = fila->fundo->prox;
	fila->fundo->item.num = numero->num;
	fila->fundo->prox = NULL;
	fila->tamanho++;
}

bool TPilha_Pop(TPilha* fila, TNumero* numero)
{
	if(TPilha_EhVazia(fila))
	{
		return false;
	}
	TCelula* aux;	
	aux = fila->topo->prox;
	fila->topo->prox = fila->topo->prox->prox;
	*numero = aux->item;
	delete aux;
	return true;
}

int TPilha_Tamanho(TPilha* pilha)
{
	return pilha->tamanho;
}

void TPilha_Limpa(TPilha* pilha)
{
	TNumero numero;
	if(TPilha_EhVazia(pilha))
	{
		cout<<"\nPilha esta vazia..."<<endl<<endl;
	}
	else
	{
		while(TPilha_Pop(pilha,&numero));
		cout<<"\nA PILHA FICOU LIMPA."<<endl<<endl;
	}
}

void TPilha_Imprimir(TPilha* pilha)
{
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
			cout<<"\nNUMERO: "<<aux->item.num<<endl;
			aux = aux->prox;
		}
	}	
}

void liberar_memoria_TNumero(TNumero* numero)
{
	delete numero;
}

void liberar_memoria_TPilha(TPilha* pilha)
{
	delete pilha;
}