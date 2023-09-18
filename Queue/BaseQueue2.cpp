// 几种队列的实现方式
#include <iostream>
using namespace std;
#define MaxSize 10
// 队尾指针指向当前元素的当前位置
typedef struct
{
    int data[MaxSize];
    int front;
    int rear;
} BaseQueue;
void Init(BaseQueue &L)
{
    L.front = 0;
    L.rear = -1;
    int i = 0;
    for (i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    cout << "Init……" << endl;
}
void Destroy(BaseQueue &L)
{
    L.front = 0;
    L.rear = -1;
    cout << "destroy……" << endl;
}

bool EnQueue(BaseQueue &L, int e)
{
    if ((L.rear + 2) % MaxSize == L.front)
    {
        cout << "Queue has been full" << endl;
        return false;
    }
    // 因为队尾指针指向的是当前元素,所以先后移再赋值
    L.rear = (L.rear + 1) % MaxSize;
    L.data[L.rear] = e;
    return true;
}

bool DeQueue(BaseQueue &L, int &e)
{
    if ((L.rear + 1) % MaxSize == L.front)
    {
        cout << "Queue has been empty" << endl;
        return false;
    }
    e = L.data[L.front];
    L.front = (L.front + 1) % MaxSize;
    cout << "DeQueue:" << e << endl;
    return true;
}

bool GetHead(BaseQueue &L, int &e)
{
    if ((L.rear + 1) % MaxSize == L.front)
    {
        cout << "Queue has been empty" << endl;
        return false;
    }
    e = L.data[L.front];
    cout << "GetHead:" << e << endl;
    return true;
}

bool Print1(BaseQueue L)
{
    if (L.front == (L.rear + 1) % MaxSize)
    {
        cout << "Queue has been empty" << endl;
        return false;
    }
    cout << "Queue:" << endl;
    int i = L.front;
    // 说明没满
    while ((L.rear + 1) % MaxSize != i % MaxSize)
    {
        cout << L.data[i] << "<-";
        i = (i + 1) % MaxSize;
    }
    cout << "\n";
    return true;
}
bool Print2(BaseQueue L)
{
    if (L.front == (L.rear + 1) % MaxSize)
    {
        cout << "Queue has been empty" << endl;
        return false;
    }
    int i = L.rear;
    cout << "Queue:" << endl;
    while ((i + 1) % MaxSize != L.front)
    {
        cout << L.data[i] << "->";
        i = (i - 1) % MaxSize;
    }
    cout << "\n";
    return true;
}
int main()
{
    BaseQueue L;
    Init(L);
    int i = 0;
    for (i = 0; i < MaxSize + 5; i++)
    {
        EnQueue(L, i);
    }
    Print1(L);
    Print2(L);
    int e;
    DeQueue(L, e);
    GetHead(L, e);
    Print1(L);
    Print2(L);
    for (i = 0; i < MaxSize + 5; i++)
    {
        DeQueue(L, i);
        Print1(L);
        Print2(L);
    }
    Destroy(L);
}