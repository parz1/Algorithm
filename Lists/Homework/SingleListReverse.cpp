#include<iostream>
#include"SingleList.h"
#define LIST_MAX_LENGTH 10 // Easy to check
#define _for(i,a,b) for(int i=a;i<b;i+=1)

int main(){
    SingleList sgl;
    _for(i,0,LIST_MAX_LENGTH){
        sgl.Push(i);
    }
    sgl.TraverseList();
    return 0;
}