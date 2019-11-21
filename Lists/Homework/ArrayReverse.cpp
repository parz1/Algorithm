#include<cstdlib>
#include<ctime>
#include<iostream>
#define ARRAY_MAX_LENGTH 10 // Easy to check
#define _for(i,a,b) for(int i=a;i<b;i+=1)
void swap(int& x, int& y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
int main() {
    int arr[ARRAY_MAX_LENGTH];
    srand((unsigned)time(NULL));
    _for(i,0,ARRAY_MAX_LENGTH) {
        arr[i] = rand()%10; // Mod 10 for easy checking.
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    // Swap
    _for(i,0,(ARRAY_MAX_LENGTH-1)/2) {
        swap(arr[i],arr[ARRAY_MAX_LENGTH-1-i]);
    }
    _for(i,0,ARRAY_MAX_LENGTH) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}

/* 0 1 2 3 4 5 6 7 */