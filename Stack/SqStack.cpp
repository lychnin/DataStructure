#include <iostream>
using namespace std;
#define MaxSize 10
typedef struct Stack
{
    int data[MaxSize];
    int top;
} SqStack;

void Init(SqStack &S)
{
    int i = 0;
    for (i = 0; i < MaxSize; i++)
    {
        S.data[i] = 0;
    }
    S.top = -1;
    cout << "Init……" << endl;
}
bool Destroy(SqStack &S)
{
    S.top = -1;
    cout << "Destroy……" << endl;
    return true;
}
bool StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        cout << "Empty" << endl;
    }
    return (S.top == -1);
}

bool push(SqStack &S, int e)
{
    if (S.top == MaxSize - 1)
    {
        cout << "Stack is full" << endl;
        return false;
    }
    // 等价
    //  S.top+=1;
    //  S.data[S.top]=e;
    S.data[++S.top] = e;
    cout << "push:" << e << endl;
    return true;
}
bool pop(SqStack &S, int &popElem)
{
    if (StackEmpty(S))
    {
        cout << "Stack is empty" << endl;
        return false;
    }
    // popElem = S.data[top];
    // S.top -= 1;
    popElem = S.data[S.top--];
    cout << "pop:" << popElem << endl;
    return true;
}
bool GetTop(SqStack S, int &topElem)
{
    if (StackEmpty(S))
    {
        cout << StackEmpty(S) << endl;
        return false;
    }
    topElem = S.data[S.top];
    cout << "top is :" << topElem << endl;
    return true;
}

int main()
{
    SqStack S;
    Init(S);
    StackEmpty(S);
    int i = 0;
    for (i = 0; i < MaxSize; i++)
    {
        push(S, i);
    }
    int popElem;
    GetTop(S, popElem);
    for (i = 0; i < MaxSize; i++)
    {
        pop(S, popElem);
    }
    Destroy(S);
}