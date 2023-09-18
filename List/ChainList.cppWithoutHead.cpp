// 不带头结点的单链表
#include <iostream>
using namespace std;
typedef int Elemtype;
typedef struct LNode
{
    Elemtype data;
    struct LNode *next;
} LNode, *LinkList;
// 这里的typedef相当于是将两条语句合成一个进行描述的
// typedef struct LNode LNode
// typedef struct LNode * LinkList
// 所以使用LinkLsit时就是使用了一个结构体指针
bool Init(LinkList &L)
{
    // 将头结点赋为空值
    L = NULL;
    cout << "Init" << endl;
    return true;
}

bool Empty(LinkList L)
{
    if (L == NULL)
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }
    return (L == NULL);
}

bool ListInsert(LinkList &L, int i, Elemtype e)
{
    // 对于不带头结点的单链表来说,与带头结点的单链表的插入操作的区别在于第一个结点的处理
    // 由于不带头结点的单链表的头指针指向的是第一个结点,所以插入第一个位置后,头指针改变
    // 对于第一个之后的位置的插入,与带头结点的单链表类似,不同的是不带头结点的单链表是从第一个结点开始遍历的
    if (i < 1)
    {
        return false;
    }
    if (i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        // 此处之所以是s->next=L,是因为链表中第一个结点的指针就是L,倘若令s->next=L->next,则s->next指向的就是第二个结点或者空值了
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;
    // 索引从1开始
    int j = 1;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        cout << "oversize" << endl;
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    // 这行体现了插入的精髓,在于移动到要插入的节点的前一个节点,将它的next域改变为s
    p->next = s;
    return true;
}

bool ListDelete(LinkList &L, int i, Elemtype e)
{
    if (i < 1)
    {
        cout << "Invaid Location" << endl;
        return false;
    }
    if (i == 1)
    {
        // 因为L为第一个结点,所以要删除第一个结点只需要将头指针指向第二个结点,并且将第一个结点的内存释放掉即可
        LNode *p = L;
        L = L->next;
        free(p);
        return true;
    }
    int j = 1;
    LNode *p = L;
    while (p != NULL || j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL)
    {
        cout << "i-1 and i node is NULL" << endl;
        return false;
    }
    LNode *q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}

LinkList List_TailInsert(LinkList &L)
{
    LNode *s, *r = L;
    int Elem;
    cin >> Elem;
    // 当输入的元素不等于结束符号时
    L->data = Elem;
    L->next = NULL;
    cin >> Elem;
    while (Elem != 999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = Elem;
        r->next = s;
        // 更新尾指针
        r = s;
        // 继续输入
        cin >> Elem;
    }
    // 最后令尾指针的next域为空,否则next域存储的为未知
    r->next = NULL;
    return L;
}

LinkList LinkList_HeadInsert(LinkList L)
{
    LNode *s;
    s = (LNode *)malloc(sizeof(LNode));
    int Elem;
    cin >> Elem;
    L->data = Elem;
    cin >> Elem;
    while (Elem != 999)
    {
        s->next = L;
        L = s;
    }
    return L;
}
int main()
{
    LinkList L;
    Init(L);
    Empty(L);
}