/*
	Feito por: Felipe Fontenele de Ávila Magalhães
	Data: 08/01/2016
	Disciplina: Estrutura de Dados I
*/
#include"mergesort.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 1                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se os conceitos basicos de ordenacao, sendo utilizado o metodo  ||"<<endl;
	cout<<"  || Mergesort, na qual insere um vetor e eh feito sua ordenacao, utilizando a tatica         ||"<<endl;
	cout<<"  || da 'divisao e conquista'.(RECURSIVO)                                                                ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	int quant,comp=0,mov=0;
	TNumero* numero;
	cout<<"\nDigite a quantidade de numeros que deseja ordenar:\n";
	cin>>quant;
	Inicializar(&numero,quant);
	Inserir(numero,quant);
	MergeSort(numero,quant,&comp,&mov);
	cout<<"\n - Ordenacao:"<<endl;
	cout<<"\n - - Merge.....: ";
	Imprimir(numero,quant);
	cout<<endl<<endl;
	cout<<"\n - Comparacoes | Movimentacoes:";
	cout<<"\n - - Merge.....: "<<comp<<" | "<<mov<<" ."<<endl;
	cout<<endl<<endl;
	
	return 0;
}