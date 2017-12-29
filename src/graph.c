#include "graph.h"

/*void createGraph(Edge *edge,void *head,void *tail,int weight){
  edge->head = head;
  edge->tail = tail;
  edge->weight = weight;
}*/

/*void createGraph(Graph *graph,void *head,void *tail,int weight){
  graph->edge->head = head;
  graph->edge->tail = tail;
  graph->edge->weight = weight;
}*/

Graph* createVerticla(Graph* graph,void *head,void *tail,int weight,int edgeNum){
  graph->edge[edgeNum].head = head;
  graph->edge[edgeNum].tail = tail;
  graph->edge[edgeNum].weight = weight;
}

Graph* createGraph(int SumE, int SumV)
{
    Graph* graph;
    graph->SumE = SumE;
    graph->SumV = SumV;
  //  graph->edge = malloc(sizeof(Edge[SumE]));
  //  free(graph->edge);
    return graph;
}
