#include "unity.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "addnode.h"
#include "rotate.h"
#include "findSmallest.h"
#include "noderemove.h"


Vertex s1,s2,s3,s4,s5,s6,s7,s8,s9;
void setUp(void)
{
  s1.sub =0;
  s2.sub =0;
  s3.sub =0;
  s4.sub =0;
  s5.sub =0;
  s6.sub =0;
  s7.sub =0;
  s8.sub =0;
  s9.sub =0;
}

void tearDown(void)
{
}

void test_Insert_Graph(void)
{
    Graph graph;
    createGraph(&graph,2,3);

    createEdge(&graph,&s1,&s2,5,0);
    createEdge(&graph,&s2,&s3,3,1);
    TEST_ASSERT_EQUAL(graph.edge[0].weight,5);
    TEST_ASSERT_EQUAL(graph.edge[1].weight,3);
}


void test_createing_node(void){
  Graph graph;
  Node *node = NULL;

  createGraph(&graph,2,3);

  createEdge(&graph,&s1,&s2,5,0);
  createEdge(&graph,&s2,&s3,3,1);
  addingNode(&node,&graph);

  TEST_ASSERT_EQUAL_PTR(node->right,NULL);
  TEST_ASSERT_NOT_NULL(node->left);
//  TEST_ASSERT_EQUAL_PTR(node.data,graph.edge);
}

void test_getting_smallest_value(void){
  Graph graph;
  Node *node = NULL;

  createGraph(&graph,5,4);

  createEdge(&graph,&s1,&s2,4,0);
  createEdge(&graph,&s2,&s4,5,1);
  createEdge(&graph,&s1,&s3,3,2);
  createEdge(&graph,&s3,&s4,2,3);
  createEdge(&graph,&s1,&s4,1,4);
  addingNode(&node,&graph);
  Node *shorted = getSmallest(node);
  TEST_ASSERT_EQUAL(1,shorted->data->weight);

}

void test_kruskal(void){
  Graph graph;
  Graph *MST;


  createGraph(&graph,5,4);

  createEdge(&graph,&s1,&s2,4,0);
  createEdge(&graph,&s2,&s4,5,1);
  createEdge(&graph,&s1,&s3,3,2);
  createEdge(&graph,&s3,&s4,2,3);
  createEdge(&graph,&s1,&s4,1,4);
  kruskal(&graph);
  //TEST_ASSERT_EQUAL(1,1);
//  printf("asd=%d",graph.edge->weight);

}
/*
void test_convertEdge(void){
  Graph graph;
  Node *node =NULL;
  createGraph(&graph,2,3);
  createEdge(&graph,&s1,&s2,4,0);
  createEdge(&graph,&s2,&s4,5,1);
  addingNode(&node,&graph);
  Node *shorted = getSmallestRemove(&node);
  Edge SmallEdge = convertNodeToEdge(shorted);
  TEST_ASSERT_EQUAL(4,SmallEdge.weight);
}*/
/*
void test_Insert_sorting(void)
{
    Graph graph;
    createGraph(&graph,5,4);
    init(&graph);

    createVerticle(&graph,&s1,&s2,4,0);
    createVerticle(&graph,&s2,&s4,5,1);
    createVerticle(&graph,&s1,&s3,3,2);
    createVerticle(&graph,&s3,&s4,2,3);
    createVerticle(&graph,&s1,&s4,1,4);
    //buildSorting(&graph);
    //kruskal(&graph);
    TEST_ASSERT_EQUAL(graph.edge[0].weight,1);
    TEST_ASSERT_EQUAL(graph.edge[1].weight,2);
    TEST_ASSERT_EQUAL(graph.edge[2].weight,3);
    TEST_ASSERT_EQUAL(graph.edge[3].weight,4);
    TEST_ASSERT_EQUAL(graph.edge[4].weight,5);
    TEST_ASSERT_EQUAL_PTR(graph.edge[0].head,&s1);

}*/
