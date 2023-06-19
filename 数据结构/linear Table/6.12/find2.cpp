#include<iostream>
using namespace std;
typedef struct  
{
    
     int data[10];
     int length =10;

    /* data */
}sqList;

void listIncert(sqList& L, int i, int e) {
    if (i < 1 || i > L.length + 1) { // 判断插入位置是否越界
        cout << "插入位置不合法" << endl; 
        return; 
    }
    if (L.length >= 10) { // 判断是否已满
        cout << "序列已满，不能插入" << endl;
        return; 
    }
    for (int j = L.length; j >= i; j--) { // 从后往前依次后移
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; // 插入元素
    L.length++; // 表长增加
}

// void listIncert(sqList &L,int i,int e){
//     for(int a=L.length;a>i;a--){
//        L.data[a]=L.data[a-1];    
//     }
//     L.data[i-1]=e;
 
// }

void showList(sqList L){
    for(int i=0;i<L.length;i++){
        // cout<<L.data[i]<<endl;
        printf("%d/n",L.data[i]);
        }
}
int main(){
   
   sqList L;
  
   listIncert(L,1,1);
   listIncert(L,1,2);
   listIncert(L,1,3);
   listIncert(L,1,4);
   listIncert(L,1,5);
   listIncert(L,1,6);
   listIncert(L,1,7);
   listIncert(L,1,8);
  
   showList(L);
  




}