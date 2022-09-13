#include <iostream>

using namespace std;

void add(int a, int b, int *ans){
    *ans=(a+b);
}
int main()
{
    int ans;
    add(1,2,&ans);
    cout<< ans;
}
