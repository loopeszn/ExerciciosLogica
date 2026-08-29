#include <stdio.h>

int main(){
	float precfabrica, perclucro, percimpost;	
	float distlucro, valorimpost, total;
	
	printf("Insira o preco de Fabrica do Veiculo:\n");
	scanf("%f", &precfabrica);
	
	printf("Insira o Percentual de lucro do Distribuidor em %%:\n");
	scanf("%f", &perclucro);
	
	printf("Insira o Percentual Impostos em %%:\n");
	scanf("%f", &percimpost);
	
	distlucro = precfabrica * (percimpost / 100.0);	
	valorimpost = precfabrica * (perclucro/100.0);
	total = precfabrica	+ distlucro + valorimpost;
	
	printf("Valor do Lucro do Distribuidor: %.2fR$\n", distlucro);
	printf("Valor do Impostos: %.2fR$\n", valorimpost);
	printf("Valor Final do Veiculo: %.2fR$\n", total);
	
	return 0;
}
