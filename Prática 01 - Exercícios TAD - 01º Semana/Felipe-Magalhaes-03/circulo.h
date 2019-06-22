#ifndef CIRCULO_H
#define CIRCULO_H
#include <iostream>
#include "ponto.h"
using namespace std;
typedef struct
{
	float centro1;
	float centro2;
	float raio;
}Circulo;

void criar_circulo (Circulo**, float, float, float);
float circ_circunferencia(Circulo**);
float circ_area (Circulo**);
void circ_interior (Circulo**, Ponto**, float);
float circ_distancia (Circulo**, Ponto**);
void circ_libera (Circulo**);
#endif