#include <stdio.h>
#include <stdlib.h>

int main(){
	float hrtrabalhadas, salariomin;
	float resceber, valorhr, salariobrut, imposto; 
	
	printf("Digite o Numero de horas Trabalhadas:\n");
	scanf("%f", &hrtrabalhadas);

	printf("Digite o valor do salario minimo:\n");
	scanf("%f", &salariomin);
	
	valorhr = salariomin / 2.0;
	salariobrut = hrtrabalhadas * valorhr;
	imposto = salariobrut *0.03;
	resceber = salariobrut - imposto;
	
	system("cls");
	printf("--------------------------------");
	printf("\nValor da Hora Trabalhada: R$ %.2fR$", valorhr);
	printf("\nValor do Salario Bruto: R$ %.2fR$", salariobrut);
	printf("\nValor do Imposto (3%%): R$ %.2fR$", imposto);
	printf("\nValor do Salario a Resceber: R$ %.2fR$", resceber);
	
	
	return 0;
}
