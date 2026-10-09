#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    int codigo[20], ano[20];
    char titulo[20][50], autor[20][50];

    int total = 3; //nao pode ser 0 porque o programa ja inicia com 3 livros pre-cadastrados
    int opcao, i, codigoBusca, posicao;
    
    //LIVRO 1
    codigo[0] = 12345;
    strcpy(titulo[0], "PequenoPrincipe");
    strcpy(autor[0], "Saint");
    ano[0] = 2000;
    
    //LIVRO 2
    codigo[1] = 12346;
    strcpy(titulo[1], "EntendendoAlgoritmos");
    strcpy(autor[1], "AdityaY.");
    ano[1] = 2018;
    
	//LIVRO 3
	codigo[2] = 12347	;
    strcpy(titulo[2], "OMassacredaFamiliaHope");
    strcpy(autor[2], "RileySager");
    ano[2] = 2019;
    
    do {
        printf("\n--- BIBLIOTECA ---\n");
        printf("1 - Cadastrar\n");
        printf("2 - Consultar\n");
        printf("3 - Listar\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            // CADASTRAR
            case 1:
               system("cls");
                if (total == 20) {  //se o vetor tiver 20 livros cadastrados
                    printf("Biblioteca cheia!\n");
                    break;
                }
				
                printf("Codigo: ");
                scanf("%d", &codigo[total]);

                printf("Titulo: ");
                scanf("%s", titulo[total]);

 		        printf("Autor: ");
                scanf("%s", autor[total]);

		        printf("Ano: ");
                scanf(" %d", &ano[total]);

                total++; //adiciona mais 1 livro para ser possivel lista-lo

                printf("Livro cadastrado!\n");
                
                break;


            // CONSULTAR
            case 2:
                system("cls");
                printf("Codigo do livro: ");  //codigo referencia para busca
                scanf("%d", &codigoBusca);   //Para achar um livro no programa se basendo no seu codigo de cadastro
                
                for (i = 0; i < total; i++) {

                    if (codigo[i] == codigoBusca) { //Se codigo[no veto i] = codigo[a ser consultado]

                        printf("\nCodigo: %d\n", codigo[i]);
                        printf("Titulo: %s\n", titulo[i]);
                        printf("Autor: %s\n", autor[i]);
                        printf("Ano: %d\n", ano[i]);
                        break;
                    }
                }

                if (i == total) //se ele chegar no total de livros cadastrados(apos verificar todos e nao achar o codigo escrito)
                    printf("Livro nao encontrado!\n");

                break;

            // LISTAR
            case 3:
                system("cls");
                if (total == 0) {   //se o total de livros cadastrados for 0(se todos os livros forem excluidos)
                    printf("Nenhum livro cadastrado!\n");
                    break;
            	}
                for (i = 0; i < total; i++) { //usa do FOR para percorrer e listar em conjuntos os valores(LIVROS E DESCRICOES) de todos os vetores
                    printf("\nCodigo: %d\n", codigo[i]);
                    printf("Titulo: %s\n", titulo[i]);
                    printf("Autor: %s\n", autor[i]);
                    printf("Ano: %d\n", ano[i]);
                }
                break;


            // ALTERAR
            case 4:
                system("cls");
                printf("Codigo do livro: "); //codigo referencia para busca
                scanf("%d", &codigoBusca);

                for (i = 0; i < total; i++) {  //Para achar um livro no programa se basendo no seu codigo de cadastro

                    if (codigo[i] == codigoBusca) {	//Quando ele acha o codigo do livro, ele solicita o novo valor que sera inserido
													//Um 1 memoria vetorial so pode te 1 valor(quando acontece a substituicao o vetor naturalmente apaga oque existe e altera para o novo)
                        printf("Novo titulo: ");
                        scanf("%s", titulo[i]);		//Lê o valor a ser alterado e armazena no [i] em questao
													//por isso o i dever o mesmo para codigo[i] = titulo[i] = autor[i] = ano[i]
                        printf("Novo autor: ");
                        scanf("%s", autor[i]);

                        printf("Novo ano: ");
                        scanf(" %d", &ano[i]);

                        printf("Livro alterado!\n");
                        break;
                    }
                }

                if (i == total)		//se ele chegar no final de livros cadastrados(apos verificar todos e nao achar o codigo escrito)
                    printf("Livro nao encontrado!\n");

                break;


            // EXCLUIR
            case 5:
                system("cls");
                printf("Codigo do livro: ");	//Codigo referencia para busca
                scanf("%d", &codigoBusca);

                for (i = 0; i < total; i++) {	//Percorre o vetor procurando o codigo escrito
                    if (codigo[i] == codigoBusca) {
                        posicao = i;			//Armazena a posicao i para as memorias vetoriais a serem excluidos
                        break;
                    }
                }

                if (i == total) {	//se ele chegar no final de livros cadastrados(apos verificar todos e nao achar o codigo escrito)
                    printf("Livro nao encontrado!\n");
                    break;
                }

                // Desloca os livros para tras
                for (i = posicao; i < total - 1; i++) {	//Faz uma alteracao nas posicoes nas memorias vetorias que nao foram excluidas
														//So alterando as memorias INT
                    codigo[i] = codigo[i + 1]; //percorre as memorias vetorias mandando elas para tras (titulo[1] => titulo[2]) => pega o codigo[2] escrevendou-o em codigo[1]
                    ano[i] = ano[i + 1];

                    // Copia o titulo
                    int j = 0;		//ajuda o programa a percorrer caracter por caracter partindo da memoria antiga para a memoria sendo escrita
                    
                    while (titulo[i + 1][j] != '\0') {	 // '/0' => para a leitura dos caracteres quando indentifica um caracter nulo(espaco ou enter)
                        titulo[i][j] = titulo[i + 1][j]; //transferencia de titulo[1] para titulo[0]
                        j++; 	//garante q ele leia caracter por caracter sem parar
                    }			//pq oq preve que o programa pare de ler é o titulo ou o nome do autor é o '/0'
                    titulo[i][j] = '\0';

                    // Copia o autor
                    j = 0;			//ajuda o programa a percorrer caracter por caracter partindo da memoria antiga para a memoria sendo escrita
                    while (autor[i + 1][j] != '\0') { 	 //condição de parada '/0'
                        autor[i][j] = autor[i + 1][j];
                        j++;
                    }
                    autor[i][j] = '\0'; //para a leitura dos caracteres transferidos
                }						//a transferencia do char ocorre de caracter por caracter
                						//a tranferencia int move o valor(como é um numero inteiro sem letras) para a nova memorial vetorial
                total--;				//esta movendo para tras (titulo[1] para titulo[0])

                printf("Livro excluido!\n");

                break;


            // SAIR
            case 0:				//encerra a execucao do programa
                system("cls");
                printf("Sistema encerrado!\n");
                break;


            default:			//caso a opcao escolhida nao for encontrada
                system("cls");
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
