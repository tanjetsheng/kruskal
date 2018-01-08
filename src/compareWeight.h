#ifndef _COMPAREWEIGHT_H
#define _COMPAREWEIGHT_H
#include "graph.h"

typedef int (*Compare)(void *EdgeAvl,void *EdgeGraph);

int WeightCompare(Graph *EdgeAvl,Graph *EdgeGraph);
#endif // _COMPAREWEIGHT_H
