/*
	Feito por: Felipe Fontenele de Ávila Magalhães
	Data: 25/01/2016
	Disciplina: Estrutura de Dados I
*/
#include"pratica06.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 1                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se os conceitos basicos de ordenacao,sendo utilizado os metodos ||"<<endl;
	cout<<"  || BubbleSort, SelectionSort, InsertionSort, MergeSort e QuickSort na qual pergunta-se ao   ||"<<endl;
	cout<<"  || usuario a quantidade de vetores e faz a ordenacao dos mesmos.                            ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	int i,num_vetores,quant,comp1=0,mov1=0,comp2=0,mov2=0,comp3=0,mov3=0,comp4=0,mov4=0,comp5=0,mov5=0;
	TNumero* vetor1,*vetor2,*vetor3,*vetor4,*vetor5;
	cout<<"\nDigite a quantidade de vetores que deseja:\n";
	cin>>num_vetores;
	for(i=0;i<num_vetores;i++)
	{
		cout<<"\nDigite a quantidade de numeros do vetor "<<i+1<<" que deseja ordenar:\n";
		cin>>quant;
		Inicializar(&vetor1,quant);
		Inicializar(&vetor2,quant);
		Inicializar(&vetor3,quant);
		Inicializar(&vetor4,quant);
		Inicializar(&vetor5,quant);
		Inserir(vetor1,vetor2,vetor3,vetor4,vetor5,quant);
		Bolha(vetor1,quant,&comp1,&mov1);
		Selection(vetor2,quant,&comp2,&mov2);
		Insertion(vetor3,quant,&comp3,&mov3);
		MergeSort(vetor4,quant,&comp4,&mov4);
		QuickSort(vetor5,quant,&comp5,&mov5);
		cout<<"\n Vetor "<<i+1<<":\n";
		cout<<"\n - Ordenacao:\n";
		cout<<"\n - - Bubble....: ";
		Imprimir(vetor1,quant);
		cout<<"\n - - Selection.: ";
		Imprimir(vetor2,quant);
		cout<<"\n - - Insertion.: ";
		Imprimir(vetor3,quant);
		cout<<"\n - - Merge.....: ";
		Imprimir(vetor4,quant);
		cout<<"\n - - Quick.....: ";
		Imprimir(vetor5,quant);
		cout<<endl<<endl;
		cout<<"\n - Comparacoes | Movimentacoes:";
		cout<<"\n - - Bubble....: "<<comp1<<" | "<<mov1<<" ."<<endl;
		cout<<"\n - - Selection.: "<<comp2<<" | "<<mov2<<" ."<<endl;
		cout<<"\n - - Insertion.: "<<comp3<<" | "<<mov3<<" ."<<endl;
		cout<<"\n - - Merge.....: "<<comp4<<" | "<<mov4<<" ."<<endl;
		cout<<"\n - - Quick.....: "<<comp5<<" | "<<mov5<<" ."<<endl;
		comp1=0;
		mov1=0;
		comp2=0;
		mov2=0;
		comp3=0;
		mov3=0;
		comp4=0;
		mov4=0;
		comp5=0;
		mov5=0;
	}
	Liberar_memoria(vetor1);
	Liberar_memoria(vetor2);
	Liberar_memoria(vetor3);
	Liberar_memoria(vetor4);
	Liberar_memoria(vetor5);
	cout<<endl<<endl;
	
	return 0;
}