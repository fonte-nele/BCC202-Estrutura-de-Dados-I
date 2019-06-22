/*
	Feito por: Felipe Fontenele de Ávila Magalhães
	Data: 18/01/2016
	Disciplina: Estrutura de Dados I
*/
#include"pratica05.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 1                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se os conceitos basicos de ordenacao,sendo utilizado os metodos ||"<<endl;
	cout<<"  || Bubblesort, SelectionSort e Insertionsort, na qual pergunta-se ao usuario a quantidade   ||"<<endl;
	cout<<"  || de vetores, insere os dados e faz a ordenacao dos mesmos.                                ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	int i,num_vetores,quant,comp1=0,mov1=0,comp2=0,mov2=0,comp3=0,mov3=0;
	TNumero* vetor1,*vetor2,*vetor3;
	cout<<"\nDigite a quantidade de vetores que deseja:\n";
	cin>>num_vetores;
	for(i=0;i<num_vetores;i++)
	{
		cout<<"\nDigite a quantidade de numeros do vetor "<<i+1<<" que deseja ordenar:\n";
		cin>>quant;
		Inicializar(&vetor1,quant);
		Inicializar(&vetor2,quant);
		Inicializar(&vetor3,quant);
		Inserir(vetor1,vetor2,vetor3,quant);
		Bolha(vetor1,quant,&comp1,&mov1);
		Selection(vetor2,quant,&comp2,&mov2);
		Insertion(vetor3,quant,&comp3,&mov3);
		cout<<"\n Vetor "<<i+1<<":\n";
		cout<<"\n - Ordenacao:\n";
		cout<<"\n - - Bubble....: ";
		Imprimir(vetor1,quant);
		cout<<"\n - - Selection.: ";
		Imprimir(vetor2,quant);
		cout<<"\n - - Insertion.: ";
		Imprimir(vetor3,quant);
		cout<<endl<<endl;
		cout<<"\n - Comparacoes | Movimentacoes:";
		cout<<"\n - - Bubble....: "<<comp1<<" | "<<mov1<<" ."<<endl;
		cout<<"\n - - Selection.: "<<comp2<<" | "<<mov2<<" ."<<endl;
		cout<<"\n - - Insertion.: "<<comp3<<" | "<<mov3<<" ."<<endl;
		comp1=0;
		mov1=0;
		comp2=0;
		mov2=0;
		comp3=0;
		mov3=0;
	}
	Liberar_memoria(vetor1);
	Liberar_memoria(vetor2);
	Liberar_memoria(vetor3);
	cout<<endl<<endl;
	
	return 0;
}