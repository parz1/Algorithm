#include "KMP.h"
#include <iostream>

iString::iString()
{
    head = new strNode;
    head->chdata = NULL;
    head->next = NULL;
    head->succ = NULL;
}

void iString::next()
{
    strNode *i, *j;
    i = head->succ;
    j = head;

    i = head; //First one unmatch
    while (i->succ)
    {
        if (j == head){
            i=i->succ;
            j=j->succ;
        }
    }
}