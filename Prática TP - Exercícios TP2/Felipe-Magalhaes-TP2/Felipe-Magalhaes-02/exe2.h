#ifndef EXE2_H
#define EXE2_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

bool Verificar_pontuacao(string*);
void Ordenacao_mexida(string*,string*,string*,int*,int);
void Extrair_dados(string*,string);
void Separar_vetores(string*,string*,string*,int);
void Bolha(string*,int);
void Imprimir(ofstream*,string*,int);

#endif