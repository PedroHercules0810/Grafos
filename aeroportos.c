#include<stdlib.h>
#include<stdio.h>
#include"aeroportos.h"
struct No {
    int vizinho;
    struct No* prox;
};
struct Grafo {
    int aeroporto;            
    struct No** aresta;
};

struct No* criaNo(int vizinho) {
    struct No* newNode = (struct No*)malloc(sizeof(struct No));
    newNode->vizinho = vizinho;
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
        printf("Arestas do aeroporto %d\n", a);
        while (temp) {
            printf(" -> %d", temp->vizinho);
            temp = temp->prox;
        }
        printf("\n");
    }
}