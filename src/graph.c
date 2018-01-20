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
  Node *shortest = getSmallest(*root);
  int smallestWeight = shortest->data->weight;
  avlRemoveEdgeNode(root,smallestWeight);
  return shortest;
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

void combine(MST graph,int NumEdge,Edge edge){
  int sub1 = edge.head->sub;
  int sub2 = edge.tail->sub;
    for(int i = 0;i<=NumEdge;i++){
  if(sub1 > sub2){
    if((graph.mstEdge[i].head->sub || graph.mstEdge[i].tail->sub) == sub1){
      graph.mstEdge[i].head->sub = sub2;
      graph.mstEdge[i].tail->sub = sub2;
    }
  }
  else{
    if((graph.mstEdge[i].head->sub || graph.mstEdge[i].tail->sub) == sub2){
      graph.mstEdge[i].head->sub = sub1;
      graph.mstEdge[i].tail->sub = sub1;
    }
  }
}
//  return graph;
}

void print(MST graph,int NumEdge){
  for(int i =0;i<NumEdge;i++){
    int weight = graph.mstEdge[NumEdge].weight;
    printf("weight= %d  ",weight);
  }
}

MST kruskal(Graph *graph){
//  int GraphEdge=0;
  int MstEdge = 0;
  int subset =1;
  int totalMst = (graph->SumV-1);
  MST minimal;
  Node *node =NULL;
  addingNode(&node,graph);
  minimal.mstEdge=(Edge *)calloc(graph->SumV,sizeof(Edge));
  minimal.totalWeight =0;
while(MstEdge<totalMst){
  Node *shorted = getSmallestRemove(&node);
  Edge SmallEdge = convertNodeToEdge(shorted);
    if((SmallEdge.head->sub == SmallEdge.tail->sub)&& SmallEdge.head->sub !=0){

    }
    else{
      minimal.mstEdge[MstEdge] = SmallEdge;
      minimal.totalWeight = minimal.totalWeight + SmallEdge.weight;
      int headSub = SmallEdge.head->sub;
      int tailSub = SmallEdge.tail->sub;
      if((headSub ==0 && tailSub == 0)){
        SmallEdge.head->sub = subset;
        SmallEdge.tail->sub = subset;
        subset ++;
      }
      else if(SmallEdge.head->sub != 0 && SmallEdge.tail->sub == 0){
        SmallEdge.tail->sub = SmallEdge.head->sub;
      }
      else if(SmallEdge.head->sub == 0 && SmallEdge.tail->sub != 0){
        SmallEdge.head->sub = SmallEdge.tail->sub;
      }
      else{
          combine(minimal,MstEdge,SmallEdge);
      }
      printf("%s ----- %s ,weight=%d\n",SmallEdge.head->name,SmallEdge.tail->name,SmallEdge.weight);
  //  GraphEdge++;
    MstEdge++;
    }
}
//print(minimal,MstEdge);
printf("totalweight = %d \n",minimal.totalWeight);
  return minimal;
    }
