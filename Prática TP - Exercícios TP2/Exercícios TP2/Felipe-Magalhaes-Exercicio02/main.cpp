/*
  Feito por Felipe Fontenele de Ávila Magalhães
  Data: 12/01/2016
  Matéria: Estrutura de Dados I  
*/
#include"exe2.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 2                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se os conceitos basicos de ordenacao, sendo utilizado o metodo  ||"<<endl;
	cout<<"  || BubbleSort para ordenar uma sequencia de listas alfanumericas mantendo a ordem original, ||"<<endl;
	cout<<"  || isto eh, onde era numero e palavra continua a ser numero e palavra, porem ordenados.     ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	string lista;
	int i,quant;
	cout<<"\nDigite a quantidade de listas que deseja ordenar:"<<endl;
	cin>>quant;
	for(i=0;i<quant;i++)
	{
		cout<<"\n\nDigite a lista "<<i+1<<" que deseja ordenar:"<<endl;
		if(i==0)
		{
			cin.ignore();
		}
		getline(cin,lista);
		ordenacao_mexida(lista);
	}
	return 0;
}