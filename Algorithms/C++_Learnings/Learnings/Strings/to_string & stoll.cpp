#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    ll num = 9088767232;
    string ans="";

    ans = to_string(num) + "/" + to_string(num);
    cout<<ans<<endl;
    num = stoll(ans);
    cout<<"NUM = "<<num<<endl;
}
