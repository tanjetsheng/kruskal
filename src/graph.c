#include "graph.h"

void createGraph(Graph *graph,Edge *head,Edge *tail,int weight){
  graph->edge->head = head;
  graph->edge->tail = tail;
  graph->edge->weight = weight;
}
