#include <iostream>


typedef struct Lnode
{int data;
struct Lnode *next;
}lNnode,*linkList;

bool listDelete(linkList &L,int i,int data){
    if (i<1){return false;}
    lNnode *p;
    int j=0;
    p=L;
    while (p!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if (p=NULL){
        return false;
    }
    Lnode *q=p->next;
    p->next=q->next;
    free(q);
    return true;
}
