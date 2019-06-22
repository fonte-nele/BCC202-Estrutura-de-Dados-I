#include "pratica03.h"
//Questão 1.
int soma_vetor(int *v, int n)
{
	if (n==1)
	{
		return v[0];
	}
	else
	{
		return (v[n-1] + soma_vetor(v, n-1));
	}
	
}

void preencher_vetor (int *v, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		cout<<"Preencha o vetor, posicao "<<i+1<<" :"<<endl;
		cin>>v[i];
	}
}

void deletar_memoria(int *v)
{
	delete []v;
}

//Questão 2.
int soma_dois_numeros(int x, int y)
{
	if (x == 0 )
	{
		return y;
	}
	else
	{
		x--;
		y++;
		return soma_dois_numeros(x,y);
	}
}

//Questão 3.
int mdc_recursivo(int m, int n)
{
	if(n==0)
	{
		return m;
	}
	else
	{
		return mdc_recursivo(n, m%n);
	}
}

int mdc_iterativo(int m, int n)
{
	int mdc,i;
	for(i=1; i<=m&&i<=n ;i++)
	{
		if(m%i==0 && n%i==0)
		{
			mdc=i;
		}
	}
	return mdc;
}

//Questão 4.
int maior (int *v, int n, int x)
{
	if (n==1)
	{
		return v[0];
	}
	else
	{
		x = maior(v,n-1,x);
		if (x>v[n-1])
			return x;
		else
			return v[n-1];
	}
}

//Questão 5.
int potencia_recursiva(double x, int n)
{
	if (n==0)
	{
		return 1;
	}
	else
		if (n==1)
		{
			return x;
		}
		else
		{
			return x * potencia_recursiva(x, n-1);
		}
}

int potencia_iterativa(double base, int exp)
{
	double result=1;
	int i;
	for(i=0; i<exp; i++)
	{
		result = result*base;
	}
	return result;
}

//Questão 6.
int buscaBinaria(int x,int *v,int e,int d, int m)
{
	if(e>d)
	{
		return -1;
	}
	else
	{
		m = (e+d)/2;
		if(v[m]==x)
		{
			return m;
		}
		if(v[m]<x)
		{
			return buscaBinaria(x,v,m+1,d,m);
		}
		else
		{
			return buscaBinaria(x,v,e,m-1,m);
		}
	}
}
