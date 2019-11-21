//#pragma once // Prevent redefining

class Node{
public:
    int Data;
    Node* pNext;
    void PrintNode(); //Print single node. Easy testing.
};

class SingleList{
public:
    SingleList(); //Constructor
    ~SingleList(); //Destructor
    void InitialList(); //Clear the list
    bool IsEmpty();
    int GetLength();
    bool Push(int n);
    void TraverseList();
    void Reverse();
private:
    Node* h_p;
    int length;
};