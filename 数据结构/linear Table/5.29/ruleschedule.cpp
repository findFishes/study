#include <stdio.h>
#define Maxsize 10
typedef struct 
{
    int data[Maxsize];
    int length;
    /* data */
}SqlList;

void init (SqlList &L){
    for(int i=0;i<19;i++){
        L.data[i]=0;

    }
    L.length=0;
    
}

int main (){

printf("helloworld");
SqlList L;
init(L);
for(int i= 0;i<10;i++){
    printf("data[%d]=%d\n",i,L.data[i]);
  
}
return 0;

}
