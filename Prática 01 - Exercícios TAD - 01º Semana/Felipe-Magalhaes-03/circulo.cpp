#include "circulo.h"
#include "ponto.h"
#include <cmath>
#define PI 3.14159

void criar_circulo (Circulo **c, float x1, float y1, float r)
{
	(*c) = new Circulo;
	(*c) -> centro1 = x1;
	(*c) -> centro2 = y1;
	(*c) -> raio = r;
}

float circ_circunferencia (Circulo **c)
{
	return 2*(*c)->raio*PI;
}

float circ_area (Circulo **c)
{
	return ((*c)->raio)*((*c)->raio)*PI;
}

void circ_interior (Circulo **c, Ponto **p, float distancia)
{
	if(distancia<(*c)->raio)
	{
		cout<<"\nO ponto de coordenadas "<<(*p)->x<<" e "<<(*p)->y<<" esta contido dentro do circulo.\n";
	}
	else
	{
		cout<<"\nO ponto de coordenadas "<<(*p)->x<<" e "<<(*p)->y<<" nao esta contido dentro dentro do circulo.\n";
	}
}

float circ_distancia (Circulo **c, Ponto **p)
{
	float dx = ((*p) -> x - (*c) -> centro1);
	float dy = ((*p) -> y - (*c) -> centro2);
	return sqrt(dx*dx + dy*dy);	
}

void circ_libera (Circulo **c)
{
	delete (*c);
}