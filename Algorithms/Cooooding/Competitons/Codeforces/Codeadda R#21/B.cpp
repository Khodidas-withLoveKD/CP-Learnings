#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

int main()
{
    ll n,k,mins=0,noOfSteaks=0,total=0,steaks_used=0;

    cin>>n>>k; cin.ignore();
    vector<int> steak;

    for(int i=1;i<n;i++)
        steak.push_back(i);

    for(int i=1;i<=steak.size();i++)
        steak[i]=0;

    while(total<(2*n))
    {
        cout<<"Inside While"<<endl;
        for(int i=1;noOfSteaks<(2*k) && steaks_used<n;i++)
        {
            cout<<"Inside For"<<endl;
            if(steak[i]==0)
                {
                    steak[i]=1;
                    total++;
                    noOfSteaks++;
                    steaks_used++;
                }
            else if(steak[i]==1)
                 {
                     steak[i]=2;
                     total++;
                     noOfSteaks++;
                     steaks_used++;
                 }
            else if(steak[i]==2)
                steak[i]=3;

            if(i==steak.size())
                i=1;
        }
        noOfSteaks=0;
        steaks_used=0;
        mins++;
    }

    cout<<5*mins;


}

