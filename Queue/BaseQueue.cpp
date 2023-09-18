// 几种队列的实现方式
#include <iostream>
using namespace std;
#define MaxSize 10
// 队尾指针指向当前元素的下一个位置
typedef struct
{
    int data[MaxSize];
    int front;
    int rear;
} BaseQueue;
// 设置了size
typedef struct
{
    int data[MaxSize];
    int front;
    int rear;
    int size;
} BaseSizeQue;
// 设置了tag
typedef struct
{
    int data[MaxSize];
    int front;
    int rear;
    int tag;
} BaseTagQue;
void Init(BaseQueue &L)
{
    L.front = 0;
    L.rear = 0;
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
    L.rear = 0;
    cout << "destroy……" << endl;
}

bool EnQueue(BaseQueue &L, int e)
{
    if ((L.rear + 1) % MaxSize == L.front)
    {
        cout << "Queue has been full" << endl;
        return false;
    }
    L.data[L.rear] = e;
    L.rear = (L.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(BaseQueue &L, int &e)
{
    if (L.rear == L.front)
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
    if (L.rear == L.front)
    {
        cout << "Queue has been empty" << endl;
        return false;
    }
    e = L.data[L.front];
    cout << "GetHead:" << e << endl;
    return true;
}

bool Print(BaseQueue L)
{
    if (L.front == L.rear)
    {
        cout << "Queue has been empty" << endl;
        return false;
    }
    cout << "Queue:" << endl;
    int i = L.front;
    // 说明没满
    while (L.rear != i % MaxSize)
    {
        cout << L.data[i] << "<-";
        i = (i + 1) % MaxSize;
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