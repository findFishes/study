#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define initSize 10

typedef struct  
{
     int *data;
     int maxSize;
     int length;

    /* data */
}sqList;

void initList(sqList &L ){
L.data=(int *)malloc(initSize*sizeof(int));
L.length=0;
L.maxSize=initSize;

}
void increaseSize(sqList &L,int len){
    int *p=L.data;
    L.data=(int *)malloc((len+L.maxSize)*sizeof(int));
    for(int i =0;i<L.length;i++){
       L.data[i]=p[i];
    }
    L.maxSize=L.maxSize+len;
    free(p);

}
void listIncert(sqList &L,int i,int e){
    for(int a=L.length;a>i;a--){
       L.data[a]=L.data[a-1];
    }
    L.data[i-1]=e;
    L.length++;
}
bool listDelete( sqList &L,int i,int &e){
   if (i<1||i>L.length-1)//判断是否执行
   return false;
    e=-1;
    e=L.data[i-1];//删除的内容赋值给e
    for (int a=i;a<L.length;a++){
        L.data[a-1]=L.data[a];
    }
    L.length--;
    return true;
}

int main(){
   
   sqList L;
   int p;
   initList(L);
   increaseSize(L,5);
   increaseSize(L,5);
   listIncert(L,1,1);
   listIncert(L,1,2);
   listIncert(L,1,3);
   listIncert(L,1,4);
   listIncert(L,1,5);
   listIncert(L,1,6);
   listIncert(L,1,7);
   listDelete(L,1,p);
   std::cout<<L.data[1];
   std::cout<<"删除的是"<<p<<std::endl;




}