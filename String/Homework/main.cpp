#include "KMP.h"
#include <iostream>
int main()
{
    iString str, mstr;
    char s[20],m[20];
    std::cout << "INPUT ORIGIN STRING: ";
    std::cin >> s;
    std::cout << "INPUT STRING TO SEARCH: ";
    std::cin >> m;
    str.assign(s);
    mstr.assign(m);
    //str.next();
    mstr.next();
    str.print();
    //str.printNext();
    mstr.print();
    mstr.printNext();
    std::cout << str.kmpSearch(&mstr) << std::endl;
    return 0;
}