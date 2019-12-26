#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
typedef stack<int> STACKINT;

//3-10 改写递归程序
void test3_10()
{
    STACKINT s;
    int x;
    while (cin >> x)
    {
        if (!x)
        {
            //
            while (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            break;
        }
        s.push(x);
    }
}

//3-24 编写g(m,n)的递归算法
int g(int m, int n)
{
    if (!m && n >= 0)
    {
        return 0;
    }
    return g(m - 1, 2 * n) + n;
}

//3-25 试写出递归函数F(n)的递归算法，并消除递归
int f(int n)
{
    if (!n)
        return 1;
    return n * f(n / 2);
}

//3-27 Ackerman
int akm(int m, int n)
{
    if (!m)
        return n + 1;
    if (!n)
    {
        return akm(m - 1, 1);
    }
    return akm(m - 1, akm(m, n - 1));
}

int main()
{
    test3_10();
    return 0;
}