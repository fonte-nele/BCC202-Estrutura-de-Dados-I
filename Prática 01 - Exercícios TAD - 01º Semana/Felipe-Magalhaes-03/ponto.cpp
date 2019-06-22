#include "ponto.h"

void criar_ponto (Ponto **p, float x1, float y1)
{
	(*p) = new Ponto;
	(*p) -> x = x1;
	(*p) -> y = y1;
}

void pto_libera (Ponto **p)
{
	delete (*p);
}