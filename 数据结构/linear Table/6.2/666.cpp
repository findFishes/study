#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int main()
{
    printf("Hello World!\n");
    printf("你好世界！\n");
    add(1,2);
    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}