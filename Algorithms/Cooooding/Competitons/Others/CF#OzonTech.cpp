#include <iostream>

using namespace std;

int sum[1000],a[1000],b[1000],n,t,temp;

void check_sum(int i,int k)
{
   for( int j=0; j<=k; j++)
   {
       if(sum[j]==sum[i] && i!=j)
       {
          if(j==0)
          {
            temp=b[j];
            b[j]=b[j+1];
            b[j+1]=temp;
            sum[j]=a[j]+b[j];
            sum[j+1]=a[j+1]+b[j+1];
            check_sum(j+1,k);

          }
          else
          {
            temp=b[j];
            b[j]=b[j-1];
            b[j-1]=temp;
            sum[j]=a[j]+b[j];
            sum[j-1]=a[j-1]+b[j-1];
            check_sum(j-1,k);
            }

        }
   }
}
int main()
{
    cin>>t;
    for(int c=0;c<t;c++)
    {
        cin>>n;
        if(c!=0)
            cout<<endl;

        for(int i=0;i<n;i++)
           {
                cin>>a[i]; cin.ignore();
               // sum[i]=0;
           }
        for(int i=0;i<n;i++)
            cin>>b[i]; cin.ignore();

        for(int k=0,i=0;i<n;i++,k++)
        {
            sum[i]=a[i]+b[i];
           // if(i==2)
            check_sum(i,k);
        }

        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<b[i]<<" ";
    }

}
