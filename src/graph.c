#include "graph.h"
#include "stdio.h"




void init(Graph *graph){
  graph->edge=(Edge *)calloc(graph->SumE,sizeof(Edge));

}
Graph* createVerticle(Graph *graph,Vertex *head,Vertex *tail,int weight){
  graph->edge->head = head;
  graph->edge->tail = tail;
  graph->edge->weight = weight;
  return graph;
}

Graph* createGraph(Graph *graph,int SumE, int SumV)
{

    graph->SumE = SumE;
    graph->SumV = SumV;
    return graph;
}

void createNode(Node *AvlNode,Graph *EdgeNode){
  AvlNode->left = NULL;
  AvlNode->right = NULL;
  AvlNode->balanceFactor =0;
  AvlNode->data = EdgeNode->edge;
}

/*
void kruskal(Graph *graph){
  int orig=1;
  int set=0;
  Graph sub;
  sub.edge[0].head = graph->edge[0].head;
  sub.edge[0].tail = graph->edge[0].tail;
  sub.edge[0].weight = graph->edge[0].weight;
  sub.edge[0].tail->sub = graph->edge[0].head->sub;
  while(now<=((graph->SumV)-1)){
    if(sub.edge[set].head->sub != graph->edge[next].head->sub ){
      if(sub.edge[set].head->sub != graph->edge[next].tail->sub ){
        sub.edge[next].head = graph->edge[next].head;
        sub.edge[next].tail = graph->edge[next].tail;
        sub.edge[next].weight = graph->edge[next].weight;
        graph->edge[].head->sub = sub.edge[].head->sub;
        graph->edge[].tail->sub = sub.edge[].tail->sub;
    }
  }
}
*/
