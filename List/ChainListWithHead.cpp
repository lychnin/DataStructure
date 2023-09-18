// 带头结点的单链表
#include <iostream>
using namespace std;
typedef int ElemType;
// 定义结构体并对其进行重命名
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
// 初始化,为头结点分配内存
bool Init(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        cout << "there is not enough memory" << endl;
        return false;
    }
    else
    {
        L->next = NULL;
        cout << "Init" << endl;
        return true;
    }
}
// 判断带头点的单链表是否为空,通过其头结点的next域是否为NULL判断
bool Empty(LinkList L)
{
    if (L->next == NULL)
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }
    return (L->next == NULL);
}
// 最好的情况是O(1),要插入第一个位置时,无需遍历
// 平均的情况是O(n)
// 最坏的情况是O(n),要插入最后一个位置时,因为要遍历n个
bool ListInsert(LinkList &L, int i, ElemType e)
{
    // 要插入的位序小于1,则无效,需要注意的是在这里的位序等同于索引
    // 因为索引虽然是从0开始的,但是索引为0的结点为头结点
    if (i < 1)
    {
        return false;
    }
    // 新建一个指针,负责对链表进行遍历
    LNode *p;
    // 索引遍历
    int j = 0;
    // 索引0对应的结点为头结点
    p = L;
    // 这个循环的作用:要么由于插入的位序不合理,使得p移动到了NULL,要么移动到位序-1的位置(也就是要插入的位置的前一个结点)
    // 有趣的是,对于带头结点的单链表来说,索引与位序是等同的,因为头结点对应的索引为0,但头结点并不存放数据
    while (p != NULL && j < i - 1)
    {
        // 遍历单链表
        p = p->next;
        // 索引遍历
        j++;
        // 索引与p对应,第n个结点(头结点算作第0个)对应j=n
    }
    if (p == NULL)
    {
        // 说明此时的位序已经超出了单链表中已有的节点,说明要插入的位置是超出上限的
        return false;
    }
    // 为要插入的节点分配内存
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    // 最后两行倘若颠倒,则p的next域指向的是s,再将s指向s,形成了死循环
    s->next = p->next;
    p->next = s;
    return true;
}
// 实现给定一个结点,在其后插入结点的逻辑
bool InsertNextNode(LNode *p, int e)
{
    // 为什么基准结点的值会为空值,因为这个函数一般是被别的函数调用的,而被调用的时候,有可能由于函数的逻辑问题,给这个函数传入空值
    //  如果基准结点的值为空值,那么就说明该结点不合法
    if (p == NULL)
    {
        cout << "Invalid node" << endl;
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    // 习惯性给新建的结点赋初值
    s->next = NULL;
    if (s == NULL)
    {
        cout << "Allocate memory false" << endl;
        return false;
    }
    s->next = p->next;
    p->next = s;
    s->data = e;
    return true;
}
// 实现给定一个结点,在其之前插入的逻辑
// 由于无法通过指针链接到前一个结点,所以我们采用后插的逻辑,但是将后插结点的数据域与基准结点的数据域互换,产生前插的效果
bool InsertPriorNode(LNode *p, int e)
{
    // 为什么基准结点的值会为空值,因为这个函数一般是被别的函数调用的,而被调用的时候,有可能由于函数的逻辑问题,给这个函数传入空值
    //  如果基准结点的值为空值,那么就说明该结点不合法
    if (p == NULL)
    {
        cout << "Invalid node" << endl;
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->next = NULL;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}
// 另一种写法的前插操作,该种写法传入的是基准结点和要插入的结点
bool InsertPriorNode2(LNode *p, LNode *s)
{
    if (p == NULL || s == NULL)
    {
        cout << "Invalid Node" << endl;
        return false;
    }
    s->next = p->next;
    p->next = s;
    int temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}
// 平均时间复杂度和最坏时间复杂度均为O(n),因为要遍历
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    // 位序小于1的结点只有头结点,而显然删除头结点不符合这个函数的目的
    if (i < 1)
    {
        cout << "invalid location" << endl;
        return false;
    }
    int j = 0;
    LNode *p = L;
    // 与插入相同,移动到要删除的结点的前一个结点,因为我们要将链接修改
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    // i-1或者i位置没有结点则说明无效
    if (p == NULL || p->next == NULL)
    {
        cout << "Invalid Location" << endl;
        return false;
    }
    // 这个目的是为了修改链接后还能找到该结点的地址并对内存进行释放
    LNode *q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}
// 删除指定结点,传入的即为要删除的结点,此时自然不能以基准结点改变链接的形式来删除
// 删除思想为以要删除的结点为基准结点删除后一个结点,将其值赋给基准结点,就产生了删除当前节点的效果
bool DeleteNode(LNode *p)
{
    // 但是这个程序有一个问题,那就是不能指定删除最后一个结点,因为最后一个结点没有p->next
    if (p == NULL)
    {
        return false;
    }
    LNode *q = p->next;
    // 看起来删除了q
    p->next = q->next;
    // 用q的值覆盖p
    p->data = q->data;
    free(q);
    return true;
}
// 按位查找，返回查找的结点
LNode *GetElem(LinkList L, int i)
{
    // 小于0的结点无效
    if (i < 0)
    {
        cout << "too low" << endl;
        return NULL;
    }
    int j = 0;
    LNode *p = L;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
// 按位查找王道书版本
LNode *GetElem2(LinkList L, int i)
{
    if (i < 0)
    {
        cout << "too low" << endl;
        return NULL;
    }
    // 查找头结点
    if (i == 0)
    {
        return L;
    }
    int j = 1;
    LNode *p = p->next;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
//  按值查找
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    // 因为这里比较的是data域,所以从第一个结点开始遍历
    while (p->data != e && p != NULL)
    {
        p = p->next;
    }
    return p;
}
// 表长
int Length(LinkList L)
{
    LNode *p = L;
    int length = 0;
    while (p != NULL)
    {
        p = p->next;
        length++;
    }
    return length - 1;
}
LinkList List_TailInsert(LinkList &L)
{
    // 这里没有对L分配内存是因为默认先使用了Init函数
    LNode *s, *r = L;
    int Elem;
    cout << "Enter Entry:" << endl;
    cin >> Elem;
    // 当输入的元素不等于结束符号时
    while (Elem != 999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->next = NULL;
        s->data = Elem;
        r->next = s;
        // 更新尾指针
        r = s;
        // 继续输入
        cout << "Enter Entry:" << endl;
        cin >> Elem;
    }
    // 最后令尾指针的next域为空,否则next域存储的为未知
    r->next = NULL;
    return L;
}
LinkList LinkList_HeadInsert(LinkList L)
{
    LNode *s;
    int Elem;
    cout << "Enter Entry:" << endl;
    cin >> Elem;
    while (Elem != 999)
    {
        // 分配内存要写在循环内部,因为每次迭代都会重新为s分配内存,就是一个全新的结点,这样的话地址就是新的地址,否则会让一个地址被重复插入,让s自己指向自己
        s = (LNode *)malloc(sizeof(LNode));
        s->next = NULL;
        s->next = L->next;
        L->next = s;
        s->data = Elem;
        cout << "Enter Entry:" << endl;
        cin >> Elem;
    }
    return L;
}
bool Print(LinkList L)
{
    if (Empty(L))
    {
        cout << "List is empty" << endl;
        return false;
    }
    int j = 0;
    LNode *p = L;
    while (p != NULL)
    {
        p = p->next;
        j++;
        if (p != NULL)
        {
            cout << "The " << j << "loc:" << p->data << endl;
        }
    }
    return true;
}
// 如果不带头结点尾插,第一个元素是特别的,因为在它之前没有别的结点,所以当i==1时,为L赋值,之后的结点与带头结点的相同
int main()
{
    LinkList L1;
    Init(L1);
    Empty(L1);
    List_TailInsert(L1);
    Length(L1);
    Print(L1);
    LinkList L2;
    Init(L2);
    LinkList_HeadInsert(L2);
    // Empty(L2);
    Length(L2);
    Print(L2);
}