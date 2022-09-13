#include <iostream>
using namespace std;

int main(){
    int n1 = 10, n2 = 9;
    char ch;
    cout<<"To mul and div by 2\n";
    cout<<"Mul 10 by 2: "<< (n1<<1)<<"\n";
    cout<<"Div 10 by 2: "<< (n1>>1)<<"\n";

    cout<<"\nCheck odd even\nIf "<<n2<<" is odd/even\n";
    (n2 & 1)? cout<<"Odd\n" : cout<<"Even\n";

    cout<<"Enter Uppercase char: ";
    cin>>ch;
    ch |= ' ';
    cout<<"Making it lowercase: "<<ch<<"\n";

    cout<<"Enter lowercase char: ";
    cin>>ch;
    ch &= '_';
    cout<<"Making it uppercase: "<<ch<<"\n";

}
