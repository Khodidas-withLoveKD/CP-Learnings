#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int knapSack(int v[], int w[], int n, int W){

    //init
    int dp[n+1][W+1];
    //memset(dp, 0 ,sizeof(dp[0][0])*(n+1)*(W+1));
    memset(dp, 0, sizeof(dp));
    cout<<"let's see = "<<"n = "<<n<<"\n";
    for(int i=0; i<=n; i++)
        cout<<" v["<<i<<"] = "<<v[i]<<" w["<<i<<"] = "<<w[i]<<"\n";
    cout<<"INDEX WENT OUT OF BOUNDS!!! But no error\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(w[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j - w[i-1]]);
        }
    }
    return dp[n][W];
}

int main(){

    // Input: set of items each with a weight and a value
	int v[] = { 20, 5, 10, 40, 15, 25 };
	int w[] = {  1, 2,  3,  8,  7, 4 };

	// Knapsack capacity
	int W = 10;

	// number of items
	int n = sizeof(v)/ sizeof(v[0]);

	cout << "Knapsack value is " << knapSack(v, w, n, W);
}
