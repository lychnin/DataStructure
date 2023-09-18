#include <iostream>
using namespace std;
#define MaxSize 10
typedef struct Node
{
    int data;
    int next;
};

typedef struct
{
    int data;
    int next;
} SLinklist[MaxSize];

void Init(SLinklist &L)
{
    int i;
    for (i = 0; i < MaxSize; i++)
    {
        L[i].data = 0;
        L[i].next = -2;
    }
    // 将第一个结点设为头结点,初始化时还没有数据,头结点的游标设置为-1
    L[0].next = -1;
    cout << "Init……" << endl;
}

void TailInsert(SLinklist &L, int e)
{
    // 数组索引,0对应头结点
    int index = 0;
    while (L[index].next != -1)
    {
        // 将索引设为该结点的next值,即游标
        index = L[index].next;
    }
    int i = 0;
    for (i = 0; i < MaxSize; i++)
    {
        if (L[i].next == -2)
        {
            cout << "\n";
            cout << "Exist Room" << endl;
            break;
        }
    }
    L[index].next = i;
    L[i].next = -1;
    L[i].data = e;
}

bool Locate(SLinklist L, int e)
{
    int index = L[0].next;
    while (index != -1 && L[index].data != e)
    {
        index = L[index].next;
    }
    if (index == -1)
    {
        return false;
    }
    cout << index << endl;
    return true;
}

bool Insert(SLinklist &L, int e, int index)
{
    if (index < 1)
    {
        cout << "Invalid" << endl;
        return false;
    }
    int symbol = 0;
    int order = 0;
    while (symbol != -1 && order < index - 1)
    {
        symbol = L[symbol].next;
        order++;
    }
    if (symbol == -1)
    {
        cout << "invalid" << endl;
        return false;
    }
    int i = 0;
    while (L[i].next != -2)
    {
        i++;
    }
    L[i].next = L[symbol].next;
    L[symbol].next = i;
    L[i].data = e;
    return true;
}

void Print(SLinklist L)
{
    // index从L的头结点的下一个开始
    int index = L[0].next;
    cout << "List:";
    // 只要游标不为-1就输出,一旦游标等于-1,就跳出
    while (index != -1)
    {
        cout << L[index].data << "->";
        // 相当于index++,只是这里是静态链表
        index = L[index].next;
    }
    cout << "\n";
}
int main()
{
    SLinklist L;
    Init(L);
    Print(L);
    TailInsert(L, 1);
    TailInsert(L, 2);
    TailInsert(L, 3);
    Print(L);
    Locate(L, 1);
    Locate(L, 3);
    Insert(L, 999, 1);
    Insert(L, 777, 2);
    Insert(L, 666, 3);
    Print(L);
}