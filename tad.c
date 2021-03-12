#include "tad.h"

void inicializaMatriz(TipoGrafo *m) {
    m->matriz = NULL;
    m->numArestas = 0;
    m->nomeArquivo = (char *) malloc((255) * sizeof(char));
    m->numVertices = 0;
}

float **alocaMatriz(int m) {
    int i, j;
    float **v;

    // aloca as linhas da matriz
    v = (float **) malloc((m) * sizeof(float *));
    if (v == NULL)
        return NULL;

    // aloca as colunas da matriz
    for (i = 0; i < m; i++) {
        v[i] = (float *) malloc((m) * sizeof(float));
        if (v[i] == NULL)
            return NULL;
    }

    // inicializa matriz com valor valorInicial pre definido
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++)
            v[i][j] = valorInicial;

    }

    return (v);
}

void imprime(TipoGrafo grafo) {
    int i, j;
    for (i = 0; i < grafo.numVertices; i++) {
        for (j = 0; j < grafo.numVertices; j++) {
            printf("%.2f ", grafo.matriz[i][j]);
        }
        printf("\n");
    }
}

void vizinhos(TipoGrafo grafo, int vertice) {
    int i, j;
    printf("\n\tVizinhos de %d\n", vertice);
    for (i = 0; i < grafo.numVertices; i++) {
        if (grafo.matriz[vertice - 1][i] != valorInicial)
            printf("Vertice: %d\n", i + 1);
    }
    printf("\n\n");
}

int grau(TipoGrafo grafo, int vertice) {
    int i, j, grau = 0;
    for (i = 0; i < grafo.numVertices; i++) {
        if (grafo.matriz[vertice - 1][i] != valorInicial)
            grau++;
    }
    return grau;
}

//BUSCA DE PROFUNDIDADE
void ImprimeProf(TipoGrafo G) {
    int i;
    //pre = malloc(G.numVertices * sizeof(int*));
    BuscaProfun(G);

    for (i = 0; i < G.numVertices; i++) {
        // printf("\n %d ",pre[i]);
    }
}

void BuscaProfun(TipoGrafo G) {
    int v, i;
    for (i = 0; i < qtd; i++)
        retorno[i][0] = retorno[i][1] = -1;
    conta = 1;
    for (v = 0; v < G.numVertices; v++)
        pre[v] = -1;
    for (v = 0; v < G.numVertices; v++)
        if (pre[v] == -1)
            BuscaProfunR(G, v);
    int cont = 0;
    while (retorno[cont][0] != -1) {
        printf("Retorno de %d para %d\n", retorno[cont][1], retorno[cont][0]);
        cont++;
    }
}

void BuscaProfunR(TipoGrafo G, int v) {
    int w;
    int i, cont = 0;
    while (retorno[cont][0] != -1)
        cont++;
    printf("%3d\n", v + 1);
    pre[v] = conta++;
    for (w = 0; w < G.numVertices; w++) {
        if (G.matriz[v][w] != valorInicial && pre[w] == -1)
            BuscaProfunR(G, w);
        if (G.matriz[v][w] != valorInicial && pre[w] != -1) {
            retorno[cont][0] = v + 1;
            retorno[cont][1] = w + 1;
            cont++;
        }
    }

}

//BUSCA EM LARGURA
void fazFila(int maxN) {
    q = (Item *) malloc(maxN * sizeof(Item));
    inicio = 0;
    fim = 0;
}

int filavazia() {
    return inicio == fim;
}

void enfileira(Item item) {
    q[fim++] = item;
}

Item desenfileira() {
    return q[inicio++];
}

void freeFila() {
    free(q);
}

void buscaEmLargura(TipoGrafo G, int s) {
    int v, w, i;
    conta = 0;
    for (v = 0; v < G.numVertices; v++)
        low[v] = -1;
    fazFila(G.numVertices);
    pre[conta] = s;
    low[s] = conta++;
    enfileira(s);
    while (!filavazia()) {
        v = desenfileira();
        printf("| %7d |", v + 1);
        for (w = 0; w < G.numVertices; w++) {
            if (G.matriz[v][w] != valorInicial && low[w] == -1) {
                low[w] = conta++;
                pre[conta] = w;
                enfileira(w);
                printf(" %3d ", w + 1);
            }
        }
        printf("\n");
    }
    freeFila();
}

