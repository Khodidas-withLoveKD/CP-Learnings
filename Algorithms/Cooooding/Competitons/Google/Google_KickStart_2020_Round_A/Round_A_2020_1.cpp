#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

int main()
{
    ll N,B,counter;
    int test,val,case_no=0;


    cin>>test;

    while(test--)
    {
        vector<ll> house;
        cin>>N>>B; cin.ignore();
        counter=0;

        for(int i=0;i<N;i++)
        {
            cin>>val;
            house.push_back(val);
        }

        sort(house.begin(),house.end());

        for(int i=0;i<N && B>=0;i++)
        {
            if(house[i]<=B)
            {
                counter++;
                B-=house[i];
            }
            else
                break;
        }

        cout<<"Case #"<<(++case_no)<<": "<<counter<<endl;
    }
}
