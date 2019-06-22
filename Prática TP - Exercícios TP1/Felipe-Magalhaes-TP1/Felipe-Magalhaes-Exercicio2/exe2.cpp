#include "exe2.h"
#include <cstdlib>
#include <time.h>

void Preencher_matriz_rand(int**m,int lin,int col)
{
	srand((unsigned)time(NULL));
	int i,j;
	for(i=0;i<lin;i++)
	{
		for(j=0;j<col;j++)
		{
			//Gerar números de 1 a 254!!!
			m[i][j] = rand() % 254 + 1;
		}
	}
}

void Preencher_matriz(int**m,int lin,int col)
{
	int i,j,temp;
	for(i=0;i<lin;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<"Escolha a cor na linha "<<i+1<<" coluna "<<j+1<<" : ";
			cin>>temp;
			while(temp<1 || temp>254)
			{
				cout<<"\nNumero da cor digitada nao existe.\n";
				cout<<"\nEscolha a cor na linha "<<i+1<<" coluna "<<j+1<<" : ";
				cin>>temp;
			}
			m[i][j] = temp;
			cout<<endl;
		}
	}
}

void Boundaryfill(int**m,int cor,int x,int y,int lin,int col,int cor_ant)
{
	//Condições para garantir que a função recursiva termine!!!
	if((x<lin && y<col && x>=0 && y>=0) && m[x][y]==cor_ant)
	{
		m[x][y] = cor;
		//Chamada recursiva para os 4 lados da matriz!
		Boundaryfill(m,cor,x+1,y,lin,col,cor_ant);
		Boundaryfill(m,cor,x-1,y,lin,col,cor_ant);
		Boundaryfill(m,cor,x,y+1,lin,col,cor_ant);
		Boundaryfill(m,cor,x,y-1,lin,col,cor_ant);
	}
}

void Imprimir_matriz(int**m,int lin,int col)
{
	int i,j;
	for(i=0;i<lin;i++)
	{
		for(j=0;j<col;j++)
		{
			//Condições para imprimir a matriz de uma forma visualmente adequada. 
			if(m[i][j]<10)
			{
				cout<<"  "<<m[i][j]<<"   ";
			}
			else
				if(m[i][j]<100)
				{
					cout<<"  "<<m[i][j]<<"  ";
				}
				else
				{
					cout<<" "<<m[i][j]<<"  ";
				}
		}
		cout<<endl<<endl;
	}
}

void Liberar_memoria(int**m,int lin)
{
	int i;
	for(i=0;i<lin;i++)
	{
		delete m[i];
	}
	delete []m;
}

