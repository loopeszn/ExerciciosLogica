#include <stdio.h>
#include <stdlib.h>

int main(){
	float salario, cheque1, cheque2, cpmf1, cpmf2, saldoatual;

	printf("Insira o Valor do Salario que foi Depositado:\n");
    scanf("%f", &salario);

	printf("Digite o Valor do Primeiro Cheque que foi Emitido:\n");
    scanf("%f", &cheque1);
	
	printf("Digite o Valor do Segundo Cheque Emitido:\n");
    scanf("%f", &cheque2);

	cpmf1 = cheque1 * 0.0038;
    cpmf2 = cheque2 * 0.0038;
	saldoatual = salario - (cheque1 + cpmf1) - (cheque2 + cpmf2);
	
	printf("\n--- Extrato Bancario ---\n");
    printf("Valor Depositado: R$ %.2f\n", salario);
    printf("Cheque 1: R$ %.2f (CPMF: R$ %.2f)\n", cheque1, cpmf1);
    printf("Cheque 2: R$ %.2f (CPMF: R$ %.2f)\n", cheque2, cpmf2);
    printf("Saldo Atual da Conta: R$ %.2f\n", saldoatual);
    
	return 0;
}
