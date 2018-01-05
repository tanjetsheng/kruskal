#include "unity.h"
#include "graph.h"
#include "counting_sort.h"
#include <stdio.h>
#include <stdlib.h>

//Edge edge1,edge2;
void setUp(void)
{
}

void tearDown(void)
{
}

void test_Insert_Graph(void)
{
    Graph graph;
    createGraph(&graph,10,9);
    init(&graph);

    createVerticle(&graph,(int *)5,(int *)6,5,1);
    createVerticle(&graph,(int *)1,(int *)2,3,9);
    buildSorting(&graph);
    TEST_ASSERT_EQUAL(graph.edge[1].head,5);
    TEST_ASSERT_EQUAL(graph.edge[9].tail,2);



}
