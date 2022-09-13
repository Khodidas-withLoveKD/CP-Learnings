#include <bits/stdc++.h>
#define ll long long
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b) 

using namespace std;


int main()
{
    /*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
	*/
    ll test;

    cin>>test;

    while(test--){

   		ll n,k,val,p=1,max_counter=0,lowest;
   		vector <ll> peak,moun;
   		
   		cin>>n>>k; cin.ignore();
   		while(n--){
   			cin>>val;
   			moun.pb(val);
   		}

   		for(int i=1; i<moun.size()-1; i++){
   			if(moun[i]>moun[i-1] && moun[i] > moun[i+1]){
   				peak.pb(i);
   				//p++;
   			}
   		}

   		ll low,high,counter=0,max_peak=0;
   		for(int i=0; i < peak.size(); i++){
   			counter=0;
   			low=peak[i]-1;
   			high = low + k - 1;
   			if(high >= moun.size())
   				high = moun.size() -1;
   			for(int j = i; peak[j] > low && peak[j] < high && j<peak.size();j++)
   				counter++;
   			if(counter > max_counter){
   				max_counter = counter;
   				max_peak=i;
   				lowest = low;
   			}
   		}
   		counter=max_counter;
   		if(lowest != 0 ){
   			low = lowest;
   			while(counter == max_counter && (--low) >= 0){
   				counter=0;
   				//low--;
   				high = low + k - 1;
   				for (int j = max_peak; peak[j] > low && peak[j] < high && j<peak.size();j++ )
   					counter++;
   				if(counter == max_counter)
   					lowest = low;	
   			}
   				
   		}
   		
   		cout<<max_counter+1<<' '<<lowest+1<<endl;
	}	
    
}
