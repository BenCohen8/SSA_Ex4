#ifndef AGLO_
#define ALGO_
#include "graph.h"

pnode A(pnode,int);
char B(pnode,int);
int D(pnode);
int S(pnode,int,int);
int T(pnode);
pSP getDJ(pSP,int,int,int,int);
pSP getMinDJ(pSP,int);
pSP RemoveND(pSP,int,int);
int calculateTSP(int[][6],int[],int,int,int,int,int);
pSP addpSp();
#endif