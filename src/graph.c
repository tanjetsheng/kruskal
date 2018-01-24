#include "graph.h"
#include "stdio.h"
//create a memory to create edge;
void init(Graph *graph){
  graph->edge=(Edge *)calloc(graph->SumE,sizeof(Edge));
}

//use to create edge with different head tail and weight
Graph* createEdge(Graph *graph,Vertex *head,Vertex *tail,int weight,int edgeNum){
  graph->edge[edgeNum].head = head;
  graph->edge[edgeNum].tail = tail;
  graph->edge[edgeNum].weight = weight;
  return graph;
}

//use to determine the total number of edge and verticle to know that need create how many space
Graph* createGraph(Graph *graph,int SumE, int SumV)
{
    graph->SumE = SumE;
    graph->SumV = SumV;
    init(graph);
    return graph;
}

//create avl node to insert into avl tree for sorting
void createNode(Node *AvlNode,Edge edges){
  Edge *edgesP=(Edge *)malloc(sizeof(Edge));
  *edgesP = edges;
  AvlNode->left = NULL;
  AvlNode->right = NULL;
  AvlNode->balanceFactor =0;
  AvlNode->data = edgesP;
  //return AvlNode;
}

//adding node into avl tree from all the edge of graph
void addingNode(Node **root,Graph *graph){

  int max = graph->SumE;
  for(int j=0;j<max;j++){
    Node *AvlNode = (Node *)malloc(sizeof(Node));
    createNode(AvlNode, graph->edge[j]);
    avlAddEdgeNode(root,AvlNode);
  }
}

//use to get the smallst value in to avl tree and remove the node
Node *getSmallestRemove(Node **root){
  Node *shortest = getSmallest(*root);
  int smallestWeight = shortest->data->weight;
  avlRemoveEdgeNode(root,smallestWeight);
  return shortest;
}

//compare function for edge weight for adding in avl
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

//compare function for edge weight in avl for remove
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

//get the data value in the avl node and convert it back to edge form
Edge convertNodeToEdge(Node *EdgeAvl){
  Edge edge;
  edge.head = EdgeAvl->data->head;
  edge.tail = EdgeAvl->data->tail;
  edge.weight = EdgeAvl->data->weight;
  return edge;
}

//combining two sub set into one test_kruskal_with_two_subset
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

}

void print(MST graph,int NumEdge){
  for(int i =0;i<NumEdge;i++){
    int weight = graph.mstEdge[NumEdge].weight;
    printf("weight= %d  ",weight);
  }
}

//main function for kruskal
MST kruskal(Graph *graph){

  int MstEdge = 0;
  int subset =1;
  int totalMst = (graph->SumV-1);
  MST minimal;
  Node *node =NULL;
  addingNode(&node,graph);          //convert edge in the graph into avl node and add them into avl tree
                                    //avl tree has done all the sorting from smallest to largest
  minimal.mstEdge=(Edge *)calloc(graph->SumV,sizeof(Edge));
  minimal.totalWeight =0;
while(MstEdge<totalMst){
  Node *shorted = getSmallestRemove(&node);   //get the smallest value in the avl node
  Edge SmallEdge = convertNodeToEdge(shorted);    //then covert back to edge type
    if((SmallEdge.head->sub == SmallEdge.tail->sub)&& SmallEdge.head->sub !=0){
        //check the edge head and tail sub that it will not have same sub
        //so that it will not have a loop
    }
    else{
      minimal.mstEdge[MstEdge] = SmallEdge;       //put into a minimal spannong tree graph
      minimal.totalWeight = minimal.totalWeight + SmallEdge.weight;
      int headSub = SmallEdge.head->sub;
      int tailSub = SmallEdge.tail->sub;
      if((headSub ==0 && tailSub == 0)){      //when put in the minimal spanning tree, it will
        SmallEdge.head->sub = subset;         //become a subset
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
          combine(minimal,MstEdge,SmallEdge);       //use to combine two subset when it
                                                    //detect two subset need to combine
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
