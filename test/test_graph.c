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
  s1.sub =1;
  s2.sub =2;
  s3.sub =3;
  s4.sub =4;
  s5.sub =5;
  s6.sub =6;
  s7.sub =7;
  s8.sub =8;
  s9.sub =9;
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

void test_getsmallest_and_remove(void){
  Graph graph;
  Node *node = NULL;

  createGraph(&graph,5,4);

  createEdge(&graph,&s1,&s2,4,0);
  createEdge(&graph,&s2,&s4,5,1);
  createEdge(&graph,&s1,&s3,3,2);
  createEdge(&graph,&s3,&s4,2,3);
  createEdge(&graph,&s1,&s4,1,4);
  addingNode(&node,&graph);
  Node *shorted = getSmallestRemove(&node);
}
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
