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

#define berlin52_base "testes/TCP/berlin52.tsp"
#define ch130_base "testes/TCP/ch130.tsp"
#define d198_base "testes/TCP/d198.tsp"


#define file_macro berlin52
#define paad_macro "testes/paad/cheaperinsertion.json"
#define macroBasePaad "src/modules/paad/base_json.json"


#define terminal 0
#if !terminal //clion case

#define debugFile "../" file_macro
#define debugPaad "../" paad_macro
#define basePaad "../" macroBasePaad

#define berlin52 "../" berlin52_base
#define ch130 "../" ch130_base
#define d198 "../" d198_base

#else //normal terminal case

#define debugFile file_macro
#define debugPaad paad_macro
#define basePaad macroBasePaad

#define berlin52 berlin52_base
#define ch130 ch130_base
#define d198 d198_base

#endif
