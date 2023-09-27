// 优化后的KMP算法,思路是将next数组优化,使得失配的元素对应的next元素如果和失配元素相同就将next元素更新为原next元素的next元素
#include <iostream>
using namespace std;
#define MaxSize 20
typedef struct String
{
    char *data;
    int length;
} SString;

void Print(SString S)
{
    int index = 1;
    while (index <= S.length)
    {
        cout << S.data[index];
        index++;
    }
    cout << "\n";
}
void Init(SString &S)
{
    S.data = (char *)malloc(MaxSize * sizeof(char));
    S.length = 0;
    cout << "Init……" << endl;
}
// 把T赋值为chars
bool StrAssign(SString &S, string chars)
{
    int index = 1;
    int len = chars.size();
    if (len > MaxSize)
    {
        cout << "Oversize……" << endl;
        return false;
    }
    while (index <= len)
    {
        S.data[index] = chars[index - 1];
        index++;
        S.length++;
    }
    Print(S);
    return true;
}

bool Optimize(int *next, int *nextval, SString pattern)
{
    // 因为第一个位置已经确定,所以从第二个元素开始匹配
    int j = 2;
    nextval[1] = 0;
    while (j <= pattern.length)
    {
        if (pattern.data[j] == pattern.data[next[j]])
        {
            // 更新第j个元素的next值为原next值的next值,因为nextval是从左到右更新的,所以这里使用的不是next[next[]]而是nextval[next[]],更为准确
            nextval[j] = nextval[next[j]];
        }
        else
        {
            // 第j个元素的next值与原next值相同
            nextval[j] = next[j];
        }
        j++;
    }
    return true;
}

bool KMP(SString Parent, SString pattern, int *next)
{
    if (Parent.length < pattern.length)
    {
        cout << "Parent is shorter than pattern." << endl;
        return false;
    }
    // 主串指针
    int Pindex = 1;
    // 模式串指针
    int pindex = 1;
    // 为什么是<=
    // 因为对模式串的匹配需要从1开始到最后一个元素(位序与下标相同)
    // 对主串的匹配也一样,每一个元素都要参加匹配
    while (Pindex <= Parent.length && pindex <= pattern.length)
    {
        // 如果当前元素可以匹配得上,那么指针就都向后移动
        if (pindex == 0 || Parent.data[Pindex] == pattern.data[pindex])
        {
            Pindex++;
            pindex++;
        }
        else
        {
            // 如果当前元素匹配不上,那么主串指针不动,模式串指针根据next数组中所存储的位置移向next[pindex]
            // 模式串第几个位置没有匹配上,就移向next[没有匹配上的位置]
            // 特殊的是如果第一个位置没有匹配上,移向next[pindex]==0,这是因为移向0后,主串指针要+1,而这里是ifelse,没有第三种处理情况：pindex=next[pindex],Pindex++
            // 所以为了方便,将pindex移向0,执行两次++
            pindex = next[pindex];
        }
    }
    if (pindex > pattern.length)
    {
        // 如果pindex成功移动到超过模式串的长度,说明成功
        cout << "success" << endl;
        return true;
    }
    else
    {
        cout << "false" << endl;
        return false;
    }
}

int main()
{
    SString Parent;
    SString pattern;
    string text = "ababbbaababaa";
    string Sub = "ababaa";
    int next[15] = {6, 0, 1, 1, 2, 3, 4};
    int nextval[15];
    Init(Parent);
    Init(pattern);
    StrAssign(Parent, text);
    StrAssign(pattern, Sub);
    Optimize(next, nextval, pattern);
    KMP(Parent, pattern, nextval);
}