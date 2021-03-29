
#include "paad.h"


void initPaad(Paad *paad) {
    paad->file = (char *) malloc(255 * sizeof(char));
    paad->edgesLen = 0;
    paad->nodeLen = 0;
    paad->isPonderado = 0;
}

char *readPaadFiles(Paad *paad) {
    FILE *arquivo;
#if DEBUG
    arquivo = fopen(debugPaad, "rw");
    strcpy(paad->file,debugPaad);
#else
    printf("Entre com o nome do arquivo matrizPaad: ");
    char nomeArquivo[255];
    scanf("%s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "rw");
    strcpy(paad->file, nomeArquivo);
#endif

    if (arquivo == NULL) {
        printf("\n\tArquivo invalido tente novamente.\n\n");
        return NULL;
    }

    fseek(arquivo, 0, SEEK_END);
    long fsize = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);
    char *string = malloc(fsize + 1);

    fread(string, 1, fsize, arquivo);
    fclose(arquivo);

    string[fsize] = 0;


    return string;

}

int searchIndex(int value, Paad *paad) {
    for (int i = 0; i < paad->nodeLen; ++i) {
        if (paad->nodes[i] == value) {
            return i;
        }
    }
    return -1;
}

int paadRead(Paad *paad) {
    if (paad->edges == NULL) {
        free(paad->edges);
    }
    if (paad->nodes == NULL) {
        free(paad->nodes);
    }


    char *jsonStr = readPaadFiles(paad);
    if (jsonStr == NULL) {
        return 0;
    }

    cJSON *json = cJSON_Parse(jsonStr);
    cJSON *data = cJSON_GetObjectItem(json, "data");
    cJSON *nodes = cJSON_GetObjectItem(data, "nodes");
    cJSON *len = cJSON_GetObjectItem(nodes, "length");
    paad->nodeLen = len->valueint;
    int nodesLen = len->valueint;

    cJSON *datas = cJSON_GetObjectItem(nodes, "_data")->child;
    paad->nodes = (int *) malloc(nodesLen * sizeof(int));

    //use while to get next

    cJSON *item = datas;
    int count = 0;
    while (item != NULL) {
        cJSON *id = cJSON_GetObjectItem(item, "id");
        item = item->next;
        paad->nodes[count] = id->valueint;
        count++;
    }

    paad->isPonderado = cJSON_GetObjectItem(json, "ponderado")->valueint;

    cJSON *edges = cJSON_GetObjectItem(data, "edges");
    cJSON *edgesDatas = cJSON_GetObjectItem(edges, "_data")->child;
    cJSON *edgesItem = edgesDatas;


    int lenEdges = cJSON_GetObjectItem(edges, "length")->valueint;
    paad->edgesLen = lenEdges;
    paad->edges = (Edge *) malloc(lenEdges * sizeof(Edge));

    count = 0;
    while (edgesItem != NULL) {
        cJSON *from = cJSON_GetObjectItem(edgesItem, "from");
        cJSON *to = cJSON_GetObjectItem(edgesItem, "to");
        cJSON *weight = cJSON_GetObjectItem(edgesItem, "label");


        paad->edges[count].from = from->valueint;
        paad->edges[count].to = to->valueint;
        if (paad->isPonderado && weight != NULL) {
            paad->edges[count].weight = strtod(weight->valuestring, NULL);
        } else {
            paad->edges[count].weight = 1;
        }
        count++;
        edgesItem = edgesItem->next;
    }
    return 1;
}

int paadWrite(Paad *paad) {
    fflush(stdin);
    FILE *arquivo;
    arquivo = fopen(basePaad, "rw");

    if (arquivo == NULL) {
        fflush(stdout);
        printf("Não foi possivel ler o arquivo base ¯\\_(ツ)_/¯\n");
        return 0;
    }

    fseek(arquivo, 0, SEEK_END);
    long fsize = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);
    char *string = malloc(fsize + 1);


    fread(string, 1, fsize, arquivo);
    fclose(arquivo);

    string[fsize] = 0;

    cJSON *json = cJSON_Parse(string);
    cJSON *data = cJSON_GetObjectItem(json, "data");
    cJSON *nodes = cJSON_GetObjectItem(data, "nodes");
    cJSON *edges = cJSON_GetObjectItem(data, "edges");

    cJSON_AddBoolToObject(json, "ponderado", 1);
    cJSON_AddNumberToObject(nodes, "length", paad->nodeLen);
    cJSON_AddNumberToObject(edges, "length", paad->edgesLen);

    cJSON *nodesData = cJSON_GetObjectItem(nodes, "_data");
    cJSON *edgesData = cJSON_GetObjectItem(edges, "_data");

    for (int i = 1; i <= paad->nodeLen; ++i) {
        char result[10];
        sprintf(result, "%d", i);
        cJSON *content = cJSON_AddObjectToObject(nodesData, result);

        cJSON_AddNumberToObject(content, "id", i);
        cJSON_AddStringToObject(content, "label", result);
    }

    char result[10];
    char weight[10];
    for (int i = 0; i < paad->edgesLen; i++) {
        sprintf(result, "%d", i);
        cJSON *content = cJSON_AddObjectToObject(edgesData, result);


        cJSON_AddNumberToObject(content, "id", i);
        cJSON_AddNumberToObject(content, "from", paad->edges[i].from + 1);
        cJSON_AddNumberToObject(content, "to", paad->edges[i].to + 1);
        cJSON_AddObjectToObject(content, "color");
        sprintf(weight, "%.2lf", paad->edges[i].weight);
        cJSON_AddStringToObject(content, "label", weight);
    }


    arquivo = fopen("paad.json", "w");
    char *stringg = cJSON_Print(json);
    fprintf(arquivo, "%s", stringg);
    fclose(arquivo);

    printf("Arquivo\033[1m paad.json\033[0m, criado com sucesso ＼(＾O＾)／\n");
    fflush(stdout);


    return 1;
}



