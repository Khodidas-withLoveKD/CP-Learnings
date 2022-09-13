#include <bits/stdc++.h>
#define ll long long
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b) 

using namespace std;


int main()
{
    /*
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
	*/
	ll test;
	cin>>test; cin.ignore();

	while(test--){
		ll N,count = 1, sum = 1, value;
		cin>>N; cin.ignore();

		while(sum < N){
			value = sum + 1;
			sum += value;
			count++;
		}
		cout<<count<<endl;
	}
}
