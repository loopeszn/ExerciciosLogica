#include <stdio.h>

int main(){
	float salariobase, receber, gratificacao, imposto;
	
	printf("Informe o seu Salario Base: \n");
	scanf("%f", &salariobase);
	
	gratificacao = salariobase * 0.05;
	imposto = salariobase * 0.07;
	receber = salariobase + gratificacao - imposto;
	
	printf("Seu Salario a Receber foi de: %.2fR$ \n", receber);
	
	return 0;
}
