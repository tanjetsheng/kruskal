#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdint.h>

typedef struct Edge Edge;
struct Edge{
  Edge *head;
  Edge *tail;
  int weight;
};

typedef struct Graph Graph;
struct Graph{
  int SumEdge;
  int SumNode;
  Edge *edge;
};

void createGraph(Graph *graph,Edge *head,Edge *tail,int weight);
#endif // _GRAPH_H
