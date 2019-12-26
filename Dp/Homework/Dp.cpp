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
int akm_dp(int m, int n)
{
    if (!m)
        return n + 1;
    if (!n)
    {
        return akm_dp(m - 1, 1);
    }
    return akm_dp(m - 1, akm_dp(m, n - 1));
}
//3-27 Ackerman 非递归
class node
{
public:
    int m;
    int n;
};
int akm_stack(int m, int n)
{
    stack<node> s;
    node e,e1,d;
    e.m=m;
    e.n=n;
    s.push(e);
    do{
        while(e.m) {
            while(e.n){
                e.n--;
                s.push(e);
            }
            e.m--;e.n=1;
        }
        if(s.size()>1) {
            e1.n=e.n;
            s.pop();
            e.m--;
            e.n=e1.n+1;
        }
    }while(s.size()!=1||e.m!=0);
    return e.n+1;
}
int main()
{
    test3_10();
    return 0;
}