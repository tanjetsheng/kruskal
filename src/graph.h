#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Node.h"


typedef struct Vertex Vertex;
struct Vertex{
  int sub;
};

typedef struct Edge Edge;
struct Edge{
  Vertex *head;
  Vertex *tail;
  int weight;
};

typedef struct Graph Graph;
struct Graph{
  int SumV;
  int SumE;
//  Node *graphNode;
  Edge *edge;
};


void init(Graph *graph);
Graph* createGraph(Graph *graph,int SumE, int SumV);
Graph* createVerticle(Graph *graph,Vertex *head,Vertex *tail,int weight);
void createNode(Node *AvlNode,Graph *EdgeNode);

//void kruskal(Graph *graph);

#endif // _GRAPH_H
