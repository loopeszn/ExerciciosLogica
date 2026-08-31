#include <stdio.h>

int main(){
	float pesoSaco, gramaporgato, totalconsumido, resto;
	
	printf("Digite o Peso do Saco de Racao (em kg):\n");
    scanf("%f", &pesoSaco);
	
	printf("Digite a Quantidade de Racao para cada Gato (em gramas): ");
    scanf("%f", &gramaporgato);
	
	totalconsumido = (gramaporgato * 2 * 5) / 1000.0;
	resto = pesoSaco - totalconsumido;
	
	printf("Resta no saco depois de 5 dias: %.2fKG\n", resto);
	
	return 0;
}
