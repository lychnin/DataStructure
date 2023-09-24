#include <iostream>
using namespace std;
#define MaxSize 50
typedef struct StringNode
{
    char *data;
    int length;
} SString;

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
    cout << "success" << endl;
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
    cout << "Destroying……" << endl;
    free(S.data);
}

// S1和S2连接成T
bool Concat(SString &T, SString S1, SString S2)
{
}
// 求子串
bool SubString(SString &Sub, SString S, int pos, int len) {}

// 串的比较
int StrCompare(SString S, SString T)
{
}

// 找到子串在母串中的位置
int Index(SString S, SString T)
{
}
int main()
{
    string s = "hello";
    cout << s[0];
}