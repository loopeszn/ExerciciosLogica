#include <stdio.h>

int main(){
	float x, pes, jardas, milha;
	
	printf("imprima um valor em Polegadas para ser convertido: \n");
	scanf("%f", &x);
	
	pes = x * 12;
	jardas = pes / 3.0;
	milha = pes / (3.0 * 1760.0);
	
	printf("Conversoes:\n ");
	printf("Convertido de Polegadas para Pes: %.2f\n ", pes);
	printf("Convertido de Polegadas para Jardas: %.2f\n ", jardas);
	printf("Convertido de Polegadas para Milha: %f\n ", milha);
	
	return 0;
}
