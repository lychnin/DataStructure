#include <iostream>
using namespace std;
typedef struct Double
{
    int data;
    struct Double *prior, *next;
} Double, *DoubleList;

void Init(DoubleList &L)
{
    L = (Double *)malloc(sizeof(Double));
    if (L == NULL)
    {
        cout << "Allocate false" << endl;
    }
    L->next = NULL;
    L->prior = NULL;
}

void InsertList(DoubleList &L, int i, int e)
{
    int j = 0;
    Double *p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    Double *s;
    s = (Double *)malloc(sizeof(Double));
    s->next = NULL;
    s->prior = NULL;
    s->next = p->next;
    s->prior = p;
    if (p->next != NULL)
    {
        // 将不同的那一条放到判断语句中
        p->next->prior = s;
    }
    // p->next最后修改,防止影响
    p->next = s;
}
// 删除p结点的后继结点,因为这样做可以使得销毁链表时方便调用
bool ListDeleteNode(Double *p)
{
    if (p == NULL)
    {
        return false;
    }
    // p没有后继结点
    if (p->next == NULL)
    {
        return false;
    }
    Double *q;
    p->next = q->next;
    if (q->next != NULL)
    {
        q->next->prior = p;
    }
    free(q);
    return true;
}
void DestroyList(DoubleList &L)
{
    while (L->next != NULL)
    {
        // 只要还存在第一个结点,就一直传入头指针,删除第一个结点,直到都删除
        // 如果删除函数删除的是当前节点,就传入L->next
        ListDeleteNode(L);
    }
    free(L);
    // 防止L变为野指针
    L = NULL;
}