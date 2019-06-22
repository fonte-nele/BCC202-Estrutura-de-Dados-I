/*
	Feito por: Felipe Fontenele de Ávila Magalhães
	Matrícula: 15.1.4331
	Data: 12/02/2016
	Disciplina: Estrutura de Dados I
*/
#include"exe3.h"

int main()
{
	cout<<endl<<endl;
	cout<<"                                       EXERCICIO 3                                              "<<endl;
	cout<<"   ============================================================================================== "<<endl;
	cout<<"  || Neste programa, trabalha-se os conceitos basicos de ordenacao, sendo utilizado os metodos  ||"<<endl;
	cout<<"  || BubbleSort, SelectionSort, InsertionSort, MergeSort, QuickSort e ShellSort para ordenacao  ||"<<endl;
	cout<<"  || de arquivos com um milhao de dados. Foram feitos testes com arquivos gerados aleatorios,   ||"<<endl;
	cout<<"  || arquivos em ordem crescente e arquivos em ordem decrescente.BOA SORTE na demora da execucao||"<<endl;
	cout<<"   ============================================================================================== "<<endl<<endl;
	
	TNumero *v1,*aux1,*v2,*aux2,*v3,*aux3;
	Inicializar(&v1);
	Inicializar(&aux1);
	Inicializar(&v2);
	Inicializar(&aux2);
	Inicializar(&v3);
	Inicializar(&aux3);
	clock_t inicio[18],fim[18],total[18];
	double tempo[18];
	long int j;
	unsigned long int vetor_comp[18],vetor_mov[18];
	//Inicializar vetor de comparação, movimentação e tempo com valor 0!!!
	for(j=0;j<19;j++)
	{
		vetor_comp[j]=0;
		vetor_mov[j]=0;
		tempo[j]=0;
	}
	ofstream entrada1,entrada2,entrada3,saida1,saida2,saida3;
	//Entrada de dados aleatório!!!
	entrada1.open("entrada_aleatoria.txt");
	entrada1<<"Entrada de dados com numeros gerados aleatorios:"<<endl<<endl;
	cout<<"Carregando entrada de dados aleatorios!!!"<<endl<<endl;
	cout<<"LOADING I....";
	long int i,k,temp;
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
	{
		temp=(rand()%1001)*(rand()%1001);
		v1[i].chave=temp;
		entrada1<<temp<<" ";
	}
	entrada1.close();
	//Entrada de dados em ordem crescente!!!
	entrada2.open("entrada_crescente.txt");
	entrada2<<"Entrada de dados com numeros em ordem crescente:"<<endl<<endl;
	cout<<"\n\nCarregando entrada de dados em ordem crescente!!!"<<endl<<endl;
	cout<<"LOADING II....";
	for(i=0,k=1;i<n;i++,k++)
	{
		v2[i].chave=k;
		entrada2<<k<<" ";
	}
	entrada2.close();
	//Entrada de dados em ordem decrescente!!!
	entrada3.open("entrada_decrescente.txt");
	entrada3<<"Entrada de dados com numeros em ordem decrescente:"<<endl<<endl;
	cout<<"\n\nCarregando entrada de dados em ordem decrescente!!!"<<endl<<endl;
	cout<<"LOADING III....";
	for(i=0,k=n;i<n;i++,k--)
	{
		v3[i].chave=k;
		entrada3<<k<<" ";
	}
	entrada3.close();
	
	//Ordenacao do vetor aleatorio com os metodos pedidos!!!
	inicio[0]=clock();
	Copiar_Vetor(v1,aux1);
	saida1.open("saida_ordenacao_aleatoria.txt");
	saida1<<"Saida de dados com numeros gerados aleatorios:"<<endl<<endl;
	saida1<<"ORDENACAO BUBBLESORT:"<<endl;
	cout<<"\n\nCarregando ordenacao BUBBLESORT de numeros aleatorios!!!"<<endl<<endl;
	cout<<"LOADING IV....";
	Bolha(aux1,vetor_comp,vetor_mov,0);
	for(i=0;i<n;i++)
	{
		saida1<<aux1[i].chave<<" ";
	}
	saida1<<endl<<endl;
	fim[0]=clock();
	total[0]=fim[0]-inicio[0];
	tempo[0]=((double)total[0])/CLOCKS_PER_SEC;
	
	inicio[1]=clock();
	Copiar_Vetor(v1,aux1);
	saida1<<"ORDENACAO SELECTIONSORT:"<<endl;
	cout<<"\n\nCarregando ordenacao SELECTIONSORT de numeros aleatorios!!!"<<endl<<endl;
	cout<<"LOADING V....";
	Selection(aux1,vetor_comp,vetor_mov,1);
	for(i=0;i<n;i++)
	{
		saida1<<aux1[i].chave<<" ";
	}
	saida1<<endl<<endl;
	fim[1]=clock();
	total[1]=fim[1]-inicio[1];
	tempo[1]=((double)total[1])/CLOCKS_PER_SEC;
	
	inicio[2]=clock();
	Copiar_Vetor(v1,aux1);
	saida1<<"ORDENACAO INSERTIONSORT:"<<endl;
	cout<<"\n\nCarregando ordenacao INSERTIONSORT de numeros aleatorios!!!"<<endl<<endl;
	cout<<"LOADING VI....";
	Insertion(aux1,vetor_comp,vetor_mov,2);
	for(i=0;i<n;i++)
	{
		saida1<<aux1[i].chave<<" ";
	}
	saida1<<endl<<endl;
	fim[2]=clock();
	total[2]=fim[2]-inicio[2];
	tempo[2]=((double)total[2])/CLOCKS_PER_SEC;
	
	inicio[3]=clock();
	Copiar_Vetor(v1,aux1);
	saida1<<"ORDENACAO MERGESORT:"<<endl;
	cout<<"\n\nCarregando ordenacao MERGESORT de numeros aleatorios!!!"<<endl<<endl;
	cout<<"LOADING VII....";
	MergeSort(aux1,vetor_comp,vetor_mov,3);
	for(i=0;i<n;i++)
	{
		saida1<<aux1[i].chave<<" ";
	}
	saida1<<endl<<endl;
	fim[3]=clock();
	total[3]=fim[3]-inicio[3];
	tempo[3]=((double)total[3])/CLOCKS_PER_SEC;
	
	inicio[4]=clock();
	Copiar_Vetor(v1,aux1);
	saida1<<"ORDENACAO QUICKSORT:"<<endl;
	cout<<"\n\nCarregando ordenacao QUICKSORT de numeros aleatorios!!!"<<endl<<endl;
	cout<<"LOADING VIII....";
	QuickSort(aux1,vetor_comp,vetor_mov,4);
	for(i=0;i<n;i++)
	{
		saida1<<aux1[i].chave<<" ";
	}
	saida1<<endl<<endl;
	fim[4]=clock();
	total[4]=fim[4]-inicio[4];
	tempo[4]=((double)total[4])/CLOCKS_PER_SEC;
	
	inicio[5]=clock();
	Copiar_Vetor(v1,aux1);
	saida1<<"ORDENACAO SHELLSORT:"<<endl;
	cout<<"\n\nCarregando ordenacao SHELLSORT de numeros aleatorios!!!"<<endl<<endl;
	cout<<"LOADING IX....";
	ShellSort(aux1,vetor_comp,vetor_mov,5);
	for(i=0;i<n;i++)
	{
		saida1<<aux1[i].chave<<" ";
	}
	saida1<<endl<<endl;
	fim[5]=clock();
	total[5]=fim[5]-inicio[5];
	tempo[5]=((double)total[5])/CLOCKS_PER_SEC;
	saida1.close();
	Liberar_memoria(v1);
	Liberar_memoria(aux1);
	
	//Ordenacao do vetor em ordem crescente com os metodos pedidos!!!
	inicio[6]=clock();
	Copiar_Vetor(v2,aux2);
	saida2.open("saida_ordenacao_crescente.txt");
	saida2<<"Saida de dados com numeros gerados em ordem crescente:"<<endl<<endl;
	saida2<<"ORDENACAO BUBBLESORT:"<<endl;
	cout<<"\n\nCarregando ordenacao BUBBLESORT de numeros gerados em ordem crescente!!!"<<endl<<endl;
	cout<<"LOADING X....";
	Bolha(aux2,vetor_comp,vetor_mov,6);
	for(i=0;i<n;i++)
	{
		saida2<<aux2[i].chave<<" ";
	}
	saida2<<endl<<endl;
	fim[6]=clock();
	total[6]=fim[6]-inicio[6];
	tempo[6]=((double)total[6])/CLOCKS_PER_SEC;
	
	inicio[7]=clock();
	Copiar_Vetor(v2,aux2);
	saida2<<"ORDENACAO SELECTIONSORT:"<<endl;
	cout<<"\n\nCarregando ordenacao SELECTIONSORT de numeros gerados em ordem crescente!!!"<<endl<<endl;
	cout<<"LOADING XI....";
	Selection(aux2,vetor_comp,vetor_mov,7);
	for(i=0;i<n;i++)
	{
		saida2<<aux2[i].chave<<" ";
	}
	saida2<<endl<<endl;
	fim[7]=clock();
	total[7]=fim[7]-inicio[7];
	tempo[7]=((double)total[7])/CLOCKS_PER_SEC;
	
	inicio[8]=clock();
	Copiar_Vetor(v2,aux2);
	saida2<<"ORDENACAO INSERTIONSORT:"<<endl;
	cout<<"\n\nCarregando ordenacao INSERTIONSORT de numeros gerados em ordem crescente!!!"<<endl<<endl;
	cout<<"LOADING XII....";
	Insertion(aux2,vetor_comp,vetor_mov,8);
	for(i=0;i<n;i++)
	{
		saida2<<aux2[i].chave<<" ";
	}
	saida2<<endl<<endl;
	fim[8]=clock();
	total[8]=fim[8]-inicio[8];
	tempo[8]=((double)total[8])/CLOCKS_PER_SEC;
	
	inicio[9]=clock();
	Copiar_Vetor(v2,aux2);
	saida2<<"ORDENACAO MERGESORT:"<<endl;
	cout<<"\n\nCarregando ordenacao MERGESORT de numeros gerados em ordem crescente!!!"<<endl<<endl;
	cout<<"LOADING XIII....";
	MergeSort(aux2,vetor_comp,vetor_mov,9);
	for(i=0;i<n;i++)
	{
		saida2<<aux2[i].chave<<" ";
	}
	saida2<<endl<<endl;
	fim[9]=clock();
	total[9]=fim[9]-inicio[9];
	tempo[9]=((double)total[9])/CLOCKS_PER_SEC;
	
	inicio[10]=clock();
	Copiar_Vetor(v2,aux2);
	saida2<<"ORDENACAO QUICKSORT:"<<endl;
	cout<<"\n\nCarregando ordenacao QUICKSORT de numeros gerados em ordem crescente!!!"<<endl<<endl;
	cout<<"LOADING XIV....";
	QuickSort(aux2,vetor_comp,vetor_mov,10);
	for(i=0;i<n;i++)
	{
		saida2<<aux2[i].chave<<" ";
	}
	saida2<<endl<<endl;
	fim[10]=clock();
	total[10]=fim[10]-inicio[10];
	tempo[10]=((double)total[10])/CLOCKS_PER_SEC;
	
	inicio[11]=clock();
	Copiar_Vetor(v2,aux2);
	saida2<<"ORDENACAO SHELLSORT:"<<endl;
	cout<<"\n\nCarregando ordenacao SHELLSORT de numeros gerados em ordem crescente!!!"<<endl<<endl;
	cout<<"LOADING XV....";
	ShellSort(aux2,vetor_comp,vetor_mov,11);
	for(i=0;i<n;i++)
	{
		saida2<<aux2[i].chave<<" ";
	}
	saida2<<endl<<endl;
	fim[11]=clock();
	total[11]=fim[11]-inicio[11];
	tempo[11]=((double)total[11])/CLOCKS_PER_SEC;
	saida2.close();
	Liberar_memoria(v2);
	Liberar_memoria(aux2);
	
	//Ordenacao do vetor em ordem decrescente com os metodos pedidos!!!
	inicio[12]=clock();
	Copiar_Vetor(v3,aux3);
	saida3.open("saida_ordenacao_decrescente.txt");
	saida3<<"Saida de dados com numeros gerados em ordem decrescente:"<<endl<<endl;
	saida3<<"ORDENACAO BUBBLESORT:"<<endl;
	cout<<"\n\nCarregando ordenacao BUBBLESORT de numeros gerados em ordem decrescente!!!"<<endl<<endl;
	cout<<"LOADING XVI....";
	Bolha(aux3,vetor_comp,vetor_mov,12);
	for(i=0;i<n;i++)
	{
		saida3<<aux3[i].chave<<" ";
	}
	saida3<<endl<<endl;
	fim[12]=clock();
	total[12]=fim[12]-inicio[12];
	tempo[12]=((double)total[12])/CLOCKS_PER_SEC;
	
	inicio[13]=clock();
	Copiar_Vetor(v3,aux3);
	saida3<<"ORDENACAO SELECTIONSORT:"<<endl;
	cout<<"\n\nCarregando ordenacao SELECTIONSORT de numeros gerados em ordem decrescente!!!"<<endl<<endl;
	cout<<"LOADING XVII....";
	Selection(aux3,vetor_comp,vetor_mov,13);
	for(i=0;i<n;i++)
	{
		saida3<<aux3[i].chave<<" ";
	}
	saida3<<endl<<endl;
	fim[13]=clock();
	total[13]=fim[13]-inicio[13];
	tempo[13]=((double)total[13])/CLOCKS_PER_SEC;
	
	inicio[14]=clock();
	Copiar_Vetor(v3,aux3);
	saida3<<"ORDENACAO INSERTIONSORT:"<<endl;
	cout<<"\n\nCarregando ordenacao INSERTIONSORT de numeros gerados em ordem decrescente!!!"<<endl<<endl;
	cout<<"LOADING XVIII....";
	Insertion(aux3,vetor_comp,vetor_mov,14);
	for(i=0;i<n;i++)
	{
		saida3<<aux3[i].chave<<" ";
	}
	saida3<<endl<<endl;
	fim[14]=clock();
	total[14]=fim[14]-inicio[14];
	tempo[14]=((double)total[14])/CLOCKS_PER_SEC;
	
	inicio[15]=clock();
	Copiar_Vetor(v3,aux3);
	saida3<<"ORDENACAO MERGESORT:"<<endl;
	cout<<"\n\nCarregando ordenacao MERGESORT de numeros gerados em ordem decrescente!!!"<<endl<<endl;
	cout<<"LOADING XIX....";
	MergeSort(aux3,vetor_comp,vetor_mov,15);
	for(i=0;i<n;i++)
	{
		saida3<<aux3[i].chave<<" ";
	}
	saida3<<endl<<endl;
	fim[15]=clock();
	total[15]=fim[15]-inicio[15];
	tempo[15]=((double)total[15])/CLOCKS_PER_SEC;
	
	inicio[16]=clock();
	Copiar_Vetor(v3,aux3);
	saida3<<"ORDENACAO QUICKSORT:"<<endl;
	cout<<"\n\nCarregando ordenacao QUICKSORT de numeros gerados em ordem decrescente!!!"<<endl<<endl;
	cout<<"LOADING XX....";
	QuickSort(aux3,vetor_comp,vetor_mov,16);
	for(i=0;i<n;i++)
	{
		saida3<<aux3[i].chave<<" ";
	}
	saida3<<endl<<endl;
	fim[16]=clock();
	total[16]=fim[16]-inicio[16];
	tempo[16]=((double)total[16])/CLOCKS_PER_SEC;
	
	inicio[17]=clock();
	Copiar_Vetor(v3,aux3);
	saida3<<"ORDENACAO SHELLSORT:"<<endl;
	cout<<"\n\nCarregando ordenacao SHELLSORT de numeros gerados em ordem decrescente!!!"<<endl<<endl;
	cout<<"LOADING XXI....";
	ShellSort(aux3,vetor_comp,vetor_mov,17);
	for(i=0;i<n;i++)
	{
		saida3<<aux3[i].chave<<" ";
	}
	saida3<<endl<<endl;
	fim[17]=clock();
	total[17]=fim[17]-inicio[17];
	tempo[17]=((double)total[17])/CLOCKS_PER_SEC;
	saida3.close();
	Liberar_memoria(v3);
	Liberar_memoria(aux3);
	
	cout<<endl<<endl;
	cout<<"    ===================================RESULTADOS==================================="<<endl<<endl;
	cout<<"   ARQUIVO COM NUMEROS GERADOS ALEATORIOS!!!"<<endl;
	cout<<" - Comparacoes | Movimentacoes | Tempo(em segundos):"<<endl;
	cout<<" - - Bubble....: "<<vetor_comp[0]<<" | "<<vetor_mov[0]<<" | "<<tempo[0]<<" ."<<endl;
	cout<<" - - Selection.: "<<vetor_comp[1]<<" | "<<vetor_mov[1]<<" | "<<tempo[1]<<" ."<<endl;
	cout<<" - - Insertion.: "<<vetor_comp[2]<<" | "<<vetor_mov[2]<<" | "<<tempo[2]<<" ."<<endl;
	cout<<" - - Merge.....: "<<vetor_comp[3]<<" | "<<vetor_mov[3]<<" | "<<tempo[3]<<" ."<<endl;
	cout<<" - - Quick.....: "<<vetor_comp[4]<<" | "<<vetor_mov[4]<<" | "<<tempo[4]<<" ."<<endl;
	cout<<" - - Shell.....: "<<vetor_comp[5]<<" | "<<vetor_mov[5]<<" | "<<tempo[5]<<" ."<<endl<<endl<<endl;
	cout<<"   ARQUIVO COM NUMEROS GERADOS EM ORDEM CRESCENTE!!!"<<endl;
	cout<<" - Comparacoes | Movimentacoes | Tempo(em segundos):"<<endl;
	cout<<" - - Bubble....: "<<vetor_comp[6]<<" | "<<vetor_mov[6]<<" | "<<tempo[6]<<" ."<<endl;
	cout<<" - - Selection.: "<<vetor_comp[7]<<" | "<<vetor_mov[7]<<" | "<<tempo[7]<<" ."<<endl;
	cout<<" - - Insertion.: "<<vetor_comp[8]<<" | "<<vetor_mov[8]<<" | "<<tempo[8]<<" ."<<endl;
	cout<<" - - Merge.....: "<<vetor_comp[9]<<" | "<<vetor_mov[9]<<" | "<<tempo[9]<<" ."<<endl;
	cout<<" - - Quick.....: "<<vetor_comp[10]<<" | "<<vetor_mov[10]<<" | "<<tempo[10]<<" ."<<endl;
	cout<<" - - Shell.....: "<<vetor_comp[11]<<" | "<<vetor_mov[11]<<" | "<<tempo[11]<<" ."<<endl<<endl<<endl;
	cout<<"   ARQUIVO COM NUMEROS GERADOS EM ORDEM DECRESCENTE!!!"<<endl;
	cout<<" - Comparacoes | Movimentacoes | Tempo(em segundos):"<<endl;
	cout<<" - - Bubble....: "<<vetor_comp[12]<<" | "<<vetor_mov[12]<<" | "<<tempo[12]<<" ."<<endl;
	cout<<" - - Selection.: "<<vetor_comp[13]<<" | "<<vetor_mov[13]<<" | "<<tempo[13]<<" ."<<endl;
	cout<<" - - Insertion.: "<<vetor_comp[14]<<" | "<<vetor_mov[14]<<" | "<<tempo[14]<<" ."<<endl;
	cout<<" - - Merge.....: "<<vetor_comp[15]<<" | "<<vetor_mov[15]<<" | "<<tempo[15]<<" ."<<endl;
	cout<<" - - Quick.....: "<<vetor_comp[16]<<" | "<<vetor_mov[16]<<" | "<<tempo[16]<<" ."<<endl;
	cout<<" - - Shell.....: "<<vetor_comp[17]<<" | "<<vetor_mov[17]<<" | "<<tempo[17]<<" ."<<endl<<endl<<endl;
	
	cout<<"LEMBRETE: OS DADOS ORDENADOS FORAM SALVOS EM ARQUIVOS SAIDAS NA PASTA DE ORIGEM DESSE PROGRAMA!!!"<<endl<<endl;
	
	return 0;
}