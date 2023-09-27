#include <iostream>
using namespace std;
#define MaxSize 50
// 这里弃用索引位置为0
typedef struct StringNode
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

// 复制操作
bool StrCopy(SString &target, SString origin)
{
    if (origin.length == 0)
    {
        cout << "Empty String " << endl;
        return false;
    }
    int i = 0;
    while (i <= origin.length)
    {
        target.data[i] = origin.data[i];
        i++;
    }
    target.length = origin.length;
    Print(target);
    return true;
}
// 判空操作
bool StrEmpty(SString S)
{
    if (S.length == 0)
    {
        cout << "Empty……" << endl;
        return true;
    }
    return false;
}
int StrLength(SString S)
{
    cout << "Length:" << S.length << endl;
    return S.length;
}
bool ClearString(SString &S)
{
    S.length = 0;
    return true;
}
bool DestroyString(SString &S)
{
    S.length = 0;
    free(S.data);
    cout << "Destroying……" << endl;
    return true;
}

// S1和S2连接成T
bool Concat(SString &T, SString S1, SString S2)
{
    T.length = S1.length + S2.length;
    T.data = (char *)malloc(2 * MaxSize * sizeof(char));
    int index = 1;
    while (index <= S1.length)
    {
        T.data[index] = S1.data[index];
        index++;
    }
    int loc;
    loc = index;
    index = 1;
    while (index <= S1.length)
    {
        T.data[loc] = S1.data[index];
        index++;
        loc++;
    }
    Print(T);
    return true;
}
// 求子串
bool SubString(SString &Sub, SString S, int pos, int len)
{
    if (S.length == 0)
    {
        cout << "the string is enpty." << endl;
        return false;
    }
    Sub.data = (char *)malloc(MaxSize * sizeof(char));
    int index = 0;
    while (index < len)
    {
        Sub.data[1 + index] = S.data[pos];
        index++;
        pos++;
    }
    Sub.length = len;
    Print(Sub);
    return true;
}

// 串的比较
int StrCompare(SString S, SString T)
{
    int index = 1;
    while (index <= min(S.length, T.length))
    {
        if (S.data[index] != T.data[index])
        {
            if (S.data[index] - T.data[index] > 0)
            {
                cout << "the string is bigger" << endl;
            }
            else
            {
                cout << "the string is smaller" << endl;
            }

            return S.data[index] - T.data[index];
        }
        index++;
    }
    // S为基准串,比S长就是负数,比S短就是正数
    if (S.length - T.length > 0)
    {
        cout << "the string is bigger" << endl;
    }
    if (S.length - T.length < 0)

    {
        cout << "the string is smaller" << endl;
    }
    if (S.length - T.length == 0)
    {
        cout << "the string is equal" << endl;
    }

    return S.length - T.length;
}

// 找到子串在母串中的位置
int Index(SString S, SString Sub)
{
    int len = StrLength(Sub);
    int n = StrLength(S);
    int index = 1;
    // 从第一个字母开始依次比较len长度的子串
    while (index < n - len + 1)
    {
        SString SSub;
        SubString(SSub, S, index, len);
        if (StrCompare(Sub, SSub) == 0)
        {
            Print(SSub);
            cout << "Sub is index:" << index << endl;
            return index;
        }
        index++;
    }
    cout << "sub is not in string" << endl;
    return 0;
}

int main()
{
    SString S, target, T, Sub;
    string value = "this a text.";
    Init(S);
    Init(target);
    Init(Sub);
    StrAssign(S, value);
    StrEmpty(target);
    StrCopy(target, S);
    StrEmpty(target);
    Concat(T, target, S);
    SubString(Sub, T, 5, 3);
    StrCompare(S, target);
    StrCompare(S, T);
    Index(S, Sub);
    ClearString(S);
    DestroyString(S);
}