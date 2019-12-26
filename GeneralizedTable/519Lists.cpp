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