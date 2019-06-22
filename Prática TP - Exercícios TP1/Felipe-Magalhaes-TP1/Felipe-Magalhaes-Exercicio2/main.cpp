#include "exe2.h"

int main()
{
	int **mat;
	int i,largura,altura,cor,x,y;
	char decisao;
	cout<<"Digite a altura e largura, respectivamente(inteiros):\n";
	cin>>altura>>largura;
	mat = new int*[altura];
	for(i=0;i<altura;i++)
	{
		mat[i] = new int [largura];
	}
	cout<<"\nDigite qual forma deseja preencher a matriz: A - Aleatorio ou M - Preencher Manualmente!"<<endl;
	cin>>decisao;
	while(tolower(decisao)!= 'a' && tolower(decisao)!= 'm')
	{
		cout<<"OPCAO INVALIDA!!! POR FAVOR TENTE NOVAMENTE...."<<endl;
		cout<<"\nDigite qual forma deseja preencher a matriz: A - Aleatorio ou M - Preencher Manualmente!"<<endl;
		cin>>decisao;
	}
	if(tolower(decisao)=='a')
	{
		Preencher_matriz_rand(mat,altura,largura);
	}
	else
	{
		Preencher_matriz(mat,altura,largura);
	}
	
	cout<<"\nA matriz gerada eh:\n";
	Imprimir_matriz(mat,altura,largura);
	
	cout<<"Digite a cor desejada e as coordenadas(linha,coluna) para alterar:\n"; 
	cin>>cor>>x>>y;
	
	while(x>altura || y>largura || cor>=255 || cor<=0 || x<=0 || y<=0)
	{
		cout<<"Algum dado nao esta correto.FAVOR DIGITAR NOVAMENTE.....\n"<<endl;
		cout<<"Digite a cor desejada e as coordenadas(linha,coluna) para alterar:\n"; 
		cin>>cor>>x>>y;
	}
	//Diminuo as coordenadas pois minha matriz começa em (0,0). Fiz isto para não pedir o usuário na hora de digitar diminuir uma posição!!
	x -=1;
	y -=1; 
	Boundaryfill(mat,cor,x,y,altura,largura,mat[x][y]);
	
	cout<<"A matriz ficou dessa forma:\n";
	Imprimir_matriz(mat,altura,largura);
	Liberar_memoria(mat,altura);
	return 0;
}