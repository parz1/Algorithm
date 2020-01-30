#include <string>
#define M 100

class codeNode
{
public:
    char ch;
    char bits[9];
    int len;
};
class treeNode
{
public:
    int w, lchild, rchild, parent;
};
class Huffman
{
public:
    void Initialize();
    void Encoding();
    void Decoding(char[]);
    void Coding(char[],char[]);
    void Print();

private:
    void huffmanSelect(int k, int &s1, int &s2);
    void createHuffmanTree(int cnt[], char str[]);
    codeNode HuffmanCode[M];
    treeNode HuffmanTree[M];
    int length;
};