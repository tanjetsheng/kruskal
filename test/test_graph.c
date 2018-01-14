#include "unity.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "addnode.h"
#include "rotate.h"
#include "compareWeight.h"

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
    createGraph(&graph,4,5);

    createVerticle(&graph,&s1,&s2,5);
    createVerticle(&graph,&s2,&s3,3);
    TEST_ASSERT_EQUAL(graph.edge[0].weight,5);
    TEST_ASSERT_EQUAL(graph.edge[1].weight,3);
}


void test_createing_node(void){
  Graph graph;
  EdgeNode *node = NULL;

  createGraph(&graph,2,1);

  createVerticle(&graph,&s1,&s2,5);
  addingNode(&node,&graph);
  //createNode(&node,&graph);


  //TEST_ASSERT_EQUAL_PTR(node[0].left,NULL);
//  TEST_ASSERT_EQUAL_PTR(node.data,graph.edge);
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
