#include <stdio.h>

int main(){
	float salario, novosalario, percent, aumento;
	
	printf("Informe o seu salario: \n");
	scanf("%f", &salario);
	
	printf("Informe qual seu percentual de aumento em %%: \n");
	scanf("%f", &percent);
	
	
	aumento = salario * (percent /100.0);
	novosalario = salario + aumento;
	
	printf("Seu Aumento foi de: %.2fR$ \n", aumento);
	printf("Seu Novo Salario com seu aumento, e de: %.2fR$ \n", novosalario);
	
	return 0;
}
