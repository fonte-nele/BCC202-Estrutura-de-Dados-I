#ifndef CONTATO_H
#define CONTATO_H
#include <iostream>
#include <string>
#include "email.h"
using namespace std;

typedef struct
{
	string nome[20];
	int codigo[20];
	int numero[20];
	string operadora[20];
	string classificacao[20];
}Contato;

void criar_contato (Contato**, string);
void retornar_nome (Contato**, string);
void adicionar_telefone (Contato**, int, int, string, string);
void modificar_nome (Contato**, string, string);
void liberar_memoria (Contato**);

#endif