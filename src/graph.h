#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Edge Edge;
struct Edge{
  void *head;
  void *tail;
  int weight;
};

typedef struct Graph Graph;
struct Graph{
  int SumV;
  int SumE;
  Edge *edge;
};

//void createGraph(Edge *edge,void *head,void *tail,int weight);
//void createGraph(Graph *graph,Edge *head,Edge *tail,int weight);
Graph* createGraph(int SumE, int SumV);
Graph* createVerticla(Graph* graph,void *head,void *tail,int weight,int edgeNum);
#endif // _GRAPH_H
