#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>

using namespace std;

#define n 100
#define m 2 * n - 1

typedef struct
{
    char ch;
    char bits[9];
    int len;
} CodeNode;

typedef CodeNode HuffmanCode[n + 1];
typedef struct
{
    int weight;
    int lchild, rchild, parent;
} HTNode;
typedef HTNode HuffmanTree[m + 1];
int num;

void select(HuffmanTree HT, int k, int &s1, int &s2) // 两节点选最小2个
{
    int i, j;
    int minl = 32767;
    for (i = 1; i <= k; i++)
    {
        if (HT[i].weight < minl && HT[i].parent == 0)
        {
            j = i;
            minl = HT[i].weight;
        }
    }
    s1 = j;
    minl = 32767;
    for (i = 1; i <= k; i++)
    {
        if (HT[i].weight < minl && HT[i].parent == 0 && i != s1)
        {
            j = i;
            minl = HT[i].weight;
        }
    }
    s2 = j;
}

int countAsc(char *s, int cnt[], char str[])
{
    char *p;
    int i, j, k = 0;
    int temp[257];
    for (i = 0; i < 257; i++)
    {
        temp[i] = 0;
    }
    for (p = s; *p != '\0'; p++)
    {
        temp[*p]++;
    }
    for (i = 0, j = 0; i <= 256; i++)
    {
        if (temp[i] != 0)
        {
            j++;
            str[j] = i;
            cnt[j] = temp[i];
        }
    }
    num = j;
    return j;
}

void createHuffmanTree(HuffmanTree &HT, HuffmanCode &HC, int cnt[], char str[])
{
    int i, s1, s2;
    for (i = 1; i <= 2 * num - 1; i++)
    {
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].parent = 0;
        HT[i].weight = 0;
    }
    for (i = 1; i <= num; i++)
    {
        HT[i].weight = cnt[i];
    }
    for (i = num + 1; i <= 2 * num - 1; i++)
    {
        select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    for (i = 1; i <= num; i++)
    {
        HC[i].ch = str[i];
    }
}

void huffmanencoding(HuffmanTree &HT, HuffmanCode &HC)
{
    int c, p, i;
    char cd[n];
    int start;
    cd[num] = '\0';
    for (i = 1; i <= num; i++)
    {
        start = num;
        c = i;
        while ((p = HT[c].parent) > 0)
        {
            start--;
            cd[start] = (HT[p].lchild == c) ? '0' : '1';
            c = p;
        }
        strcpy(HC[i].bits, &cd[start]);
        HC[i].len = num - start;
    }
}

void decode(HuffmanCode &HC, /*char receive[],*/ char s[])
{
    FILE *fp;
    fopen_s(&fp, "CodeFile.txt", "r");
    if (fp == NULL)
    {
        return;
    }
    char ch;
    int num = 0;
    while (ch = getc(fp) != EOF)
    {
        num++;
    }
    fclose(fp);

    ifstream in("CodeFile.txt");
    string line;
    char result[200];
    int z = 0;
    if (in)
    {
        while (!in.eof())
        {
            in >> ch;
            result[z] = ch;
            z++;
        }
    }
    else
    {
        cout << "ERR" << endl;
    }
    result[num] = '\0';

    cout << result << endl;
    in.close();

    char str[268];
    char cd[9];
    int i, j, k = 0, p = 0, flag;
    while (result[p] != '\0')
    {
        flag = 0;
        for (i = 0; i < num && flag == 0 && result[p] != '/0'; i++)
        {
            cd[i] = ' ';
            cd[i + 1] = '\0';
            cd[i] = result[p++];
            for (j = 1; j <= num; j++)
            {
                if (strcmp(HC[j].bits, cd) == 0)
                {
                    str[k] = HC[j].ch;
                    k++;
                    flag = 1;
                    break;
                }
            }
        }
    }
    str[k] = '\0';
    strcpy(s, str);
}

void coding(HuffmanCode &HC, char str[], char get[])
{
    int i, j = 0;
    while (str[j] != '\0')
    {
        for (i = 1; i <= num; i++)
        {
            if (HC[i].ch == str[j])
            {
                strcat(get, HC[i].bits);
                break;
            }
        }
        j++;
    }
    strcat(get, "\0");
    int len = sizeof(get) / sizeof(get[0]);
    //cout << "长度:"<<len << endl;
    FILE *fp;
    fopen_s(&fp, "CodeFile.txt", "w");
    fputs(get, fp);
    fclose(fp);
}

int main()
{
    char str[257];
    char st[10000], sresult[10000];
    int cn[257];
    HuffmanTree HT;
    HuffmanCode HC;
    printf("please input strings to CodeFile code:\n");
    scanf("%s", &st);
    num = countAsc(st, cn, str);
    str[num + 1] = '\0';
    createHuffmanTree(HT, HC, cn, str);
    huffmanencoding(HT, HC);
    printf("TOTAL %d WORDS: \n", num);
    for (int i = 1; i <= num; i++)
    {
        printf("TIMES OF %c IS %d, CODE : %s\n", HC[i].ch, cn[i], HC[i].bits);
    }
    char get[10000];
    get[0] = '\0';
    coding(HC, st, get);
    printf("HUFFMAN CODE : %s\n", get);
    printf("saved in CodeFile.txt...\n");
    decode(HC, sresult);
    printf("DECODED : %s\n", sresult);
    return 0;
}