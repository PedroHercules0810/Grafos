#include<stdlib.h>
#include<stdio.h>
#include"aeroportos.h"
struct No {
    int rota;
    struct No* prox;
};
struct Grafo {
    int aeroporto;            
    struct No** aresta;
};

struct No* criaNo(int rota) {
    struct No* newNode = (struct No*)malloc(sizeof(struct No));
    newNode->rota = rota;
    newNode->prox = NULL;
    return newNode;
}


struct Grafo* criaGrafo(int aeroporto) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->aeroporto = aeroporto;
    grafo->aresta = (struct No**)malloc(aeroporto * sizeof(struct No*));

    for (int i = 0; i < aeroporto; i++) {
        grafo->aresta[i] = NULL;
    }

    return grafo;
}


void addAresta(struct Grafo* grafo, int origem, int destino) {
    
    struct No* newNode = criaNo(destino);
    newNode->prox = grafo->aresta[origem];
    grafo->aresta[origem] = newNode;

    
    newNode = criaNo(origem);
    newNode->prox = grafo->aresta[destino];
    grafo->aresta[destino] = newNode;
}


void printGrafo(struct Grafo* grafo) {
    for (int a = 0; a < grafo->aeroporto; a++) {
        struct No* temp = grafo->aresta[a];
        printf("Rotas do aeroporto %d\n", a);
        while (temp) {
            printf(" -> %d", temp->rota);
            temp = temp->prox;
        }
        printf("\n");
    }
}

void printArestasAeroporto(struct Grafo* grafo, int aeroportoDesejado) {
    if (aeroportoDesejado < 0 || aeroportoDesejado >= grafo->aeroporto) {
        printf("Aeroporto invalido\n");
        return;
    }

    struct No* temp = grafo->aresta[aeroportoDesejado];
    printf("Rotas do aeroporto %d:\n", aeroportoDesejado);
    while (temp) {
        printf(" -> %d", temp->rota);
        temp = temp->prox;
    }
    printf("\n");
}

int rotasAeroportos(struct Grafo* grafo, int aeroporto1, int aeroporto2) {
    if (aeroporto1 < 0 || aeroporto1 >= grafo->aeroporto || aeroporto2 < 0 || aeroporto2 >= grafo->aeroporto) {
        printf("Aeroportos invalidos\n");
        return 0;
    }

    struct No* temp = grafo->aresta[aeroporto1];
    while (temp) {
        if (temp->rota == aeroporto2) {
            return 1; 
        }
        temp = temp->prox;
    }

    return 0; 
}