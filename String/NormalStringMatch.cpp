#include <iostream>
using namespace std;
#define MaxSize 20
typedef struct String
{
    char *data;
    int length;

} SString;

void Init(SString &S)
{
    S.data = (char *)malloc(MaxSize * sizeof(char));
    S.length = 0;
    cout << "init……" << endl;
}
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
int Match(SString Parent, SString Sub)
{
    if (Parent.length < Sub.length)
    {
        cout << "parent is shorter than sub." << endl;
        return 0;
    }
    int i = 1;
    int j = 1;
    while (i <= Parent.length && j <= Sub.length)
    {
        if (Parent.data[i] == Sub.data[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    // 只有子串的索引大于子串的长度时才能说明匹配成功,
    // 如果没有匹配成功主串的索引也可以大于主串的长度
    if (j > Sub.length)
    {
        // i减去Sub.length为这次匹配的起始位置
        return i - Sub.length;
    }
    else
    {
        //
        return 0;
    }
}
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

int main()
{
    string text = "Winter is coming.";
    string pattern = "com";
    SString Parent;
    SString Sub;
    Init(Parent);
    Init(Sub);
    StrAssign(Parent, text);
    StrAssign(Sub, pattern);
    int index = Match(Parent, Sub);
    cout << "index:" << index << endl;
}