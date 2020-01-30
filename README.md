# 数据结构

Homework

**2-25**

```c++
/*
假设以两个元素依值递增有序排列的线性表A和B分别表示两个集合
（即同一表中的元素值各不相同），现要求另辟空间构成一个线性表
C，其元素为A和B中元素的交集，且表C中的元素也依值递增有序排列。试对顺序表编写求C的算法。
*/
#include <iostream>
using namespace std;

void algorithm(list a, list b, list *c)
{
    int i, j, k;
    i = j = 0;
    k = 1;
    while (i < a.length && j < b.length)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if(a[i]>b[j])
        {
            j++;
        }
        else
        {
            lc.push(k);
            k++;
            i++;
            j++;
        }
        
    }
}
```

**2-27 (1)**

```c++
/*
2-27 (1)
*/

#include <iostream>
using namespace std;

void algorithm(list a, list b, list *c)
{
    int i, j;
    i = j = 0;
    while (i < a.length && j < b.length)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            if (!i || a[i] != b[j])
            {
                lc.push(a[i]);
            }
            i++;
            j++;
        }
    }
}
```

**2-29** 逆置

顺序表逆置

```c++
#include<cstdlib>
#include<ctime>
#include<iostream>
#define ARRAY_MAX_LENGTH 10 // Easy to check
#define _for(i,a,b) for(int i=a;i<b;i+=1)
void swap(int& x, int& y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
int main() {
    int arr[ARRAY_MAX_LENGTH];
    srand((unsigned)time(NULL));
    _for(i,0,ARRAY_MAX_LENGTH) {
        arr[i] = rand()%10; // Mod 10 for easy checking.
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    // Swap
    _for(i,0,(ARRAY_MAX_LENGTH-1)/2) {
        swap(arr[i],arr[ARRAY_MAX_LENGTH-1-i]);
    }
    _for(i,0,ARRAY_MAX_LENGTH) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}

/* 0 1 2 3 4 5 6 7 */
```

单链表逆置

核心代码部分：Lists\Homework\SingleList.cpp

```
void SingleList::Reverse(){
    Node* p_current = h_p->pNext;
    while(p_current!=NULL){
        Node* p_n = p_current->pNext;
        Node* p_t = p_n->pNext;
        p_n->pNext=p_current;
        h_p->pNext = p_n;
        p_current->pNext = p_t;
        p_current = p_t;
    }
}
```

**3-10** 求非递归版本

```c++
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
```

**运行**

```
projects\Algorithm\Dp\Homework>a
1 2 3 4 5 6 7 0
7654321
```

**3-24&25** 

```c++
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
```



**3-27**

```c++
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
```



**4-11&19** 求得所有包含在串s中而不包含在串t中的字符（s中重复的字符只选一个）构成的新串r，以及r中每个字符在s中第一次出现的位置 

String/Homework/411String.cpp

```c++
#include <iostream>
#include <string>
#include <cstdio>
#include <list>
using namespace std;

typedef list<char> LISTCHAR;
typedef list<int> LISTINT;

int main()
{
    string s, t;
    cin >> s >> t;
    LISTCHAR ans;
    LISTINT pos;
    for (int i = 0; i < s.length(); i++)
    {
        int flag = 0;
        for (int j = 0; j < t.length(); j++)
        {
            if (s[i] == t[j])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            ans.push_back(s[i]);
            pos.push_back(i);
        }
    }
    LISTCHAR::iterator i = ans.begin();
    LISTINT::iterator j = pos.begin();
    for (; i != ans.end(); i++, j++)
    {
        cout << *i << " in pos - ";
        cout << *j << endl;
    }
    return 0;
}
```

结果:

```
projects\Algorithm\String\Homework>a
abcdefg
abcghik
d in pos - 3
e in pos - 4
f in pos - 5
```



**4-20** 从串s中删除所有和串t相同的字串

```c++
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
```

**运行**

```
projects\Algorithm\String\Homework>a
ORIGIN:abcde
TARGET:cd
ANSWER:abe
```

**4-28**  假设以结点大小为1（带头结点）的链表结构表示串，则在利用next函数值进行串匹配时，在每个结点中需设三个域：数据域chdata、指针域succ和指针域next。其中chdata域存放一个字符；succ域存放指向同一链表中后继结点的指针；next域在主串中存放指向同一链表中前驱结点的指针；在模式串中，存放指向当该结点的字符与主串中的字符不等时，在模式串中下一个应进行比较的字符结点（即与该字符的next函数值相对应的字符结点）的指针，若该节点字符的next函数值为0，则其next域的值应指向头结点。试按上述定义的结构改写求模式串的next函数值的算法.。

**4-29**  试按4.28题定义的结构改写串匹配的改进算法（KMP算法）。

4-28 核心代码片段 改进后next函数

```c++
void iString::next()
{
    strNode *i, *j;
    i = head->succ;
    j = head;

    i->next = head; //First one unmatch

    while (i)
    {
        if (j == head || i->chdata == j->chdata) //j处于头或两个指针指向的值相同
        {
            //向后移一位
            i = i->succ;
            j = j->succ;
            if (i)
                i->next = j;
        }
        else
        {
            j = head;
        }
    }
}
```

4-29 核心代码片段 改进后KMP代码

```c++
int iString::kmpSearch(iString *t)
{
    int counter = 0;
    strNode *i = head, *j = t->headp();
    strNode *p, *k;
    while (i && j)
    {
        if (j == t->headp() || i->chdata == j->chdata)
        {
            i = i->succ;
            j = j->succ;
        }
        else
        {
            j = j->next;
            if (j == t->headp())
            {
                //std::cout << "match again!" << std::endl;
                p = i;
            }
        }
    }
    counter = 0;
    if (!j)
    {
        for (k = head; k != p; k = k->succ, counter++)
            ;
        //std::cout << "YES" << std::endl;
        return counter;
    }
    // else
    // {
    //     std::cout << "NO" << std::endl;
    // }
    return 0;
}
```



### 运行

```
g++ KMP.h KMP.cpp main.cpp
./a.exe

/*		//sample
INPUT ORIGIN STRING: ABABCDEFCDFFFFF
INPUT STRING TO SEARCH: CDEFCDF
ORIGIN VAL ARR: ABABCDEFCDFFFFF
ORIGIN VAL ARR: CDEFCDF
  NEXT VAL ARR: CDDDDEF
4
*/
```





**5-19** 

```
#include <iostream>
#define M 255
using namespace std;

class node
{
    int x;
    int y;
    int v;
};

int main()
{
    node p[M];
    int row = 4, col = 4;
    int a[M][M] = {
        {1, 2, 1, 4},
        {-1, 6, -5, 2},
        {-2, 7, 0, 1},
        {1, 2, 1, 3}};
    int k;
    p[0].v = 0;
    node min[M];
    for (int i = 0; i < row; i++)
    {
        minRow(a, col, i, min);
        for (int k = 1; k <= min[0]; k++)
        {
            if (isColMax(a, row, min[k]))
            {
                p[0].v++;
                p[p[0].v] = min[k];
            }
        }
    }
    if (p[0].v)
    {
        return true;
    }
    else
    {
        return false;
    }

    return 0;
}
```

