/*
	Feito por: Felipe Fontenele de Ávila Magalhães
	Matrícula: 15.1.4331
	Data: 10/02/2016
	Disciplina: Estrutura de Dados I
*/
#include"pratica07-questao2.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 2                                              "<<endl;
	cout<<"   ============================================================================================ "<<endl;
	cout<<"  || Neste programa, trabalha-se os conceitos basicos de ordenacao,sendo utilizado os metodos ||"<<endl;
	cout<<"  || BubbleSort, SelectionSort, InsertionSort, MergeSort e QuickSort na qual pergunta-se ao   ||"<<endl;
	cout<<"  || usuario a quantidade de vetores e faz a ordenacao dos mesmos.                            ||"<<endl;
	cout<<"   ============================================================================================ "<<endl<<endl;
	
	int i,j,num_vetores,quant,comp=0,vetor_comp[9],vetor_mov[9],temp;
	TNumero* vetor,*aux;
	clock_t inicio1,fim1,total1,inicio2,fim2,total2,inicio3,fim3,total3,inicio4,fim4,total4;
	double tempo1,tempo2,tempo3,tempo4;
	cout<<"\nDigite a quantidade de vetores que deseja inserir:\n";
	cin>>num_vetores;
	for(i=0;i<num_vetores;i++)
	{
		for(j=0;j<10;j++)
		{
			//Inicializar vetor de comparacoes e movimentacoes com valor 0!!!
			vetor_comp[j]=0;
			vetor_mov[j]=0;
		}
		cout<<"\nDigite a quantidade de numeros do vetor "<<i+1<<" que deseja ordenar:\n";
		cin>>quant;
		temp=quant;
		Inicializar(&vetor,quant);
		Inicializar(&aux,quant);
		Inserir(vetor,quant);
		//Fazer copia do vetor original para auxiliar para poder ser ordenado!!!
		Copiar_Vetores(vetor,aux,quant);
		Bolha(aux,quant,&comp,vetor_mov);
		cout<<"\n Vetor "<<i+1<<":\n";
		cout<<"\n - Ordenacao:\n";
		cout<<"\n - - Bubble....: ";
		Imprimir(aux,quant);
		Copiar_Vetores(vetor,aux,quant);
		Selection(aux,quant,vetor_comp,vetor_mov);
		cout<<"\n - - Selection.: ";
		Imprimir(aux,quant);
		Copiar_Vetores(vetor,aux,quant);
		Insertion(aux,quant,vetor_comp,vetor_mov);
		cout<<"\n - - Insertion.: ";
		Imprimir(aux,quant);
		Copiar_Vetores(vetor,aux,quant);
		MergeSort(aux,quant,vetor_comp,vetor_mov);
		cout<<"\n - - Merge.....: ";
		Imprimir(aux,quant);
		Copiar_Vetores(vetor,aux,quant);
		QuickSort(aux,quant,vetor_comp,vetor_mov);
		cout<<"\n - - Quick.....: ";
		Imprimir(aux,quant);
		inicio1=clock();
		Copiar_Vetores(vetor,aux,quant);
		ShellSort01(aux,quant,vetor_comp,vetor_mov);
		cout<<"\n - - Shell01...: ";
		Imprimir(aux,quant);
		fim1=clock();
		total1=fim1-inicio1;
		//TEMPO EM MILISSEGUNDOS, MELHOR ESCALA PARA ESSA SITUACAO DEVIDO AOS POUCOS DADOS DE ENTRADA.
		tempo1=(((double)total1)/CLOCKS_PER_SEC)*1000;
		inicio2=clock();
		Copiar_Vetores(vetor,aux,quant);
		ShellSort02(aux,quant,vetor_comp,vetor_mov);
		cout<<"\n - - Shell02...: ";
		Imprimir(aux,quant);
		fim2=clock();
		total2=fim2-inicio2;
		//TEMPO EM MILISSEGUNDOS, MELHOR ESCALA PARA ESSA SITUACAO DEVIDO AOS POUCOS DADOS DE ENTRADA.
		tempo2=(((double)total2)/CLOCKS_PER_SEC)*1000;
		inicio3=clock();
		Copiar_Vetores(vetor,aux,quant);
		ShellSort03(aux,quant,vetor_comp,vetor_mov);
		cout<<"\n - - Shell03...: ";
		Imprimir(aux,temp);
		fim3=clock();
		total3=fim3-inicio3;
		//TEMPO EM MILISSEGUNDOS, MELHOR ESCALA PARA ESSA SITUACAO DEVIDO AOS POUCOS DADOS DE ENTRADA.
		tempo3=(((double)total3)/CLOCKS_PER_SEC)*1000;
		inicio4=clock();
		HeapSort(vetor,quant,vetor_comp,vetor_mov);
		cout<<"\n - - Heap......: ";
		Imprimir(vetor,quant);
		fim4=clock();
		total4=fim4-inicio4;
		//TEMPO EM MILISSEGUNDOS, MELHOR ESCALA PARA ESSA SITUACAO DEVIDO AOS POUCOS DADOS DE ENTRADA.
		tempo4=(((double)total4)/CLOCKS_PER_SEC)*1000;
		cout<<endl<<endl;
		
		cout<<"\n - Comparacoes | Movimentacoes | Tempo:";
		cout<<"\n - - Bubble....: "<<comp<<" | "<<vetor_mov[0]<<" ."<<endl;
		cout<<"\n - - Selection.: "<<vetor_comp[1]<<" | "<<vetor_mov[1]<<" ."<<endl;
		cout<<"\n - - Insertion.: "<<vetor_comp[2]<<" | "<<vetor_mov[2]<<" ."<<endl;
		cout<<"\n - - Merge.....: "<<vetor_comp[3]<<" | "<<vetor_mov[3]<<" ."<<endl;
		cout<<"\n - - Quick.....: "<<vetor_comp[4]<<" | "<<vetor_mov[4]<<" ."<<endl;
		cout<<"\n - - Shell01...: "<<vetor_comp[5]<<" | "<<vetor_mov[5]<<" | "<<tempo1<<" ."<<endl;
		cout<<"\n - - Shell02...: "<<vetor_comp[6]<<" | "<<vetor_mov[6]<<" | "<<tempo2<<" ."<<endl;
		cout<<"\n - - Shell03...: "<<vetor_comp[7]<<" | "<<vetor_mov[7]<<" | "<<tempo3<<" ."<<endl;
		cout<<"\n - - Heap......: "<<vetor_comp[8]<<" | "<<vetor_mov[8]<<" | "<<tempo4<<" ."<<endl;
		comp=0;
	}
	Liberar_memoria(vetor);
	Liberar_memoria(aux);
	cout<<endl<<endl;
	
	return 0;
}