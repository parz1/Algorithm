#include"SingleList.h"
#include<iostream>

void Node::PrintNode(){
    std::cout<<Data<<' ';
}

SingleList::SingleList(){
    h_p = new Node;
    h_p->Data = 9;
    h_p->pNext = NULL;
    length = 0;
}

SingleList::~SingleList(){
    InitialList();
    delete h_p;
}

bool SingleList::IsEmpty(){
    return length==0?true:false;
}

int SingleList::GetLength(){
    return length;
}

void SingleList::InitialList(){
    Node* p_current = h_p->pNext;
    while(p_current!=NULL){
        Node* p_t = p_current->pNext;
        delete p_current;
        p_current = p_t;
    }
    length = 0;
    h_p->pNext = NULL;
}

void SingleList::TraverseList(){
    Node* p_current = h_p->pNext;
    while(p_current!=NULL){
        p_current->PrintNode();
        p_current = p_current->pNext;
    }
}

bool SingleList::Push(int n){
    Node* pNewNode = new Node;
    if(!pNewNode) return false;
    pNewNode->Data=n;
    pNewNode->pNext=h_p->pNext;
    h_p->pNext=pNewNode;
    return true;
}

void SingleList::Reverse(){
    Node* p_current = h_p->pNext;
    while(p_current!=NULL){
        Node* p_n = p_current->pNext;
        Node* p_t = p_n->pNext;
        p_n->pNext=p_current;
        h_p->pNext = p_n;
        p_current->pNext = p_t;
        p_current = p_t;
    }
}