#include <iostream>
#include <cmath>
using namespace std;

void findMSB(int n){
    cout<<"MSB = "<<(int)log2(n);
}

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;

    findMSB(n);
}
