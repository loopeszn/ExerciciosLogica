#include <stdio.h>

int main(){
	float n1, n2, n3, media;
	int p1, p2, p3;
	
	printf("Digite sua Nota 1:\n");
	scanf("%f", &n1);
	printf("Escolha um peso para sua Nota 1: \n");
	scanf("%d", &p1);
	
	printf("Digite sua Nota 2:\n");
	scanf("%f", &n2);
	printf("Escolha um peso para sua Nota 1: \n");
	scanf("%d", &p2);
	
	printf("Digite sua Nota 3:\n");
	scanf("%f", &n3);
	printf("Escolha um peso para sua Nota 1: \n");
	scanf("%d", &p3);
	
	media = ((n1*p1)+(n2*p2)+(n3*p3)) / (p1+p2+p3);
	
	printf("A media ponderada de suas notas com seus respectivos pesos e: %.2f\n", media);
	
	return 0;
}
