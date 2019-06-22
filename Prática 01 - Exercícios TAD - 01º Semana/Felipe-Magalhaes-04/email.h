#ifndef EMAIL_H
#define EMAIL_H 
#include <iostream>
#include <string>
using namespace std;
typedef struct
{
	string ehpessoal[];
	string ehprofissional[];
}Email;

void adicionar_email (Email**, string, int);
void deletar_memoria (Email**);

#endif