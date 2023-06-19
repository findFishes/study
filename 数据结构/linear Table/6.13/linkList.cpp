#include <iostream>
using namespace std;
typedef struct 
{
    /* data */

    int data;
}newStyle,*news ;

int main(){
newStyle L ;

L.data =5;
news P =&L;
cout<<L.data<<endl;
cout<<P->data<<endl;
cout<<P<<endl;



}

