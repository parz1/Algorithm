#include "Huffman.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#define MIN 100000
using namespace std;

void Huffman::Initialize()
{
    ifstream in("hfmTree.txt");
    int cnt[M];
    char str[M];
    if (in.is_open())
    {
        int i = 0;
        int n;
        in >> n;
        for (int i = 1; i <= n; i++)
        {
            in >> str[i] >> cnt[i];
        }
        length = n;
        createHuffmanTree(cnt, str);
        in.close();
    }
    else
    {
        ofstream out("hfmTree.txt", ofstream::out);
        int n;
        cin >> n;
        out << n << ' ';
        for (int i = 1; i <= n; i++)
        {
            cin >> str[i] >> cnt[i];
            out << str[i] << ' ' << cnt[i] << ' ';
        }
        length = n;
        createHuffmanTree(cnt, str);
        out.close();
    }
}

void Huffman::huffmanSelect(int k, int &s1, int &s2)
{
    int i, j, minl = MIN;
    for (i = 1; i <= k; i++)
    {
        if (HuffmanTree[i].w < minl && HuffmanTree[i].parent == 0)
        {
            j = i;
            minl = HuffmanTree[i].w;
        }
    }
    s1 = j;
    minl = MIN;
    for (i = 1; i <= k; i++)
    {
        if (HuffmanTree[i].w < minl && HuffmanTree[i].parent == 0 && i != s1)
        {
            j = i;
            minl = HuffmanTree[i].w;
        }
    }
    s2 = j;
}

void Huffman::createHuffmanTree(int cnt[], char str[])
{
    int i, s1, s2;
    //clear
    for (i = 1; i < length * 2; i++)
    {
        HuffmanTree[i].lchild = 0;
        HuffmanTree[i].rchild = 0;
        HuffmanTree[i].parent = 0;
        HuffmanTree[i].w = 0;
    }
    for (i = 1; i <= length; i++)
    {
        HuffmanTree[i].w = cnt[i];
    }
    for (i = length + 1; i < 2 * length; i++)
    {
        huffmanSelect(i - 1, s1, s2);
        //cout << s1 << ' ' << s2 << endl;
        HuffmanTree[s1].parent = i;
        HuffmanTree[s2].parent = i;
        HuffmanTree[i].lchild = s1;
        HuffmanTree[i].rchild = s2;
        HuffmanTree[i].w = HuffmanTree[s1].w + HuffmanTree[s2].w;
    }
    for (i = 1; i <= length; i++)
    {
        HuffmanCode[i].ch = str[i];
    }
}

void Huffman::Encoding()
{
    cout << "ENCODING" << endl;
    int c, p, i;
    char cd[M];
    int start;
    cd[length] = '\0';
    for (i = 1; i <= length; i++)
    {
        start = length;
        c = i;
        while (HuffmanTree[c].parent> 0)
        {
            start--;
            cd[start] = (HuffmanTree[p].lchild == c) ? '0' : '1';
            cout << cd[start] << endl;
            c=p;
        }
        strcpy(HuffmanCode[i].bits, &cd[start]);
        HuffmanCode[i].len = length - start;
    }
    cout << "CD: " << cd << endl;
}

void Huffman::Decoding(char s[])
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
        cout << "READ FILE ERR" << endl;
    }
    result[num] = '\0';
    cout << result << endl;
    in.close();

    char str[300];
    char cd[10];
    int i, j, k = 0, p = 0, flag;
    while (result[p] != '\0')
    {
        flag = 0;
        for (i = 0; i < num && flag == 0 && result[p != '\0']; i++)
        {
            cd[i] = ' ';
            cd[i + 1] = '\0';
            cd[i] = result[p]++;
            for (j = 1; j <= num; j++)
            {
                if (strcmp(HuffmanCode[j].bits, cd) == 0)
                {
                    str[k] = HuffmanCode[j].ch;
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

void Huffman::Coding(char str[], char get[])
{
    cout << "Coding" << endl;
    int i, j = 0;
    while (str[j] != '\0')
    {
        for (i = 1; i <= length; i++)
        {
            if (HuffmanCode[i].ch == str[j])
            {
                cout << HuffmanCode[i].bits << endl;
                strcat(get, HuffmanCode[i].bits);
                break;
            }
        }
        j++;
    }
    //strcat(get, '\0');
    int len = sizeof(get) / sizeof(get[0]);
    cout << len << endl;
    FILE *fp;
    fopen_s(&fp, "CodeFile.txt", "w");
    fputs(get, fp);
    fclose(fp);
};