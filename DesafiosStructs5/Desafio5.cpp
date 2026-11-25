#include <stdio.h>
#include <string.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Paciente {
    int codigo;
    char nome[50];
};

struct Consulta {
    struct Paciente paciente;
    struct Data data;
};

void limparBuffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

int buscarPaciente(struct Paciente pacientes[], int total,int codigo) {
    for (int i = 0; i < total; i++) {
        if (pacientes[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

void cadastrarPaciente(
    struct Paciente pacientes[],
    int *totalPacientes
) {
    if (*totalPacientes >= 15) {
        printf("Limite de pacientes atingido!\n");
        return;
    }

    int codigo;

    printf("\nCodigo do paciente: ");
    scanf("%d", &codigo);
    limparBuffer();

    if (buscarPaciente(pacientes, *totalPacientes, codigo) != -1) {
        printf("Codigo ja cadastrado!\n");
        return;
    }

    pacientes[*totalPacientes].codigo = codigo;

    printf("Nome do paciente: ");
    fgets(pacientes[*totalPacientes].nome, 50, stdin);
    pacientes[*totalPacientes].nome[
        strcspn(pacientes[*totalPacientes].nome, "\n")
    ] = '\0';

    (*totalPacientes)++;

    printf("Paciente cadastrado!\n");
}

void registrarConsulta(
	struct Paciente pacientes[],
    int totalPacientes,
    struct Consulta consultas[],
    int *totalConsultas) {
    	
    if (*totalConsultas >= 30) {
        printf("Limite de consultas atingido!\n");
        return;
    }

    int codigo;

    printf("\nCodigo do paciente: ");
    scanf("%d", &codigo);
    limparBuffer();

    int posicao = buscarPaciente(pacientes, totalPacientes, codigo);

    if (posicao == -1) {
        printf("Paciente nao encontrado!\n");
        return;
    }

    consultas[*totalConsultas].paciente = pacientes[posicao];

    printf("Dia: ");
    scanf("%d", &consultas[*totalConsultas].data.dia);
    limparBuffer();

    printf("Mes: ");
    scanf("%d", &consultas[*totalConsultas].data.mes);
    limparBuffer();

    printf("Ano: ");
    scanf("%d", &consultas[*totalConsultas].data.ano);
    limparBuffer();

    (*totalConsultas)++;

    printf("Consulta registrada!\n");
}

void pesquisarConsultas(
    struct Consulta consultas[],
    int totalConsultas
) {
    int codigo;
    int encontrou = 0;

    printf("\nCodigo do paciente: ");
    scanf("%d", &codigo);
    limparBuffer();

    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].paciente.codigo == codigo) {
            printf("\nPaciente: %s",
                   consultas[i].paciente.nome);

            printf("\nData: %02d/%02d/%04d\n",
                   consultas[i].data.dia,
                   consultas[i].data.mes,
                   consultas[i].data.ano);

            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("Nenhuma consulta encontrada!\n");
    }
}

void listarPorData(
    struct Consulta consultas[],
    int totalConsultas
) {
    int dia, mes, ano;
    int encontrou = 0;

    printf("\nDigite o dia: ");
    scanf("%d", &dia);
    limparBuffer();

    printf("Digite o mes: ");
    scanf("%d", &mes);
    limparBuffer();

    printf("Digite o ano: ");
    scanf("%d", &ano);
    limparBuffer();

    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].data.dia == dia &&
            consultas[i].data.mes == mes &&
            consultas[i].data.ano == ano) {

            printf("\nPaciente: %s",
                   consultas[i].paciente.nome);

            printf("\nCodigo: %d",
                   consultas[i].paciente.codigo);

            printf("\nData: %02d/%02d/%04d\n",
                   consultas[i].data.dia,
                   consultas[i].data.mes,
                   consultas[i].data.ano);

            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("Nenhuma consulta nessa data!\n");
    }
}

void relatorio(
    struct Paciente pacientes[],
    int totalPacientes,
    struct Consulta consultas[],
    int totalConsultas
) {
    int maiorQuantidade = 0;
    int posicaoMaior = -1;

    for (int i = 0; i < totalPacientes; i++) {
        int quantidade = 0;

        for (int j = 0; j < totalConsultas; j++) {
            if (pacientes[i].codigo ==
                consultas[j].paciente.codigo) {
                quantidade++;
            }
        }

        printf("\nPaciente: %s", pacientes[i].nome);
        printf("\nQuantidade de consultas: %d\n", quantidade);

        if (posicaoMaior == -1 ||
            quantidade > maiorQuantidade) {

            maiorQuantidade = quantidade;
            posicaoMaior = i;
        }
    }

    if (posicaoMaior != -1 && maiorQuantidade > 0) {
        printf("\nPaciente com mais atendimentos: %s\n",
               pacientes[posicaoMaior].nome);

        printf("Quantidade: %d\n", maiorQuantidade);
    } else {
        printf("\nNenhuma consulta registrada.\n");
    }
}

int main() {
    struct Paciente pacientes[15];
    struct Consulta consultas[30];

    int totalPacientes = 0;
    int totalConsultas = 0;
    int opcao;

    do {
        printf("\n===== SISTEMA MEDICO =====\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Registrar consulta\n");
        printf("3 - Pesquisar consultas por paciente\n");
        printf("4 - Listar consultas por data\n");
        printf("5 - Relatorio de atendimentos\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                cadastrarPaciente(pacientes, &totalPacientes);
                break;

            case 2:
                registrarConsulta(
                    pacientes,
                    totalPacientes,
                    consultas,
                    &totalConsultas
                );
                break;

            case 3:
                pesquisarConsultas(consultas, totalConsultas);
                break;

            case 4:
                listarPorData(consultas, totalConsultas);
                break;

            case 5:
                relatorio(
                    pacientes,
                    totalPacientes,
                    consultas,
                    totalConsultas
                );
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
