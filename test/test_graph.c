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
  s1.name ="s1";
  s2.name ="s2";
  s3.name ="s3";
  s4.name ="s4";
  s5.name ="s5";
  s6.name ="s6";
  s7.name ="s7";
  s8.name ="s8";
  s9.name ="s9";
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
}

/*     s1 ---4----s2              s1 ---4----  s2
       |  \        |                   \
       3    1      5       -->           1
       |      \   |                       \
      s3---2----s4               s3 ---2--- s4

*/
void test_kruskal(void){
  Graph graph;
  MST mst;

  createGraph(&graph,5,4);
  createEdge(&graph,&s1,&s2,4,0);
  createEdge(&graph,&s2,&s4,5,1);
  createEdge(&graph,&s1,&s3,3,2);
  createEdge(&graph,&s3,&s4,2,3);
  createEdge(&graph,&s1,&s4,1,4);
  mst = kruskal(&graph);
  TEST_ASSERT_EQUAL(mst.totalWeight,7);

}


/*    s1----7----s2                s1          s2
      |           |                |           |
      1           2                1           2
      |           |                |           |
      s3----5----s4     -->        s3----5----s4
      |           |                |           |
      3           4                3           4
      |           |                |           |
      s5----6----s6                s5          s6

*/


void test_kruskal_with_two_subset(void){
  Graph graph;
  MST mst;

  createGraph(&graph,7,6);
  createEdge(&graph,&s1,&s2,7,0);
  createEdge(&graph,&s1,&s3,1,1);
  createEdge(&graph,&s2,&s4,2,2);
  createEdge(&graph,&s3,&s4,5,3);
  createEdge(&graph,&s3,&s5,3,4);
  createEdge(&graph,&s4,&s6,4,5);
  createEdge(&graph,&s5,&s6,6,6);
  mst = kruskal(&graph);
  TEST_ASSERT_EQUAL(mst.totalWeight,15);
}


void test_two_same_value_node(void){
  Graph graph;
  MST mst;

  createGraph(&graph,5,4);
  createEdge(&graph,&s1,&s2,1,0);
  createEdge(&graph,&s2,&s4,2,1);
  createEdge(&graph,&s1,&s3,5,2);
  createEdge(&graph,&s3,&s4,1,3);
  createEdge(&graph,&s1,&s4,3,4);
  mst = kruskal(&graph);
  TEST_ASSERT_EQUAL(mst.totalWeight,4);
}
