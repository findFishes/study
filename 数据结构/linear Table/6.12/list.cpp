#include <stdlib.h>
#include <iostream>
using namespace std;



typedef struct 
{
    int *data;
    int lenth;
    int maxSize;
    /* data */
}sqList;

void initList(sqList &L){
    L.data =0;
    L.lenth=0;
    L.maxSize=0;
}

void increaseSize(sqList &L,int size){
    int *p=L.data;
    L.data=(int *)malloc(sizeof(int)*(L.maxSize+size));
    for (int i=0;i<L.lenth;i++){
        L.data[i]=p[i];
    }
    L.maxSize=L.maxSize+size;
    free(p);
}

void insertList(sqList &L,int loc,int e){
      for(int i=L.maxSize;i>=loc;i--){
        L.data[i]=L.data[i-1];
      }
        L.data[loc-1]=e;
        L.lenth++;
}

void deletaList(sqList &L,int loc){
    int m=L.data[loc-1];
    for( int a=loc-1;a<L.lenth-1;a++){
        L.data[a]=L.data[a+1];
    }
    L.lenth--;
    cout<<"删除的是"<<m<<endl;
}
int listFind(sqList L,int e){
   for (int i=0;i<L.lenth;i++)
        if(L.data[i]==e)
             return 666;
    
}
int main(){
    sqList L;
    initList(L);
    increaseSize(L,5);
    insertList(L,1,5);
    insertList(L,1,4);
    insertList(L,1,3);
    insertList(L,1,2);
    insertList(L,1,1);
    for(int i=0;i<L.lenth;i++){
        cout<<"kaishi"<<endl;
         cout<<L.data[i]<<endl;
    };
    deletaList(L,3);
    for(int i=0;i<L.lenth;i++){
         cout<<L.data[i]<<endl;
    }
   
    cout<<listFind(L,2)<<endl;
     cout<<listFind(L,3)<<endl;
    

}