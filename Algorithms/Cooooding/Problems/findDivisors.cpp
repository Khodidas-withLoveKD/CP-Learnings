#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void findDivisors(int n, vector<int> &ans){
    int i;
    for(i=1; i<ceil(sqrt(n)); ++i){
        if(n%i == 0){
            ans.push_back(i);
            ans.push_back(n/i);
        }
    }
    if(i*i == n && n%i == 0)
        ans.push_back(i);

    sort(ans.begin(), ans.end());
}
int main(){
    int n;
    cout<<"Give number: ";
    cin>>n;

    vector<int> ans;
    findDivisors(n, ans);
    cout<<"Divisors are ="<<endl;
    for(int x : ans)
        cout<<x<<" ";
}
