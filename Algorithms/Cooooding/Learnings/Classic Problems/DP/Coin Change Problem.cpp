#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int c,n = 10;
    int coins[] = {2,5,3,6};
    int cNum = sizeof(coins)/sizeof(coins[0]);

    cout<<"Least no. of coins = ";
    int change[n+1];
    change[0] = 0;
    int counter[n+1], first[n+1];
    memset(counter, 0 ,sizeof(counter));
    counter[0] = 1;

    for(int i=1; i<=n; i++){
        change[i] = 10*n;
        for(int j=0; j<cNum ; j++){ c = coins[j];
            if(i - c >= 0){
                if(change[i-c] < change[i]){
                    change[i] = change[i - c] + 1;  //for least coins
                    first[i] = c;                   //to keep track of which coin
                }
                counter[i] += counter[i-c];         //to keep to total ordered ways
            }
        }
    }
    cout<<change[n]<<"\n";

    cout<<"Total ways (where order matters) are = ";
    cout<<counter[n];

    cout<<"\nCoins are = ";
    int temp = n;
    while(temp){
        cout<<first[temp]<<" ";
        temp -= first[temp];
    }

    //------------------------------------------------------------
    int dp[cNum+1][n+1];

    for(int i=0; i<=cNum; i++)
        for(int j=0; j<=n; j++){
             if(i == 0)
                dp[i][j] = 0;
             else if(j == 0)
                dp[i][j] = 1;
             else if(coins[i-1] > j)
                dp[i][j] = dp[i-1][j]; //exclude
             else
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]]; //include;
        }

    cout<<"\nNo of ways (permutation does not matter) = "<<dp[cNum][n];
}

