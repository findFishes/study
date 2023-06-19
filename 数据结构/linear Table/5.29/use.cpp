#include <stdio.h>

void test (int &y)
{   y =1024;
    printf("test函数内部 x=%d\n",y);
}
void test2 (int x)
{   x =1024;
    printf("test函数内部 x=%d\n",x);
}

int main()
{  int x =1;
   printf("test:\n");
   printf("调用前x=%d\n",x);
   test2(x); 
   printf("调用后x=%d\n",x); 
   printf("test2:\n");


   printf("调用前x=%d\n",x);
   test(x);   
   printf("调用后x=%d\n",x);
}