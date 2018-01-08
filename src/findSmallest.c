#include "findSmallest.h"
#include "Node.h"

Node *getSmallest(Node *nodePtr){
  if(nodePtr->left!=NULL){
    getSmallest(nodePtr->left);
  }
  else{
    return nodePtr;
}
}
