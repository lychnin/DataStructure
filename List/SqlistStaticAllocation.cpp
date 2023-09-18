#include <iostream>
using namespace std;
typedef int Elemtype;
#define MaxSize 10
// 静态存储
// typedef 起别名
typedef struct
{
    // 顺序表的数据
    Elemtype data[MaxSize];
    // 顺序表的长度
    int length;
} Sqlist;

void InitList(Sqlist &L)
{
    // 顺序表的长度是必须设置的,因为长度是合法访问顺序表元素必须知道的值
    L.length = 0;
    cout << "List is inited." << endl;
    // 为了防止产生脏数据，对数据进行赋初值
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
}

int main()
{
    Sqlist L;
    InitList(L);
    for (int i = 0; i < MaxSize; i++)
    {
        cout << i << endl;
        cout << L.data[i] << endl;
    }
}