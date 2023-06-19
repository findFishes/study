#include <iostream>
using namespace std;

typedef struct lNode
{
    char name;
    int data;
    lNode *next;
}lNnode,*linkList;

bool initList(linkList &L){
   L=(lNode*)malloc(sizeof(lNode));
   if (L==NULL)
        return false;
   L->next =NULL;
   return true;
}


bool listInsert(linkList &L,int i,int e){
   if (i<1){
      return false;
      }
   lNnode *P =NULL;
   int j=0;//j代表当前节点
   P = L;//P指向当前的头节点
   while (P!=NULL && j<i-1)
   {
     P=P->next;
     j++;
   }
   if (P==NULL){
      return false;
   }
   
   lNnode *S=(lNnode *)malloc(sizeof(lNnode));
   S->data=e;
   S->next=P->next;
   P->next=S;
   return true;
        
}

//链表删除节点
bool listDelete(linkList &L,int i,int &e){
    if(i<1)
        return false;
    lNnode *P=L;
    int j=0;
    while (P!=NULL && j<i-1)
    {
        P=P->next;
        j++;
    }
    if(P==NULL)
        return false;
    lNnode *Q=P->next;
    if(Q==NULL)
        return false;
    e=Q->data;
    P->next=Q->next;
    free(Q);
    return true;
    
}



lNnode* listFind1(linkList L,int i){ //按位查找
    if(i<1)
        return 0;
        
    int j=0;//当前p指向的第几个节点
           
    lNnode *P=L;//L指向头结点,头结点是低0个节点
    
    while (j<i)
    {
        
        P=P->next;
        j++;

    }
    return P;


    
}
 

 lNnode* listFind2(linkList L, int data) {
    lNnode *P = L->next;
    while (P != NULL && P->data != data) {
        P = P->next;
    }
    return P;
}



int main(){
    linkList L;
    initList (L);
    listInsert(L,1,5);
    listInsert(L,1,4);
    listInsert(L,1,3);
    listInsert(L,1,2);
    listInsert(L,1,1);
        lNnode *P=L;

    // for(int i=0;i<5;i++){

    // cout<<P->next->data<<endl;
    // P=P->next;

        

    // }

    cout<<listFind1(L,5)->data<<endl;
    cout<<listFind2(L,3)->data<<endl;
   //输出结果为2
    return 0;


}

