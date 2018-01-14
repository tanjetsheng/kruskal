#include "graph.h"
#include "stdio.h"


int i =0;

void init(Graph *graph){
  graph->edge=(Edge *)calloc(graph->SumE,sizeof(Edge));

}
Graph* createVerticle(Graph *graph,Vertex *head,Vertex *tail,int weight){
  //EdgeNode node = graph->AvlNode;
  graph->edge[i].head = head;
  graph->edge[i].tail = tail;
  graph->edge[i].weight = weight;
  //createNode(,&graph);
  i++;
  return graph;
}

Graph* createGraph(Graph *graph,int SumE, int SumV)
{
    graph->SumE = SumE;
    graph->SumV = SumV;
    init(graph);
    return graph;
}

EdgeNode* createNode(EdgeNode *AvlNode,Edge Edges){
  AvlNode->left = NULL;
  AvlNode->right = NULL;
  AvlNode->balanceFactor =0;
  AvlNode->data = Edges;
  return AvlNode;
}

int addingNode(EdgeNode *root,Graph *graph){
  EdgeNode *AvlNode;
  int max = graph->SumV;
  for(int j=0;j<max;j++){
    createNode(&AvlNode,graph->edge[j]);
    avlAddEdgeNode(&root,&AvlNode);
  }

}


int WeightCompare(int *EdgeAvl,EdgeNode *EdgeGraph)
{

  if (EdgeAvl < EdgeGraph->data.weight)
  {
    return 1;
  }
  else if (EdgeAvl > EdgeGraph->data.weight)
  {
    return -1;
  }
  else
    return 0;
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
