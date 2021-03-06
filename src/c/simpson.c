/**
*simpson.c
*Calcula a integral de uma função em um determinado intervalo pelo método de Simpson
*autor: Moacyr Baptista <mdbneto@gmail.com>
**/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double funcao_x(double x){ //retorna o valor de e^(-(x^2))
	return exp(-pow(x,2));
	//return pow(x,2);
}

double n_simpson(double intervalo_min, double intervalo_max, double h){
	double xk = intervalo_min + h;
	double soma;	
	int i = 1;	
	while (xk<intervalo_max){
		if(i%2==0)
			soma += 2.0*funcao_x(xk);
		else
			soma += 4.0*funcao_x(xk);

		xk += h;
		i++;
	}

	soma = h*(funcao_x(intervalo_max) + funcao_x(intervalo_min) + soma)/3.0;
	return soma;
}



//tentativa de cálculo de a_0
int main (){
	int dois_n = 10000;	//número de partições
	double intervalo_max = M_PI;	//extremo superior do intervalo
	double intervalo_min = - M_PI;//estremo inferior do intervalo

	double h; //passo de integracao

	//debug
	printf("valor de intervalo_max = %e \n", intervalo_max);
	printf("valor de intervalo_min = %e \n", intervalo_min);
	double ultimaSoma, soma;
	do{	
		h = (intervalo_max - intervalo_min) / dois_n;
		ultimaSoma = n_simpson(intervalo_min, intervalo_max, h); 
		h = (intervalo_max - intervalo_min) / (dois_n+1000.0);
		soma = n_simpson(intervalo_min, intervalo_max, h);
		printf("soma = %e, ultimaSoma = %e, i = %d\n", soma, ultimaSoma, dois_n);
		printf("dif = %e\n", (soma-ultimaSoma));		
		dois_n += 1000;
	}while(fabs(soma-ultimaSoma) > pow(10,-12));

	printf("Resposta: a0 = %e \n", (soma/(2*M_PI)));
	return 0;
}


