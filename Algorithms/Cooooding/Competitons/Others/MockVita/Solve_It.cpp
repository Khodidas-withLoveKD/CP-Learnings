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

int N, num, noOfPairs = 0, ans = 0;
vector<int> bitScore;
unordered_map<int, int> hasOddIndex, hasEvenIndex;

void extractBitScore(int temp){
	vector<int> nums;
	int digit;
	while(temp > 0){
		digit = temp % 10;
		nums.pb(digit);
		temp /= 10;
	}
	digit = (*min_element(nums.begin(), nums.end()) * 7) + (*max_element(nums.begin(), nums.end()) * 11);
	string str = to_string(digit);

	if(str.length() > 2)
		digit = digit % 100;

	bitScore.pb(digit);
}
void solve() 
{ 
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> num; cin.ignore();
		extractBitScore(num);
	}
	unordered_map<int,int> :: iterator it;
	for(int i=0; i<N; i++){
		//most significant digit
		int signi = bitScore[i] / 10;
		int oddEven = i%2;		//0 for even, 1 for odd
		if(oddEven == 0){	//even
			it = hasEvenIndex.find(signi);
			if(it != hasEvenIndex.end()){
				if(it->S < 2){
					it->S++;
					ans++;
				}
			}
			else{	//not found insert
				hasEvenIndex.insert(mp(signi, 0));
			}
		}
		else if(oddEven == 1){	//odd
			it = hasOddIndex.find(signi);
			if(it != hasOddIndex.end()){
				if(it->S < 2){
					it->S++;
					ans++;
				}
			}
			else{	//not found insert
				hasOddIndex.insert(mp(signi, 0));
			}
		}
	}
	cout<<ans;

} 
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
/*
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
    #endif 
*/
    int t=1; 
    ///*is Single Test case?*/
    //cin>>t; 
    while(t--) 
    { 
        solve(); 
        cout<<"\n"; 
    } 

    //cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
return 0; 
} 
