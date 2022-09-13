#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(){
    //two vectors
    string str1 = "AGGTAB", str2 = "GXTXAYB";
    stack<char> st;
    int l1 = str1.length(), l2 = str2.length();
    int dp[l1+1][l2+1];

    for(int i=0; i<=l1; i++)
        for(int j=0; j<=l2; j++)
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if( str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    cout<<"length of LCS = "<<dp[l1][l2];
    cout<<"\nLCS is: ";

    int i = l1, j = l2;
    while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){//dp[i][j] - 1 == dp[i-1][j-1]){//} && str1[i-1] == str2[j-1]){
            st.push(str1[i-1]);
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else //if(dp[i][j] == dp[i][j-1])
            j--;
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}

