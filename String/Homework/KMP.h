class strNode
{
public:
    char chdata;
    strNode *succ; //指向后继
    strNode *next; //主串中指向前驱 & 模式串中指向当前结点失配时，下一个应该比较的点
};

class iString
{
public:
    iString(){};  //Constructor
    ~iString(){}; //Destructor
private:
    strNode *head;
};
