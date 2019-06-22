#include "pratica03.h"

int main()
{
	//Questão 1.
	cout<<"\nQUESTAO 1!!!"<<endl<<endl;
	int num, *v;
	cout<<"Digite a quantidade de numeros do vetor:\n";
	cin>>num;
	v = new int [num];
	preencher_vetor(v,num);
	cout<<"A soma dos elementos desse vetor e: "<<soma_vetor(v,num)<<endl<<endl;
	deletar_memoria(v);
	
	
	//Questão 2.
	cout<<"QUESTAO 2!!!"<<endl<<endl;
	int num1, num2;
	cout<<"Digite dois numeros inteiros nao negativos para fazer a soma:\n";
	cin>>num1>>num2;
	while(num1<0 || num2<0)
	{
		if(num1<0 && num2<0)
		{
			cout<<"\nOs dois numeros digitados "<<num1<<" , "<<num2<<" nao sao positivos.\n"<<endl;
			cout<<"DIGITE NOVAMENTE!!!"<<endl<<endl;
			cin>>num1>>num2;
		}
		else
			if(num1<0)
			{
				cout<<"\nO primeiro numero digitado "<<num1<<" nao eh positivo.\n"<<endl;
				cout<<"DIGITE NOVAMENTE!!!"<<endl<<endl;
				cin>>num1>>num2;
			}
			else
			{
				cout<<"\nO segundo numero digitado "<<num2<<" nao eh positivo.\n"<<endl;
				cout<<"DIGITE NOVAMENTE!!!"<<endl<<endl;
				cin>>num1>>num2;
			}
	}
		cout<<"A soma dos dois numeros eh: "<<soma_dois_numeros(num1, num2)<<endl;
	
	
	//Questão 3.
	cout<<"\nQUESTAO 3!!!"<<endl<<endl;
	int num_mdc1, num_mdc2;
	cout<<"Digite dois numeros para calcular o MDC:\n";
	cin>>num_mdc1>>num_mdc2;
	while(num_mdc1<=0 || num_mdc2<=0)
	{
		if(num_mdc1<=0)
		{
			if(num_mdc1 == 0)
			{
				cout<<"\nO primeiro numero digitado "<<num_mdc1<<" eh nulo."<<endl<<endl;
				cout<<"DIGITE NOVAMENTE!!!"<<endl<<endl;
				cin>>num_mdc1;
			}
			else
				if(num_mdc2<=0){
					cout<<"\nOs dois numeros digitados "<<num_mdc1<<" , "<<num_mdc2<<" nao sao positivos."<<endl<<endl;
					cout<<"DIGITE NOVAMENTE!!!"<<endl<<endl;
					cin>>num_mdc1>>num_mdc2;
				}
				else{
					cout<<"\nO primeiro numero digitado "<<num_mdc1<<" nao eh positivo."<<endl<<endl;
					cout<<"DIGITE NOVAMENTE!!!"<<endl<<endl;
					cin>>num_mdc1;
				}
		}
		else
		{
			if(num_mdc2 == 0)
			{
				cout<<"\nO segundo numero digitado "<<num_mdc2<<" eh nulo."<<endl<<endl;
				cout<<"DIGITE NOVAMENTE!!!"<<endl<<endl;
				cin>>num_mdc2;
			}
			else
			{
				cout<<"\nO segundo numero digitado "<<num_mdc2<<" nao eh positivo."<<endl<<endl;
				cout<<"DIGITE NOVAMENTE!!!"<<endl<<endl;
				cin>>num_mdc2;
			}
		}
	}
	//Função recursiva!!!
	cout<<"O maximo divisor dos dois numeros "<<num_mdc1<<" e "<<num_mdc2<<" eh(forma recursiva): "<<mdc_recursivo(num_mdc1,num_mdc2)<<endl;
	//Função iterativa!!!
	cout<<"O maximo divisor dos dois numeros "<<num_mdc1<<" e "<<num_mdc2<<" eh(forma iterativa): "<<mdc_iterativo(num_mdc1,num_mdc2)<<endl;
	
	
	//Questão 4.
	cout<<"\nQUESTAO 4!!!"<<endl<<endl;
	int quant_elementos, *vetor, enorme=0;
	cout<<"Digite a quantidade de numeros do vetor:\n";
	cin>>quant_elementos;
	vetor = new int [quant_elementos];
	preencher_vetor(vetor,quant_elementos);
	cout<<"O maior elemento do vetor eh: "<<maior(vetor,quant_elementos,enorme)<<endl;
	deletar_memoria(vetor);
	
	//Questão 5.
	cout<<"\nQUESTAO 5!!!"<<endl<<endl;
	int exp;
	double base;
	cout<<"Digite a base e exponte para fazer o calculo da potencia:\n";
	cin>>base>>exp;
	while(exp<0)
	{
		cout<<"O expoente digitado "<<exp<<" nao eh positivo."<<endl;
		cout<<"DIGITE NOVAMENTE UM EXPOENTE COM VALOR POSITIVO!!!"<<endl;
		cin>>exp;
	}
	//Função recursiva!!!
	cout<<"O calculo da potencia eh(forma recursiva): "<<potencia_recursiva(base,exp)<<endl;
	//Função iterativa!!!
	cout<<"O calculo da potencia eh(forma iterativa): "<<potencia_iterativa(base,exp)<<endl;
		
	
	//Questao 6.
	cout<<"\nQUESTAO 6!!!"<<endl<<endl;
	int x,num_elementos, *vetor_ordenado,m=0;
	cout<<"Digite a quantidade de numeros do vetor:\n";
	cin>>num_elementos;
	vetor_ordenado = new int [num_elementos];
	cout<<"\nPREENCHA O VETOR EM ORDEM CRESCENTE!!!"<<endl<<endl;
	preencher_vetor(vetor_ordenado,num_elementos);
	cout<<"Digite o numero que esta procurando:\n";
	cin>>x;
	cout<<"O elemento esta no indice: "<<buscaBinaria(x,vetor_ordenado,0,num_elementos,m)<<" do vetor."<<endl;
	deletar_memoria(vetor_ordenado);
	return 0;
}