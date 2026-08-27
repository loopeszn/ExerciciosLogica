include <stdio.h>

int main(){
	int n1, n2, n3, n4, soma;
	
	printf("Digite sua Nota 1:\n");
	scanf("%d", &n1);
	
	printf("Digite sua Nota 2:\n");
	scanf("%d", &n2);
	
	printf("Digite sua Nota 3:\n");
	scanf("%d", &n3);
	
	printf("Digite sua Nota 4:\n");
	scanf("%d", &n4);
	
	soma = n1+n2+n3+n4;
	
	print("A Soma de suas notas e: %d\n", soma);
	return 0;
}
