#include "findSmallest.h"
#include "Node.h"


//rotating two node so that my remove function can remove the correct node
Node *getSmallest(Node *nodePtr){
  Node *temp = (Node *)malloc(sizeof(Node));
  Node *nodeLeft = nodePtr->left;
  if(nodePtr->left!=NULL){
    if(nodePtr->data->weight == nodeLeft->data->weight){
      temp->left = nodeLeft->left;
      temp->right = nodeLeft->right;
      temp->balanceFactor = nodeLeft->balanceFactor;
      temp->data = nodeLeft->data;

      nodePtr->left->right = nodePtr->right;
      nodePtr->left->balanceFactor = nodePtr->balanceFactor;
      nodePtr->left->data = nodePtr->data;

      nodePtr->right = temp->right;
      nodePtr->balanceFactor = temp->balanceFactor;
      nodePtr->data = temp->data;

      return nodePtr;
    }
    else{
        getSmallest(nodePtr->left);
    }
  }
  else{
    return nodePtr;
}
}
