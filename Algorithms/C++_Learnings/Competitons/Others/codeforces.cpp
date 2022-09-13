#include <iostream>
#include <math.h>
#include <vector>
//#include <string>

using namespace std;

bool check_prime(int sum)
{
    //bool prime;
    long int i;
    //cout<<"Sum="<<sum<<endl;
   long int root=sqrt(sum);
    //cout<<"QRT="<<root<<endl;

    for(i=2;i<=root;i++)
       {
          //as
           //cout<<"Modulo="<<sum%i<<endl;
           if(sum%i==0)
                return false;
            else
                continue;
       }
        if(i==(root+1))
            return true;
}

int main()
{
  unsigned int t,n,rec,count=0;
  bool flag,flag1,flag2;

    cin>>t; cin.ignore();

    for(int z=0;z<t;z++)
    {
        vector<long int> a;

        count=0;
        cin>>n;cin.ignore();

         for(long int y=0;y<n;y++)
           {
               cin>>rec; cin.ignore();
               a.push_back(rec);
           }

        //for(int y=0;y<n;y++)
          //  cout<<a[y]<<endl;

        for(long int i=0;i<n-1;i++)
            for(long int j=i+1;j<n;j++)
        {
            //flag1=check_prime(a[i]);
           // flag2=check_prime(a[j]);

            //flag=(flag1 || flag2);

            if(check_prime(a[i]) || check_prime(a[j]))
            {
                flag=check_prime(a[i]+a[j]);

                    if(flag==true)
                        {
                            //cout<<flag<<endl;
                                count++;
                            flag=false;
                        continue;
                    }
                    else
                        continue;
            }
            else
                continue;
        }

        cout<<count<<endl;

    }
}
