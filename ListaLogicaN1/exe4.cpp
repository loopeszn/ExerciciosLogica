#include <stdio.h>

int main(){
	float salario, novosalario;
	
	printf("Informe o seu salario: \n");
	scanf("%f", &salario);
	
	novosalario = salario * 1.25;
	
	printf("Seu Novo Salario com seu aumento, e de: %.2f \n", novosalario);
	
	return 0;
}
