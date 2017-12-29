#include "unity.h"
#include "graph.h"
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

    createVerticla(&graph,(int *)5,(int *)6,5,1);
    createVerticla(&graph,(int *)5,(int *)7,4,2);
//    TEST_ASSERT_EQUAL_PTR(5,graph.edge[1].head);
/*    TEST_ASSERT_EQUAL_PTR(3,Edge[1].tail);
    TEST_ASSERT_EQUAL_PTR(5,Edge[1].weight);
    TEST_ASSERT_EQUAL_PTR(5,Edge[2].head);
    TEST_ASSERT_EQUAL_PTR(2,Edge[2].tail);
    TEST_ASSERT_EQUAL_PTR(3,Edge[2].weight);
*/

}
