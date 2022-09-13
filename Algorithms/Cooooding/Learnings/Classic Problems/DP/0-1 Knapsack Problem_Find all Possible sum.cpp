#include <iostream>
#include <cstring>
using namespace std;

/*
    given the weights find all possible sum that can be made using those weigts
*/
int main(){
    int k[] = {0,1,3,3,5};
    int n = sizeof(k)/sizeof(k[0]);
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += k[i];

    //using 2D Matrix
    bool possible[n][sum+1];
    memset(possible, false, sizeof(possible));
    /*for(int j=0; j<n; j++)
        for(int i=0; i<sum+1; i++)
            cout<<j<<','<<i<<" = "<<possible[j][i]<<"\n";
    cout<<"--CHANGED----\n";
    */
    possible[0][0] = true;

    for(int j=1; j<n; j++)
        for(int w=0; w<sum+1; w++){
            //Select given knapsack item and recur for remaining
            if(w - k[j] >= 0)
                possible[j][w] = possible[j][w] || possible[j-1][w-k[j]];

            //don't select current item
            possible[j][w] = possible[j][w] || possible[j-1][w];
            cout<<j<<','<<w<<" = "<<possible[j][w]<<"\n";
        }
    /*for(int j=0; j<n; j++)
        for(int i=0; i<sum+1; i++)
            cout<<j<<','<<i<<" = "<<possible[j][i]<<"\n";//[i == sum-1];
            */
}
