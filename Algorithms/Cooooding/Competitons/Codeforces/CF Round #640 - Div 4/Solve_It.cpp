#include <bits/stdc++.h>
#define ll long long
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b) 

using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
	
	ll test;
	cin>>test; cin.ignore();

	while(test--){

		vector <ll> candies;int flag=0;
		ll n,val,turn=0,move=0,bobTotal=0,aliceTotal=0,bobCan=0,aliceCan=0,currentCan=0,alice,bob;
		cin>>n; cin.ignore();

		while(n--){
			cin>>val;
			candies.pb(val);
		}
		alice = 0;
		bob = candies.size() - 1;
		 // 1for alice and 0 for bob

		while(1){
			turn = 1 - turn; 
			cout<<"Turn = "<<turn<<endl;
		if(turn == 1){
			aliceCan = 0;
			//cout<<"Inside alice"<<endl;
			if(alice == 0 ){
				aliceCan += candies[alice++];
				move++;
				currentCan = aliceCan;
				aliceTotal += aliceCan;

					cout<<"AliceCAn = "<<aliceCan<<endl;

				cout<<"InsideIF"<<endl;
				continue;
			}
			while(aliceCan < currentCan && bob > alice){
					aliceCan += candies[alice++];
					//cout<<"AliceCAn = "<<aliceCan<<endl;
				}
				if(aliceCan > currentCan){
					move++;
					currentCan = aliceCan;
					cout<<"AliceCAn = "<<aliceCan<<endl;
					aliceTotal += aliceCan;
				}
				else{
					flag =1;
					break;
				}
		}
		else{
			//cout<<"Inside BOB"<<endl;
			bobCan = 0;
				while(bobCan < currentCan && bob > alice){
					bobCan += candies[bob--];
					//cout<<"BObCAn = "<<bobCan<<endl;
				}
				if(bobCan > currentCan){
					move++;
					currentCan = bobCan;
					cout<<"BObCAn = "<<bobCan<<endl;
				
					bobTotal += bobCan;
				}
				else{
					flag= 1;
					break;
				}
		}
	}
	if(flag == 1)
		move++;
	cout<<move<<' '<<aliceTotal<<' '<<bobTotal<<endl;	
   } 
}
