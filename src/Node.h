#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>

typedef struct Vertex Vertex;
struct Vertex{
  int sub;
};

typedef struct Edge Edge;
struct Edge{
  Vertex *head;
  Vertex *tail;
  int weight;
};

typedef struct Node Node;
struct Node {
  Node *left;
  Node *right;
  int balanceFactor;
  Edge *data;
};

typedef struct StringNode StringNode;
struct StringNode {
  StringNode *left;
  StringNode *right;
  int balanceFactor;
  char *data;
};



#endif // _NODE_H
