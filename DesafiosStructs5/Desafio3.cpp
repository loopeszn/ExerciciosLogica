#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void limparBuffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

struct Funcionario {
    int codigo;
    char nome[50];
    char cargo[50];
    float salarioBase;
    float horasExtras;
    float salarioLiquido;
};

float calcularHoraExtra(float salarioBase) {
    float horaNormal = salarioBase / 160;

    return horaNormal * 1.5;
}

float calcularBruto(float salarioBase, float horasExtras) {
    float valorExtra = calcularHoraExtra(salarioBase);

    return salarioBase + (valorExtra * horasExtras);
}

float calcularLiquido(float salarioBruto) {
    float desconto = salarioBruto * 0.10;

    return salarioBruto - desconto;
}

int main() {
    struct Funcionario funcionarios[8];

    float totalFolha = 0;
    int maior = 0;

    for (int i = 0; i < 8; i++) {
        printf("\nFuncionario %d\n", i + 1);

        printf("Codigo: ");
        scanf("%d", &funcionarios[i].codigo);
        limparBuffer();

        printf("Nome: ");
        fgets(funcionarios[i].nome, 50, stdin);
        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0';

        printf("Cargo: ");
        fgets(funcionarios[i].cargo, 50, stdin);
        funcionarios[i].cargo[strcspn(funcionarios[i].cargo, "\n")] = '\0';

        printf("Salario base: ");
        scanf("%f", &funcionarios[i].salarioBase);
        limparBuffer();

        printf("Horas extras: ");
        scanf("%f", &funcionarios[i].horasExtras);
        limparBuffer();

        float bruto = calcularBruto(
            funcionarios[i].salarioBase,
            funcionarios[i].horasExtras
        );

        funcionarios[i].salarioLiquido = calcularLiquido(bruto);

        totalFolha += funcionarios[i].salarioLiquido;
    }

    for (int i = 0; i < 8; i++) {
        printf("\nNome: %s", funcionarios[i].nome);
        printf("\nCargo: %s", funcionarios[i].cargo);

        printf("\nSalario liquido: R$ %.2f\n",
               funcionarios[i].salarioLiquido);

        if (funcionarios[i].salarioLiquido >
            funcionarios[maior].salarioLiquido) {
            maior = i;
        }
    }

    printf("\nMaior salario liquido: %s\n",
           funcionarios[maior].nome);

    printf("Valor: R$ %.2f\n",
           funcionarios[maior].salarioLiquido);

    printf("Custo total da folha: R$ %.2f\n", totalFolha);

    return 0;
}
