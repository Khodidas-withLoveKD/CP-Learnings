#include<iostream>

using namespace std;

int flag=-1;
    long long int first=0,second=0,third=0,l,r;

int coprime(long long int a, long long int b)
{
    cout<<"inside Co-prie"<<endl;
    long long int i;
    if(b%a==0)
        return 0;
    else
    {
        for( i=2;i<b;i++)
            if(a%i==0 && b%i==0)
                return 0;
            else
                continue;

        if(i==b)
            return 1;
    }
}
int main()
{
    cin>>l>>r; cin.ignore();
    int flag=-1,first_flag=-1,j;

    for(int i=l;i<=r;i++)
    {
        j=i+1;
       while(j<=r)
        {cout<<"Inside for"<<endl;
       first_flag=coprime(i,j);
       cout<<first_flag<<endl;

        if(first_flag==1 && first==0)
        {first=i; second=j;i=second;j=second+1;first_flag=0;}
        else if(first_flag==1 && first!=0 && third==0)
        {
            third=i;
            flag=coprime(first,third);
        }
        }
    }
    if(flag!=0)
        cout<<first<<" "<<second<<" "<<third<<endl;
    else
        cout<<"-1";
}

