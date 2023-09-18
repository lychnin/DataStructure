#include <iostream>
using namespace std;
typedef struct RLNode
{
    int data;
    struct RLNode *next;
} RLNode, *RLinkList;

typedef struct RDNode
{
    int data;
    struct RDNode *next, *prior;
} RDNode, *RDList;

void InitRL(RLinkList &L)
{
    L = (RLNode *)malloc(sizeof(RLNode));
    L->next = L;
    cout << "Init……" << endl;
}

void InitRD(RDList &L)
{
    L = (RDNode *)malloc(sizeof(RDNode));
    L->next = L;
    L->prior = L;
    cout << "Init……" << endl;
}

bool EmptyRL(RLinkList L)
{
    if (L->next == L)
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Not Empty" << endl;
    }
    return (L->next == L);
}

bool EmptyRD(RDList L)
{
    if (L->next == L)
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Not Empty" << endl;
    }
    return (L->next == L);
}

void TailInsertRL(RLinkList &L, int e)
{
    // L为表尾指针
    RLNode *p;
    p = (RLNode *)malloc(sizeof(RLNode));
    p->next = NULL;
    p->data = e;
    p->next = L->next;
    L->next = p;
    L = p;
}

void InsertRL(RLinkList &L, int i, int e)
{
    RLNode *p;
    p = (RLNode *)malloc(sizeof(RLNode));
    p->next = NULL;
    p->data = e;
    int j = 0;
    RLNode *index = L->next;
    while (j < i - 1)
    {
        index = index->next;
        j++;
    }
    if (index->next != L->next)
    {
        p->next = index->next;
        index->next = p;
    }
    // 判断p是否为表尾指针
    else
    {
        p->next = index->next;
        index->next = p;
        L = p;
    }
}

void TailInsertRD(RDList &L, int e)
{
    RDNode *p;
    p = (RDNode *)malloc(sizeof(RDNode));
    p->data = e;
    p->prior = NULL;
    p->next = NULL;
    p->next = L->next;
    L->next->prior = p;
    L->next = p;
    p->prior = L;
    L = p;
}

void InsertRD(RDList &L, int i, int e)
{
    RDNode *p;
    p = (RDNode *)malloc(sizeof(RDNode));
    p->next = NULL;
    p->data = e;
    int j = 0;
    RDNode *index = L->next;
    while (j < i - 1)
    {
        index = index->next;
        j++;
    }
    if (index->next != L->next)
    {
        p->next = index->next;
        index->next = p;
    }
    // 判断p是否为表尾指针
    else
    {
        p->next = index->next;
        index->next = p;
        L = p;
    }
}

void DeleteRL() {}

void DeleteRD() {}

void PrintRL(RLinkList L)
{
    int j = 1;
    RLNode *p;
    p = L->next->next;
    while (p != L->next)
    {
        cout << p->data << "->";
        j++;
        p = p->next;
    }
    cout << "length:" << j - 1 << endl;
}

void PrintRD(RDList L)
{
    int j = 1;
    RDNode *p;
    p = L->next->next;
    while (p != L->next)
    {

        cout << p->data << "->";
        j++;
        p = p->next;
    }
    cout << "length:" << j - 1 << endl;
}

int main()
{
    RLinkList L1;
    RDList L2;
    InitRL(L1);
    InitRD(L2);
    EmptyRL(L1);
    EmptyRD(L2);
    int i;
    int length = 5;
    for (i = 0; i < length; i++)
    {
        TailInsertRL(L1, i);
        TailInsertRD(L2, i);
    }
    EmptyRL(L1);
    EmptyRD(L2);
    PrintRL(L1);
    PrintRD(L2);
    InsertRL(L1, 2, 999);
    PrintRL(L1);
    InsertRD(L2, 2, 999);
    PrintRD(L2);
    InsertRL(L1, 7, 999);
    PrintRL(L1);
    InsertRD(L2, 7, 999);
    PrintRD(L2);
    InsertRL(L1, 8, 888);
    PrintRL(L1);
    InsertRD(L2, 8, 888);
    PrintRD(L2);
}