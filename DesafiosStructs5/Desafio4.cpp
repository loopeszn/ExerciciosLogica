#include <stdio.h>
#include <string.h>

struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int estoque;
};

struct Venda {
    struct Produto produto;
    int quantidade;
    float valorTotal;
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

void cadastrarProduto(struct Produto produtos[], int *total) {
    if (*total >= 10) {
        printf("Limite de produtos atingido!\n");
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

    printf("Estoque: ");
    scanf("%d", &produtos[*total].estoque);
    limparBuffer();

    (*total)++;

    printf("Produto cadastrado!\n");
}

void registrarVenda(
    struct Produto produtos[],
    int totalProdutos,
    struct Venda vendas[],
    int *totalVendas
) {
    if (*totalVendas >= 20) {
        printf("Limite de vendas atingido!\n");
        return;
    }

    int codigo;
    int quantidade;

    printf("\nCodigo do produto: ");
    scanf("%d", &codigo);
    limparBuffer();

    int posicao = buscarProduto(produtos, totalProdutos, codigo);

    if (posicao == -1) {
        printf("Produto nao encontrado!\n");
        return;
    }

    printf("Quantidade vendida: ");
    scanf("%d", &quantidade);
    limparBuffer();

    if (quantidade <= 0) {
        printf("Quantidade invalida!\n");
        return;
    }

    if (quantidade > produtos[posicao].estoque) {
        printf("Estoque insuficiente!\n");
        return;
    }

    vendas[*totalVendas].produto = produtos[posicao];

    vendas[*totalVendas].quantidade = quantidade;

    vendas[*totalVendas].valorTotal =
        produtos[posicao].preco * quantidade;

    produtos[posicao].estoque -= quantidade;

    (*totalVendas)++;

    printf("Venda registrada!\n");
}

void relatorio(struct Venda vendas[], int totalVendas) {
    float faturamentoTotal = 0;
    float maiorFaturamento = 0;

    int posicaoMaior = -1;

    if (totalVendas == 0) {
        printf("Nenhuma venda registrada!\n");
        return;
    }

    for (int i = 0; i < totalVendas; i++) {
        faturamentoTotal += vendas[i].valorTotal;
    }

    for (int i = 0; i < totalVendas; i++) {
        float faturamentoProduto = 0;
        int primeiraVenda = 1;

        for (int k = 0; k < i; k++) {
            if (vendas[k].produto.codigo ==
                vendas[i].produto.codigo) {
                primeiraVenda = 0;
            }
        }

        if (primeiraVenda == 1) {
            for (int j = 0; j < totalVendas; j++) {
                if (vendas[j].produto.codigo ==
                    vendas[i].produto.codigo) {
                    faturamentoProduto += vendas[j].valorTotal;
                }
            }

            if (posicaoMaior == -1 ||
                faturamentoProduto > maiorFaturamento) {

                maiorFaturamento = faturamentoProduto;
                posicaoMaior = i;
            }
        }
    }

    printf("\nFaturamento total: R$ %.2f\n", faturamentoTotal);

    printf("Produto com maior faturamento: %s\n",
           vendas[posicaoMaior].produto.nome);

    printf("Faturamento do produto: R$ %.2f\n",
           maiorFaturamento);
}

int main() {
    struct Produto produtos[10];
    struct Venda vendas[20];

    int totalProdutos = 0;
    int totalVendas = 0;
    int opcao;

    do {
        printf("\n===== LOJA =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Registrar venda\n");
        printf("3 - Relatorio\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &totalProdutos);
                break;

            case 2:
                registrarVenda(
                    produtos,
                    totalProdutos,
                    vendas,
                    &totalVendas
                );
                break;

            case 3:
                relatorio(vendas, totalVendas);
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
