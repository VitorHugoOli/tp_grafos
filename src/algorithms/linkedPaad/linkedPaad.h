
#include "../../tads/LinkedGrafo/linkedGrafo.h"
#include "../../modules/paad/paad.h"

#ifndef TP_C_LINKEDPAAD_H
#define TP_C_LINKEDPAAD_H

int linkedToPaad(GrafoLinked *grafo, Paad *paad);

int PaadToLinked(GrafoLinked *grafo, Paad *paad, int isInitGraph);

#endif //TP_C_LINKEDPAAD_H
