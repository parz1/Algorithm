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