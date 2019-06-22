#ifndef CONTATO_H
#define CONTATO_H
#include<iostream>
#include<string>
#include<iomanip>
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

#endif