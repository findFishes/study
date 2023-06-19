#include <iostream>
using namespace std;

//定义单链表节点类型
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode,*LinkList;

//初始化一个单链表（带头结点)
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));

    if(L == NULL)
        return false;
    L->next = NULL;
    return true;
}

void test(){
    LinkList L;
    InitList(L);
    cout << "test" << endl;
}
//在第i个位置插入元素e（带头结点）
bool ListInsert(LinkList &L,int i,int e)
{
    if(i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while(p != NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//后插操作:在p节点之后插入元素e
bool InsertNextNode(LNode *p,int e)
{
    if(p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
//尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s,*r = L;
    cin >> x;
    while(x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = NULL;
    return L;
}
//头插法建立单链表
LinkList List_HeadInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s;
    cin >> x;
    while(x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
    return L;
}






