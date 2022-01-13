#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "nodes.h"
#include <string.h>

pnode insert(int num1)
{
    pnode curr=(pnode)malloc(sizeof(node));
    curr->node_num=num1;
    return curr;
}
pedge createdge()
{
    pedge new=(pedge)malloc(sizeof(edge));
    return new;

}
char addEdge(pnode Nodelist,pnode Node)
{
    int dest;
    int w;
    char c;
    pedge prev;
    int i=0;
    scanf(" %c",&c);
    while (c>='0'&&c<='9')
    {

        pedge new=createdge();
        dest=(int)(c-'0');
        scanf(" %c",&c);
        w=(int)(c-'0');
        scanf(" %c",&c);

        new->endpoint=getNode(Nodelist,dest);
        new->weight=w;
        if(i!=0)
        {
            prev->next=new;

        }else
        {
           Node->edges=new;
        }
        prev=new;
        i++;
    }

    return c;
    
   return 'c';
}
pnode getNode(pnode NodeList,int id)
{
    pnode prev=NodeList;
    while (prev&&prev->node_num!=id)
    {
        prev=prev->next;
    }   
    return prev; 
}