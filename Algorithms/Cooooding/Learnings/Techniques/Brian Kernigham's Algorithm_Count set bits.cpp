#include <iostream>
using namespace std;

int countSetBits(int n){
    //Brian Kernigham's Algorithm
    int counter = 0;
    while(n){
        counter++;
        n &= (n-1);
    }
    return counter;
}

int main(){

    cout<<"set bits of 10 are:\nUsing Brian Kernigham's Algo = "<<countSetBits(10);
    cout<<"\nUsing __builtin_popcount(n) = "<<__builtin_popcount(10);
}
