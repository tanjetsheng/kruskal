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
  int edgeNum;
};

typedef struct Graph Graph;
struct Graph{
  int SumV;
  int SumE;
  Edge *edge;
};

//void createGraph(Edge *edge,void *head,void *tail,int weight);
//void createGraph(Graph *graph,Edge *head,Edge *tail,int weight);
void init(Graph *graph);
Graph* createGraph(Graph *graph,int SumE, int SumV);
Graph* createVerticle(Graph *graph,void *head,void *tail,int weight,int edgeNum);
Graph* buildSorting(Graph *graph);

#endif // _GRAPH_H
