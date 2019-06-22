#include "TRecurso.h"

void Inicializar_Recurso(TRecurso**recurso)
{
	*recurso = new TRecurso;
	TRecurso_setTipo(*recurso, 0);
	TRecurso_setCapacidade(*recurso, 0);
	TRecurso_setEmUso(*recurso, 0);
	TRecurso_setVelocidade(*recurso, 0);
}

int TRecurso_getTipo(TRecurso* recurso)
{
	return recurso -> tipo;
}

double TRecurso_getCapacidade(TRecurso* recurso)
{
	return recurso -> capacidade;
}

double TRecurso_getEmUso(TRecurso* recurso)
{
	return recurso -> EmUso;
}

double TRecurso_getVelocidade(TRecurso* recurso)
{
	return recurso -> velocidade;
}

void TRecurso_setTipo(TRecurso* recurso, int tipo)
{
	recurso -> tipo = tipo;
}

void TRecurso_setCapacidade(TRecurso* recurso, double capac)
{
	recurso -> capacidade = capac;
}

void TRecurso_setEmUso(TRecurso* recurso, double quant)
{
	recurso -> EmUso = quant;
}

void TRecurso_setVelocidade(TRecurso* recurso, double veloc)
{
	recurso -> velocidade = veloc;
}

int estaDisponivel(TRecurso* recurso,double num)
{
	//Verificar se é CPU cujo tipo é 1
	if(recurso->tipo==1)
	{
		//Analisa disponibilidade CPU
		if(recurso ->capacidade - recurso->EmUso > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	//Verificar os outros tipos
	if((recurso ->capacidade - recurso->EmUso) >= num)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int reservar(TRecurso* recurso,double num)
{
	//Analisa se é CPU
	if(recurso->tipo == 1)
	{
		if((recurso -> capacidade - recurso->EmUso) > 0)
		{
			recurso -> EmUso += 1;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if((recurso -> capacidade - recurso->EmUso) >= num)
	{
		recurso -> EmUso += num;
		return 1;
	}
	else
	{
		return 0;
	}
}

int liberar_recurso(TRecurso* recurso,double num)
{
	if(recurso -> EmUso >= num)
	{
		recurso -> EmUso -= num;
		return 1;
	}
	else
	{
		return 0;
	}
}

double calcularTempo(TRecurso* recurso, double num)
{
	return (recurso -> velocidade * num);
}

void liberar_memoria (TRecurso* recurso)
{
	delete recurso;
}