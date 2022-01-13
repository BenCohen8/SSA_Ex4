#include "graph.h"
#include "algo.h"
#include "nodes.h"
#include "edges.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

pnode A(pnode NodeList,int size)
{


    pnode prev;
    pnode curr;
    for (int i = 0; i < size-1; i++)
    {
        if (i==0)
        {
            NodeList=insert(i);
            curr=insert(i+1);
            NodeList->next=curr;
            curr->next=NULL;
            prev=NodeList;

        }else
        {
            prev=curr;
            curr=insert(i+1);
            prev->next=curr;
            prev=curr;
        }
    }
    return NodeList;

}
char B(pnode NodeList,int size)
{
    int src=2;
    pnode prev=NodeList;
    pnode curr=NodeList;
    pnode new;
    scanf(" %d",&src);
    //curr=NodeList->next->next->next;
    int i=0;
    while (curr->node_num!=src&&i<size-1)
    {
     prev=curr;
        curr=curr->next;
        i++;
    }
    if (curr->node_num==src)
    {
        pnode temp =curr->next;
        free(curr);
        pnode curr1=(pnode)malloc(sizeof(node));
        prev->next=curr1;
        curr1->next=temp;
        addEdge(NodeList,curr1);
    }else
    {
        new=insert(src);
        curr->next=new;
        new->next=NULL;
        addEdge(NodeList,new);
    }
    return 0;
}
int D(pnode Nodelist)
{
    int src;
    scanf(" %d",&src);
    pnode prev;
    pnode curr=Nodelist;
    
    if (Nodelist->node_num==src)
    {
        Nodelist=Nodelist->next;

    }else
    { 
        while (curr->node_num!=src)
        {
            prev=curr;
            curr=curr->next;
        }
        if (curr->node_num==src)
        {
            prev->next=curr->next;
            free(curr);
        }
    }
    curr=Nodelist;
    while (curr->next)
    {
        remove_edge(curr,src);
        curr=curr->next;
    }
    
    
    return 0; 
}
pSP addpSp()
{
    pSP new=(pSP)malloc(sizeof(SP));
    return new;
}
int S(pnode Nodelist,int src,int dest)
{
    if(src==dest){
        return 0;
    }
    int i=0;
    pnode curr=Nodelist->next;
    pSP Head=(pSP)malloc(sizeof(SP));
    pSP prev=Head;
    pSP currs;
    while (curr)
    {
        i++;
        currs=addpSp();
        currs->node_num=curr->node_num;
        currs->next=NULL;
        if (currs==NULL)
        {
            break;
        }
        prev->next=currs;
        prev=currs;
        i++;
        curr=curr->next;
    }
    
        curr=Nodelist;
    pSP t=Head;
    pSP curr1;

    while(t)
    {

       if (t->node_num!=src)
       {

        t->dist=__INT_MAX__;
        t->node_num=curr->node_num;

       }else
       {
            t->dist=0;
            t->node_num=curr->node_num;
            curr1=t;    
       }
        curr=curr->next;
        t=t->next;  
    }    
    curr=Nodelist;

    while (i&&curr1->node_num!=dest)
    {

        //printf("%d",i);


        curr1=getMinDJ(Head,i); 
        if (curr1->dist==__INT_MAX__)
        {
            return -1;
        }
        

       curr=getNode(Nodelist,curr1->node_num);


            pedge e=curr->  edges;
            while (e)
            {

                int w1=e->weight;
                pnode dest=e->endpoint;

                Head=getDJ(Head,dest->node_num,i,w1,curr1->dist);
                e=e->next;
            }
        pSP t=Head;
        pSP prev;
    if (Head){
    if (t->node_num==curr1->node_num)
    {
       Head=Head->next;
    }else
    {
        while (t&&t->node_num!=curr1->node_num)
        {
            prev=t;
            t=t->next;
        
    }
        if(t)
        {
        prev->next=t->next;
        }
    }
    }

        //free(t);

         //RemoveND(Head,curr1->node_num,i);
         
         i--;
         
    }   
        while(Head)
    {
        pSP t=Head->next;
        free(Head);
        Head=t;
    }
    return curr1->dist;
}
int T(pnode NodeList)
{

    int temp=-1;
    char c;
    scanf(" %c",&c);
    int len=(int)(c-'0');
    int* TSP=(int*)malloc(len*sizeof(int));



    for (int i = 0; i < len; i++)
    {
        scanf(" %c",&c);
        TSP[i]=(int)(c-'0');
    }
            scanf(" %c",&c);



    int mat[len][len];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
                        mat[i][j]=S(NodeList,TSP[i],TSP[j]);
                        if (mat[i][j]==0&&i!=j)
                        {
                            mat[i][j]=-1;
                        }
        }        
    }
    int min=__INT_MAX__;
    for (int i = 0; i < len; i++)
    {
        int vis[len];
        for (int k = 0; k < len; k++)
        {
            vis[k]=0;
        }
        vis[i]=1;
        int sum=__INT_MAX__;
        temp =calculateTSP(mat,vis,0,len,1,0,sum);
        if (temp<min)
        {
            min=temp;
        }   
    }
    free(TSP);
    if (temp==__INT_MAX__)
    {
        temp=-1;
    }
    
    printf("TSP shortest path: %d\n",min);
    return c;    
}
int calculateTSP(int mat[][6],int vis[],int currpos,int n,int count,int cost,int ans )
{

    if (count == n -1&& mat[currpos][0] > 0)
    {

        if (cost<ans)
        {
            ans=cost;

        }
        return ans;
    }
    for (int i = 0; i < n; i++)
    {

        if (vis[i] == 0 && mat[currpos][i] > 0)
        {  


            vis[i] = 1;
            ans = calculateTSP(mat, vis, i, n, count+1,cost + mat[currpos][i], ans);
            vis[i] = 0;
        }
    }
    return ans;
}   
pSP getDJ(pSP dj,int num_id,int size,int w,int distw)
{
    pSP curr=dj;
    while (curr&&curr->node_num!=num_id)
    {
        curr=curr->next;
    }
    if (curr&&w+distw<curr->dist)
    {
        curr->dist=w+distw;

    }

    
    return dj;
}
pSP getMinDJ(pSP s,int size)
{
    pSP t=s;
    pSP ret;
    int min=__INT_MAX__;
    while (t)
    {

        if (t->dist<min)
        {

            min=t->dist;
            ret=t;
        }
        t=t->next;
    }

    return ret;
}
pSP RemoveND(pSP s,int cur,int size)
{
    pSP t=s;
    pSP prev;
    while (t->node_num!=cur)
    {
        prev=t;
        t=t->next;
        
    }
        prev->next=t->next;
        free(t);
    
    return s;  
}

