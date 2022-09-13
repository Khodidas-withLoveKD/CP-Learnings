/******************************************
* AUTHOR : KHODIDAS CHAUHAN*
* NICK : with_Love_KD *
* INSTITUTION : NIRMA UNIVERSITY *
******************************************/

#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std; 

ll n, num, ans, curr, b, e;
vector<ll> nums;
ll findInArr(ll temp){
    for(ll i=0; i < nums.size(); i++)
        if(nums[i] == temp)
            return i;
    return 10;
}
void solve() 
{ 
    nums.clear();
    ans = curr = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        nums.pb(num);
    }

    for( b=0, e=n-1; b != e;){
        if(nums[b] <= nums[e]){
            if(curr <= nums[b]){
                curr = nums[b];
                b++;
            }
            else{
                ans = findInArr(curr) + 1;
                curr = nums[b];
                b++;
            }
        }
        else if(nums[e] < nums[b]){
            if(curr <= nums[e]){
                curr = nums[e];
                e--;
            }
            else if(curr <= nums[b]){
                curr = nums[b];
                b++;
            }
            else{
                ans = findInArr(curr) + 1;
                curr = nums[b];
                b++;
            }
            /*else if(curr < nums[b]){
                ans = b + 1;
                curr = nums[b];
                b++;
            }
            else{
                ans = findInArr(curr) + 1;
                curr = nums[e];
                e--;
            }*/
        }
    }
    cout<<ans;
} 
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

   #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
    #endif
    
    
    ll t=1; 
    cin>>t; 
    while(t--) 
    { 
        solve(); 
        cout<<"\n"; 
    } 

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
return 0; 
} 
