#include "TTime.h"
#include <iomanip>

int main()
{
	int num_times,num_jog,num_jog_titulares,sumula,i,j,idTime1,idTime2,pontosT1 = 0 , pontosT2 = 0,operacao,time,valor;
	int jogos, pont_jog,faltas_jog,cartoes_jog,vit,derrotas;
	char nome_time[50],nome_jog[50]; 
	TTime* time1; 
	TTime* time2;
	/*Usuário preencher a quantidade de times,
	jogadores, jogadores titulares e súmulas do juiz*/
	cin>> num_times>> num_jog>> num_jog_titulares>> sumula;
	
	//Alocando dinamicamente times.
	TTime **times = new TTime*[num_times];
	
	for(i=0;i<num_times;i++)
	{
		TTime_Inicia(&times[i]);
		//Nome dos times.
		cin>> nome_time;
		TTime_setNome(times[i], nome_time);
		//Alocando dinamicamente jogadores.
		TJogador **jogadores = new TJogador*[num_jog];
		
		for(j=0 ; j<num_jog;j++)
		{
			//Nome dos jogadores.
			cin>> nome_jog;
			TJogador_Inicia(&jogadores[j]);
			TJogador_setNome(jogadores[j], nome_jog);
		}
		TTime_setJogadores(times[i], jogadores);
	}
	
	for(i = 0 ; i < sumula ; i++)
	{
		//Digitar operacao da súmula.
		cin>> operacao;
		//De acordo com o operacao entrar em cada case.
		switch(operacao)
		{
			case(1):
				//Inicializar variáveis.
				cin>>idTime1>>idTime2;
				time1 = times[idTime1];
				time2 = times[idTime2];
				break;
			case(2):
				//Incrementar número de jogos de cada jogador escalado.
				cin>>time;
				for(j =  0 ; j < num_jog_titulares ; j++)
				{
					int a;
					cin>>a;
					jogos = TJogador_getJogos(TTime_getJogadores(times[time])[a])+1;
					TJogador_setJogos(TTime_getJogadores(times[time])[a], jogos);
				}
				break;
			case(3):
				//Contabilizar os pontos marcados pelo jogador no campeonato e o número de pontos marcados pelo time na partida.
				cin>>time>>valor;
				if(time == idTime1)
				{
					pontosT1++;
					pont_jog = TJogador_getPontos(TTime_getJogadores(time1)[valor])+1;
					TJogador_setPontos(TTime_getJogadores(time1)[valor],pont_jog);
				}else if(time == idTime2)
				{
					pontosT2++;
					pont_jog = TJogador_getPontos(TTime_getJogadores(time2)[valor])+1;
					TJogador_setPontos(TTime_getJogadores(time2)[valor],pont_jog);
				}
				break;
			case(4):
				//Contabilizar o número de faltas marcadas pelo jogador.
				cin>>time>>valor;
				if(time == idTime1)
				{
					faltas_jog = TJogador_getFaltas(TTime_getJogadores(time1)[valor])+1;
					TJogador_setFaltas(TTime_getJogadores(time1)[valor],faltas_jog);
				}else if(time == idTime2)
				{
					faltas_jog = TJogador_getFaltas(TTime_getJogadores(time2)[valor])+1;
					TJogador_setFaltas(TTime_getJogadores(time2)[valor],faltas_jog);
				}
				break;
			case(5):
				//Contabilizar o número de cartões recebidos pelo jogador.
				cin>>time>>valor;
				if(time == idTime1)
				{
					cartoes_jog = TJogador_getCartoes(TTime_getJogadores(time1)[valor])+1;
					TJogador_setCartoes(TTime_getJogadores(time1)[valor],cartoes_jog);
				}else if(time == idTime2)
				{
					cartoes_jog = TJogador_getCartoes(TTime_getJogadores(time2)[valor])+1;
					TJogador_setCartoes(TTime_getJogadores(time2)[valor],cartoes_jog);
				}
				break;
			case(6):
				//Finalizar o jogo, fazendo todas contas, como vit, derrotas.
				if(pontosT1 > pontosT2)
				{
					vit = TTime_getVitorias(time1)+1;
					TTime_setVitorias(time1, vit);
					derrotas = TTime_getDerrotas(time2)+1;
					TTime_setDerrotas(time2, derrotas);
				}else if(pontosT2 > pontosT1)
				{
					vit = TTime_getVitorias(time2)+1;
					TTime_setVitorias(time2, vit);
					derrotas = TTime_getDerrotas(time1)+1;
					TTime_setDerrotas(time1, derrotas);
				}else
				{
					int empatesT1 = TTime_getEmpates(time1)+1;
					int empatesT2 = TTime_getEmpates(time2)+1;
					TTime_setEmpates(time1, empatesT1);
					TTime_setEmpates(time2, empatesT2);
				}
				pontosT1 = 0;
				pontosT2 = 0;
				break;
			default:
				cout<<"\nSumula inconsistente...";
		}
		
	}
	for(i = 0 ; i < num_times ; i++)
	{
		TTime_calculaScore(times[i], num_jog);
		TTime_calculaPontos(times[i]);
	}
	TTime *campeao = times[0];
	for(i = 0 ; i < num_times ; i++)
	{
		if(times[i]->pontos > campeao->pontos )
		{
			campeao = times[i];
		}else if (times[i]->pontos == campeao->pontos)
		{
			if(times[i]->score > campeao->score)
			{
				campeao = times[i];
			}
		}
	}
	cout<<"\nTime campeao: "<<TTime_getNome(campeao)<<" "<<fixed<<setprecision(2)<< campeao->score<<" "<<campeao->pontos<<endl;
	for(i = 0; i < num_times ; i++)
	{
		cout<<"\nTime "<<i+1<<" : "<<fixed<<setprecision(2)<<TTime_getNome(times[i])<<" "<<times[i]->score<<" "<<times[i]->pontos;
	}
	
	for(i = 0 ; i < num_times ; i++)
	{
		TTime_libera(times[i], num_jog);
	}
	return 0;
}
