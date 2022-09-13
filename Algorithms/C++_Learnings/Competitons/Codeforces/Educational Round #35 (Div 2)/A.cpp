#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

 int test,n;
 ll x,val,maxi,counter,arr[100000],avg,ind;

 vector<int> index;

 cin>>test; cin.ignore();

 while(test--){
 	cin>>n>>x; cin.ignore();
 	counter=0;
 	avg=0;
 	memset(arr,'\0',sizeof(arr));
 	index.clear();

 	for(int i=0;i<n;i++){
 		cin>>arr[i];
 	}
 	/*if(x==1){
 		cout<<n<<endl;
 		break;
 	}*/
 	for(int j=0;j<n;j++){
 		maxi=0;
 		for(int i=0;i<n;i++){
 			if(arr[i]>maxi){
 				maxi=arr[i];
 				ind=i;
 			}
 		}
 		//maxi=max_element(arr,arr+n);
	 		index.push_back(maxi);
	 		arr[ind]=0;
	 		//calclulatea
	 		avg=0;
	 		for(int i=0;i<index.size();i++)
	 			avg+=index[i];
	 		avg=avg/index.size();
	 		if(avg>=x)
	 			counter++;
	 		else break;
	 	/*for(int i=0;i<n;i++){
	 		if(arr[i]==*maxi){
	 			arr[i]=0;
	 			break;
	 		}
	 	}*/
 	}
 
 	cout<<counter<<endl;
	}
}
