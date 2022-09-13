#include <iostream>

using namespace std;

void swapper (int &x,int &y){

    int temp = x;
    x = y;
    y =temp;
}

int main()
{
        int a=5,b=10;
        cout<<"Before swapping\na = "<<a<<" | b = "<<b<<endl;
        swapper(a,b);
        cout<<"After swapping\na = "<<a<<" | b = "<<b<<endl;
}
