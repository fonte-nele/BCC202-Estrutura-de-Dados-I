#include <iostream>
#include <iomanip>
#include "ponto.h"
#include "circulo.h"

int main ()
{
	Circulo *circ;
	Ponto *ponto;
	float x_centro,y_centro,raio,x_ponto1,y_ponto1,x_ponto2,y_ponto2,dist;
	//cout<<"Digite as coordenadas do centro e o valor de seu raio\n";
	cin>>x_centro>>y_centro>>raio;
	criar_circulo (&circ, x_centro, y_centro, raio);
	cout<<"O comprimento da circunferencia eh: "<<fixed<<setprecision(2)<<circ_circunferencia(&circ)<<endl;
	cout<<"\nA area do circulo eh: "<<fixed<<setprecision(2)<<circ_area(&circ)<<endl;
	//cout<<"Digite as coordenadas de um ponto para verificar se encontra dentro do circulo:\n";
	cin>>x_ponto1>>y_ponto1;
	criar_ponto (&ponto, x_ponto1, y_ponto1);
	dist = circ_distancia(&circ, &ponto);
	circ_interior (&circ, &ponto, dist);
	//cout<<"Digite as coordenadas de um ponto para verificar a distancia com o centro.\n";
	cin>>x_ponto2>>y_ponto2;
	criar_ponto (&ponto, x_ponto2, y_ponto2);
	cout<<"\nA distancia entre o centro e o ponto eh: "<<circ_distancia(&circ, &ponto)<<endl;
	pto_libera(&ponto);
	circ_libera(&circ);
	return 0;
}