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