#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long;
using namespace std;

ll n,x,steps;
int val, *maxi,pt1;
vector<int> a;

void check_max()
{
    for(int i=0;i<a.size(); i++)
            if(a[i]==maxi)
              {
                  if(steps==1)
                  {
                      x-=maxi;
                      steps++;
                      a[i]=0;
                      pt2=i;
                  }
                  else if(steps==0)
                  {
                      x-=maxi;
                      a[i]=0;
                      pt1=i;
                      steps++;

                  }
                  else
                  {
                      if(i)
                  }
             }

}

int main()
{
  cin>>n>>x; cin.ignore();

    for(int i=0;i<n;i++)
    {
        cin>>val;
        a.push_back(val);
    }

    while(x>0)
    {
      maxi=max_element(a.begin(),a.end());

      check_max();

    }
}
