#include <stdio.h>
#include <stdlib.h>

struct aluno{
	int matricula;
	char nome[50];
	float media, nota1, nota2;
};

typedef struct aluno aluno;

void cad_aluno(aluno turma[], int n){
	int i;

	printf("Cadastro dos %d Alunos da Turma:\n", n);

	for(i=0;i<n;i++){
		printf("\nCadastro Aluno(%d):\n", i+1);

		printf("Nome: ");
		scanf(" %49[^\n]", turma[i].nome);

		printf("Matricula: ");
		scanf("%d", &turma[i].matricula);

		printf("Nota 1 do Aluno(%d): ", i+1);
		scanf("%f", &turma[i].nota1);

		printf("Nota 2 do Aluno(%d): ", i+1);
		scanf("%f", &turma[i].nota2);
	}
}

void calc_medias(aluno turma[], int n){
	int i;

	for(i=0;i<n;i++){
		turma[i].media = (turma[i].nota1 + turma[i].nota2) / 2.0;
	}
}

void exibir_situacao(aluno turma[], int n){
	int i;

	printf("\n====Situacao dos Alunos====\n");
	for(i=0;i<n;i++){
		printf("Matricula: %d | Nome: %s | Media: %.2f | ", turma[i].matricula, turma[i].nome, turma[i].media);
		if(turma[i].media >= 6.0){
			printf("Aprovado\n");
		}else{
			printf("Reprovado\n");
		}
	}
}

float media_aluno(aluno turma[], int n, int ped_media){
	int i;

	printf("Calculando a Media do Aluno:\n");
	for(i=0;i<n;i++){

		if(turma[i].matricula == ped_media){
			printf("Matricula (%d) encontrada\n", turma[i].matricula);
			turma[i].media = (turma[i].nota1 + turma[i].nota2) / 2.0;
			printf("Media do Aluno e: %.2f\n", turma[i].media);
			return turma[i].media;
		}
	}
	printf("Matricula do Aluno nao encontrada\n");
	return -1;
}

int main(){

	int i, ped_media;
	int maior = 0, menor = 0, acima = 0;
	float soma = 0, geral;
	aluno turma[10];

	cad_aluno(turma, 10);
	printf("\n====Alunos Cadastrados====\n");

	calc_medias(turma, 10);
	exibir_situacao(turma, 10);

	for(i=0;i<10;i++){
		if(turma[i].media > turma[maior].media){
			maior = i;
		}
		if(turma[i].media < turma[menor].media){
			menor = i;
		}
		soma += turma[i].media;
	}
	geral = soma / 10;

	for(i=0;i<10;i++){
		if(turma[i].media > geral){
			acima++;
		}
	}

	printf("\n====Resultados da Turma====\n");
	printf("Maior media: %s (Matricula %d) - %.2f\n", turma[maior].nome, turma[maior].matricula, turma[maior].media);
	printf("Menor media: %s (Matricula %d) - %.2f\n", turma[menor].nome, turma[menor].matricula, turma[menor].media);
	printf("Media geral da turma: %.2f\n", geral);
	printf("Alunos acima da media geral: %d\n", acima);

	printf("\nMatricula do Aluno para calculo de sua Media: ");
	scanf("%d", &ped_media);
	media_aluno(turma, 10, ped_media);

	return 0;
}
