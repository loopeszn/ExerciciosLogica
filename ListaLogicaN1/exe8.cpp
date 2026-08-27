#include <stdio.h>

int main(){
	float deposito, rendimento, total;
	int taxa;
	
	printf("Informe o deposito feito: \n");
	scanf("%f", &deposito);
	
	printf("Informe a Taxa de Juros (em %%) que foi aplicada:\n");
	scanf("%d", &taxa);
	
	rendimento = deposito * (taxa/100.0);
	total = deposito - rendimento;
	
	printf("Seu Rendimento foi de: %.2fR$\n", total);
	
	return 0;
}
