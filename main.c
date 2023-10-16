#include <stdio.h>
#include <stdlib.h>
#include"aeroportos.c"
int main() {
    int aeroporto = 2939;
    struct Grafo* grafo = criaGrafo(aeroporto);
    FILE *f;
    int teste1;
    int teste2;

    f = fopen("openflights.csv", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while (fscanf(f, "%d;%d;", &teste1, &teste2) == 2) {
        addAresta(grafo, teste1, teste2);
    }

    int escolha;
    int aeroporto1, aeroporto2;

    do {
        printf("\nMenu:\n");
        printf("1. Imprimir todas as rotas\n");
        printf("2. Verificar se dois aeroportos tem rota entre si\n");
        printf("3. Imprimir as rotas de um aeroporto\n");
        printf("4. Sair\n");
        printf("so existem 2939 aeroportos!");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        

        switch (escolha) {
            case 1:
                printGrafo(grafo);
                break;
            case 2:
                printf("Digite o numero do primeiro aeroporto: ");
                scanf("%d", &aeroporto1);
                printf("Digite o numero do segundo aeroporto: ");
                scanf("%d", &aeroporto2);

                if (rotasAeroportos(grafo, aeroporto1, aeroporto2)) {
                    printf("Os aeroportos %d e %d possuem rotas entre si.\n", aeroporto1, aeroporto2);
                } else {
                    printf("Os aeroportos %d e %d nao possuem rotas entre si.\n", aeroporto1, aeroporto2);
                }
                break;
            case 3:
                printf("Digite o numero do aeroporto que deseja imprimir: ");
                scanf("%d", &aeroporto1);
                printArestasAeroporto(grafo, aeroporto1);
                break;
            case 4:
                printf("Encerrando o programa\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 4);

    fclose(f);
    return 0;
}