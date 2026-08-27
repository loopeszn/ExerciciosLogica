#include <stdio.h>

int main(){
	float a, b , h;
	
	printf("Informe a medida da Base do Triangulo:\n");
	scanf("%f", &b);
	
	printf("Informe a medida da Altura do Triangulo:\n");
	scanf("%f", &h);

	a = (b * h) / 2.0;
	
	printf("A medida da Area de seu triangulo e de: %.2f\n", a);
	
	return 0;
}
