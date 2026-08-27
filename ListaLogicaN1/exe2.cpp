#include <stdio.h>

int main(){
	float n1, n2, n3, media;
	
	printf("Digite sua Nota 1:\n");
	scanf("%f", &n1);
	
	printf("Digite sua Nota 2:\n");
	scanf("%f", &n2);
	
	printf("Digite sua Nota 3:\n");
	scanf("%f", &n3);
	
	media = (n1+n2+n3) / 3.0;
	
	printf("A media de suas notas e: %.2f \n", media);
	
	return 0;
}
