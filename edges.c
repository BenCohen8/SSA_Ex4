#include <stdio.h>
#include <stdlib.h>
#include "edges.h"

int remove_edge(pnode N,int id)
{
  if(N->edges&&N->edges->endpoint->node_num!=id)
  {
      pedge prev;
      pedge curr=N->edges;
      while (curr&&curr->endpoint->node_num!=id)
      {
        prev=curr;
        curr=curr->next;
      }
      if (curr->endpoint->node_num==id)
      {
        prev->next=curr->next;
        free(curr);
      }
      
  }else if(N->edges)
  {
    pedge t=N->edges;
    N->edges=N->edges->next;
    free(t);
  }
  return 0;
}
edge get_edge(pedge ed, int id)
{
  pedge curr;
  if(ed[0].endpoint->node_num==id)
  {
    return ed[0];
  }else
  {
    pedge prev=ed;
    curr=prev->next;
    while (curr->endpoint->node_num!=id||curr->endpoint!=NULL)
    {
      prev=curr;
      curr=curr->next;
    }
    if(curr->endpoint->node_num==id)
    {
      return curr[0];
    }
    
  }
  return curr[0];
}