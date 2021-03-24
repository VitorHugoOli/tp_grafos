//
// Created by vitor on 3/20/21.
//
#include "conexo.h"

//COMPONENTE CONEXA

/*
 * encontraComponenteConexo(ECC)
 *
 * Acha todos os componentes conexos e seus respectivos vertices
 * */
int ECC(GrafoMatriz G, int *groupConexoVertice) {
    int numGrupoConexo = 0;

    //Inicializa o vetor groupConexoVertice
    for (int i = 0; i < G.numVertices; i++)
        groupConexoVertice[i] = -1;

    //Percorrer todos os vertices do grafo
    for (int vertice = 0; vertice < G.numVertices; vertice++)
        //Entra nos vertices que tem valores igual a -1
        if (groupConexoVertice[vertice] == -1)
            PCC(G, vertice, numGrupoConexo++, groupConexoVertice);
    return numGrupoConexo;
}


/*
 *  percorreComponenteConexo(PCC)
 *
 *  Dado um verticeAnalise, percorre todos os outros vertices do mesmo
 *  grupo conexo a ele.
 * */
void PCC(GrafoMatriz G, int verticeAnalise, int numGrupoConexo, int *groupConexoVertice) {

    //Atribuindo no index que representa o verticeAnalise o seu grupo conexo
    groupConexoVertice[verticeAnalise] = numGrupoConexo;

    //Percorrer todos os vertices do grafo
    for (int verticesComparado = 0; verticesComparado < G.numVertices; verticesComparado++)
        //SE o verticeAnalise e o verticeConexo possui aresta E o vertice conexo nao tiver sido visitado, ENTRA NO IF
        if (G.matriz[verticeAnalise][verticesComparado] != valorInicial && groupConexoVertice[verticesComparado] == -1)

            PCC(G, verticesComparado, numGrupoConexo, groupConexoVertice);
}