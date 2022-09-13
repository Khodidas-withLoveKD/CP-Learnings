#include <iostream>
#include <string>
using namespace std;

string str, printString(){
    str = "My name is Khan";
    return &str;
}
int main(){
    cout<<"Some string = "<<printString()<<"\n";
}
