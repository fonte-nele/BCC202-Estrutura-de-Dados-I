/*
  Feito por: Felipe Fontenele de Ávila Magalhães
  Matricula: 15.1.4331
  Data: 08/02/2016
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
	cout<<"  || Primeiramente, pergunta-se ao usuario a quantidade de listas que deseja ordenar e logo   ||"<<endl;
	cout<<"  || apos eh feito a ordenacao.                                                               ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	string lista;
	//Arquivos criados para salvar as listas digitadas e as listas ordenadas!!!
	ofstream saida,entrada;
	entrada.open("ENTRADA_DIGITADA.txt");
	saida.open("saida.txt");
	saida<<"ABAIXO ESTAO TODAS AS LISTAS DIGITADAS FEITO SUA DEVIDA ORDENACAO:"<<endl<<endl;
	int k,quant;
	cout<<"\nDigite a quantidade de listas que deseja ordenar:"<<endl;
	cin>>quant;
	
	for(k=0;k<quant;k++)
	{
		cout<<"\n\nDigite a lista "<<k+1<<" que deseja ordenar:"<<endl;
		if(k==0)
		{
			cin.ignore();
		}
		getline(cin,lista);
		while(!Verificar_pontuacao(&lista))
		{
			cout<<"\nLISTA DIGITADA INVALIDA, POIS FALTA PONTUACAO '.' PARA FINALIZAR A LISTA."<<endl;
			cout<<"\nDigite a lista "<<k+1<<" que deseja ordenar:"<<endl;
			if(k==0)
			{
				cin.ignore();
			}
			getline(cin,lista);
		}
		entrada<<"LISTA DIGITADA "<<k+1<<": "<<lista<<endl<<endl;
		int cont=1,i=0,j=1;
		//Contagem da quantidade de palavras e numeros!!!
		while(lista[i]!='.')
		{
			if(lista[i]==',')
			{
				if(lista[j]==' ')
				{
					cont++;
				}
			}
			i++;
			j++;
		}
		string *v1,*v2,*v3;
		int v4[cont],tam2=0,tam3=0;
		v1= new string[cont];
		Extrair_dados(v1,lista);
		for(i=0;i<cont;i++)
		{
			if(isalpha(v1[i][0]))
			{
				//Verificar tamanho do vetor de numeros e palavras.
				tam2++;
				//Flag para guardar as posicoes do vetor, 1-palavras 2-numeros.
				v4[i]=1;
			}
			else
			{
				tam3++;
				v4[i]=2;
			}
		}
		v2= new string[tam2];
		v3= new string[tam3];
		Separar_vetores(v1,v2,v3,cont);
		Bolha(v2,tam2);
		Bolha(v3,tam3);
		Ordenacao_mexida(v1,v2,v3,v4,cont);
		saida<<"LISTA ORDENADA "<<k+1<<": ";
		Imprimir(&saida,v1,cont);
		delete []v2;
		delete []v3;
		delete []v1;
	}
	entrada.close();
	saida.close();
	cout<<"\n\nLEMBRETE: TODOS OS DADOS DIGITADOS FORAM SALVOS EM ''ENTRADA_DIGITADA.TXT'' NA PASTA DE ORIGEM DESTE PROGRAMA."<<endl;
	cout<<"LEMBRETE 2: OS DADOS ORDENADOS FORAM SALVOS EM ''SAIDA.TXT'' NA PASTA DE ORIGEM DESTE PROGRAMA."<<endl;
	cout<<"\nPROGRAMA FINALIZADO COM SUCESSO..."<<endl<<endl;
	return 0;
}