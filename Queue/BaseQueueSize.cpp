// 几种队列的实现方式
#include <iostream>
using namespace std;
#define MaxSize 10
// 设置了size
typedef struct
{
    int data[MaxSize];
    int front;
    int rear;
    int size;
} BaseSizeQue;

void Init(BaseSizeQue &L)
{
    L.front = 0;
    L.rear = 0;
    L.size = 0;
    int i = 0;
    for (i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    cout << "Init……" << endl;
}

void Destroy(BaseSizeQue &L)
{
    L.front = 0;
    L.rear = 0;
    L.size = 0;
    cout << "destroy……" << endl;
}

bool EnQueue(BaseSizeQue &L, int e)
{
    if (L.size == MaxSize)
    {
        cout << "Queue has been full" << endl;
        return false;
    }
    L.data[L.rear] = e;
    L.rear = (L.rear + 1) % MaxSize;
    L.size = L.size + 1;
    return true;
}

bool DeQueue(BaseSizeQue &L, int &e)
{
    if (L.size == 0)
    {
        cout << "Queue has been empty" << endl;
        return false;
    }
    e = L.data[L.front];
    L.front = (L.front + 1) % MaxSize;
    cout << "DeQueue:" << e << endl;
    L.size = L.size - 1;
    return true;
}

bool GetHead(BaseSizeQue &L, int &e)
{
    if (L.rear == L.front)
    {
        cout << "Queue has been empty" << endl;
        return false;
    }
    e = L.data[L.front];
    cout << "GetHead:" << e << endl;
    return true;
}

bool Print(BaseSizeQue L)
{
    if (L.size == 0)
    {
        cout << "Queue has been empty" << endl;
        return false;
    }
    cout << "Queue:" << endl;
    int i = L.front;
    // 说明没满
    cout << "L.size:" << L.size << endl;
    while (L.size != 0)
    {
        // 每次循环开始的时候L.size 为当前队列拥有的元素个数
        cout << L.data[i] << "<-";
        i = (i + 1) % MaxSize;
        L.size -= 1;
    }
    cout << "\n";
    return true;
}

int main()
{
    BaseSizeQue L;
    Init(L);
    int i = 0;
    for (i = 0; i < MaxSize + 5; i++)
    {
        EnQueue(L, i);
    }
    Print(L);
    int e;
    DeQueue(L, e);
    GetHead(L, e);
    Print(L);
    for (i = 0; i < MaxSize + 5; i++)
    {
        DeQueue(L, i);
        Print(L);
    }
    Destroy(L);
}