/**
*simpson.c
*Calcula a integral de uma função em um determinado intervalo pelo método de Simpson
*autor: Moacyr Baptista <mdbneto@gmail.com>
**/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float funcao_x(float x){ //retorna o valor de e^(-(x^2))
	return exp(-pow(x,2));
}

/* Teste para ver se a função funciona
int main () {
	printf("Resultados em notação científica\n");
	printf("x=1 => %e \n", funcao_x(1));
	printf("x=2 => %e \n", funcao_x(2));
	printf("x=3 => %e \n", funcao_x(3));
	printf("x=4 => %e \n", funcao_x(4));
	printf("x=5 => %e \n", funcao_x(5));
	printf("x=6 => %e \n", funcao_x(6));

	return 0;
}*/

//tentativa de cálculo de a_0
int main (){
	int dois_n = 10;	//número de partições
	float intervalo_max = M_PI;	//extremo superior do intervalo
	float intervalo_min = - M_PI;//estremo inferior do intervalo

	//cálculo do h
	float h = (intervalo_max - intervalo_min) / dois_n;

	float soma = 0;
	float x;
	bool impar = true;

	//debug
	printf("valor de intervalo_max = %e \n", intervalo_max);
	printf("valor de intervalo_min = %e \n", intervalo_min);
	printf("valor de h = %e \n", h);
	
	for(x = (intervalo_min+h); x > (intervalo_max-h); x=x+h){
		if(!impar)
			soma += 2*funcao_x(x);
		else
			soma += 4*funcao_x(x);
		impar = !impar;
	}
	soma += funcao_x(intervalo_min);
	soma += funcao_x(intervalo_max);

	soma = soma*h/3;

	printf("Valor de a_0 = %e \n", soma);
	
	return 0;
}

