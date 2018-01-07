#include "graph.h"
#include "stdio.h"
#include "counting_sort.h"

void init(Graph *graph){
  graph->edge=(Edge *)calloc(graph->SumE,sizeof(Edge));

}
Graph* createVerticle(Graph *graph,void *head,void *tail,int weight,int edgeNum){

  graph->edge[edgeNum].head = head;
  graph->edge[edgeNum].tail = tail;
  graph->edge[edgeNum].weight = weight;
  graph->edge[edgeNum].edgeNum = edgeNum;
  return graph;
}

Graph* createGraph(Graph *graph,int SumE, int SumV)
{

    graph->SumE = SumE;
    graph->SumV = SumV;
    return graph;
}

Graph* buildSorting(Graph *graph){
  int totalNum = graph->SumE;
  //int sorted[totalNum];
  //sorted=(Edge *) malloc(sizeof(edge));
  //for(int i=0;i<totalNum;i++){
  //  Graph* now = graph->edge[i];
    //sorted[i] =(graph->edge[i]);
    //printf("%d ,",sorted[i]);
//  }
  countingSort(graph->edge->weight,totalNum);

  return graph;
}
