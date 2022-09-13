#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int test;
    long long val,N,sum_0,sum_1,maxi;//,round;

    cin>>test;

    for(int t=0;t<test;t++)
    {
        vector<long long> v;
        maxi=0;sum_0=0;sum_1=0;
        cin>>N;

        for(int i=0;i<N;i++)
        {
            cin>>val;
            v.push_back(val);
        }
        /*for(int i=0;i<N;i++)
        {
            cout<<"v["<<i<<"]="<<v[i]<<endl;
        }*/

        //calculating sum_0 and sum_1;

        for(int i=0;i<N; i=i+2)
            sum_0+=v[i];
        if(N>0)
            for(int i=1;i<N; i=i+2)
              {
                  sum_1+=v[i];

                  if((i+2)%N<i && N%2!=0)
                    sum_1+=v[(i+2)%N];
              }
         maxi=sum_0;
         if(sum_1>sum_0)
            maxi=sum_1;
        if(N%2!=0)
        {
            if(N>=2)
            for(int i=2;i<N;i=i+2)
            {
               sum_0=sum_0-v[i-2]+v[i-1];
               if(sum_0>maxi)
                maxi=sum_0;
            }


            if(N>3)
                for(int i=3;i<N;i=i+2)
                {
                   sum_1=sum_1-v[i-2]+v[i-1];
                   if(sum_1>maxi)
                    maxi=sum_1;
                }

        cout<<maxi<<endl;
        }
        else
            cout<<maxi<<endl;
    }

        /*for(int j=0;j<N;j++)
          {//cout<<"Inside first for"<<endl;
         //cout<<"flag="<<flag<<endl;
            round=0;sum=0;
              for(int i=j; (i>=j && round==0) || (i<j && round==1); i=(i+2)%N)
            {
                //cout<<"Inside 2nd for"<<endl;

                //cout<<"i="<<i<<endl;
                if((i+2)>=N)
                    round++;

                sum+=v[i];
                //cout<<sum<<endl;

            }

            if(sum>maxi)
                maxi=sum;
          }

          cout<<maxi;
    }*/
}
