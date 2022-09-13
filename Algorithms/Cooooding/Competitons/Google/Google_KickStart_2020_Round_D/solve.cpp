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
#define endl "\n"
using namespace std; 

int findDist(int i, int j, int N){
    int dist1, dist2;

    dist1 = j-i;
    dist2 = N-j + i;

    return min(dist1, dist2);
}

void solve() 
{   
    ll n, x, N, ans = INT_MAX;
    vector <int> nums;
    cin >> n >> N;

    for(int i=0; i<n; i++){
        cin >> x;
        nums.pb(x);
    }
    sort(nums.begin(), nums.end());
    //create a 2D matrix
    int table[n][n];
    ll sum[n];

    memset(sum, 0 ,sizeof(sum));
    
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i == j)
                table[i][j] = 0;
            else
                table[i][j] = table[j][i] = findDist(nums[i], nums[j], N);
            sum[i] += table[i][j];
            sum[j] += table[j][i];
        }
        cout<<"sum["<<nums[i]<<"] = "<<sum[i]<<endl;
        ans = min(ans, sum[i]);
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

    ll t;
    ll Case = 1;
    cin>>t; 
    while(t--) 
    { 
        //solve(); 
        cout<<"Case #"<<Case++<<": ";
         solve(); cout<<endl;//ans <<"\n"; 
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
return 0; 
}   