//BIPARTIDO
int GRAPHtwocolor(TipoGrafo G) {
    int v;
    int c = 0;
    for (v = 0; v < G.numVertices; v++)
        color[v] = -1;
    for (v = 0; v < G.numVertices; v++)
        if (color[v] == -1)
            if (dfsRcolor(G, v, 0) == 0)
                return 0;
    return 1;
}

int dfsRcolor(TipoGrafo G, int v, int c) {
    int i, j;
    color[v] = 1 - c;
    for (i = 0; i < G.numVertices; i++) {
        if (G.matriz[v][i] != valorInicial) {
            if (color[i] == -1) {
                if (dfsRcolor(G, i, 1 - c) == 0) return 0;
            } else if (color[i] == 1 - c) return 0;
        }
    }
    return 1;
}

//CAMINHO DE CUSTO MINIMO
void dijkstra(TipoGrafo G, int s) {
    int v0, w, mindist;
    int i;
    float c;
    distancia = malloc(G.numVertices * sizeof(float));
    vet = malloc(G.numVertices * sizeof(int));
    rot = malloc(G.numVertices * sizeof(int));
    iniciaVars(G, s);//inicia rot com inifinito, vet recebe o vertice, distancia recebe valorInicial.

    while (1) {
        mindist = INF;
        for (w = 1; w < G.numVertices; w++) {
            if (vet[w] == -1 && mindist > distancia[w])
                mindist = distancia[v0 = w];
        }
        if (mindist == INF) break;
        vet[v0] = rot[v0];
        for (w = 0; w < G.numVertices; w++) {
            if (G.matriz[v0][w] != 0) {
                c = G.matriz[v0][w];
                if (vet[w] == -1 && distancia[w] > distancia[v0] + c) {
                    distancia[w] = distancia[v0] + c;
                    rot[w] = v0;
                }
            }
        }
    }
    for (i = 0; i < G.numVertices; i++) {
        printf("%5d ", i + 1);
        if (rot[i] != INF)
            printf("sequencia(rot) %d\t\t", rot[i] + 1);
        else
            printf("sequencia(rot) oo\t\t");
        printf("distancia %5.2f\n", distancia[i]);
    }
}

void iniciaVars(TipoGrafo G, int s) {
    int w;
    int c;
    for (w = 0; w < G.numVertices; w++) {
        vet[w] = -1;
        distancia[w] = INF;
    }
    vet[s] = s;
    distancia[s] = 0.0;
    rot[s] = INF;
    for (w = 0; w < G.numVertices; w++) {
        if (G.matriz[s][w] != 0) {
            c = G.matriz[s][w];
            distancia[w] = c;
            rot[w] = s;
        }
    }
}

//ARVORE GERADORA MINIMA
void mst(TipoGrafo G, int parent[]) {
    int v0;
    int w, frj[qtd];
    int a;
    FILE *arvoreMinima;
    float price[qtd], c, total = 0;
    arvoreMinima = fopen("resultado.txt", "at");
    fprintf(arvoreMinima, "%d\n", G.numVertices);
    for (w = 0; w < G.numVertices; w++) {
        parent[w] = -1, price[w] = INF;
    }

    v0 = 0;
    parent[v0] = v0;
    for (w = 0; w < G.numVertices; w++) {
        if (G.matriz[v0][w] != 0) {
            price[w] = G.matriz[v0][w];
            frj[w] = v0;
        }

    }

    while (1) {
        double minprice = INF;
        for (w = 0; w < G.numVertices; w++)
            if (parent[w] == -1 && minprice > price[w])
                minprice = price[v0 = w];
        if (minprice == INF) break;
        parent[v0] = frj[v0];
        for (w = 0; w < G.numVertices; w++) {
            if (G.matriz[v0][w] != 0) {
                c = G.matriz[v0][w];
                if (parent[w] == -1 && price[w] > c) {
                    price[w] = c;
                    frj[w] = v0;
                }
            }
        }
    }
    for (w = 0; w < G.numVertices; w++) {
        if (w == 0 && frj[w] == 0)
            continue;
        printf("|%5d\t%5d   | \t%.2f\n", w + 1, frj[w] + 1, price[w]);
        fprintf(arvoreMinima, "%d %d %.2f\n", w + 1, frj[w] + 1, price[w]);
        total = total + price[w];
    }
    printf("%.2f \n", total);
    fclose(arvoreMinima);
}

