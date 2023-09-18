#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int Elemtype;
#define MaxSize 10
// 动态分配,这里要注意的是这是顺序存储而不是链式存储
typedef struct
{
    // 指示动态分配数组的指针
    int *data;
    int maxLength;
    int length;
} Seqlist;

void Init(Seqlist &L)
{
    // 申请一片指定大小的空间,malloc函数返回一个地址,最前面的(int*)是用来将这个地址转换为整型指针类型,这是因为只有知道指针类型,才能正确地将数据以正确的类型进行读取
    L.data = (int *)malloc(MaxSize * sizeof(int));
    int index = 0;
    L.maxLength = MaxSize;
    for (index = 0; index < L.maxLength; index++)
    {
        L.data[index] = 0;
    }
    L.length = 0;
    L.maxLength = MaxSize;
    cout << "Init……" << endl;
}

// 对于动态分配的顺序表,更改大小的话,新建一片更大的空间,将原空间存储的数据放到这片空间上
void IncreaseSize(Seqlist &L, int len)
{
    // 将原空间的指针赋给另一个指针,让这片空间还可以被找到,因为之后要在存放新的指针
    int *p = L.data;
    // 用原来的指针申请一片更大的空间,L.data的值改变,成为了一个新的指针
    // L.data = new int[L.maxLength + len];
    L.data = (int *)malloc((L.maxLength + len) * sizeof(int));
    // 将原空间存储的数据赋值给新的空间
    int i = 0;
    for (i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    for (i = L.maxLength; i <= L.maxLength + len - 1; i++)
    {
        L.data[i] = 0;
    }
    // 最大表长增加
    cout << "Origin length of L is:" << L.maxLength << endl;
    int origin = L.maxLength;
    L.maxLength = L.maxLength + len;
    cout << "Length of L change to :" << L.maxLength << endl;
    cout << "the increase room is " << L.maxLength - origin << endl;
    // 释放原来的空间
    free(p);
    p = NULL;
}

// 访问顺序表指定位序的元素,即按位查找
int LocateElem(Seqlist L, int i)
{
    if (i - 1 < 0 || i - 1 > L.length - 1)
    {
        cout << "Ilegal Search " << endl;
        return false;
    }
    // 这里的i是从1开始的
    cout << "search the" << i << "data" << endl;
    cout << "data is :" << L.data[i - 1] << endl;
    return L.data[i - 1];
}

// 按值查找
int GetElem(Seqlist L, int e)
{
    int index = 0;
    while (L.data[index] != e)
    {
        index++;
    }
    cout << "the elem's index is" << index << endl;
    return index;
}

// 顺序表插入元素,i代表位序
bool ListInsert(Seqlist &L, int i, int e)
{
    if (i < 1 || i > L.maxLength + 1)
    {
        cout << "invalid location" << endl;
        return false;
    }
    if (L.length == L.maxLength)
    {
        cout << "the Seqlist is full" << endl;
        return false;
    }
    cout << "insert to the" << i << "loc" << endl;
    int index = 0;
    for (index = L.length - 1; index >= i - 1; index--)
    {
        L.data[index + 1] = L.data[index];
    }
    // 对第i位序插入元素
    L.data[i - 1] = e;
    // 表长+1
    L.length += 1;
    return true;
}

// 销毁一个顺序表
void DestroyList(Seqlist &L)
{
    free(L.data);
    L.data = NULL;
    L.length = 0;
    L.maxLength = 0;
    cout << "destroy the seqlist" << endl;
}

// 删除顺序表中的元素
void ListDelete(Seqlist &L, int e)
{
    int index = 0;
    while (L.data[index] != e || index <= L.length - 1)
    {
        index++;
    }
    if (index == L.length)
    {
        cout << "Not exist the Elem" << endl;
    }
    else
    {
        cout << "the Elem is:" << L.data[index] << endl;
    }
}
// 输出线性表的表长
int Length(Seqlist L)
{
    cout << "the length of the Seqlist" << L.length << endl;
    return L.length;
}

// 打印线性表
void PrintList(Seqlist L)
{
    int index = 0;
    while (index < L.length)
    {
        cout << "the" << index + 1 << "Elem is:" << L.data[index] << endl;
        index++;
    }
}

// 判断线性表是否为空
bool Empty(Seqlist L)
{
    if (L.length == 0)
    {
        cout << "Seqlist is empty" << endl;
        return true;
    }
    else
    {
        cout << "Seqlist is not empty" << endl;
        return false;
    }
}

void help()
{
    cout << "*********All function*********" << endl;
    cout << "Init(Seqlist &L)" << endl;
    cout << "bool Empty(Seqlist L)" << endl;
    cout << "int ListInsert(Seqlist &L, int i, int e)" << endl;
    cout << "int Length(Seqlist L)" << endl;
    cout << "int LocateElem(Seqlist L, int i)" << endl;
    cout << "int GetElem(Seqlist L, int e)" << endl;
    cout << "void PrintList(Seqlist L)" << endl;
    cout << "void IncreaseSize(Seqlist &L, int len)" << endl;
    cout << "void ListDelete(Seqlist &L,int e)" << endl;
    cout << "void DestroyList(Seqlist &L)" << endl;
}
int main()
{
    help();
    // 定义一个顺序表
    Seqlist L;
    // 初始化该顺序表
    Init(L);
    // 查看该顺序表是否为空
    Empty(L);
    // 为顺序表插入元素
    int index = 0;
    int elem = 0;
    for (index = 1; index <= L.maxLength; index++)
    {
        ListInsert(L, index, elem);
        elem++;
    }
    // 查看插入元素后的顺序表长度
    Length(L);
    // 增加该顺序表的长度
    IncreaseSize(L, 5);
    PrintList(L);
    ListInsert(L, 11, 150);
    PrintList(L);
    DestroyList(L);
}