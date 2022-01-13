#include <stdio.h>
#include "graph.h"
#include "algo.h"
#include "nodes.h"
#include "edges.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main()
{
    pnode NodeList;
    char c='c';
    int size;
        scanf(" %c",&c);

    while (c!=EOF)    
    {
        if(c=='A')
        {
            scanf(" %d",&size);
            NodeList=A(NodeList,size);
            scanf(" %c",&c);

        }
        if(c=='B')
        {
            
            B(NodeList,size);
            //    scanf("%c",&c);
           // free(NodeList);
        }
        if (c=='D')
        {
            D(NodeList);
            scanf(" %c",&c);
        }
        if (c=='S')
        {
            char c1,c2;
            int src,dest;
            scanf(" %c %c",&c1,&c2);
            src=(int)(c1-'0');
            dest=(int)(c2-'0');
            int x=S(NodeList,src,dest);
                printf("Dijsktra shortest path: %d\n",x); 

            scanf(" %c",&c);
        }
        if (c=='T')
        {
           c=T(NodeList);
            }
        if(c=='n')
        {
            char c1;
            int src;
            scanf(" %c",&c1);
            src=(int)(c1-'0');

            pnode t=NodeList;
            int i=0;
            while (t->node_num!=src&&i<size-1)
            {
                t=t->next;
                i++;
            }
            
            c=addEdge(NodeList,t);
        }
    }
    
}