//PONTE
int GRAPHbridges(TipoGrafo G) {
    int v;
    conta = 0;
    numpts = 0;
    for (v = 0; v < G.numVertices; v++)
        pre[v] = -1;
    for (v = 0; v < G.numVertices; v++)
        if (pre[v] == -1) {
            parent[v] = v;
            bridgeR(G, v);
        }
    return numpts;
}

void bridgeR(TipoGrafo G, int v) {
    int w;
    pre[v] = conta++;///a cada chamada ele tira um v?rtice do vetor de v?rtices marcados pre.
    low[v] = pre[v];
    for (w = 0; w < G.numVertices; w++) {
        if (G.matriz[v][w] != 0) {
            if (pre[w] == -1) {
                parent[w] = v;
                bridgeR(G, w);
                if (low[v] > low[w]) low[v] = low[w];
                //if(v==w) printf("eh ponte");
                if (low[w] == pre[w]) {
                    if ((vertice1 == v + 1 && vertice2 == w + 1) || (vertice1 == w + 1 && vertice2 == v + 1))
                        numpts++;
                }
            } else if (w != parent[v] && low[v] > pre[w])
                low[v] = pre[w];
        }
    }
}

//ARTICULA??O
void grafoArticulacao(TipoGrafo G, int vertice) {
    TipoGrafo grafo;
    grafo.numVertices = G.numVertices;
    grafo.matriz = alocaMatriz(G.numVertices);
    int i, j;
    for (i = 0; i < G.numVertices; i++) {
        for (j = 0; j < G.numVertices; j++) {
            grafo.matriz[i][j] = G.matriz[i][j];
        }
    }
    for (j = 0; j < G.numVertices; j++) {
        if (grafo.matriz[vertice - 1][j] != valorInicial) {
            grafo.matriz[vertice - 1][j] = valorInicial;
            grafo.matriz[j][vertice - 1] = valorInicial;
        }
    }
    if (GRAPHcc(grafo) > GRAPHcc(G) + 1)
        printf("\n\tVertice %d eh uma articulacao!\n\n", vertice);
    else
        printf("\n\tVertice %d nao eh uma articulacao!\n\n", vertice);
}


//COMPONENTE CONEXA
int GRAPHcc(TipoGrafo G) {
    int v, id, i;
    id = 0;
    for (v = 0; v < G.numVertices; v++)
        pre[v] = -1;
    for (v = 0; v < G.numVertices; v++)
        if (pre[v] == -1)
            dfsRcc(G, v, id++);
    return id;
}

void dfsRcc(TipoGrafo G, int v, int id) {
    int w;
    pre[v] = id;
    for (w = 0; w < G.numVertices; w++)
        if (G.matriz[v][w] != valorInicial && pre[w] == -1)
            dfsRcc(G, w, id);
}

//CIRCUITO NEGATIVO

float FindMinDistance(float **matrix, float matrixSize, float pt1, float pt2) {
    int i, j, k;
    int ponto1, ponto2;
    ponto1 = pt1;
    ponto2 = pt2;
    for (i = 0; i < matrixSize; ++i) {
        for (j = 0; j < matrixSize; ++j)
            if (j != i && matrix[j][i] < 999)
                for (k = 0; k < matrixSize; ++k) {
                    matrix[j][k] = minPonto(matrix[j][k], matrix[j][i] + matrix[i][k]);
                }
    }
    PrintMatrix(matrix, matrixSize);
    return matrix[ponto1 - 1][ponto2 - 1];
}

float minPonto(float x, float y) {
    if (x < y)
        return x;
    else
        return y;
}

void PrintMatrix(float **matrix, float matrixSize) {
    int i, j;
    for (i = 0; i < matrixSize; ++i) {
        for (j = 0; j < matrixSize; ++j)
            printf("%.8f\t", matrix[i][j]);
        printf("\n");
    }
}

