#include "email.h"

void adicionar_email (Email **email, string campo, int n)
{
	int i=0,j=0,tipo_email;
	(*email) = new Email;
	cout<<"\nO email eh pessoal ou profissional, responda 1-pessoal 2-profissional.\n";
	cin>>tipo_email;
	if(tipo_email==1)
	{	
		(*email) -> ehpessoal[i++] = campo; 
	}
	else
	{
		(*email) -> ehprofissional[j++] = campo;
	}
}

void deletar_memoria (Email **email)
{
	delete (*email);
}