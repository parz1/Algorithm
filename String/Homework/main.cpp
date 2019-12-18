#include "KMP.h"
#include <iostream>
int main()
{
    iString str;
    char s[20];
    std::cin >> s;
    str.assign(s);
    str.next();
    str.print();
    str.printNext();
    return 0;
}