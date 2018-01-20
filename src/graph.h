#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "addnode.h"
#include "noderemove.h"
#include "avlint.h"
#include "findSmallest.h"
#include "Node.h"


typedef struct MST MST;
struct MST{
  int totalWeight;
  Edge *mstEdge;
};

typedef struct Graph Graph;
struct Graph{
  int SumV;
  int SumE;
  Edge *edge;
};


#define avlRemoveEdgeNode(rootPtr,nodeToRemove) RemoveNode(rootPtr,nodeToRemove,(CompareWeight)WeightCompareRemove)
#define avlAddEdgeNode(nodePtr,newNode)  addNode(nodePtr,newNode,(Compare)WeightCompare)

void init(Graph *graph);
Graph* createGraph(Graph *graph,int SumE, int SumV);
Graph* createEdge(Graph *graph,Vertex *head,Vertex *tail,int weight,int edgeNum);
void createNode(Node *AvlNode,Edge edges);
void addingNode(Node **root,Graph *graph);
Node *getSmallestRemove(Node **root);
Edge convertNodeToEdge(Node *EdgeAvl);
void combine(MST graph,int NumEdge,Edge edge);
MST kruskal(Graph *graph);
int WeightCompare(Edge *EdgeAvl,Node *EdgeGraph);
int WeightCompareRemove(int EdgeGraph,Node *EdgeAvl);
void print(MST graph,int NumEdge);


#endif // _GRAPH_H
