#include <stdio.h>

int main(){
	float a, r;
	float pi = 3.14;
	
	printf("Digite a medida do Raio da Circunferencia:\n");
	scanf("%f", &r);
	
	a = pi *(r*r);
	
	printf("A medida da Area da Circunferencia e: %.2f\n", a);
	
	return 0;
}
