#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Node.h"
#include "addnode.h"
#include "compareWeight.h"
#include "avlint.h"
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

typedef struct EdgeNode EdgeNode;
struct EdgeNode {
  Node *left;
  Node *right;
  int balanceFactor;
  Edge data;
};


typedef struct Graph Graph;
struct Graph{
  int SumV;
  int SumE;
//  EdgeNode AvlNode;
  Edge *edge;
};



#define avlAddEdgeNode(nodePtr,newNode)  addNode(nodePtr,newNode,(Compare)WeightCompare)

void init(Graph *graph);
Graph* createGraph(Graph *graph,int SumE, int SumV);
Graph* createVerticle(Graph *graph,Vertex *head,Vertex *tail,int weight);
EdgeNode* createNode(EdgeNode *AvlNode,Edge Edges);
int addingNode(EdgeNode *root,Graph *graph);
int WeightCompare(int *EdgeAvl,EdgeNode *EdgeGraph);

//void kruskal(Graph *graph);

#endif // _GRAPH_H
