#include <stdio.h>

int main(){
	float salariobase, receber, gratificacao = 50.0, imposto;
	
	printf("Informe o seu Salario Base: \n");
	scanf("%f", &salariobase);
	
	imposto = salariobase * 0.10;
	receber = salariobase + gratificacao - imposto;
	
	printf("Seu Salario a Receber foi de: %.2fR$ \n", receber);
	
	return 0;
}
