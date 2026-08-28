#include <stdio.h>

int main(){
	int anonasc, anoatual, idade1, idade2;
	
	printf("Digite seu Ano de Nascimento:\n");
	scanf("%d", &anonasc);
	
	printf("Digite o Ano Atual:\n");
	scanf("%d", &anoatual);
	
	idade1 = anoatual - anonasc;
	idade2 = 2050 - anonasc;
	
	printf("Sua idade e: %d\n", idade1);
	printf("Sua idade e: %d\n", idade2);
	
	return 0;
}
