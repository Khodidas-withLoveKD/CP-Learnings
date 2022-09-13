#include<iostream>

using namespace std;

int flag=-1;
long long int l,r;
int main()
{
    cin>>l>>r; cin.ignore();

        if(l%2==0 && l+2<=r)
            cout<<l<<" "<<l+1<<" "<<l+2;
        else
        {
            l++;
            if(l%2==0 && l+2<=r)
               cout<<l<<" "<<l+1<<" "<<l+2;
            else
                cout<<"-1";
        }

}
