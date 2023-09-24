#include <iostream>
using namespace std;
int *allocateMemory()
{
    int *ptr = new int; // 在内层函数中使用 new 分配内存
    *ptr = 42;          // 对内存进行操作
    return ptr;         // 返回指向内存的指针
}

void deallocateMemory(int *ptr)
{

    delete ptr; // 在外层函数中使用 delete 释放内存
}

int main()
{
    int *memory = allocateMemory();    // 调用内层函数分配内存
    std::cout << *memory << std::endl; // 输出内存中的值
    deallocateMemory(memory);          // 调用外层函数释放内存
    return 0;
}
