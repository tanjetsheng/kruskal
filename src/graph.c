#include "graph.h"
#include "stdio.h"

void init(Graph *graph){
  graph->edge=(Edge *)calloc(graph->SumE,sizeof(Edge));

}
Graph* createEdge(Graph *graph,Vertex *head,Vertex *tail,int weight,int edgeNum){
  //EdgeNode node = graph->AvlNode;
  graph->edge[edgeNum].head = head;
  graph->edge[edgeNum].tail = tail;
  graph->edge[edgeNum].weight = weight;
  //printf("%d",graph->edge[i].weight);
  //createNode(,&graph);
  return graph;
}

Graph* createGraph(Graph *graph,int SumE, int SumV)
{
    graph->SumE = SumE;
    graph->SumV = SumV;
    init(graph);
    return graph;
}

void createNode(Node *AvlNode,Edge edges){
  Edge *edgesP=(Edge *)malloc(sizeof(Edge));
  *edgesP = edges;
  AvlNode->left = NULL;
  AvlNode->right = NULL;
  AvlNode->balanceFactor =0;
  AvlNode->data = edgesP;
  //return AvlNode;
}

void addingNode(Node **root,Graph *graph){

  int max = graph->SumE;
  for(int j=0;j<max;j++){
    Node *AvlNode = (Node *)malloc(sizeof(Node));
    createNode(AvlNode, graph->edge[j]);
    avlAddEdgeNode(root,AvlNode);
  }
}

Node *getSmallestRemove(Node **root){
  Node *shortest = getSmallest(&(*root));
  int smallestWeight = shortest->data->weight;
  avlRemoveEdgeNode(root,smallestWeight);
}

int WeightCompare(Edge *EdgeAvl,Node *EdgeGraph)
{
  int data = EdgeAvl->weight;
  int data1 = EdgeGraph->data->weight;
  if (data < data1)
  {
    return 1;
  }
  else if (data > data1)
  {
    return -1;
  }
  else
    return 0;
}

int WeightCompareRemove(int EdgeGraph,Node *EdgeAvl)
{
  int data = EdgeAvl->data->weight;
  if (data < EdgeGraph)
  {
    return -1;
  }
  else if (data > EdgeGraph)
  {
    return 1;
  }
  else
    return 0;
}

Edge convertNodeToEdge(Node *EdgeAvl){
  Edge edge;
  edge.head = EdgeAvl->data->head;
  edge.tail = EdgeAvl->data->tail;
  edge.weight = EdgeAvl->data->weight;
  return edge;
}


Graph kruskal(Graph *graph){
  int i=1;
  Graph MST;
  Node *node;
  addingNode(&node,&graph);
  int mainSub = graph->edge[0]->head->sub;
  graph->edge[0]->tail->sub =graph->edge[0]->head->sub;
  MST->edge[0]->head->sub = mainSub;
  MST->edge[0]->tail->sub = mainSub;
  MST->edge[0]->weight = graph->edge[0]->weight;
while(i<(graph->SumV-1)){
  Node *shorted = getSmallestRemove(&node);
  Edge SmallEdge = convertNodeToEdge(shorted);
    if()











}
    }
