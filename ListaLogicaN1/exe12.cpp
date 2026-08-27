#include <stdio.h>
#include <math.h>

int main(){
	float a, b, potencia;
	
	printf("Informe a base da potencia:\n");
	scanf("%f", &a);
	printf("Informe o expoente da potencia:\n");
	scanf("%f", &b);
	
	potencia = pow(a,b);
	
	printf("Apotencia e de %.1f elevado a %.1f \n", a, b);
	printf("Valor da Potencia e de: %.1f\n", potencia);
	
	return 0;
}
