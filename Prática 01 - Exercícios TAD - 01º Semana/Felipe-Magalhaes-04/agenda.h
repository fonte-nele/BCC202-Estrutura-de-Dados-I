#ifndef AGENDA_H
#define AGENDA_H
#include "contato.h"
#include <iostream>
using namespace std;

typedef struct
{
	Contato** cont;
	int quant;
}Agenda;

void criar_agenda (Agenda**,int);
void inserir_contato(Agenda**, Contato**);
void buscar_contato(Agenda**, string, Contato**);
int quantidade_contatos(Agenda**);
int capacidade_agenda(Agenda**, int);
void liberar_memoria(Agenda**);

#endif