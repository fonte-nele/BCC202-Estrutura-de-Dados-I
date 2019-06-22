#include"exe2.h"

void ordenacao_mexida(string lista)
{
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
	string *v,*v2,*v3;
	int v4[cont],tam2=0,tam3=0;
	v= new string[cont];
	Extrair_dados(v,lista);
	for(i=0;i<cont;i++)
	{
		if(isalpha(v[i][0]))
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
	Separar_vetores(v,v2,v3,cont);
	Bolha(v2,tam2);
	Bolha(v3,tam3);
	Intercalar(v,v2,v3,v4,cont);
	Imprimir(v,cont);
	delete []v2;
	delete []v3;
	delete []v;
}

void Extrair_dados(string *v,string lista)
{
	int i,j,k,tam,cont=0,inicio=0;
	tam=lista.size();
	//Extraindo palavras e numeros colocando em um vetor.
	for(i=0,j=1,k=0;i<tam;i++,j++)
	{
		cont++;
		if(lista[i]==',')
		{
			if(lista[j]==' ')
			{
				v[k++]=lista.substr(inicio,cont-1);
				inicio=j+1;
				cont=-1;
			}
		}
	}
	v[k]=lista.substr(inicio,cont-1);
}

void Separar_vetores(string *v,string *v2,string *v3,int cont)
{
	//Separacao em dois vetores, palavras e numeros.
	int i,j,k;
	for(i=0,j=0,k=0;i<cont;i++)
	{
		if(isalpha(v[i][0]))
		{
			v2[j++]=v[i];
		}
		else
		{
			v3[k++]=v[i];
		}
	}
}

void Bolha(string *v,int n)
{
	int i,j,tam1,tam2;
	string aux;
	for(i=0;i<n-1;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(isalpha(v[j][0]))
			{
				if(tolower(v[j][0])==tolower(v[j-1][0]))
				{
					if(tolower(v[j][1])<tolower(v[j-1][1]))
					{
						aux=v[j];
						v[j]=v[j-1];
						v[j-1]=aux;
					}
				}
				if(tolower(v[j][0])<tolower(v[j-1][0]))
				{
					aux=v[j];
					v[j]=v[j-1];
					v[j-1]=aux;
				}
			}
			else
			{
				tam1=v[j-1].size();
				tam2=v[j].size();
				
				if(ispunct(v[j-1][0]) || ispunct(v[j][0]))
				{
					if(v[j]<v[j-1])
					{
						aux=v[j];
						v[j]=v[j-1];
						v[j-1]=aux;
					}
				}
				else
				{
					if(tam1==tam2)
					{
						if(v[j]<v[j-1])
						{
							aux=v[j];
							v[j]=v[j-1];
							v[j-1]=aux;
						}
					}
					else
					{
						if(tam1>tam2)
						{
							aux=v[j-1];
							v[j-1]=v[j];
							v[j]=aux;
						}
					}
				}
			}
		}
	}
}

void Intercalar(string *v,string *v2,string *v3,int *v4,int cont)
{
	int i,j,k;
	for(i=0,j=0,k=0;i<cont;i++)
	{
		if(v4[i]==1)
		{
			v[i]=v2[j++];
		}
		else
		{
			v[i]=v3[k++];
		}
	}
}

void Imprimir(string *v, int cont)
{
	cout<<endl<<endl<<"A LISTA ORDENADA EH:"<<endl;
	for(int i=0;i<cont;i++)
	{
		if(i!=cont-1)
		{
			cout<<v[i]<<", ";
		}
		else
		{
			cout<<v[i]<<".";
		}
	}
}