void Floyd(TipoGrafo G) {
    int numRows, numPoints,   /* number of points and number of the rows in the file*/
    i, j,                  /* counters for counter-controlled loops */
    status = 0,           /* for fscanf */
    dist;                 /* temporary distance holder */
    float pt1, pt2, **matrix;         /* temporary point holders */
    numPoints = G.numVertices;
    matrix = (float **) malloc(G.numVertices * sizeof(float *));
    for (i = 0; i < G.numVertices; i++) {
        matrix[i] = (float *) malloc(G.numVertices * sizeof(float));
        for (j = 0; j < G.numVertices; j++)
            matrix[i][j] = 9999;
    }

    for (i = 0; i < G.numVertices; i++) {
        for (j = 0; j < G.numVertices; j++) {
            if (G.matriz[i][j] != valorInicial) {
                matrix[i][j] = G.matriz[i][j];
                matrix[j][i] = G.matriz[i][j];
            }
        }
    }

    /* if(DEBUG)
    {
        PrintMatrix(matrix, numPoints);
        printf("=========================================================\n");
    }*/
    /* getting two points from user to find the distance between them */
    printf("Entre com dois vertices separando-os com espacos");
    scanf("%f%f", &pt1, &pt2);
    if (DEBUG)
        printf("Os vertices sao = %.2f - %.2f\n", pt1, pt2);

    /* calculate and display the minimum distance between pt1 and pt2 */
    printf("A menor distancia entre os vertices %.8f e %.8f eh %.8f\n",
           pt1, pt2, FindMinDistance(matrix, numPoints, pt1, pt2));
}

void greedy(TipoGrafo G) {
    int k, aux, i, j, n, alpha = 0, vetS[G.numVertices], conjuntoN = G.numVertices;
    Titem vertices[G.numVertices];
    n = G.numVertices;

    for (j = 0; j < G.numVertices; j++) {
        vertices[j].grau = 0;
        vertices[j].index = 0;
        vertices[j].marca = -1;
        vetS[j] = -1;
    }
    for (i = 0; i < G.numVertices; i++) {
        for (j = 0; j < G.numVertices; j++) {
            if (G.matriz[i][j] != valorInicial) {
                vertices[i].grau = vertices[i].grau++;
                vertices[i].index = i;
            }
        }
    }
    ordena(vertices, n);
    aux = 0;
    for (k = 0; k < G.numVertices; k++) {
        printf("\n Valor de n %d", n);
        if (vertices[aux].marca == -1) {
            vetS[vertices[aux].index] = aux;
            vertices[aux].marca = 0;
            for (i = 0; i < G.numVertices; i++) {
                if (G.matriz[aux][i] != valorInicial) {
                    vertices[i].marca = i;
                    printf("\n Vizinho %d", i);
                    n--;
                }
            }
            alpha++;
        }
        aux++;
    }

    for (i = 0; i < G.numVertices; i++) {
        if (vetS[i] != -1) { printf("\n item do conjunto%d", vetS[i] + 1); }

    }
    printf("\n Alpha %d", alpha);

    return;
}


void ordena(Titem *A, int n) {
    int i, j;
    int h = 1;
    Titem aux;

    do h = h * 3 + 1; while (h < n);
    do {
        h = h / 3;
        for (i = h; i < n; i++) {
            aux = A[i];
            j = i;
            while (A[j - h].grau < aux.grau) {
                A[j] = A[j - h];
                j -= h;
                if (j < h) break;
            }
            A[j] = aux;
        }
    } while (h != 1);
    return;
}

//EULERIANO

int verificarGrafoEhEuleriano(TipoGrafo *grafo) {
    int i, j;
    for (i = 1; i < grafo->numVertices; i++) {
        if (grau(*grafo, i) % 2 != 0)
            return 1; //n?o pode ser euleriano pois possui grau impar
    }
    return 0;
}

int dentroDeCiclo(int *ciclo, int vertice) {
    int enCiclo = false;

    int k = 0;

    while (ciclo[k] != FIN_CICLO && !enCiclo) {
        if (vertice == ciclo[k]) enCiclo = true;

        k++;
    }

    return enCiclo;
}

void mostrarCiclo(int *ciclo) {
    int i;
    for (i = 0; ciclo[i] != FIN_CICLO; i++) {
        printf(" %d ", ciclo[i] + 1);
    }

    printf("\n");
}

