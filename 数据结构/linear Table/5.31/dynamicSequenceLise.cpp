#include <stdio.h>
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


int main(){
   
   sqList L;
   initList(L);
   
   increaseSize(L,5);
   return 0;
}