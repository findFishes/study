#include <iostream>
//定义双链表节点类型
typedef struct DNode
{
    int data;
    struct DNode *prior,*next;
} DNode,*DLinkList;
//初始化一个双链表（带头结点)
bool InitList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if(L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}
void test(){
    DLinkList L;
    InitList(L);
    std::cout << "test" << std::endl;
}
//在第i个位置插入元素e（带头结点）
bool ListInsert(DLinkList &L,int i,int e)
{
    if(i < 1)
        return false;
    DNode *p;
    int j = 0;
    p = L;
    while(p != NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL)
        return false;
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    if(p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}
//后插操作:在p节点之后插入元素e
bool InsertNextNode(DNode *p,int e)
{
    if(p == NULL)
        return false;
    DNode *s = (DNode *)malloc(sizeof(DNode));
    if(s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    if(p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}
//前插操作:在p节点之前插入元素e
bool InsertPriorNode(DNode *p,int e)
{
    if(p == NULL)
        return false;
    DNode *s = (DNode *)malloc(sizeof(DNode));
    if(s == NULL)
        return false;
    s->data = p->data;
    p->data = e;
    s->prior = p->prior;
    p->prior = s;
    s->next = p;
    if(s->prior != NULL)
        s->prior->next = s;
    return true;
}
//删除p节点的后继节点
bool DeleteNextNode(DNode *p)
{
    if(p == NULL)
        return false;
    DNode *q = p->next;
    if(q == NULL)
        return false;
    p->next = q->next;
    if(q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}
//双链表的遍历
void TraverseList(DLinkList L)
{
    DNode *p = L->next;
    while(p != NULL)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}