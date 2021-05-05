//
// Created by vitor on 3/14/21.
//
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <wchar.h>
#include <stdio.h>
#include <math.h>
#include "time.h"
#include <unistd.h>
#include <pthread.h>
#include "modules/cjson/cJSON.h"


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
#define DEBUG 1 /* 1 for print the matrixes,0 to hide */

#include "time.h"

#define file_macro "testes/TCP/ch130.tsp"
//#define file_macro "testes/TCP/berlin52.tsp"
#define paad_macro "testes/paad/complet_pdf_aula.json"
#define macroBasePaad "src/modules/paad/base_json.json"


#define terminal 1
#if !terminal //clion case

#define debugFile "../" file_macro
#define debugPaad "../" paad_macro
#define basePaad "../" macroBasePaad

#else //normal terminal case

#define debugFile file_macro
#define debugPaad paad_macro
#define basePaad macroBasePaad

#endif
