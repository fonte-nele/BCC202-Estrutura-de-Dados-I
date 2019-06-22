#include <iostream>
#include "matriz.h"

int main ()
{
	int nlinhas, ncolunas, coord1, coord2, coord3, coord4;
	float n_add;
	Matriz *matriz;
	//cout<<"Digite a quantidade de linhas da matriz:\n";
	cin>>nlinhas;
	//cout<<"Digite a quantidade de colunas da matriz:\n";
	cin>>ncolunas;
	criar_matriz (&matriz, nlinhas, ncolunas);
	//cout<<"Digite o elemento e as coordenadas correspondente para adicionar na matriz:\n";
	cin>>n_add>>coord1>>coord2;
	adicionar_elemento (&matriz, n_add, coord1, coord2);
	//cout<<"Digite as coordenadas para acessar o elemento correspondente:\n";
	cin>>coord3>>coord4;
	cout<<"O elemento procurado nas coordenadas ("<<coord3<<","<<coord4<<") eh: "<<acessar_elemento (&matriz, coord3, coord4)<<endl;
	cout<<"A quantidade de linhas da matriz eh: "<<getNumeroLinha(&matriz)<<endl;
	cout<<"A quantidade de colunas da matriz eh: "<<getNumeroColuna(&matriz)<<endl;
	liberar_memoria(&matriz);
	return 0;
}