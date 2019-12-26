/*
假设以两个元素依值递增有序排列的线性表A和B分别表示两个集合
（即同一表中的元素值各不相同），现要求另辟空间构成一个线性表
C，其元素为A和B中元素的交集，且表C中的元素也依值递增有序排列。试对顺序表编写求C的算法。
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
        else if(a[i]>b[j])
        {
            j++;
        }
        else
        {
            lc.push(a[i]);
            i++;
            j++;
        }
        
    }
}