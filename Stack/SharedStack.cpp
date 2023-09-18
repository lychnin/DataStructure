#include <iostream>
using namespace std;
#define MaxSize 10
typedef struct sharedStack
{
    int top1;
    int top2;
    int data[MaxSize];
} SharedStack;

void Init(SharedStack &S)
{
    int i = 0;
    for (i = 0; i < MaxSize; i++)
    {
        S.data[i] = 0;
    }
    S.top1 = -1;
    S.top2 = MaxSize;
    cout << "Init……" << endl;
}
bool Destroy(SharedStack &S)
{
    S.top1 = -1;
    S.top2 = MaxSize;
    cout << "Destroy……" << endl;
    return true;
}
bool StackEmpty(SharedStack S, int order)
{
    if (order == 1)
    {
        if (S.top1 == -1)
        {
            cout << "Empty" << endl;
        }
        return (S.top1 == -1);
    }
    if (order == 2)
    {
        if (S.top2 == MaxSize)
        {
            cout << "Empty" << endl;
        }
        return (S.top2 == MaxSize);
    }
}

bool StackFull(SharedStack S)
{
    if ((S.top1 + 1) == S.top2)
    {
        cout << "Stack is Full" << endl;
        return true;
    }
    return false;
}
bool push(SharedStack &S, int order, int e)
{
    if (order == 1)
    {
        if (StackFull(S))
        {
            return false;
        }
        S.data[++(S.top1)] = e;
        cout << "push:" << e << endl;
        return true;
    }
    if (order == 2)
    {
        if (StackFull(S))
        {
            return false;
        }
        S.data[--(S.top2)] = e;
        cout << "push:" << e << endl;
        return true;
    }
}
bool pop(SharedStack &S, int order, int &popElem)
{
    if (order == 1)
    {
        if (StackEmpty(S, order))
        {
            return false;
        }
        popElem = S.data[S.top1--];
        cout << "pop:" << popElem << endl;
        return true;
    }
    if (order == 2)
    {
        if (StackEmpty(S, order))
        {
            return false;
        }
        popElem = S.data[S.top2++];
        cout << "pop:" << popElem << endl;
        return true;
    }
}
bool GetTop(SharedStack S, int order, int &topElem)
{
    if (order == 1)
    {
        if (StackEmpty(S, order))
        {
            return false;
        }
        topElem = S.data[S.top1];
        cout << "GET:" << topElem << endl;
        return true;
    }
    if (order == 2)
    {
        if (StackEmpty(S, order))
        {
            return false;
        }
        topElem = S.data[S.top2];
        cout << "GET:" << topElem << endl;
        return true;
    }
}

int main()
{
    SharedStack S;
    Init(S);
    StackEmpty(S, 1);
    StackEmpty(S, 2);
    StackFull(S);

    int i = 0;
    for (i = 0; i < MaxSize - 5; i++)
    {
        push(S, 1, i);
        push(S, 2, i);
    }
    int popElem;
    GetTop(S, 1, popElem);
    GetTop(S, 2, popElem);
    for (i = 0; i < MaxSize - 5; i++)
    {
        pop(S, 1, popElem);
        pop(S, 2, popElem);
    }
    Destroy(S);
}