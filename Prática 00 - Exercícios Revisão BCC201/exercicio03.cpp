#include<iostream>
using namespace std;
void Dados_matriz(int**, int, int);
int main()
{
	int num_mat,i,j,r;
	int **mat,nlinhas,ncol;
	//cout<<"Digite o numero de matrizes desejado:\n";
	cin>>num_mat;
	//Quantidade de matrizes a ser trabalhada.
	cout<<endl;
	for(r=0; r<num_mat; r++)
	{
		cout<<"Matriz "<<r+1;
		//cout<<"Digite a quantidade de linhas e colunas, respectivamente:\n";
		cin>>nlinhas>>ncol;
		//Alocando dinamicamente.
		mat = new int*[nlinhas];
		for(i=0;i<nlinhas;i++)
		{
			mat[i]=new int[ncol];
		}
		//Iniciando a matriz com zero.
		for(i=0; i<nlinhas; i++)
		{
			for(j=0; j<ncol; j++)
			{
				mat[i][j] = 0;
			}
		}
		//Preencher a matriz.
		for(i=0;i<nlinhas;i++)
		{
			for(j=0;j<ncol;j++)
			{
				//cout<<"Preencha a matriz, Linha "<<i+1<<" Coluna "<<j+1<<" : ";
				cin>>mat[i][j];
				//cout<<endl;
			}
		}
		//Chamar o procedimento.
		Dados_matriz(mat,nlinhas,ncol);
		cout<<"\n\n";
		//Liberar memória.
		for(i=0;i<nlinhas;i++)
		{
			delete mat[i];
		}
		delete []mat;	
	}
	return 0;
}

void Dados_matriz(int**M,int lin,int col)
{
	int i,j,maior,menor;
	double media, soma=0;
	menor = M[0][0];
	maior = M[0][0];
	for(i=0; i<lin; i++)
	{
		for(j=0; j<col; j++)
		{
			if(M[i][j]<menor)
			{
				//Calculando o menor termo da matriz.
				menor = M[i][j];
			}
			if(M[i][j]>maior)
			{
				//Calculando o maior termo da matriz.
				maior = M[i][j];
			}
			soma += M[i][j];
		}
	}
	//Calculando a nedia da matriz.
	media = soma/((lin*col)*1.0);
	cout<<"\nO Maior numero da matriz eh: "<<
			maior<<" "<<" O Menor numero eh: "<<
			menor<<" "<<" Com Media: "<<media;
}