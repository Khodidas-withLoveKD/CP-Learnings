#include <iostream>
#include <algorithm>
using namespace std;

int euclideanGcd(int a, int b){
    cout<<" a = "<<a<<" b = "<<b<<"\n";
    if(a == 0)
        return b;
    return euclideanGcd(b%a ,a);
}
int main(){
    cout<<"gcd(6,20) using inbuilt function = "<<__gcd(6,20)<<"\n";


    cout<<"gcd(6,20) using Euclidean Algorithm = "<<euclideanGcd(6,20)<<"\n";

}
