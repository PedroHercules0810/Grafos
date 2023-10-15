#include <stdio.h>
#include <stdlib.h>
#include"aeroportos.c"
int main()
{
    int aeroporto = 2939;
    struct Grafo* grafo = criaGrafo(aeroporto);
    FILE *f;
    int teste;
    int teste2;
    f = fopen("openflights.csv", "r");
    if (f == NULL)
    {
        printf("erro ao abrir o arquivo");
        return 1;
    }

    while (fscanf(f, "%d;%d;", &teste, &teste2) == 2) {
    addAresta( grafo, teste, teste2);
    }
    printGrafo(grafo);
    fclose(f);

    return 0;
}