#ifndef CONTATO_H
#define CONTATO_H
#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#define tam 100
#define tam2 10
using namespace std;

typedef struct
{
	string nome;
	int niver;
	unsigned long int telefone;
}TDados;

typedef struct
{
	TDados *v;
	int n;
	int max;
}TContato;

#endif