int *encontrarCiclo(TipoGrafo G, int vertice, int n) {
    int v, i, j, k;
    int *ciclo = malloc(sizeof(int[n * n + 1]));
    ciclo[0] = FIN_CICLO;

    v = vertice;

    i = 0;

    do {
        int j = 0;

        while (G.matrizAux[v][j] == 0 || dentroDeCiclo(ciclo, j)) {
            j++;

            while (j == n) {

                i--;

                if (i < 0) return NULL;

                else if (i == 0) {
                    v = vertice;
                } else {
                    v = ciclo[i - 1];
                }

                j = ciclo[i] + 1;

                ciclo[i] = FIN_CICLO;

                // mostrarCiclo(ciclo);
            }
        }

        v = j;

        ciclo[i] = v;

        ciclo[i + 1] = FIN_CICLO;

        i++;

        //mostrarCiclo(ciclo);

        if (i >= n * n) return NULL;

    } while (v != vertice || i <= 2);

    return ciclo;
}

void eliminarAristas(TipoGrafo G, int *ciclo) {
    int i;
    if (ciclo[0] == FIN_CICLO) return;

    i = 1;

    while (ciclo[i] != FIN_CICLO) {

        G.matrizAux[ciclo[i - 1]][ciclo[i]] = 0;
        G.matrizAux[ciclo[i]][ciclo[i - 1]] = 0;


        i++;
    }

    G.matrizAux[ciclo[i - 1]][ciclo[0]] = 0;
    G.matrizAux[ciclo[0]][ciclo[i - 1]] = 0;
}

int tieneAristas(TipoGrafo G, int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G.matrizAux[i][j] == 1) return true;

    return false;
}

void pegarCiclos(int *ciclo, int *subciclo, int posicion) {
    int i, tamano_ciclo, tamano_subciclo;

    for (i = 0; ciclo[i] != FIN_CICLO; i++);

    tamano_ciclo = i;

    for (i = 0; subciclo[i] != FIN_CICLO; i++);

    tamano_subciclo = i;

    int *ciclo_aux = malloc(sizeof(int[tamano_ciclo + tamano_subciclo + 1]));

    for (i = 0; i < posicion; i++)
        ciclo_aux[i] = ciclo[i];


    for (i = posicion; i < posicion + tamano_subciclo; i++)
        ciclo_aux[i] = subciclo[i - posicion];


    for (i = posicion + tamano_subciclo; i < tamano_ciclo + tamano_subciclo; i++)
        ciclo_aux[i] = ciclo[i - tamano_subciclo];


    for (i = 0; i < tamano_ciclo + tamano_subciclo; i++)
        ciclo[i] = ciclo_aux[i];

    ciclo[tamano_ciclo + tamano_subciclo] = FIN_CICLO;

    free(ciclo_aux);
}

int chamaEuler(TipoGrafo G) {

    //int **matriz = leerMatrizAdyacencia("matriz.txt");
    int vertInicial = 0;
    printf("Matriz de adjacencia inicial: \n");

    //mostrarMatrizAdyacencia( G.numVertices);

    int *ciclo = encontrarCiclo(G, vertInicial, G.numVertices);

    if (ciclo == NULL) {
        printf("Nao ha ciclo\n");

        return 0;
    }

    printf("Ciclo inicial: \n");

    mostrarCiclo(ciclo);

    eliminarAristas(G, ciclo);

    int i, *subciclo, *euleriano = ciclo;

    while (tieneAristas(G, G.numVertices)) {
        //printf( "matriz de adyacencia sin las aristas del ciclo euleriano: \n");

        // mostrarMatrizAdyacencia(G.numVertices);

        //printf("ciclo euleriano atual:\n");

        mostrarCiclo(euleriano);

        system("PAUSE");

        subciclo = NULL;

        i = 0;

        do {

            subciclo = encontrarCiclo(G, euleriano[i], G.numVertices);

            i++;

        } while (subciclo == NULL && euleriano[i] != FIN_CICLO);


        if (subciclo == NULL)
            printf("Nao existe subciclo");
        else {
            //printf("subciclo encontrado:\n");

            //mostrarCiclo(subciclo);

            pegarCiclos(euleriano, subciclo, i);

            //printf("inserindo subciclo na  posicao %d do ciclo euleriano:\n",i);

            //mostrarCiclo(euleriano);

            system("PAUSE");

            eliminarAristas(G, subciclo);
        }

    }


    printf("Ciclo euleriano final:\n");

    mostrarCiclo(euleriano);


    //destruirMatrizAdyacencia( G.numVertices);

    system("PAUSE");
    return EXIT_SUCCESS;
}

