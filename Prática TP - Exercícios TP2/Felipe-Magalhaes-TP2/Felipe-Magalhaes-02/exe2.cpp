#include"exe2.h"

bool Verificar_pontuacao(string *lista)
{
	int i,tam;
	tam=(*lista).size();
	for(i=0;i<tam;i++)
	{
		if((*lista)[i]=='.')
		{
			return true;
		}
	}
	return false;
}

void Ordenacao_mexida(string *v1,string *v2,string *v3,int *v4,int cont)
{
	int i,j,k;
	for(i=0,j=0,k=0;i<cont;i++)
	{
		if(v4[i]==1)
		{
			v1[i]=v2[j++];
		}
		else
		{
			v1[i]=v3[k++];
		}
	}
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
					if(tolower(v[j][1])==tolower(v[j-1][1]))
					{
						if(tolower(v[j][2])==tolower(v[j-1][2]))
						{
							if(tolower(v[j][3])<tolower(v[j-1][3]))
							{
								aux=v[j];
								v[j]=v[j-1];
								v[j-1]=aux;
							}
						}
						else
						{
							if(tolower(v[j][2])<tolower(v[j-1][2]))
							{
								aux=v[j];
								v[j]=v[j-1];
								v[j-1]=aux;
							}
						}
					}
					else
					{
						if(tolower(v[j][1])<tolower(v[j-1][1]))
						{
							aux=v[j];
							v[j]=v[j-1];
							v[j-1]=aux;
						}	
					}
				}
				else
				{
					if(tolower(v[j][0])<tolower(v[j-1][0]))
					{
						aux=v[j];
						v[j]=v[j-1];
						v[j-1]=aux;
					}
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

void Imprimir(ofstream *saida,string *v, int cont)
{
	cout<<endl<<endl<<"A LISTA ORDENADA EH:"<<endl;
	
	for(int i=0;i<cont;i++)
	{
		if(i!=cont-1)
		{
			cout<<v[i]<<", ";
			(*saida)<<v[i]<<", ";
		}
		else
		{
			cout<<v[i]<<".";
			(*saida)<<v[i]<<".";
		}
	}
	(*saida)<<endl<<endl;
}