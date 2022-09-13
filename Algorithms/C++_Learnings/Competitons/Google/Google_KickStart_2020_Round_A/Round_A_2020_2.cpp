#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test,N,K,P,a[50][30],result=0;

int find_max(int row_no)
{
    int maxi=a[row_no][0];
    int max_index=0;

    for(int i=row_no,j=1;j<N-1;j++)
      if(a[row_no][j]>maxi)
        {
            maxi=a[row-no][j];
            max_index=j;

        }
        else continue;

    return max_index;
}

int main()
{
    int ans,max_index;
    cin>>test;

    while(test--)
    {
        cin>>N>>K>>P; cin.ignore();

        for(int i=0;i<N;i++)
            for(int j=0;j<K;j++)
                cin>>a[i][j];

        max_index=find_max(0);

        result+=a[0][max_index];
        a[0][max_index]=0;

        max_index=find_max(0);





    }
}
