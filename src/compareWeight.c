#include "compareWeight.h"


int WeightCompare(Graph *EdgeAvl,Graph *EdgeGraph)
{

  if (EdgeAvl->edge->weight < EdgeGraph->edge->weight)
  {
    return 1;
  }
  else if (EdgeAvl->edge->weight > EdgeGraph->edge->weight)
  {
    return -1;
  }
  else
    return 0;
}
