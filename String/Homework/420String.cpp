#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void DelStr(char *, char *);
int main()
{
    char input[256] = {0};
    char del[20] = {0};
    cout << "ORIGIN:";
    cin >> input;
    cout << "TARGET:";
    cin >> del;
    if (del != 0)
    {
        DelStr(input, del);
    }
    cout << "ANSWER:" << input;
    return 0;
}
void DelStr(char *src, char *dst)
{
    char *p = src;
    char *q = dst;
    int dstLen;
    dstLen = strlen(dst);
    while (*src != EOF)
    {
        if (*q == '\0')
        {
            p -= dstLen;
            q = dst; //Q重新指向删除的字符
            continue;
        }
        else if (*src != *q)
        {
            q = dst;
        }
        else
        {
            ++q;
        }
        *p++ = *src++; //每次都用src来刷新p,如果p指针往回dstLen长度,匹配到的字符串会被覆盖掉
    }
    *p = '\0';
}