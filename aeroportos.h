struct No* createNode(int vizinho);
struct Grafo* createGrafo(int aeroporto);
void addAresta(struct Grafo* grafo, int origem, int destino);
void printGrafo(struct Grafo* grafo);
void printArestasAeroporto(struct Grafo* grafo, int aeroportoDesejado);
int saoVizinhos(struct Grafo* grafo, int aeroporto1, int aeroporto2);