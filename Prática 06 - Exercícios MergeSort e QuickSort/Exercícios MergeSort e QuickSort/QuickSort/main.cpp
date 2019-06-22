/*
	Feito por: Felipe Fontenele de Ávila Magalhães
	Data: 08/01/2016
	Disciplina: Estrutura de Dados I
*/
#include"quicksort.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 2                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se os conceitos basicos de ordenacao, sendo utilizado o metodo  ||"<<endl;
	cout<<"  || Quicksort, na qual insere um vetor e eh feito sua ordenacao, utilizando a tatica         ||"<<endl;
	cout<<"  || da 'divisao e conquista'.                                                                ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	int quant,comp=0,mov=0;
	TNumero* numero;
	cout<<"\nDigite a quantidade de numeros que deseja ordenar:\n";
	cin>>quant;
	Inicializar(&numero,quant);
	Inserir(numero,quant);
	QuickSort(numero,quant,&comp,&mov);
	cout<<"\n - Ordenacao:"<<endl;
	cout<<"\n - - Quick.....: ";
	Imprimir(numero,quant);
	cout<<endl<<endl;
	cout<<"\n - Comparacoes | Movimentacoes:";
	cout<<"\n - - Quick.....: "<<comp<<" | "<<mov<<" ."<<endl;
	cout<<endl<<endl;
	
	return 0;
}