#include <stdio.h>
#define maxSize 10
typedef struct 
{
    int data[maxSize];
    int length;
    /* data */
}sqList;

void initList(sqList &L){
    L.length=0;
}
int main(){
    sqList L;
    initList(L);
    for(int i=0;i<10;i++)
    printf("data[%d]=%d\n",i,L.data[i]);

}
