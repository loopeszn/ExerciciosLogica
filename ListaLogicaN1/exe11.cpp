#include <stdio.h>
#include <math.h>

int main(){
	float x, raiz, quad, cubo, raizcub;
	
	do{
		printf("Informe um Numero Maior ou Diferente de 0: \n");
		scanf("%f", &x);
		if (x <= 0){
		printf("Numero informado Invalido!!! \n");
	} else{
	raiz = sqrt(x);
	}} while (x <= 0);
	
	quad = x*x;
	cubo = x*x*x;
	raizcub = cbrt(x);
	
	printf("O Quadrado do Numero e: %.2f\n", quad);
	printf("O Cubo do Numero e: %.2f\n", cubo);	
	printf("A Raiz Quadrada do numero informado e: %.2f \n", raiz);
	printf("A Raiz Cubica do numero informado e: %.2f \n", raizcub);

	return 0;
}
