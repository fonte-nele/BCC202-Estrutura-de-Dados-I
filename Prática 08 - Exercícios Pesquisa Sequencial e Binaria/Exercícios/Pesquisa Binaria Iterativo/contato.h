#ifndef CONTATO_H
#define CONTATO_H
#include<iostream>
#include<string>
using namespace std;

typedef struct
{
	string nome;
	int niver;
	unsigned long int telefone;
	int chave;
}TDados;

typedef struct
{
	TDados *v;
	int n;
	int max;
}TContato;

void TContato_Construir(TContato*);
void TContato_Inserir(TContato*,TDados*);
//Pesquisa binaria iterativa!
int TContato_Pesquisar(TContato*,unsigned long int,int*);

#endif