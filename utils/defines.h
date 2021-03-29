//
// Created by vitor on 3/14/21.
//
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <wchar.h>
#include "../cjson/cJSON.h"

#define FIN_CICLO -1
#define false 0
#define true 1


#ifdef _WIN32
#define limpatela vsystem("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
#define limpatela system("clear");
#endif

#ifdef _WIN32
#define congela system("pause");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
#define congela system("read -p \"Pressione enter para sair\" saindo");
#endif


#define valorInicial 0
#define qtd 1000000
#define DEBUG 1/* 1 for print the matrixes,0 to hide */
#define debugFile "testes/pilot.txt"
#define debugPaad "testes/paad/depth.json"
#define basePaad "paad/base_json.json"

