#ifndef PONTO_H
#define PONTO_H
#include<iostream>
using namespace std;
typedef struct
{
	float x;
	float y;
}Ponto;

void criar_ponto (Ponto**, float, float);
void pto_libera (Ponto**);

#endif