# 数据结构-串

Homework

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

