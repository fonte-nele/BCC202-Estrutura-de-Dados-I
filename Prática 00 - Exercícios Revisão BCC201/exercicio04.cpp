#include <iostream>
using namespace std;
void Comparar(int**M, int a,int n, int gab[])
{
	int i,j, acertos=0, cham;
	for(i=0; i<a; i++)
	{
		for(j=0; j<n; j++)
		{
			if(M[i][j]==gab[j])
			{
				acertos++;
			}
			cham= M[i][5];
			
		}
		cout<<"Aluno Chamada: "<<cham;
		cout<<" Quantidade de acertos: "<<acertos<<endl;
		//Zero o contador de acertos.
		acertos=0;
		cham=0;
	}
}
int main ()
{
	int i,j,n, a, gab[5], **mat_respostas;
	//cout<<"Digite o numero de questoes:\n";
	cin>>n;
	//cout<<"Digite a quantidade de alunos:\n";
	cin>>a;
	for(i=0;i<5;i++)
	{
		//cout<<"Digite o gabarito oficial:\n";
		cin>>gab[i];
	}
	//Alocando dinamicamente.
	mat_respostas = new int*[a];
	for(i=0;i<a;i++)
	{
		mat_respostas[i] = new int[n+1];
	}
	//Iniciando a matriz com zero.
	for(i=0; i<a; i++)
	{
		for(j=0; j<(n+1); j++)
		{
			mat_respostas[i][j] = 0;
		}
	}
	for(i=0;i<a;i++)
	{
		for(j=0;j<(n+1);j++)
		{
			//cout<<"Gabarito aluno "<<i+1<<" :\n";
			cin>>mat_respostas[i][j];
		}
	}
	//Procedimento para comparar as respostas e pegar o gabarito.
	Comparar(mat_respostas,a,n,gab);
	//Liberar memória.
	for(i=0;i<a;i++)
	{
		delete mat_respostas[i];
	}
	delete []mat_respostas;
	return 0;
}