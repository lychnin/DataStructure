#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
} QueueNode;

typedef struct
{
    QueueNode *front, *rear;
    int length;
} ChainQueue;

// 因为是带头结点的,所以要为头指针分配空间,即头结点的空间
void Init(ChainQueue &L)
{
    L.front = (QueueNode *)malloc(sizeof(QueueNode));
    L.front->next = NULL;
    L.rear = L.front;
    L.length = 0;
    cout << "Init……" << endl;
}

void Destroy(ChainQueue &L)
{
    cout << "Destroy……" << endl;
}

bool EnQueue(ChainQueue &L, int e)
{
    QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
    p->next = NULL;
    p->data = e;
    // 在尾部插入结点
    L.rear->next = p;
    // 更新尾指针
    L.rear = p;
    cout << "EnQueue:" << e << endl;
    L.length += 1;
    return true;
}

bool DeQueue(ChainQueue &L, int &pop)
{
    if (L.front->next == NULL)
    {
        cout << "The Queue has been empty." << endl;
        return false;
    }
    QueueNode *p = L.front->next;
    pop = p->data;
    cout << "DeQueue:" << pop << endl;
    L.front->next = p->next;
    L.length -= 1;
    free(p);
    return true;
}

bool GetHead(ChainQueue L, int &pop)
{
    if (L.front->next == NULL)
    {
        cout << "The Queue has been empty." << endl;
        return false;
    }
    pop = L.front->next->data;
    return true;
}

bool Print(ChainQueue L)
{
    if (L.front->next == NULL)
    {
        cout << "The queue has been empty" << endl;
        return false;
    }
    QueueNode *p = L.front->next;
    while (p != NULL)
    {
        cout << p->data << "<-";
        p = p->next;
    }
    cout << "\n";
    return true;
}
void Test()
{
    ChainQueue L;
    int pop;
    int i = 0;
    Init(L);
    while (i != 10)
    {
        EnQueue(L, i);
        i++;
    }
    Print(L);
    i = 0;
    while (i != 15)
    {
        DeQueue(L, pop);
        i++;
        Print(L);
    }
    GetHead(L, pop);
    Destroy(L);
}

int main()
{
    Test();
}