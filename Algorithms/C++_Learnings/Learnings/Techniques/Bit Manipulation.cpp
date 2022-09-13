#include <iostream>
using namespace std;

int main(){

    int a = 1, b = 2;

    cout<<"a&b = "<<(a&b)<<"\n";
    cout<<"a|b = "<<(a|b)<<"\n";
    cout<<"a^b = "<<(a^b)<<"\n";
    cout<<"~a = "<<(~a)<<"\n";
    cout<<"~(a^b) = "<<(~(a^b))<<"\n";
    cout<<"a<<1 = "<< (a<<1) <<"\n";
    cout<<"a>>b = "<< (a>>1) <<"\n";
}
