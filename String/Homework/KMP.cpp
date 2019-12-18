#include "KMP.h"
#include <iostream>
#include <cstring>

iString::iString()
{
    head = new strNode;
    head->chdata = '*';
    head->next = NULL;
    head->succ = NULL;
}

iString::~iString()
{
    delete head;
}

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
            //j = j->next; //j置零？
            j = head;
        }
    }
}

bool iString::assign(char *s)
{
    head = (strNode *)malloc(sizeof(strNode));
    if (!head)
    {
        return false;
    }
    head->succ = head->next = NULL;

    strNode *prevNode = (strNode *)malloc(sizeof(strNode));
    if (!prevNode)
        return false;
    head->succ = prevNode;
    prevNode->chdata = s[0];
    prevNode->next = head;

    for (int i = 1; i < strlen(s); i++)
    {
        strNode *node = (strNode *)malloc(sizeof(strNode));
        if (!node)
            return false;
        prevNode->succ = node;
        node->chdata = s[i];
        node->succ = NULL;
        node->next = head;
        prevNode = node;
    }
    return true;
}

void iString::print()
{
    strNode *p = head;
    std::cout << "ORIGIN VAL ARR: ";
    while (p->succ)
    {
        p = p->succ;
        std::cout << p->chdata;
    }
    std::cout << std::endl;
}

void iString::printNext()
{
    strNode *p = head;
    std::cout << "  NEXT VAL ARR: ";
    while (p->succ)
    {
        p = p->succ;
        std::cout << p->next->chdata;
    }
    std::cout << std::endl;
}