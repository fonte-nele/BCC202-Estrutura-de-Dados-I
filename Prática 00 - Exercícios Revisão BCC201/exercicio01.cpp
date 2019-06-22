#include <iostream>
#include <cmath>
#define PI 3.141592654
using namespace std;
double converter (double a)
{
	//Função para converter graus em radianos.
	double conversao;
	conversao = (a * PI / 180);
	return conversao;
}
int main ()
{
	int z,n,i,j=0;
	double x,cos=0,fat=1;
	//cout<<"Quantos calculos deseja fazer:\n";
	cin>>z;
	//Faço um do-while para fazer a quantidade de cálculos desejada.
	do
	{
		//cout<<"\n\nDigite o valor de X(graus):\n";
		cin>>x;
		//cout<<"Quantidade de termos para calculo do cosseno:\n";
		cin>>n;
		cout<<"Conversao em radianos: "<<converter(x)<<" Numero de termos: "<<n<<" ";
		//Cálculo do cosseno.
		for(i=1;i<=n;i++)
		{
			if(x!=0)
			{
				if(i%2==0)
				{
					cos -= (pow (converter(x),(2.0*i-2.0)))/fat;
				}
				else
				{
					cos += (pow (converter(x), (2.0*i-2.0)))/fat;
				}
			}
			fat = fat *(2.0*i-1.0)*(2.0*i);
		}
		cout<<"Valor cosseno: "<<cos<<endl<<endl;
		//Zero os valores para evitar eventuais problemas, mesmo que não ocorra.
		x=0;
		cos=0;
		fat=1;
		j++;
	}while(j!=z);
	return 0;
}