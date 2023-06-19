#include <iostream>


typedef struct Lnode
{int data;
struct Lnode *next;
}lNnode,*linkList;


bool initList(linkList &L){
   L=(Lnode*)malloc(sizeof(Lnode));
   if (L=NULL)
        return false;
   L->next =NULL;
   return true;
}

bool listInsert(linkList &L,int i,int e){
   if (i<1){
      return false;}
   lNnode *P =NULL;
   int j=0;//j代表当前节点
   P = L;//P指向当前的头节点
   while (P!=NULL && j<i-1)
   {
     P=P->next;
     j++;
   }
   if (P=NULL){
      return false;
   }
   
   lNnode *S=(lNnode *)malloc(sizeof(lNnode));
   S->data=e;
   S->next=P->next;
   P->next=S;
   return true;

}


bool listIncert2(linkList &L,int i, int e){
   if(i<1){
      return false;
   }
   if(i==1){
      Lnode *S=(Lnode*)malloc(sizeof(Lnode));
      S->data=e;
      S->next=L;
      L=S;
      return true;   

   }
   lNnode *P=NULL;
   P=L;
   int j=1;
   while (P!=NULL&&j<i-1)
   {
      P=P->next;
   
      j++;
      
   }
   if (P=NULL){
      return false;
   }
   
   lNnode *S=(lNnode *)malloc(sizeof(lNnode));
   S->data=e;
   S->next=P->next;
   P->next=S;
   return true;
}
//指定节点后的插入
bool insertNextNode(lNnode *P,int e){
   Lnode *S=(Lnode *)malloc(sizeof(Lnode));
   if(P=NULL){
      return false;
   }
   S->data=e;
   P->next=S;
   return true;

}
//指定节点前插入元素e
bool insertBeforeNode(Lnode *p,int e){
   if(p=NULL){return false;}
   Lnode *S=(Lnode *)malloc(sizeof(Lnode));
   S=p;
   p->data=e;
   p->next=S;
   return true;

}
bool listDelete(Lnode &L,int i,int e){
   if(i<1){
      return false;
   }
   Lnode *P=&L;
   int j=1;
   while (j<i)
   {
      P=P->next;
      j++;
   }
   Lnode *q=P->next;
   e=q->data;
   P->next=q->next;
   free(P);
   return true;


}
int main(){
   printf("helloworld");
   return 0;
}


