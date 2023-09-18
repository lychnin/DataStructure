// 几种队列的实现方式
#include <iostream>
using namespace std;
#define MaxSize 10
// 设置tag属性,若前一步为插入,则设置为1,如果前一步为删除则设置为0
// 队空和队满的时候都是L.front==L.rear,进而通过tag的值判断
typedef struct
{
    int data[MaxSize];
    int front;
    int rear;
    int tag;
} BaseTagQue;
// 这里L.rear指向下一个元素
void Init(BaseTagQue &L)
{
    L.front = 0;
    L.rear = 0;
    L.tag = -1;
    int i = 0;
    // 初始化数据,替换脏数据
    for (i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    cout << "Init……" << endl;
}

void Destroy(BaseTagQue &L)
{
    L.front = 0;
    L.rear = 0;
    L.tag = -1;
    cout << "destroy……" << endl;
}
// 入队操作
bool EnQueue(BaseTagQue &L, int e)
{
    // 如果队满则不能入队
    if ((L.rear == L.front) && L.tag == 1)
    {
        cout << "Queue has been full" << endl;
        return false;
    }
    L.data[L.rear] = e;
    cout << "Enqueue" << L.data[L.rear] << endl;
    L.rear = (L.rear + 1) % MaxSize;
    L.tag = 1;
    return true;
}
// 出队操作
bool DeQueue(BaseTagQue &L, int &e)
{
    // 如果队空则无法出队
    if ((L.rear == L.front) && L.tag == 0)
    {
        cout << "Queue has been empty" << endl;
        return false;
    }
    e = L.data[L.front];
    cout << "DeQueue:" << e << endl;
    L.front = (L.front + 1) % MaxSize;
    L.tag = 0;
    return true;
}
// 取队头元素
bool GetHead(BaseTagQue &L, int &e)
{
    if ((L.rear == L.front) && L.tag == 0)
    {
        cout << "Queue has been empty" << endl;
        return false;
    }
    e = L.data[L.front];
    cout << "GetHead:" << e << endl;
    return true;
}

bool Print(BaseTagQue L)
{
    // 队空则无法打印元素
    if ((L.rear == L.front) && L.tag == 0)
    {
        cout << "Queue has been empty" << endl;
        return false;
    }
    cout << "Queue:" << endl;
    int i = L.rear;
    while (!((i == L.front) && L.tag == 0))
    {
        // 为了防止i变为负数
        i = (i - 1 + MaxSize) % MaxSize;
        // 读取时相当于出队,L.tag不会为1
        L.tag = 0;
        cout << L.data[i] << "->";
    }
    cout << "\n";
    return true;
}
int main()
{
    BaseTagQue L;
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