/*
	Feito por: Felipe Fontenele de Ávila Magalhães
	Data: 09/01/2016
	Disciplina: Estrutura de Dados I
*/
#include"exe3.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 3                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se os conceitos basicos de ordenacao, sendo utilizado o metodo  ||"<<endl;
	cout<<"  || Quicksort(versao iterativa) implementado usando pilhas para armazenar os indices, um     ||"<<endl;
	cout<<"  || vetor eh inserido e eh feito sua ordenacao utilizando a ideia da 'divisao e conquista'.  ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	int quant;
	TNumero* numero;
	cout<<"\nDigite a quantidade de numeros que deseja ordenar(maior que 1 e menor que 51):\n";
	cin>>quant;
	while(quant<2 || quant>50)
	{
		cout<<"\n\nQUANTIDADE INVALIDA.FAVOR TENTAR NOVAMENTE.";
		cout<<"\nDigite a quantidade de numeros que deseja ordenar(maior que 1 e menor que 51):\n";
		cin>>quant;
	}
	Inicializar(&numero,quant);
	Inserir(numero,quant);
	QuickSort_iter(numero,quant);
	cout<<"\n - Ordenacao:"<<endl;
	cout<<"\n - - Quick.....: ";
	Imprimir(numero,quant);
	cout<<endl<<endl<<endl;
	
	return 0;
}