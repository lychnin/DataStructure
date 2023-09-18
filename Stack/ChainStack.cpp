#include <iostream>
using namespace std;
typedef struct Stack
{
    int data;
    struct Stack *next;
} StackElem, *ChainStack;

// 我们选用不带头结点的
void Init(ChainStack &S)
{
    // 只有头指针
    S = NULL;
    cout << "Init……" << endl;
}

bool StackEmpty(ChainStack S)
{
    if (S == NULL)
    {
        cout << "Empty" << endl;
        return true;
    }
    return false;
}

bool push(ChainStack &S, int e)
{
    StackElem *p;
    p = (StackElem *)malloc(sizeof(StackElem));
    p->data = e;
    p->next = S;
    S = p;
    cout << "push:" << p->data << endl;
    return true;
}

bool pop(ChainStack &S, int &pop)
{
    if (StackEmpty(S))
    {
        return false;
    }
    StackElem *p = S;
    pop = S->data;
    S = S->next;
    free(p);
    return true;
}

void destroy(ChainStack &S)
{
    StackElem *p = S;
    StackElem *q;
    while (p != NULL)
    {
        q = p;
        p->data = 0;
        p = p->next;
        free(q);
        q = NULL;
    }
    cout << "Destroy……" << endl;
}

bool GetTop(ChainStack S, int &pop)
{
    if (StackEmpty(S))
    {
        return false;
    }
    pop = S->data;
    return true;
}
void Print(ChainStack S)
{
    StackElem *p = S;
    cout << "List:";
    while (p != NULL)
    {
        if (p->next == NULL)
        {
            cout << p->data;
            p = p->next;
            break;
        }
        cout << p->data;
        cout << "->";
        p = p->next;
    }
    cout << "\n";
}

int main()
{
    ChainStack S;
    Init(S);
    StackEmpty(S);
    int e = 0;
    for (e = 0; e < 10; e++)
    {
        push(S, e);
    }
    Print(S);
    int top;
    GetTop(S, top);
    for (e = 0; e < 10; e++)
    {
        pop(S, top);
        Print(S);
    }
    destroy(S);
}