#include <stdio.h>
#include <string.h>

struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

void limparBuffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

int buscarProduto(struct Produto produtos[], int total, int codigo) {
    for (int i = 0; i < total; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

void cadastrar(struct Produto produtos[], int *total) {
    if (*total >= 15) {
        printf("Cadastro cheio!\n");
        return;
    }

    int codigo;

    printf("\nCodigo: ");
    scanf("%d", &codigo);
    limparBuffer();

    if (buscarProduto(produtos, *total, codigo) != -1) {
        printf("Codigo ja cadastrado!\n");
        return;
    }

    produtos[*total].codigo = codigo;

    printf("Nome: ");
    fgets(produtos[*total].nome, 50, stdin);
    produtos[*total].nome[strcspn(produtos[*total].nome, "\n")] = '\0';

    printf("Preco: ");
    scanf("%f", &produtos[*total].preco);
    limparBuffer();

    printf("Quantidade: ");
    scanf("%d", &produtos[*total].quantidade);
    limparBuffer();

    (*total)++;

    printf("Produto cadastrado!\n");
}

void listar(struct Produto produtos[], int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\nCodigo: %d", produtos[i].codigo);
        printf("\nNome: %s", produtos[i].nome);
        printf("\nPreco: R$ %.2f", produtos[i].preco);
        printf("\nQuantidade: %d\n", produtos[i].quantidade);
    }
}

void repor(struct Produto produtos[], int total) {
    int codigo;
    int quantidade;

    printf("\nCodigo do produto: ");
    scanf("%d", &codigo);
    limparBuffer();

    int posicao = buscarProduto(produtos, total, codigo);

    if (posicao == -1) {
        printf("Produto nao encontrado!\n");
        return;
    }

    printf("Quantidade para adicionar: ");
    scanf("%d", &quantidade);
    limparBuffer();

    if (quantidade <= 0) {
        printf("Quantidade invalida!\n");
        return;
    }

    produtos[posicao].quantidade += quantidade;

    printf("Estoque atualizado!\n");
}

void vender(struct Produto produtos[], int total) {
    int codigo;
    int quantidade;

    printf("\nCodigo do produto: ");
    scanf("%d", &codigo);
    limparBuffer();

    int posicao = buscarProduto(produtos, total, codigo);

    if (posicao == -1) {
        printf("Produto nao encontrado!\n");
        return;
    }

    printf("Quantidade para vender: ");
    scanf("%d", &quantidade);
    limparBuffer();

    if (quantidade <= 0) {
        printf("Quantidade invalida!\n");
    } else if (quantidade > produtos[posicao].quantidade) {
        printf("Estoque insuficiente!\n");
    } else {
        produtos[posicao].quantidade -= quantidade;

        printf("Venda realizada!\n");
    }
}

void consultar(struct Produto produtos[], int total) {
    int codigo;

    printf("\nDigite o codigo: ");
    scanf("%d", &codigo);
    limparBuffer();

    int posicao = buscarProduto(produtos, total, codigo);

    if (posicao == -1) {
        printf("Produto nao encontrado!\n");
    } else {
        printf("\nNome: %s", produtos[posicao].nome);
        printf("\nPreco: R$ %.2f", produtos[posicao].preco);
        printf("\nEstoque: %d\n", produtos[posicao].quantidade);
    }
}

void relatorio(struct Produto produtos[], int total) {
    float valorTotal = 0;
    float maiorValor = 0;

    int posicaoMaior = -1;

    for (int i = 0; i < total; i++) {
        float valor = produtos[i].preco * produtos[i].quantidade;

        valorTotal += valor;

        if (posicaoMaior == -1 || valor > maiorValor) {
            maiorValor = valor;
            posicaoMaior = i;
        }
    }

    printf("\nValor total do estoque: R$ %.2f\n", valorTotal);

    if (posicaoMaior != -1) {
        printf("Produto com maior valor em estoque: %s\n",
               produtos[posicaoMaior].nome);

        printf("Valor: R$ %.2f\n", maiorValor);
    }
}

int main() {
    struct Produto produtos[15];

    int total = 0;
    int opcao;

    do {
        printf("\n===== PAPELARIA =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Repor estoque\n");
        printf("4 - Vender produto\n");
        printf("5 - Consultar produto\n");
        printf("6 - Relatorio\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                cadastrar(produtos, &total);
                break;

            case 2:
                listar(produtos, total);
                break;

            case 3:
                repor(produtos, total);
                break;

            case 4:
                vender(produtos, total);
                break;

            case 5:
                consultar(produtos, total);
                break;

            case 6:
                relatorio(produtos, total);
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

